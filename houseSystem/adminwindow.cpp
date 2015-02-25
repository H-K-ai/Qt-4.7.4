#include "adminwindow.h"
#include "ui_adminwindow.h"

adminWindow::adminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminWindow)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);

    //ˢ��¥��
    on_pushButton_4_clicked();
}

adminWindow::~adminWindow()
{
    delete ui;
}

//�˵������йش���
void adminWindow::on_action_triggered()
{
    //¥��
    ui->tabWidget->setCurrentIndex(0);   //�����ת����Ӧѡ�
    on_pushButton_4_clicked();           //��ִ����Ӧ��ˢ��
}

void adminWindow::on_action_2_triggered()
{
    //��Ȩ
    ui->tabWidget->setCurrentIndex(1);   //�����ת����Ӧѡ�
    on_pushButton_6_clicked();           //��ִ����Ӧ��ˢ��
}

void adminWindow::on_action_3_triggered()
{
    //����
    ui->tabWidget->setCurrentIndex(4);   //�����ת����Ӧѡ�
    on_pushButton_21_clicked();           //��ִ����Ӧ��ˢ��
}

void adminWindow::on_action_4_triggered()
{
    //�Ǽ�
    ui->tabWidget->setCurrentIndex(2);   //�����ת����Ӧѡ�
    on_pushButton_11_clicked();           //��ִ����Ӧ��ˢ��
}

void adminWindow::on_action_5_triggered()
{
    //����
    ui->tabWidget->setCurrentIndex(3);   //�����ת����Ӧѡ�
    on_pushButton_16_clicked();           //��ִ����Ӧ��ˢ��
}

void adminWindow::on_action_6_triggered()
{
    //��Ա
    ui->tabWidget->setCurrentIndex(5);   //�����ת����Ӧѡ�
    on_pushButton_26_clicked();           //��ִ����Ӧ��ˢ��
}

void adminWindow::on_action_7_triggered()
{
    //���԰�
    ui->tabWidget->setCurrentIndex(6);   //�����ת����Ӧѡ�
    on_pushButton_35_clicked();           //��ִ����Ӧ��ˢ��
}

void adminWindow::on_action_8_triggered()
{
    //�˳���¼
    this->hide();
    emit closeWindows();
}
//�˵�����������

//����ҳ��ˢ�°�ť
void adminWindow::on_pushButton_4_clicked()
{
    //¥��
    currentView = ui->tableView;

    currentTableModel->setTable("houses");
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->pushButton->setEnabled(true); //��Ӱ�ť����
}

void adminWindow::on_pushButton_6_clicked()
{
    //��Ȩ
    currentView = ui->tableView_2;

    currentTableModel->setTable("property");
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->pushButton_8->setEnabled(true); //��Ӱ�ť����
}

void adminWindow::on_pushButton_11_clicked()
{
    //�Ǽ�
    currentView = ui->tableView_3;

    currentTableModel->setTable("grade");
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->pushButton_13->setEnabled(true); //��Ӱ�ť�û�
}

void adminWindow::on_pushButton_16_clicked()
{
    //����
    currentView = ui->tableView_4;

    currentTableModel->setTable("record");
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->pushButton_18->setEnabled(true); //��Ӱ�ť����
}

void adminWindow::on_pushButton_21_clicked()
{
    //����
    currentView = ui->tableView_5;

    currentTableModel->setTable("business");
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->pushButton_23->setEnabled(true); //��Ӱ�ť����
}

void adminWindow::on_pushButton_26_clicked()
{
    //��Ա
    currentView = ui->tableView_6;

    currentTableModel->setTable("person");
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->pushButton_30->setEnabled(true); //��Ӱ�ť����
}

void adminWindow::on_pushButton_35_clicked()
{
    //���԰�
    currentView = ui->tableView_7;

    currentTableModel->setTable("message");
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->pushButton_32->setEnabled(true); //��Ӱ�ť����
}

//����ҳ��ˢ�°�ť ����

