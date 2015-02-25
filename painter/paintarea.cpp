#include "paintarea.h"
#include <QPainter>
#include <QPrintDialog>
#include <QPrinter>
#include <QMessageBox>
#include<qvector.h>
int presscount=0;
PaintArea::PaintArea()
{
    //��ʼ������
    image = QImage(520,390,QImage::Format_RGB32); //�����ĳ�ʼ����С��Ϊ520,390��ʹ��32λ��ɫ
    backColor = qRgb(255,255,255); //������ʼ������ɫʹ�ð�ɫ
    image.fill(backColor);
    modified = false;
    angle = 0;

    penColor = Qt::black;
    brushColor = Qt::white;
    penWidth = 1;
    penStyle = Qt::SolidLine;
    curShape = None;
    isDrawing = false;
}
void PaintArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this); 
    if(isDrawing)   //������ڻ�������ͼ�Σ�����ʾ��ʱ��ͼ���ϵ�����
    { 
        painter.drawImage(0,0,tempImage);
    } 
    else 
    { 
        if(angle) 
        { 
            QImage copyImage = image;  //�½���ʱ�� copyImage��������������ת���� 
            QPainter pp(&copyImage); 
            QPointF center(copyImage.width()/2.0,copyImage.height()/2.0); 
            pp.translate(center); 
            pp.rotate(angle); 
            pp.translate(-center); 
            pp.drawImage(0,0,image); 
            image = copyImage;   //ֻ�Ḵ��ͼƬ�ϵ����ݣ����Ḵ������ϵͳ 
            angle = 0;   //�����ת�󽫽Ƕ�ֵ������Ϊ 0 
        }
        painter.drawImage(0,0,image); 
    }
}
void PaintArea::mousePressEvent(QMouseEvent *event)
{
    //���ѹ��
    if(event->button() == Qt::LeftButton)
    {
        lastPoint = event->pos();

        isDrawing = true;
    }
}
void PaintArea::mouseMoveEvent(QMouseEvent *event)
{
    //����ƶ�
    if(event->buttons()&Qt::LeftButton)
    {
        endPoint = event->pos();
        if(curShape == None)
        {
            isDrawing = false;
            paint(image);
        }
        else
        {
            tempImage = image;
            paint(tempImage);
        }
    }
}
void PaintArea::mouseReleaseEvent(QMouseEvent *event)
{
    //����ͷ�
    if(event->button() == Qt::LeftButton)
    {
        endPoint = event->pos();
        isDrawing = false;
        paint(image);
    }
}
void PaintArea::paint(QImage &theImage)
{
    //��ͼ
    QPainter pp(&theImage);
    QPen pen = QPen();
    pen.setColor(penColor);
    pen.setStyle(penStyle);
    pen.setWidth(penWidth);
    QBrush brush = QBrush(brushColor);
    pp.setPen(pen);
    pp.setBrush(brush);
    int x,y,w,h,f,g;
    x = lastPoint.x();
    y = lastPoint.y();
    w = endPoint.x() - x;
    h = endPoint.y() - y;
    jiao[2]=endPoint;
    f=(lastPoint.x()+endPoint.x())/2;

    switch(curShape)
    {
    case None:
    {
        pp.drawLine(lastPoint,endPoint);
        lastPoint = endPoint;
        presscount=0;
        break;
    }
    case Line:
    {
        pp.drawLine(lastPoint,endPoint);
        presscount=0;
        break;
    }
    case Rectangle:
    {
        pp.drawRect(x,y,w,h);
        presscount=0;
        break;
    }
    case Ellipse:
    {
        pp.drawEllipse(x,y,w,h);
        presscount=0;
        break;
    }
    case Triangle:
    {
	QPolygonF polygon;
	
        polygon << QPointF( lastPoint.x(), endPoint.y())<<endPoint << QPointF(f, lastPoint.y());
        presscount=0;
        pp.drawPolygon(polygon, Qt::WindingFill);
        break;
    }
    default:
    {
        break;
    }
    }
    update(); //���и��½�����ʾ�������𴰿��ػ��¼����ػ洰��
    modified = true;
}
void PaintArea::setImageSize(int width, int height)
{
    //����ͼ���С
    QImage newImage(width,height,QImage::Format_RGB32);
    image = newImage;
    update();
}
void PaintArea::setImageColor(QColor color)
{
    //����ͼ����ɫ
    backColor = color.rgb(); //��Ϊimage�ı���ɫҪ��QRgb���͵���ɫ���������������һ��ת��
    image.fill(backColor);
    update();
}
bool PaintArea::saveImage(const QString &fileName, const char *fileFormat)
{
    //����ͼƬ
    QImage visibleImage = image;
    if (visibleImage.save(fileName, fileFormat))
    {
        modified = false;
        return true;
    }
    else
    {
        return false;
    }
}
bool PaintArea::openImage(const QString &fileName)
{
    //��ͼƬ
    QImage loadedImage;
    if (!loadedImage.load(fileName))
        return false;
    QSize newSize = loadedImage.size();
    setImageSize(newSize.width(),newSize.height());
    image = loadedImage;
    modified = false;
    update();
    return true;
}
QSize PaintArea::getImageSize()
{
    //��ȡͼ���С
    return image.size();
}
void PaintArea::aboutus()
{
    //����
    QMessageBox::StandardButton boxus;
    boxus = QMessageBox::information(this,tr("���ڻ�ͼ��"),tr("������ϢѧԺ"),
                                     QMessageBox::Yes);
}
void PaintArea::doRotate()
{
    //��ת
    angle +=90;
    update();
}
void PaintArea::doClear()
{
    //���
    image.fill(backColor); //�����ڵĻ�������ɫ�������
    update();
}
void PaintArea::setPenStyle(Qt::PenStyle style)
{
    //���ñ�
    penStyle = style;
}
void PaintArea::setPenWidth(int width)
{
    //���ÿ��
    penWidth = width;
}
void PaintArea::setPenColor(QColor color)
{
    //������ɫ
    penColor = color;
}
void PaintArea::setBrushColor(QColor color)
{
    //����ˢ��
    brushColor = color;
}
void PaintArea::setShape(ShapeType shape)
{
    //���ñʻ�����
    curShape = shape;
}
