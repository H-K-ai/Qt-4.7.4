#include "searchdialog.h"
#include "ui_searchdialog.h"

searchDialog::searchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchDialog)
{
    ui->setupUi(this);
}

searchDialog::~searchDialog()
{
    delete ui;
}

void searchDialog::on_pushButton_clicked()
{
    //Ԥ������ѯ
    bookw.show();
}

void searchDialog::on_pushButton_2_clicked()
{
    //��ס����ѯ
    inw.show();
}

void searchDialog::on_pushButton_3_clicked()
{
    //�޷�����
    callw.show();
}
