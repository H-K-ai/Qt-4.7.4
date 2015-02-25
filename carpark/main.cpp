#include <QtGui/QApplication>
#include "userlogin.h"
#include "mydatabase.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QApplication::setStyle(new QPlastiqueStyle);

    QApplication a(argc, argv);

    //�����ݿ�
    mydatabase db;
    if(db.opendb("carpark.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    userlogin w;
    w.show();

    return a.exec();
}
