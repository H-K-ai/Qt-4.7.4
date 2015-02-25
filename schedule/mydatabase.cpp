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
            && tables.contains("note", Qt::CaseInsensitive)
            && tables.contains("day", Qt::CaseInsensitive)
            && tables.contains("orderoption", Qt::CaseInsensitive)
            && tables.contains("mycourse", Qt::CaseInsensitive)
            && tables.contains("mynote", Qt::CaseInsensitive)
            )
    {
        //������������Ѵ��ڣ�����Ҫ�ٴδ���
        //qDebug("table exsited\n");
    }
    else
    {
        QSqlQuery query;
        //������¼����Ϣ(���, ����, ����)
        query.exec("create table users(usersid int primary key, name varchar, passwd varchar)");
        //����ѧ����Ϣ��(���, ����, ���֤, רҵ, �༶, ѧ��, ��Ƭ)
        query.exec("create table students(studentsid int primary key, name varchar, idcard varchar, spec varchar, classid varchar, schid varchar, pic varchar)");
        //�����γ̱�(���, ��Ŀ)
        query.exec("create table subjucts(subjuctsid int primary key, name varchar)");
        //�����Ͽα�(���, ��Ŀ, �༶, ����, ʱ��)
        query.exec("create table courses(coursesid int primary key, subjucts varchar, classid varchar, weekday varchar, time varchar)");
        //�����ɼ���(���, ��Ŀ, ѧ��, �ɼ�)
        query.exec("create table scores(scoresid int primary key, subjucts varchar, schid varchar, score int)");
        //�����ҵĿγ̱�(���, �༶id, �γ�, ��, ��)
        query.exec("create table mycourse(mycourseid int primary key, classid varchar, name varchar, colindex int, rowindex int)");
        //�����ҵĿγ̱�ע��(���, �û�id, ��ע, ��, ��)
        query.exec("create table mynote(mynoteid int primary key, userid varchar, note varchar, colindex int, rowindex int)");

        //�������ڱ�(���, ����, ����, ����, �ظ�, ��ע)
        query.exec("create table note(noteid int primary key, title varchar, data varchar, sort int, ditto int, remark varchar)");
        //��������ʱ��(���, ����, ����, ����)
        query.exec("create table day(dayid int primary key, title varchar, daynum int, sort int)");
        //����ѡ���(���, ����ʽ)
        query.exec("create table orderoption(orderoptionid int primary key, rule int)");

        //�������Ա��ʼ�û���������
        query.exec("insert into users values(1, 'ad', '')");
        query.exec("insert into orderoption values(1, 0)");
    }
}

void mydatabase::closedb()
{
    db.close();
}
