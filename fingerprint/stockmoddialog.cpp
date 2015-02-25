#include "stockmoddialog.h"
#include "ui_stockmoddialog.h"

stockModDialog::stockModDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stockModDialog)
{
    ui->setupUi(this);

    QDesktopWidget* desktop = QApplication::desktop();
    this->move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);
    this->setWindowTitle("�޸Ŀ�����");

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    qFinger = new qFingerprint(this);
    connect(qFinger, SIGNAL(OnImageReceived()), this, SLOT(finishImageReceived()));
    connect(qFinger, SIGNAL(OnFeatureInfo(int)), this, SLOT(finishFeatureInfo(int)));
    connect(qFinger, SIGNAL(OnCapture(QVariant)), this, SLOT(finishCapture(QVariant)));

    init();
}

stockModDialog::~stockModDialog()
{
    delete ui;
}

void stockModDialog::showEvent(QShowEvent *)
{
    init();
    on_pushButton_clicked();
}

void stockModDialog::paintEvent(QPaintEvent *)
{}

void stockModDialog::closeEvent(QCloseEvent *)
{
    qFinger->EndEngine();
    emit OnClose();
}

void stockModDialog::init()
{
    //��ʼ��
    /*
    //��������¼��(���, ��Ʒ���, ��Ʒ����, ����, �ɹ�, ����, ����)
    query.exec("create table stockslog(stockslogid INT PRIMARY KEY, goodsid INT, num INT, createdate VARCHAR, buyerid INT, keeperid INT, leaderid INT)");
    //��������(���, ��Ʒ���, ��Ʒ����, �������)
    query.exec("create table stocks(stocksid INT PRIMARY KEY, goodsid INT, num INT, borrownum INT)");
    */

    initGoods();

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

    ui->pushButton_2->setEnabled(false);

    ui->lineEdit_6->clear();
    ui->lineEdit_6->setEnabled(false);
    QRegExp regExp("^[0-9]+$");
    QRegExpValidator *pRevalidotor = new QRegExpValidator(regExp, 0);
    ui->lineEdit_6->setValidator(pRevalidotor);

    keeperid = 0;
    leaderid = 0;
}

void stockModDialog::initGoods()
{
    //��ʼ����Ʒ��
    currentTableModel->setTable("goods");
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

void stockModDialog::finishImageReceived()
{
    //ָ��ͼ�����
    qFinger->SaveBitmap();
    ui->label_2->setPixmap(QPixmap(fingerBmpPath));
}

void stockModDialog::finishFeatureInfo(int Aquality)
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

void stockModDialog::finishCapture(QVariant ATemplate)
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

void stockModDialog::findFingerUser(int mUserid)
{
    //������Ա��Ϣ
    QSqlQuery query;
    QString sql;
    QString name;
    int idNum = 0;
    int role = -1;

    sql = "select * from users where usersid = '" + QString::number(mUserid, 10) + "'";;
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
        break;
    case BUYER_ROLE:
        break;
    case KEEPER_ROLE:
        keeperid = idNum;
        ui->checkBox_1->setText(name);
        ui->checkBox_1->setChecked(true);
        break;
    case LEADER_ROLE:
        leaderid = idNum;
        ui->checkBox_2->setText(name);
        ui->checkBox_2->setChecked(true);
        break;
    default:
        break;
    }

    roleCheckboxStatus();
}

void stockModDialog::roleCheckboxStatus()
{
    //���Ȩ��
    if((ui->checkBox_1->checkState())
            &&(ui->checkBox_2->checkState()))
    {
        ui->lineEdit_6->clear();
        ui->lineEdit_6->setEnabled(true);

        ui->pushButton_2->setEnabled(true);
    }
}

void stockModDialog::on_pushButton_clicked()
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

void stockModDialog::on_lineEdit_2_textChanged(const QString &arg1)
{
    //������Ʒ
    currentTableModel->setFilter("gname like '%" + arg1 + "%'");
}

void stockModDialog::on_tableView_clicked(const QModelIndex &index)
{
    //��Ʒ������
    int curRow = index.row(); //��ȡѡ�е���
    QString gname = currentTableModel->index(curRow, 0).data().toString();
    ui->lineEdit_3->setText(gname);

    QSqlQuery query;
    QString sql;
    QString goodsid = "0";
    QString num = "0";
    QString borrownum = "0";

    sql = "select goodsid from goods where gname = '" + gname + "'";
    query.exec(sql);
    while(query.next())
    {
        goodsid = query.value(0).toString();
    }

    sql = "select * from stocks where goodsid = '" + goodsid + "'";
    query.exec(sql);
    while(query.next())
    {
        num = query.value(2).toString();
        borrownum = query.value(3).toString();
    }

    ui->lineEdit_4->setText(num);
    ui->lineEdit_5->setText(borrownum);
}

void stockModDialog::on_pushButton_2_clicked()
{
    //�޸�
    if(keeperid == 0)
    {
        QMessageBox::information(NULL, "error.", "�޷���¼����,������ˢ�뱣��ָ��!");
        return;
    }
    if(leaderid == 0)
    {
        QMessageBox::information(NULL, "error.", "�޷���¼����,������ˢ������ָ��!");
        return;
    }

    int num = ui->lineEdit_4->text().toInt();
    int borrownum = ui->lineEdit_5->text().toInt();
    int modnum = ui->lineEdit_6->text().toInt();

    if(modnum == 0)
    {
        QMessageBox::information(NULL, "error.", "û����д���ٸ���!");
        return;
    }

    if((num-modnum) < borrownum)
    {
        QMessageBox::information(NULL, "error.", "����������С�ڽ������!");
        return;
    }

    QSqlQuery query;
    QString sql;
    int idNum = 0;
    QString goodsid = "0";
    QString gname =  ui->lineEdit_3->text().trimmed();

    // ����goodsid
    sql = "select goodsid from goods where gname = '" + gname + "'";
    query.exec(sql);
    while(query.next())
    {
        goodsid = query.value(0).toString();
    }

    //����stockslog
    sql = "select stockslogid from stockslog";
    query.exec(sql);
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }
    idNum++;

    sql = "insert into stockslog values('" + QString::number(idNum, 10)
            + "', '" + goodsid
            + "', '-" + QString::number(modnum, 10)
            + "', '" + QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss")
            + "', '" + QString::number(0, 10)
            + "', '" + QString::number(keeperid, 10)
            + "', '" + QString::number(leaderid, 10)
            + "')";
    query.exec(sql);

    //����stocks
    sql = "update stocks set num = '" + QString::number((num-modnum), 10)
            + "' where goodsid = '" + goodsid + "'";
    query.exec(sql);

    ui->lineEdit_4->setText(QString::number((num-modnum), 10));
    ui->lineEdit_6->clear();
}
