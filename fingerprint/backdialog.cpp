#include "backdialog.h"
#include "ui_backdialog.h"

backDialog::backDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::backDialog)
{
    ui->setupUi(this);

    QDesktopWidget* desktop = QApplication::desktop();
    this->move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);
    this->setWindowTitle("�黹��Ʒ����");

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    qFinger = new qFingerprint(this);
    connect(qFinger, SIGNAL(OnImageReceived()), this, SLOT(finishImageReceived()));
    connect(qFinger, SIGNAL(OnFeatureInfo(int)), this, SLOT(finishFeatureInfo(int)));
    connect(qFinger, SIGNAL(OnCapture(QVariant)), this, SLOT(finishCapture(QVariant)));

    init();
}

backDialog::~backDialog()
{
    delete ui;
}

void backDialog::showEvent(QShowEvent *)
{
    init();
    on_pushButton_clicked();
}

void backDialog::paintEvent(QPaintEvent *)
{}

void backDialog::closeEvent(QCloseEvent *)
{
    qFinger->EndEngine();
    emit OnClose();
}

void backDialog::on_pushButton_clicked()
{
    //����ָ����
    int result = -1;
    QString strSN = "ָ������δ����!";
    result = qFinger->InitEngine();

    if(result == 0)
    {
        strSN = qFinger->SensorSN();
    }
    else
    {
        qFinger->EndEngine();
        QMessageBox::information(NULL, "error.", "��ʼ��ָ����ʧ��!");
    }
    ui->lineEdit->setText(QString(strSN));
}

void backDialog::on_lineEdit_2_textChanged(const QString &arg1)
{
    //������Ʒ
    currentTableModel->setFilter("gname like '%" + arg1 + "%'");
}

void backDialog::on_tableView_clicked(const QModelIndex &index)
{
    //��Ʒ������
    int curRow = index.row(); //��ȡѡ�е���
    QString gname = currentTableModel->index(curRow, 0).data().toString();
    ui->lineEdit_4->setText(gname);

    QSqlQuery query;
    QString sql;
    QString goodsid = "0";
    QString num = "0";

    sql = "select goodsid from goods where gname = '" + gname + "'";
    query.exec(sql);
    while(query.next())
    {
        goodsid = query.value(0).toString();
    }

    sql = "select num from usergoods where userid = '" + QString::number(userid, 10)
            + "' and goodsid = '" + goodsid
            + "'";
    query.exec(sql);
    while(query.next())
    {
        num = query.value(0).toString();
    }

    ui->lineEdit_6->setText(gname);
    ui->lineEdit_7->setText(num);
}

void backDialog::on_tableWidget_clicked(const QModelIndex &index)
{
    //�黹������
    int curRow = index.row(); //��ȡѡ�е���
    QString gname = ui->tableWidget->item(curRow, 0)->text().trimmed();
    QString num = ui->tableWidget->item(curRow, 1)->text().trimmed();
    ui->lineEdit_3->setText(QString::number(curRow, 10));
    ui->lineEdit_4->setText(gname);
    ui->lineEdit_5->setText(num);

    QSqlQuery query;
    QString sql;
    QString goodsid = "0";
    QString borrowNum = "0";

    sql = "select goodsid from goods where gname = '" + gname + "'";
    query.exec(sql);
    while(query.next())
    {
        goodsid = query.value(0).toString();
    }

    sql = "select num from usergoods where userid = '" + QString::number(userid, 10)
            + "' and goodsid = '" + goodsid
            + "'";
    query.exec(sql);
    while(query.next())
    {
        borrowNum = query.value(0).toString();
    }

    ui->lineEdit_6->setText(gname);
    ui->lineEdit_7->setText(borrowNum);
}

