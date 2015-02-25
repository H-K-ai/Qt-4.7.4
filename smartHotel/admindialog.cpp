#include "admindialog.h"
#include "ui_admindialog.h"

adminDialog::adminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminDialog)
{
    ui->setupUi(this);

    connect(&guestw, SIGNAL(modGuest()), &orderw, SLOT(initGuest()));
    connect(&roomw, SIGNAL(modRoom()), &orderw, SLOT(initRoom()));
}

adminDialog::~adminDialog()
{
    delete ui;
}

void adminDialog::on_pushButton_clicked()
{
    //�ͻ���Ϣ
    guestw.show();
}

void adminDialog::on_pushButton_2_clicked()
{
    //������Ϣ
    roomw.show();
}

void adminDialog::on_pushButton_3_clicked()
{
    //��ס��Ϣ
    orderw.show();
}

void adminDialog::on_pushButton_4_clicked()
{
    //��Ա����
    userw.show();
}
