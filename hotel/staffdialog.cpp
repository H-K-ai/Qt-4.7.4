#include "staffdialog.h"
#include "ui_staffdialog.h"

staffDialog::staffDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::staffDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->lineEdit_5->clear();

    on_pushButton_9_clicked();
}

staffDialog::~staffDialog()
{
    delete ui;
}

void staffDialog::on_pushButton_clicked()
{
    //���Ų�ѯ
    currentTableModel->setFilter("staffid = '" + ui->lineEdit->text().trimmed() + "'");
    currentTableModel->select();
}

void staffDialog::on_pushButton_2_clicked()
{
    //������ѯ
    currentTableModel->setFilter("name like '%" + ui->lineEdit_2->text().trimmed() + "%'");
    currentTableModel->select();
}

void staffDialog::on_pushButton_3_clicked()
{
    //���֤��ѯ
    currentTableModel->setFilter("idnum = '" + ui->lineEdit_3->text().trimmed() + "'");
    currentTableModel->select();
}

void staffDialog::on_pushButton_4_clicked()
{
    //ְλ��ѯ
    currentTableModel->setFilter("post = '" + ui->lineEdit_4->text().trimmed() + "'");
    currentTableModel->select();
}

void staffDialog::on_pushButton_5_clicked()
{
    //��ְʱ���ѯ
    currentTableModel->setFilter("date = '" + ui->dateEdit->date().toString("yyyy.MM.dd") + "'");
    currentTableModel->select();
}

void staffDialog::on_pushButton_6_clicked()
{
    //��ͼ
    picPath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
    if(picPath.length() == 0) {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
    } else {
        QMessageBox::information(NULL, tr("Path"), tr("You selected ") + picPath);
    }

    ui->label->setScaledContents(true);
    ui->label->setPixmap(picPath);
}

void staffDialog::on_pushButton_10_clicked()
{
    //����
    int rowNum = currentTableModel->rowCount(); //��ñ������
    int idNum = 0;
    QSqlQuery query;
    query.exec("select staffid from staff");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    ui->lineEdit->setText(QString::number(idNum, 10));

    QString targetPath = "staff/" + QString::number(idNum, 10) + ".jpg";
    copyFileToPath(picPath, targetPath, true); //����ʽ����

    currentTableModel->insertRow(rowNum); //���һ��
    currentTableModel->setData(currentTableModel->index(rowNum, 0), idNum);
    currentTableModel->setData(currentTableModel->index(rowNum, 1), ui->lineEdit_2->text());
    currentTableModel->setData(currentTableModel->index(rowNum, 2), ui->lineEdit_3->text());
    currentTableModel->setData(currentTableModel->index(rowNum, 3), ui->lineEdit_4->text());
    currentTableModel->setData(currentTableModel->index(rowNum, 4), ui->dateEdit->date().toString("yyyy.MM.dd"));
    currentTableModel->setData(currentTableModel->index(rowNum, 5), ui->lineEdit_5->text());
    currentTableModel->setData(currentTableModel->index(rowNum, 6), targetPath);

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->lineEdit_5->clear();

    currentTableModel->submitAll();
}

void staffDialog::on_pushButton_7_clicked()
{
    //�޸�
    QString sql;
    QSqlQuery query;

    sql = "delete from staff where staffid = '" + ui->lineEdit->text() + "'";
    query.exec(sql);

    //����ͼƬ
    QString targetPath = "staff/" + ui->lineEdit->text() + ".jpg";
    copyFileToPath(picPath, targetPath, true); //����ʽ����

    //�������ݿ�
    sql = "insert into staff values ('" +  ui->lineEdit->text()
            + "', '" + ui->lineEdit_2->text()
            + "', '" + ui->lineEdit_3->text()
            + "', '" + ui->lineEdit_4->text()
            + "', '" + ui->dateEdit->date().toString("yyyy.MM.dd")
            + "', '" + ui->lineEdit_5->text()
            + "', '" + targetPath
            + "')";
    qDebug() << sql << endl;
    query.exec(sql);

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->lineEdit_5->clear();

    currentTableModel->submitAll();

    currentTableModel->select();
}

void staffDialog::on_pushButton_8_clicked()
{
    //ɾ��
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->lineEdit_5->clear();
}

void staffDialog::on_pushButton_9_clicked()
{
    //ˢ��
    currentTableModel->setTable("staff");
    currentTableModel->select();
    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->lineEdit_5->clear();
}

void staffDialog::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    ui->lineEdit->setText(currentTableModel->index(curRow, 0).data().toString());
    ui->lineEdit_2->setText(currentTableModel->index(curRow, 1).data().toString());
    ui->lineEdit_3->setText(currentTableModel->index(curRow, 2).data().toString());
    ui->lineEdit_4->setText(currentTableModel->index(curRow, 3).data().toString());
    ui->dateEdit->setDate(QDate::fromString(currentTableModel->index(curRow, 4).data().toString(), "yyyy.MM.dd"));
    ui->lineEdit_5->setText(currentTableModel->index(curRow, 5).data().toString());
    picPath = currentTableModel->index(curRow, 6).data().toString();

    ui->label->setScaledContents(true);
    ui->label->setPixmap(picPath);
}
