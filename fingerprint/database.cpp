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
    if (tables.contains("cracker", Qt::CaseInsensitive)
            && tables.contains("person", Qt::CaseInsensitive)
            && tables.contains("goods", Qt::CaseInsensitive)
            && tables.contains("users", Qt::CaseInsensitive)
            && tables.contains("stockslog", Qt::CaseInsensitive)
            && tables.contains("stocks", Qt::CaseInsensitive)
            && tables.contains("borrowlog", Qt::CaseInsensitive)
            && tables.contains("usergoods", Qt::CaseInsensitive)
            && tables.contains("usergoodstemp", Qt::CaseInsensitive)
            )
    {
        //������������Ѵ��ڣ�����Ҫ�ٴδ���
        //qDebug("table exsited\n");
    }
    else
    {
        QSqlQuery query;
        //������Ա��(���, �û���, ע����, ����, ����)
        query.exec("CREATE TABLE cracker(cname VARCHAR, cpwd VARCHAR, cdate VARCHAR, cnum INT)");
        //������Ա��(���, ����)
        query.exec("CREATE TABLE person(pwd VARCHAR)");
        //������Ʒ��(���, ����)
        query.exec("CREATE TABLE goods(goodsid INT PRIMARY KEY, gname VARCHAR)");
        //����Ա����(���, ����, ���֤, Ȩ��, ָ��)
        query.exec("CREATE TABLE users(usersid INT PRIMARY KEY, username VARCHAR, idcard VARCHAR, role INT, userzw VARCHAR)");
        //��������¼��(���, ��Ʒ���, ��Ʒ����, ����, �ɹ�, ����, ����)
        query.exec("CREATE TABLE stockslog(stockslogid INT PRIMARY KEY, goodsid INT, num INT, createdate VARCHAR, buyerid INT, keeperid INT, leaderid INT)");
        //��������(���, ��Ʒ���, ��Ʒ����, �������)
        query.exec("CREATE TABLE stocks(stocksid INT PRIMARY KEY, goodsid INT, num INT, borrownum INT)");
        //������ȡ��¼��(���, ��Ʒ���, ��Ʒ����, ����, ����, ��ȡ��, �軹��־)
        query.exec("CREATE TABLE borrowlog(borrowlogid INT PRIMARY KEY, goodsid INT, num INT, createdate VARCHAR, keeperid INT, userid INT, borrowflag INT)");
        //������ȡ��Ա��(���, ��Ʒ���, ��Ʒ����, ��ȡ��)
        query.exec("CREATE TABLE usergoods(usergoodsid INT PRIMARY KEY, goodsid INT, num INT, userid INT)");
        //������ȡ��Ա��Ʒ��ʱ��(���, ��Ʒ���, ��Ʒ����)
        query.exec("CREATE TABLE usergoodstemp(usergoodstempid INT PRIMARY KEY, goodsid INT, gname VARCHAR)");

        //����ע����Ϣ
        query.exec("INSERT INTO cracker VALUES('zhiwen', '', '" + QDate::currentDate().toString("yyyy.MM.dd") + "', 60)");
        query.exec("INSERT INTO person VALUES('qwer')");
    }
}

void database::closedb()
{
    db.close();
}
