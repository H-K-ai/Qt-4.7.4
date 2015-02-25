#ifndef COLORDIALOG_H
#define COLORDIALOG_H

#include <QDialog>
#include <QtGui>
#include <qmath.h>

#define PI 3.1415926

class colorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit colorDialog(QWidget *parent = 0);
    ~colorDialog();

    bool initFlag;          //�Ƿ��һ�γ�ʼ��
    bool colorFlag;         //�Ƿ�ѡ������ɫ
    bool selectSCFlag;      //�Ƿ�ѡ���˵�ɫ����СȦ
    bool selectHCFlag;      //�Ƿ�ѡ����ʰɫ����СȦ
    QColor pickRoundColor;  //ѡ��Ļ�����ɫ
    QColor pickRadialColor; //ѡ����ض���ɫ

    int drawRoundX;			//��ɫ��
    int drawRoundY;
    int drawRoundRadius;
    int drawRoundHeight;
    int drawRoundCentreX;
    int drawRoundCentreY;

    int drawRadialX;		//��ɫ��
    int drawRadialY;
    int drawRadialRadius;
    int drawRadialCentreX;
    int drawRadialCentreY;

    int drawHollowCircleX[2];//������
    int drawHollowCircleY[2];
    int drawHollowCircleRadius[2];
    int drawHollowCircleCentreX[2];
    int drawHollowCircleCentreY[2];

    int drawColorStandardDrawX;//��׼ɫ��ʼλ��
    int drawColorStandardDrawY;
    int drawColorStandardDrawW;
    int drawColorStandardDrawH;
    int drawColorStandardSpaceW;
    int drawColorStandardSpaceH;

    int drawColorStandardX[14];//��׼ɫ
    int drawColorStandardY[14];
    int drawColorStandardW[14];
    int drawColorStandardH[14];
    QColor drawColorStandardC[14];

    int drawColorSelectX;		//ѡ����ɫ��
    int drawColorSelectY;
    int drawColorSelectW;
    int drawColorSelectH;

    QPushButton *selectBtn; //ѡ��ť
    QPushButton *cancelBtn; //�˳���ť

    void paintEvent(QPaintEvent *e);

    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void myMouseEvent(QMouseEvent *e);

    void drawColorRound();
    void drawColorRadial();
    void drawColorLinear();
    void drawHollowCircle();
    void drawColorStandard();
    void drawColorSelect();

    void setColor(QColor col);
    QColor getColor();

signals:
    void sendColor(const QColor col);

private slots:
    void selectBtnClicked();
    void cancelBtnClicked();

};

#endif // COLORDIALOG_H
