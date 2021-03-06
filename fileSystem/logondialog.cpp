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

void logonDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/images/logo.jpg").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}


void logonDialog::on_loginBut_clicked()
{
    QSqlQuery query;
    QString sql;

    sql = "select * from person where pname = '" + ui->nameEdit->text().trimmed()
            + "' and passwd = '"+ ui->pwdEdit->text() + "'";
    query.exec(sql);

    if (query.next())
    {
        this->close();
        mainw.show();
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"),QMessageBox::Yes);

        ui->nameEdit->clear();      //清空用户名输入框
        ui->pwdEdit->clear();       //清空密码输入框
        ui->nameEdit->setFocus();   //将光标转到用户名输入框
    }
}

void logonDialog::on_cancelBut_clicked()
{
    close();
}
