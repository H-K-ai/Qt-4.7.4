#include "admindialog.h"
#include "ui_admindialog.h"

adminDialog::adminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);

    currentView = ui->tableView;

    idNum = -1;

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox->setEnabled(true);
    ui->label->clear();
    comboBox_2DataFill(ui->comboBox->currentIndex());

    on_pushButton_4_clicked(); //ˢ��ʳ��
}

adminDialog::~adminDialog()
{
    delete ui;
}

void adminDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/png/bj2.png").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void adminDialog::on_pushButton_clicked()
{
    //���
    QString sql;
    QSqlQuery query;

    QString targetPath;

    idNum = 0;
    switch(ui->comboBox->currentIndex())
    {
    case 0:
        //food
        //��ȡ������С
        sql = "select foodid from food";
        query.exec(sql);
        while(query.next())
        {
            if(idNum < query.value(0).toInt())
                idNum = query.value(0).toInt();
        }

        idNum++;

        //����ͼƬ
        targetPath = "food/" + QString::number(idNum, 10) + ".jpg";
        copyFileToPath(picPath, targetPath, true); //����ʽ����

        //�������ݿ�
        sql = "insert into food values ('" + QString::number(idNum, 10)
                + "', '" + ui->lineEdit->text().trimmed()
                + "', '" + ui->lineEdit_2->text().trimmed()
                + "', '" + ui->lineEdit_3->text().trimmed()
                + "', '" + ui->comboBox_2->currentText()
                + "', '" + targetPath
                + "')";
        query.exec(sql);

        break;
    case 1:
        //cookbook
        sql = "select cookbookid from cookbook";
        query.exec(sql);
        while(query.next())
        {
            if(idNum < query.value(0).toInt())
                idNum = query.value(0).toInt();
        }

        idNum++;

        targetPath = "cookbook/" + QString::number(idNum, 10) + ".jpg";
        copyFileToPath(picPath, targetPath, true); //����ʽ����

        sql = "insert into cookbook values ('" + QString::number(idNum, 10)
                + "', '" + ui->lineEdit->text().trimmed()
                + "', '" + ui->lineEdit_2->text().trimmed()
                + "', '" + ui->lineEdit_3->text().trimmed()
                + "', '" + ui->comboBox_2->currentText()
                + "', '" + targetPath
                + "')";
        query.exec(sql);

        break;
    case 2:
        //sports
        sql = "select sportsid from sports";
        query.exec(sql);
        while(query.next())
        {
            if(idNum < query.value(0).toInt())
                idNum = query.value(0).toInt();
        }

        idNum++;

        targetPath = "sports/" + QString::number(idNum, 10) + ".jpg";
        copyFileToPath(picPath, targetPath, true); //����ʽ����

        sql = "insert into sports values ('" + QString::number(idNum, 10)
                + "', '" + ui->lineEdit->text().trimmed()
                + "', '" + ui->lineEdit_2->text().trimmed()
                + "', '" + ui->lineEdit_3->text().trimmed()
                + "', '" + ui->comboBox_2->currentText()
                + "', '" + targetPath
                + "')";
        query.exec(sql);

        break;
    default:
        break;
    }

    currentTableModel->select(); //ˢ�±�

    ui->lineEdit->clear(); //�������
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->label->clear();
    comboBox_2DataFill(ui->comboBox->currentIndex());
}

