#include "logindialog.h"
#include "ui_logindialog.h"

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
}

loginDialog::~loginDialog()
{
    delete ui;
}

void loginDialog::on_pushButton_clicked()
{
    //��¼
    QSqlQuery query;
    QString sql;

    sql = "select * from users where name = '" + ui->lineEdit->text().trimmed()
            + "' and passwd = '"+ ui->lineEdit_2->text() + "'";
    query.exec(sql);

    if (query.next())
    {
        this->close();
        mainw.show();
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"),QMessageBox::Yes);

        ui->lineEdit->clear();      //����û��������
        ui->lineEdit_2->clear();    //������������
        ui->lineEdit->setFocus();   //�����ת���û��������
    }
}

void loginDialog::on_pushButton_2_clicked()
{
    //�ҵĿα�
    this->close();
    myCoursew.show();
}
