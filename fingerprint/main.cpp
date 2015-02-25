#include <QtGui/QApplication>
#include "common.h"
#include "database.h"
#include "logondialog.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    //�����ݿ�
    database db;
    if(db.opendb("fingerprint.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    logonDialog w;
    w.show();

    return a.exec();
}
