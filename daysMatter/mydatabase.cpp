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
    if (tables.contains("user", Qt::CaseInsensitive)
            && tables.contains("note", Qt::CaseInsensitive)
            && tables.contains("day", Qt::CaseInsensitive)
            && tables.contains("orderoption", Qt::CaseInsensitive)
            )
    {
        //������������Ѵ��ڣ�����Ҫ�ٴδ���
        //qDebug("table exsited\n");
    }
    else
    {
        QSqlQuery query;
        //������¼����Ϣ(��ţ�����������)
        query.exec("create table user(userid int primary key, name varchar, passwd varchar)");
        //�������ڱ�(���,����,����,����,�ظ�,��ע)
        query.exec("create table note(noteid int primary key, title varchar, data varchar, sort int, ditto int, remark varchar)");
        //��������ʱ��(���,����,����,����)
        query.exec("create table day(dayid int primary key, title varchar, daynum int, sort int)");
        //����ѡ���(���,����ʽ)
        query.exec("create table orderoption(orderoptionid int primary key, rule int)");

        //�������Ա��ʼ�û���������
        query.exec("insert into user values(1,'ad','')");
        query.exec("insert into orderoption values(1,0)");
    }
}

void mydatabase::closedb()
{
    db.close();
}

