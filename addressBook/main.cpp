#include <QtGui/QApplication>
#include "common.h"
#include "maindialog.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QApplication a(argc, argv);

    //�����ݿ�
    database db;
    if(db.opendb("address.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    //������Ӧ���ļ���
    createFolder("user");       //����

    mainDialog w;
    w.show();

    return a.exec();
}
