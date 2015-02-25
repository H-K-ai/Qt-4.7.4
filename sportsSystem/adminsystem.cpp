#include "adminsystem.h"
#include "ui_adminsystem.h"

adminSystem::adminSystem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminSystem)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);

    /*0 ��Ʒ��Ϣ
      1 �ֿ����
      2 ��Ա����
      3 �򿨼�¼
      4 Ա������ */
    tagFlag = 0;

    on_pushButton_clicked(); //ˢ�²ֿ�
}

adminSystem::~adminSystem()
{
    delete ui;
}

void adminSystem::on_pushButton_clicked()
{
    //��Ʒ����
    ui->groupBox_2->setTitle("��Ʒ����");
    tagFlag = 0;

    currentView = ui->tableView;

    currentTableModel->setTable("goods");
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->pushButton->setEnabled(true); //��Ӱ�ť����

    ui->label->clear(); //���label
    ui->label_2->clear(); //���label
}

void adminSystem::on_pushButton_2_clicked()
{
    //�ֿ����
    ui->groupBox_2->setTitle("�ֿ����");
    tagFlag = 1;

    currentView = ui->tableView;

    currentTableModel->setTable("depot");
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->label->clear(); //���label
    ui->label_2->clear(); //���label
}

void adminSystem::on_pushButton_3_clicked()
{
    //��Ա����
    ui->groupBox_2->setTitle("��Ա����");
    tagFlag = 2;

    currentView = ui->tableView;

    currentTableModel->setTable("member");
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->label->clear(); //���label
    ui->label_2->clear(); //���label
}

void adminSystem::on_pushButton_4_clicked()
{
    //�򿨼�¼
    ui->groupBox_2->setTitle("�򿨼�¼");
    tagFlag = 3;

    currentView = ui->tableView;

    currentTableModel->setTable("punch");
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->label->clear(); //���label
    ui->label_2->clear(); //���label
}

void adminSystem::on_pushButton_5_clicked()
{
    //Ӫҵ���¼
    tWindows.show();
}

void adminSystem::on_pushButton_6_clicked()
{
    //Ա������
    ui->groupBox_2->setTitle("�򿨼�¼");
    tagFlag = 4;

    currentView = ui->tableView;

    currentTableModel->setTable("person");
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->label->clear(); //���label
    ui->label_2->clear(); //���label
}

void adminSystem::on_pushButton_7_clicked()
{
    //�����Ϣ
    int rowNum, id;
    QString sourcePath, targetPath;

    rowNum = currentTableModel->rowCount(); //��ñ������
    id = currentTableModel->record(rowNum - 1).value(0).toInt() + 1;

    currentView->setEditTriggers(QAbstractItemView::DoubleClicked);  //ʹ��ɱ༭
    currentTableModel->insertRow(rowNum); //���һ��
    currentTableModel->setData(currentTableModel->index(rowNum, 0), id);

    switch(tagFlag)
    {
    case 0:
        sourcePath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
        if(sourcePath.length() == 0) {
            QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
            on_pushButton_clicked();
            return;
        } else {
            QMessageBox::information(NULL, tr("Path"), tr("You selected ") + sourcePath);
            ui->pushButton_7->setEnabled(false); //��Ӱ�ť�û�
        }

        targetPath = "goods/" + QString::number(id, 10) + ".jpg";

        currentTableModel->setData(currentTableModel->index(rowNum, 4), targetPath);

        break;
    case 1:
        sourcePath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
        if(sourcePath.length() == 0) {
            QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
            on_pushButton_2_clicked();
            return;
        } else {
            QMessageBox::information(NULL, tr("Path"), tr("You selected ") + sourcePath);
            ui->pushButton_7->setEnabled(false); //��Ӱ�ť�û�
        }

        targetPath = "depot/" + QString::number(id, 10) + ".jpg";

        currentTableModel->setData(currentTableModel->index(rowNum, 4), targetPath);
        break;
    case 2:
        sourcePath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
        if(sourcePath.length() == 0) {
            QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
            on_pushButton_3_clicked();
            return;
        } else {
            QMessageBox::information(NULL, tr("Path"), tr("You selected ") + sourcePath);
            ui->pushButton_7->setEnabled(false); //��Ӱ�ť�û�
        }

        targetPath = "member/" + QString::number(id, 10) + ".jpg";

        currentTableModel->setData(currentTableModel->index(rowNum, 3), targetPath);
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }

    copyFileToPath(sourcePath, targetPath, true); //����ʽ����

    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(targetPath));
}

void adminSystem::on_pushButton_8_clicked()
{
    //ɾ����Ϣ
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������
}

