#include "mydata.h"

myData::myData()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

bool myData::opendb(QString dbname)
{
    db.setDatabaseName(dbname);
    if(!db.open())
    {
        qDebug("db file open error");
        return false;
    }
    return true;
}

void myData::createtable()
{
    QStringList tables = db.tables();
    if (tables.contains("user", Qt::CaseInsensitive)
            && tables.contains("room", Qt::CaseInsensitive)
            && tables.contains("checkin", Qt::CaseInsensitive)
            && tables.contains("staff", Qt::CaseInsensitive)
            && tables.contains("member", Qt::CaseInsensitive)
            && tables.contains("roomstatus", Qt::CaseInsensitive)
            )
    {
        //������������Ѵ���,����Ҫ�ٴδ���
        //qDebug("table exsited\n");
    }
    else
    {
        QSqlQuery query;
        //������¼��(���,��¼��,����)
        query.exec("create table user(userid int primary key, name varchar, passwd varchar)");
        //���������(�����,״̬,ͼƬ·��1,ͼƬ·��2,ͼƬ·��3)
        query.exec("create table room(roomid int primary key, status int, pic_1 varchar, pic_2 varchar, pic_3 varchar)");
        //������ס��(���,�����,����,���֤��,��סʱ��,���Ѷ�)
        query.exec("create table checkin(checkinid int primary key, roomnum int, name varchar, idnum varchar, date datetime, price int)");
        //����Ա����(���,����,���֤��,ְλ,��ְʱ��,����,ͼƬ)
        query.exec("create table staff(staffid int primary key, name varchar, idnum varchar, post varchar, date datetime, wage int, pic varchar)");
        //������Ա��(���,����,���֤��,���Ѷ�,����ʱ��,�����,ͼƬ)
        query.exec("create table member(memberid int primary key, name varchar, idnum varchar, price int, date datetime, roomnum int)");
        //����״̬��(���,״̬) ״̬: δʹ�� ʹ�� Ԥ��
        query.exec("create table roomstatus(roomstatusid int primary key, status varchar)");

        //�������Ա��ʼ�û���������
        query.exec("insert into user values(1,'ad','')");

        query.exec("insert into roomStatus values(0, 'δʹ��')");
        query.exec("insert into roomStatus values(1, 'ʹ��')");
        query.exec("insert into roomStatus values(2, 'Ԥ��')");
    }
}

void myData::closedb()
{
    db.close();
}
