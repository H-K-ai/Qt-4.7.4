#include "colordialog.h"

colorDialog::colorDialog(QWidget *parent) :
    QDialog(parent)
{
    initFlag = true;
    colorFlag = false;
    selectSCFlag = false;
    selectHCFlag = false;

    //��ɫ��ʼ��
    pickRoundColor = QColor(0x00, 0x00, 0x00);
    pickRadialColor = QColor(0x00, 0x00, 0x00);

    //��ɫ��
    drawRoundX = 50;
    drawRoundY = 50;
    drawRoundRadius = 220;
    drawRoundHeight = 15;

    drawRoundCentreX = drawRoundX + drawRoundRadius / 2;
    drawRoundCentreY = drawRoundY + drawRoundRadius / 2;

    //��ɫ��
    drawRadialX = drawRoundX + drawRoundHeight;
    drawRadialY = drawRoundY + drawRoundHeight;
    drawRadialRadius = drawRoundRadius - 2 * drawRoundHeight;
    drawRadialCentreX = drawRadialX + drawRadialRadius / 2;
    drawRadialCentreY = drawRadialY + drawRadialRadius / 2;

    //����Ȧ
    drawHollowCircleRadius[0] = drawRoundHeight;
    drawHollowCircleCentreX[0] = drawRoundCentreX + (drawRoundRadius - drawRoundHeight) / 2;
    drawHollowCircleCentreY[0] = drawRoundCentreY;
    drawHollowCircleX[0] = drawHollowCircleCentreX[0] - drawRoundHeight / 2;
    drawHollowCircleY[0] = drawHollowCircleCentreY[0] - drawRoundHeight / 2;

    drawHollowCircleRadius[1] = drawRoundHeight;
    drawHollowCircleCentreX[1] = drawRadialCentreX;
    drawHollowCircleCentreY[1] = drawRadialCentreY;
    drawHollowCircleX[1] = drawHollowCircleCentreX[1] - drawRoundHeight / 2;
    drawHollowCircleY[1] = drawHollowCircleCentreY[1] - drawRoundHeight / 2;

    //��׼ɫ
    drawColorStandardSpaceW = 15;
    drawColorStandardSpaceH = 14;
    drawColorStandardDrawX = drawRoundX + drawRoundRadius + drawColorStandardSpaceW;
    drawColorStandardDrawY = drawRoundY;
    drawColorStandardDrawW = 50;
    drawColorStandardDrawH = 15;

    for (int i=0; i<14; i++)
    {
        drawColorStandardX[i] = drawColorStandardDrawX + (i % 2) * (drawColorStandardDrawW + drawColorStandardSpaceW);
        drawColorStandardY[i] = drawRoundY + (i / 2) * (drawColorStandardDrawH + drawColorStandardSpaceH);
        drawColorStandardW[i] = drawColorStandardDrawW;
        drawColorStandardH[i] = drawColorStandardDrawH;
        if (12 <= i)
        {
            drawColorStandardX[i] = drawColorStandardDrawX + drawColorStandardDrawW + drawColorStandardSpaceW;
            drawColorStandardY[i] = drawRoundY + ((i / 2) + (i % 2)) * (drawColorStandardDrawH + drawColorStandardSpaceH) - ((i % 2) * 5);
            drawColorStandardH[i] = drawColorStandardDrawH + 5;
        }
    }

    drawColorStandardC[0] = QColor(192, 0, 0);
    drawColorStandardC[1] = QColor(255, 0, 0);
    drawColorStandardC[2] = QColor(255, 192, 0);
    drawColorStandardC[3] = QColor(255, 255, 0);
    drawColorStandardC[4] = QColor(146, 208, 80);
    drawColorStandardC[5] = QColor(0, 176, 80);
    drawColorStandardC[6] = QColor(0, 176, 240);
    drawColorStandardC[7] = QColor(0, 112, 192);
    drawColorStandardC[8] = QColor(0, 32, 96);
    drawColorStandardC[9] = QColor(112, 48, 160);
    drawColorStandardC[10] = QColor(0, 0, 0);
    drawColorStandardC[11] = QColor(255, 255, 255);
    drawColorStandardC[12] = QColor(192, 0, 0);
    drawColorStandardC[13] = QColor(192, 0, 0);

    selectBtn = new QPushButton(this);
    cancelBtn = new QPushButton(this);
    selectBtn->setText(QString("Select"));
    cancelBtn->setText(QString("Cancel"));
    selectBtn->setGeometry(drawColorStandardX[12], drawColorStandardY[12], drawColorStandardW[12], drawColorStandardH[12]);
    cancelBtn->setGeometry(drawColorStandardX[13], drawColorStandardY[13], drawColorStandardW[13], drawColorStandardH[13]);

    QObject::connect(selectBtn, SIGNAL(clicked()), this, SLOT(selectBtnClicked()));
    QObject::connect(cancelBtn, SIGNAL(clicked()), this, SLOT(cancelBtnClicked()));

    //��ɫѡ�о��ο�
    drawColorSelectX = drawColorStandardDrawX;
    drawColorSelectY = drawColorStandardY[10] + drawColorStandardDrawH + drawColorStandardSpaceH;
    drawColorSelectW = drawColorStandardDrawW;
    drawColorSelectH = 2 * drawColorStandardDrawH + drawColorStandardSpaceH;

    this->setWindowOpacity(1);    //͸����1.0-0.0
    this->setWindowFlags(Qt::FramelessWindowHint);   //�����ޱ߿�
    this->setAttribute(Qt::WA_TranslucentBackground); //͸������
}

