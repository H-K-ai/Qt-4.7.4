#include "messagewindow.h"
#include "ui_messagewindow.h"

messageWindow::messageWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::messageWindow)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    currentTableModel->setTable("message");
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->label_5->setText(username);
    ui->lineEdit->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->textEdit->clear();
}

messageWindow::~messageWindow()
{
    delete ui;
}

void messageWindow::on_pushButton_clicked()
{
    //��Ҫ����
    ui->label_5->setText(username);
    ui->lineEdit->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->textEdit->clear();
}

void messageWindow::on_pushButton_2_clicked()
{
    //�ύ
    int rowNum = currentTableModel->rowCount(); //��ñ������
    int idNum = 0;
    QSqlQuery query;
    query.exec("select messageId from message");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    currentTableModel->insertRow(rowNum); //���һ��
    currentTableModel->setData(currentTableModel->index(rowNum, 0), idNum);
    currentTableModel->setData(currentTableModel->index(rowNum, 1), username);
    currentTableModel->setData(currentTableModel->index(rowNum, 2), ui->lineEdit->text());
    currentTableModel->setData(currentTableModel->index(rowNum, 3), ui->comboBox->currentIndex());
    currentTableModel->setData(currentTableModel->index(rowNum, 4), ui->textEdit->toPlainText());

    currentTableModel->submitAll();


    ui->label_5->setText(username);
    ui->lineEdit->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->textEdit->clear();
}

void messageWindow::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    ui->label_5->setText(currentTableModel->index(curRow, 1).data().toString());
    ui->lineEdit->setText(currentTableModel->index(curRow, 2).data().toString());
    ui->comboBox->setCurrentIndex(currentTableModel->index(curRow, 3).data().toInt());
    ui->textEdit->setPlainText(currentTableModel->index(curRow, 4).data().toString());
}
