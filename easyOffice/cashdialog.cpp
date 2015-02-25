#include "cashdialog.h"
#include "ui_cashdialog.h"

cashDialog::cashDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cashDialog)
{
    ui->setupUi(this);

    ui->comboBox->setCurrentIndex(0);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());

    ui->label_4->setText("�ϼƼ۸� : 0 Ԫ");

    initDialog();
}

cashDialog::~cashDialog()
{
    delete ui;
}

void cashDialog::showEvent(QShowEvent *)
{
    //��ʾ����
    ui->comboBox->setCurrentIndex(0);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());

    ui->label_4->setText("�ϼƼ۸� : 0 Ԫ");

    initDialog();
}

void cashDialog::on_pushButton_clicked()
{
    //���ڲ�ѯ
    QDate preDate = ui->dateEdit->date();
    QDate nextDate = ui->dateEdit_2->date();
    QSqlQuery query;
    int price = 0;

    if(preDate > nextDate)
    {
        QMessageBox::warning(this,tr("Warning"),tr("preDate > nextDate!"),QMessageBox::Yes);
        ui->dateEdit->setDate(nextDate); //����Ϊ��һ��ʱ��
    }

    query.exec("select price from clothes where time >= '" + preDate.toString("yyyy.MM.dd")
               + "' and time <= '" + nextDate.toString("yyyy.MM.dd") + "'");
    while(query.next())
        price += query.value(0).toInt();

    ui->label_4->setText("�ϼƼ۸� : " + QString::number(price, 10)+ " Ԫ");
}

void cashDialog::on_pushButton_2_clicked()
{
    //����ز�ѯ
    QSqlQuery query;
    int price = 0;

    query.exec("select price from clothes where buyplace = '" + ui->comboBox->currentText() + "'");
    while(query.next())
        price += query.value(0).toInt();

    ui->label_4->setText("�ϼƼ۸� : " + QString::number(price, 10)+ " Ԫ");
}

void cashDialog::initDialog()
{
    QSqlQuery query;
    ui->comboBox->clear();

    query.exec("select distinct buyplace from clothes");
    while(query.next())
        ui->comboBox->addItem(query.value(0).toString());
}
