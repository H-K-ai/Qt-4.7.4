#include <QtGui/QApplication>
#include "common.h"
#include "database.h"
#include "logondialog.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QApplication a(argc, argv);

    //�����ݿ�
    database db;
    if(db.opendb("class.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    logonDialog w;
    w.show();

    return a.exec();
}
