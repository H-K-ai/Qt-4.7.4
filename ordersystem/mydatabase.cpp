#include "mydatabase.h"
#include<QDebug>
#include<QSqlQuery>
#include<QStringList>

mydatabase::mydatabase()
{
    db=QSqlDatabase::addDatabase("QSQLITE");
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
        && tables.contains("desk", Qt::CaseInsensitive)
        && tables.contains("dish", Qt::CaseInsensitive)
        && tables.contains("orderform", Qt::CaseInsensitive)
       )
    {
        //������������Ѵ��ڣ�����Ҫ�ٴδ���
        QSqlQuery query;
        //query.exec("insert into desk values(1,0)");
    }
    else
    {
        QSqlQuery query;
        //������Ա��(��ţ����������룬��ɫ)   ��ɫ��0Ϊ����Ա��1Ϊ����Ա
        query.exec("create table person(personid int primary key,pname varchar,passwd  varchar,role  int)");
        //����������(��ţ���״̬)    ״̬��0���У�1Ԥ����2ʹ����
        query.exec("create table desk(deskid int primary key,status int)");
        //������Ʒ��(��ţ��������۸�)
        query.exec("create table dish(dishid int primary key,dname varchar,dprice int)");
        //����������(��ţ����ڣ�ʱ�䣬���ţ���)
        query.exec("create table orderform(orderid int primary key,date varchar, time varchar,deskno int,income int)");
        //�������Ա��ʼ�û���������
        query.exec("insert into person values(1,'admin','123',0)");
    }


}
void mydatabase::closedb()
{
    db.close();
}
