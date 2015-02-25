#include "accountdialog.h"
#include "ui_accountdialog.h"

accountDialog::accountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::accountDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    on_pushButton_2_clicked();
}

accountDialog::~accountDialog()
{
    delete ui;
}

void accountDialog::on_pushButton_clicked()
{
    //�½�
    QSqlQuery query;
    int idNum = 0;
    QString name = ui->lineEdit->text().trimmed();
    bool nameFlag = false;

    query.exec("select userid from user");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    query.exec("select name from user");
    while(query.next())
    {
        if(name == query.value(0).toString())
        {
            QMessageBox::information(NULL, "fail", "name repeat!");
            nameFlag = true;
            break;
        }
    }

    if(nameFlag == false)
    {
        query.exec("insert into user values('" + QString::number(idNum, 10) + "', '" + name + "', '" + ui->lineEdit_2->text().trimmed() + "')");

        ui->lineEdit->clear();
        ui->lineEdit_2->clear();

        currentTableModel->select();
        QMessageBox::information(NULL, "success", "user add success!");
    }
}

void accountDialog::on_pushButton_2_clicked()
{
    //ˢ��
    currentTableModel->setTable("user");
    currentTableModel->select();
    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void accountDialog::on_pushButton_3_clicked()
{
    //�޸�
    currentView->setEditTriggers(QAbstractItemView::AllEditTriggers);
}

void accountDialog::on_pushButton_4_clicked()
{
    //ɾ��
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������
}

void accountDialog::on_pushButton_5_clicked()
{
    //�ύ
    currentTableModel->submitAll();
}
