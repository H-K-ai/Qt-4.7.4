#include "common.h"

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
    if (tables.contains("historyList", Qt::CaseInsensitive))
    {
        //������������Ѵ���,����Ҫ�ٴδ���
        //qDebug("table exsited\n");
    }
    else
    {
        QSqlQuery query;
        //������Ա��(���,����,����)
        query.exec("create table historyList(historyListid int primary key, name varchar, score int)");
    }
}

void database::closedb()
{
    db.close();
}
