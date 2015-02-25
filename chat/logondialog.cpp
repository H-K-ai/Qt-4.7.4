#include "logondialog.h"
#include "ui_logondialog.h"

logonDialog::logonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logonDialog)
{
    ui->setupUi(this);
}

logonDialog::~logonDialog()
{
    delete ui;
}


void logonDialog::on_loginBut_clicked()
{

    QSqlQuery query;
    QString sql;

        sql = "select * from users where name = '" + ui->nameEdit->text().trimmed()
                + "' and passwd = '"+ ui->pwdEdit->text() + "'";
        query.exec(sql);

        if (query.next())
        {
            loginName = ui->nameEdit->text().trimmed();
            this->close();
            w.show();

            ui->nameEdit->clear();     //����û��������
            ui->pwdEdit->clear();      //������������
            ui->nameEdit->setFocus();  //�����ת���û��������
        }
        else
        {
            QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"),QMessageBox::Yes);

            ui->nameEdit->clear();     //����û��������
            ui->pwdEdit->clear();      //������������
            ui->nameEdit->setFocus();  //�����ת���û��������

        }
}

void logonDialog::on_cancelBut_clicked()
{
    close();
}
