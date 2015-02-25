#include "libroomdialog.h"
#include "ui_libroomdialog.h"

libroomDialog::libroomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::libroomDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    on_pushButton_4_clicked();

    ui->lineEdit->clear();
}

libroomDialog::~libroomDialog()
{
    delete ui;
}

void libroomDialog::showEvent(QShowEvent *)
{
    on_pushButton_4_clicked();

    ui->lineEdit->clear();
}

void libroomDialog::on_pushButton_3_clicked()
{
    //��ѯʵ����
    currentTableModel->setFilter("name like '%" + ui->lineEdit->text().trimmed() + "%'");
    currentTableModel->select();
}

void libroomDialog::on_pushButton_clicked()
{
    //���ʵ����
    QSqlQuery query;
    int idNum = 0;

    query.exec("select libroomid from libroom");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    query.exec("insert into libroom values('" + QString::number(idNum, 10) + "', '"
               + ui->lineEdit->text().trimmed() + "')");

    ui->lineEdit->clear();

    currentTableModel->select();
    QMessageBox::information(NULL, "success", "add success!");

    emit modifyLib();
}

void libroomDialog::on_pushButton_2_clicked()
{
    //ɾ��ʵ����
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������

    ui->lineEdit->clear();

    QMessageBox::information(NULL, "success", "delete success!");

    emit modifyLib();
}

void libroomDialog::on_pushButton_4_clicked()
{
    //ȫ��ʵ����
    currentTableModel->setTable("libroom");
    currentTableModel->select();
    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->lineEdit->clear();
}

void libroomDialog::on_tableView_clicked(const QModelIndex &index)
{
    //�����б�
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();

    query.exec("select * from libroom where libroomid = '" + idNum + "'");
    while(query.next())
    {
        ui->lineEdit->setText(query.value(1).toString());
    }
}
