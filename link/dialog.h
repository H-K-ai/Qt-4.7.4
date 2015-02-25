#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "common.h"
#include "listdialog.h"
#include "recorddialog.h"
#include "chatdialog.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void paintEvent(QPaintEvent *); //��ͼ
    void mousePressEvent(QMouseEvent *event); //���ѹ��
    void randomp(); //������ɵ�ͼ
    void initPixmaps(); //������������
    bool matchChessman(); //ƥ������
    void gameLevelSetValue(); //���ݵȼ���ֵ
    bool matchDirect(chessman preManTmp, chessman nextManTmp); //ֱ������
    bool matchOneCorner(chessman preManTmp, chessman nextManTmp); //һ���ս�����
    bool matchTwoCorner(chessman preManTmp, chessman nextManTmp); //�����յ�����

    int gameLevel; //��Ϸ�ȼ�
    int manNum; //�������Ӹ���
    int manTypeNum; //��������������Ŀ
    int manWide; //���ӿ��
    int manHigh; //���Ӹ߶�
    QList<QPixmap> pixmaps; //ͼƬ�б�
    QPixmap backgroundPixmap; //����ͼ
    bool gamePause; //��ͣ��־
    bool gameStart; //��ʼ��־
    bool gameOver; //������־
    int gameOnline; //������Ϸ��־,0 ����, 1 ������, 2 ͬ����
    chessman preMan; //ǰһ������ѡ��
    chessman nextMan; //��һ������ѡ��
    int manSum;    //��Ϸ��������
    int manLeft;   //��Ϸʣ������

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void gameOnlineRandomp();

    void gameOnlineLevel();

    void gameOnlineServer();

    void gameOnlineClient();

    void gameOnlineProgressBar();

    void gameOnlineGameOver();

    void gamePlayerOne();

    void gamePlayerTwo();

private:
    Ui::Dialog *ui;
    listDialog listDlg;
    recordDialog recordDlg;
    ChatDialog chatDlg;
};

#endif // DIALOG_H
