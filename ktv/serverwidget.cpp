#include "serverwidget.h"
#include "ui_serverwidget.h"

serverWidget::serverWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::serverWidget)
{
    ui->setupUi(this);

    currentTableModel = new QSqlRelationalTableModel(this);
    currentView = ui->tableView;

    currentTableModel->setTable("roomNum");
    currentTableModel->setRelation(1, QSqlRelation("roomStatus", "roomStatusid", "status"));
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->sortByColumn(0, Qt::AscendingOrder);
    currentView->setItemDelegate(new QSqlRelationalDelegate(currentView));

    QHeaderView* headerView = currentView->verticalHeader();
    headerView->setHidden(true);
}

serverWidget::~serverWidget()
{
    delete ui;
}

void serverWidget::on_pushButton_clicked()
{
    //������Ѷ�
    QString sql;
    QSqlQuery query;
    int tmp = -1;

    //���Ҹ��û������Ѷ�
    sql = "select amount from member where name = '"
            + ui->lineEdit->text().trimmed() + "'";
    query.exec(sql);
    while(query.next())
        tmp = query.value(0).toInt();

    if(tmp == -1)
    {
        QMessageBox::information(NULL, tr("member"), tr("û���ҵ������Ա!"));
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
    }
    else
    {
        sql = "update member set amount = '" + QString::number(tmp+ui->lineEdit_2->text().trimmed().toInt(), 10)
                + "' where name = '" + ui->lineEdit->text().trimmed() + "'";
        query.exec(sql);
        QMessageBox::information(NULL, tr("member"), tr("success!"));

        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
    }
}

void serverWidget::on_pushButton_2_clicked()
{
    //���
    int rowNum = currentTableModel->rowCount(); //��ñ������
    currentTableModel->insertRow(rowNum); //���һ��
    currentTableModel->setData(currentTableModel->index(rowNum, 1), 0);

    ui->pushButton_2->setEnabled(false);
}

void serverWidget::on_pushButton_3_clicked()
{
    //ɾ��
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������
}

void serverWidget::on_pushButton_5_clicked()
{
    //�ύ
    currentTableModel->submitAll();
    currentTableModel->select(); //ѡȡ�������������
    ui->pushButton_2->setEnabled(true);
}

void serverWidget::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
#if 0
    QString sql;
    QSqlQuery query;
    int tmp;
    int i=0;
    for(i=0; i<currentTableModel->rowCount(); i++)
    {
        sql = "select status from roomNum where roomNumid = '"
                + currentTableModel->index(i, 0).data().toString() + "'";
        query.exec(sql);
        while(query.next())
            tmp = query.value(0).toInt();
        switch(tmp)
        {
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        default:
            break;
        }
    }
#endif
}

void serverWidget::on_pushButton_6_clicked()
{
    //�˳���¼
    this->close();
    emit returnDialog();
}

void serverWidget::paintEvent(QPaintEvent *)
{
    //����ͼƬ
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/png/4.png").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}
