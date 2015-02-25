#ifndef COMMON_H
#define COMMON_H

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

#define TBOPENCOMCOL 0    //�б��ȡ��λ�����к�
#define TBOPENSALCOL 1    //�б��ȡ���ղ����к�
#define TBOPENPROCOL 2    //�б��ȡ���������к�
#define TBOPENSTKCOL 3    //�б��ȡ��ĩ����к�
#define TBOPENTRACOL 4    //�б��ȡ��·�����к�
#define TBOPENCARCOL 5    //�б��ȡ���������к�
#define TBOPENREMCOL 6    //�б��ȡ������ע�к�

#define XLSOPENCOMROW 5   //�ļ���ȡ�к�
#define XLSOPENCOMCOL 2   //�ļ���ȡ��λ�����к�
#define XLSOPENSALCOL 3   //�ļ���ȡ���ղ����к�
#define XLSOPENPROCOL 5   //�ļ���ȡ���������к�
#define XLSOPENSTKCOL 7   //�ļ���ȡ��ĩ����к�
#define XLSOPENTRACOL 8   //�ļ���ȡ��·�����к�
#define XLSOPENCARCOL 9   //�ļ���ȡ���������к�
#define XLSOPENREMCOL 10  //�ļ���ȡ������ע�к�

#define XLSSAVETIMROW 1   //�ļ�����ʱ���к�
#define XLSSAVETIMCOL 1   //�ļ�����ʱ���к�

#define XLSSAVECOMROW 5   //�ļ������к�
#define XLSSAVEENDROW 15  //�ļ���������к�
#define XLSSAVECOMCOL 2   //�ļ����浥λ�����к�
#define XLSSAVESALCOL 3   //�ļ����浱�ղ����к�
#define XLSSAVESSLCOL 4   //�ļ������ۼƲ����к�
#define XLSSAVEPROCOL 5   //�ļ����浱�������к�
#define XLSSAVESPRCOL 6   //�ļ������ۼ������к�
#define XLSSAVESTKCOL 7   //�ļ�������ĩ����к�
#define XLSSAVETRACOL 8   //�ļ�������·�����к�
#define XLSSAVECARCOL 9   //�ļ��������������к�
#define XLSSAVEREMCOL 10  //�ļ�����������ע�к�

#endif // COMMON_H
