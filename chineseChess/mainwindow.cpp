#include "mainwindow.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);

    //������������.������ʾ����
    //��ʼ������
    chessGameOver = 0;

    memcpy(m_ChessBoard, InitChessBoard, 4*90);

    m_MoveChess.nChessID = NOCHESS;
    m_BoardBmp.load(":/pic/board.png");
    m_Chessman.load(":/pic/chessmanBLACK.png");
    chessmanRed = false;

    CMoveGenerator *pMG;
    CEveluation *pEvel;
    //����������ֵ��������
    m_pSE = new CNegaMaxEngine;
    //�����߷�������
    pMG = new CMoveGenerator;
    //������ֵ����
    pEvel = new CEveluation;

    //�趨��������Ϊ3
    m_pSE->SetSearchDepth(3);
    //�����������趨�߷�������
    m_pSE->SetMoveGenerator(pMG);
    //�����������趨��ֵ����
    m_pSE->SetEveluator(pEvel);
    ui->pushButton_3->setEnabled(false);
}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::paintEvent(QPaintEvent *)
{
    //��ͼ
    int i = 0;
    int j = 0;
    QPixmap temp;
    QPainter painter(this);

    temp = m_BoardBmp.scaled(BOARDWIDTH, BOARDHEIGHT, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    painter.drawPixmap(BOARDSTARTX, BOARDSTARTY, temp);

    for(i=0; i<10; i++)
        for(j=0; j<9; j++)
        {
            if(m_ChessBoard[i][j] == NOCHESS)
                continue;
            temp = m_Chessman.copy((m_ChessBoard[i][j]-1)*GRILLEWIDTH, 0, GRILLEWIDTH, GRILLEHEIGHT);
            painter.drawPixmap(BOARDSTARTY+BOARDMANY+j*(GRILLEHEIGHT+10), BOARDSTARTX+BOARDMANX+i*(GRILLEWIDTH+10), temp);
        }
    //�����û������϶�������
    if (m_MoveChess.nChessID != NOCHESS)
    {
        temp = m_Chessman.copy((m_MoveChess.nChessID - 1)*GRILLEWIDTH, 0, GRILLEWIDTH, GRILLEHEIGHT);
        painter.drawPixmap(m_MoveChess.ptMovePoint, temp);
    }
}

void mainWindow::mousePressEvent(QMouseEvent *event)
{
    //���ѹ��
    int x,y;
    //�����껻��������ϵĸ���
    y = (event->y() - (BOARDSTARTX + BOARDMANX)) / (GRILLEHEIGHT + 10);
    x = (event->x() - (BOARDSTARTY + BOARDMANY)) / (GRILLEWIDTH + 10);

    //���ݵ�ǰ����
    memcpy(m_BackupChessBoard, m_ChessBoard, 4*90);
    //�ж�����Ƿ���������,���ҵ����˺췽(�û�)����
    if(x>=0 && x<9 && y>=0 && y<10  && IsRed(m_ChessBoard[y][x]))
    {
        //��������
        memcpy(m_BackupChessBoard, m_ChessBoard, 4*90);
        m_ptMoveChess.setX(x);
        m_ptMoveChess.setY(y);
        m_MoveChess.nChessID = m_ChessBoard[y][x];
        //��������ԭλ������ȥ��
        m_ChessBoard[m_ptMoveChess.y()][m_ptMoveChess.x()] = NOCHESS;
        //�������е�����λ��������ڵ�
        m_MoveChess.ptMovePoint.setX(event->x()-20);
        m_MoveChess.ptMovePoint.setY(event->y()-20);
        //�ػ���Ļ
        update(BOARDSTARTX, BOARDSTARTY, BOARDWIDTH, BOARDHEIGHT);
    }
}
void mainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //����ƶ�
    int x = 0;
    int y = 0;
    if(m_MoveChess.nChessID)
    {
        //��ֹ�������ϳ�����
        if(event->x() < BOARDSTARTX+10) //����
            x = BOARDSTARTX+10;
        if(event->y() < BOARDSTARTY+10) //����
            y = BOARDSTARTY+10;
        if(event->x() > BOARDWIDTH) //�ұ�
            x = BOARDWIDTH;
        if(event->y() > BOARDHEIGHT) //����
            y = BOARDHEIGHT;

        //�����ӵ�����λ��������ڴ�
        if (x == 0) //xû����
            m_MoveChess.ptMovePoint.setX(event->x()-20);
        else
            m_MoveChess.ptMovePoint.setX(x-20);
        if (y == 0) //yû����
            m_MoveChess.ptMovePoint.setY(event->y()-20);
        else
            m_MoveChess.ptMovePoint.setY(y-20);

        //ˢ�´���
        update(BOARDSTARTX, BOARDSTARTY, BOARDWIDTH, BOARDHEIGHT);
    }
}

