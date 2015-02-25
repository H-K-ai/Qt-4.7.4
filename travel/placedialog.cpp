#include "placedialog.h"
#include "ui_placedialog.h"

placeDialog::placeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::placeDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    on_pushButton_6_clicked();

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->textEdit->clear();
}

placeDialog::~placeDialog()
{
    delete ui;
}

void placeDialog::showEvent(QShowEvent *)
{
    on_pushButton_6_clicked();

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->textEdit->clear();
}

void placeDialog::paintEvent(QPaintEvent *)
{
}

void placeDialog::on_pushButton_8_clicked()
{
    //���Ʋ�ѯ
    currentTableModel->setFilter("name like '%" + ui->lineEdit->text().trimmed() + "%'");
    currentTableModel->select();
}

void placeDialog::on_pushButton_9_clicked()
{
    //���Ҳ�ѯ
    currentTableModel->setFilter("country like '%" + ui->lineEdit_2->text().trimmed() + "%'");
    currentTableModel->select();
}

void placeDialog::on_pushButton_10_clicked()
{
    //ʡ�ݲ�ѯ
    currentTableModel->setFilter("province like '%" + ui->lineEdit_3->text().trimmed() + "%'");
    currentTableModel->select();
}

void placeDialog::on_pushButton_11_clicked()
{
    //���в�ѯ
    currentTableModel->setFilter("city like '%" + ui->lineEdit_4->text().trimmed() + "%'");
    currentTableModel->select();
}

void placeDialog::on_pushButton_12_clicked()
{
    //������ѯ
    currentTableModel->setFilter("personnum like '%" + ui->lineEdit_5->text().trimmed() + "%'");
    currentTableModel->select();
}

void placeDialog::on_pushButton_13_clicked()
{
    //���ò�ѯ
    currentTableModel->setFilter("price like '%" + ui->lineEdit_6->text().trimmed() + "%'");
    currentTableModel->select();
}

void placeDialog::on_pushButton_7_clicked()
{
    //��ͼƬ
    picPath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
    if(picPath.length() == 0) {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
        return;
    } else {
        QMessageBox::information(NULL, tr("Path"), tr("You selected ") + picPath);
    }
    ui->label_2->setScaledContents(true);
    ui->label_2->setPixmap(QPixmap(picPath));
}

void placeDialog::on_pushButton_4_clicked()
{
    //�޸�
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();
    query.exec("delete from place where placeid = '" + idNum + "'");

    QString targetPath = "place/" + idNum + ".jpg";
    copyFileToPath(picPath, targetPath, true); //����ʽ����

    query.exec("insert into place values('" + idNum + "', '"
               + ui->lineEdit->text().trimmed() + "', '"
               + ui->lineEdit_2->text().trimmed() + "', '"
               + ui->lineEdit_3->text().trimmed() + "', '"
               + ui->lineEdit_4->text().trimmed() + "', '"
               + ui->lineEdit_5->text().trimmed() + "', '"
               + ui->lineEdit_6->text().trimmed() + "', '"
               + ui->textEdit->toPlainText() + "', '"
               + targetPath + "')");

    ui->label_2->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->textEdit->clear();

    currentTableModel->select();
    QMessageBox::information(NULL, "success", "modefy success!");
}

void placeDialog::on_pushButton_3_clicked()
{
    //���
    QSqlQuery query;
    int idNum = 0;

    query.exec("select placeid from place");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    QString targetPath = "place/" + QString::number(idNum, 10) + ".jpg";
    copyFileToPath(picPath, targetPath, true); //����ʽ����

    query.exec("insert into place values('" + QString::number(idNum, 10) + "', '"
               + ui->lineEdit->text().trimmed() + "', '"
               + ui->lineEdit_2->text().trimmed() + "', '"
               + ui->lineEdit_3->text().trimmed() + "', '"
               + ui->lineEdit_4->text().trimmed() + "', '"
               + ui->lineEdit_5->text().trimmed() + "', '"
               + ui->lineEdit_6->text().trimmed() + "', '"
               + ui->textEdit->toPlainText() + "', '"
               + targetPath + "')");

    ui->label_2->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->textEdit->clear();

    currentTableModel->select();
    QMessageBox::information(NULL, "success", "add success!");
}

void placeDialog::on_pushButton_5_clicked()
{
    //ɾ��
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������

    ui->label_2->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->textEdit->clear();

    QMessageBox::information(NULL, "success", "delete success!");
}

void placeDialog::on_pushButton_6_clicked()
{
    //ˢ��
    currentTableModel->setTable("place");
    currentTableModel->select();

    ui->label_2->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->textEdit->clear();

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void placeDialog::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();

    query.exec("select * from place where placeid = '" + idNum + "'");
    while(query.next())
    {
        ui->lineEdit->setText(query.value(1).toString());
        ui->lineEdit_2->setText(query.value(2).toString());
        ui->lineEdit_3->setText(query.value(3).toString());
        ui->lineEdit_4->setText(query.value(4).toString());
        ui->lineEdit_5->setText(query.value(5).toString());
        ui->lineEdit_6->setText(query.value(6).toString());
        ui->textEdit->setPlainText(query.value(7).toString());
        ui->label_2->setScaledContents(true);
        ui->label_2->setPixmap(QPixmap(query.value(8).toString()));
    }
}
