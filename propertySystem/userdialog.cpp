#include "userdialog.h"
#include "ui_userdialog.h"

userDialog::userDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userDialog)
{
    ui->setupUi(this);

    currentTableModel_1 = new QSqlTableModel(this);
    currentView_1 = ui->tableView;
    currentTableModel_2 = new QSqlTableModel(this);
    currentView_2 = ui->tableView_2;

    ui->comboBox->setCurrentIndex(0);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());

    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->dateEdit_3->setDate(QDate::currentDate());
}

userDialog::~userDialog()
{
    delete ui;
}

void userDialog::showEvent(QShowEvent *event)
{
    on_comboBox_currentIndexChanged(0);
    on_comboBox_2_currentIndexChanged(0);

    int moneyRemain = 0;
    QSqlQuery query;
    query.exec("select balance from waterchanges where date <= '" + QDate::currentDate().toString("yyyy-MM-dd") + "' and name = '" + username + "'");
    while(query.next())
        moneyRemain = query.value(0).toInt();
    if(moneyRemain <= 20)
        QMessageBox::information(NULL, "waterchanges", "ˮ������Ѿ�<font color='red'> ���� 20 Ԫ </font>.Ϊ��Ӱ����������ʹ��,�뾡���ֵ!");

    moneyRemain = 0;
    query.exec("select balance from electricitychanges where date <= '" + QDate::currentDate().toString("yyyy-MM-dd") + "' and name = '" + username + "'");
    while(query.next())
        moneyRemain = query.value(0).toInt();
    if(moneyRemain <= 20)
        QMessageBox::information(NULL, "electricitychanges", "�������Ѿ�<font color='red'> ���� 20 Ԫ </font>.Ϊ��Ӱ����������ʹ��,�뾡���ֵ!");

    moneyRemain = 0;
    query.exec("select balance from gaschanges where date <= '" + QDate::currentDate().toString("yyyy-MM-dd") + "' and name = '" + username + "'");
    while(query.next())
        moneyRemain = query.value(0).toInt();
    if(moneyRemain <= 20)
        QMessageBox::information(NULL, "gaschanges", "��Ȼ������Ѿ�<font color='red'> ���� 20 Ԫ </font>.Ϊ��Ӱ����������ʹ��,�뾡���ֵ!");

}

void userDialog::on_comboBox_currentIndexChanged(int index)
{
    //ˮ��������б��л�
    QSqlQuery query;
    switch(index)
    {
    case 0:
        ui->label_3->clear();

        currentTableModel_1->setTable("waterchanges");
        currentTableModel_1->setFilter("name = '" + username + "'");
        currentTableModel_1->select();
        currentView_1->setModel(currentTableModel_1);
        currentView_1->setEditTriggers(QAbstractItemView::NoEditTriggers);

        query.exec("select balance from waterchanges where date <= '" + QDate::currentDate().toString("yyyy-MM-dd") + "' and name = '" + username + "'");
        while(query.next())
            ui->label_3->setText("��� :  " + query.value(0).toString()+ "Ԫ");

        break;
    case 1:
        ui->label_3->clear();

        currentTableModel_1->setTable("electricitychanges");
        currentTableModel_1->setFilter("name = '" + username + "'");
        currentTableModel_1->select();
        currentView_1->setModel(currentTableModel_1);
        currentView_1->setEditTriggers(QAbstractItemView::NoEditTriggers);

        query.exec("select balance from electricitychanges where date <= '" + QDate::currentDate().toString("yyyy-MM-dd") + "' and name = '" + username + "'");
        while(query.next())
            ui->label_3->setText("��� :  " + query.value(0).toString()+ "Ԫ");
        break;
    case 2:
        ui->label_3->clear();

        currentTableModel_1->setTable("gaschanges");
        currentTableModel_1->setFilter("name = '" + username + "'");
        currentTableModel_1->select();
        currentView_1->setModel(currentTableModel_1);
        currentView_1->setEditTriggers(QAbstractItemView::NoEditTriggers);

        query.exec("select balance from gaschanges where date <= '" + QDate::currentDate().toString("yyyy-MM-dd") + "' and name = '" + username + "'");
        while(query.next())
            ui->label_3->setText("��� :  " + query.value(0).toString()+ "Ԫ");
        break;
    default:
        break;
    }
}

void userDialog::on_pushButton_clicked()
{
    //��ѯ
    QDate preDate = ui->dateEdit->date();
    QDate nextDate = ui->dateEdit_2->date();

    if(preDate > nextDate)
    {
        QMessageBox::warning(this,tr("Warning"),tr("preDate > nextDate!"),QMessageBox::Yes);
        ui->dateEdit->setDate(nextDate); //����Ϊ��һ��ʱ��
    }

    switch(ui->comboBox->currentIndex())
    {
    case 1:
        //ˮ��
        currentTableModel_1->setFilter("date >= '" + preDate.toString("yyyy-MM-dd")
                                       + "' and date <= '" + nextDate.toString("yyyy-MM-dd") + "'");
        currentTableModel_1->select();
        ui->label_3->clear();
        break;
    case 2:
        //���
        currentTableModel_1->setFilter("date >= '" + preDate.toString("yyyy-MM-dd")
                                       + "' and date <= '" + nextDate.toString("yyyy-MM-dd") + "'");
        currentTableModel_1->select();
        ui->label_3->clear();
        break;
    case 3:
        //ú����
        currentTableModel_1->setFilter("date >= '" + preDate.toString("yyyy-MM-dd")
                                       + "' and date <= '" + nextDate.toString("yyyy-MM-dd") + "'");
        currentTableModel_1->select();
        ui->label_3->clear();
        break;
    default:
        break;
    }
}

