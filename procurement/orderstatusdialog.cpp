#include "orderstatusdialog.h"
#include "ui_orderstatusdialog.h"

orderStatusDialog::orderStatusDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::orderStatusDialog)
{
    ui->setupUi(this);
}

orderStatusDialog::~orderStatusDialog()
{
    delete ui;
}

void orderStatusDialog::showEvent(QShowEvent *)
{
    ui->lineEdit->clear();
    ui->comboBox->setCurrentIndex(0);
}

void orderStatusDialog::on_pushButton_clicked()
{
    //��ѯ
    QSqlQuery query;
    query.exec("select status from orderform where orderformcode = '" + ui->lineEdit->text().trimmed() + "'");
    while(query.next())
    {
        ui->comboBox->setCurrentIndex(query.value(0).toInt());
        return;
    }

    QMessageBox::information(NULL, "warring", "������û���ҵ�!");
}

void orderStatusDialog::on_pushButton_2_clicked()
{
    //�޸�
    QSqlQuery query;
    query.exec("update orderform set status = '" + QString::number(ui->comboBox->currentIndex(), 10)
               + QString("' where orderformcode = '") + ui->lineEdit->text().trimmed() + "'");

    QMessageBox::information(NULL, "success", "�޸ĳɹ�!");
}