void backDialog::on_pushButton_2_clicked()
{
    //���
    int borrowNum = ui->lineEdit_7->text().toInt();
    QString name = ui->lineEdit_4->text().trimmed();
    QString num = ui->lineEdit_5->text().trimmed();

    if(name == "")
    {
        QMessageBox::information(NULL, "error.", "û����Ʒ����!");
        return;
    }

    if((num == "") || (num.toInt() == 0))
    {
        QMessageBox::information(NULL, "error.", "û����Ʒ����!");
        return;
    }

    int curRowCount = ui->tableWidget->rowCount();
    int beforeNum = 0;
    for(int i=0; i<curRowCount; i++)
    {
        if(ui->tableWidget->item(i, 0)->text().trimmed() == name)
        {
            beforeNum += ui->tableWidget->item(i, 1)->text().toInt();
        }
    }

    if(borrowNum < (beforeNum + num.toInt()))
    {
        QMessageBox::information(NULL, "error.", "�黹̫��,�޷��黹!");
        return;
    }

    QTableWidgetItem *nameItem = new QTableWidgetItem(QTableWidgetItem::Type);
    nameItem->setText(name);
    QTableWidgetItem *numItem = new QTableWidgetItem(QTableWidgetItem::Type);
    numItem->setText(num);

    int currentRow = ui->tableWidget->rowCount();

    ui->tableWidget->insertRow(currentRow);
    ui->tableWidget->setItem(currentRow, 0, nameItem);
    ui->tableWidget->setItem(currentRow, 1, numItem);

    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
}

void backDialog::on_pushButton_3_clicked()
{
    //�޸�
    int borrowNum = ui->lineEdit_7->text().toInt();
    QString name = ui->lineEdit_4->text().trimmed();
    QString num = ui->lineEdit_5->text().trimmed();

    if(name == "")
    {
        QMessageBox::information(NULL, "error.", "û����Ʒ����!");
        return;
    }

    if(num == "")
    {
        QMessageBox::information(NULL, "error.", "û����Ʒ����,����ɾ��,����д 0!");
        return;
    }

    int curRowCount = ui->tableWidget->rowCount();
    int beforeNum = 0;
    for(int i=0; i<curRowCount; i++)
    {
        if(i == ui->lineEdit_3->text().toInt())
        {
            continue;
        }

        if(ui->tableWidget->item(i, 0)->text().trimmed() == name)
        {
            beforeNum += ui->tableWidget->item(i, 1)->text().toInt();
        }
    }

    if(borrowNum < (beforeNum + num.toInt()))
    {
        QMessageBox::information(NULL, "error.", "�黹̫��,�޷��黹!");
        return;
    }

    QTableWidgetItem *nameItem = new QTableWidgetItem(QTableWidgetItem::Type);
    nameItem->setText(name);
    QTableWidgetItem *numItem = new QTableWidgetItem(QTableWidgetItem::Type);
    numItem->setText(num);

    QString currentRowStr = ui->lineEdit_3->text().trimmed();
    int currentRow = currentRowStr.toInt();

    if(currentRowStr == "")
    {
        QMessageBox::information(NULL, "error.", "û��ѡ������Ҫ�޸ĵļ�¼!");
        return;
    }

    if(num.toInt() == 0)
    {

        ui->tableWidget->removeRow(currentRow);
    }
    else
    {
        ui->tableWidget->setItem(currentRow, 0, nameItem);
        ui->tableWidget->setItem(currentRow, 1, numItem);
    }

    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
}

