#include "mainwindow.h"
#include <QtGui/QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    //����֧��
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    //�̶�д��
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
