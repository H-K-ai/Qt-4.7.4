#include <QtGui/QApplication>
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QApplication::setStyle(new QPlastiqueStyle);

    QApplication a(argc, argv);

    //�����ݿ�
    mydatabase db;
    if(db.opendb("procurement.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    loginDialog w;
    w.show();

    return a.exec();
}
