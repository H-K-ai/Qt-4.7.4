#include "userdialog.h"
#include "ui_userdialog.h"

userDialog::userDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    on_pushButton_5_clicked();

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

userDialog::~userDialog()
{
    delete ui;
}

void userDialog::showEvent(QShowEvent *)
{
    on_pushButton_5_clicked();

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void userDialog::paintEvent(QPaintEvent *)
{
#if 0
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/png/user.png").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
#endif
}

void userDialog::on_pushButton_clicked()
{
    //����
    QSqlQuery query;
    int idNum = 0;
    QString name = ui->lineEdit->text().trimmed();
    bool nameFlag = false;

    query.exec("select personid from person");
    while(query.next())
    {
        idNum = query.value(0).toInt() + 1;
    }

    query.exec("select name from person");
    while(query.next())
    {
        if(name == query.value(0).toString())
        {
            QMessageBox::information(NULL, "fail", "name repeat!");
            nameFlag = true;
            break;
        }
    }

    if(nameFlag == false)
    {
        query.exec("insert into person values('" + QString::number(idNum, 10) + "', '" + name + "', '" + ui->lineEdit_2->text().trimmed() + "')");

        ui->lineEdit->clear();
        ui->lineEdit_2->clear();

        currentTableModel->select();
        QMessageBox::information(NULL, "success", "user add success!");
    }
}

void userDialog::on_pushButton_2_clicked()
{
    //�޸�
    currentView->setEditTriggers(QAbstractItemView::AllEditTriggers);
}

void userDialog::on_pushButton_3_clicked()
{
    //ɾ��
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������
}

void userDialog::on_pushButton_4_clicked()
{
    //�ύ
    currentTableModel->submitAll();
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void userDialog::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
}

void userDialog::on_pushButton_5_clicked()
{
    //ˢ��
    currentTableModel->setTable("person");
    currentTableModel->select();
    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}