void adminWindow::on_tabWidget_currentChanged(int index)
{
    //�л�ѡ�
    ui->label->clear(); //���ͼƬ
    ui->label_2->clear();
    ui->label_3->clear();
    ui->label_4->clear();
    ui->label_5->clear();
    ui->label_6->clear();

    switch(index)
    {
    case 0:
        on_pushButton_4_clicked();
        break;
    case 1:
        on_pushButton_6_clicked();
        break;
    case 2:
        on_pushButton_11_clicked();
        break;
    case 3:
        on_pushButton_16_clicked();
        break;
    case 4:
        on_pushButton_21_clicked();
        break;
    case 5:
        on_pushButton_26_clicked();
        break;
    case 6:
        on_pushButton_35_clicked();
        break;
    default:
        break;
    }
}

//����ҳ����Ӱ�ť
void adminWindow::on_pushButton_clicked()
{
    //¥��
    int rowNum = currentTableModel->rowCount(); //��ñ������
    int id = currentTableModel->record(rowNum - 1).value(0).toInt() + 1;

    currentView->setEditTriggers(QAbstractItemView::DoubleClicked);  //ʹ��ɱ༭
    currentTableModel->insertRow(rowNum); //���һ��
    currentTableModel->setData(currentTableModel->index(rowNum, 0), id);

    QString sourcePath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
    if(sourcePath.length() == 0) {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
        on_pushButton_4_clicked();
    } else {
        QMessageBox::information(NULL, tr("Path"), tr("You selected ") + sourcePath);
        ui->pushButton->setEnabled(false); //��Ӱ�ť�û�
    }

    QString targetPath = "house/" + QString::number(id, 10) + "." + "3.jpg";

    qDebug() << targetPath << endl;

    copyFileToPath(sourcePath, targetPath, true); //����ʽ����
    currentTableModel->setData(currentTableModel->index(rowNum, 3), targetPath);

    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(targetPath));
}

void adminWindow::on_pushButton_8_clicked()
{
    //��Ȩ
    int rowNum = currentTableModel->rowCount(); //��ñ������
    int id = currentTableModel->record(rowNum - 1).value(0).toInt() + 1;

    currentView->setEditTriggers(QAbstractItemView::AllEditTriggers);  //ʹ��ɱ༭
    currentTableModel->insertRow(rowNum); //���һ��
    currentTableModel->setData(currentTableModel->index(rowNum, 0), id);

    QString sourcePath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
    if(sourcePath.length() == 0) {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
        on_pushButton_6_clicked();
    } else {
        QMessageBox::information(NULL, tr("Path"), tr("You selected ") + sourcePath);
        ui->pushButton_8->setEnabled(false); //��Ӱ�ť�û�
    }

    QString targetPath = "property/" + QString::number(id, 10) + ".jpg";

    qDebug() << targetPath << endl;

    copyFileToPath(sourcePath, targetPath, true); //����ʽ����
    currentTableModel->setData(currentTableModel->index(rowNum, 3), targetPath);

    ui->label_2->setScaledContents(true);
    ui->label_2->setPixmap(QPixmap(targetPath));
}

void adminWindow::on_pushButton_13_clicked()
{
    //�Ǽ�
    int rowNum = currentTableModel->rowCount(); //��ñ������
    int id = currentTableModel->record(rowNum - 1).value(0).toInt() + 1;

    currentView->setEditTriggers(QAbstractItemView::AllEditTriggers);  //ʹ��ɱ༭
    currentTableModel->insertRow(rowNum); //���һ��
    currentTableModel->setData(currentTableModel->index(rowNum, 0), id);

    QString sourcePath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
    if(sourcePath.length() == 0) {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
        on_pushButton_11_clicked();
    } else {
        QMessageBox::information(NULL, tr("Path"), tr("You selected ") + sourcePath);
        ui->pushButton_13->setEnabled(false); //��Ӱ�ť�û�
    }

    QString targetPath = "grade/" + QString::number(id, 10) + ".jpg";

    qDebug() << targetPath << endl;

    copyFileToPath(sourcePath, targetPath, true); //����ʽ����
    currentTableModel->setData(currentTableModel->index(rowNum, 3), targetPath);

    ui->label_3->setScaledContents(true);
    ui->label_3->setPixmap(QPixmap(targetPath));
}

