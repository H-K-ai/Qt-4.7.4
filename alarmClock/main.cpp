#include <QtGui/QApplication>
#include "logondialog.h"
#include "common.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QApplication a(argc, argv);
    //�����ݿ�
    database db;
    if(db.opendb("alarmClock.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    //������Ӧ���ļ���
    createFolder("music"); //����

    logonDialog w;
    w.show();

    return a.exec();
}
