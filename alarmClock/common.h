#ifndef COMMON_H
#define COMMON_H

#include <QtGui>
#include <QtDebug>
#include <QtSql>
#include <QList>
#include <QDateTime>
#include <QTextCodec>
#include <QAbstractItemModel>
#include <Phonon/MediaObject>
#include <Phonon/VideoPlayer>
#include <phonon/audiooutput.h>
#include <phonon/seekslider.h>
#include <phonon/mediaobject.h>
#include <phonon/volumeslider.h>
#include <phonon/backendcapabilities.h>

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

extern QString userid;


//�������ڲ�
int datedef(QString dateStr, int rule);
//�Ƿ�����
int leap(int year);
//������������
void swapNum(int *pre, int *next);
//����ת����
int weekToInt(QString weekStr);

//ɾ����ť���ڵı�־
extern int itemDelButtonFlag;

//����λ��
extern QPoint windowsPos;

//�б�˫���õ��ı���
extern QString viewTitle;




#endif // COMMON_H