void adminWindow::on_pushButton_18_clicked()
{
    //����
    int rowNum = currentTableModel->rowCount(); //��ñ������
    int id = currentTableModel->record(rowNum - 1).value(0).toInt() + 1;

    currentView->setEditTriggers(QAbstractItemView::AllEditTriggers);  //ʹ��ɱ༭
    currentTableModel->insertRow(rowNum); //���һ��
    currentTableModel->setData(currentTableModel->index(rowNum, 0), id);
    currentTableModel->setData(currentTableModel->index(rowNum, 1), QDate::currentDate().toString("yyyy.MM.dd"));
    currentTableModel->setData(currentTableModel->index(rowNum, 2), QTime::currentTime().toString("hh:mm:ss"));
    currentTableModel->setData(currentTableModel->index(rowNum, 4), 1);

    QString sourcePath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
    if(sourcePath.length() == 0) {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
        on_pushButton_16_clicked();
    } else {
        QMessageBox::information(NULL, tr("Path"), tr("You selected ") + sourcePath);
        ui->pushButton_18->setEnabled(false); //��Ӱ�ť�û�
    }

    QString targetPath = "record/" + QString::number(id, 10) + ".jpg";

    qDebug() << targetPath << endl;

    copyFileToPath(sourcePath, targetPath, true); //����ʽ����
    currentTableModel->setData(currentTableModel->index(rowNum, 5), targetPath);

    ui->label_4->setScaledContents(true);
    ui->label_4->setPixmap(QPixmap(targetPath));
}

void adminWindow::on_pushButton_23_clicked()
{
    //����
    int rowNum = currentTableModel->rowCount(); //��ñ������
    int id = currentTableModel->record(rowNum - 1).value(0).toInt() + 1;

    currentView->setEditTriggers(QAbstractItemView::AllEditTriggers);  //ʹ��ɱ༭
    currentTableModel->insertRow(rowNum); //���һ��
    currentTableModel->setData(currentTableModel->index(rowNum, 0), id);

    ui->pushButton_23->setEnabled(false); //��Ӱ�ť�û�
}

void adminWindow::on_pushButton_30_clicked()
{
    //��Ա
    int rowNum = currentTableModel->rowCount(); //��ñ������
    int id = currentTableModel->record(rowNum - 1).value(0).toInt() + 1;

    currentView->setEditTriggers(QAbstractItemView::AllEditTriggers);  //ʹ��ɱ༭
    currentTableModel->insertRow(rowNum); //���һ��
    currentTableModel->setData(currentTableModel->index(rowNum, 0), id);

    ui->pushButton_30->setEnabled(false); //��Ӱ�ť�û�
}

void adminWindow::on_pushButton_32_clicked()
{
    //���԰�
    ui->label_8->setText(adminname);
    ui->lineEdit->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->textEdit->clear();
    ui->pushButton_32->setEnabled(false); //��Ӱ�ť�û�
}

//����ҳ����Ӱ�ť ����

//����ҳ���޸İ�ť
void adminWindow::on_pushButton_3_clicked()
{
    //¥��
    currentView->setEditTriggers(QAbstractItemView::DoubleClicked);  //ʹ��ɱ༭
}

void adminWindow::on_pushButton_7_clicked()
{
    //��Ȩ
    currentView->setEditTriggers(QAbstractItemView::DoubleClicked);  //ʹ��ɱ༭
}

void adminWindow::on_pushButton_12_clicked()
{
    //�Ǽ�
    currentView->setEditTriggers(QAbstractItemView::DoubleClicked);  //ʹ��ɱ༭
}

void adminWindow::on_pushButton_17_clicked()
{
    //����
    currentView->setEditTriggers(QAbstractItemView::DoubleClicked);  //ʹ��ɱ༭
}