colorDialog::~colorDialog()
{
}

void colorDialog::paintEvent(QPaintEvent *e)
{
    //QPainter painter(this);
    //painter.drawPixmap(0, 0, QPixmap(":/bj.png"));

    drawColorRound();
    drawColorRadial();
    drawHollowCircle();
    drawColorStandard();
    drawColorSelect();

    initFlag = false;
    colorFlag = false;
}

//���ѹ���ƶ�
void colorDialog::mouseMoveEvent(QMouseEvent *e)
{
    myMouseEvent(e);
}

//���ѹ��
void colorDialog::mousePressEvent(QMouseEvent *e)
{
    myMouseEvent(e);
}

//����ͷ�
void colorDialog::mouseReleaseEvent(QMouseEvent *e)
{
    selectHCFlag = false;
    selectSCFlag = false;
}

//����¼�
void colorDialog::myMouseEvent(QMouseEvent *e)
{
    /*
 ��P��X1,Y1) ��Բ (x��a)^2+(y��b) ^2=r^2��λ�ù�ϵ��
 1.��(x1��a)^2+(y1��b) ^2>r^2ʱ�����P��Բ�⡣
 2.��(x1��a)^2+(y1��b) ^2=r^2ʱ�����P��Բ�ϡ�
 3.��(x1��a)^2+(y1��b) ^2<r^2ʱ�����P��Բ�ڡ�

 ���� = �Ƕȳ��Ԧк��ٳ���180
 �Ƕ� = ���ȳ��Ԧ��ٳ���180
 */

    //HSVɫ��
    double colorH = 0.0;
    double colorS = 255.0;
    double colorV = 255.0;

    int iColorH = 0;
    int iColorS = 0;
    int iColorL = 0;

    //��������ĵ�ľ���
    double selectCentreRange = 0.0;

    //����ɫ�̻���
    double radian = 0.0;

    if((qPow((e->x()-drawRoundCentreX), 2) + qPow((e->y()-drawRoundCentreY), 2)) < qPow((drawRoundRadius/2), 2))
    {
        //��ɫ����
        if((qPow((e->x()-drawRadialCentreX), 2) + qPow((e->y()-drawRadialCentreY), 2)) > qPow((drawRadialRadius/2), 2))
        {
            //��ɫ����
            if(false == selectSCFlag)
            {
                selectHCFlag = true;
            }
            else
            {
                selectHCFlag = false;
            }
        }
        else
        {
            //��ɫ����
            if(false == selectHCFlag)
            {
                //û��ѡ��ʰɫ���е�СȦ
                if((qPow((e->x()-drawRadialCentreX), 2) + qPow((e->y()-drawRadialCentreY), 2)) < qPow(((drawRadialRadius-drawRoundHeight)/2), 2))
                {
                    //��ɫ��СȦ
                    drawHollowCircleCentreX[1] = e->x();
                    drawHollowCircleCentreY[1] = e->y();
                    drawHollowCircleX[1] = drawHollowCircleCentreX[1] - drawRoundHeight / 2;
                    drawHollowCircleY[1] = drawHollowCircleCentreY[1] - drawRoundHeight / 2;

                    pickRoundColor.getHsl(&iColorH, &iColorS, &iColorL);

                    selectCentreRange = qPow(abs(drawHollowCircleCentreX[1] - drawRadialCentreX), 2) + qPow(abs(drawHollowCircleCentreY[1] - drawRadialCentreY), 2);
                    iColorL = 255 * (sqrt(selectCentreRange) / (drawRadialRadius/2));
                    pickRadialColor = QColor::fromHsl(iColorH, iColorS, iColorL);

                    colorFlag = true;
                    selectSCFlag = true;
                    update();

                    return;
                }
            }
        }
    }

    if((false == selectHCFlag) && (true == selectSCFlag))
    {
        //��ɫСȦѡ��
        colorH = 180 * (atan((double)(e->y()-drawRoundCentreY)/(e->x()-drawRoundCentreX))) / PI;
        if(e->y() >= drawRoundCentreY)          //���Ƕ�ת��Ϊ0-360��
        {
            if(e->x() >= drawRoundCentreX)
            {
                colorH = colorH;
            }
            else
            {
                colorH += 180;
            }
        }
        else
        {
            if(e->x() >= drawRoundCentreX)
            {
                colorH += 360;
            }
            else
            {
                colorH += 180;
            }
        }

        //��ɫ��СȦ
        radian = colorH * PI / 180;
        drawHollowCircleCentreX[1] = cos(radian) * (drawRadialRadius - drawRoundHeight) / 2 + drawRoundCentreX;
        drawHollowCircleCentreY[1] = sin(radian) * (drawRadialRadius - drawRoundHeight) / 2 + drawRoundCentreY;
        drawHollowCircleX[1] = drawHollowCircleCentreX[1] - drawRoundHeight / 2;
        drawHollowCircleY[1] = drawHollowCircleCentreY[1] - drawRoundHeight / 2;

        colorFlag = true;
        update();
    }

    if((true == selectHCFlag) && (false == selectSCFlag))
    {
        //��ɫС��ѡ��
        colorH = 180 * (atan((double)(e->y()-drawRoundCentreY)/(e->x()-drawRoundCentreX))) / PI;
        if(e->y() >= drawRoundCentreY)          //���Ƕ�ת��Ϊ0-360��
        {
            if(e->x() >= drawRoundCentreX)
            {
                colorH = colorH;
            }
            else
            {
                colorH += 180;
            }
        }
        else
        {
            if(e->x() >= drawRoundCentreX)
            {
                colorH += 360;
            }
            else
            {
                colorH += 180;
            }
        }
        pickRoundColor = QColor::fromHsv((int)colorH, (int)colorS, (int)colorV);

        pickRoundColor.getHsl(&iColorH, &iColorS, &iColorL);
        selectCentreRange = qPow(abs(drawHollowCircleCentreX[1] - drawRadialCentreX), 2) + qPow(abs(drawHollowCircleCentreY[1] - drawRadialCentreY), 2);
        iColorL = 255 * (sqrt(selectCentreRange) / (drawRadialRadius/2));
        pickRadialColor = QColor::fromHsl(iColorH, iColorS, iColorL);

        //��ɫ��СȦ
        radian = colorH * PI / 180;
        drawHollowCircleCentreX[0] = cos(radian) * (drawRoundRadius - drawRoundHeight) / 2 + drawRoundCentreX;
        drawHollowCircleCentreY[0] = sin(radian) * (drawRoundRadius - drawRoundHeight) / 2 + drawRoundCentreY;
        drawHollowCircleX[0] = drawHollowCircleCentreX[0] - drawRoundHeight / 2;
        drawHollowCircleY[0] = drawHollowCircleCentreY[0] - drawRoundHeight / 2;

        colorFlag = true;
        update();
    }


    if((false == selectHCFlag) && (false == selectSCFlag))
    {
        //��������
        for (int i=0; i<12; i++)
        {
            if ((e->x() >= drawColorStandardX[i]) && (e->x() <= (drawColorStandardX[i] + drawColorStandardW[i])))
            {
                if ((e->y() >= drawColorStandardY[i]) && (e->y() <= (drawColorStandardY[i] + drawColorStandardH[i])))
                {
                    setColor(drawColorStandardC[i]);
                    return;
                }
            }
        }
    }
}

