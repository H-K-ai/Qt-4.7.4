#include "crackerdialog.h"
#include "ui_crackerdialog.h"

crackerDialog::crackerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::crackerDialog)
{
    ui->setupUi(this);
}

crackerDialog::~crackerDialog()
{
    delete ui;
}

void crackerDialog::showEvent(QShowEvent *)
{
    init();
}

void crackerDialog::paintEvent(QPaintEvent *)
{}

void crackerDialog::closeEvent(QCloseEvent *)
{
}

void crackerDialog::init()
{
    QSqlQuery query;
    QString sql;
    QString cname = "";
    QString cpwd = "";
    QString cdate = "";
    int dayNum = 0;
    int cnum = 0;

    sql = "select cname, cpwd, cdate, cnum from cracker";
    query.exec(sql);
    while(query.next())
    {
        cname = query.value(0).toString();
        cpwd = query.value(1).toString();
        cdate = query.value(2).toString();
        cnum = query.value(3).toInt();
    }

    if(cpwd == Encrypt(cname))
    {
        ui->label->setText("ע����Ϣ����:");
    }
    else
    {
        sql = "update cracker set cpwd = '' where cname = '" + cname + "'";
        cpwd = "";
        query.exec(sql);

        dayNum = QDate::fromString(cdate, "yyyy.MM.dd").daysTo(QDate::currentDate());
        dayNum = ((cnum - dayNum) > 0) ? (cnum - dayNum) : 0;
        ui->label->setText("�������ڻ�ʣ " + QString::number(dayNum) + " ��");
    }
    ui->lineEdit->setText(cname);
    ui->lineEdit->setEnabled(false);
    ui->lineEdit_2->setText(cpwd);

    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();

    //c8e71556394336cecf081b79b84294c4297dbae8
}

void crackerDialog::on_pushButton_clicked()
{
    //ע��
    QString strName = ui->lineEdit->text().trimmed();
    QString strPwd = ui->lineEdit_2->text().trimmed();
    if(strPwd == Encrypt(strName))
    {
        //ע��ɹ�
        QSqlQuery query;
        QString sql;
        sql = "update cracker set cpwd = '" + strPwd
                + "' where cname = '" + strName + "'";
        query.exec(sql);
        QMessageBox::information(NULL, "success.", "ע��ɹ�!");
    }
    else
    {
        //ע��ʧ��
        QMessageBox::information(NULL, "error.", "ע��ʧ��!");
    }
}

void crackerDialog::on_pushButton_3_clicked()
{
    //�޸�����
    QSqlQuery query;
    QString sql;

    QString oldPwd = ui->lineEdit_3->text().trimmed();
    QString newPwd1 = ui->lineEdit_4->text().trimmed();
    QString newPwd2 = ui->lineEdit_5->text().trimmed();

    if(ui->lineEdit_4->text().right(1) == " ")
    {
        QMessageBox::information(NULL, "error.", "���벻���Կո��β!");
        return;
    }

    if(ui->lineEdit_5->text().right(1) == " ")
    {
        QMessageBox::information(NULL, "error.", "���벻���Կո��β!");
        return;
    }

    sql = "select * from person where pwd = '" + oldPwd + "'";
    query.exec(sql);

    if (query.next())
    {
        if(newPwd1 == newPwd2)
        {
            sql = "update person set pwd = '" + newPwd1 + "' where pwd = '" + oldPwd + "'";
            query.exec(sql);

            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->lineEdit_5->clear();
            QMessageBox::information(NULL, "success.", "�޸ĳɹ�!");
        }
        else
        {
            QMessageBox::information(NULL, "error.", "������������������벻һ��!");
        }
    }
    else
    {
        QMessageBox::information(NULL, "error.", "�������!");
    }
}

void crackerDialog::on_pushButton_2_clicked()
{
    //ȡ��
    this->close();
}