//ȫ�ֱ�������,����ͳ��Ҷ�ӽڵ���Ŀ
extern int count;
void mainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    //����ɿ�
    bool bTurnSide = FALSE;
    QTime timeCount;
    int x, y;
    //�����껻��������ϵĸ���
    y = (event->y() - (BOARDSTARTX + BOARDMANX)) / (GRILLEHEIGHT + 10);
    x = (event->x() - (BOARDSTARTY + BOARDMANY)) / (GRILLEWIDTH + 10);

    //�ж��Ƿ����ƶ�����,���Ҹ����ӵ��ƶ���һ���Ϸ��߷�
    if(m_MoveChess.nChessID && CMoveGenerator::IsValidMove(m_BackupChessBoard,
                                                           m_ptMoveChess.x(), m_ptMoveChess.y(), x, y))
    {
        m_ChessBoard[y][x] = m_MoveChess.nChessID;
        bTurnSide = true;
        ui->pushButton_3->setEnabled(true);
    }
    else
    {
        //�ָ��ƶ�ǰ������״̬
        memcpy(m_ChessBoard, m_BackupChessBoard, 4*90);
    }
    //���ƶ����������
    m_MoveChess.nChessID = NOCHESS;
    //�ػ���Ļ
    update(BOARDSTARTX, BOARDSTARTY, BOARDWIDTH, BOARDHEIGHT);
    //�ͷ���꽹��
    //    ReleaseCapture();

    if(bTurnSide == true)
    {
        //ȡ��ʼ��ʱ��
        timeCount.start();
        //�õ�������һ��
        m_pSE->SearchAGoodMove(m_ChessBoard);
        gameIsOver(m_ChessBoard);

        if(chessGameOver == 1)
        {
            QMessageBox::information(NULL, tr("Game Over"), tr("����Ӯ��,ͬ־����Ŭ��!"));
        }
        if(chessGameOver == 2)
        {
            QMessageBox::information(NULL, tr("Game Over"), tr("Ӣ��սʤ����!"));
        }

        QString sNodeCount = QString("���Թ�����:\n%1����\n\n����:\n%2���߷�!")
                .arg(timeCount.elapsed()).arg(count);
        //���������Ϣ
        ui->label->setText(sNodeCount);
    }
    //����������
    count = 0;
    //�ػ���Ļ
    update(BOARDSTARTX, BOARDSTARTY, BOARDWIDTH, BOARDHEIGHT);
}

void mainWindow::on_pushButton_clicked()
{
    //����Ϸ
    CMoveGenerator  *pMG;
    CEveluation	    *pEvel;

    if(m_pSE)
        //�ͷžɵ���������
        delete m_pSE;

    m_pSE = new CNegaMaxEngine;
    pEvel = new CEveluation;

    //��ʼ������
    memcpy(m_ChessBoard, InitChessBoard, 4*90);
    //����ƶ�����
    m_MoveChess.nChessID = NOCHESS;
    //�����߷�������
    pMG = new CMoveGenerator;
    //���߷�������������������
    m_pSE->SetMoveGenerator(pMG);
    //����ֵ���Ĵ�����������
    m_pSE->SetEveluator(pEvel);
    //ˢ�´���
    chessGameOver = 0;
    ui->pushButton_3->setEnabled(false);
    ui->comboBox->setCurrentIndex(0);

    update();
}

void mainWindow::on_pushButton_2_clicked()
{
    //����
    QMessageBox::information(NULL, tr("Game Over"), tr("����Ӯ��,ͬ־����Ŭ��!"));
    on_pushButton_clicked();
}

void mainWindow::on_pushButton_3_clicked()
{
    //����
    memcpy(m_ChessBoard, m_BackupChessBoard, 4*90);
    ui->pushButton_3->setEnabled(false);
    update();
}

void mainWindow::on_pushButton_4_clicked()
{
    //��������
    int i, j;
    switch(ui->comboBox->currentIndex())
    {
    case 0:
        for(i=0; i<10; i++)
            for(j=0; j<9; j++)
                if(m_ChessBoard[i][j] == B_CAR)
                    m_ChessBoard[i][j] = NOCHESS;
        break;
    case 1:
        for(i=0; i<10; i++)
            for(j=0; j<9; j++)
                if(m_ChessBoard[i][j] == B_HORSE)
                    m_ChessBoard[i][j] = NOCHESS;
        break;
    case 2:
        for(i=0; i<10; i++)
            for(j=0; j<9; j++)
                if(m_ChessBoard[i][j] == B_CANON)
                    m_ChessBoard[i][j] = NOCHESS;
        break;
    default:
        break;
    }

    update();
}

void mainWindow::on_pushButton_5_clicked()
{
    //�������
    QString targetPath = QFileDialog::getSaveFileName(this, tr("save"), "./chessboard/Chessboard" + QDateTime::currentDateTime().toString("dd-MM-yyyy") + ".cb", tr("Chessboard Files(*.cb)"));
    if(targetPath.length() == 0)
    {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
    }
    else
    {
        QMessageBox::information(NULL, tr("save"), tr("success!"));

        QFile f(targetPath);
        f.open(QIODevice::WriteOnly);
        QTextStream t(&f);
        t << chessmanDataToFile(m_ChessBoard);
        f.close();
    }
}

void mainWindow::on_pushButton_6_clicked()
{
    //�������
    QString sourcePath = QFileDialog::getOpenFileName(this, tr("open"), "./chessboard", tr("Chessboard Files(*.cb)"));
    if(sourcePath.length() == 0)
    {
        QMessageBox::information(NULL, tr("open"), tr("You didn't select any files."));
    }
    else
    {
        QMessageBox::information(NULL, tr("open"), tr("success!"));

        QFile f(sourcePath);
        f.open(QIODevice::ReadOnly);
        QTextStream t(&f);
        chessmanDataFromFile(t.read(90), m_ChessBoard);
        f.close();

        update();
    }
}

void mainWindow::on_pushButton_7_clicked()
{
    //������ɫ
    if(chessmanRed == false)
    {
        m_Chessman.load(":/pic/chessmanRED.png");
        chessmanRed = true;
    }
    else
    {
        m_Chessman.load(":/pic/chessmanBLACK.png");
        chessmanRed = false;
    }

    update();
}
