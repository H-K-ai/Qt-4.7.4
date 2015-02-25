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
    if (tables.contains("room", Qt::CaseInsensitive)
            && tables.contains("checkin", Qt::CaseInsensitive)
            && tables.contains("roomstatus", Qt::CaseInsensitive)
            )
    {
        //������������Ѵ���,����Ҫ�ٴδ���
        //qDebug("table exsited\n");
    }
    else
    {
        QSqlQuery query;
        //���������(�����,״̬)
        query.exec("create table room(roomid int primary key, status int)");
        //������ס��(���,�����,����,���֤��,�˷�ʱ��,���Ѷ�)
        query.exec("create table checkin(checkinid int primary key, roomnum int, name varchar, idnum varchar, date datetime, price int)");
        //����״̬��(���,״̬) ״̬: δʹ�� ʹ�� Ԥ��
        query.exec("create table roomstatus(roomstatusid int primary key, status varchar)");

        query.exec("insert into roomstatus values(0, 'δʹ��')");
        query.exec("insert into roomstatus values(1, 'ʹ��')");
        query.exec("insert into roomstatus values(2, 'Ԥ��')");
    }
}

void mydatabase::closedb()
{
    db.close();
}
