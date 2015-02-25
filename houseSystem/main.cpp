#include <QtGui/QApplication>
#include "loginwindow.h"
#include "mydatabase.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QApplication::setStyle(new QPlastiqueStyle);
    QApplication a(argc, argv);

    //�����ݿ�
    mydatabase db;
    if(db.opendb("houseSystem.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    //������Ӧ���ļ���
    createFolder("house");    //¥��
    createFolder("property"); //��Ȩ
    createFolder("grade");    //�Ǽ�
    createFolder("record");   //����

    loginWindow logWindow;

    logWindow.show();

    return a.exec();
}
