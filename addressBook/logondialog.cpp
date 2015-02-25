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
    //登录
    QSqlQuery query;
    QString sql;

    sql = "select * from person where name = '" + ui->nameEdit->text().trimmed()
            + "' and passwd = '"+ ui->pwdEdit->text() + "'";
    query.exec(sql);

    if (query.next())
    {
        this->close();
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"),QMessageBox::Yes);

        ui->nameEdit->clear();      //清空用户名输入框
        ui->pwdEdit->clear();       //清空密码输入框
        ui->nameEdit->setFocus();   //将光标转到用户名输入框
    }
}

void logonDialog::on_registerBut_clicked()
{
    //注册
    QSqlQuery query;
    int idNum = 0;
    QString name = ui->nameEdit->text().trimmed();
    bool nameFlag = false;

    query.exec("select personid from person");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    query.exec("select name from person");
    while(query.next())
    {
        if(name == query.value(0).toString())
        {
            QMessageBox::information(NULL, "fail", "用户名重复!");
            nameFlag = true;
            break;
        }
    }

    if(ui->pwdEdit->text().trimmed() != ui->pwdEdit_2->text().trimmed())
    {
        QMessageBox::information(NULL, "fail", "两次密码不一致!");
        return;
    }

    if(nameFlag == false)
    {
        query.exec("insert into person values('" + QString::number(idNum, 10) + "', '" + name + "', '" + ui->pwdEdit->text().trimmed() + "')");

        ui->nameEdit->clear();
        ui->pwdEdit->clear();
        QMessageBox::information(NULL, "success", "注册成功!");

        this->close();
        emit registerSignal();
    }
}

void logonDialog::on_cancelBut_clicked()
{
    close();
}
