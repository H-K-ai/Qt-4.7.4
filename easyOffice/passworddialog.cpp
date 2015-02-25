#include "passworddialog.h"
#include "ui_passworddialog.h"

passwordDialog::passwordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::passwordDialog)
{
    ui->setupUi(this);
}

passwordDialog::~passwordDialog()
{
    delete ui;
}

void passwordDialog::showEvent(QShowEvent *)
{
    ui->lineEdit->setText(loginName);
}

void passwordDialog::on_pushButton_clicked()
{
    //�޸�����
    QString name;
    QString tPwd1;
    QString tPwd2;
    QString sql;
    QSqlQuery query;

    name = ui->lineEdit->text().trimmed();
    tPwd1 = ui->lineEdit_3->text().trimmed();
    tPwd2 = ui->lineEdit_4->text().trimmed();

    if (tPwd1 == tPwd2)
    {
        sql = "update users set passwd = '" + tPwd1 + "' where name = '" + name + "'";
        query.exec(sql);
        QMessageBox::warning(this,tr("Success"),tr("successfully Modify!"), QMessageBox::Yes);

        ui->lineEdit_3->clear();    //��������������
        ui->lineEdit_4->clear();    //��ն����������������
        ui->lineEdit->setFocus();   //�����ת���û��������

        this->close();
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("Second password is not suit the first!"), QMessageBox::Yes);

        ui->lineEdit_3->clear();    //��������������
        ui->lineEdit_4->clear();    //��ն����������������
        ui->lineEdit->setFocus();   //�����ת���û��������
    }
}