void backDialog::on_pushButton_4_clicked()
{
    //�ύ
    if(keeperid == 0)
    {
        QMessageBox::information(NULL, "error.", "�޷���¼����,������ˢ�뱣��ָ��!");
        return;
    }
    if(userid == 0)
    {
        QMessageBox::information(NULL, "error.", "�޷���¼Ա��,������ˢ��Ա��ָ��!");
        return;
    }

    QSqlQuery query;
    QString sql;
    int curRow = 0;
    int idNum = 0;
    QString goodsid = "0";
    int stockBorrowNum = 0;
    int curBorrowNum = 0;
    QString num = "0";
    QString gname = "";

    while(ui->tableWidget->rowCount())
    {
        curRow = 0;
        idNum = 0;
        goodsid = "0";
        stockBorrowNum = 0;
        curBorrowNum = 0;
        num = "0";
        gname = "";

        curRow = ui->tableWidget->rowCount() - 1;
        gname = ui->tableWidget->item(curRow, 0)->text().trimmed();
        num = ui->tableWidget->item(curRow, 1)->text().trimmed();

        // ����goodsid
        sql = "select goodsid from goods where gname = '" + gname + "'";
        query.exec(sql);
        while(query.next())
        {
            goodsid = query.value(0).toString();
        }

        //����borrowlog
        sql = "select borrowlogid from borrowlog";
        query.exec(sql);
        while(query.next())
        {
            if(idNum < query.value(0).toInt())
                idNum = query.value(0).toInt();
        }
        idNum++;

        sql = "insert into borrowlog values('" + QString::number(idNum, 10)
                + "', '" + goodsid
                + "', '" + num
                + "', '" + QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss")
                + "', '" + QString::number(keeperid, 10)
                + "', '" + QString::number(userid, 10)
                + "', '" + QString::number(BACK_FALG, 10)
                + "')";
        query.exec(sql);

        //����stocks
        sql = "select * from stocks where goodsid = '" + goodsid + "'";
        query.exec(sql);
        while(query.next())
        {
            stockBorrowNum = query.value(3).toInt() - num.toInt();
        }
        sql = "update stocks set borrownum = '" + QString::number(stockBorrowNum, 10)
                + "' where goodsid = '" + goodsid + "'";
        query.exec(sql);

        //����usergoods
        sql = "select * from usergoods where goodsid = '" + goodsid
                + "' and userid = '" + QString::number(userid, 10)
                + "'";
        query.exec(sql);
        while(query.next())
        {
            curBorrowNum = query.value(2).toInt();
        }

        curBorrowNum = curBorrowNum - num.toInt();
        if(curBorrowNum == 0)
        {
            sql = "delete from usergoods where goodsid = '" + goodsid
                    + "' and userid = '" + QString::number(userid, 10)
                    + "'";
            query.exec(sql);
        }
        else
        {
            sql = "update usergoods set num = '" + QString::number(curBorrowNum, 10)
                    + "' where goodsid = '" + goodsid
                    + "' and userid = '" + QString::number(userid, 10)
                    + "'";
            query.exec(sql);
        }

        ui->tableWidget->removeRow(curRow);
    }

    ui->checkBox_2->setText("���ڶԱ� ...");
    ui->checkBox_2->setChecked(false);
    ui->lineEdit_5->clear();
    ui->lineEdit_5->setEnabled(false);

    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);

    ui->lineEdit_6->clear();
    ui->lineEdit_6->setEnabled(false);
    ui->lineEdit_7->clear();
    ui->lineEdit_7->setEnabled(false);

    userid = 0;

    delBorrowGoods();
    initGoods();
}

void backDialog::init()
{
    //��ʼ��
    /*
    //��������(���, ��Ʒ���, ��Ʒ����, �������)
    query.exec("create table stocks(stocksid INT PRIMARY KEY, goodsid INT, num INT, borrownum INT)");

    //������ȡ��¼��(���, ��Ʒ���, ��Ʒ����, ����, ����, ��ȡ��, �軹��־)
    query.exec("create table borrowlog(borrowlogid INT PRIMARY KEY, goodsid INT, num INT, createdate VARCHAR, keeperid INT, userid INT, borrowflag INT)");
    //������ȡ��Ա��(���, ��Ʒ���, ��Ʒ����, ��ȡ��)
    query.exec("create table usergoods(usergoodsid INT PRIMARY KEY, goodsid INT, num INT, userid INT)");
    //������ȡ��Ա��Ʒ��ʱ��(���, ��Ʒ���, ��Ʒ����)
    query.exec("create table usergoodstemp(usergoodstempid INT PRIMARY KEY, goodsid INT, gname INT)");
    */

    delBorrowGoods();
    initGoods();

    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnCount(2);
    int tableWidth = (ui->tableWidget->width() - 20 - 20) / 2;
    ui->tableWidget->setColumnWidth(0, tableWidth);
    ui->tableWidget->setColumnWidth(1, tableWidth);
    QStringList header;
    header.append("��Ʒ����");
    header.append("�黹����");
    ui->tableWidget->setHorizontalHeaderLabels(header);

    ui->lineEdit->setEnabled(false);
    ui->label_2->clear();
    ui->label_2->setScaledContents(true);
    ui->label_3->clear();
    ui->label_3->setText("ָ������ : ");

    ui->checkBox_1->setText("���ڶԱ� ...");
    ui->checkBox_1->setChecked(false);
    ui->checkBox_1->setEnabled(false);
    ui->checkBox_2->setText("���ڶԱ� ...");
    ui->checkBox_2->setChecked(false);
    ui->checkBox_2->setEnabled(false);

    ui->lineEdit_2->clear();
    ui->lineEdit_2->setEnabled(true);
    ui->lineEdit_3->clear();
    ui->lineEdit_3->setEnabled(false);
    ui->lineEdit_4->clear();
    ui->lineEdit_4->setEnabled(false);
    ui->lineEdit_5->clear();
    ui->lineEdit_5->setEnabled(false);
    QRegExp regExp("^[0-9]+$");
    QRegExpValidator *pRevalidotor = new QRegExpValidator(regExp, 0);
    ui->lineEdit_5->setValidator(pRevalidotor);

    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);

    ui->lineEdit_6->clear();
    ui->lineEdit_6->setEnabled(false);
    ui->lineEdit_7->clear();
    ui->lineEdit_7->setEnabled(false);

    keeperid = 0;
    userid = 0;
}

