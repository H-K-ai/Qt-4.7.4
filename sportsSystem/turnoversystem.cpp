#include "turnoversystem.h"
#include "ui_turnoversystem.h"

turnoverSystem::turnoverSystem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::turnoverSystem)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);

    currentView = ui->tableView;

    currentTableModel->setTable("turnover");
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->label->clear();
    ui->label_2->clear();

    ui->dateEdit_2->setDateTime(QDateTime::currentDateTime()); //����Ϊ��ǰʱ��

    ui->lcdNumber->display(0);
}

turnoverSystem::~turnoverSystem()
{
    delete ui;
}

void turnoverSystem::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    QString sql;
    QSqlQuery query;
    QString labelInfo;
    QString picPath;
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QModelIndex indexData = currentTableModel->index(curRow, 3);   //���һ����¼��һ�����Ե�ֵ

    sql = "select * from depot where dname = '" + indexData.data().toString() + "'";  //�ڲֿ���в���

    qDebug() << sql << endl;
    query.exec(sql);
    do
    {
        labelInfo = " ��Ʒ���� : " + query.value(1).toString()
                + "\n\n ��Ʒ���� : " + query.value(2).toString()
                + "\n\n ʣ����� : " + query.value(3).toString();
        picPath = query.value(4).toString();

        qDebug() << labelInfo << endl;
        qDebug() << picPath << endl;
    }while(query.next());

    ui->label->setScaledContents(true);
    ui->label->setPixmap(picPath);

    ui->label_2->setText(labelInfo);
}

void turnoverSystem::on_pushButton_clicked()
{
    //��ѯ
    QDateTime preDate =  ui->dateEdit->dateTime();
    QDateTime nextDate =  ui->dateEdit_2->dateTime();

    if(preDate > nextDate)
    {
        QMessageBox::warning(this,tr("Warning"),tr("preDate > nextDate!"),QMessageBox::Yes);
        ui->dateEdit->setDateTime(nextDate); //����Ϊ��һ��ʱ��
        ui->lcdNumber->display(0);
        return;
    }

    QString dateSql;
    QSqlQuery queryDate;
    int turnoverSum = 0;

    currentTableModel->setFilter("turnoverdate >= '" + preDate.toString("yyyy.MM.dd")
                                 + "' and turnoverdate <= '" + nextDate.toString("yyyy.MM.dd") + "'");
    currentTableModel->select();

    dateSql = "select tprice from turnover where turnoverdate >= '" + preDate.toString("yyyy.MM.dd")
            + "' and turnoverdate <= '" + nextDate.toString("yyyy.MM.dd") + "'";
    queryDate.exec(dateSql);

    while(queryDate.next())
    {
        turnoverSum += queryDate.value(0).toInt();
    }

    qDebug() << turnoverSum << endl;

    ui->lcdNumber->display(turnoverSum);
}

void turnoverSystem::paintEvent(QPaintEvent *)
{
    //����ͼƬ
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/png/5.png").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}
