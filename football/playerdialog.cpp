#include "playerdialog.h"
#include "ui_playerdialog.h"

playerDialog::playerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::playerDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    currentTableModel->setTable("info");
    currentTableModel->select();    

    currentTableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("���"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("����λ��"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("���"));
    currentTableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(6, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(7, Qt::Horizontal, QObject::tr("���º���"));
    currentTableModel->setHeaderData(8, Qt::Horizontal, QObject::tr("ͼƬ·��"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);    

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->dateEdit->setDate(QDate::currentDate());
}

playerDialog::~playerDialog()
{
    delete ui;
}

void playerDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/jpg/5.jpg").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void playerDialog::on_pushButton_clicked()
{
    //���
    QSqlQuery query;
    int idNum = 0;

    query.exec("select infoid from info");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    QString targetPath = "player/" + QString::number(idNum, 10) + ".jpg";
    copyFileToPath(picPath, targetPath, true); //����ʽ����

    query.exec("insert into info values('" + QString::number(idNum, 10) + "', '"
               + ui->lineEdit->text().trimmed() + "', '"
               + ui->lineEdit_2->text().trimmed() + "', '"
               + ui->dateEdit->date().toString("yyyy.MM.dd") + "', '"
               + ui->lineEdit_3->text().trimmed() + "', '"
               + ui->lineEdit_4->text().trimmed() + "', '"
               + ui->lineEdit_5->text().trimmed() + "', '"
               + ui->lineEdit_6->text().trimmed() + "', '"
               + targetPath + "')");

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->dateEdit->setDate(QDate::currentDate());

    currentTableModel->select();
    QMessageBox::information(NULL, "success", "add success!");

    emit addPlayer();
}

void playerDialog::on_pushButton_2_clicked()
{
    //ɾ��
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->dateEdit->setDate(QDate::currentDate());

    QMessageBox::information(NULL, "success", "delete success!");

    emit addPlayer();
}

void playerDialog::on_pushButton_3_clicked()
{
    //�޸�
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();
    query.exec("delete from info where infoid = '" + idNum + "'");

    QString targetPath = "player/" + idNum + ".jpg";
    copyFileToPath(picPath, targetPath, true); //����ʽ����

    query.exec("insert into info values('" + idNum + "', '"
               + ui->lineEdit->text().trimmed() + "', '"
               + ui->lineEdit_2->text().trimmed() + "', '"
               + ui->dateEdit->date().toString("yyyy.MM.dd") + "', '"
               + ui->lineEdit_3->text().trimmed() + "', '"
               + ui->lineEdit_4->text().trimmed() + "', '"
               + ui->lineEdit_5->text().trimmed() + "', '"
               + ui->lineEdit_6->text().trimmed() + "', '"
               + targetPath + "')");

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->dateEdit->setDate(QDate::currentDate());

    currentTableModel->select();
    QMessageBox::information(NULL, "success", "modefy success!");

    emit addPlayer();
}

void playerDialog::on_pushButton_4_clicked()
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

void playerDialog::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();

    query.exec("select * from info where infoid = '" + idNum + "'");
    while(query.next())
    {
        ui->lineEdit->setText(query.value(1).toString());
        ui->lineEdit_2->setText(query.value(2).toString());
        ui->dateEdit->setDate(QDate::fromString(query.value(3).toString(), "yyyy.MM.dd"));
        ui->lineEdit_3->setText(query.value(4).toString());
        ui->lineEdit_4->setText(query.value(5).toString());
        ui->lineEdit_5->setText(query.value(6).toString());
        ui->lineEdit_6->setText(query.value(7).toString());
        ui->label->setScaledContents(true);
        ui->label->setPixmap(QPixmap(query.value(8).toString()));
    }
}
