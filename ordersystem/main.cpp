#include <QtGui/QApplication>
#include "logdialog.h"
#include"mydatabase.h"
#include<qtextcodec.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("gb2312"));
    //�����ݿ�
    mydatabase  db;
    if(db.opendb("ordersystem.db"))
    {
        //�������ݿ��
        db.createtable();
    }


    logDialog w;
    w.show();

    //�����¼�ѭ��
    a.exec();

    //�ر����ݿ�
    db.closedb();

    return 0;
}
