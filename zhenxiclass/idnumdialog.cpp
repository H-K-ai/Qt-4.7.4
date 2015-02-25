#include "idnumdialog.h"
#include "ui_idnumdialog.h"

idnumDialog::idnumDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::idnumDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    currentTableModel->setTable("student");
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
    currentTableModel->setHeaderData(9, Qt::Horizontal, QObject::tr("�໤��"));
    currentTableModel->setHeaderData(10, Qt::Horizontal, QObject::tr("�໤�˵绰"));
    currentTableModel->setHeaderData(11, Qt::Horizontal, QObject::tr("ͼƬ·��"));

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
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_5->clear();
    ui->dateEdit->setDate(QDate::currentDate());
}

idnumDialog::~idnumDialog()
{
    delete ui;
}

void idnumDialog::showEvent(QShowEvent *)
{
    currentTableModel->setTable("student");
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
    currentTableModel->setHeaderData(9, Qt::Horizontal, QObject::tr("�໤��"));
    currentTableModel->setHeaderData(10, Qt::Horizontal, QObject::tr("�໤�˵绰"));
    currentTableModel->setHeaderData(11, Qt::Horizontal, QObject::tr("ͼƬ·��"));

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
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_5->clear();
    ui->dateEdit->setDate(QDate::currentDate());
}

void idnumDialog::on_pushButton_clicked()
{
    //��ѯ
    currentTableModel->setFilter("aid like '%" + ui->lineEdit_5->text().trimmed() + "%'");

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->dateEdit->setDate(QDate::currentDate());
}

void idnumDialog::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();

    query.exec("select * from student where studentid = '" + idNum + "'");
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
        ui->lineEdit_8->setText(query.value(9).toString());
        ui->lineEdit_9->setText(query.value(10).toString());
        ui->label->setScaledContents(true);
        ui->label->setPixmap(QPixmap(query.value(11).toString()));
    }
}
