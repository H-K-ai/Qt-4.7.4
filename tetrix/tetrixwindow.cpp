#include "tetrixwindow.h"
#include "tetrixboard.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QGridLayout>
#include <QDebug>

TetrixWindow::TetrixWindow()
{
    board = new TetrixBoard();
    nextPieceLabel = new QLabel();
    nextPieceLabel->setFrameStyle(QFrame::NoFrame);
    nextPieceLabel->setAlignment(Qt::AlignCenter);
    nextPieceLabel->setFixedWidth(80);
    nextPieceLabel->setFixedHeight(80);
    board->setNextPieceLabel(nextPieceLabel);

    levelLCD = new QLCDNumber(5);
    levelLCD->setFixedWidth(80);
    levelLCD->setFrameStyle(QLCDNumber::NoFrame);
    levelLCD->setSegmentStyle(QLCDNumber::Flat);

    scoreLCD = new QLCDNumber(5);
    scoreLCD->setFixedWidth(80);
    scoreLCD->setFrameStyle(QLCDNumber::NoFrame);
    scoreLCD->setSegmentStyle(QLCDNumber::Flat);

    startButton = new QPushButton(tr("��ʼ"));
    startButton->setFixedWidth(80);
    startButton->setFocusPolicy(Qt::NoFocus);
    pauseButton = new QPushButton(tr("��ͣ"));
    pauseButton->setFixedWidth(80);
    pauseButton->setFocusPolicy(Qt::NoFocus);
    topButton = new QPushButton(tr("���а�"));
    topButton->setFixedWidth(80);
    topButton->setFocusPolicy(Qt::NoFocus);

    easyRadio = new QRadioButton(tr("��"));
    easyRadio->setFixedWidth(80);
    easyRadio->setChecked(true);
    normalRadio = new QRadioButton(tr("����"));
    normalRadio->setFixedWidth(80);
    hardRadio = new QRadioButton(tr("����"));
    hardRadio->setFixedWidth(80);
    radioGroup = new QButtonGroup(this);
    radioGroup->addButton(easyRadio);
    radioGroup->addButton(normalRadio);
    radioGroup->addButton(hardRadio);
    radioGroup->setId(easyRadio, 0);
    radioGroup->setId(normalRadio, 1);
    radioGroup->setId(hardRadio, 2);
    // ��ǰ���� - (��ǰ�ȼ� - 1) * 5 >=  5 �� �ȼ�+1
    // ��������ÿ���ʱ��Ϊ 1000/(��ǰ�ȼ�+����ѡ��)

    QVBoxLayout *rightBox = new QVBoxLayout;
    rightBox->addWidget(createLabel(tr("Next")));
    rightBox->addWidget(nextPieceLabel);
    rightBox->addWidget(createLabel(tr("Level")));
    rightBox->addWidget(levelLCD);
    rightBox->addWidget(createLabel(tr("Score")));
    rightBox->addWidget(scoreLCD);
    rightBox->addWidget(startButton);
    rightBox->addWidget(pauseButton);
    rightBox->addWidget(topButton);
    rightBox->addWidget(easyRadio);
    rightBox->addWidget(normalRadio);
    rightBox->addWidget(hardRadio);
    rightBox->addStretch(1);

    connect(startButton,SIGNAL(clicked()),board,SLOT(start()));
    connect(pauseButton,SIGNAL(clicked()),board,SLOT(pause()));
    connect(topButton,SIGNAL(clicked()),board,SLOT(showTopList()));
    connect(this,SIGNAL(hardChanged(int)),board,SLOT(setHard(int)));
    connect(easyRadio,SIGNAL(clicked()),this,SLOT(setHard()));
    connect(normalRadio,SIGNAL(clicked()),this,SLOT(setHard()));
    connect(hardRadio,SIGNAL(clicked()),this,SLOT(setHard()));
    connect(board,SIGNAL(levelChanged(int)),levelLCD,SLOT(display(int)));
    connect(board,SIGNAL(scoreChanged(int)),scoreLCD,SLOT(display(int)));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(board);
    layout->addLayout(rightBox);

    setLayout(layout);
    setWindowTitle(tr("Tetrix"));
    setFixedSize(470, 624);
}


void TetrixWindow::setHard()
{
    int hard = 0;
    hard = radioGroup->checkedId();
    emit hardChanged(hard);
}


QLabel *TetrixWindow::createLabel(const QString &text){
    QLabel *label = new QLabel(text);
    label->setAlignment(Qt::AlignCenter);
    return label;
}
