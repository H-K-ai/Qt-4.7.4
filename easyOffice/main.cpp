#include <QtGui/QApplication>
#include "myfunc.h"
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QApplication a(argc, argv);

    //�����ݿ�
    database db;
    if(db.opendb("easyOffice.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    //������Ӧ���ļ���
    createFolder("supplies"); //�칫��Ʒ

    loginDialog w;
    w.show();

    return a.exec();
}
