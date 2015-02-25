#ifndef COMMON_H
#define COMMON_H

#include <QtGui>
#include <QtDebug>
#include <QtSql>
#include <QList>
#include <QDateTime>
#include <QTextCodec>
#include <QAbstractItemModel>

#include "mydatabase.h"

//�����ļ�
bool copyFileToPath(QString sourceDir, QString toDir, bool coverFileIfExist);
//�����ļ���
bool copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist);
//�����ļ���
bool createFolder(const QString dir);

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
