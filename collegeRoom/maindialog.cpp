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
    //ѧ����Ϣ����
    stuw.show();
}

void mainDialog::on_pushButton_2_clicked()
{
    //ʵ���ҹ���
    libw.show();
}

void mainDialog::on_pushButton_3_clicked()
{
    //�γ���Ϣ����
    subw.show();
}

void mainDialog::on_pushButton_4_clicked()
{
    //ʵ����ԤԼ
    libtimew.show();
}

void mainDialog::on_pushButton_6_clicked()
{
    //��¼��Ա����
    userw.show();
}
