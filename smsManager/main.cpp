#include <QtGui/QApplication>
#include "logondialog.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QApplication::setStyle(new QCleanlooksStyle);
    QApplication a(argc, argv);

    //�����ݿ�
    database db;
    if(db.opendb("sms.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    //������Ӧ���ļ���
    createFolder("user");       //����

    logonDialog w;
    w.show();

    return a.exec();
}
