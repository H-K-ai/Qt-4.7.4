#ifndef COMMON_H
#define COMMON_H

#include <QtGui>
#include <QtDebug>
#include <QtSql>
#include <QList>
#include <QDateTime>
#include <QTextCodec>
#include <QAbstractItemModel>
#include <QAbstractSocket>
#include <QHash>
#include <QHostAddress>
#include <QString>
#include <QTcpSocket>
#include <QTime>
#include <QTimer>
#include <QByteArray>
#include <QObject>
#include <QUdpSocket>
#include <QTcpServer>
#include <QtNetwork>
#include <QListWidgetItem>

//��Ϸ������ʼλ��
#define GAMEAEROX 10
#define GAMEAEROY 10
//����������
#define BOARDWIDE 500
#define BOARDHIGH 500
//���ѡ�к��С
#define REDUCEXY 5
//û������
#define NOCHESSMAN 0
//�ȼ�������Ŀ
#define LEVELONEMANNUM 10
#define LEVELONETYPENUM 10
#define LEVELTWOMANNUM 20
#define LEVELTWOTYPENUM 15
#define LEVELTHREEMANNUM 25
#define LEVELTHREETYPENUM 25
//����ת��ĸ
#define NUMTOUNICODE 65

//��Ϸ���ݵ�
extern int **chessmanData;
//���ӵ����ݽṹ
class chessman
{
public:
    chessman();
    void clear();
    void set(int x=0, int y=0, int type=NOCHESSMAN);
    int getX();
    int getY();
    int getType();
    bool typeExist();
    friend bool operator ==(const chessman& a,const chessman& b);
private:
    int chessmanX;
    int chessmanY;
    int chessmanType;
};

//��Ϸʱ��
extern QTime gameTime;
//��Ϸ����
extern int gameRole;
//�Է�ʣ������
extern int onlineManLeft;

//���ݿ�
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

//����Ϣת����������
void chessmanDataFromMessage(QString message);
//����������ת����Ϣ��ʽ
QString chessmanDataToMessage();

#endif // COMMON_H
