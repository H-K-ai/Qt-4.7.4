#include <QtGui/QApplication>
#include "common.h"
#include "logondialog.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    QApplication a(argc, argv);

    //�����ݿ�
    database db;
    if(db.opendb("chat.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    logonDialog w;
    w.show();

    return a.exec();
}
