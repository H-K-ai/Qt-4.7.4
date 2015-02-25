#include "logindialog.h"
#include "ui_logindialog.h"

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);

    connect(&adminw, SIGNAL(loginOut()), this, SLOT(loginShow()));
    connect(&userw, SIGNAL(loginOut()), this, SLOT(loginShow()));
}

loginDialog::~loginDialog()
{
    delete ui;
}

void loginDialog::on_loginBut_clicked()
{
    //��¼
    QSqlQuery query;
    QString sql;

    if (ui->adminRadio->isChecked() == true)
    {
        sql = "select * from users where name = '" + ui->nameEdit->text().trimmed()
                + "' and passwd = '"+ ui->pwdEdit->text() + "' and role = 0";
        query.exec(sql);

        if (query.next())
        {
            loginName = ui->nameEdit->text().trimmed();
            this->close();
            adminw.show();

            ui->nameEdit->clear();      //����û��������
            ui->pwdEdit->clear();       //������������
            ui->nameEdit->setFocus();   //�����ת���û��������
        }
        else
        {
            QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"),QMessageBox::Yes);

            ui->nameEdit->clear();      //����û��������
            ui->pwdEdit->clear();       //������������
            ui->nameEdit->setFocus();   //�����ת���û��������

        }
    }
    if (ui->userRadio->isChecked() == true)
    {
        sql = "select * from students where stucode = '" + ui->nameEdit->text().trimmed()
                + "' and passwd = '"+ ui->pwdEdit->text() + "'";
        query.exec(sql);

        if (query.next())
        {
            loginName = ui->nameEdit->text().trimmed();
            userw.setStuCode(ui->nameEdit->text().trimmed());
            this->close();
            userw.show();

            ui->nameEdit->clear();      //����û��������
            ui->pwdEdit->clear();       //������������
            ui->nameEdit->setFocus();   //�����ת���û��������
        }
        else
        {
            QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"),QMessageBox::Yes);

            ui->nameEdit->clear();      //����û��������
            ui->pwdEdit->clear();       //������������
            ui->nameEdit->setFocus();   //�����ת���û��������
        }
    }
}

void loginDialog::on_cancelBut_clicked()
{
    //�˳�
    this->close();
}

void loginDialog::loginShow()
{
    //��¼�Ի�����ʾ
    this->show();

    ui->nameEdit->clear();      //����û��������
    ui->pwdEdit->clear();       //������������
    ui->nameEdit->setFocus();   //�����ת���û��������
}
