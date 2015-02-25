#include <QtGui/QApplication>
#include "maindialog.h"
#include "mydatabase.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

    QApplication a(argc, argv);

    myDatabase db;
    if(db.opendb("map.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    mainDialog w;
    w.show();

    return a.exec();
}
