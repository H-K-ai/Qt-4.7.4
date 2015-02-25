#include <QtGui/QApplication>
#include "logindialog.h"
#include "sqldata.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QApplication a(argc, argv);

    //�����ݿ�
    sqldata db;
    if(db.opendb("gymnasium.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    loginDialog w;
    w.show();

    return a.exec();
}
