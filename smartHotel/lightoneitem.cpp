#include "lightoneitem.h"

lightOneItem::lightOneItem()
{
    lightWidth = 302 * 0.8;
    lightHeight = 221 * 0.8;

    lightStep = 0;
}

QRectF lightOneItem::boundingRect() const
{
    //����item��ŵ�����
    qreal adjust = 2;
    return QRectF(-(lightWidth-adjust)/2, -(lightHeight-adjust)/2, (lightWidth+adjust), (lightHeight+adjust));
}

void lightOneItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    switch(lightStep % 2)
    {
    case 0:
        painter->drawPixmap(boundingRect().topLeft(), QPixmap(":/images/transparent.png").scaled(lightWidth, lightHeight, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        break;
    case 1:
        painter->drawPixmap(boundingRect().topLeft(), QPixmap(":/images/light1.png").scaled(lightWidth, lightHeight, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        break;
    default:
        painter->drawPixmap(boundingRect().topLeft(), QPixmap(":/images/light1.png").scaled(lightWidth, lightHeight, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        break;
    }
}

void lightOneItem::advance(int step)
{
    if (!step)
        return;
}

void lightOneItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //���
    lightStep++;

    update();
}

void lightOneItem::lightOn()
{
    lightStep = 1;

    update();
}

void lightOneItem::lightOff()
{
    lightStep = 0;

    update();
}

void lightOneItem::lightStepChange()
{
    //��������ı�
    lightStep++;

    update();
}


