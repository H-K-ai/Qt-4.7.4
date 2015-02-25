#include "logondialog.h"
#include "ui_logondialog.h"

logonDialog::logonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logonDialog)
{
    ui->setupUi(this);

    //����һ���ṹ�壬������Ŵ��ڸ�������
    struct PortSettings myComSetting = {BAUD9600, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 500};
    //���崮�ڶ��󣬲����ݲ������ڹ��캯���������г�ʼ��
    myCom = new Win_QextSerialPort("com1", myComSetting, QextSerialBase::EventDriven);
    //�Կɶ�д��ʽ�򿪴���
    myCom->open(QIODevice::ReadWrite);
    //�źźͲۺ��������������ڻ�����������ʱ�����ж����ڲ���
    connect(myCom, SIGNAL(readyRead()), this, SLOT(readMyCom()));
    //д���ڲ���
    //myCom->write("99999");
}

logonDialog::~logonDialog()
{
    delete ui;
}


void logonDialog::on_loginBut_clicked()
{
    QSqlQuery query;
    QString sql;

    if (ui->adminRadio->isChecked() == true)
    {
        sql = "select * from users where name = '" + ui->nameEdit->text().trimmed()
                + "' and passwd = '"+ ui->pwdEdit->text() + "' and role = 0";
        query.exec(sql);

        if (query.next())
        {
            loginName = ui->nameEdit->text().trimmed();
            this->close();
            adminw.show();

            ui->nameEdit->clear();     //����û��������
            ui->pwdEdit->clear();      //������������
            ui->nameEdit->setFocus();  //�����ת���û��������
        }
        else
        {
            QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"),QMessageBox::Yes);

            ui->nameEdit->clear();     //����û��������
            ui->pwdEdit->clear();      //������������
            ui->nameEdit->setFocus();  //�����ת���û��������

        }
    }
    if (ui->userRadio->isChecked() == true)
    {
        sql = "select * from users where name = '" + ui->nameEdit->text().trimmed()
                + "' and passwd = '"+ ui->pwdEdit->text() + "' and role = 1";
        query.exec(sql);

        if (query.next())
        {
            loginName = ui->nameEdit->text().trimmed();
            this->close();
            userw = new userRoomDialog;
            userw->show();

            ui->nameEdit->clear();     //����û��������
            ui->pwdEdit->clear();      //������������
            ui->nameEdit->setFocus();  //�����ת���û��������
        }
        else
        {
            QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"),QMessageBox::Yes);

            ui->nameEdit->clear();     //����û��������
            ui->pwdEdit->clear();      //������������
            ui->nameEdit->setFocus();  //�����ת���û��������
        }
    }
}

void logonDialog::on_cancelBut_clicked()
{
    close();
}

void logonDialog::readMyCom()
{
    //��ȡ��������
    //��ȡ���ڻ��������������ݸ���ʱ����temp
    QByteArray temp = myCom->readAll();
    QString logonString(temp);

    //logon:�û���,����,Ȩ��
    //logon:us::1
    if(logonString == "")
    {
        return;
    }

    QStringList logonStringList = logonString.split(":");
    if(logonStringList.at(0) != "logon")
    {
        return;
    }

    QSqlQuery query;
    QString sql;

    sql = "select * from users where name = '" + logonStringList.at(1)
            + "' and passwd = '"+ logonStringList.at(2) + "' and role = '" + logonStringList.at(3) + "'";
    query.exec(sql);

    if (query.next())
    {
        loginName = logonStringList.at(1);
        this->close();
        myCom->close();
        userw = new userRoomDialog;
        userw->show();

        ui->nameEdit->clear();     //����û��������
        ui->pwdEdit->clear();      //������������
        ui->nameEdit->setFocus();  //�����ת���û��������
    }
}
