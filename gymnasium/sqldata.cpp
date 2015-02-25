#include "sqldata.h"

sqldata::sqldata()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

bool sqldata::opendb(QString dbname)
{
    db.setDatabaseName(dbname);
    if(!db.open())
    {
        qDebug("db file open error");
        return false;
    }
    return true;
}

void sqldata::createtable()
{
    QStringList tables = db.tables();
    if (tables.contains("person", Qt::CaseInsensitive)
            && tables.contains("member", Qt::CaseInsensitive)
            && tables.contains("punch", Qt::CaseInsensitive)
            && tables.contains("assessor", Qt::CaseInsensitive)
            && tables.contains("turnover", Qt::CaseInsensitive)
            && tables.contains("park", Qt::CaseInsensitive)
            )
    {
        //������������Ѵ���,����Ҫ�ٴδ���
        //qDebug("table exsited\n");
    }
    else
    {
        QSqlQuery query;
        //������Ա��(���,����,����,��ɫ)   ��ɫ��0Ϊ�곤,1Ϊ����Ա
        query.exec("create table person(personid int primary key, name varchar, passwd varchar, role int)");
        //������Ա��(���,��Ա����,�Ա�,����,������,��Ա���Ѷ��)
        query.exec("create table member(memberid int primary key, name varchar, sex int, age int, assname varchar, integral int)");
        //�����򿨱�(���,����Ա��,��¼ʱ��,���˳�ʱ��)
        query.exec("create table punch(punchid int primary key, name varchar, logtime varchar, outtime varchar)");
        //�������ʱ�(���,��������,�Ա�,����,�ó�)
        query.exec("create table assessor(assessorid int primary key, name varchar, sex int, age int, note varchar)");
        //����Ӫҵ����(���,ʱ��,��Ŀ����,���)
        query.exec("create table turnover(turnoverid int primary key, consumetime datetime, name varchar, price int)");
        //�������ر�(���,״̬)
        query.exec("create table park(parkid int primary key, status int)");

        //�������Ա��ʼ�û���������
        query.exec("insert into person values(1,'admin','admin',0)");
        query.exec("insert into person values(2,'ad','',0)");
        query.exec("insert into person values(3,'wa','',1)");

        query.exec("insert into member values(0,'����','','','','')");

    }
}

void sqldata::closedb()
{
    db.close();
}
