#include <QtGui/QApplication>
#include "myDatabase.h"
#include "loginwindow.h"

int main(int argc, char *argv[])
{

    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QApplication a(argc, argv);

    //�����ݿ�
    myDatabase db;
    if(db.opendb("propertySystem.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    loginWindow w;
    w.show();

    return a.exec();
}
