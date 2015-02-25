#include "admindialog.h"
#include "ui_admindialog.h"

adminDialog::adminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminDialog)
{
    ui->setupUi(this);

    connect(&adBookw, SIGNAL(addBook()), &adBorroww, SLOT(updateComboBox()));
    connect(&adStuw, SIGNAL(addStu()), &adBorroww, SLOT(updateComboBox()));
    connect(&adBookw, SIGNAL(addBook()), &adOverw, SLOT(updateComboBox()));
    connect(&adStuw, SIGNAL(addStu()), &adOverw, SLOT(updateComboBox()));
}

adminDialog::~adminDialog()
{
    delete ui;
}

void adminDialog::on_pushButton_clicked()
{
    //ͼ�����
    adBookw.show();
}

void adminDialog::on_pushButton_2_clicked()
{
    //ѧ������
    adStuw.show();
}

void adminDialog::on_pushButton_3_clicked()
{
    //���Ĺ���
    adBorroww.show();
}

void adminDialog::on_pushButton_4_clicked()
{
    //ͼ�����
    bookSearchw.show();
}

void adminDialog::on_pushButton_5_clicked()
{
    //���ڹ���
    adOverw.show();
}

void adminDialog::on_pushButton_6_clicked()
{
    //�˳���¼
    this->close();
    emit loginOut();
}
