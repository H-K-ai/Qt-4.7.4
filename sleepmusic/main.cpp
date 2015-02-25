#include <QtGui/QApplication>
#include "maindialog.h"
#include "myfunc.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    //�����ݿ�
    mydatabase db;
    if(db.opendb("sleepmusic.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    //������Ӧ���ļ���
    createFolder("music"); //����
    createFolder("pic"); //ͼƬ

    QApplication a(argc, argv);
    mainDialog w;
    w.show();

    return a.exec();
}
