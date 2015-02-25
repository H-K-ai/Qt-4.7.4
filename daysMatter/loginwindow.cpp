#include "loginwindow.h"
#include "ui_loginwindow.h"

loginWindow::loginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
}

loginWindow::~loginWindow()
{
    delete ui;
}

void loginWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/png/bk.png").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void loginWindow::on_pushButton_clicked()
{
    //��¼
    QSqlQuery query;
    QString sql;

    sql = "select * from user where name = '" + ui->lineEdit->text().trimmed()
            + "' and passwd = '"+ ui->lineEdit_2->text() + "'";
    query.exec(sql);

    if (query.next())
    {
        windowsPos = this->QWidget::pos(); //��ȡ����λ��
        this->close();
        mainw.move(windowsPos);   //���´���λ�õ�������ԭ��һ��
        mainw.show();
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"),QMessageBox::Yes);

        ui->lineEdit->clear();      //����û��������
        ui->lineEdit_2->clear();    //������������
        ui->lineEdit_3->clear();    //��������������
        ui->lineEdit_4->clear();    //��ն����������������
        ui->lineEdit->setFocus();   //�����ת���û��������

    }
}

void loginWindow::on_pushButton_2_clicked()
{
    //�޸�����
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

    sql = "select * from user where name = '" + name
            + "' and passwd = '"+ sPwd + "'";

    query.exec(sql);
    if (query.next())
    {
        if (tPwd1 == tPwd2)
        {
            sql = "update user set passwd = '" + tPwd1 + "' where name = '" + name + "'";
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
        QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"), QMessageBox::Yes);

        ui->lineEdit->clear();      //����û��������
        ui->lineEdit_2->clear();    //������������
        ui->lineEdit_3->clear();    //��������������
        ui->lineEdit_4->clear();    //��ն����������������
        ui->lineEdit->setFocus();   //�����ת���û��������
    }
}

void loginWindow::on_pushButton_3_clicked()
{
    //�˳�
    close();
}
