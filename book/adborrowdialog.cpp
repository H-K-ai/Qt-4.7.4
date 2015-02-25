#include "adborrowdialog.h"
#include "ui_adborrowdialog.h"

adBorrowDialog::adBorrowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adBorrowDialog)
{
    ui->setupUi(this);

    updateComboBox();

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    currentTableModel->setTable("borrow");
    currentTableModel->setFilter("realreturndate = '7999.12.31'");
    currentTableModel->select();

    currentTableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("���"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("ͼ����"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("ѧ�����"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("��������"));
    currentTableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("��������"));
    currentTableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("�黹����"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_3->setDate(QDate::currentDate());    

    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
}

adBorrowDialog::~adBorrowDialog()
{
    delete ui;
}

void adBorrowDialog::showEvent(QShowEvent *)
{
    //��ʾ����
    currentTableModel->setTable("borrow");
    currentTableModel->setFilter("realreturndate = '7999.12.31'");
    currentTableModel->setSort(0, Qt::AscendingOrder);
    currentTableModel->select();

    currentTableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("���"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("ͼ����"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("ѧ�����"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("��������"));
    currentTableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("��������"));
    currentTableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("�黹����"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_3->setDate(QDate::currentDate());

    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
}

void adBorrowDialog::on_pushButton_5_clicked()
{
    //�������
    currentTableModel->setFilter("bookcode like '%" + ui->lineEdit_3->text().trimmed() + "%' and realreturndate = '7999.12.31'");
    currentTableModel->select();
}

void adBorrowDialog::on_pushButton_6_clicked()
{
    //ѧ������
    currentTableModel->setFilter("stucode like '%" + ui->lineEdit_4->text().trimmed() + "%' and realreturndate = '7999.12.31'");
    currentTableModel->select();
}

void adBorrowDialog::on_pushButton_clicked()
{
    //�������
    QSqlQuery query;
    int idNum = 0;

    if(ui->comboBox->currentText() == "")
    {
        QMessageBox::information(NULL, "warring", "ͼ���Ų���Ϊ��!");
        return;
    }

    if(ui->comboBox_2->currentText() == "")
    {
        QMessageBox::information(NULL, "warring", "ѧ����Ų���Ϊ��!");
        return;
    }

    query.exec("select borrowid from borrow");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    query.exec("insert into borrow values('" + QString::number(idNum, 10) + "', '"
               + ui->comboBox->currentText() + "', '"
               + ui->comboBox_2->currentText() + "', '"
               + ui->dateEdit->date().toString("yyyy.MM.dd") + "', '"
               + ui->dateEdit_2->date().toString("yyyy.MM.dd") + "', '"
               + "7999.12.31" + "')");

    query.exec("update books set status = 1 where bookcode = '" + ui->comboBox->currentText() + "'");

    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_3->setDate(QDate::currentDate());

    currentTableModel->select();
    QMessageBox::information(NULL, "success", "���ĳɹ�!");

    updateComboBox();
}

void adBorrowDialog::on_pushButton_2_clicked()
{
    //�黹ͼ��
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();

    query.exec("update borrow set realreturndate = '"
               + QDate::currentDate().toString("yyyy.MM.dd")
               + "' where borrowid = '" + idNum + "'");

    query.exec("update books set status = 0 where bookcode = '" + ui->comboBox->currentText() + "'");

    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_3->setDate(QDate::currentDate());

    currentTableModel->select();
    QMessageBox::information(NULL, "success", "�黹�ɹ�!");

    updateComboBox();
}

void adBorrowDialog::on_pushButton_4_clicked()
{
    //ˢ��
    updateComboBox();

    currentTableModel->setTable("borrow");
    currentTableModel->setFilter("realreturndate = '7999.12.31'");
    currentTableModel->setSort(0, Qt::AscendingOrder);
    currentTableModel->select();

    currentTableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("���"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("ͼ����"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("ѧ�����"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("��������"));
    currentTableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("��������"));
    currentTableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("�黹����"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_3->setDate(QDate::currentDate());

    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
}

void adBorrowDialog::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();

    ui->comboBox->clear();
    ui->comboBox_2->clear();

    ui->comboBox->addItem(currentTableModel->index(curRow, 1).data().toString());
    ui->comboBox_2->addItem(currentTableModel->index(curRow, 2).data().toString());

    query.exec("select * from borrow where borrowid = '" + idNum + "'");
    while(query.next())
    {
        ui->comboBox->setCurrentIndex(ui->comboBox->findText(query.value(1).toString()));
        ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(query.value(2).toString()));
        ui->dateEdit->setDate(QDate::fromString(query.value(3).toString(), "yyyy.MM.dd"));
        ui->dateEdit_3->setDate(QDate::fromString(query.value(5).toString(), "yyyy.MM.dd"));

        ui->pushButton->setEnabled(false);
        if(query.value(5).toString() == "7999.12.31")
            ui->pushButton_2->setEnabled(true);
        else
            ui->pushButton_2->setEnabled(false);
    }
}

void adBorrowDialog::updateComboBox()
{
    //��ʼ����Ͽ�
    QSqlQuery query;
    ui->comboBox->clear();
    ui->comboBox_2->clear();

    ui->comboBox->addItem("");
    ui->comboBox_2->addItem("");

    query.exec("select bookcode from books where status = 0");
    while(query.next())
        ui->comboBox->addItem(query.value(0).toString());

    query.exec("select stucode from students where status = 0");
    while(query.next())
        ui->comboBox_2->addItem(query.value(0).toString());
}

void adBorrowDialog::on_dateEdit_dateChanged(const QDate &date)
{
    //�������ڸı�
    ui->dateEdit_2->setDate(ui->dateEdit->date().addMonths(2));
}