//����Բ��ʰɫ��
void colorDialog::drawColorRound()
{
    int colorNum = 6;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QConicalGradient conicalGradient(drawRoundX+(drawRoundRadius/2), drawRoundY+(drawRoundRadius/2), 0);

    conicalGradient.setColorAt((double)(0.0/colorNum), Qt::red);        //0xFF0000
    conicalGradient.setColorAt((double)(1.0/colorNum), Qt::magenta);    //0xFF00FF
    conicalGradient.setColorAt((double)(2.0/colorNum), Qt::blue);       //0x0000FF
    conicalGradient.setColorAt((double)(3.0/colorNum), Qt::cyan);       //0x00FFFF
    conicalGradient.setColorAt((double)(4.0/colorNum), Qt::green);      //0x00FF00
    conicalGradient.setColorAt((double)(5.0/colorNum), Qt::yellow);     //0xFFFF00
    conicalGradient.setColorAt((double)(6.0/colorNum), Qt::red);        //0xFF0000

    painter.setBrush(QBrush(conicalGradient));
    painter.drawEllipse(drawRoundX, drawRoundX, drawRoundRadius, drawRoundRadius);
}

//����Բ�ε�ɫ��
void colorDialog::drawColorRadial()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QRadialGradient radialGradient(QPointF(drawRadialX+(drawRadialRadius/2), drawRadialY+(drawRadialRadius/2)), drawRadialRadius/2);

    radialGradient.setColorAt(0.0, Qt::black);          //0x000000
    radialGradient.setColorAt(0.4, pickRoundColor);
    radialGradient.setColorAt(1.0, Qt::white);          //0xFFFFFF

    painter.setBrush(QBrush(radialGradient));
    painter.drawEllipse(drawRadialX, drawRadialX, drawRadialRadius, drawRadialRadius);
}

