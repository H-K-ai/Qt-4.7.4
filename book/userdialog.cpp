#include "userdialog.h"
#include "ui_userdialog.h"

userDialog::userDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userDialog)
{
    ui->setupUi(this);

    msgTimer = new QTimer(this);
    connect(msgTimer, SIGNAL(timeout()), this, SLOT(msgTimeOut()));
}

userDialog::~userDialog()
{
    delete ui;
}

void userDialog::showEvent(QShowEvent *)
{
    //��ʾ����
    msgTimer->start(1*1000);

    chatw.setNickName();

    chatw.sendMessage("student:" + loginName);

    //chatw.show();
}

void userDialog::closeEvent(QCloseEvent *)
{
    //�˳�
    qDebug("leave!");
    int i = 100;
    while(i--)
        chatw.sendMessage("leave:" + loginName);
}

void userDialog::setStuCode(QString tmp)
{
    stuCode = tmp;
    usInfow.setStuCode(tmp);
    usBorroww.setStuCode(tmp);
}

void userDialog::on_pushButton_9_clicked()
{
    //������Ϣ
    usInfow.show();
}

void userDialog::on_pushButton_11_clicked()
{
    //������Ϣ
    usBorroww.show();
}

void userDialog::on_pushButton_10_clicked()
{
    //ͼ����Ϣ����
    bookSearchw.show();
}

void userDialog::msgTimeOut()
{
    //��ȡϵͳ��Ϣ
    QSqlQuery msgQuery, delQuery;
    msgQuery.exec("select * from message where stucode = '" + stuCode + "'");
    while(msgQuery.next())
    {
        QMessageBox::information(NULL, "����Ա����", "�𾴵�<font color='red'> " + stuCode + " </font>�û�:<br><br>�����ĵ�ͼ��<font color='red'> " + msgQuery.value(1).toString() + " </font>�ѵ���!<br><br>����Ա��ʾ�����컹��!");
        delQuery.exec("delete from message where messageid = '" + msgQuery.value(0).toString() + "'");
    }

    chatw.sendMessage("student:" + loginName);
}

void userDialog::on_pushButton_12_clicked()
{
    //�˳���¼
    this->close();

    msgTimer->stop();

    emit loginOut();
}
