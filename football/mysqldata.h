#ifndef MYSQLDATA_H
#define MYSQLDATA_H

#include <QtGui>
#include <QtDebug>
#include <QtSql>
#include <QList>
#include <QDateTime>
#include <QTextCodec>
#include <QAbstractItemModel>

class mysqldata
{
public:
    mysqldata();
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

#endif // MYSQLDATA_H
