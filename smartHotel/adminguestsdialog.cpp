#include "adminguestsdialog.h"
#include "ui_adminguestsdialog.h"

adminGuestsDialog::adminGuestsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminGuestsDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    currentTableModel->setTable("guests");
    currentTableModel->select();

    currentTableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("���"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("�û���"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("�Ա�"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("���֤��"));
    currentTableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("�ֻ���"));
    currentTableModel->setHeaderData(6, Qt::Horizontal, QObject::tr("��Ա"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->lineEdit->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit_5->clear();

    //�۸�������ʽ
    QRegExp regExp("^[0-9]+$");
    QRegExpValidator *pRevalidotor = new QRegExpValidator(regExp, 0);
    ui->lineEdit_2->setValidator(pRevalidotor);
    ui->lineEdit_3->setValidator(pRevalidotor);
    ui->lineEdit_4->setValidator(pRevalidotor);
}

adminGuestsDialog::~adminGuestsDialog()
{
    delete ui;
}

void adminGuestsDialog::showEvent(QShowEvent *)
{
    currentTableModel->setTable("guests");
    currentTableModel->select();

    currentTableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("���"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("�û���"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("�Ա�"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("���֤��"));
    currentTableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("�ֻ���"));
    currentTableModel->setHeaderData(6, Qt::Horizontal, QObject::tr("��Ա"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->lineEdit->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit_5->clear();
}

void adminGuestsDialog::paintEvent(QPaintEvent *)
{
    //QPainter painter(this);
    //painter.drawPixmap(0, 0, QPixmap(":/jpg/6.jpg").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void adminGuestsDialog::on_pushButton_clicked()
{
    //���
    QSqlQuery query;
    int idNum = 0;

    query.exec("select guestsid from guests");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    query.exec("insert into guests values('" + QString::number(idNum, 10) + "', '"
               + ui->lineEdit->text().trimmed() + "', '"
               + QString::number(ui->comboBox->currentIndex()) + "', '"
               + ui->lineEdit_2->text().trimmed() + "', '"
               + ui->lineEdit_3->text().trimmed() + "', '"
               + ui->lineEdit_4->text().trimmed() + "', '"
               + QString::number(ui->comboBox_2->currentIndex()) + "')");

    ui->lineEdit->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->comboBox_2->setCurrentIndex(0);

    currentTableModel->select();
    QMessageBox::information(NULL, "success", "add success!");

    emit modGuest();
}

void adminGuestsDialog::on_pushButton_2_clicked()
{
    //�޸�
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();
    query.exec("delete from guests where guestsid = '" + idNum + "'");

    query.exec("insert into guests values('" + idNum + "', '"
               + ui->lineEdit->text().trimmed() + "', '"
               + QString::number(ui->comboBox->currentIndex()) + "', '"
               + ui->lineEdit_2->text().trimmed() + "', '"
               + ui->lineEdit_3->text().trimmed() + "', '"
               + ui->lineEdit_4->text().trimmed() + "', '"
               + QString::number(ui->comboBox_2->currentIndex()) + "')");

    ui->lineEdit->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->comboBox_2->setCurrentIndex(0);

    currentTableModel->select();
    QMessageBox::information(NULL, "success", "modefy success!");

    emit modGuest();
}

void adminGuestsDialog::on_pushButton_3_clicked()
{
    //ɾ��
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������

    ui->lineEdit->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->comboBox_2->setCurrentIndex(0);

    QMessageBox::information(NULL, "success", "delete success!");

    emit modGuest();
}

void adminGuestsDialog::on_pushButton_4_clicked()
{
    //ˢ��
    currentTableModel->setTable("guests");
    currentTableModel->select();

    currentTableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("���"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("�û���"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("�Ա�"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("���֤��"));
    currentTableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("�ֻ���"));
    currentTableModel->setHeaderData(6, Qt::Horizontal, QObject::tr("��Ա"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->lineEdit->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit_5->clear();
}

void adminGuestsDialog::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();

    query.exec("select * from guests where guestsid = '" + idNum + "'");
    while(query.next())
    {
        ui->lineEdit->setText(query.value(1).toString());
        ui->comboBox->setCurrentIndex(query.value(2).toInt());
        ui->lineEdit_2->setText(query.value(3).toString());
        ui->lineEdit_3->setText(query.value(4).toString());
        ui->lineEdit_4->setText(query.value(5).toString());
        ui->comboBox_2->setCurrentIndex(query.value(6).toInt());
    }
}

void adminGuestsDialog::on_pushButton_5_clicked()
{
    //����
    currentTableModel->setTable("guests");
    if (ui->radioButton->isChecked() == true)
    {
        currentTableModel->setFilter("name like '%" + ui->lineEdit_5->text().trimmed() + "%'");
    }

    if (ui->radioButton_2->isChecked() == true)
    {
        currentTableModel->setFilter("idcard like '%" + ui->lineEdit_5->text().trimmed() + "%'");
    }

    if (ui->radioButton_3->isChecked() == true)
    {
        currentTableModel->setFilter("phone like '%" + ui->lineEdit_5->text().trimmed() + "%'");
    }

    currentTableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("���"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("�û���"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("�Ա�"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("���֤��"));
    currentTableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("�ֻ���"));
    currentTableModel->setHeaderData(6, Qt::Horizontal, QObject::tr("��Ա"));
    currentTableModel->select();
}
