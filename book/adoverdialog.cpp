#include "adoverdialog.h"
#include "ui_adoverdialog.h"

adOverDialog::adOverDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adOverDialog)
{
    ui->setupUi(this);

    updateComboBox();

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    currentTableModel->setTable("borrow");
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
    ui->dateEdit_2->setDate(QDate::currentDate());
    ui->dateEdit_3->setDate(QDate::currentDate());
}

adOverDialog::~adOverDialog()
{
    delete ui;
}

void adOverDialog::showEvent(QShowEvent *)
{
    //��ʾ����
    currentTableModel->setTable("borrow");
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
    ui->dateEdit_2->setDate(QDate::currentDate());
    ui->dateEdit_3->setDate(QDate::currentDate());
}

void adOverDialog::on_pushButton_5_clicked()
{
    //���յ����û�
    currentTableModel->setFilter("returndate = '" + QDate::currentDate().addDays(1).toString("yyyy.MM.dd") + "' and realreturndate = '7999.12.31'");
    currentTableModel->select();
}

void adOverDialog::on_pushButton_6_clicked()
{
    //�Ѿ������û�
    currentTableModel->setFilter("returndate < '" + QDate::currentDate().toString("yyyy.MM.dd") + "' and realreturndate = '7999.12.31'");
    currentTableModel->select();
}

void adOverDialog::on_pushButton_clicked()
{
    //��ǰ�û���������
    QMessageBox::information(NULL, "warring", "δ��⵽����װ��!");
}

void adOverDialog::on_pushButton_2_clicked()
{
    //��ǰϵͳ��Ϣ����
    QSqlQuery query;
    int idNum = 0;

    chatw.setNickName();

    if(ui->comboBox->currentText() == "")
    {
        QMessageBox::information(NULL, "warring", "ͼ����Ϊ��!");
        return;
    }

    if(ui->comboBox_2->currentText() == "")
    {
        QMessageBox::information(NULL, "warring", "����֤���Ϊ��!");
        return;
    }

    if(chatw.isOnline(ui->comboBox_2->currentText()))
    {
        chatw.sendMessage("warring book:" + ui->comboBox->currentText() + QString(" user:") + ui->comboBox_2->currentText());

        QMessageBox::information(NULL, "success", "�û�����,�ѷ��ͳɹ�!");
    }
    else
    {
        query.exec("select messageid from message");
        while(query.next())
        {
            if(idNum < query.value(0).toInt())
                idNum = query.value(0).toInt();
        }

        idNum++;

        query.exec("insert into message values('" + QString::number(idNum, 10) + "', '"
                   + ui->comboBox->currentText() + "', '"
                   + ui->comboBox_2->currentText() + "', '"
                   + ui->dateEdit_3->date().toString("yyyy.MM.dd") + "')");

        QMessageBox::information(NULL, "success", "�û�δ����,�ѷ���������Ϣ!");
    }


    //chatw.show();
}

void adOverDialog::on_pushButton_3_clicked()
{
    //ȫ����������
    QMessageBox::information(NULL, "warring", "δ��⵽����װ��!");
}

void adOverDialog::on_pushButton_4_clicked()
{
    //ȫ��ϵͳ����
    QSqlQuery query;
    int idNum = 0;
    int rowCount = currentTableModel->rowCount();

    query.exec("select messageid from message");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    for(int i=0; i<rowCount; i++, idNum++)
        query.exec("insert into message values('" + QString::number(idNum, 10) + "', '"
                   + currentTableModel->index(i, 1).data().toString() + "', '"
                   + currentTableModel->index(i, 2).data().toString() + "', '"
                   + currentTableModel->index(i, 4).data().toString() + "')");

    QMessageBox::information(NULL, "success", "���ͳɹ�!");
}

void adOverDialog::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();

    query.exec("select * from borrow where borrowid = '" + idNum + "'");
    while(query.next())
    {
        ui->comboBox->setCurrentIndex(ui->comboBox->findText(query.value(1).toString()));
        ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(query.value(2).toString()));
        ui->dateEdit_2->setDate(QDate::fromString(query.value(3).toString(), "yyyy.MM.dd"));
        ui->dateEdit_3->setDate(QDate::fromString(query.value(4).toString(), "yyyy.MM.dd"));
    }
}

void adOverDialog::updateComboBox()
{
    //��ʼ����Ͽ�
    QSqlQuery query;
    ui->comboBox->clear();
    ui->comboBox_2->clear();

    ui->comboBox->addItem("");
    ui->comboBox_2->addItem("");

    query.exec("select bookcode from books");
    while(query.next())
        ui->comboBox->addItem(query.value(0).toString());

    query.exec("select stucode from students");
    while(query.next())
        ui->comboBox_2->addItem(query.value(0).toString());
}
