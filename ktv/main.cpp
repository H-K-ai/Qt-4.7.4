#include <QtGui/QApplication>
#include "function.h"
#include "frontWidget.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    //�����ݿ�
    mydatabase db;
    if(db.opendb("ktv.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    //������Ӧ���ļ���
    createFolder("songsLibrary"); //������

    QApplication a(argc, argv);

    frontWidget w;
    w.show();

    return a.exec();
}