void adminWindow::on_pushButton_22_clicked()
{
    //����
    currentView->setEditTriggers(QAbstractItemView::DoubleClicked);  //ʹ��ɱ༭
}

void adminWindow::on_pushButton_28_clicked()
{
    //��Ա
    currentView->setEditTriggers(QAbstractItemView::DoubleClicked);  //ʹ��ɱ༭
}

void adminWindow::on_pushButton_33_clicked()
{
    //���԰�
    currentView->setEditTriggers(QAbstractItemView::DoubleClicked);  //ʹ��ɱ༭
}
//����ҳ���޸İ�ť ����

//����ҳ��ɾ����ť
void adminWindow::on_pushButton_2_clicked()
{
    //¥��
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������
}

void adminWindow::on_pushButton_10_clicked()
{
    //��Ȩ
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������
}

void adminWindow::on_pushButton_15_clicked()
{
    //�Ǽ�
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������
}

void adminWindow::on_pushButton_20_clicked()
{
    //����
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������
}

void adminWindow::on_pushButton_25_clicked()
{
    //����
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������
}

void adminWindow::on_pushButton_29_clicked()
{
    //��Ա
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������
}

void adminWindow::on_pushButton_34_clicked()
{
    //���԰�
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������
}
//����ҳ��ɾ����ť ����

//����ҳ���ϴ���ť
void adminWindow::on_pushButton_5_clicked()
{
    //¥��
    currentTableModel->submitAll();

    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    on_pushButton_4_clicked();
}

void adminWindow::on_pushButton_9_clicked()
{
    //��Ȩ
    currentTableModel->submitAll();

    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    on_pushButton_6_clicked();
}

void adminWindow::on_pushButton_14_clicked()
{
    //�Ǽ�
    currentTableModel->submitAll();

    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    on_pushButton_11_clicked();
}

void adminWindow::on_pushButton_19_clicked()
{
    //����
    currentTableModel->submitAll();

    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭


    on_pushButton_16_clicked();
}

void adminWindow::on_pushButton_24_clicked()
{
    //����
    currentTableModel->submitAll();

    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    on_pushButton_21_clicked();
}

void adminWindow::on_pushButton_27_clicked()
{
    //��Ա
    currentTableModel->submitAll();

    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    on_pushButton_26_clicked();
}

void adminWindow::on_pushButton_31_clicked()
{
    //���԰�
    int rowNum = currentTableModel->rowCount(); //��ñ������
    int idNum = 0;
    QSqlQuery query;
    query.exec("select messageId from message");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    currentTableModel->insertRow(rowNum); //���һ��
    currentTableModel->setData(currentTableModel->index(rowNum, 0), idNum);
    currentTableModel->setData(currentTableModel->index(rowNum, 1), adminname);
    currentTableModel->setData(currentTableModel->index(rowNum, 2), ui->lineEdit->text());
    currentTableModel->setData(currentTableModel->index(rowNum, 3), ui->comboBox->currentIndex());
    currentTableModel->setData(currentTableModel->index(rowNum, 4), ui->textEdit->toPlainText());

    currentTableModel->submitAll();

    ui->label_5->setText(username);
    ui->lineEdit->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->textEdit->clear();

    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    on_pushButton_35_clicked();
}
//����ҳ���ϴ���ť ����

//����ҳ���б���
void adminWindow::on_tableView_clicked(const QModelIndex &index)
{
    //¥��
    int curCol = currentView->currentIndex().column(); //��ȡѡ�е���
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���

    QModelIndex indexData = currentTableModel->index(curRow, 3);   //���һ����¼��һ�����Ե�ֵ

    if (curCol < 3)
    {
        indexData = currentTableModel->index(curRow, 3);   //���һ����¼��һ�����Ե�ֵ
    }
    else
    {
        indexData = currentTableModel->index(curRow, curCol);   //���һ����¼��һ�����Ե�ֵ
    }
    qDebug() << indexData.data() << endl;

    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(indexData.data().toString()));
}

