#include "logondialog.h"
#include "ui_logondialog.h"

logonDialog::logonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logonDialog)
{
    ui->setupUi(this);
}

logonDialog::~logonDialog()
{
    delete ui;
}

void logonDialog::on_loginBut_clicked()
{
    //��¼
    QSqlQuery query;
    QString sql;

    sql = "select * from person where name = '" + ui->nameEdit->text().trimmed()
            + "' and passwd = '"+ ui->pwdEdit->text() + "'";
    query.exec(sql);

    if (query.next())
    {
        this->close();
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"),QMessageBox::Yes);

        ui->nameEdit->clear();      //����û��������
        ui->pwdEdit->clear();       //������������
        ui->nameEdit->setFocus();   //�����ת���û��������
    }
}

void logonDialog::on_registerBut_clicked()
{
    //ע��
    QSqlQuery query;
    int idNum = 0;
    QString name = ui->nameEdit->text().trimmed();
    bool nameFlag = false;

    query.exec("select personid from person");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    query.exec("select name from person");
    while(query.next())
    {
        if(name == query.value(0).toString())
        {
            QMessageBox::information(NULL, "fail", "�û����ظ�!");
            nameFlag = true;
            break;
        }
    }

    if(ui->pwdEdit->text().trimmed() != ui->pwdEdit_2->text().trimmed())
    {
        QMessageBox::information(NULL, "fail", "�������벻һ��!");
        return;
    }

    if(nameFlag == false)
    {
        query.exec("insert into person values('" + QString::number(idNum, 10) + "', '" + name + "', '" + ui->pwdEdit->text().trimmed() + "')");

        ui->nameEdit->clear();
        ui->pwdEdit->clear();
        QMessageBox::information(NULL, "success", "ע��ɹ�!");

        this->close();
        emit registerSignal();
    }
}

void logonDialog::on_cancelBut_clicked()
{
    close();
}