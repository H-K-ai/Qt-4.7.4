#include <QtGui/QApplication>
#include "logindialog.h"
#include "mydatabase.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

    QApplication a(argc, argv);

    //�����ݿ�
    mydatabase db;
    if(db.opendb("express.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    loginDialog w;
    w.show();

    return a.exec();
}
