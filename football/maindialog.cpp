#include "maindialog.h"
#include "ui_maindialog.h"

mainDialog::mainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainDialog)
{
    ui->setupUi(this);

    connect(&playerw, SIGNAL(addPlayer()), &scorew, SLOT(initComboBox()));
    connect(&gamew, SIGNAL(addGame()), &scorew, SLOT(initComboBox()));
}

mainDialog::~mainDialog()
{
    delete ui;
}

void mainDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/jpg/4.jpg").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void mainDialog::on_pushButton_clicked()
{
    //��Ա��Ϣ����
    playerw.show();
}

void mainDialog::on_pushButton_2_clicked()
{
    //��Ա�ɼ�����
    scorew.show();
}

void mainDialog::on_pushButton_3_clicked()
{
    //���ֲ���֧����
    accw.show();
}

void mainDialog::on_pushButton_4_clicked()
{
    //���̹���
    gamew.show();
}
