#include "admindialog.h"
#include "ui_admindialog.h"

adminDialog::adminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    tableSeletc = 0;

    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());
    ui->comboBox->setCurrentIndex(0);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->label_3->clear();
    ui->lineEdit_3->clear();
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit_4->clear();
    ui->dateEdit_3->setDate(QDate::currentDate());
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();

    addComboBoxItem();
    on_pushButton_clicked();
}

adminDialog::~adminDialog()
{
    delete ui;
}

void adminDialog::on_pushButton_clicked()
{
    //ˮ��
    currentTableModel->setTable("waterchanges");
    currentTableModel->select();
    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    tableSeletc = 1;
}

void adminDialog::on_pushButton_2_clicked()
{
    //���
    currentTableModel->setTable("electricitychanges");
    currentTableModel->select();
    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    tableSeletc = 2;
}

void adminDialog::on_pushButton_3_clicked()
{
    //ú����
    currentTableModel->setTable("gaschanges");
    currentTableModel->select();
    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    tableSeletc = 3;
}

void adminDialog::on_pushButton_7_clicked()
{
    //��ѯ
    QDate preDate = ui->dateEdit->date();
    QDate nextDate = ui->dateEdit_2->date();
    QSqlQuery query;

    if(preDate > nextDate)
    {
        QMessageBox::warning(this,tr("Warning"),tr("preDate > nextDate!"),QMessageBox::Yes);
        ui->dateEdit->setDate(nextDate); //����Ϊ��һ��ʱ��
    }

    switch(tableSeletc)
    {
    case 1:
        //ˮ��
        currentTableModel->setFilter("date >= '" + preDate.toString("yyyy-MM-dd")
                                     + "' and date <= '" + nextDate.toString("yyyy-MM-dd") + "'");
        currentTableModel->select();

        if(ui->comboBox->currentIndex())
        {
            query.exec("select balance from waterchanges where date <= '" + QDate::currentDate().toString("yyyy-MM-dd") + "' and name = '" + ui->comboBox->currentText() + "'");
            while(query.next())
                ui->label_3->setText("��� : \n" + query.value(0).toString()+ "Ԫ");
        }
        else
        {
            ui->label_3->clear();
        }
        break;
    case 2:
        //���
        currentTableModel->setFilter("date >= '" + preDate.toString("yyyy-MM-dd")
                                     + "' and date <= '" + nextDate.toString("yyyy-MM-dd") + "'");
        currentTableModel->select();

        if(ui->comboBox->currentIndex())
        {
            query.exec("select balance from electricitychanges where date <= '" + QDate::currentDate().toString("yyyy-MM-dd") + "' and name = '" + ui->comboBox->currentText() + "'");
            while(query.next())
                ui->label_3->setText("��� : \n" + query.value(0).toString()+ "Ԫ");
        }
        else
        {
            ui->label_3->clear();
        }
        break;
    case 3:
        //ú����
        currentTableModel->setFilter("date >= '" + preDate.toString("yyyy-MM-dd")
                                     + "' and date <= '" + nextDate.toString("yyyy-MM-dd") + "'");
        currentTableModel->select();

        if(ui->comboBox->currentIndex())
        {
            query.exec("select balance from gaschanges where date <= '" + QDate::currentDate().toString("yyyy-MM-dd") + "' and name = '" + ui->comboBox->currentText() + "'");
            while(query.next())
                ui->label_3->setText("��� : \n" + query.value(0).toString()+ "Ԫ");
        }
        else
        {
            ui->label_3->clear();
        }
        break;
    default:
        break;
    }
}

