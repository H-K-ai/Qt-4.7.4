#include <QtGui/QApplication>
#include "logindialog.h"
#include "sqldate.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QApplication::setStyle(new QPlastiqueStyle);

    QApplication a(argc, argv);

    //�����ݿ�
    sqlDate db;
    if(db.opendb("fitMiss.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    //������Ӧ���ļ���
    createFolder("food");       //ʳ��
    createFolder("cookbook");   //ʳ��
    createFolder("sports");     //�˶�

    loginDialog w;
    w.show();

    return a.exec();
}
