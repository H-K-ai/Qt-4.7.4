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
            && tables.contains("classLevel", Qt::CaseInsensitive)
            && tables.contains("classType", Qt::CaseInsensitive)
            && tables.contains("classCon", Qt::CaseInsensitive)
            )
    {
        //������������Ѵ��ڣ�����Ҫ�ٴδ���
        //qDebug("table exsited\n");
    }
    else
    {
        QString sql;
        QSqlQuery query;
        //������¼��(���, ����, ����)
        sql = "CREATE TABLE person(personid INT PRIMARY KEY, name VARCHAR, passwd VARCHAR)";
        query.exec(sql);
        //������¼��(���, ���)
        sql = "CREATE TABLE classLevel(classLevelId INT PRIMARY KEY, name VARCHAR)";
        query.exec(sql);
        //������¼��(���, ���)
        sql = "CREATE TABLE classType(classTypeId INT PRIMARY KEY, name VARCHAR)";
        query.exec(sql);
        //������¼��(���, ���, ���, ����, ����, ����, ѧʱ, ѧ��, ʵ��, ѧ��, ���˷�ʽ)
        sql = "CREATE TABLE classCon(classConId INT PRIMARY KEY, "
                + QString("cLevel INT, ")
                + QString("cType INT, ")
                + QString("cNature INT, ")
                + QString("cCode VARCHAR, ")
                + QString("cName VARCHAR, ")
                + QString("cHrs VARCHAR, ")
                + QString("cCrs VARCHAR, ")
                + QString("cTest VARCHAR, ")
                + QString("cTime INT, ")
                + QString("cExam INT ")
                + QString(")");
        query.exec(sql);

        //�����¼��Ϣ
        query.exec("INSERT INTO person VALUES(1, 'ad', 'ad')");
    }
}

void database::closedb()
{
    db.close();
}
