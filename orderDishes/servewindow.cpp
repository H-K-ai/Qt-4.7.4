#include "servewindow.h"
#include "ui_servewindow.h"

serveWindow::serveWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::serveWindow)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);

    tabViews.append(ui->svTableTabView);
    tabViews.append(ui->svDishesTabView);
    tabViews.append(ui->svMoneyTabView);

    sqlNames.append("desk");
    sqlNames.append("dishDesk");
    sqlNames.append("dishDesk");

    tempTableModel = new QSqlTableModel(this);
    tempView = new QTableView;

    connect(tempView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(addDeskDishesToDatabass(QModelIndex)));

    currentModelDoubleClickedFlag = false;

    on_svSelButton_clicked();
}

serveWindow::~serveWindow()
{
    delete ui;
}

void serveWindow::on_svTableAction_triggered()
{
    //��λ����
    ui->tabWidget->setCurrentIndex(0);   //�����ת����λ����ѡ�
    on_svSelButton_clicked();
}

void serveWindow::on_svDishesAction_triggered()
{
    //��˹���
    ui->tabWidget->setCurrentIndex(1);   //�����ת����˹���ѡ�
    on_svSelButton_clicked();
}

void serveWindow::on_svPayAction_triggered()
{
    //���˹���
    ui->tabWidget->setCurrentIndex(2);   //�����ת�����˹���ѡ�
    on_svSelButton_clicked();
}

void serveWindow::on_svPwdAction_triggered()
{
    //�޸�����
}

void serveWindow::on_svCancelAction_triggered()
{
    //�˳�
    this->close();
}

void serveWindow::on_svAddButton_clicked()
{
    //�������
    int rowNum = currentTableModel->rowCount(); //��ñ������
    int id = currentTableModel->record(rowNum - 1).value(0).toInt() + 1;

    currentView->setEditTriggers(QAbstractItemView::AllEditTriggers);  //ʹ��ɱ༭
    currentTableModel->insertRow(rowNum); //���һ��
    if (0 == currentIndexNum)
    {
        currentTableModel->setData(currentTableModel->index(rowNum, 0), 0);
    }
    else
    {
        if (1 == currentIndexNum)
        {
            currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);  //ʹ��ɱ༭
        }
        currentTableModel->setData(currentTableModel->index(rowNum, 0), id);
    }

    currentModelDoubleClickedFlag = true;
}

void serveWindow::on_svDelButton_clicked()
{
    //ɾ������
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������
}

void serveWindow::on_svChButton_clicked()
{
    //�޸�����
    currentView->setEditTriggers(QAbstractItemView::DoubleClicked);  //ʹ��ɱ༭

    currentModelDoubleClickedFlag = true;
}

void serveWindow::on_svSubButton_clicked()
{
    //�ύ����
    currentTableModel->submitAll();

    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    currentModelDoubleClickedFlag = false;
}

void serveWindow::on_svSelButton_clicked()
{
    //ˢ������
    currentIndexNum = ui->tabWidget->currentIndex();

    sqlName = sqlNames.at(currentIndexNum);
    currentView = tabViews.at(currentIndexNum);

    currentTableModel->setTable(sqlName);

    currentTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    if (2 == currentIndexNum)
    {
        currentTableModel->setFilter("deskno = '" + ui->svTabNumEdit->text() + "'");
    }
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    currentModelDoubleClickedFlag = false;
}

void serveWindow::on_svPwdButton_clicked()
{
    //�޸�����
    QString name;
    QString sPwd;
    QString tPwd1;
    QString tPwd2;
    QString sql;
    QSqlQuery query;

    name = ui->svNameEdit->text().trimmed();
    sPwd = ui->svPwd1Edit->text().trimmed();
    tPwd1 = ui->svPwd2Edit->text().trimmed();
    tPwd2 = ui->svPwd3Edit->text().trimmed();

    sql = "select * from person where pname = '" + name
          + "' and passwd = '"+ sPwd + "' and role = 1";

    query.exec(sql);
    qDebug() << sql;
    if (query.next())
    {
        if (tPwd1 == tPwd2)
        {
            sql = "update person set passwd = '" + tPwd1 + "' where pname = '" + name + "' and role = 1";
            query.exec(sql);
            QMessageBox::warning(this,tr("Success"),tr("successfully Modify!"), QMessageBox::Yes);

            ui->svNameEdit->clear();
            ui->svPwd1Edit->clear();
            ui->svPwd2Edit->clear();
            ui->svPwd3Edit->clear();
            ui->svNameEdit->setFocus();
        }
        else
        {
            QMessageBox::warning(this,tr("Warning"),tr("Second password is not suit the first!"), QMessageBox::Yes);

            ui->svNameEdit->clear();
            ui->svPwd1Edit->clear();
            ui->svPwd2Edit->clear();
            ui->svPwd3Edit->clear();
            ui->svNameEdit->setFocus();
        }
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"), QMessageBox::Yes);

        ui->svNameEdit->clear();
        ui->svPwd1Edit->clear();
        ui->svPwd2Edit->clear();
        ui->svPwd3Edit->clear();
        ui->svNameEdit->setFocus();
    }

}

