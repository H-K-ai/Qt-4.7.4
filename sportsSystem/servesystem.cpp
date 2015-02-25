#include "servesystem.h"
#include "ui_servesystem.h"

serveSystem::serveSystem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::serveSystem)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);

    on_pushButton_8_clicked();
}

serveSystem::~serveSystem()
{
    delete ui;
}

void serveSystem::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
}

void serveSystem::on_tableView_doubleClicked(const QModelIndex &index)
{
    //�б�˫��
}

void serveSystem::on_pushButton_clicked()
{
    //���
    int rowNum = currentTableModel->rowCount(); //��ñ������
    int id = currentTableModel->record(rowNum - 1).value(0).toInt() + 1;

    currentView->setEditTriggers(QAbstractItemView::AllEditTriggers);  //ʹ��ɱ༭
    currentTableModel->insertRow(rowNum); //���һ��
    currentTableModel->setData(currentTableModel->index(rowNum, 0), id);

    QString currentDate;
    currentDate = QDate::currentDate().toString("yyyy.MM.dd");
    QString currentTime;
    currentTime = QTime::currentTime().toString("hh:mm:ss");

    currentTableModel->setData(currentTableModel->index(rowNum, 1), currentDate);
    currentTableModel->setData(currentTableModel->index(rowNum, 2), currentTime);

    ui->pushButton->setEnabled(false); //��
}

void serveSystem::on_pushButton_2_clicked()
{
    //ɾ��
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������
}

void serveSystem::on_pushButton_3_clicked()
{
    //�޸�
    currentView->setEditTriggers(QAbstractItemView::DoubleClicked);  //ʹ��ɱ༭
}

void serveSystem::on_pushButton_6_clicked()
{
    //�ύ
    QString timeSql;
    QString priceSql;
    QSqlQuery query;
    QSqlQuery queryTime;
    QSqlQuery queryPrice;

    QString timeSqlStr;
    currentTableModel->submitAll();

    QString name;
    int num;
    int curNum;

    name = currentTableModel->index(currentTableModel->rowCount()-1, 3).data().toString();
    query.exec("select dnumber from depot where dname ='" + name + "'");
    while(query.next())
        num = query.value(0).toInt();
    curNum = num-currentTableModel->index(currentTableModel->rowCount()-1, 4).data().toInt();
    if(curNum < 0)
        curNum = 0;
    query.exec("update depot set dnumber = '" + QString::number(curNum, 10) + "' where dname ='" + name + "'");

    query.exec("select gnumber from goods where gname ='" + name + "'");
    while(query.next())
        num = query.value(0).toInt();
    curNum = num-currentTableModel->index(currentTableModel->rowCount()-1, 4).data().toInt();
    if(curNum < 0)
        curNum = 0;
    query.exec("update depot set gnumber = '" + QString::number(curNum, 10) + "' where gname ='" + name + "'");

    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭
    sumPrice = 0;

    timeSql = "select time from turnover where turnoverdate = '" + todayDate + "'";
    qDebug() << timeSql << endl;

    queryTime.exec(timeSql);
    while(queryTime.next())
    {
        timeSqlStr = queryTime.value(0).toString();
        qDebug() << timeSqlStr << endl;

        if(QTime::fromString(timeSqlStr, "hh:mm:ss") > QTime::fromString(startTime, "hh:mm:ss"))
        {
            priceSql = "select tprice from turnover where turnoverdate = '" + todayDate + "' and time = '" + timeSqlStr + "'";
            queryPrice.exec(priceSql);
            while(queryPrice.next())
            {
                sumPrice += queryPrice.value(0).toInt();
                qDebug() << queryPrice.value(0) << sumPrice << endl;
            }
        }
    }

    ui->label->setText(QString("�ϼ� :"+ QString::number(sumPrice, 10) + "Ԫ"));
    ui->pushButton->setEnabled(true); //��
}

void serveSystem::on_pushButton_7_clicked()
{
    //����
    int payNum = ui->lineEdit->text().trimmed().toInt();
    int changeNum = payNum - sumPrice;
    QString str = "���� : " + QString::number(changeNum, 10) + "Ԫ";

    ui->label_2->setText(str);
}

void serveSystem::on_pushButton_8_clicked()
{
    //�½�
    currentView = ui->tableView;

    currentTableModel->setTable("turnover");
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->pushButton->setEnabled(true); //��Ӱ�ť����

    sumPrice = 0;

    todayDate = QDate::currentDate().toString("yyyy.MM.dd");
    startTime = QTime::currentTime().toString("hh:mm:ss");

    ui->label->setText("�ϼ� :");
    ui->label_2->setText("���� :");

    ui->lineEdit->clear();
}

void serveSystem::on_pushButton_4_clicked()
{
    //�ϻ���
    QString sql;
    QSqlQuery query;
    int punchid = 0;
    punchLoginDateTime = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss");

    sql = "select punchid from punch";
    query.exec(sql);
    while(query.next())
    {
        punchid = query.value(0).toInt() + 1;
    }

    sql = "insert into punch (punchid, name, logtime, outtime) values ('" + QString::number(punchid, 10) + "', '" + serveName + "', '" + punchLoginDateTime + "', 'null')";
    qDebug() << sql << endl;
    query.exec(sql);

    if (query.next())
    {
        QMessageBox::warning(this,tr("Warning"),tr("user punch login fail!"),QMessageBox::Yes);
    }
    else
    {
        QMessageBox::information(this,tr("punch"),tr("user punch login success!"),QMessageBox::Yes);
    }
}

void serveSystem::on_pushButton_5_clicked()
{
    //�»���
    QString sql;
    QSqlQuery query;
    punchOutDateTime = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss");

    sql = "update punch set outtime = '" + punchOutDateTime + "' where logtime = '"+ punchLoginDateTime +"'";
    query.exec(sql);

    if (query.next())
    {
        QMessageBox::warning(this,tr("Warning"),tr("user punch out fail!"),QMessageBox::Yes);
    }
    else
    {
        QMessageBox::information(this,tr("punch"),tr("user punch out success!"),QMessageBox::Yes);
    }
}

void serveSystem::on_pushButton_9_clicked()
{
    //�˳���¼
    this->close();
    emit exitLogin();
}

void serveSystem::paintEvent(QPaintEvent *)
{
    //����ͼƬ
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/png/4.png").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}
