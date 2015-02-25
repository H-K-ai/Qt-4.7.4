#include "pauseitem.h"

pauseItem::pauseItem()
{
    pauseWidth = 308;
    pauseHeight = 250;
}

QRectF pauseItem::boundingRect() const
{
    //����item��ŵ�����
    qreal adjust = 2;
    return QRectF(-(pauseWidth-adjust)/2, -(pauseHeight-adjust)/2, (pauseWidth+adjust), (pauseHeight+adjust));
}

void pauseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect().topLeft(), QPixmap(":/images/pause.png"));
}

void pauseItem::advance(int step)
{
    if (!step)
        return;
}

int pauseItem::type() const
{
    //��������
    return PAUSEITEM;
}

