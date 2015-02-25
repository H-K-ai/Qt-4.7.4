#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include "commfunc.h"
#include "CMoveGenerator.h"
#include "CEveluation.h"
#include "CNegaMaxEngine.h"
#include "CSearchEngine.h"

namespace Ui {
    class mainWindow;
}

class mainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = 0);
    ~mainWindow();
    void paintEvent(QPaintEvent *); //��ͼ
    void mousePressEvent(QMouseEvent *event); //���ѹ��
    void mouseMoveEvent(QMouseEvent *event);  //����ƶ�
    void mouseReleaseEvent(QMouseEvent *event);  //����ɿ�

    //������������.������ʾ����
    int m_ChessBoard[10][9];
    //������������.���ڳ���ָ�
    int m_BackupChessBoard[10][9];
    //���ڱ��浱ǰ����ק�����ӵĽṹ
    MOVECHESS m_MoveChess;
    //���뱣�浱ǰ����ק�����ӵ�λ��
    QPoint m_ptMoveChess;
    //������ʾ����
    QPixmap m_BoardBmp;
    //�û���������
    QPixmap m_Chessman;
    //���Ӻ�ڱ�־
    bool chessmanRed;
    //��������ָ��
    CSearchEngine *m_pSE;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::mainWindow *ui;
};

#endif // MAINWINDOW_H
