#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtGui>
#include <qmath.h>

//KSD��ɫģ������
class ParamColor
{
public:
    ParamColor()
    {
        this->dR = 0;
        this->dG = 0;
        this->dB = 0;
    }

    ParamColor(double dR, double dG, double dB)
    {
        this->dR = dR;
        this->dG = dG;
        this->dB = dB;
    }

    ParamColor(const ParamColor& ParamC)
    {
        this->dR = ParamC.dR;
        this->dG = ParamC.dG;
        this->dB = ParamC.dB;
    }

    ParamColor &operator =(const ParamColor& ParamC)
    {
        this->dR = ParamC.dR;
        this->dG = ParamC.dG;
        this->dB = ParamC.dB;
        return *this;
    }
public:
    double dR;
    double dG;
    double dB;
};

//KSD��ɫģ����
class KSDColor
{
public:
    KSDColor()
    {
        this->dK = ParamColor();
        this->dS = ParamColor();
        this->dD = 0;
    }

    KSDColor(ParamColor dK, ParamColor dS, double dD)
    {
        this->dK = dK;
        this->dS = dS;
        this->dD = dD;
    }

    KSDColor &operator =(const KSDColor& KSDCol)
    {
        this->dK = KSDCol.dK;
        this->dS = KSDCol.dS;
        this->dD = KSDCol.dD;
        return *this;
    }
public:
    ParamColor dK;
    ParamColor dS;
    double dD;
};

//KSDתΪRGB
QColor KSDToRGB(const KSDColor KSDCol);
//KSD���
KSDColor KSDMix(const KSDColor KSDColF, const KSDColor KSDColS);

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    QColor drawColorStandardRGB[7];     //RGB��׼ɫ
    KSDColor drawColorStandardKSD[7];   //KSD��׼ɫ

    KSDColor drawColorMixKSD;           //KSD���ɫ
    KSDColor drawColorSelectKSD;        //KSDѡ��ɫ

    int drawColorX;                      //ɫ����ʼX
    int drawColorY;                      //ɫ����ʼY
    int drawColorW;                      //ɫ����ʼW
    int drawColorH;                      //ɫ����ʼH
    int drawColorS;                      //ɫ����ʼS

    int drawColorStandardX[7];           //��׼ɫ��ʼX
    int drawColorStandardY[7];           //��׼ɫ��ʼY
    int drawColorStandardW[7];           //��׼ɫ��ʼW
    int drawColorStandardH[7];           //��׼ɫ��ʼH

    int drawColorMixX;                   //���ɫ��ʼX
    int drawColorMixY;                   //���ɫ��ʼY
    int drawColorMixW;                   //���ɫ��ʼW
    int drawColorMixH;                   //���ɫ��ʼH


    QPushButton *clearBtn;               //��հ�ť
    QPushButton *selectBtn;              //ѡ��ť

    int buttonX[2];                      //��ť��ʼX
    int buttonY[2];                      //��ť��ʼY
    int buttonW[2];                      //��ť��ʼW
    int buttonH[2];                      //��ť��ʼH
    int buttonS;                         //��ť��ʼs

    void paintEvent(QPaintEvent *e);
    void drawColorStandard();           //���Ʊ�׼��ɫ����
    void drawColorMix();                //���ƻ����ɫ����

    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void myMouseEvent(QMouseEvent *e);

signals:
    void sendColor(const QColor col);

private slots:
    void clearBtnClicked();
    void selectBtnClicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
