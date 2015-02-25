#include "sqldate.h"

sqlDate::sqlDate()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

bool sqlDate::opendb(QString dbname)
{
    db.setDatabaseName(dbname);
    if(!db.open())
    {
        qDebug("db file open error");
        return false;
    }
    return true;
}

void sqlDate::createtable()
{
    QStringList tables = db.tables();
    if (tables.contains("user", Qt::CaseInsensitive)
            && tables.contains("food", Qt::CaseInsensitive)
            && tables.contains("cookbook", Qt::CaseInsensitive)
            && tables.contains("sports", Qt::CaseInsensitive)
            && tables.contains("calrecord", Qt::CaseInsensitive)
            && tables.contains("weightrecord", Qt::CaseInsensitive)
            )
    {
        //������������Ѵ��ڣ�����Ҫ�ٴδ���
        //qDebug("table exsited\n");
    }
    else
    {
        QSqlQuery query;
        //������¼����Ϣ(��ţ�����������)
        query.exec("create table user(userid int primary key, passwd varchar)");
        //����ʳ���(���,����,����,ָ��,����,ͼƬ)
        query.exec("create table food(foodid int primary key, name varchar, calories int, indexNum int, category varchar, pic varchar)");
        //����ʳ�ױ�(���,����,����,ָ��,����,ͼƬ)
        query.exec("create table cookbook(cookbookid int primary key, name varchar, calories int, indexNum int, category varchar, pic varchar)");
        //�����˶���(���,����,����,ָ��,����,ͼƬ)
        query.exec("create table sports(sportsid int primary key, name varchar, calories int, indexNum int, category varchar, pic varchar)");
        //����������¼��(���,����,����,����,����,����)
        query.exec("create table calrecord(calrecordid int primary key, name varchar, calories int, calvariable int, category int, date varchar)");
        //�������ؼ�¼��(���,����,����)
        query.exec("create table weightrecord(weightrecordid int primary key, weight int, date varchar)");

        //�������Ա��ʼ�û���������
        query.exec("insert into user values(1,'ad')");
    }
}

void sqlDate::closedb()
{
    db.close();
}