void adminDialog::on_pushButton_2_clicked()
{
    //�޸�
    QString sql;
    QSqlQuery query;
    QString targetPath;

    switch(ui->comboBox->currentIndex())
    {
    case 0:
        //food
        //��ɾ����id�ŵ�����
        sql = "delete from food where foodid = '" + QString::number(idNum, 10) + "'";
        query.exec(sql);

        //ͼƬ�޸�
        targetPath = "food/" + QString::number(idNum, 10) + ".jpg";
        copyFileToPath(picPath, targetPath, true); //����ʽ����

        //�������ݿ�
        sql = "insert into food values ('" + QString::number(idNum, 10)
                + "', '" + ui->lineEdit->text().trimmed()
                + "', '" + ui->lineEdit_2->text().trimmed()
                + "', '" + ui->lineEdit_3->text().trimmed()
                + "', '" + ui->comboBox_2->currentText()
                + "', '" + targetPath
                + "')";
        query.exec(sql);

        break;
    case 1:
        //cookbook
        sql = "delete from cookbook where cookbookid = '" + QString::number(idNum, 10) + "'";
        query.exec(sql);

        targetPath = "cookbook/" + QString::number(idNum, 10) + ".jpg";
        copyFileToPath(picPath, targetPath, true); //����ʽ����

        sql = "insert into cookbook values ('" + QString::number(idNum, 10)
                + "', '" + ui->lineEdit->text().trimmed()
                + "', '" + ui->lineEdit_2->text().trimmed()
                + "', '" + ui->lineEdit_3->text().trimmed()
                + "', '" + ui->comboBox_2->currentText()
                + "', '" + targetPath
                + "')";
        query.exec(sql);

        break;
    case 2:
        //sports
        sql = "delete from sports where sportsid = '" + QString::number(idNum, 10) + "'";
        query.exec(sql);

        targetPath = "sports/" + QString::number(idNum, 10) + ".jpg";
        copyFileToPath(picPath, targetPath, true); //����ʽ����

        sql = "insert into sports values ('" + QString::number(idNum, 10)
                + "', '" + ui->lineEdit->text().trimmed()
                + "', '" + ui->lineEdit_2->text().trimmed()
                + "', '" + ui->lineEdit_3->text().trimmed()
                + "', '" + ui->comboBox_2->currentText()
                + "', '" + targetPath
                + "')";
        query.exec(sql);

        break;
    default:
        break;
    }

    currentTableModel->select(); //ˢ�±�

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->label->clear();
    comboBox_2DataFill(ui->comboBox->currentIndex());
}

void adminDialog::on_pushButton_3_clicked()
{
    //ɾ��
    QString sql;
    QSqlQuery query;

    switch(ui->comboBox->currentIndex())
    {
    case 0:
        //food
        //ɾ����id�ŵ�����
        sql = "delete from food where foodid = '" + QString::number(idNum, 10) + "'";
        query.exec(sql);
        break;
    case 1:
        //cookbook
        sql = "delete from cookbook where cookbookid = '" + QString::number(idNum, 10) + "'";
        query.exec(sql);
        break;
    case 2:
        //sports
        sql = "delete from sports where sportsid = '" + QString::number(idNum, 10) + "'";
        query.exec(sql);
        break;
    default:
        break;
    }

    currentTableModel->select(); //ˢ�±�

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->label->clear();
    comboBox_2DataFill(ui->comboBox->currentIndex());
}

void adminDialog::on_pushButton_7_clicked()
{
    //ͼƬ
    switch(ui->comboBox->currentIndex())
    {
    case 0:
        //food
        picPath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
        break;
    case 1:
        //cookbook
        picPath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
        break;
    case 2:
        //sports
        picPath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
        break;
    default:
        break;
    }

    if(picPath.length() == 0) {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
    } else {
        QMessageBox::information(NULL, tr("Path"), tr("You selected ") + picPath);
    }

    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(picPath));
}

void adminDialog::on_pushButton_4_clicked()
{
    //ʳ��
    currentTableModel->setTable("food");
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->comboBox->setEnabled(true);
}

void adminDialog::on_pushButton_5_clicked()
{
    //ʳ��
    currentTableModel->setTable("cookbook");
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->comboBox->setEnabled(true);
}

void adminDialog::on_pushButton_6_clicked()
{
    //�˶�
    currentTableModel->setTable("sports");
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->label_4->setText("ǧ��/Сʱ");
    ui->comboBox->setEnabled(true);
}

void adminDialog::on_comboBox_currentIndexChanged(int index)
{
    //����仯
    int comboBoxIndex = ui->comboBox->currentIndex();
    comboBox_2DataFill(comboBoxIndex);
}

void adminDialog::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    QString currentTableName = currentTableModel->tableName();
    int comboBoxIndex = 0;
    if(currentTableName == QString("food"))
    {
        comboBoxIndex = 0;
    }
    else if(currentTableName == QString("cookbook"))
    {
        comboBoxIndex = 1;
    }
    else if(currentTableName == QString("sports"))
    {
        comboBoxIndex = 2;
    }
    else
    {
    }
    ui->comboBox->setCurrentIndex(comboBoxIndex);
    ui->comboBox->setEnabled(false);
    comboBox_2DataFill(comboBoxIndex);

    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    idNum = currentTableModel->index(curRow, 0).data().toInt();

    ui->lineEdit->setText(currentTableModel->index(curRow, 1).data().toString());
    ui->lineEdit_2->setText(currentTableModel->index(curRow, 2).data().toString());
    ui->lineEdit_3->setText(currentTableModel->index(curRow, 3).data().toString());

    ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(currentTableModel->index(curRow, 4).data().toString()));

    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(currentTableModel->index(curRow, 5).data().toString()));

    picPath = currentTableModel->index(curRow, 5).data().toString();
}

