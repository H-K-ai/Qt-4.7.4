#ifndef COMMON_H
#define COMMON_H

#include <QtGui>
#include <QtDebug>
#include <QtSql>
#include <QList>
#include <QDateTime>
#include <QTextCodec>
#include <QtNetwork>
#include <QHash>
#include <QString>
#include <QTime>
#include <QTimer>
#include <QByteArray>
#include <QObject>
#include <QSqlDatabase>
#include <QListWidgetItem>
#include <QStateMachine>
#include <QPushButton>
#include <QSignalTransition>
#include <QPropertyAnimation>
#include <Phonon/MediaObject>
#include <Phonon/VideoPlayer>
#include <phonon/audiooutput.h>
#include <phonon/seekslider.h>
#include <phonon/mediaobject.h>
#include <phonon/volumeslider.h>
#include <phonon/backendcapabilities.h>

//���Կ���
#define DEBUGLEVELONE   1              //����DEBUG���صȼ�1
#define DEBUGLEVELTWO   1              //����DEBUG���صȼ�2
#define DEBUGLEVELTHREE 1              //����DEBUG���صȼ�3

#define INTNUMBERINIT 0                //int�������ݳ�ʼ��
#define NUMBERTOSTRINGBASE 10          //intת��string���ͽ��Ʊ�־
#define INTNUMBERDECREMENT 1           //int������Ŀ�Լ�1
#define INTEVENNUMBERFLAG 2            //int���������Ƿ�Ϊż��
#define STRINGNOTFINDINDEX -1          //��string��û���ҵ��±�

#define WEATHERFINDSTRINGLENGTH 3      //����Ԥ����":"�ֶεĳ���

#define UPDATETIMEONESECOND 1*1000     //ʱ��ÿ�����
#define ISONLINETENSECONDS 10*1000     //����ÿʮ�����

#define BKGPAINTERX 0                  //����������ʼXλ��
#define BKGPAINTERY 0                  //����������ʼYλ��

#define CLOTHESFONTSIZE 20             //�·���������С
#define DIGICLOCKDATEFONTSIZE 18       //����Ԥ���ص������С
#define WEATHERPLACEFONTSIZE 72        //����Ԥ���ص������С
#define WEATHERTEMPFONTSIZE 30         //����Ԥ���¶������С

#define SQLCLOTHESIDNUMINDEX 0         //���ݿ��·�����ID������λ��
#define SQLCLOTHESNAMEINDEX 1          //���ݿ��·��������Ƶ�����λ��
#define SQLCLOTHESTYPEINDEX 2          //���ݿ��·��������͵�����λ��
#define SQLCLOTHESSEASONINDEX 3        //���ݿ��·����м��ڵ�����λ��
#define SQLCLOTHESCLASSTYPEINDEX 4     //���ݿ��·����г��ϵ�����λ��
#define SQLCLOTHESBRANDINDEX 5         //���ݿ��·�����Ʒ�Ƶ�����λ��
#define SQLCLOTHESPRICEINDEX 6         //���ݿ��·����м۸������λ��
#define SQLCLOTHESTIMEINDEX 7          //���ݿ��·�����ʱ�������λ��
#define SQLCLOTHESSTOREPLACEINDEX 8    //���ݿ��·����д�ŵص�����λ��
#define SQLCLOTHESBUYPLACEINDEX 9      //���ݿ��·����й���ص�����λ��
#define SQLCLOTHESNOTEINDEX 10         //���ݿ��·����б�ע������λ��
#define SQLCLOTHESPICPATHINDEX 11      //���ݿ��·�����ͼƬ·��������λ��

#define SQLDAYDRESSIDNUMINDEX 0        //���ݿ�ÿ��װ�����ID������λ��
#define SQLDAYDRESSCLOTHESIDINDEX 1    //���ݿ�ÿ��װ������·�ID������λ��
#define SQLDAYDRESSTYPEINDEX 2         //���ݿ�ÿ��װ��������͵�����λ��
#define SQLDAYDRESSDATEINDEX 3         //���ݿ�ÿ��װ��������ڵ�����λ��
#define SQLDAYDRESSPICPATHINDEX 4      //���ݿ�ÿ��װ�����ͼƬ·��������λ��

#define SQLWEATHERIDNUMINDEX 0         //���ݿ�����б���ID������λ��
#define SQLWEATHERCITYNAMEINDEX 1      //���ݿ�����б��г������Ƶ�����λ��
#define SQLWEATHERCITYCODEINDEX 2      //���ݿ�����б��г��д��������λ��

extern QPoint globaWindowsPos;         //����λ��

extern QFont clothesFont;              //�·���������

extern QFont digiClockDateFont;        //��ҳ��������

extern QFont weatherPlaceFont;         //����Ԥ���ص�����

extern QFont weatherTempFont;          //����Ԥ���¶�����

//�����ļ�
bool copyFileToPath(QString sourceDir, QString toDir, bool coverFileIfExist);
//�����ļ���
bool copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist);
//�����ļ���
bool createFolder(const QString dir);

#endif // COMMON_H
