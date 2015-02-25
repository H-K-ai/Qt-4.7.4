#include "userwindow.h"
#include "ui_userwindow.h"

userWindow::userWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::userWindow)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);

    //ˢ��¥��
    on_pushButton_4_clicked();
}

userWindow::~userWindow()
{
    delete ui;
}

void userWindow::on_pushButton_clicked()
{
    //��һ��
    if (picCol <= 3)
    {
        picCol = 7;
    }
    else
    {
        picCol--;
    }
    QModelIndex indexData = currentTableModel->index(picRow, picCol);   //���һ����¼��һ�����Ե�ֵ
    qDebug() << indexData.data() << endl;

    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(indexData.data().toString()));
}

void userWindow::on_pushButton_4_clicked()
{
    //ˢ��
    currentView = ui->tableView;

    currentTableModel->setTable("houses");
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->label->clear();
}

void userWindow::on_pushButton_2_clicked()
{
    //��һ��
    if (picCol < 3)
    {
        picCol = 4;
    }
    else if (picCol >= 7)
    {
        picCol = 3;
    }
    else
    {
        picCol++;
    }
    QModelIndex indexData = currentTableModel->index(picRow, picCol);   //���һ����¼��һ�����Ե�ֵ
    qDebug() << indexData.data() << endl;

    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(indexData.data().toString()));
}

void userWindow::on_pushButton_3_clicked()
{
    //�����޸�
    QString name;
    QString sPwd;
    QString tPwd;
    QString sql;
    QSqlQuery query;

    name = ui->lineEdit->text().trimmed();
    sPwd = ui->lineEdit_2->text().trimmed();
    tPwd = ui->lineEdit_3->text().trimmed();

    sql = "select * from person where pname = '" + name
            + "' and passwd = '"+ sPwd + "' and role = 1";

    query.exec(sql);
    if (query.next())
    {
        sql = "update person set passwd = '" + tPwd + "' where pname = '" + name + "' and role = 1";
        query.exec(sql);
        QMessageBox::warning(this,tr("Success"),tr("successfully Modify!"), QMessageBox::Yes);

        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"), QMessageBox::Yes);

        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
    }
}

void userWindow::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    picCol = currentView->currentIndex().column(); //��ȡѡ�е���
    picRow = currentView->currentIndex().row(); //��ȡѡ�е���

    QModelIndex indexData = currentTableModel->index(picRow, 3);   //���һ����¼��һ�����Ե�ֵ

    if (picCol < 3)
    {
        indexData = currentTableModel->index(picRow, 3);   //���һ����¼��һ�����Ե�ֵ
    }
    else
    {
        indexData = currentTableModel->index(picRow, picCol);   //���һ����¼��һ�����Ե�ֵ
    }
    qDebug() << indexData.data() << endl;

    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(indexData.data().toString()));
}

void userWindow::on_pushButton_5_clicked()
{
    //���԰�
    messagew.show();
}

void userWindow::on_pushButton_6_clicked()
{
    //�˳���¼
    this->hide();
    emit closeWindows();
}
