#include "admindialog.h"
#include "ui_admindialog.h"

adminDialog::adminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminDialog)
{
    ui->setupUi(this);

    connect(&assw, SIGNAL(addAssessor()), &memw, SLOT(initComboBox()));
}

adminDialog::~adminDialog()
{
    delete ui;
}

void adminDialog::on_pushButton_clicked()
{
    //��Ա����
    userw.show();
}

void adminDialog::on_pushButton_4_clicked()
{
    //���ʹ���
    assw.show();
}

void adminDialog::on_pushButton_3_clicked()
{
    //��Ա����
    memw.show();
}

void adminDialog::on_pushButton_5_clicked()
{
    //�򿨹���
    punw.show();
}

void adminDialog::on_pushButton_2_clicked()
{
    //��������
    turnw.show();
}

void adminDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/jpg/11.jpg").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}
