#include "loginwindow.h"
#include "ui_loginwindow.h"

loginWindow::loginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
}

loginWindow::~loginWindow()
{
    delete ui;
}

void loginWindow::on_pushButton_clicked()
{
    //�û���¼
    QString sql;
    QSqlQuery query;
    sql = "select * from ownerinfo where name = '" + ui->lineEdit->text().trimmed()
            + "' and pwd = '"+ ui->lineEdit_2->text() + "'";
    query.exec(sql);

    if (query.next())
    {
        username = ui->lineEdit->text().trimmed();
        this->close();
        userw.show();
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"),QMessageBox::Yes);

        ui->lineEdit->clear();      //����û��������
        ui->lineEdit_2->clear();       //������������
        ui->lineEdit->setFocus();   //�����ת���û��������
    }
}

void loginWindow::on_pushButton_2_clicked()
{
    //�û�ȡ��
    close();
}

void loginWindow::on_pushButton_3_clicked()
{
    //����Ա��¼
    QString sql;
    QSqlQuery query;
    sql = "select * from person where name = '" + ui->lineEdit_3->text().trimmed()
            + "' and passwd = '"+ ui->lineEdit_4->text() + "' and role = 0";
    query.exec(sql);

    if (query.next())
    {
        this->close();
        adminw.show();
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"),QMessageBox::Yes);

        ui->lineEdit_3->clear();      //����û��������
        ui->lineEdit_4->clear();       //������������
        ui->lineEdit_3->setFocus();   //�����ת���û��������
    }
}

void loginWindow::on_pushButton_4_clicked()
{
    //����Աȡ��
    close();
}

void loginWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/jpg/1.jpg").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}
