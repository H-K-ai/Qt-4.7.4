#include "adminusersdialog.h"
#include "ui_adminusersdialog.h"

adminUsersDialog::adminUsersDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminUsersDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    currentTableModel->setTable("users");
    currentTableModel->select();

    currentTableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("编号"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("用户名"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("密码"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("权限"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->comboBox->setCurrentIndex(0);
}

adminUsersDialog::~adminUsersDialog()
{
    delete ui;
}

void adminUsersDialog::showEvent(QShowEvent *)
{
    currentTableModel->setTable("users");
    currentTableModel->select();

    currentTableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("编号"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("用户名"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("密码"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("权限"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->comboBox->setCurrentIndex(0);
}

void adminUsersDialog::paintEvent(QPaintEvent *)
{
    //QPainter painter(this);
    //painter.drawPixmap(0, 0, QPixmap(":/jpg/6.jpg").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void adminUsersDialog::on_pushButton_clicked()
{
    //添加
    QSqlQuery query;
    int idNum = 0;
    QString name = ui->lineEdit->text().trimmed();
    bool nameFlag = false;

    query.exec("select usersid from users");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    query.exec("select name from users");
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
        query.exec("insert into users values('" + QString::number(idNum, 10) + "', '" + name + "', '" + ui->lineEdit_2->text().trimmed() + "', '" + QString::number(ui->comboBox->currentIndex()) + "')");

        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->comboBox->setCurrentIndex(0);

        currentTableModel->select();
        QMessageBox::information(NULL, "success", "user add success!");
    }
}

void adminUsersDialog::on_pushButton_2_clicked()
{
    //删除
    int curRow = currentView->currentIndex().row(); //获取选中的行
    currentTableModel->removeRow(curRow); //删除该行
}

void adminUsersDialog::on_pushButton_3_clicked()
{
    //修改密码
    int curRow = currentView->currentIndex().row(); //获取选中的行
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();
    query.exec("delete from users where usersid = '" + idNum + "'");

    query.exec("insert into users values('" + idNum + "', '" + ui->lineEdit->text().trimmed() + "', '" + ui->lineEdit_2->text().trimmed() + "', '" + QString::number(ui->comboBox->currentIndex()) + "')");

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->comboBox->setCurrentIndex(0);

    currentTableModel->select();
    QMessageBox::information(NULL, "success", "modefy success!");
}

void adminUsersDialog::on_tableView_clicked(const QModelIndex &index)
{
    //列表单击
    int curRow = currentView->currentIndex().row(); //获取选中的行
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();

    query.exec("select * from users where usersid = '" + idNum + "'");
    while(query.next())
    {
        ui->lineEdit->setText(query.value(1).toString());
        ui->lineEdit_2->setText(query.value(2).toString());
        ui->comboBox->setCurrentIndex(query.value(3).toInt());
    }
}

