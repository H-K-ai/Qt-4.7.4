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
    //��ַ��
    addw.show();
}

void mainDialog::on_pushButton_2_clicked()
{
    //��Ϣ����
    smsw.show();
}

void mainDialog::on_pushButton_3_clicked()
{
    //��Ա����
    userw.show();
}

void mainDialog::on_pushButton_4_clicked()
{
    //����
    aboutw.show();
}
