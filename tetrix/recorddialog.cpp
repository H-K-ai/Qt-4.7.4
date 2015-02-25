#include "recorddialog.h"
#include "ui_recorddialog.h"

recordDialog::recordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recordDialog)
{
    ui->setupUi(this);
    score = "0";
}

recordDialog::~recordDialog()
{
    delete ui;
}

void recordDialog::showEvent(QShowEvent *event)
{
    ui->label_2->setText(score);
    ui->lineEdit->clear();
}

void recordDialog::on_pushButton_clicked()
{
    //ȷ��
    QString nameStr = ui->lineEdit->text().trimmed();
    if(nameStr == "")
    {
        nameStr = "����";
    }
    QSqlQuery query;
    int idNum = 0;
    query.exec("select historyListid from historyList");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;
    query.exec("insert into historyList values ('" + QString::number(idNum, 10) + "', '"
               + nameStr + "', '"
               + score + "')");

    this->close();
}
