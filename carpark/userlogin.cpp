#include "userlogin.h"
#include "ui_userlogin.h"

userlogin::userlogin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::userlogin)
{
    ui->setupUi(this);
}

userlogin::~userlogin()
{
    delete ui;
}

void userlogin::on_pushButton_clicked()
{
    //��¼
    QSqlQuery query;

    query.exec("select * from person where name = '" + ui->lineEdit->text().trimmed()
               + "' and passwd = '"+ ui->lineEdit_2->text() + "'");

    if (query.next())
    {
        this->close();
        mainw.show();
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"),QMessageBox::Yes);

        ui->lineEdit->clear();      //����û��������
        ui->lineEdit_2->clear();       //������������
        ui->lineEdit->setFocus();   //�����ת���û��������
    }
}

void userlogin::on_pushButton_2_clicked()
{
    //ȡ��
}
