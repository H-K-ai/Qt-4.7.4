#include <QtGui/QApplication>
#include "mainwindow.h"

//1.CEveluation��:����ʽ������,�Ը��������̽��й�ֵ.
//2.CMoveGenerator��:�߷�������,�Ը��������̾������������п��ܵ��߷�.
//3.CSearchEngine��:�����������.

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));

    QApplication a(argc, argv);    

    //������Ӧ���ļ���
    createFolder("chessboard");    //����

    mainWindow w;
    w.show();

    return a.exec();
}
