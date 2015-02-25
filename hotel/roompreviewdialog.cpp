#include "roompreviewdialog.h"
#include "ui_roompreviewdialog.h"

roomPreviewDialog::roomPreviewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::roomPreviewDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlRelationalTableModel(this);
    currentView = ui->tableView;

    on_pushButton_5_clicked();

    ui->label->clear();
}

roomPreviewDialog::~roomPreviewDialog()
{
    delete ui;
}

void roomPreviewDialog::on_pushButton_clicked()
{
    //�½�
    int rowNum = currentTableModel->rowCount(); //��ñ������
    int id = currentTableModel->record(rowNum - 1).value(0).toInt() + 1;
    currentView->setEditTriggers(QAbstractItemView::DoubleClicked);  //ʹ��ɱ༭
    currentTableModel->insertRow(rowNum); //���һ��
    currentTableModel->setData(currentTableModel->index(rowNum, 0), id);
    currentTableModel->setData(currentTableModel->index(rowNum, 1), 0);

    QString sourcePath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
    if(sourcePath.length() == 0) {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
    } else {
        QMessageBox::information(NULL, tr("Path"), tr("You selected ") + sourcePath);
    }

    QString targetPath = "room/" + QString::number(id, 10) + "." + "2.jpg";

    copyFileToPath(sourcePath, targetPath, true); //����ʽ����
    currentTableModel->setData(currentTableModel->index(rowNum, 2), targetPath);

    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(targetPath));
}

void roomPreviewDialog::on_pushButton_2_clicked()
{
    //�޸�
    currentView->setEditTriggers(QAbstractItemView::DoubleClicked);  //ʹ��ɱ༭
}

void roomPreviewDialog::on_pushButton_3_clicked()
{
    //ɾ��
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������
}

void roomPreviewDialog::on_pushButton_4_clicked()
{
    //�ύ
    currentTableModel->submitAll();

    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    on_pushButton_5_clicked();
}

void roomPreviewDialog::on_pushButton_5_clicked()
{
    //ˢ��
    currentTableModel->setTable("room");
    currentTableModel->setRelation(1, QSqlRelation("roomstatus", "roomstatusid", "status"));
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setItemDelegate(new QSqlRelationalDelegate(currentView));
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    ui->label->clear();
}

void roomPreviewDialog::on_pushButton_6_clicked()
{
    //��һ��
    if (picCol <= 2)
    {
        picCol = 4;
    }
    else
    {
        picCol--;
    }
    QModelIndex indexData = currentTableModel->index(picRow, picCol);   //���һ����¼��һ�����Ե�ֵ

    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(indexData.data().toString()));
}

void roomPreviewDialog::on_pushButton_7_clicked()
{
    //��һ��
    if (picCol < 2)
    {
        picCol = 3;
    }
    else if (picCol >= 4)
    {
        picCol = 2;
    }
    else
    {
        picCol++;
    }
    QModelIndex indexData = currentTableModel->index(picRow, picCol);   //���һ����¼��һ�����Ե�ֵ

    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(indexData.data().toString()));
}

void roomPreviewDialog::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    int curCol = currentView->currentIndex().column(); //��ȡѡ�е���
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���

    picCol = currentView->currentIndex().column(); //��ȡѡ�е���
    picRow = currentView->currentIndex().row(); //��ȡѡ�е���

    QModelIndex indexData = currentTableModel->index(curRow, 3);   //���һ����¼��һ�����Ե�ֵ

    if (curCol < 2)
    {
        indexData = currentTableModel->index(curRow, 2);   //���һ����¼��һ�����Ե�ֵ
    }
    else
    {
        indexData = currentTableModel->index(curRow, curCol);   //���һ����¼��һ�����Ե�ֵ
    }

    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(indexData.data().toString()));
}

void roomPreviewDialog::on_tableView_doubleClicked(const QModelIndex &index)
{
    //�б�˫��
    int curCol = currentView->currentIndex().column(); //��ȡѡ�е���
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    int id = currentTableModel->record(curRow).value(0).toInt(); //��ȡѡ���е�id��
    QModelIndex indexData = currentTableModel->index(curRow, curCol);   //���һ����¼��һ�����Ե�ֵ

    QString sourcePath, targetPath;

    if (currentView->editTriggers() == QAbstractItemView::DoubleClicked) //����ǿɱ༭��ģʽ
    {
        switch (curCol)
        {
        case 0:
        case 1:
            break;
        case 2:
        case 3:
        case 4:
            ui->label->setScaledContents(true);
            ui->label->setPixmap(QPixmap(indexData.data().toString()));

            sourcePath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
            if(sourcePath.length() == 0) {
                QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
            } else {
                QMessageBox::information(NULL, tr("Path"), tr("You selected ") + sourcePath);
            }

            targetPath = "room/" + QString::number(id, 10) + "." + QString::number(curCol, 10) + ".jpg";

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
