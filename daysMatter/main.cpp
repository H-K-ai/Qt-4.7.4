#include <QtGui/QApplication>
#include "loginwindow.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QApplication a(argc, argv);

    //�ж��Ƿ���ڱ������ݿ�
    if(QFile::exists("backup.db"))
    {
        //����
        copyFileToPath("backup.db", "daysMatter.db", true);
        QFile::remove("backup.db");
    }

    //�����ݿ�
    if(db.opendb("daysMatter.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    //������Ӧ���ļ���
    createFolder("dataBackup");    //���ݱ���

    loginWindow w;
    w.show();

    return a.exec();
}