void adminSystem::on_pushButton_9_clicked()
{
    //�޸���Ϣ
    currentView->setEditTriggers(QAbstractItemView::DoubleClicked);  //ʹ��ɱ༭
}

void adminSystem::on_pushButton_10_clicked()
{
    //�ύ��Ϣ
    currentTableModel->submitAll();

    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    on_pushButton_11_clicked();
}

void adminSystem::on_pushButton_11_clicked()
{
    //ˢ����Ϣ
    currentView = ui->tableView;

    switch(tagFlag)
    {
    case 0:
        currentTableModel->setTable("goods");
        break;
    case 1:
        currentTableModel->setTable("depot");
        break;
    case 2:
        currentTableModel->setTable("member");
        break;
    case 3:
        currentTableModel->setTable("punch");
        break;
    case 4:
        currentTableModel->setTable("person");
        break;
    default:
        break;
    }
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->pushButton_7->setEnabled(true); //��Ӱ�ť����
}


void adminSystem::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    QString labelInfo;
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QModelIndex indexData;
    switch(tagFlag)
    {
    case 0:
        indexData = currentTableModel->index(curRow, 4);   //���һ����¼��һ�����Ե�ֵ
        labelInfo = " ��Ʒ���� : " + currentTableModel->index(curRow, 1).data().toString()
                + "\n\n ��Ʒ���� : " + currentTableModel->index(curRow, 2).data().toString()
                + "\n\n ʣ����� : " + currentTableModel->index(curRow, 3).data().toString();
        break;
    case 1:
        indexData = currentTableModel->index(curRow, 4);   //���һ����¼��һ�����Ե�ֵ
        labelInfo = " ��Ʒ���� : " + currentTableModel->index(curRow, 1).data().toString()
                + "\n\n ��Ʒ���� : " + currentTableModel->index(curRow, 2).data().toString()
                + "\n\n ʣ����� : " + currentTableModel->index(curRow, 3).data().toString();
        break;
    case 2:
        indexData = currentTableModel->index(curRow, 3);   //���һ����¼��һ�����Ե�ֵ
        labelInfo = " ��Ա��� : " + currentTableModel->index(curRow, 0).data().toString()
                + "\n\n ��Ա���� : " + currentTableModel->index(curRow, 1).data().toString()
                + "\n\n ���Ѷ�� : " + currentTableModel->index(curRow, 2).data().toString();
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }
    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(indexData.data().toString()));

    ui->label_2->setText(labelInfo);
}



void adminSystem::on_tableView_doubleClicked(const QModelIndex &index)
{
    //�б�˫��
    int curCol = currentView->currentIndex().column(); //��ȡѡ�е���
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    int id = currentTableModel->record(curRow).value(0).toInt(); //��ȡѡ���е�id��
    int picFlag = false;
    QModelIndex indexData = currentTableModel->index(curRow, curCol);   //���һ����¼��һ�����Ե�ֵ
    qDebug() << indexData.data() << endl;

    QString sourcePath, targetPath;

    if (currentView->editTriggers() == QAbstractItemView::DoubleClicked) //����ǿɱ༭��ģʽ
    {
        switch(tagFlag)
        {
        case 0:
            if (curCol == 4)
            {
                picFlag = true;
            }
            targetPath = "goods/" + QString::number(id, 10) + ".jpg";
            break;
        case 1:
            if (curCol == 4)
            {
                picFlag = true;
            }
            targetPath = "depot/" + QString::number(id, 10) + ".jpg";
            break;
        case 2:
            if (curCol == 3)
            {
                picFlag = true;
            }
            targetPath = "member/" + QString::number(id, 10) + ".jpg";
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
        }

        if (picFlag == true)
        {
            ui->label->setScaledContents(true);
            ui->label->setPixmap(QPixmap(indexData.data().toString()));

            sourcePath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
            if(sourcePath.length() == 0) {
                QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
            } else {
                QMessageBox::information(NULL, tr("Path"), tr("You selected ") + sourcePath);
            }

            copyFileToPath(sourcePath, targetPath, true); //����ʽ����
            currentTableModel->setData(currentTableModel->index(curRow, curCol), targetPath);

            ui->label->setScaledContents(true);
            ui->label->setPixmap(QPixmap(targetPath));
        }
    }
    else
    {
        ;
    }
}

void adminSystem::on_pushButton_12_clicked()
{
    //�˳���¼
    this->close();
    emit exitLogin();
}

void adminSystem::paintEvent(QPaintEvent *)
{
    //����ͼƬ
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/png/1.png").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

