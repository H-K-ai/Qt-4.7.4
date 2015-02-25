#include "database.h"

database::database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

bool database::opendb(QString dbname)
{
    db.setDatabaseName(dbname);
    if(!db.open())
    {
        qDebug("db file open error");
        return false;
    }
    return true;
}

void database::createtable()
{
    QStringList tables = db.tables();
    if (tables.contains("person", Qt::CaseInsensitive)
            && tables.contains("goods", Qt::CaseInsensitive)
            && tables.contains("depot", Qt::CaseInsensitive)
            && tables.contains("turnover", Qt::CaseInsensitive)
            && tables.contains("member", Qt::CaseInsensitive)
            && tables.contains("punch", Qt::CaseInsensitive)
            )
    {
        //������������Ѵ���,����Ҫ�ٴδ���
        //qDebug("table exsited\n");
    }
    else
    {
        QSqlQuery query;
        //������Ա��(���,����,����,��ɫ)   ��ɫ��0Ϊ�곤,1Ϊ����Ա, 2Ϊ�ֿ����Ա
        query.exec("create table person(personid int primary key, pname varchar, passwd varchar, role int)");
        //������Ʒ��(���,����,�۸�,�ֿ�ʣ������,ͼƬ·��)
        query.exec("create table goods(goodsid int primary key, gname varchar, gprice int, gnumber int, gpic varchar)");
        //�����ֿ��(���,����,����,�ֿ�ʣ������,ͼƬ·��)
        query.exec("create table depot(depotid int primary key, dname varchar, dprice int, dnumber int, dpic varchar)");
        //����Ӫҵ����(���,����,ʱ��,��Ʒ��,����,���)
        query.exec("create table turnover(turnoverid int primary key, turnoverdate datetime, time varchar, tname varchar, tnumber int, tprice int)");
        //������Ա��(���, ��Ա����, ��Ա���Ѷ��, ͼƬ·��)
        query.exec("create table member(memberid int primary key, mname varchar, mamount varchar, mpic varchar)");
        //�����򿨱�(���, ����Ա��, ��¼ʱ��, ���˳�ʱ��)
        query.exec("create table punch(punchid int primary key, name varchar, logtime varchar, outtime varchar)");

        //�������Ա��ʼ�û���������
        query.exec("insert into person values(1,'admin','admin',0)");
        query.exec("insert into person values(2,'ad','',0)");
        query.exec("insert into person values(3,'us','',1)");
        query.exec("insert into person values(4,'de','',2)");
    }
}

void database::closedb()
{
    db.close();
}
