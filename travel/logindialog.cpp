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

void loginDialog::paintEvent(QPaintEvent *)
{
#if 0
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/jpg/1.jpg").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
#endif
}

void loginDialog::on_pushButton_clicked()
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

void loginDialog::on_pushButton_2_clicked()
{
    //ȡ��
    this->close();
}
