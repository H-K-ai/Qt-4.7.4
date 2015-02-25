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
    if (tables.contains("users", Qt::CaseInsensitive)
            && tables.contains("students", Qt::CaseInsensitive)
            && tables.contains("subjucts", Qt::CaseInsensitive)
            && tables.contains("courses", Qt::CaseInsensitive)
            && tables.contains("scores", Qt::CaseInsensitive)
            )
    {
        //������������Ѵ��ڣ�����Ҫ�ٴδ���
        //qDebug("table exsited\n");
    }
    else
    {
        QSqlQuery query;
        //������¼����Ϣ(���,����,����)
        query.exec("create table users(usersid int primary key, name varchar, passwd varchar)");
        //����ѧ����Ϣ��(���,����,���֤,רҵ,�༶,ѧ��,��Ƭ)
        query.exec("create table students(studentsid int primary key, name varchar, idcard varchar, spec varchar, classid varchar, schid varchar, pic varchar)");
        //�����γ̱�(���,��Ŀ)
        query.exec("create table subjucts(subjuctsid int primary key, name varchar)");
        //�����Ͽα�(���,��Ŀ,�༶,����,ʱ��)
        query.exec("create table courses(coursesid int primary key, subjucts varchar, classid varchar, weekday varchar, time varchar)");
        //�����ɼ���(���,��Ŀ,ѧ��,�ɼ�)
        query.exec("create table scores(scoresid int primary key, subjucts varchar, schid varchar, score int)");

        //�������Ա��ʼ�û���������
        query.exec("insert into users values(1,'ad','')");
    }
}

void mydatabase::closedb()
{
    db.close();
}
