#include "maindialog.h"
#include "ui_maindialog.h"

mainDialog::mainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainDialog)
{
    ui->setupUi(this);

    QDesktopWidget* desktop = QApplication::desktop();
    this->move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);
    this->setWindowTitle("ָ�ƿ�����");

    connect(&borrowW, SIGNAL(OnClose()), this, SLOT(selfShow()));
    connect(&backW, SIGNAL(OnClose()), this, SLOT(selfShow()));
    connect(&goodsW, SIGNAL(OnClose()), this, SLOT(selfShow()));
    connect(&addW, SIGNAL(OnClose()), this, SLOT(selfShow()));
    connect(&modW, SIGNAL(OnClose()), this, SLOT(selfShow()));
    connect(&selW, SIGNAL(OnClose()), this, SLOT(selfShow()));
}

mainDialog::~mainDialog()
{
    delete ui;
}

void mainDialog::showEvent(QShowEvent *)
{
}

void mainDialog::paintEvent(QPaintEvent *)
{}

void mainDialog::closeEvent(QCloseEvent *)
{
    emit OnClose();
}

void mainDialog::selfShow()
{
    this->show();
}

void mainDialog::on_pushButton_1_clicked()
{
    //�����Ʒ
    this->hide();
    borrowW.show();
}

void mainDialog::on_pushButton_2_clicked()
{
    //�黹��Ʒ
    this->hide();
    backW.show();
}

void mainDialog::on_pushButton_3_clicked()
{
    //��Ʒ����
    this->hide();
    goodsW.show();
}

void mainDialog::on_pushButton_4_clicked()
{
    //��ӿ��
    this->hide();
    addW.show();
}

void mainDialog::on_pushButton_5_clicked()
{
    //�޸Ŀ��
    this->hide();
    modW.show();
}


void mainDialog::on_pushButton_6_clicked()
{
    //��ѯ���
    this->hide();
    selW.show();
}


void mainDialog::on_pushButton_7_clicked()
{
    //���ص�¼
    this->close();
}

void mainDialog::on_pushButton_8_clicked()
{
    //�˳�ϵͳ
    this->hide();
    emit OnExit();
}
