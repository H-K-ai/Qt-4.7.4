#include <QtGui/QApplication>
#include "logindialog.h"
#include "mysqldata.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QApplication::setStyle(new QPlastiqueStyle);

    QApplication a(argc, argv);

    //�����ݿ�
    mysqldata db;
    if(db.opendb("football.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    //������Ӧ���ļ���
    createFolder("player");       //ʳ��

    loginDialog w;
    w.show();

    return a.exec();
}
