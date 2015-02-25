#include "maindialog.h"
#include "ui_maindialog.h"

mainDialog::mainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainDialog)
{
    ui->setupUi(this);
}

mainDialog::~mainDialog()
{
    delete ui;
}

void mainDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/png/main.png").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void mainDialog::on_pushButton_clicked()
{
    //��λ����
    spacew.show();
}

void mainDialog::on_pushButton_2_clicked()
{
    //���������
    carw.show();
}

void mainDialog::on_pushButton_3_clicked()
{
    //�����ѯ
    incomew.show();
}

void mainDialog::on_pushButton_4_clicked()
{
    //��Ա����
    userw.show();
}
