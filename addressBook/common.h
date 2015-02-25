#ifndef COMMON_H
#define COMMON_H

#include <QtGui>
#include <QtDebug>
#include <QAbstractItemModel>
#include <QtCore>
#include <QList>
#include <QDateTime>
#include <QTextCodec>
#include <QHash>
#include <QtSql>
#include <QString>
#include <QTime>
#include <QTimer>
#include <QByteArray>
#include <QObject>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QIODevice>
#include <QEvent>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QGraphicsItem>
#include <math.h>

//�����ļ�
bool copyFileToPath(QString sourceDir, QString toDir, bool coverFileIfExist);
//�����ļ���
bool copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist);
//�����ļ���
bool createFolder(const QString dir);

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

enum itemType{BARITEM=0, BULLETITEM, CANNONITEM, FISHITEM, PAUSEITEM, WEBITEM};

extern int score;
extern int secondTime;


#endif // COMMON_H
