#include "adminwindow.h"
#include "ui_adminwindow.h"

adminWindow::adminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminWindow)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);

    tabViews.append(ui->adDishesTabView);
    tabViews.append(ui->adPeopleTabView);
    tabViews.append(ui->adOrderTabView);
    tabViews.append(ui->adDayTabView);
    tabViews.append(ui->adMonthTabView);
    tabViews.append(ui->adDateTabView);

    sqlNames.append("dish");
    sqlNames.append("person");
    sqlNames.append("orderform");
    sqlNames.append("orderform");
    sqlNames.append("orderform");
    sqlNames.append("orderform");

    on_adSelButton_clicked();
}

adminWindow::~adminWindow()
{
    delete ui;
}
void adminWindow::on_adDishesAction_triggered()
{
    //��Ʒ����
    ui->tabWidget->setCurrentIndex(0);   //�����ת���˵�����ѡ�
    on_adSelButton_clicked();
}

void adminWindow::on_adPeopleAction_triggered()
{
    //��Ա����
    ui->tabWidget->setCurrentIndex(1);   //�����ת����Ա����ѡ�
    on_adSelButton_clicked();
}

void adminWindow::on_adOrderAction_triggered()
{
    //��������
    ui->tabWidget->setCurrentIndex(2);   //�����ת����������ѡ�
    on_adSelButton_clicked();
}

void adminWindow::on_adDayAction_triggered()
{
    //����Ӫҵ��
    ui->tabWidget->setCurrentIndex(3);   //�����ת������Ӫҵ�����ѡ�
    on_adSelButton_clicked();
}

void adminWindow::on_adMonthAction_triggered()
{
    //����Ӫҵ��
    ui->tabWidget->setCurrentIndex(4);   //�����ת������Ӫҵ�����ѡ�
    on_adSelButton_clicked();
}

void adminWindow::on_adDateAction_triggered()
{
    //������ͳ��
    ui->tabWidget->setCurrentIndex(5);   //�����ת��������ͳ�ƹ���ѡ�
    on_adSelButton_clicked();
}

void adminWindow::on_adPwdAction_triggered()
{
    //�޸�����
}

void adminWindow::on_adCancelAction_triggered()
{
    //�˳�
    this->close();
}

void adminWindow::on_adAddButton_clicked()
{
    //�������
    int rowNum = currentTableModel->rowCount(); //��ñ������
    int id = currentTableModel->record(rowNum - 1).value(0).toInt() + 1;

    currentView->setEditTriggers(QAbstractItemView::AllEditTriggers);  //ʹ��ɱ༭
    currentTableModel->insertRow(rowNum); //���һ��
    currentTableModel->setData(currentTableModel->index(rowNum, 0), id);
}

void adminWindow::on_adDelButton_clicked()
{
    //ɾ������
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������
}

void adminWindow::on_adChButton_clicked()
{
    //�޸�����
    currentView->setEditTriggers(QAbstractItemView::DoubleClicked);  //ʹ��ɱ༭
}

void adminWindow::on_adSubButton_clicked()
{
    //�ύ����
    currentTableModel->submitAll();

    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭
}

void adminWindow::on_adSelButton_clicked()
{
    //ˢ������
    currentIndexNum = ui->tabWidget->currentIndex();

    sqlName = sqlNames.at(currentIndexNum);
    currentView = tabViews.at(currentIndexNum);

    currentTableModel->setTable(sqlName);

    qDebug() << sqlName << endl;

    currentTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    QString currentDate;
    if (3 == currentIndexNum)
    {
        currentDate = QDate::currentDate().toString("dd.MM.yyyy");

        currentTableModel->setFilter("date = '" + currentDate + "'");

        int tempMoneySum = 0;
        QString sql;
        QSqlQuery query;

        sql = "select income from orderform where date = '" + currentDate + "'";
        query.exec(sql);

        while(query.next())
        {
            tempMoneySum += query.value(0).toInt();
        }

        sql = QString::number(tempMoneySum, 10);
        ui->adDaySumLab->setText("�ܼ� : " + sql + " Ԫ");
    }
    else if (4 == currentIndexNum)
    {
        currentDate = QDate::currentDate().toString("MM.yyyy");

        currentTableModel->setFilter("date like '%" + currentDate + "'");

        int tempMoneySum = 0;
        QString sql;
        QSqlQuery query;

        sql = "select income from orderform where date like '%" + currentDate + "'";
        query.exec(sql);
        while(query.next())
        {
            tempMoneySum += query.value(0).toInt();
        }

        sql = QString::number(tempMoneySum, 10);
        ui->adMonthSumLab->setText("�ܼ� : " + sql + " Ԫ");
    }
    else if (5 == currentIndexNum)
    {
        int tempMoneySum = 0;
        QString sql;
        QSqlQuery query;

        sql = "select income from orderform";
        query.exec(sql);
        while(query.next())
        {
            tempMoneySum += query.value(0).toInt();
        }

        sql = QString::number(tempMoneySum, 10);
        ui->adDateSumLab->setText("�ܼ� : " + sql + " Ԫ");
    }
    else
    {
        qDebug() << "test" << endl;
    }
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭
}

void adminWindow::on_adPwdButton_clicked()
{
    //�޸�����
    QString name;
    QString sPwd;
    QString tPwd1;
    QString tPwd2;
    QString sql;
    QSqlQuery query;

    name = ui->adNameEdit->text().trimmed();
    sPwd = ui->adPwd1Edit->text().trimmed();
    tPwd1 = ui->adPwd2Edit->text().trimmed();
    tPwd2 = ui->adPwd3Edit->text().trimmed();

    sql = "select * from person where pname = '" + name
          + "' and passwd = '"+ sPwd + "' and role = 0";

    query.exec(sql);
    if (query.next())
    {
        if (tPwd1 == tPwd2)
        {
            sql = "update person set passwd = '" + tPwd1 + "' where pname = '" + name + "' and role = 0";
            query.exec(sql);
            QMessageBox::warning(this,tr("Success"),tr("successfully Modify!"), QMessageBox::Yes);

            ui->adNameEdit->clear();
            ui->adPwd1Edit->clear();
            ui->adPwd2Edit->clear();
            ui->adPwd3Edit->clear();
            ui->adNameEdit->setFocus();
        }
        else
        {
            QMessageBox::warning(this,tr("Warning"),tr("Second password is not suit the first!"), QMessageBox::Yes);

            ui->adNameEdit->clear();
            ui->adPwd1Edit->clear();
            ui->adPwd2Edit->clear();
            ui->adPwd3Edit->clear();
            ui->adNameEdit->setFocus();
        }
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"), QMessageBox::Yes);

        ui->adNameEdit->clear();
        ui->adPwd1Edit->clear();
        ui->adPwd2Edit->clear();
        ui->adPwd3Edit->clear();
        ui->adNameEdit->setFocus();
    }
}

void adminWindow::on_tabWidget_currentChanged(int index)
{
    //�л�ѡ�
    on_adSelButton_clicked();
}
