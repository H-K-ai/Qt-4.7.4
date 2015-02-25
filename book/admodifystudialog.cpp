#include "admodifystudialog.h"
#include "ui_admodifystudialog.h"

adModifyStuDialog::adModifyStuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adModifyStuDialog)
{
    ui->setupUi(this);

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->comboBox->setCurrentIndex(0);
}

adModifyStuDialog::~adModifyStuDialog()
{
    delete ui;
}

void adModifyStuDialog::showEvent(QShowEvent *)
{
    //��ʾ����
    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->comboBox->setCurrentIndex(0);
}

void adModifyStuDialog::on_pushButton_clicked()
{
    //����
    QSqlQuery query;

    query.exec("select * from students where phone = '" + ui->lineEdit_5->text().trimmed() + "'");
    while(query.next())
    {
        ui->lineEdit->setText(query.value(1).toString());
        ui->lineEdit_2->setText(query.value(2).toString());
        ui->lineEdit_3->setText(query.value(3).toString());
        ui->lineEdit_4->setText(query.value(4).toString());
        ui->comboBox->setCurrentIndex(query.value(5).toInt());
        picPath = query.value(6).toString();
        ui->label->setScaledContents(true);
        ui->label->setPixmap(QPixmap(picPath));

        return;
    }

    QMessageBox::information(NULL, "Warring", "�ֻ�����δ�ҵ�!");
}

void adModifyStuDialog::on_pushButton_2_clicked()
{
    //�޸���Ϣ
    QSqlQuery query;
    QString idNum;

    if(ui->lineEdit->text().trimmed().length() == 0)
    {
        QMessageBox::information(NULL, "Warring", "�޸�ʧ��!��������Ϊ��.");
        return;
    }

    if(ui->lineEdit_4->text().trimmed().length() == 0)
    {
        QMessageBox::information(NULL, "Warring", "�޸�ʧ��!��ϵ��ʽ����Ϊ��.");
        return;
    }

    query.exec("select phone from students where stucode <> '" + ui->lineEdit_3->text().trimmed() + "'");
    while(query.next())
    {
        if(query.value(0).toString() == ui->lineEdit_4->text().trimmed())
        {
            QMessageBox::information(NULL, "Warring", "�޸�ʧ��!�ֻ������ظ�.");
            return;
        }
    }

    query.exec("select studentsid from students where stucode = '" + ui->lineEdit_3->text().trimmed() + "'");
    while(query.next())
    {
        idNum = query.value(0).toString();
    }

    query.exec("delete from students where stucode = '" + ui->lineEdit_3->text().trimmed() + "'");

    QString targetPath = "user/" + idNum + ".jpg";
    copyFileToPath(picPath, targetPath, true); //����ʽ����

    query.exec("insert into students values('" + idNum + "', '"
               + ui->lineEdit->text().trimmed() + "', '"
               + ui->lineEdit_2->text().trimmed() + "', '"
               + ui->lineEdit_3->text().trimmed() + "', '"
               + ui->lineEdit_4->text().trimmed() + "', '"
               + QString::number(ui->comboBox->currentIndex(), 10) + "', '"
               + targetPath + "')");


    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->comboBox->setCurrentIndex(0);

    QMessageBox::information(NULL, "success", "�޸ĳɹ�!");

    emit modifyStu();
}

void adModifyStuDialog::on_pushButton_3_clicked()
{
    //ѧ����Ƭ
    picPath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
    if(picPath.length() == 0) {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
        return;
    } else {
        QMessageBox::information(NULL, tr("Path"), tr("You selected ") + picPath);
    }
    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(picPath));
}
