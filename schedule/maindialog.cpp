#include "maindialog.h"
#include "ui_maindialog.h"

mainDialog::mainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainDialog)
{
    ui->setupUi(this);

    connect(&stuw, SIGNAL(modifyStu()), &courw, SLOT(initDialog()));
    connect(&stuw, SIGNAL(modifyStu()), &scow, SLOT(initDialog()));
    connect(&subw, SIGNAL(modifySub()), &courw, SLOT(initDialog()));
    connect(&subw, SIGNAL(modifySub()), &scow, SLOT(initDialog()));
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
    //�α����
    subw.show();
}

void mainDialog::on_pushButton_3_clicked()
{
    //�γ̰��Ź���
    courw.show();
}

void mainDialog::on_pushButton_4_clicked()
{
    //ѧ���ɼ�����
    scow.show();
}

void mainDialog::on_pushButton_5_clicked()
{
    //�û���Ϣ����
    userw.show();
}
