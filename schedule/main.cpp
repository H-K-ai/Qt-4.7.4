#include <QtGui/QApplication>
#include "logindialog.h"
#include "mydatabase.h"
#include "common.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QApplication a(argc, argv);

    //�����ݿ�
    mydatabase db;
    if(db.opendb("schedule.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    //������Ӧ���ļ���
    createFolder("student");    //���ݱ���

    loginDialog w;
    w.show();

    return a.exec();
}
