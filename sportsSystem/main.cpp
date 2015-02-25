#include <QtGui/QApplication>
#include "loginsystem.h"
#include "database.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QApplication::setStyle(new QCleanlooksStyle);
    QApplication a(argc, argv);

    //�����ݿ�
    database db;
    if(db.opendb("cosmeticsSystem.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    //������Ӧ���ļ���
    createFolder("goods"); //��Ʒ
    createFolder("depot"); //�ֿ�
    createFolder("member");//��Ա

    loginSystem w;
    w.show();

    return a.exec();
}