void adminWindow::on_tableView_2_clicked(const QModelIndex &index)
{
    //��Ȩ
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QModelIndex indexData = currentTableModel->index(curRow, 3);   //���һ����¼��һ�����Ե�ֵ
    qDebug() << indexData.data() << endl;

    ui->label_2->setScaledContents(true);
    ui->label_2->setPixmap(QPixmap(indexData.data().toString()));
}

void adminWindow::on_tableView_3_clicked(const QModelIndex &index)
{
    //�Ǽ�
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QModelIndex indexData = currentTableModel->index(curRow, 3);   //���һ����¼��һ�����Ե�ֵ
    qDebug() << indexData.data() << endl;

    ui->label_3->setScaledContents(true);
    ui->label_3->setPixmap(QPixmap(indexData.data().toString()));
}

void adminWindow::on_tableView_4_clicked(const QModelIndex &index)
{
    //����
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QModelIndex indexData = currentTableModel->index(curRow, 5);   //���һ����¼��һ�����Ե�ֵ
    qDebug() << indexData.data() << endl;

    ui->label_4->setScaledContents(true);
    ui->label_4->setPixmap(QPixmap(indexData.data().toString()));
}

void adminWindow::on_tableView_5_clicked(const QModelIndex &index)
{
    //����
}

void adminWindow::on_tableView_6_clicked(const QModelIndex &index)
{
    //��Ա
}

void adminWindow::on_tableView_7_clicked(const QModelIndex &index)
{
    //���԰�
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    ui->label_8->setText(currentTableModel->index(curRow, 1).data().toString());
    ui->lineEdit->setText(currentTableModel->index(curRow, 2).data().toString());
    ui->comboBox->setCurrentIndex(currentTableModel->index(curRow, 3).data().toInt());
    ui->textEdit->setPlainText(currentTableModel->index(curRow, 4).data().toString());
}
//����ҳ���б��� ����

//����ҳ���б�˫��
void adminWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    //¥��
    int curCol = currentView->currentIndex().column(); //��ȡѡ�е���

    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    int id = currentTableModel->record(curRow).value(0).toInt(); //��ȡѡ���е�id��
    QModelIndex indexData = currentTableModel->index(curRow, curCol);   //���һ����¼��һ�����Ե�ֵ
    qDebug() << indexData.data() << endl;

    QString sourcePath, targetPath;

    if (currentView->editTriggers() == QAbstractItemView::DoubleClicked) //����ǿɱ༭��ģʽ
    {
        switch (curCol)
        {
        case 0:
        case 1:
        case 2:
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            ui->label->setScaledContents(true);
            ui->label->setPixmap(QPixmap(indexData.data().toString()));

            sourcePath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
            if(sourcePath.length() == 0) {
                QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
            } else {
                QMessageBox::information(NULL, tr("Path"), tr("You selected ") + sourcePath);
            }

            targetPath = "house/" + QString::number(id, 10) + "." + QString::number(curCol, 10) + ".jpg";

            qDebug() << targetPath << endl;

            copyFileToPath(sourcePath, targetPath, true); //����ʽ����
            currentTableModel->setData(currentTableModel->index(curRow, curCol), targetPath);

            ui->label->setScaledContents(true);
            ui->label->setPixmap(QPixmap(targetPath));
            break;
        default:
            break;
        }
    }
    else
    {
        ;
    }
}

void adminWindow::on_tableView_2_doubleClicked(const QModelIndex &index)
{
    //��Ȩ
    int curCol = currentView->currentIndex().column(); //��ȡѡ�е���

    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    int id = currentTableModel->record(curRow).value(0).toInt(); //��ȡѡ���е�id��
    QModelIndex indexData = currentTableModel->index(curRow, curCol);   //���һ����¼��һ�����Ե�ֵ
    qDebug() << indexData.data() << endl;

    QString sourcePath, targetPath;

    if (currentView->editTriggers() == QAbstractItemView::DoubleClicked) //����ǿɱ༭��ģʽ
    {
        switch (curCol)
        {
        case 0:
        case 1:
        case 2:
            break;
        case 3:
            ui->label->setScaledContents(true);
            ui->label->setPixmap(QPixmap(indexData.data().toString()));

            sourcePath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
            if(sourcePath.length() == 0) {
                QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
            } else {
                QMessageBox::information(NULL, tr("Path"), tr("You selected ") + sourcePath);
            }

            targetPath = "house/" + QString::number(id, 10) + "." + QString::number(curCol, 10) + ".jpg";

            qDebug() << targetPath << endl;

            copyFileToPath(sourcePath, targetPath, true); //����ʽ����
            currentTableModel->setData(currentTableModel->index(curRow, curCol), targetPath);

            ui->label->setScaledContents(true);
            ui->label->setPixmap(QPixmap(targetPath));
            break;
        default:
            break;
        }
    }
    else
    {
        ;
    }
}

