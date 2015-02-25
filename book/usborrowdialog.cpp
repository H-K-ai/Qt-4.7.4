#include "usborrowdialog.h"
#include "ui_usborrowdialog.h"

usBorrowDialog::usBorrowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::usBorrowDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    currentTableModel->setTable("borrow");
    currentTableModel->select();

    currentTableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("���"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("ͼ����"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("ѧ�����"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("��������"));
    currentTableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("��������"));
    currentTableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("�黹����"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());
}

usBorrowDialog::~usBorrowDialog()
{
    delete ui;
}

void usBorrowDialog::showEvent(QShowEvent *)
{
    //��ʾ����
    currentTableModel->setTable("borrow");
    currentTableModel->setFilter("stucode = '" + stuCode + "'");
    currentTableModel->select();

    currentTableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("���"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("ͼ����"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("ѧ�����"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("��������"));
    currentTableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("��������"));
    currentTableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("�黹����"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());
}

void usBorrowDialog::setStuCode(QString tmp)
{
    stuCode = tmp;
}

void usBorrowDialog::on_pushButton_2_clicked()
{
    //��ʷ���Ĳ�ѯ
    currentTableModel->setTable("borrow");
    currentTableModel->setFilter("stucode = '" + stuCode + "'");
    currentTableModel->select();

    currentTableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("���"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("ͼ����"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("ѧ�����"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("��������"));
    currentTableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("��������"));
    currentTableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("�黹����"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());
}

void usBorrowDialog::on_pushButton_clicked()
{
    //����ͼ���ѯ
    currentTableModel->setFilter("returndate < '"
                                 + QDate::currentDate().toString("yyyy.MM.dd")
                                 + "' and realreturndate = '7999.12.31' and stucode = '"
                                 + stuCode + "'");
    currentTableModel->select();

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());
}

void usBorrowDialog::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();
    QString bookCode;

    query.exec("select * from borrow where borrowid = '" + idNum + "'");
    while(query.next())
    {
        bookCode = query.value(1).toString();
        ui->dateEdit->setDate(QDate::fromString(query.value(3).toString(), "yyyy.MM.dd"));
        ui->dateEdit_2->setDate(QDate::fromString(query.value(4).toString(), "yyyy.MM.dd"));
    }

    query.exec("select * from books where bookcode = '" + bookCode + "'");
    while(query.next())
    {
        ui->lineEdit->setText(query.value(1).toString());
        ui->lineEdit_2->setText(bookCode);
    }
}
