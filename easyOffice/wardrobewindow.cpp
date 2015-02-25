#include "wardrobewindow.h"
#include "ui_wardrobewindow.h"

wardrobeWindow::wardrobeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wardrobeWindow)
{
    ui->setupUi(this);

    clothesSelect = true;

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    currentTableModel->setTable("clothes");
    currentTableModel->setSort(0, Qt::AscendingOrder);
    currentTableModel->select(); //ѡȡ�������������
    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox_3->setCurrentIndex(0);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->textEdit->clear();

    on_pushButton_clicked();
}

wardrobeWindow::~wardrobeWindow()
{
    delete ui;
}

void wardrobeWindow::on_pushButton_clicked()
{
    //�ҵ��¹�
    clothesSelect = true;
    tableWidgetData();
    currentTableModel->setTable("clothes");
    currentTableModel->setSort(0, Qt::AscendingOrder);
    currentTableModel->select();

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox_3->setCurrentIndex(0);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->textEdit->clear();
}

void wardrobeWindow::on_pushButton_2_clicked()
{
    //�ҵĴ���
    clothesSelect = false;
    tableWidgetData();
    currentTableModel->setTable("clothes");
    currentTableModel->setSort(0, Qt::AscendingOrder);
    currentTableModel->select();

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox_3->setCurrentIndex(0);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->textEdit->clear();
}

void wardrobeWindow::on_pushButton_3_clicked()
{
    //ÿ�մ���
    //matchDlg.show();
}

void wardrobeWindow::on_pushButton_4_clicked()
{
    //�������
    int rowNum = currentTableModel->rowCount(); //��ñ������
    int idNum = 0;
    QSqlQuery query;
    query.exec("select clothesid from clothes");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    QString targetPath = "supplies/" + QString::number(idNum, 10) + ".jpg";
    copyFileToPath(picPath, targetPath, true); //����ʽ����

    currentTableModel->insertRow(rowNum); //���һ��
    currentTableModel->setData(currentTableModel->index(rowNum, 0), idNum);
    currentTableModel->setData(currentTableModel->index(rowNum, 1), ui->lineEdit->text());
    currentTableModel->setData(currentTableModel->index(rowNum, 2), ui->comboBox->currentIndex());
    currentTableModel->setData(currentTableModel->index(rowNum, 3), ui->comboBox_2->currentIndex());
    currentTableModel->setData(currentTableModel->index(rowNum, 4), ui->comboBox_3->currentIndex());
    currentTableModel->setData(currentTableModel->index(rowNum, 5), ui->lineEdit_2->text());
    currentTableModel->setData(currentTableModel->index(rowNum, 6), ui->lineEdit_3->text());
    currentTableModel->setData(currentTableModel->index(rowNum, 7), ui->dateEdit->date().toString("yyyy.MM.dd"));
    currentTableModel->setData(currentTableModel->index(rowNum, 8), ui->lineEdit_4->text());
    currentTableModel->setData(currentTableModel->index(rowNum, 9), ui->lineEdit_5->text());
    currentTableModel->setData(currentTableModel->index(rowNum, 10), ui->textEdit->toPlainText());
    currentTableModel->setData(currentTableModel->index(rowNum, 11), targetPath);

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->textEdit->clear();

    currentTableModel->submitAll();
}

void wardrobeWindow::on_pushButton_5_clicked()
{
    //�޸�����
    QString sql;
    QSqlQuery query;

    sql = "delete from clothes where clothesid = '" + QString::number(clothesSelectId, 10) + "'";
    query.exec(sql);

    //����ͼƬ
    QString targetPath = "clothes/" + QString::number(clothesSelectId, 10) + ".jpg";
    copyFileToPath(picPath, targetPath, true); //����ʽ����

    //�������ݿ�
    sql = "insert into clothes values ('" + QString::number(clothesSelectId, 10)
            + "', '" + ui->lineEdit->text()
            + "', '" + QString::number(ui->comboBox->currentIndex(), 10)
            + "', '" + QString::number(ui->comboBox_2->currentIndex(), 10)
            + "', '" + QString::number(ui->comboBox_3->currentIndex(), 10)
            + "', '" + ui->lineEdit_2->text()
            + "', '" + ui->lineEdit_3->text()
            + "', '" + ui->dateEdit->date().toString("yyyy.MM.dd")
            + "', '" + ui->lineEdit_4->text()
            + "', '" + ui->lineEdit_5->text()
            + "', '" + ui->textEdit->toPlainText()
            + "', '" + targetPath
            + "')";
    query.exec(sql);

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->textEdit->clear();

    currentTableModel->submitAll();

    currentTableModel->select();
}

void wardrobeWindow::on_pushButton_6_clicked()
{
    //ɾ������
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������
    currentTableModel->submitAll();
}

void wardrobeWindow::on_pushButton_7_clicked()
{
    //�ϴ�ͼƬ
    picPath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
    if(picPath.length() == 0) {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
    } else {
        QMessageBox::information(NULL, tr("Path"), tr("You selected ") + picPath);
    }

    ui->label->setScaledContents(true);
    ui->label->setPixmap(picPath);
}

