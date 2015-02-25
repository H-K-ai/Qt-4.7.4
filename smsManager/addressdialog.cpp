#include "addressdialog.h"
#include "ui_addressdialog.h"

addressDialog::addressDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addressDialog)
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
}

addressDialog::~addressDialog()
{
    delete ui;
}

void addressDialog::paintEvent(QPaintEvent *)
{
    //QPainter painter(this);
    //painter.drawPixmap(0, 0, QPixmap(":/jpg/5.jpg").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void addressDialog::on_pushButton_clicked()
{
    //���
    QSqlQuery query;
    int idNum = 0;

    query.exec("select addressid from address");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    QString targetPath = "user/" + QString::number(idNum, 10) + ".jpg";
    copyFileToPath(picPath, targetPath, true); //����ʽ����

    query.exec("insert into address values('" + QString::number(idNum, 10) + "', '"
               + ui->lineEdit->text().trimmed() + "', '"
               + ui->lineEdit_2->text().trimmed() + "', '"
               + ui->lineEdit_3->text().trimmed() + "', '"
               + ui->lineEdit_4->text().trimmed() + "', '"
               + QString::number(ui->comboBox->currentIndex(), 10) + "', '"
               + ui->lineEdit_6->text().trimmed() + "', '"
               + ui->lineEdit_7->text().trimmed() + "', '"
               + ui->dateEdit->date().toString("yyyy.MM.dd") + "', '"
               + targetPath + "', '"
               + QString::number(ui->comboBox_2->currentIndex(), 10) + "')");

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

    currentTableModel->select();
    QMessageBox::information(NULL, "success", "add success!");

    emit addUser();
}

void addressDialog::on_pushButton_2_clicked()
{
    //ɾ��
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������

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

    QMessageBox::information(NULL, "success", "delete success!");

    emit addUser();
}

void addressDialog::on_pushButton_3_clicked()
{
    //�޸�
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();
    query.exec("delete from address where addressid = '" + idNum + "'");

    QString targetPath = "user/" + idNum + ".jpg";
    copyFileToPath(picPath, targetPath, true); //����ʽ����

    query.exec("insert into address values('" + idNum + "', '"
               + ui->lineEdit->text().trimmed() + "', '"
               + ui->lineEdit_2->text().trimmed() + "', '"
               + ui->lineEdit_3->text().trimmed() + "', '"
               + ui->lineEdit_4->text().trimmed() + "', '"
               + QString::number(ui->comboBox->currentIndex(), 10) + "', '"
               + ui->lineEdit_6->text().trimmed() + "', '"
               + ui->lineEdit_7->text().trimmed() + "', '"
               + ui->dateEdit->date().toString("yyyy.MM.dd") + "', '"
               + targetPath + "', '"
               + QString::number(ui->comboBox_2->currentIndex(), 10) + "')");

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

    currentTableModel->select();
    QMessageBox::information(NULL, "success", "modefy success!");

    emit addUser();
}

void addressDialog::on_pushButton_4_clicked()
{
    //ͷ��
    picPath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
    if(picPath.length() == 0) {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
        return;
    } else {
        QMessageBox::information(NULL, tr("Path"), tr("You selected ") + picPath);
    }
    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(picPath));
}

void addressDialog::on_tableView_clicked(const QModelIndex &index)
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
        ui->comboBox_2->setCurrentIndex(query.value(10).toInt());
    }
}

void addressDialog::on_comboBox_2_currentIndexChanged(int index)
{
    //��ϵ�˷���
    currentTableModel->setTable("address");

    if(index == 0)
    {
        //NULL
    }
    else
    {
        currentTableModel->setFilter("groupsms = '" + QString::number(ui->comboBox_2->currentIndex(), 10) + "'");

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
