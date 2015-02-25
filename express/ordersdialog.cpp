#include "ordersdialog.h"
#include "ui_ordersdialog.h"

/*
���������Ѿ������׼����л��ѡ�񰮲���Ϊ���ṩ�Ŀ�ݲ�ѯ�ӿڣ�API������

���Ƿ������ʹ�õ����Key�ܳ�Ϊ��9BD58D8642F528E792E4BF8EAA845AC8

ÿ�յ�������Ϊ��1000��

��ע���ṩ������KEYֻ�����͹�˾ר�ã����𹫿����⴫�����߽�ȡ������APIʹ���ʸ�

ʹ�������ṩ�Ŀ�ݲ�ѯAPI�ӿڼ�����ͬ�Ⱞ�������İ�Ȩ���������

���÷����ͽӿ���ο�������վ���ṩ����ϸ˵����

-----------------------------------------

1�������κ������뼰ʱ���������硣

2��������ҳ���¶˼��ϡ���ѯ�����ɰ������ṩ�����������ӵ�ַ��http://www.ickd.cn����

3����������վ���������Ӵ��������ǵ����ӣ�����δ�������˽�������ӵ����ǽ�ȡ������API�ʸ����ǻᶨ�ڼ�����ӵ��������

������ӣ���ݲ�ѯAPI˵����http://www.ickd.cn/api/doc.html������֧�ֵĿ�ݹ�˾�б�http://www.ickd.cn/api/list.php����ShopEx��EcShop����ϵͳ�����http://www.ickd.cn/api/plugins.html��

------------------------------------------------------

API���òο���

http://api.ickd.cn/?id=9BD58D8642F528E792E4BF8EAA845AC8&com=��ݹ�˾Ӣ�Ĵ���&nu=��ݵ���&type=html|text|json�����������˵���ĵ���

http://api.ickd.cn/?com=[]&nu=[]&id=[]&type=[]&encode=[]&ord=[]&lang=[]

*/

ordersDialog::ordersDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ordersDialog)
{
    ui->setupUi(this);

    networkAccessManager = new QNetworkAccessManager(this);
    connect(networkAccessManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(Finish(QNetworkReply *)));

    model = new QStandardItemModel;
    model->setColumnCount(3);
    model->setHeaderData(0,Qt::Horizontal,"����");
    model->setHeaderData(1,Qt::Horizontal,"�ص�");
    model->setHeaderData(2,Qt::Horizontal,"״̬");
    ui->tableView->setShowGrid(true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->setResizeMode(QHeaderView::Stretch);


    initComboBox();

    ui->lineEdit->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
}

ordersDialog::~ordersDialog()
{
    delete ui;
}

void ordersDialog::showEvent(QShowEvent *)
{
    initComboBox();

    ui->lineEdit->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
}

void ordersDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/jpg/3.jpg").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void ordersDialog::on_pushButton_clicked()
{
    //��ѯ
    if(ui->lineEdit->text().length() == 0)
    {
        QMessageBox::information(NULL, "error", "express num is empty");
        return;
    }

    QString expressCodes;
    QSqlQuery query;
    query.exec("select codes from expresscom where expresscomid = '" + QString::number(ui->comboBox->currentIndex(), 10) + "'");
    while(query.next())
        expressCodes = query.value(0).toString();

    QString html = QString("http://api.ickd.cn/?id=9BD58D8642F528E792E4BF8EAA845AC8&com=" + expressCodes + "&nu=" + ui->lineEdit->text().trimmed() + "&type=text");

    qDebug() << html << endl;
    networkAccessManager->get(QNetworkRequest(QUrl(html)));
}

void ordersDialog::on_pushButton_3_clicked()
{
    //����
    QSqlQuery query;
    int idNum = 0;

    query.exec("select ordersid from orders");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    query.exec("insert into orders values('" + QString::number(idNum, 10) + "', '"
               + ui->lineEdit->text().trimmed() + "', '"
               + QString::number(ui->comboBox->currentIndex(), 10) + "')");

    ui->lineEdit->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);

    initComboBox();
}

void ordersDialog::on_pushButton_2_clicked()
{
    //��ѯ
    if(ui->comboBox_2->currentIndex() == 0)
    {
        QMessageBox::information(NULL, "error", "express num is empty");
        return;
    }

    QString expressCodes;
    QSqlQuery query;
    query.exec("select codes from expresscom where expresscomid = '" + QString::number(ui->comboBox->currentIndex(), 10) + "'");
    while(query.next())
        expressCodes = query.value(0).toString();

    QString html = QString("http://api.ickd.cn/?id=9BD58D8642F528E792E4BF8EAA845AC8&com=" + expressCodes + "&nu=" + ui->comboBox_2->currentText() + "&type=text");

    qDebug() << html << endl;
    networkAccessManager->get(QNetworkRequest(QUrl(html)));
}

void ordersDialog::on_pushButton_4_clicked()
{
    //ɾ��
    QSqlQuery query;
    query.exec("delete from orders where ordernum = '" + ui->comboBox_2->currentText() + "'");

    initComboBox();
}


void ordersDialog::on_comboBox_2_currentIndexChanged(int index)
{
    //���е���ѡ��
    QSqlQuery query;

    query.exec("select express from orders where ordernum = '" + ui->comboBox_2->currentText() + "'");
    while(query.next())
    {
        ui->comboBox->setCurrentIndex(query.value(0).toInt());
    }
}

void ordersDialog::Finish(QNetworkReply *networkReply)
{
    //�������
    QTextCodec *codec=QTextCodec::codecForName("GBK");
    QString all=codec->toUnicode(networkReply->readAll());
    networkReply->deleteLater();

    model->clear();
    model->setColumnCount(3);
    model->setHeaderData(0,Qt::Horizontal,"����");
    model->setHeaderData(1,Qt::Horizontal,"�ص�");
    model->setHeaderData(2,Qt::Horizontal,"״̬");
    QStringList list=all.split("\n");
    foreach (QString temp, list) {
        QString time = temp.left(temp.indexOf("  "));
        temp = temp.mid(temp.indexOf("  ") + 2);
        QString place = temp.left(temp.indexOf(" "));
        temp = temp.mid(temp.indexOf(" ") + 1);
        QStandardItem *timeitem = new QStandardItem(time);
        QStandardItem *placeitem = new QStandardItem(place);
        QStandardItem *state = new QStandardItem(temp);
        QList<QStandardItem*> item;
        item << timeitem << placeitem << state;
        model->appendRow(item);
    }

    model->removeRow(model->rowCount()-1);

    qDebug() << all << model->rowCount() << endl;

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

void ordersDialog::initComboBox()
{
    //��ʼ��������
    QSqlQuery query;
    ui->comboBox->clear();
    ui->comboBox_2->clear();

    ui->comboBox_2->addItem("");

    query.exec("select name from expresscom");
    while(query.next())
        ui->comboBox->addItem(query.value(0).toString());

    query.exec("select ordernum from orders");
    while(query.next())
        ui->comboBox_2->addItem(query.value(0).toString());
}
