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
    //����Ԥ��
    roompreDlg.show();
}

void mainDialog::on_pushButton_2_clicked()
{
    //��ס��Ϣ
    checkinDlg.show();
}

void mainDialog::on_pushButton_3_clicked()
{
    //Ա������
    staffDlg.show();
}

void mainDialog::on_pushButton_4_clicked()
{
    //��Ա����
    memberDlg.show();
}

void mainDialog::on_pushButton_5_clicked()
{
    //�˻�����
    accountDlg.show();
}
