#include "smsdialog.h"
#include "ui_smsdialog.h"

smsDialog::smsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::smsDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    currentTableModel->setTable("address");
    currentTableModel->select();

    currentTableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("���"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("�绰"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("���֤��"));
    currentTableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("�Ա�"));
    currentTableModel->setHeaderData(6, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(7, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(8, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(9, Qt::Horizontal, QObject::tr("ͼƬ·��"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->dateEdit->setDate(QDate::currentDate());
}

smsDialog::~smsDialog()
{
    delete ui;
}

void smsDialog::showEvent(QShowEvent *)
{
    currentTableModel->setTable("address");
    currentTableModel->select();

    currentTableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("���"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("�绰"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("���֤��"));
    currentTableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("�Ա�"));
    currentTableModel->setHeaderData(6, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(7, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(8, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(9, Qt::Horizontal, QObject::tr("ͼƬ·��"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->dateEdit->setDate(QDate::currentDate());
}

void smsDialog::paintEvent(QPaintEvent *)
{
    //QPainter painter(this);
    //painter.drawPixmap(0, 0, QPixmap(":/jpg/5.jpg").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void smsDialog::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();

    query.exec("select * from address where addressid = '" + idNum + "'");
    while(query.next())
    {
        ui->lineEdit->setText(query.value(1).toString());
        ui->lineEdit_2->setText(query.value(2).toString());
        ui->lineEdit_3->setText(query.value(3).toString());
        ui->lineEdit_4->setText(query.value(4).toString());
        ui->comboBox->setCurrentIndex(query.value(5).toInt());
        ui->lineEdit_6->setText(query.value(6).toString());
        ui->lineEdit_7->setText(query.value(7).toString());
        ui->dateEdit->setDate(QDate::fromString(query.value(8).toString(), "yyyy.MM.dd"));
        ui->label->setScaledContents(true);
        ui->label->setPixmap(QPixmap(query.value(9).toString()));
    }
}

void smsDialog::on_pushButton_clicked()
{
    //���ֲ�ѯ
    currentTableModel->setFilter("aname like '%" + ui->lineEdit->text().trimmed() + "%'");
    currentTableModel->select();
}

void smsDialog::on_pushButton_2_clicked()
{
    //�绰��ѯ
    currentTableModel->setFilter("aphone like '%" + ui->lineEdit_2->text().trimmed() + "%'");
    currentTableModel->select();
}

void smsDialog::on_pushButton_3_clicked()
{
    //���֤��ѯ
    currentTableModel->setFilter("aid like '%" + ui->lineEdit_3->text().trimmed() + "%'");
    currentTableModel->select();
}

void smsDialog::on_pushButton_4_clicked()
{
    //�����ѯ
    currentTableModel->setFilter("aage like '%" + ui->lineEdit_4->text().trimmed() + "%'");
    currentTableModel->select();
}

void smsDialog::on_pushButton_5_clicked()
{
    //�Ա��ѯ
    currentTableModel->setFilter("asex = '" + QString::number(ui->comboBox->currentIndex(), 10) + "'");
    currentTableModel->select();
}

void smsDialog::on_pushButton_6_clicked()
{
    //�����ѯ
    currentTableModel->setFilter("anation like '%" + ui->lineEdit_6->text().trimmed() + "%'");
    currentTableModel->select();
}

void smsDialog::on_pushButton_7_clicked()
{
    //�����ѯ
    currentTableModel->setFilter("aorigin like '%" + ui->lineEdit_7->text().trimmed() + "%'");
    currentTableModel->select();
}

void smsDialog::on_pushButton_8_clicked()
{
    //���ղ�ѯ
    currentTableModel->setFilter("abirth = '" + ui->dateEdit->date().toString("yyyy.MM.dd") + "'");
    currentTableModel->select();
}
