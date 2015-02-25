#include "mydatabase.h"

myDatabase::myDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

bool myDatabase::opendb(QString dbname)
{
    db.setDatabaseName(dbname);
    if(!db.open())
    {
        qDebug("db file open error");
        return false;
    }
    return true;
}

void myDatabase::createtable()
{
    QStringList tables = db.tables();
    if (tables.contains("person", Qt::CaseInsensitive)
            && tables.contains("waterchanges", Qt::CaseInsensitive)
            && tables.contains("electricitychanges", Qt::CaseInsensitive)
            && tables.contains("gaschanges", Qt::CaseInsensitive)
            && tables.contains("lights", Qt::CaseInsensitive)
            && tables.contains("boardcase", Qt::CaseInsensitive)
            && tables.contains("equipment", Qt::CaseInsensitive)
            && tables.contains("park", Qt::CaseInsensitive)
            && tables.contains("parkstatus", Qt::CaseInsensitive)
            && tables.contains("ownerinfo", Qt::CaseInsensitive)
            )
    {
        //������������Ѵ���,����Ҫ�ٴδ���
        //qDebug("table exsited\n");
    }
    else
    {
        QSqlQuery query;
        //������Ա��(���,����,����,��ɫ)   ��ɫ��0Ϊ����Ա, 1Ϊ�û�
        query.exec("create table person(personid int primary key, name varchar, passwd varchar, role int)");
        //����ˮ�ѱ�(���,����,����,�ɷ�,���)
        query.exec("create table waterchanges(waterchangesid int primary key, name varchar, date datetime, payment int, balance int)");
        //������ѱ�(���,����,����,�ɷ�,���)
        query.exec("create table electricitychanges(electricitychangesid int primary key, name varchar, date datetime, payment int, balance int)");
        //����ú���ѱ�(���,����,����,�ɷ�,���)
        query.exec("create table gaschanges(gaschangesid int primary key, name varchar, date datetime, payment int, balance int)");
        //����·�Ʊ�(���,�豸��,״̬,����,����)
        query.exec("create table lights(lightsid int primary key, name varchar, status int, detail varchar, date varchar)");
        //�����㲥��(���,�豸��,״̬,����,����)
        query.exec("create table boardcase(boardcaseid int primary key, name varchar, status int, detail varchar, date varchar)");
        //����������(���,�豸��,״̬,����,����)
        query.exec("create table equipment(equipmentid int primary key, name varchar, status int, detail varchar, date varchar)");

        //�������Ա��ʼ�û���������
        query.exec("insert into person values(1,'admin','admin',0)");
        query.exec("insert into person values(2,'ad','',0)");
        query.exec("insert into person values(3,'us','',1)");

        //������λ��(���,״̬)
        query.exec("create table park(parkid int primary key, status int)");
        //����״̬��(���,״̬) ״̬: δʹ�� ʹ��
        query.exec("create table parkstatus(parkstatusid int primary key, status varchar)");
        //����״̬
        query.exec("insert into parkstatus values(0, 'δʹ��')");
        query.exec("insert into parkstatus values(1, 'ʹ��')");
        query.exec("insert into parkstatus values(2, 'Ԥ��')");

        //�û���Ϣ��
        query.exec("create table ownerinfo(ownerinfoid int primary key, name varchar, pwd varchar, loufang varchar, danyuan varchar, louceng varchar, fangjian varchar, dianhua varchar)");
        query.exec("insert into ownerinfo values(1,'us','','12','3','4','5','041184831234')");
    }
}

void myDatabase::closedb()
{
    db.close();
}

QString username;
