#ifndef COMMFUNC_H
#define COMMFUNC_H

#include <QtGui>
#include <QtDebug>
#include <QtSql>
#include <QList>
#include <QDateTime>
#include <QTextCodec>
#include <QAbstractItemModel>
#include <QHash>
#include <QString>
#include <QTime>
#include <QTimer>
#include <QByteArray>
#include <QObject>
#include <QListWidgetItem>

#define NOCHESS			0 //û������

#define B_KING			1 //��˧
#define B_CAR			2 //�ڳ�
#define B_HORSE			3 //����
#define B_CANON			4 //����
#define B_BISHOP		5 //��ʿ
#define B_ELEPHANT		6 //����
#define B_PAWN			7 //�ڱ�
#define B_BEGIN			B_KING
#define B_END			B_PAWN

#define R_KING			8 //��˧
#define R_CAR			9 //�쳵
#define R_HORSE			10//����
#define R_CANON			11//����
#define R_BISHOP		12//��ʿ
#define R_ELEPHANT		13//����
#define R_PAWN			14//����
#define R_BEGIN			R_KING
#define R_END			R_PAWN

#define IsBlack(x)	(x >= B_BEGIN && x <= B_END)	//�ж�һ�������ǲ��Ǻ�ɫ
#define IsRed(x)	(x >= R_BEGIN && x <= R_END)	//�ж�һ�������ǲ��Ǻ�ɫ

//�ж����������ǲ���ͬɫ
#define IsSameSide(x,y)  ((IsBlack(x)&&IsBlack(y))||(IsRed(x)&&IsRed(y)))

//����һ������λ�õĽṹ
typedef struct _chessmanposition
{
    int x;
    int y;
}CHESSMANPOS;

//һ���߷��Ľṹ
typedef struct _chessmove
{
    int ChessID;	//������ʲô����
    CHESSMANPOS From; //��ʼλ��
    CHESSMANPOS To; //�ߵ�λ��
}CHESSMOVE;

//�����ƶ�������
typedef struct _movechess
{
    int nChessID;
    QPoint ptMovePoint;
}MOVECHESS;

#define BOARDSTARTX 30 //������ʼX
#define BOARDSTARTY 30 //������ʼY
#define BOARDMANX 10 //�������ӵ���ʼX
#define BOARDMANY 10 //�������ӵ���ʼY
#define BOARDWIDTH 460 //���̿��
#define BOARDHEIGHT 510 //���̸߶�
#define GRILLEWIDTH 40 //������ÿ�����ӵĸ߶�
#define GRILLEHEIGHT 40 //������ÿ�����ӵĿ��

//���峣���������̵ĳ�ʼ״̬
const int InitChessBoard[10][9]=
{
    {B_CAR,   B_HORSE, B_ELEPHANT, B_BISHOP, B_KING,  B_BISHOP, B_ELEPHANT, B_HORSE, B_CAR},
    {NOCHESS, NOCHESS, NOCHESS,    NOCHESS,  NOCHESS, NOCHESS,  NOCHESS,    NOCHESS, NOCHESS},
    {NOCHESS, B_CANON, NOCHESS,    NOCHESS,  NOCHESS, NOCHESS,  NOCHESS,    B_CANON, NOCHESS},
    {B_PAWN,  NOCHESS, B_PAWN,     NOCHESS,  B_PAWN,  NOCHESS,  B_PAWN,     NOCHESS, B_PAWN},
    {NOCHESS, NOCHESS, NOCHESS,    NOCHESS,  NOCHESS, NOCHESS,  NOCHESS,    NOCHESS, NOCHESS},

    {NOCHESS, NOCHESS, NOCHESS,    NOCHESS,  NOCHESS, NOCHESS,  NOCHESS,    NOCHESS, NOCHESS},
    {R_PAWN,  NOCHESS, R_PAWN,     NOCHESS,  R_PAWN,  NOCHESS,  R_PAWN,     NOCHESS, R_PAWN},
    {NOCHESS, R_CANON, NOCHESS,    NOCHESS,  NOCHESS, NOCHESS,  NOCHESS,    R_CANON, NOCHESS},
    {NOCHESS, NOCHESS, NOCHESS,    NOCHESS,  NOCHESS, NOCHESS,  NOCHESS,    NOCHESS, NOCHESS},
    {R_CAR,   R_HORSE, R_ELEPHANT, R_BISHOP, R_KING,  R_BISHOP, R_ELEPHANT, R_HORSE, R_CAR}
};

//��Ϸ����,0:δ����,1:����ʤ��,2:���ʤ��
extern int chessGameOver;

//�����ļ���
bool createFolder(const QString dir);

//����ת��ĸ
#define NUMTOUNICODE 65
//���ļ�����ת����������
void chessmanDataFromFile(QString fileData, int chessmanData[10][9]);
//����������ת���ļ�����
QString chessmanDataToFile(const int chessmanData[10][9]);

//�����Ϸ�Ƿ����
void gameIsOver(int position[10][9]);


#endif // COMMFUNC_H