void wardrobeWindow::on_tableWidget_clicked(const QModelIndex &index)
{
    //��������б�
    int curRow = ui->tableWidget->currentItem()->row();  //��ȡѡ�е���
    switch(clothesSelect)
    {
    case true:
        currentTableModel->setFilter("type ='" + QString::number(curRow, 10) + "'");
        ui->comboBox->setCurrentIndex(curRow);
        break;
    case false:
        if(curRow < 4)
        {
            currentTableModel->setFilter("season ='" + QString::number(curRow, 10) + "'");
            ui->comboBox_2->setCurrentIndex(curRow);
            ui->comboBox_3->setCurrentIndex(0);
        }
        else
        {
            currentTableModel->setFilter("classtype ='" + QString::number(curRow-4, 10) + "'");
            ui->comboBox_2->setCurrentIndex(0);
            ui->comboBox_3->setCurrentIndex(curRow-4);
        }
        break;
    default:
        break;
    }

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->textEdit->clear();
}

void wardrobeWindow::on_tableView_clicked(const QModelIndex &index)
{
    //�����Ҳ��б�
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    clothesSelectId = currentTableModel->index(curRow, 0).data().toInt();   //���ID��

    ui->lineEdit->setText(currentTableModel->index(curRow, 1).data().toString());
    ui->comboBox->setCurrentIndex(currentTableModel->index(curRow, 2).data().toInt());
    ui->comboBox_2->setCurrentIndex(currentTableModel->index(curRow, 3).data().toInt());
    ui->comboBox_3->setCurrentIndex(currentTableModel->index(curRow, 4).data().toInt());
    ui->lineEdit_2->setText(currentTableModel->index(curRow, 5).data().toString());
    ui->lineEdit_3->setText(currentTableModel->index(curRow, 6).data().toString());
    ui->dateEdit->setDate(QDate::fromString(currentTableModel->index(curRow, 7).data().toString(), "yyyy.MM.dd"));
    ui->lineEdit_4->setText(currentTableModel->index(curRow, 8).data().toString());
    ui->lineEdit_5->setText(currentTableModel->index(curRow, 9).data().toString());
    ui->textEdit->setPlainText(currentTableModel->index(curRow, 10).data().toString());
    picPath = currentTableModel->index(curRow, 11).data().toString();

    ui->label->setScaledContents(true);
    ui->label->setPixmap(picPath);
}

void wardrobeWindow::tableWidgetData()
{
    //����б��������
    int i = 0;
    ui->tableWidget->setRowCount(100); //����һ���ϴ���к�

    switch(clothesSelect)
    {
    case true:
        ui->tableWidget->setItem(i++, 0, new QTableWidgetItem(QString("�ľ���Ʒ")));
        ui->tableWidget->setItem(i++, 0, new QTableWidgetItem(QString("�칫�Ĳ�")));
        ui->tableWidget->setItem(i++, 0, new QTableWidgetItem(QString("���Ӱٻ�")));
        ui->tableWidget->setItem(i++, 0, new QTableWidgetItem(QString("�칫�豸")));
        ui->tableWidget->setItem(i++, 0, new QTableWidgetItem(QString("�칫�Ҿ�")));
        ui->tableWidget->setItem(i++, 0, new QTableWidgetItem(QString("������Ʒ")));
        break;
    case false:
        ui->tableWidget->setItem(i++, 0, new QTableWidgetItem(QString("����")));
        ui->tableWidget->setItem(i++, 0, new QTableWidgetItem(QString("�ļ�")));
        ui->tableWidget->setItem(i++, 0, new QTableWidgetItem(QString("�＾")));
        ui->tableWidget->setItem(i++, 0, new QTableWidgetItem(QString("����")));
        ui->tableWidget->setItem(i++, 0, new QTableWidgetItem(QString("ְ��")));
        ui->tableWidget->setItem(i++, 0, new QTableWidgetItem(QString("����")));
        ui->tableWidget->setItem(i++, 0, new QTableWidgetItem(QString("�˶�")));
        ui->tableWidget->setItem(i++, 0, new QTableWidgetItem(QString("���")));
        ui->tableWidget->setItem(i++, 0, new QTableWidgetItem(QString("����")));
        break;
    default:
        break;
    }

    //����Ϊ��������
    ui->tableWidget->setRowCount(i);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);  //��ѡ

    //ȥ��tableWidget�Դ����к�
    QHeaderView* headerView = ui->tableWidget->verticalHeader();
    headerView->setHidden(true);
}

void wardrobeWindow::on_pushButton_8_clicked()
{
    //�Ƽ�����
    //randDlg.show();
}

void wardrobeWindow::on_pushButton_9_clicked()
{
    //�ֿ��ѯ
    warw.show();
}

void wardrobeWindow::on_pushButton_10_clicked()
{
    //�۸�ͳ��
    cashw.show();
}

void wardrobeWindow::on_pushButton_11_clicked()
{
    //��Ա����
    userw.show();
}
