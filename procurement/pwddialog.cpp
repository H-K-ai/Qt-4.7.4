#include "pwddialog.h"
#include "ui_pwddialog.h"

pwdDialog::pwdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pwdDialog)
{
    ui->setupUi(this);
}

pwdDialog::~pwdDialog()
{
    delete ui;
}

void pwdDialog::showEvent(QShowEvent *)
{
    ui->lineEdit->clear();      //����û��������
    ui->lineEdit_2->clear();    //������������
    ui->lineEdit_3->clear();    //��������������
    ui->lineEdit_4->clear();    //��ն����������������
    ui->lineEdit->setFocus();   //�����ת���û��������
}

void pwdDialog::on_pushButton_clicked()
{
    //�޸�
    QString name;
    QString sPwd;
    QString tPwd1;
    QString tPwd2;
    QString sql;
    QSqlQuery query;

    name = ui->lineEdit->text().trimmed();
    sPwd = ui->lineEdit_2->text().trimmed();
    tPwd1 = ui->lineEdit_3->text().trimmed();
    tPwd2 = ui->lineEdit_4->text().trimmed();

    sql = "select * from person where name = '" + name
            + "' and passwd = '"+ sPwd + "'";

    query.exec(sql);
    if (query.next())
    {
        if (tPwd1 == tPwd2)
        {
            sql = "update person set passwd = '" + tPwd1 + "' where name = '" + name + "'";
            query.exec(sql);
            QMessageBox::warning(this,tr("Success"),tr("successfully Modify!"), QMessageBox::Yes);

            ui->lineEdit->clear();      //����û��������
            ui->lineEdit_2->clear();    //������������
            ui->lineEdit_3->clear();    //��������������
            ui->lineEdit_4->clear();    //��ն����������������
            ui->lineEdit->setFocus();   //�����ת���û��������
        }
        else
        {
            QMessageBox::warning(this,tr("Warning"),tr("Second password is not suit the first!"), QMessageBox::Yes);

            ui->lineEdit->clear();      //����û��������
            ui->lineEdit_2->clear();    //������������
            ui->lineEdit_3->clear();    //��������������
            ui->lineEdit_4->clear();    //��ն����������������
            ui->lineEdit->setFocus();   //�����ת���û��������
        }
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("person name or password error!"), QMessageBox::Yes);

        ui->lineEdit->clear();      //����û��������
        ui->lineEdit_2->clear();    //������������
        ui->lineEdit_3->clear();    //��������������
        ui->lineEdit_4->clear();    //��ն����������������
        ui->lineEdit->setFocus();   //�����ת���û��������
    }
}

void pwdDialog::on_pushButton_2_clicked()
{
    //ȡ��
    this->close();
}
