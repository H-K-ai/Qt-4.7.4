#include "goodsdialog.h"
#include "ui_goodsdialog.h"

goodsDialog::goodsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::goodsDialog)
{
    ui->setupUi(this);

    QDesktopWidget* desktop = QApplication::desktop();
    this->move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);
    this->setWindowTitle("��Ʒ��Ŀ����");

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    qFinger = new qFingerprint(this);
    connect(qFinger, SIGNAL(OnImageReceived()), this, SLOT(finishImageReceived()));
    connect(qFinger, SIGNAL(OnFeatureInfo(int)), this, SLOT(finishFeatureInfo(int)));
    connect(qFinger, SIGNAL(OnCapture(QVariant)), this, SLOT(finishCapture(QVariant)));

    init();
}

goodsDialog::~goodsDialog()
{
    delete ui;
}

void goodsDialog::showEvent(QShowEvent *)
{
    init();
    on_pushButton_clicked();
}

void goodsDialog::paintEvent(QPaintEvent *)
{}

void goodsDialog::closeEvent(QCloseEvent *)
{
    qFinger->EndEngine();
    emit OnClose();
}

void goodsDialog::on_pushButton_clicked()
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

void goodsDialog::on_pushButton_2_clicked()
{
    //���
    QSqlQuery query;
    QString sql;
    int idNum = 0;
    QString name = ui->lineEdit_4->text().trimmed();

    if(name == "")
    {
        QMessageBox::information(NULL, "error.", "û����Ʒ����!");
        return;
    }

    sql = "select * from goods where gname = '" + name + "'";
    query.exec(sql);
    while(query.next())
    {
        if(name == query.value(1).toString())
        {
            QMessageBox::information(NULL, "error.", "���и���Ʒ����!");
            return;
        }
    }

    sql = "select goodsid from goods";
    query.exec(sql);
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    sql = "insert into goods values('" + QString::number(idNum, 10) + "', '" + name + "')";
    query.exec(sql);

    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();

    currentTableModel->select();

    emit modGoods();
}

void goodsDialog::on_pushButton_3_clicked()
{
    //�޸�
    QSqlQuery query;
    QString sql;
    QString idNum = ui->lineEdit_3->text().trimmed();
    QString name = ui->lineEdit_4->text().trimmed();

    if(name == "")
    {
        QMessageBox::information(NULL, "error.", "û����Ʒ����!");
        return;
    }

    sql = "select * from goods where gname = '" + name + "'";
    query.exec(sql);
    while(query.next())
    {
        if(name == query.value(1).toString())
        {
            QMessageBox::information(NULL, "error.", "���и���Ʒ����!");
            return;
        }
    }

    sql = "update goods set gname = '" + name + "' where goodsid = '" + idNum + "'";
    query.exec(sql);

    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();

    currentTableModel->select();

    emit modGoods();
}

void goodsDialog::on_lineEdit_2_textChanged(const QString &arg1)
{
    //����
    currentTableModel->setFilter("gname like '%" + arg1 + "%'");
}

void goodsDialog::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    int curRow = index.row(); //��ȡѡ�е���

    ui->lineEdit_3->setText(currentTableModel->index(curRow, 0).data().toString());
    ui->lineEdit_4->setText(currentTableModel->index(curRow, 1).data().toString());
}

void goodsDialog::init()
{
    //��ʼ��
    currentTableModel->setTable("goods");
    currentTableModel->select();

    currentTableModel->setHeaderData(0, Qt::Horizontal, QString("���"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QString("����"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->lineEdit->setEnabled(false);
    ui->label_2->clear();
    ui->label_2->setScaledContents(true);
    ui->label_3->clear();
    ui->label_3->setText("ָ������ : ");

    ui->checkBox->setText("���ڶԱ� ...");
    ui->checkBox->setChecked(false);
    ui->checkBox->setEnabled(false);

    ui->lineEdit_3->clear();
    ui->lineEdit_3->setEnabled(false);
    ui->lineEdit_4->clear();
    ui->lineEdit_4->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
}

void goodsDialog::finishImageReceived()
{
    //ָ��ͼ�����
    qFinger->SaveBitmap();
    ui->label_2->setPixmap(QPixmap(fingerBmpPath));
}

void goodsDialog::finishFeatureInfo(int Aquality)
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
    ui->checkBox->setChecked(false);
    ui->lineEdit_4->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->checkBox->setText("���ڶԱ� ...");
}

void goodsDialog::finishCapture(QVariant ATemplate)
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

void goodsDialog::findFingerUser(int mUserid)
{
    //������Ա��Ϣ
    QSqlQuery query;
    QString sql;
    QString name;
    int role = -1;

    sql = "select * from users where usersid = '" + QString::number(mUserid, 10) + "'";
    query.exec(sql);

    while(query.next())
    {
        name = query.value(1).toString();
        role = query.value(3).toInt();
    }

    switch(role)
    {
    default:
    case STAFF_ROLE:
    case BUYER_ROLE:
    case KEEPER_ROLE:
        ui->checkBox->setChecked(false);
        ui->lineEdit_4->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        break;
    case LEADER_ROLE:
        ui->checkBox->setText(name);
        ui->checkBox->setChecked(true);
        ui->lineEdit_4->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        break;
    }
}
