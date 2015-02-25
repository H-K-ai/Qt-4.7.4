#include "loginsystem.h"
#include "ui_loginsystem.h"

loginSystem::loginSystem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginSystem)
{
    ui->setupUi(this);

    connect(&adWindow, SIGNAL(exitLogin()), this, SLOT(loginShow()));
    connect(&kpWindow, SIGNAL(exitLogin()), this, SLOT(loginShow()));
    connect(&svWindow, SIGNAL(exitLogin()), this, SLOT(loginShow()));
}

loginSystem::~loginSystem()
{
    delete ui;
}

void loginSystem::on_cancelBut_clicked()
{
    close();
}

void loginSystem::on_loginBut_clicked()
{
    QSqlQuery query;
    QString sql;

    if (ui->adminRadio->isChecked() == true)
    {
        sql = "select * from person where pname = '" + ui->nameEdit->text().trimmed()
                + "' and passwd = '"+ ui->pwdEdit->text() + "' and role = 0";
        query.exec(sql);

        if (query.next())
        {
            this->close();
            adWindow.show();
        }
        else
        {
            QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"),QMessageBox::Yes);

            ui->nameEdit->clear();      //����û��������
            ui->pwdEdit->clear();       //������������
            ui->nameEdit->setFocus();   //�����ת���û��������

        }
    }
    if (ui->serveRadio->isChecked() == true)
    {
        sql = "select * from person where pname = '" + ui->nameEdit->text().trimmed()
                + "' and passwd = '"+ ui->pwdEdit->text() + "' and role = 1";
        query.exec(sql);

        if (query.next())
        {
            serveName = ui->nameEdit->text().trimmed();
            this->close();
            svWindow.show();
        }
        else
        {
            QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"),QMessageBox::Yes);

            ui->nameEdit->clear();      //����û��������
            ui->pwdEdit->clear();       //������������
            ui->nameEdit->setFocus();   //�����ת���û��������
        }
    }
    if (ui->keeperRadio->isChecked() == true)
    {
        sql = "select * from person where pname = '" + ui->nameEdit->text().trimmed()
                + "' and passwd = '"+ ui->pwdEdit->text() + "' and role = 2";
        query.exec(sql);

        if (query.next())
        {
            this->close();
            kpWindow.show();
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

void loginSystem::loginShow()
{
    //��ʾ��¼��
    this->show();
}

void loginSystem::paintEvent(QPaintEvent *)
{
    //����ͼƬ
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/png/3.png").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}
