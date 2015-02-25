#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);

    updateTableDay();
    on_pushButton_clicked(); //ȫ��
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    on_pushButton_clicked();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/png/bk.png").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void MainWindow::on_pushButton_6_clicked()
{
    //����
    windowsPos = this->QWidget::pos(); //��ȡ����λ��
    this->hide();

    itemDelButtonFlag = false;
    itemw = new itemWindow;
    itemw->move(windowsPos);   //���´���λ�õ�������ԭ��һ��
    itemw->show();
    itemw->exec();

    this->move(windowsPos);
    this->show();
    currentTableModel->select(); //ѡȡ�������������,�˴��൱��ˢ��
}

void MainWindow::on_pushButton_clicked()
{
    //ȫ��
    currentView = ui->tableView;

    currentTableModel->setTable("day");

    currentTableModel->removeColumn(3);  //��ȥ������
    currentTableModel->removeColumn(0);  //��ȥ��һ��


    int ruleInt;
    QString sql;
    QSqlQuery query;

    sql = "select rule from orderoption where orderoptionid = '1'";
    query.exec(sql);
    while(query.next())
    {
        ruleInt = query.value(0).toInt();
    }
    if(ruleInt == 1) //����ʣ����������
    {
        currentTableModel->setSort(1, Qt::AscendingOrder);
    }

    currentTableModel->select(); //ѡȡ�������������


    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭
}

void MainWindow::on_pushButton_2_clicked()
{
    //������
    currentTableModel->setFilter("sort = '0'");
}

void MainWindow::on_pushButton_3_clicked()
{
    //����
    currentTableModel->setFilter("sort = '1'");
}

void MainWindow::on_pushButton_4_clicked()
{
    //����
    currentTableModel->setFilter("sort = '2'");
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    //˫���б�
    windowsPos = this->QWidget::pos(); //��ȡ����λ��
    this->hide();

    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QModelIndex indexData = currentTableModel->index(curRow, 0);   //���һ����¼��һ�����Ե�ֵ
    viewTitle = indexData.data().toString();

    itemDelButtonFlag = true;
    itemw = new itemWindow;
    itemw->move(windowsPos);   //���´���λ�õ�������ԭ��һ��
    itemw->show();
    itemw->exec();

    this->move(windowsPos);
    this->show();
    currentTableModel->select(); //ѡȡ�������������,�˴��൱��ˢ��
}

void MainWindow::updateTableDay()
{
    //���µ���ʱ����
    QString titleStr; //����
    QString dateStr;  //����
    int dittoInt;     //�ظ�

    QSqlQuery query;

    int curId = 0;
    int totalNum = 0;
    int dayResult = 0;

    query.exec("select dayid from day");
    while(query.next())
        totalNum++;
    qDebug() << "totalNum = " << totalNum;

    do
    {
        query.exec("select title from day where dayid = '" + QString::number(curId, 10) + "'");
        while(query.next())
            titleStr = query.value(0).toString();

        query.exec("select data, ditto from note where title = '" + titleStr + "'");
        while(query.next())
        {
            dateStr = query.value(0).toString();
            dittoInt = query.value(1).toInt();
        }

        dayResult = datedef(dateStr, dittoInt);
        query.exec("update day set daynum = '" + QString::number(dayResult, 10) + "' where dayid = '" + QString::number(curId, 10) + "'");

        curId++;

        qDebug() << "curId = " << curId;
        qDebug() << "titleStr = " << titleStr;
        qDebug() << "dateStr = " << dateStr;
        qDebug() << "dittoInt = " << dittoInt;
        qDebug() << "dayResult = " << dayResult;
    }while(curId != totalNum+1);
}
