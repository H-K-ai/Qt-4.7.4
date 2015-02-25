#include "logdialog.h"
#include "ui_logdialog.h"
#include"servedialog.h"
#include"admindialog.h"
#include<QDebug>
#include<QMessageBox.h>
#include<QSqlQuery>

logDialog::logDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logDialog)
{
    ui->setupUi(this);
    ui->rbadmin->setChecked(true);
    QPalette   palette;
    QPixmap pixmap("resource/2.jpg");
    palette.setBrush(backgroundRole(),QBrush(pixmap));
    setPalette(palette);
}

logDialog::~logDialog()
{
    delete ui;
}

void logDialog::on_pbcancel_clicked()
{
    close();
}

void logDialog::on_pblogin_clicked()
{
    //�����û��������롢��ݣ������ݿ�����Ϣ�Ƚ�

    this->close();

        serveDialog  sd;
        sd.exec();


    //�رյ�¼����
}
