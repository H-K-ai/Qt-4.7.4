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

void mainDialog::on_pushButton_clicked()
{
    //�ͻ�������Ϣ
    clientw.show();
}

void mainDialog::on_pushButton_2_clicked()
{
    //����������Ϣ
    orderw.show();
}

void mainDialog::on_pushButton_4_clicked()
{
    //����״̬��Ϣ
    ordersw.show();
}

void mainDialog::on_pushButton_3_clicked()
{
    //��Ʒ������Ϣ
    goodsw.show();
}

void mainDialog::on_pushButton_5_clicked()
{
    //�����޸�
    pwdw.show();
}

void mainDialog::on_pushButton_6_clicked()
{
    //�˳�
    this->close();
}
