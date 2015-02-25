#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>

#include <QtGui>
#include <QtDebug>
#include <QtSql>
#include <QList>
#include <QDateTime>
#include <QTextCodec>
#include <QAbstractItemModel>
#include <QtNetwork/QNetworkConfigurationManager>
#include <QtNetwork/QNetworkSession>

class database
{
public:
    database();
    bool opendb(QString dbname);
    void createtable();
    void closedb();

private:
    QSqlDatabase db;

};

//�����ļ�
bool copyFileToPath(QString sourceDir, QString toDir, bool coverFileIfExist);
//�����ļ���
bool copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist);
//�����ļ���
bool createFolder(const QString dir);

#endif // DATABASE_H
