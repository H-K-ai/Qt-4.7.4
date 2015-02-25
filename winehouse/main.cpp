#include <QtGui/QApplication>
#include "maindialog.h"
#include "mydatabase.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QApplication a(argc, argv);

    //�����ݿ�
    mydatabase db;
    if(db.opendb("winehouse.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    mainDialog w;
    w.show();

    return a.exec();
}
