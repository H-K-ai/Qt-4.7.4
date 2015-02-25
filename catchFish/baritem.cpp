#include "baritem.h"

barItem::barItem()
{
    barWidth = 765;
    barHeight = 72;
}

QRectF barItem::boundingRect() const
{
    //����item��ŵ�����
    qreal adjust = 2;
    return QRectF(-(barWidth-adjust)/2, -(barHeight-adjust)/2, (barWidth+adjust), (barHeight+adjust));
}

void barItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(boundingRect().topLeft(), QPixmap(":/images/bar.png"));
}

void barItem::advance(int step)
{
    if (!step)
        return;
}

int barItem::type() const
{
    //��������
    return BARITEM;
}



