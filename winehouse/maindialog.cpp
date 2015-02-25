#include "maindialog.h"
#include "ui_maindialog.h"

mainDialog::mainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainDialog)
{
    ui->setupUi(this);

    //���Ӹ����źźͲ�
    connect(&checkinw.inroomw, SIGNAL(inRoom()), &roomw, SLOT(updateRoom()));       //��ס�ź�,����room״̬
    connect(&roomw, SIGNAL(modifyRoom()), &checkinw.inroomw, SLOT(initDialog()));   //����room�ź�,�޸���Ӧѡ�����ʾ

    connect(&checkinw.outroomw, SIGNAL(outRoom()), &roomw, SLOT(updateRoom()));
    connect(&roomw, SIGNAL(modifyRoom()), &checkinw.outroomw, SLOT(initDialog()));

    connect(&checkinw.bookroomw, SIGNAL(bookRoom()), &roomw, SLOT(updateRoom()));
    connect(&roomw, SIGNAL(modifyRoom()), &checkinw.bookroomw, SLOT(initDialog()));

    connect(&checkinw.inroomw, SIGNAL(inRoom()), &checkinw, SLOT(initDialog()));
    connect(&checkinw.inroomw, SIGNAL(inRoom()), &checkinw.outroomw, SLOT(initDialog()));
    connect(&checkinw.inroomw, SIGNAL(inRoom()), &checkinw.bookroomw, SLOT(initDialog()));

    connect(&checkinw.outroomw, SIGNAL(outRoom()), &checkinw.inroomw, SLOT(initDialog()));
    connect(&checkinw.outroomw, SIGNAL(outRoom()), &checkinw.bookroomw, SLOT(initDialog()));

    connect(&checkinw.bookroomw, SIGNAL(bookRoom()), &checkinw.inroomw, SLOT(initDialog()));
    connect(&checkinw.bookroomw, SIGNAL(bookRoom()), &checkinw.outroomw, SLOT(initDialog()));

    connect(&checkinw.inroomw, SIGNAL(inRoom()), &incomew, SLOT(initDialog()));

    connect(&checkinw.inroomw, SIGNAL(inRoom()), &searchw.bookw, SLOT(initDialog()));
    connect(&checkinw.bookroomw, SIGNAL(bookRoom()), &searchw.bookw, SLOT(initDialog()));

    connect(&checkinw.inroomw, SIGNAL(inRoom()), &searchw.inw, SLOT(initDialog()));
    connect(&checkinw.outroomw, SIGNAL(outRoom()), &searchw.inw, SLOT(initDialog()));

    connect(&checkinw.inroomw, SIGNAL(inRoom()), &searchw.callw, SLOT(initDialog()));
    connect(&checkinw.outroomw, SIGNAL(outRoom()), &searchw.callw, SLOT(initDialog()));
}

mainDialog::~mainDialog()
{
    delete ui;
}

void mainDialog::on_pushButton_clicked()
{
    //ס�޹���
    checkinw.show();
}

void mainDialog::on_pushButton_2_clicked()
{
    //�ͷ�����
    roomw.show();
}

void mainDialog::on_pushButton_3_clicked()
{
    //���˹���
    incomew.show();
}

void mainDialog::on_pushButton_4_clicked()
{
    //��ѯͳ��
    searchw.show();
}
