#include "staffdialog.h"
#include "ui_staffdialog.h"

staffDialog::staffDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::staffDialog)
{
    ui->setupUi(this);
}

staffDialog::~staffDialog()
{
    delete ui;
}

void staffDialog::on_pushButton_clicked()
{
    //��ѯ��Ʒ
    warw.show();
}

void staffDialog::on_pushButton_2_clicked()
{
    //�޸�����
    pwdw.show();
}