void adminDialog::comboBox_2DataFill(const int comboBoxIndex)
{
    //ϸ���� ѡ�����

    //�����
    ui->comboBox_2->clear();

    switch(comboBoxIndex)
    {
    case 0:
        //food
        ui->comboBox_2->addItem("����");
        ui->comboBox_2->addItem("������");
        ui->comboBox_2->addItem("�ɶ�");
        ui->comboBox_2->addItem("�߲�");
        ui->comboBox_2->addItem("����");
        ui->comboBox_2->addItem("ˮ��");
        ui->comboBox_2->addItem("�������");
        ui->comboBox_2->addItem("����");
        ui->comboBox_2->addItem("����");
        ui->comboBox_2->addItem("����");
        ui->comboBox_2->addItem("����");
        ui->comboBox_2->addItem("��Ϻз��");
        ui->comboBox_2->addItem("Ӥ�׶�ʳƷ");
        ui->comboBox_2->addItem("С�����");
        ui->comboBox_2->addItem("��ʳʳƷ");
        ui->comboBox_2->addItem("������");
        ui->comboBox_2->addItem("�ƾ�����");
        ui->comboBox_2->addItem("���۽�");
        ui->comboBox_2->addItem("��֬");
        ui->comboBox_2->addItem("��ζƷ");
        ui->comboBox_2->addItem("ҩʳ������");

        ui->label_4->setText("ǧ��/�ٿ�");
        break;
    case 1:
        //cookbook
        ui->comboBox_2->addItem("˽�Ҳ�");
        ui->comboBox_2->addItem("�ҳ���");
        ui->comboBox_2->addItem("������");
        ui->comboBox_2->addItem("����");
        ui->comboBox_2->addItem("���ϲ�");
        ui->comboBox_2->addItem("���ղ�");
        ui->comboBox_2->addItem("������");
        ui->comboBox_2->addItem("ɽ����");
        ui->comboBox_2->addItem("�Ϻ���");
        ui->comboBox_2->addItem("�����");
        ui->comboBox_2->addItem("�Ĵ���");
        ui->comboBox_2->addItem("������");
        ui->comboBox_2->addItem("������");
        ui->comboBox_2->addItem("���ݲ�");
        ui->comboBox_2->addItem("�㽭��");
        ui->comboBox_2->addItem("���ϲ�");
        ui->comboBox_2->addItem("��ի��");
        ui->comboBox_2->addItem("ɽ����");
        ui->comboBox_2->addItem("������");
        ui->comboBox_2->addItem("�����");
        ui->comboBox_2->addItem("�㶫��");
        ui->comboBox_2->addItem("���ղ�");
        ui->comboBox_2->addItem("������");
        ui->comboBox_2->addItem("��ǭ��");
        ui->comboBox_2->addItem("̨���");
        ui->comboBox_2->addItem("���ϲ�");
        ui->comboBox_2->addItem("�½���");
        ui->comboBox_2->addItem("������");
        ui->comboBox_2->addItem("���Ĳ�");
        ui->comboBox_2->addItem("�ຣ��");
        ui->comboBox_2->addItem("������");

        ui->label_4->setText("ǧ��/�ٿ�");
        break;
    case 2:
        //sports
        ui->comboBox_2->addItem("��������");
        ui->comboBox_2->addItem("��·");
        ui->comboBox_2->addItem("����ѵ��");
        ui->comboBox_2->addItem("�赸");
        ui->comboBox_2->addItem("���г��˶�");
        ui->comboBox_2->addItem("ˮ���˶�");
        ui->comboBox_2->addItem("�ճ��˶�");
        ui->comboBox_2->addItem("����");
        ui->comboBox_2->addItem("����");
        ui->comboBox_2->addItem("԰���˶�");
        ui->comboBox_2->addItem("����");
        ui->comboBox_2->addItem("�����˶�");
        ui->comboBox_2->addItem("�ܲ�");

        ui->label_4->setText("ǧ��/Сʱ");
        break;
    default:
        break;
    }
}
