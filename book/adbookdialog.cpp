#include "adbookdialog.h"
#include "ui_adbookdialog.h"

adBookDialog::adBookDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adBookDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    currentTableModel->setTable("books");
    currentTableModel->setSort(0, Qt::AscendingOrder);
    currentTableModel->select();

    currentTableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("���"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("ͼ����"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("������"));
    currentTableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(6, Qt::Horizontal, QObject::tr("���ʱ��"));
    currentTableModel->setHeaderData(7, Qt::Horizontal, QObject::tr("״̬"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->dateEdit->setDate(QDate::currentDate());

    connect(&adModifyBookw, SIGNAL(modifyBook()), this, SLOT(on_pushButton_4_clicked()));
}

adBookDialog::~adBookDialog()
{
    delete ui;
}

void adBookDialog::showEvent(QShowEvent *)
{
    //��ʾ����
    currentTableModel->setTable("books");
    currentTableModel->setSort(0, Qt::AscendingOrder);
    currentTableModel->select();

    currentTableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("���"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("ͼ����"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("������"));
    currentTableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(6, Qt::Horizontal, QObject::tr("���ʱ��"));
    currentTableModel->setHeaderData(7, Qt::Horizontal, QObject::tr("״̬"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->dateEdit->setDate(QDate::currentDate());
}

void adBookDialog::on_pushButton_clicked()
{
    //�������
    QSqlQuery query;
    int idNum = 0;

    query.exec("select booksid,bookcode from books");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
        if(query.value(1).toString() == ui->lineEdit_2->text().trimmed())
        {
            QMessageBox::information(NULL, "Warring", "���ʧ��!ͼ�����ظ�.");
            return;
        }
    }

    idNum++;

    query.exec("insert into books values('" + QString::number(idNum, 10) + "', '"
               + ui->lineEdit->text().trimmed() + "', '"
               + ui->lineEdit_2->text().trimmed() + "', '"
               + ui->lineEdit_3->text().trimmed() + "', '"
               + ui->lineEdit_4->text().trimmed() + "', '"
               + ui->lineEdit_5->text().trimmed() + "', '"
               + ui->dateEdit->date().toString("yyyy.MM.dd") + "', '"
               + "0" + "')");

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->dateEdit->setDate(QDate::currentDate());

    currentTableModel->select();
    QMessageBox::information(NULL, "success", "��ӳɹ�!");

    emit addBook();
}

void adBookDialog::on_pushButton_2_clicked()
{
    //ͼ�����
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->dateEdit->setDate(QDate::currentDate());

    QMessageBox::information(NULL, "success", "ɾ���ɹ�!");

    emit addBook();
}

void adBookDialog::on_pushButton_3_clicked()
{
    //��Ϣ�޸�
#if 0
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();

    QString bookStatus;
    query.exec("select status from books where booksid = '" + idNum + "'");
    while(query.next())
        bookStatus = query.value(0).toString();

    query.exec("delete from books where booksid = '" + idNum + "'");

    query.exec("insert into books values('" + idNum + "', '"
               + ui->lineEdit->text().trimmed() + "', '"
               + ui->lineEdit_2->text().trimmed() + "', '"
               + ui->lineEdit_3->text().trimmed() + "', '"
               + ui->lineEdit_4->text().trimmed() + "', '"
               + ui->lineEdit_5->text().trimmed() + "', '"
               + ui->dateEdit->date().toString("yyyy.MM.dd") + "', '"
               + bookStatus + "')");

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->dateEdit->setDate(QDate::currentDate());

    currentTableModel->select();
    QMessageBox::information(NULL, "success", "�޸ĳɹ�!");
#endif
    adModifyBookw.show();

    emit addBook();
}

void adBookDialog::on_pushButton_4_clicked()
{
    //ˢ��
    currentTableModel->setTable("books");
    currentTableModel->setSort(0, Qt::AscendingOrder);
    currentTableModel->select();

    currentTableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("���"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("ͼ����"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("������"));
    currentTableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(6, Qt::Horizontal, QObject::tr("���ʱ��"));
    currentTableModel->setHeaderData(7, Qt::Horizontal, QObject::tr("״̬"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->dateEdit->setDate(QDate::currentDate());
}

void adBookDialog::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();

    query.exec("select * from books where booksid = '" + idNum + "'");
    while(query.next())
    {
        ui->lineEdit->setText(query.value(1).toString());
        ui->lineEdit_2->setText(query.value(2).toString());
        ui->lineEdit_3->setText(query.value(3).toString());
        ui->lineEdit_4->setText(query.value(4).toString());
        ui->lineEdit_5->setText(query.value(5).toString());
        ui->dateEdit->setDate(QDate::fromString(query.value(6).toString(), "yyyy.MM.dd"));
    }
}