void backDialog::initGoods()
{
    //��ʼ����Ʒ��
    currentTableModel->setTable("usergoodstemp");
    currentTableModel->select();

    currentTableModel->removeColumn(0);
    currentTableModel->setHeaderData(0, Qt::Horizontal, QString("����"));

    currentView->setModel(currentTableModel);
    currentView->setColumnWidth(0, currentView->width());
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QHeaderView* headerView = currentView->verticalHeader();
    headerView->setHidden(true);

    ui->lineEdit_2->clear();
}

void backDialog::finishImageReceived()
{
    //ָ��ͼ�����
    qFinger->SaveBitmap();
    ui->label_2->setPixmap(QPixmap(fingerBmpPath));
}

void backDialog::finishFeatureInfo(int Aquality)
{
    //ָ����������
    switch(Aquality)
    {
    case 0:
        ui->label_3->setText("ָ������ : �ϸ�");
        break;
    case 1:
        ui->label_3->setText("ָ������ : �����㲻��");
        break;
    case 2:
        ui->label_3->setText("ָ������ : �޷�ȡ��ָ������");
        break;
    default:
        ui->label_3->setText("ָ������ : ");
        break;
    }
}

void backDialog::finishCapture(QVariant ATemplate)
{
    //ָ�ƶԱ�
    QMapIterator<int, QVariant> i(fingerTemplateMap);
    while (i.hasNext())
    {
        i.next();
        if(qFinger->VerFinger(ATemplate, i.value()))
        {
            findFingerUser(i.key());
        }
    }
}

void backDialog::findFingerUser(int mUserid)
{
    //������Ա��Ϣ
    QSqlQuery query;
    QString sql;
    QString name;
    int idNum = 0;
    int role = -1;

    sql = "select * from users where usersid = '" + QString::number(mUserid, 10) + "'";
    query.exec(sql);

    while(query.next())
    {
        idNum = query.value(0).toInt();
        name = query.value(1).toString();
        role = query.value(3).toInt();
    }

    switch(role)
    {
    case STAFF_ROLE:
        userid = idNum;
        ui->checkBox_2->setText(name);
        ui->checkBox_2->setChecked(true);
        delBorrowGoods();
        getBorrowGoods();
        break;
    case BUYER_ROLE:
        break;
    case KEEPER_ROLE:
        keeperid = idNum;
        ui->checkBox_1->setText(name);
        ui->checkBox_1->setChecked(true);
        break;
    case LEADER_ROLE:
        break;
    default:
        break;
    }

    roleCheckboxStatus();
}

void backDialog::roleCheckboxStatus()
{
    //���Ȩ��
    if((ui->checkBox_1->checkState())
            &&(ui->checkBox_2->checkState()))
    {
        ui->lineEdit_5->clear();
        ui->lineEdit_5->setEnabled(true);

        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
    }
}

void backDialog::getBorrowGoods()
{
    //���ҽ������Ʒ
    QSqlQuery query;
    QString sql;
    QList<QString> goodsid;
    QList<QString> gname;

    sql = "select goodsid from usergoods where userid = '" + QString::number(userid, 10) + "'";
    query.exec(sql);
    while(query.next())
    {
        goodsid << query.value(0).toString();
    }

    for(int i=0; i<goodsid.count(); i++)
    {
        sql = "select gname from goods where goodsid = '" + goodsid[i] + "'";
        query.exec(sql);
        while(query.next())
        {
            gname << query.value(0).toString();
        }
    }

    for(int i=0; i<goodsid.count(); i++)
    {
        sql = "insert into usergoodstemp values('" + QString::number(i, 10)
                + "', '" + goodsid[i]
                + "', '" + gname[i]
                + "')";
        query.exec(sql);
    }

    initGoods();
}

void backDialog::delBorrowGoods()
{
    //ɾ����ʱ��Ʒ��
    QSqlQuery query;
    QString sql;

    sql = "delete from usergoodstemp";
    query.exec(sql);
}
