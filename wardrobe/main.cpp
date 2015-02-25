#include <QtGui/QApplication>
#include "myfunc.h"
#include "wardrobewindow.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QApplication a(argc, argv);

    //�����ݿ�
    database db;
    if(db.opendb("wardrobe.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    //������Ӧ���ļ���
    createFolder("clothes"); //�·�
    createFolder("matchclothes"); //�·�

    wardrobeWindow w;
    w.show();

    return a.exec();
}
