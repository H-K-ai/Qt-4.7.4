#include "keepersystem.h"
#include "ui_keepersystem.h"

keeperSystem::keeperSystem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::keeperSystem)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);

    on_pushButton_5_clicked();
}

keeperSystem::~keeperSystem()
{
    delete ui;
}

void keeperSystem::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    QString labelInfo;
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QModelIndex indexData = currentTableModel->index(curRow, 4);   //���һ����¼��һ�����Ե�ֵ
    labelInfo = " ��Ʒ���� : " + currentTableModel->index(curRow, 1).data().toString()
            + "\n\n ��Ʒ���� : " + currentTableModel->index(curRow, 2).data().toString()
            + "\n\n ʣ����� : " + currentTableModel->index(curRow, 3).data().toString();

    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(indexData.data().toString()));

    ui->label_2->setText(labelInfo);
}

void keeperSystem::on_tableView_doubleClicked(const QModelIndex &index)
{
    //�б�˫��
    int curCol = currentView->currentIndex().column(); //��ȡѡ�е���
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    int id = currentTableModel->record(curRow).value(0).toInt(); //��ȡѡ���е�id��

    QModelIndex indexData = currentTableModel->index(curRow, curCol);   //���һ����¼��һ�����Ե�ֵ
    qDebug() << indexData.data() << endl;

    QString sourcePath, targetPath;

    if (currentView->editTriggers() == QAbstractItemView::DoubleClicked) //����ǿɱ༭��ģʽ
    {
        if (curCol == 4)
        {
            targetPath = "depot/" + QString::number(id, 10) + ".jpg";
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

void keeperSystem::on_pushButton_clicked()
{
    //���
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

    QString targetPath = "depot/" + QString::number(id, 10) + ".jpg";

    qDebug() << targetPath << endl;

    copyFileToPath(sourcePath, targetPath, true); //����ʽ����
    currentTableModel->setData(currentTableModel->index(rowNum, 4), targetPath);

    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(targetPath));
    ui->label_2->clear();
}

void keeperSystem::on_pushButton_2_clicked()
{
    //ɾ��
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������
}

void keeperSystem::on_pushButton_3_clicked()
{
    //�޸�
    currentView->setEditTriggers(QAbstractItemView::DoubleClicked);  //ʹ��ɱ༭
}

void keeperSystem::on_pushButton_4_clicked()
{
    //�ύ
    currentTableModel->submitAll();

    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    on_pushButton_5_clicked();
}

void keeperSystem::on_pushButton_5_clicked()
{
    //ˢ��
    currentView = ui->tableView;

    currentTableModel->setTable("depot");
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->pushButton->setEnabled(true); //��Ӱ�ť����

    ui->label->clear(); //���label
    ui->label_2->clear(); //���label
}

void keeperSystem::on_pushButton_6_clicked()
{
    //�˳���¼
    this->close();
    emit exitLogin();
}

void keeperSystem::paintEvent(QPaintEvent *)
{
    //����ͼƬ
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/png/2.png").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}
