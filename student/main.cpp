#include <QtGui/QApplication>
#include "logindialog.h"
#include "mydatabase.h"

//�����ļ���
bool createFolder(const QString dir)
{
    QDir *temp = new QDir;
    bool exist = temp->exists(dir);
    if(exist)
        return false;
    else
    {
        bool ok = temp->mkdir(dir);
        if(ok)
            qDebug() << "success" << endl;
    }

    return true;
}

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QApplication a(argc, argv);

    //�����ݿ�
    mydatabase db;
    if(db.opendb("student.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    //������Ӧ���ļ���
    createFolder("student");    //���ݱ���

    loginDialog w;
    w.show();

    return a.exec();
}
