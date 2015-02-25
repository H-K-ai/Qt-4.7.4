#include "incomedialog.h"
#include "ui_incomedialog.h"

incomeDialog::incomeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::incomeDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    currentTableModel->setTable("checkin");
    currentTableModel->select();
    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());

    on_pushButton_clicked();
}

incomeDialog::~incomeDialog()
{
    delete ui;
}

void incomeDialog::showEvent(QShowEvent *)
{
    currentTableModel->select();

    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());
}

void incomeDialog::on_pushButton_clicked()
{
    //��ѯ
    QDate preDate = ui->dateEdit->date();
    QDate nextDate = ui->dateEdit_2->date();
    QSqlQuery query;
    int price = 0;

    if(preDate > nextDate)
    {
        QMessageBox::warning(this,tr("Warning"),tr("preDate > nextDate!"),QMessageBox::Yes);
        ui->dateEdit->setDate(nextDate); //����Ϊ��һ��ʱ��
    }

    currentTableModel->setFilter("date >= '" + preDate.toString("yyyy.MM.dd")
                                 + "' and date <= '" + nextDate.toString("yyyy.MM.dd") + "'");
    currentTableModel->select();

    query.exec("select price from checkin where date >= '" + preDate.toString("yyyy.MM.dd")
               + "' and date <= '" + nextDate.toString("yyyy.MM.dd") + "'");
    while(query.next())
        price += query.value(0).toInt();

    ui->label_4->setText("�ϼ�Ӫҵ�� : " + QString::number(price, 10)+ " Ԫ");
}

void incomeDialog::initDialog()
{
    on_pushButton_clicked();
}
