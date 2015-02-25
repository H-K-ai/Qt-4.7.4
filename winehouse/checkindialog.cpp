#include "checkindialog.h"
#include "ui_checkindialog.h"

checkinDialog::checkinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkinDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    initDialog();
}

checkinDialog::~checkinDialog()
{
    delete ui;
}

void checkinDialog::showEvent(QShowEvent *)
{
    initDialog();
}

void checkinDialog::on_pushButton_clicked()
{
    //��ס
    inroomw.show();
}

void checkinDialog::on_pushButton_3_clicked()
{
    //�˷�
    outroomw.show();
}

void checkinDialog::on_pushButton_2_clicked()
{
    //Ԥ��
    bookroomw.show();
}

void checkinDialog::initDialog()
{
    //�������
    currentTableModel->setTable("checkin");
    currentTableModel->select();
    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