void adminWindow::on_tableView_3_doubleClicked(const QModelIndex &index)
{
    //�Ǽ�
    int curCol = currentView->currentIndex().column(); //��ȡѡ�е���

    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    int id = currentTableModel->record(curRow).value(0).toInt(); //��ȡѡ���е�id��
    QModelIndex indexData = currentTableModel->index(curRow, curCol);   //���һ����¼��һ�����Ե�ֵ
    qDebug() << indexData.data() << endl;

    QString sourcePath, targetPath;

    if (currentView->editTriggers() == QAbstractItemView::DoubleClicked) //����ǿɱ༭��ģʽ
    {
        switch (curCol)
        {
        case 0:
        case 1:
        case 2:
            break;
        case 3:
            ui->label->setScaledContents(true);
            ui->label->setPixmap(QPixmap(indexData.data().toString()));

            sourcePath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
            if(sourcePath.length() == 0) {
                QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
            } else {
                QMessageBox::information(NULL, tr("Path"), tr("You selected ") + sourcePath);
            }

            targetPath = "house/" + QString::number(id, 10) + "." + QString::number(curCol, 10) + ".jpg";

            qDebug() << targetPath << endl;

            copyFileToPath(sourcePath, targetPath, true); //����ʽ����
            currentTableModel->setData(currentTableModel->index(curRow, curCol), targetPath);

            ui->label->setScaledContents(true);
            ui->label->setPixmap(QPixmap(targetPath));
            break;
        default:
            break;
        }
    }
    else
    {
        ;
    }
}

void adminWindow::on_tableView_4_doubleClicked(const QModelIndex &index)
{
    //����
    int curCol = currentView->currentIndex().column(); //��ȡѡ�е���

    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    int id = currentTableModel->record(curRow).value(0).toInt(); //��ȡѡ���е�id��
    QModelIndex indexData = currentTableModel->index(curRow, curCol);   //���һ����¼��һ�����Ե�ֵ
    qDebug() << indexData.data() << endl;

    QString sourcePath, targetPath;

    if (currentView->editTriggers() == QAbstractItemView::DoubleClicked) //����ǿɱ༭��ģʽ
    {
        switch (curCol)
        {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            break;
        case 5:
            ui->label->setScaledContents(true);
            ui->label->setPixmap(QPixmap(indexData.data().toString()));

            sourcePath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
            if(sourcePath.length() == 0) {
                QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
            } else {
                QMessageBox::information(NULL, tr("Path"), tr("You selected ") + sourcePath);
            }

            targetPath = "house/" + QString::number(id, 10) + "." + QString::number(curCol, 10) + ".jpg";

            qDebug() << targetPath << endl;

            copyFileToPath(sourcePath, targetPath, true); //����ʽ����
            currentTableModel->setData(currentTableModel->index(curRow, curCol), targetPath);

            ui->label->setScaledContents(true);
            ui->label->setPixmap(QPixmap(targetPath));
            break;
        default:
            break;
        }
    }
    else
    {
        ;
    }
}

void adminWindow::on_tableView_5_doubleClicked(const QModelIndex &index)
{
    //����
}

void adminWindow::on_tableView_6_doubleClicked(const QModelIndex &index)
{
    //��Ա
}
//����ҳ���б�˫�� ����
