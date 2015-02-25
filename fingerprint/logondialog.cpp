#include "logondialog.h"
#include "ui_logondialog.h"

logonDialog::logonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logonDialog)
{
    ui->setupUi(this);

    QDesktopWidget* desktop = QApplication::desktop();
    this->move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);
    this->setWindowTitle("ָ�ƿ�����");

    qFinger = new qFingerprint(this);
    connect(qFinger, SIGNAL(OnImageReceived()), this, SLOT(finishImageReceived()));
    connect(qFinger, SIGNAL(OnFeatureInfo(int)), this, SLOT(finishFeatureInfo(int)));
    connect(qFinger, SIGNAL(OnCapture(QVariant)), this, SLOT(finishCapture(QVariant)));

    connect(&regw, SIGNAL(OnClose()), this, SLOT(selfShow()));
    connect(&mainw, SIGNAL(OnClose()), this, SLOT(selfShow()));
    connect(&mainw, SIGNAL(OnExit()), this, SLOT(exitApp()));

    //��ʼ��ָ������������
    initFingerTempMap();

    init();

    on_pushButton_clicked();
}

logonDialog::~logonDialog()
{
    qFinger->EndEngine();
    delete ui;
}

void logonDialog::init()
{
    //��ʼ��
    crackerFlag = 0;
    ui->lineEdit->setEnabled(false);
    ui->label_2->clear();
    ui->label_2->setScaledContents(true);
    ui->label_3->clear();
    ui->label_3->setText("ָ������ : ");
    ui->label_6->setText("���ڲ��� ...");

    ui->lineEdit_2->clear();
    ui->lineEdit_2->setEnabled(false);
    ui->comboBox->setEnabled(false);
    ui->comboBox->clear();
    ui->comboBox->addItem("Ա��");
    ui->comboBox->addItem("�ɹ�Ա");
    ui->comboBox->addItem("����Ա");
    ui->comboBox->addItem("����");
    ui->comboBox->setCurrentIndex(0);

    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);

    ui->lineEdit_3->clear();
}

void logonDialog::paintEvent(QPaintEvent *)
{}

void logonDialog::closeEvent(QCloseEvent *)
{}

void logonDialog::initFingerTempMap()
{
    //��ʼ����ǰ��ָ��ģ��
    QSqlQuery query;
    QString sql;
    int userid;
    QString fingerTempStr;
    QVariant fingerTempVar;

    sql = "select * from users";
    query.exec(sql);

    while(query.next())
    {
        userid = query.value(0).toInt();
        fingerTempStr = query.value(4).toString();
        fingerTempVar = qFinger->DecodeTemplate(fingerTempStr);
        insertFingerTempMap(userid, fingerTempVar);
    }
}

void logonDialog::keyPressEvent(QKeyEvent *e)
{
    switch(e->key())
    {
    case Qt::Key_Control:
        crackerFlag = 1;
        break;
    case Qt::Key_Alt:
        if(crackerFlag == 1)
        {
            crackerFlag = 2;
        }
        else
        {
            crackerFlag = 0;
        }
        break;
    case Qt::Key_F1:
        if(crackerFlag == 2)
        {
            crackerw.show();
        }
        else
        {
        }
        crackerFlag = 0;
        break;
    default:
        crackerFlag = 0;
        break;
    }
}

void logonDialog::findFingerUser(int mUserid)
{
    //������Ա��Ϣ
    QSqlQuery query;
    QString sql;
    int role = 0;

    sql = "select * from users where usersid = '" + QString::number(mUserid, 10) + "'";
    query.exec(sql);

    while(query.next())
    {
        ui->lineEdit_2->setText(query.value(1).toString());
        role = query.value(3).toInt();
        ui->comboBox->setCurrentIndex(role);
    }

    switch(role)
    {
    case 0:
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(true);
        break;
    case 1:
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(true);
        break;
    case 2:
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(true);
        break;
    case 3:
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        break;
    default:
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        break;
    }
}

void logonDialog::on_pushButton_clicked()
{
    //����ָ����
    int result = -1;
    QString strSN = "ָ������δ����!";
    result = qFinger->InitEngine();

    if(result == 0)
    {
        strSN = qFinger->SensorSN();
    }
    else
    {
        qFinger->EndEngine();
        QMessageBox::information(NULL, "error.", "��ʼ��ָ����ʧ��!");
    }
    ui->lineEdit->setText(QString(strSN));
}

void logonDialog::selfShow()
{
    //��ʾ�Լ�
    init();
    on_pushButton_clicked();
    this->show();
}

void logonDialog::exitApp()
{
    //�رճ���
    this->close();
}

void logonDialog::finishImageReceived()
{
    //ָ��ͼ�����
    qFinger->SaveBitmap();
    ui->label_2->setPixmap(QPixmap(fingerBmpPath));
}

void logonDialog::finishFeatureInfo(int Aquality)
{
    //ָ����������
    switch(Aquality)
    {
    case 0:
        ui->label_3->setText("ָ������ : �ϸ�");
        break;
    case 1:
        ui->label_3->setText("ָ������ : �����㲻��");
        break;
    case 2:
        ui->label_3->setText("ָ������ : �޷�ȡ��ָ������");
        break;
    default:
        ui->label_3->setText("ָ������ : ");
        break;
    }
    ui->lineEdit_2->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->label_6->setText("���ڶԱ� ...");
}

void logonDialog::finishCapture(QVariant ATemplate)
{
    //ָ�ƶԱ�
    QMapIterator<int, QVariant> i(fingerTemplateMap);
    while (i.hasNext())
    {
        i.next();
        if(qFinger->VerFinger(ATemplate, i.value()))
        {
            ui->label_6->setText("���ҳɹ� ...");
            findFingerUser(i.key());
        }
    }
}

void logonDialog::on_pushButton_2_clicked()
{
    //ָ�ƹ���
    QString strSN = "ָ������δ����!";
    ui->lineEdit->setText(QString(strSN));

    qFinger->EndEngine();
    regw.show();
    this->close();
}

void logonDialog::on_pushButton_3_clicked()
{
    //������
    QString strSN = "ָ������δ����!";
    ui->lineEdit->setText(QString(strSN));

    qFinger->EndEngine();
    mainw.show();
    this->close();
}

void logonDialog::on_pushButton_4_clicked()
{
    //�����½
    QSqlQuery query;
    QString sql;

    sql = "select * from person where pwd = '" + ui->lineEdit_3->text().trimmed() + "'";
    query.exec(sql);

    if (query.next())
    {
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->lineEdit_3->clear();
    }
    else
    {
        QMessageBox::information(NULL, "error.", "�������!");

        ui->lineEdit_3->clear();
    }
}
