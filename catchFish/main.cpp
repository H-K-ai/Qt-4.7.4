#include <QtGui/QApplication>
#include "common.h"
#include "logondialog.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QApplication a(argc, argv);

    //�����ݿ�
    database db;
    if(db.opendb("fish.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    //�������
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    logonDialog w;
    w.show();

    return a.exec();
}
