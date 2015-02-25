#include <QtGui/QApplication>
#include "dialog.h"
#include "database.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QString sPath = a.applicationDirPath();
    a.addLibraryPath(sPath);

    QLibrary codecLib(sPath + "/codecs/qcncodecs4.dll");

    if (codecLib.load())
    {
    }
    else
    {
    }

    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

    //�����ݿ�
    database db;
    if(db.opendb("database.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    Dialog w;
    w.show();

    return a.exec();
}
