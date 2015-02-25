#include "roomdialog.h"
#include "ui_roomdialog.h"

roomDialog::roomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::roomDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlRelationalTableModel(this);
    currentView = ui->tableView;

    on_pushButton_4_clicked();
}

roomDialog::~roomDialog()
{
    delete ui;
}

void roomDialog::showEvent(QShowEvent *)
{
    on_pushButton_4_clicked();
}

void roomDialog::on_pushButton_clicked()
{
    //��ӷ���
    int rowNum = currentTableModel->rowCount(); //��ñ������
    int id = currentTableModel->record(rowNum - 1).value(0).toInt() + 1;
    currentView->setEditTriggers(QAbstractItemView::DoubleClicked);  //ʹ��ɱ༭
    currentTableModel->insertRow(rowNum); //���һ��
    currentTableModel->setData(currentTableModel->index(rowNum, 0), id);
    currentTableModel->setData(currentTableModel->index(rowNum, 1), 0);

    currentTableModel->submitAll();

    emit modifyRoom();
}

void roomDialog::on_pushButton_2_clicked()
{
    //ɾ������
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������

    emit modifyRoom();
}

void roomDialog::on_pushButton_3_clicked()
{
    //�ύ�޸�
    currentTableModel->submitAll();

    emit modifyRoom();
}

void roomDialog::on_pushButton_4_clicked()
{
    //ˢ�·���
    currentTableModel->setTable("room");
    currentTableModel->setRelation(1, QSqlRelation("roomstatus", "roomstatusid", "status"));
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setItemDelegate(new QSqlRelationalDelegate(currentView));
}

void roomDialog::updateRoom()
{
    //ˢ�·����ź�
    on_pushButton_4_clicked();
}
