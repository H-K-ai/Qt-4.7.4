#ifndef MYDATABASE_H
#define MYDATABASE_H

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

class mydatabase
{
public:
    mydatabase();
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

extern QString loginName;

#endif // MYDATABASE_H
