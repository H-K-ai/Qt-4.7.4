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
            && tables.contains("park", Qt::CaseInsensitive)
            && tables.contains("comego", Qt::CaseInsensitive)
            && tables.contains("parkstatus", Qt::CaseInsensitive)
            )
    {
        //������������Ѵ���,����Ҫ�ٴδ���
        //qDebug("table exsited\n");
    }
    else
    {
        QSqlQuery query;
        //������Ա��(���,����,����)
        query.exec("create table person(personid int primary key, name varchar, passwd varchar)");
        //������λ��(���,״̬)
        query.exec("create table park(parkid int primary key, status int)");
        //���������(���,���ƺ�,��λ,���ʱ��,����ʱ��,����)
        query.exec("create table comego(comegoid int primary key, plate varchar, park int, comedate datetime, go datetime, price int)");
        //����״̬��(���,״̬) ״̬: δʹ�� ʹ��
        query.exec("create table parkstatus(parkstatusid int primary key, status varchar)");

        //�������Ա��ʼ�û���������
        query.exec("insert into person values(1,'ad','')");
        //����״̬
        query.exec("insert into parkstatus values(0, 'δʹ��')");
        query.exec("insert into parkstatus values(1, 'ʹ��')");
        query.exec("insert into parkstatus values(2, 'Ԥ��')");
    }
}

void mydatabase::closedb()
{
    db.close();
}