void userDialog::on_comboBox_2_currentIndexChanged(int index)
{
    //�豸��������л�
    switch(index)
    {
    case 0:
        currentTableModel_2->setTable("lights");
        currentTableModel_2->select();
        currentView_2->setModel(currentTableModel_2);
        currentView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        break;
    case 1:
        currentTableModel_2->setTable("boardcase");
        currentTableModel_2->select();
        currentView_2->setModel(currentTableModel_2);
        currentView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        break;
    case 2:
        currentTableModel_2->setTable("equipment");
        currentTableModel_2->select();
        currentView_2->setModel(currentTableModel_2);
        currentView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        break;
    default:
        break;
    }
}

void userDialog::on_pushButton_10_clicked()
{
    //�ϴ�
    QSqlQuery query;
    int idNum = 0;
    switch(ui->comboBox_2->currentIndex())
    {
    case 0:
        //·��
        query.exec("select lightsid from lights");
        while(query.next())
        {
            if(idNum < query.value(0).toInt())
                idNum = query.value(0).toInt();
        }

        idNum++;

        query.exec("insert into lights values('" + QString::number(idNum, 10) + "', '"
                   + ui->lineEdit->text().trimmed() + "', 0, '"
                   + ui->lineEdit_2->text().trimmed() + "', '"
                   + QDate::currentDate().toString("yyyy-MM-dd") + "')");

        currentTableModel_2->select();
        break;
    case 1:
        //�㲥
        query.exec("select boardcaseid from boardcase");
        while(query.next())
        {
            if(idNum < query.value(0).toInt())
                idNum = query.value(0).toInt();
        }

        idNum++;

        query.exec("insert into boardcase values('" + QString::number(idNum, 10) + "', '"
                   + ui->lineEdit->text().trimmed() + "', 0, '"
                   + ui->lineEdit_2->text().trimmed() + "', '"
                   + QDate::currentDate().toString("yyyy-MM-dd") + "')");

        currentTableModel_2->select();
        break;
    case 2:
        //����
        query.exec("select equipmentid from equipment");
        while(query.next())
        {
            if(idNum < query.value(0).toInt())
                idNum = query.value(0).toInt();
        }

        idNum++;

        query.exec("insert into equipment values('" + QString::number(idNum, 10) + "', '"
                   + ui->lineEdit->text().trimmed() + "', 0, '"
                   + ui->lineEdit_2->text().trimmed() + "', '"
                   + QDate::currentDate().toString("yyyy-MM-dd") + "')");

        currentTableModel_2->select();
        break;
    default:
        break;
    }
    ui->lineEdit->clear();
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit_2->clear();
    ui->dateEdit_3->setDate(QDate::currentDate());
}

void userDialog::on_pushButton_11_clicked()
{
    //��ѯ
    switch(ui->comboBox_2->currentIndex())
    {
    case 0:
        //·��
        currentTableModel_2->setFilter("name like '%" + ui->lineEdit->text().trimmed() + "%'");
        currentTableModel_2->select();
        break;
    case 1:
        //�㲥
        currentTableModel_2->setFilter("name like '%" + ui->lineEdit->text().trimmed() + "%'");
        currentTableModel_2->select();
        break;
    case 2:
        //����
        currentTableModel_2->setFilter("name like '%" + ui->lineEdit->text().trimmed() + "%'");
        currentTableModel_2->select();
        break;
    default:
        break;
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void userDialog::on_tableView_2_clicked(const QModelIndex &index)
{
    //�Ҳ��б���
    int curRow = currentView_2->currentIndex().row(); //��ȡѡ�е���
    switch(ui->comboBox_2->currentIndex())
    {
    case 0:
    case 1:
    case 2:
        ui->lineEdit->setText(currentTableModel_2->index(curRow, 1).data().toString());
        ui->comboBox_3->setCurrentIndex(currentTableModel_2->index(curRow, 2).data().toInt());
        ui->lineEdit_2->setText(currentTableModel_2->index(curRow, 3).data().toString());
        ui->dateEdit_3->setDate(QDate::fromString(currentTableModel_2->index(curRow, 4).data().toString(), "yyyy-MM-dd"));
        break;
    default:
        break;
    }
}

void userDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/jpg/4.jpg").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void userDialog::on_pushButton_2_clicked()
{
    //��ϸ��Ϣ
    infow.show();
}
