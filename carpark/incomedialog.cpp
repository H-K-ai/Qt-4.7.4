#include "incomedialog.h"
#include "ui_incomedialog.h"

incomeDialog::incomeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::incomeDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    currentTableModel->setTable("comego");
    currentTableModel->select();
    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->lineEdit->clear();
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_2->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_3->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_4->setDateTime(QDateTime::currentDateTime());
}

incomeDialog::~incomeDialog()
{
    delete ui;
}

void incomeDialog::showEvent(QShowEvent *)
{
    currentTableModel->setTable("comego");
    currentTableModel->select();
    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->lineEdit->clear();
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_2->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_3->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_4->setDateTime(QDateTime::currentDateTime());
}

void incomeDialog::on_pushButton_clicked()
{
    //��ѯ
    QDateTime preDate = ui->dateTimeEdit_3->dateTime();
    QDateTime nextDate = ui->dateTimeEdit_4->dateTime();
    QSqlQuery query;
    int price = 0;

    if(preDate > nextDate)
    {
        QMessageBox::warning(this,tr("Warning"),tr("preDate > nextDate!"),QMessageBox::Yes);
        ui->dateTimeEdit_3->setDateTime(nextDate); //����Ϊ��һ��ʱ��
    }

    currentTableModel->setFilter("go >= '" + preDate.toString("yyyy.MM.dd hh:mm:ss")
                                 + "' and go <= '" + nextDate.toString("yyyy.MM.dd hh:mm:ss") + "'");
    currentTableModel->select();

    query.exec("select price from comego where go >= '" + preDate.toString("yyyy.MM.dd hh:mm:ss")
               + "' and go <= '" + nextDate.toString("yyyy.MM.dd hh:mm:ss") + "'");
    while(query.next())
        price += query.value(0).toInt();

    ui->label_6->setText("��Ӫҵ�� :\n  " + QString::number(price, 10)+ " Ԫ");

    ui->lineEdit->clear();
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_2->setDateTime(QDateTime::currentDateTime());
}

void incomeDialog::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    ui->lineEdit->setText(currentTableModel->index(curRow, 1).data().toString());
    ui->dateTimeEdit->setDateTime(QDateTime::fromString(currentTableModel->index(curRow, 3).data().toString(), "yyyy.MM.dd hh:mm:ss"));
    ui->dateTimeEdit_2->setDateTime(QDateTime::fromString(currentTableModel->index(curRow, 4).data().toString(), "yyyy.MM.dd hh:mm:ss"));
}
