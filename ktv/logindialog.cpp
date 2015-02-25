#include "logindialog.h"
#include "ui_logindialog.h"

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);

    connect(&adminw, SIGNAL(returnDialog()), this, SLOT(returnShow()));
    connect(&serverw, SIGNAL(returnDialog()), this, SLOT(returnShow()));
}

loginDialog::~loginDialog()
{
    delete ui;
}

void loginDialog::on_cancelBut_clicked()
{
    close();
}

void loginDialog::on_loginBut_clicked()
{
    QSqlQuery query;
    QString sql;

    sql = "select * from person where name = '" + ui->nameEdit->text().trimmed()
            + "' and passwd = '"+ ui->pwdEdit->text() + "' and role = '" +QString::number(ui->comboBox->currentIndex(), 10) + "'";
    query.exec(sql);

    if (query.next())
    {
        this->close();
        if(ui->comboBox->currentIndex() == 0)
            adminw.show();
        else
            serverw.show();
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"),QMessageBox::Yes);

        ui->nameEdit->clear();      //����û��������
        ui->pwdEdit->clear();       //������������
        ui->nameEdit->setFocus();   //�����ת���û��������

    }
}

void loginDialog::on_cancelBut_2_clicked()
{
    //����
    this->close();
    emit returnDialog();
}

void loginDialog::returnShow()
{
    //������ʾ
    this->show();
}

void loginDialog::paintEvent(QPaintEvent *)
{
    //����ͼƬ
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/png/3.png").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}
