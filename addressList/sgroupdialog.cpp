#include "sgroupdialog.h"
#include "ui_sgroupdialog.h"

sgroupDialog::sgroupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sgroupDialog)
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
    currentTableModel->setHeaderData(10, Qt::Horizontal, QObject::tr("����"));

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
    ui->comboBox_2->setCurrentIndex(0);

    initComboBox_2();
}

sgroupDialog::~sgroupDialog()
{
    delete ui;
}

void sgroupDialog::on_comboBox_2_currentIndexChanged(int index)
{
    //��ϵ�˷���
    currentTableModel->setTable("address");

    if(index == 0)
    {
        //NULL
    }
    else
    {
        currentTableModel->setFilter("mygroup = '" + ui->comboBox_2->currentText() + "'");

    }
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
    currentTableModel->setHeaderData(10, Qt::Horizontal, QObject::tr("����"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
void sgroupDialog::showEvent(QShowEvent *)
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
    currentTableModel->setHeaderData(10, Qt::Horizontal, QObject::tr("����"));

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
    ui->comboBox_2->setCurrentIndex(0);

    initComboBox_2();
}

void sgroupDialog::paintEvent(QPaintEvent *)
{
    //QPainter painter(this);
    //painter.drawPixmap(0, 0, QPixmap(":/jpg/5.jpg").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void sgroupDialog::on_tableView_clicked(const QModelIndex &index)
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

void sgroupDialog::initComboBox_2()
{
    //��ʼ��
    QSqlQuery query;
    ui->comboBox_2->clear();
    ui->comboBox_2->addItem("");

    query.exec("select name from myGroup");
    while(query.next())
        ui->comboBox_2->addItem(query.value(0).toString());
}
