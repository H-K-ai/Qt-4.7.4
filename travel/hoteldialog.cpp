#include "hoteldialog.h"
#include "ui_hoteldialog.h"

hotelDialog::hotelDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hotelDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    on_pushButton_4_clicked();

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->textEdit->clear();
}

hotelDialog::~hotelDialog()
{
    delete ui;
}

void hotelDialog::showEvent(QShowEvent *)
{
    on_pushButton_4_clicked();

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->textEdit->clear();
}

void hotelDialog::paintEvent(QPaintEvent *)
{
}

void hotelDialog::on_pushButton_5_clicked()
{
    //��������
    currentTableModel->setFilter("name like '%" + ui->lineEdit->text().trimmed() + "%'");
    currentTableModel->select();
}

void hotelDialog::on_pushButton_6_clicked()
{
    //��������
    currentTableModel->setFilter("country like '%" + ui->lineEdit_2->text().trimmed() + "%'");
    currentTableModel->select();
}

void hotelDialog::on_pushButton_7_clicked()
{
    //ʡ������
    currentTableModel->setFilter("province like '%" + ui->lineEdit_3->text().trimmed() + "%'");
    currentTableModel->select();
}

void hotelDialog::on_pushButton_8_clicked()
{
    //��������
    currentTableModel->setFilter("city like '%" + ui->lineEdit_4->text().trimmed() + "%'");
    currentTableModel->select();
}

void hotelDialog::on_pushButton_9_clicked()
{
    //�ص�����
    currentTableModel->setFilter("place like '%" + ui->lineEdit_5->text().trimmed() + "%'");
    currentTableModel->select();
}

void hotelDialog::on_pushButton_10_clicked()
{
    //��������
    currentTableModel->setFilter("hoteltype like '%" + ui->lineEdit_6->text().trimmed() + "%'");
    currentTableModel->select();
}

void hotelDialog::on_pushButton_clicked()
{
    //���
    QSqlQuery query;
    int idNum = 0;

    query.exec("select hotelid from hotel");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    query.exec("insert into hotel values('" + QString::number(idNum, 10) + "', '"
               + ui->lineEdit->text().trimmed() + "', '"
               + ui->lineEdit_2->text().trimmed() + "', '"
               + ui->lineEdit_3->text().trimmed() + "', '"
               + ui->lineEdit_4->text().trimmed() + "', '"
               + ui->lineEdit_5->text().trimmed() + "', '"
               + ui->lineEdit_6->text().trimmed() + "', '"
               + ui->lineEdit_7->text().trimmed() + "', '"
               + ui->lineEdit_8->text().trimmed() + "', '"
               + ui->textEdit->toPlainText() + "')");

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->textEdit->clear();

    currentTableModel->select();
    QMessageBox::information(NULL, "success", "add success!");
}

void hotelDialog::on_pushButton_2_clicked()
{
    //�޸�
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();
    query.exec("delete from hotel where hotelid = '" + idNum + "'");

    query.exec("insert into hotel values('" + idNum + "', '"
               + ui->lineEdit->text().trimmed() + "', '"
               + ui->lineEdit_2->text().trimmed() + "', '"
               + ui->lineEdit_3->text().trimmed() + "', '"
               + ui->lineEdit_4->text().trimmed() + "', '"
               + ui->lineEdit_5->text().trimmed() + "', '"
               + ui->lineEdit_6->text().trimmed() + "', '"
               + ui->lineEdit_7->text().trimmed() + "', '"
               + ui->lineEdit_8->text().trimmed() + "', '"
               + ui->textEdit->toPlainText() + "')");

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->textEdit->clear();

    currentTableModel->select();
    QMessageBox::information(NULL, "success", "modefy success!");
}

void hotelDialog::on_pushButton_3_clicked()
{
    //ɾ��
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->textEdit->clear();

    QMessageBox::information(NULL, "success", "delete success!");
}

void hotelDialog::on_pushButton_4_clicked()
{
    //ˢ��
    currentTableModel->setTable("hotel");
    currentTableModel->select();

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->textEdit->clear();

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void hotelDialog::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();

    query.exec("select * from hotel where hotelid = '" + idNum + "'");
    while(query.next())
    {
        ui->lineEdit->setText(query.value(1).toString());
        ui->lineEdit_2->setText(query.value(2).toString());
        ui->lineEdit_3->setText(query.value(3).toString());
        ui->lineEdit_4->setText(query.value(4).toString());
        ui->lineEdit_5->setText(query.value(5).toString());
        ui->lineEdit_6->setText(query.value(6).toString());
        ui->lineEdit_7->setText(query.value(7).toString());
        ui->lineEdit_8->setText(query.value(8).toString());
        ui->textEdit->setPlainText(query.value(9).toString());
    }
}
