#include "coursedialog.h"
#include "ui_coursedialog.h"

courseDialog::courseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::courseDialog)
{
    ui->setupUi(this);
}

courseDialog::~courseDialog()
{
    delete ui;
}

void courseDialog::showEvent(QShowEvent *)
{
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setRowCount(5);

    int i = 0;
    ui->tableWidget->setColumnWidth(i, 30);
    int tableWidth = (ui->tableWidget->width() - 30) / 7;
    int tableHeight = (ui->tableWidget->height() - 30) / 5;
    for(i=1; i<8; i++)
    {
        ui->tableWidget->setColumnWidth(i, tableWidth);
    }
    for(i=0; i<5; i++)
    {
        ui->tableWidget->setRowHeight(i, tableHeight);
    }

    QHeaderView* headerView = ui->tableWidget->verticalHeader();
    headerView->setHidden(true);

    QStringList header;
    header.append("");
    header.append("��һ");
    header.append("�ܶ�");
    header.append("����");
    header.append("����");
    header.append("����");
    header.append("����");
    header.append("��ĩ");
    ui->tableWidget->setHorizontalHeaderLabels(header);

    i = 0;
    ui->tableWidget->setItem(i++, 0, new QTableWidgetItem("A"));
    ui->tableWidget->setItem(i++, 0, new QTableWidgetItem("B"));
    ui->tableWidget->setItem(i++, 0, new QTableWidgetItem("C"));
    ui->tableWidget->setItem(i++, 0, new QTableWidgetItem("D"));
    ui->tableWidget->setItem(i++, 0, new QTableWidgetItem("E"));

    QSqlQuery query;
    query.exec("select * from course where userid = " + userid);
    while(query.next())
    {
        ui->tableWidget->setItem(query.value(4).toInt(), query.value(3).toInt(), new QTableWidgetItem(query.value(2).toString()));
    }

    ui->lineEdit->clear();
}

void courseDialog::on_tableWidget_clicked(const QModelIndex &index)
{
    //�б���
    QString courseName = QString("");
    if(ui->tableWidget->item(index.row(), index.column()) == NULL)
    {
        courseName = QString("");
    }
    else
    {
        courseName = ui->tableWidget->item(index.row(), index.column())->text();
    }
    ui->lineEdit->setText(courseName);
}

void courseDialog::on_pushButton_clicked()
{
    //�޸�
    QString colIndex = QString::number(ui->tableWidget->currentColumn(), 10);
    QString rowIndex = QString::number(ui->tableWidget->currentRow(), 10);
    int idNum = 0;
    QSqlQuery query;
    query.exec("delete from course where userid = " + userid + " and colindex = " + colIndex + "and rowindex = " + rowIndex);

    query.exec("select courseid from course");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }
    idNum++;

    query.exec("insert into course values ('" + QString::number(idNum, 10) //�������ݿ�
               + "', '" + userid
               + "', '" + ui->lineEdit->text()
               + "', '" + colIndex
               + "', '" + rowIndex
               + "')");

    query.exec("select * from course where userid = " + userid);
    while(query.next())
    {
        ui->tableWidget->setItem(query.value(4).toInt(), query.value(3).toInt(), new QTableWidgetItem(query.value(2).toString()));
    }

    ui->lineEdit->clear();
}