//���Ʒ���ɫ��
void colorDialog::drawColorLinear()
{
    QPainter pt(this);
    QColor color(0x00,0x00,0x00);
    for (int i=0; i<256; i++)
    {
        for (int j=0; j<256; j++)
        {
            color.setRgb(0xff, i, j, 0xff);
            pt.setPen(color);
            pt.drawPoint(20+i, 20+j);
            color.setRgb(i, 0xff, j, 0xff);
            pt.setPen(color);
            pt.drawPoint(296+i, 20+j);
            color.setRgb(j, i, 0xff, 0xff);
            pt.setPen(color);
            pt.drawPoint(572+i, 20+j);
        }
    }
}

//���ƿ���Բ
void colorDialog::drawHollowCircle()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QColor transparentColor = QColor(0x00, 0x00, 0x00, 0);
    QLinearGradient linearGradient(drawHollowCircleX[0], drawHollowCircleY[0], drawHollowCircleRadius[0], drawHollowCircleRadius[0]);
    linearGradient.setColorAt(0.0, transparentColor);

    painter.setBrush(QBrush(linearGradient));
    painter.drawEllipse(drawHollowCircleX[0], drawHollowCircleY[0], drawHollowCircleRadius[0], drawHollowCircleRadius[0]);
    painter.drawEllipse(drawHollowCircleX[1], drawHollowCircleY[1], drawHollowCircleRadius[1], drawHollowCircleRadius[1]);
}

//���Ʊ�׼��ɫ����
void colorDialog::drawColorStandard()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    for (int i=0; i<12; i++)
    {
        painter.setPen(drawColorStandardC[i]);
        painter.setBrush(QBrush(drawColorStandardC[i],Qt::SolidPattern));
        painter.drawRect(drawColorStandardX[i], drawColorStandardY[i], drawColorStandardW[i], drawColorStandardH[i]);
    }
}

//������ɫ����
void colorDialog::drawColorSelect()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(pickRadialColor);
    painter.setBrush(QBrush(pickRadialColor,Qt::SolidPattern));
    painter.drawRect(drawColorSelectX, drawColorSelectY, drawColorSelectW, drawColorSelectH);
}

//������ɫ
void colorDialog::setColor(QColor col)
{
    pickRadialColor = col;

    int colorH = 0;
    int colorS = 255;
    int colorV = 255;

    int iColorH = 0;
    int iColorS = 0;
    int iColorL = 0;

    int iLength = 0;

    pickRadialColor.getHsv(&colorH, &colorS, &colorV);
    pickRoundColor = QColor::fromHsv(colorH, colorS, colorV);

    drawHollowCircleCentreX[0] = drawRoundCentreX + ((drawRoundRadius - drawRoundHeight) / 2) * cos(colorH * PI / 180);
    drawHollowCircleCentreY[0] = drawRoundCentreY + ((drawRoundRadius - drawRoundHeight) / 2) * sin(colorH * PI / 180);
    drawHollowCircleX[0] = drawHollowCircleCentreX[0] - drawRoundHeight / 2;
    drawHollowCircleY[0] = drawHollowCircleCentreY[0] - drawRoundHeight / 2;

    pickRadialColor.getHsl(&iColorH, &iColorS, &iColorL);

    iLength = sqrt((qPow((((double)iColorL / 255.0) * (drawRadialRadius / 2)), 2)) / 2);

    drawHollowCircleCentreX[1] = drawRoundCentreX + iLength * cos(colorH * PI / 180);
    drawHollowCircleCentreY[1] = drawRoundCentreY + iLength * sin(colorH * PI / 180);
    drawHollowCircleX[1] = drawHollowCircleCentreX[1] - drawRoundHeight / 2;
    drawHollowCircleY[1] = drawHollowCircleCentreY[1] - drawRoundHeight / 2;

    update();
}

//��ȡ��ɫ
QColor colorDialog::getColor()
{
    return pickRadialColor;
}

//ѡ��ť
void colorDialog::selectBtnClicked()
{
    emit sendColor(getColor());
}

//ȡ����ť
void colorDialog::cancelBtnClicked()
{
    close();
}
