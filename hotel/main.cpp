#include <QtGui/QApplication>
#include "func.h"
#include "mydata.h"
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QApplication a(argc, argv);

    //�����ݿ�
    myData db;
    if(db.opendb("hotel.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    //������Ӧ���ļ���
    createFolder("room"); //����
    createFolder("staff"); //Ա��

    loginDialog w;
    w.show();

    return a.exec();
}

