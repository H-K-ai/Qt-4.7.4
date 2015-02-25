#include "subjectdialog.h"
#include "ui_subjectdialog.h"

subjectDialog::subjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::subjectDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    on_pushButton_4_clicked();

    ui->lineEdit->clear();
}

subjectDialog::~subjectDialog()
{
    delete ui;
}

void subjectDialog::showEvent(QShowEvent *)
{
    on_pushButton_4_clicked();

    ui->lineEdit->clear();
}

void subjectDialog::on_pushButton_3_clicked()
{
    //��ѯ�γ�
    currentTableModel->setFilter("name like '%" + ui->lineEdit->text().trimmed() + "%'");
    currentTableModel->select();
}

void subjectDialog::on_pushButton_clicked()
{
    //��ӿγ�
    QSqlQuery query;
    int idNum = 0;

    query.exec("select subjuctsid from subjucts");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    query.exec("insert into subjucts values('" + QString::number(idNum, 10) + "', '"
               + ui->lineEdit->text().trimmed() + "')");

    ui->lineEdit->clear();

    currentTableModel->select();
    QMessageBox::information(NULL, "success", "add success!");

    emit modifySub();
}

void subjectDialog::on_pushButton_2_clicked()
{
    //ɾ���γ�
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������

    ui->lineEdit->clear();

    QMessageBox::information(NULL, "success", "delete success!");

    emit modifySub();
}

void subjectDialog::on_pushButton_4_clicked()
{
    //ȫ���γ�
    currentTableModel->setTable("subjucts");
    currentTableModel->select();
    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->lineEdit->clear();
}

void subjectDialog::on_tableView_clicked(const QModelIndex &index)
{
    //�����б�
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();

    query.exec("select * from subjucts where subjuctsid = '" + idNum + "'");
    while(query.next())
    {
        ui->lineEdit->setText(query.value(1).toString());
    }
}
