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
    //��Ϣ����
    stuw.show();
}

void mainDialog::on_pushButton_3_clicked()
{
    //��Ա����
    userw.show();
}

void mainDialog::on_pushButton_2_clicked()
{
    //���֤��ѯ
    idnumw.show();
}

void mainDialog::on_pushButton_4_clicked()
{
    //�໤�˲�ѯ
    stuidw.show();
}

void mainDialog::on_pushButton_5_clicked()
{
    //������ѯ
    namew.show();
}

void mainDialog::on_pushButton_6_clicked()
{
    //�绰��ѯ
    phonew.show();
}