void adminDialog::on_pushButton_8_clicked()
{
    //�ɷ�
    QSqlQuery query;
    int idNum = 0;
    int balance = 0;
    if(ui->comboBox->currentIndex())
    {
        //��0
        switch(tableSeletc)
        {
        case 1:
            //ˮ��
            query.exec("select waterchangesid from waterchanges where name = '" + ui->comboBox->currentText() + "'");
            while(query.next())
            {
                if(idNum < query.value(0).toInt())
                    idNum = query.value(0).toInt();
            }

            idNum++;

            query.exec("select balance from waterchanges where waterchangesid = '" + QString::number(idNum-1, 10) + "'");
            while(query.next())
            {
                balance = query.value(0).toInt();
            }

            query.exec("insert into waterchanges values('" + QString::number(idNum, 10) + "', '"
                       + ui->comboBox->currentText() + "', '"
                       + QDate::currentDate().toString("yyyy-MM-dd") + "', '"
                       + ui->lineEdit->text().trimmed() + "', '"
                       + QString::number(balance+ui->lineEdit->text().trimmed().toInt(), 10) + "')");

            currentTableModel->select();

            ui->label_3->setText("��� : \n" + QString::number(balance+ui->lineEdit->text().trimmed().toInt(), 10)+ "Ԫ");
            break;
        case 2:
            //���
            query.exec("select electricitychangesid from electricitychanges where name = '" + ui->comboBox->currentText() + "'");
            while(query.next())
            {
                if(idNum < query.value(0).toInt())
                    idNum = query.value(0).toInt();
            }

            idNum++;

            query.exec("select balance from waterchanges where electricitychanges = '" + QString::number(idNum-1, 10) + "'");
            while(query.next())
            {
                balance = query.value(0).toInt();
            }

            query.exec("insert into electricitychanges values('" + QString::number(idNum, 10) + "', '"
                       + ui->comboBox->currentText() + "', '"
                       + QDate::currentDate().toString("yyyy-MM-dd") + "', '"
                       + ui->lineEdit->text().trimmed() + "', '"
                       + QString::number(balance+ui->lineEdit->text().trimmed().toInt(), 10) + "')");

            currentTableModel->select();

            ui->label_3->setText("��� : \n" + QString::number(balance+ui->lineEdit->text().trimmed().toInt(), 10)+ "Ԫ");
            break;
        case 3:
            //ú����
            query.exec("select gaschangesid from gaschanges where name = '" + ui->comboBox->currentText() + "'");
            while(query.next())
            {
                if(idNum < query.value(0).toInt())
                    idNum = query.value(0).toInt();
            }

            idNum++;

            query.exec("select balance from waterchanges where gaschanges = '" + QString::number(idNum-1, 10) + "'");
            while(query.next())
            {
                balance = query.value(0).toInt();
            }

            query.exec("insert into gaschanges values('" + QString::number(idNum, 10) + "', '"
                       + ui->comboBox->currentText() + "', '"
                       + QDate::currentDate().toString("yyyy-MM-dd") + "', '"
                       + ui->lineEdit->text().trimmed() + "', '"
                       + QString::number(balance+ui->lineEdit->text().trimmed().toInt(), 10) + "')");

            currentTableModel->select();

            ui->label_3->setText("��� : \n" + QString::number(balance+ui->lineEdit->text().trimmed().toInt(), 10)+ "Ԫ");
            break;
        default:
            break;
        }
    }
    else
    {
        QMessageBox::information(NULL, tr("fail"), tr("no user name choose!"));
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void adminDialog::on_pushButton_9_clicked()
{
    //�۷�
    QSqlQuery query;
    int idNum = 0;
    int balance = 0;
    if(ui->comboBox->currentIndex())
    {
        //��0
        switch(tableSeletc)
        {
        case 1:
            //ˮ��
            query.exec("select waterchangesid from waterchanges where name = '" + ui->comboBox->currentText() + "'");
            while(query.next())
            {
                if(idNum < query.value(0).toInt())
                    idNum = query.value(0).toInt();
            }

            idNum++;

            query.exec("select balance from waterchanges where waterchangesid = '" + QString::number(idNum-1, 10) + "'");
            while(query.next())
            {
                balance = query.value(0).toInt();
            }

            query.exec("insert into waterchanges values('" + QString::number(idNum, 10) + "', '"
                       + ui->comboBox->currentText() + "', '"
                       + QDate::currentDate().toString("yyyy-MM-dd") + "', '-"
                       + ui->lineEdit_2->text().trimmed() + "', '"
                       + QString::number(balance-ui->lineEdit_2->text().trimmed().toInt(), 10) + "')");

            currentTableModel->select();

            ui->label_3->setText("��� : \n" + QString::number(balance-ui->lineEdit_2->text().trimmed().toInt(), 10)+ "Ԫ");
            break;
        case 2:
            //���
            query.exec("select electricitychangesid from electricitychanges where name = '" + ui->comboBox->currentText() + "'");
            while(query.next())
            {
                if(idNum < query.value(0).toInt())
                    idNum = query.value(0).toInt();
            }

            idNum++;

            query.exec("select balance from waterchanges where electricitychanges = '" + QString::number(idNum-1, 10) + "'");
            while(query.next())
            {
                balance = query.value(0).toInt();
            }

            query.exec("insert into electricitychanges values('" + QString::number(idNum, 10) + "', '"
                       + ui->comboBox->currentText() + "', '"
                       + QDate::currentDate().toString("yyyy-MM-dd") + "', '-"
                       + ui->lineEdit_2->text().trimmed() + "', '"
                       + QString::number(balance-ui->lineEdit_2->text().trimmed().toInt(), 10) + "')");

            currentTableModel->select();

            ui->label_3->setText("��� : \n" + QString::number(balance-ui->lineEdit_2->text().trimmed().toInt(), 10)+ "Ԫ");
            break;
        case 3:
            //ú����
            query.exec("select gaschangesid from gaschanges where name = '" + ui->comboBox->currentText() + "'");
            while(query.next())
            {
                if(idNum < query.value(0).toInt())
                    idNum = query.value(0).toInt();
            }

            idNum++;

            query.exec("select balance from waterchanges where gaschanges = '" + QString::number(idNum-1, 10) + "'");
            while(query.next())
            {
                balance = query.value(0).toInt();
            }

            query.exec("insert into gaschanges values('" + QString::number(idNum, 10) + "', '"
                       + ui->comboBox->currentText() + "', '"
                       + QDate::currentDate().toString("yyyy-MM-dd") + "', '-"
                       + ui->lineEdit_2->text().trimmed() + "', '"
                       + QString::number(balance-ui->lineEdit_2->text().trimmed().toInt(), 10) + "')");

            currentTableModel->select();

            ui->label_3->setText("��� : \n" + QString::number(balance-ui->lineEdit_2->text().trimmed().toInt(), 10)+ "Ԫ");
            break;
        default:
            break;
        }
    }
    else
    {
        QMessageBox::information(NULL, tr("fail"), tr("no user name choose!"));
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void adminDialog::on_pushButton_4_clicked()
{
    //·��
    currentTableModel->setTable("lights");
    currentTableModel->select();
    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    tableSeletc = 4;

    ui->lineEdit_3->clear();
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit_4->clear();
    ui->dateEdit_3->setDate(QDate::currentDate());
}

void adminDialog::on_pushButton_5_clicked()
{
    //�㲥
    currentTableModel->setTable("boardcase");
    currentTableModel->select();
    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    tableSeletc = 5;

    ui->lineEdit_3->clear();
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit_4->clear();
    ui->dateEdit_3->setDate(QDate::currentDate());
}

void adminDialog::on_pushButton_6_clicked()
{
    //����
    currentTableModel->setTable("equipment");
    currentTableModel->select();
    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    tableSeletc = 6;

    ui->lineEdit_3->clear();
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit_4->clear();
    ui->dateEdit_3->setDate(QDate::currentDate());
}

void adminDialog::on_pushButton_10_clicked()
{
    //��¼
    QSqlQuery query;
    int idNum = 0;
    switch(tableSeletc)
    {
    case 4:
        //·��
        query.exec("select lightsid from lights");
        while(query.next())
        {
            if(idNum < query.value(0).toInt())
                idNum = query.value(0).toInt();
        }

        idNum++;

        query.exec("insert into lights values('" + QString::number(idNum, 10) + "', '"
                   + ui->lineEdit_3->text().trimmed() + "', '"
                   + QString::number(ui->comboBox_2->currentIndex(), 10) + "', '"
                   + ui->lineEdit_4->text().trimmed() + "', '"
                   + QDate::currentDate().toString("yyyy-MM-dd") + "')");
        currentTableModel->select();
        break;
    case 5:
        //�㲥
        query.exec("select boardcaseid from boardcase");
        while(query.next())
        {
            if(idNum < query.value(0).toInt())
                idNum = query.value(0).toInt();
        }

        idNum++;

        query.exec("insert into boardcase values('" + QString::number(idNum, 10) + "', '"
                   + ui->lineEdit_3->text().trimmed() + "', '"
                   + QString::number(ui->comboBox_2->currentIndex(), 10) + "', '"
                   + ui->lineEdit_4->text().trimmed() + "', '"
                   + QDate::currentDate().toString("yyyy-MM-dd") + "')");

        currentTableModel->select();
        break;
    case 6:
        //����
        query.exec("select equipmentid from equipment");
        while(query.next())
        {
            if(idNum < query.value(0).toInt())
                idNum = query.value(0).toInt();
        }

        idNum++;

        query.exec("insert into equipment values('" + QString::number(idNum, 10) + "', '"
                   + ui->lineEdit_3->text().trimmed() + "', '"
                   + QString::number(ui->comboBox_2->currentIndex(), 10) + "', '"
                   + ui->lineEdit_4->text().trimmed() + "', '"
                   + QDate::currentDate().toString("yyyy-MM-dd") + "')");

        currentTableModel->select();
        break;
    default:
        break;
    }
    ui->lineEdit_3->clear();
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit_4->clear();
    ui->dateEdit_3->setDate(QDate::currentDate());
}

void adminDialog::on_pushButton_11_clicked()
{
    //��ѯ
    switch(tableSeletc)
    {
    case 4:
        //·��
        currentTableModel->setFilter("name like '%" + ui->lineEdit_3->text().trimmed() + "%'");
        currentTableModel->select();
        break;
    case 5:
        //�㲥
        currentTableModel->setFilter("name like '%" + ui->lineEdit_3->text().trimmed() + "%'");
        currentTableModel->select();
        break;
    case 6:
        //����
        currentTableModel->setFilter("name like '%" + ui->lineEdit_3->text().trimmed() + "%'");
        currentTableModel->select();
        break;
    default:
        break;
    }
    ui->lineEdit_3->clear();
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit_4->clear();
    ui->dateEdit_3->setDate(QDate::currentDate());
}

void adminDialog::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    switch(tableSeletc)
    {
    case 4:
    case 5:
    case 6:
        ui->lineEdit_3->setText(currentTableModel->index(curRow, 1).data().toString());
        ui->comboBox_2->setCurrentIndex(currentTableModel->index(curRow, 2).data().toInt());
        ui->lineEdit_4->setText(currentTableModel->index(curRow, 3).data().toString());
        ui->dateEdit_3->setDate(QDate::fromString(currentTableModel->index(curRow, 4).data().toString(), "yyyy-MM-dd"));
        break;
    default:
        break;
    }
}

void adminDialog::on_pushButton_12_clicked()
{
    //�½��û�
    QSqlQuery query;
    int idNum = 0;
    QString name = ui->lineEdit_5->text().trimmed();
    bool nameFlag = false;

    query.exec("select personid from person");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    query.exec("select name from person");
    while(query.next())
    {
        if(name == query.value(0).toString())
        {
            QMessageBox::information(NULL, "fail", "name repeat!");
            nameFlag = true;
            break;
        }
    }

    if(nameFlag == false)
    {
        query.exec("insert into person values('" + QString::number(idNum, 10) + "', '" + name + "', '" + ui->lineEdit_6->text().trimmed() + "', 1)");

        ui->lineEdit_5->clear();
        ui->lineEdit_6->clear();

        addComboBoxItem();
        currentTableModel->select();
        QMessageBox::information(NULL, "success", "user add success!");
    }
}

void adminDialog::on_pushButton_13_clicked()
{
    //�û�����
    currentTableModel->setTable("person");
    currentTableModel->select();
    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    tableSeletc = 8;
}

void adminDialog::on_pushButton_14_clicked()
{
    //�û��޸�
    if(tableSeletc == 8)
    {
        currentView->setEditTriggers(QAbstractItemView::AllEditTriggers);
    }
}

void adminDialog::on_pushButton_15_clicked()
{
    //�û�ɾ��
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    if(tableSeletc == 8)
    {
        currentTableModel->removeRow(curRow); //ɾ������
    }
}

void adminDialog::addComboBoxItem()
{
    //���ѡ�
    ui->comboBox->clear();
    ui->comboBox->addItem("");
    QString sql;
    QSqlQuery query;
    sql = "select name from ownerinfo";
    query.exec(sql);
    while(query.next())
    {
        if(ui->comboBox->findText(query.value(0).toString()) == -1)
        {
            ui->comboBox->addItem(query.value(0).toString());
        }
    }
}

void adminDialog::on_pushButton_16_clicked()
{
    //�ύ
    currentTableModel->submitAll();
}

void adminDialog::on_pushButton_17_clicked()
{
    //ͣ��λ����
    carw.show();
}

void adminDialog::on_pushButton_18_clicked()
{
    //�û�����
    ownerw.show();
}

void adminDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/jpg/4.jpg").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}
