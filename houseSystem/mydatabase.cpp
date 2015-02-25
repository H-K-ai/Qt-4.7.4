#include "mydatabase.h"

mydatabase::mydatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

bool mydatabase::opendb(QString dbname)
{
    db.setDatabaseName(dbname);
    if(!db.open())
    {
        qDebug("db file open error");
        return false;
    }
    return true;
}

void mydatabase::createtable()
{
    QStringList tables = db.tables();
    if (tables.contains("person", Qt::CaseInsensitive)
            && tables.contains("houses", Qt::CaseInsensitive)
            && tables.contains("business", Qt::CaseInsensitive)
            && tables.contains("record", Qt::CaseInsensitive)
            && tables.contains("property", Qt::CaseInsensitive)
            && tables.contains("grade", Qt::CaseInsensitive)
            && tables.contains("message", Qt::CaseInsensitive)
            )
    {
        //������������Ѵ��ڣ�����Ҫ�ٴδ���
        //qDebug("table exsited\n");
    }
    else
    {
        QSqlQuery query;
        //������Ա��(��ţ����������룬��ɫ)   ��ɫ��0Ϊ����Ա��1Ϊ��ͨ�û�
        query.exec("create table person(personid int primary key, pname varchar, passwd varchar, role int)");
        //����¥�̱�(��ţ����ƣ��۸�ͼƬ·����ͼƬ·��1��ͼƬ·��2��ͼƬ·��3��ͼƬ·��4)
        query.exec("create table houses(houseid int primary key, hname varchar, hprice int, hpic varchar, hpic_1 varchar, hpic_2 varchar, hpic_3 varchar, hpic_4 varchar)");
        //�������ױ�(��ţ�¥�������ɽ��ˣ��۸�)
        query.exec("create table business(businessid int primary key, hname varchar, bname varchar, bprice int)");
        //����������(��ţ����ڣ�ʱ�䣬¥������״̬��ͼƬ·��) ״̬��0Ϊ�����1ΪԤ�桢2Ϊ���顢3Ϊ���
        query.exec("create table record(recordid int primary key, date varchar, time varchar, hname varchar, status int, rpic varchar)");
        //������Ȩ��(���, ¥��, ��Ȩ�ˣ�ͼƬ·��)
        query.exec("create table property(propertyId int primary key, hname varchar, dname varchar, ppic varchar)");
        //�����ǼǱ�(���, ¥��, ��Ȩ�ˣ�ͼƬ·��)
        query.exec("create table grade(gradeId int primary key, hname varchar, dname varchar, gpic varchar)");
        //�������Ա�(���, �û�����¥�������Ǽ�������)
        query.exec("create table message(messageId int primary key, mname varchar, mhouse varchar, level int, data varchar)");

        //�������Ա��ʼ�û���������
        query.exec("insert into person values(1,'admin','admin',0)");
        query.exec("insert into person values(2,'ad','',0)");
        query.exec("insert into person values(3,'us','',1)");
    }
}

void mydatabase::closedb()
{
    db.close();
}