void serveWindow::on_tabWidget_currentChanged(int index)
{
    //�л�ѡ�

    on_svSelButton_clicked();
}

void serveWindow::on_svPayButton_clicked()
{
    //���˲��붩�����ݿ�
    QString currentDate;
    currentDate = QDate::currentDate().toString("dd.MM.yyyy");
    QString currentTime;
    currentTime = QTime::currentTime().toString("hh:mm:ss");

    QString sql;
    QSqlQuery query;
    int tempLastOrderId;
    QString LastOrderId;

    for(int i=0; i<currentTableModel->columnCount(); i++)
    {
        sql = "select orderid from orderform";
        query.exec(sql);
        while(query.next())
        {
            tempLastOrderId = query.value(0).toInt();
        }
    }

    qDebug() << query.value(0);
    tempLastOrderId += 1;
    LastOrderId = QString::number(tempLastOrderId, 10);
    sql = "insert into orderform values ('"
            + LastOrderId + "', '" + currentDate +"', '"
            + currentTime + "', '" + ui->svTabNumEdit->text() + "', '"
            + deskNumMoneySum + "')";
    query.exec(sql);
}

void serveWindow::on_svDishesTabView_doubleClicked(const QModelIndex &index)
{
    //��˹���
    if (true == currentModelDoubleClickedFlag)
    {
        if (1 == index.column())
        {
            tempTableModel->setTable("desk");

            tempTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
            tempTableModel->select(); //ѡȡ�������������

            tempView->setModel(tempTableModel);
            tempView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

            currentModelDoubleClickedRow = index.row();
            currentModelDoubleClickedColumn = index.column();
            tempView->show();
        }
        if (2 == index.column())
        {
            tempTableModel->setTable("dish");

            tempTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
            tempTableModel->select(); //ѡȡ�������������

            tempView->setModel(tempTableModel);
            tempView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

            currentModelDoubleClickedRow = index.row();
            currentModelDoubleClickedColumn = index.column();
            tempView->show();
        }
    }
}

void serveWindow::addDeskDishesToDatabass(const QModelIndex &index)
{
    if (-1 == currentModelDoubleClickedColumn)
    {
        ui->svTabNumEdit->setText(tempTableModel->data(tempTableModel->index(index.row(), 0)).toString());
        tempView->hide();

        on_svSelButton_clicked();

        int tempMoneySum = 0;

        QString sql;
        QSqlQuery query;

        for(int i=0; i<currentTableModel->columnCount(); i++)
        {
            sql = "select dprice from dish where dname = '" + currentTableModel->data(currentTableModel->index(i, 2)).toString() + "'";
            query.exec(sql);
            while(query.next())
            {
                tempMoneySum += query.value(0).toInt();
            }
        }

        deskNumMoneySum = QString::number(tempMoneySum, 10);
        ui->svTabNumSumLab->setText("�ܼ� : " + deskNumMoneySum + " Ԫ");
    }
    if (1 == currentModelDoubleClickedColumn)
    {
        currentTableModel->setData(currentTableModel->index(currentModelDoubleClickedRow, currentModelDoubleClickedColumn), tempTableModel->data(tempTableModel->index(index.row(), 0)));
        tempView->hide();
    }
    if (2 == currentModelDoubleClickedColumn)
    {
        currentTableModel->setData(currentTableModel->index(currentModelDoubleClickedRow, currentModelDoubleClickedColumn), tempTableModel->data(tempTableModel->index(index.row(), 1)));
        tempView->hide();
    }
}

void serveWindow::on_svTabNumEdit_selectionChanged()
{
    tempTableModel->setTable("desk");
    tempTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    tempTableModel->select(); //ѡȡ�������������
    tempView->setModel(tempTableModel);
    tempView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭
    currentModelDoubleClickedColumn = -1;
    tempView->show();
}
