#include "mainwindow.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);

    currentView = ui->tableView_3;

    foodItemUpdate();
    cookbookItemUpdate();
    sportsItemUpdate();

    ui->label->clear();
    ui->label_2->clear();
    ui->label_3->clear();
}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/png/bj2.png").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void mainWindow::on_pushButton_clicked()
{
    //ʳ���
    ui->tabWidget->setCurrentIndex(0);
}

void mainWindow::on_pushButton_2_clicked()
{
    //�˶���
    ui->tabWidget->setCurrentIndex(2);
}

void mainWindow::on_pushButton_3_clicked()
{
    //��¼��ʳ
    recDlg.show();
}

void mainWindow::on_pushButton_4_clicked()
{
    //��¼�˶�
    recDlg.show();
}

void mainWindow::on_pushButton_6_clicked()
{
    //��¼����
    weiDlg.show();
}

void mainWindow::on_pushButton_5_clicked()
{
    //��ʷ��¼
    hisDlg.show();
}

void mainWindow::on_pushButton_7_clicked()
{
    //����ָ��
    bmiDlg = new bmiDialog;
    bmiDlg->show();
}

void mainWindow::on_pushButton_8_clicked()
{
    //��׼����
    stdwDlg = new stdweightDialog;
    stdwDlg->show();
}

void mainWindow::on_pushButton_9_clicked()
{
    //�����ά
    sizeDlg = new sizeDialog;
    sizeDlg->show();
}

void mainWindow::on_pushButton_10_clicked()
{
    //��·��ת����
    calDlg = new calorieDialog;
    calDlg->show();
}

void mainWindow::on_pushButton_11_clicked()
{
    //��̨���
    adminDlg.show();
}

void mainWindow::on_tableWidget_clicked(const QModelIndex &index)
{
    //ʳ���б���
    QString sortStr = ui->tableWidget->currentItem()->text();  //���һ����¼��һ�����Ե�ֵ
    qDebug() << sortStr << endl;

    currentTableModel->setTable("food");
    currentTableModel->setFilter("category = '" + sortStr + "'");
    currentTableModel->removeColumn(0); //ȡ����������ʾ

    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭
}

void mainWindow::on_tableWidget_2_clicked(const QModelIndex &index)
{
    //ʳ���б���
    QString sortStr = ui->tableWidget_2->currentItem()->text();  //���һ����¼��һ�����Ե�ֵ

    currentTableModel->setTable("cookbook");
    currentTableModel->setFilter("category = '" + sortStr + "'");
    currentTableModel->removeColumn(0);

    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭
}

void mainWindow::on_tableWidget_4_clicked(const QModelIndex &index)
{
    //�˶��б���
    QString sortStr = ui->tableWidget_4->currentItem()->text();  //���һ����¼��һ�����Ե�ֵ

    currentTableModel->setTable("sports");
    currentTableModel->setFilter("category = '" + sortStr + "'");
    currentTableModel->removeColumn(0);

    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭
}

void mainWindow::on_tableView_3_clicked(const QModelIndex &index)
{
    //�Ҳ��б���
    QString labelInfo;
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QModelIndex indexData = currentTableModel->index(curRow, 4);   //���һ����¼��һ�����Ե�ֵ
    labelInfo = "���� : " + currentTableModel->index(curRow, 1).data().toString()
            + "ǧ��/100��\n\nָ�� : " + currentTableModel->index(curRow, 2).data().toString()
            + "\n\n���� : " + currentTableModel->index(curRow, 3).data().toString();

    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(indexData.data().toString()));

    ui->label_2->setText(currentTableModel->index(curRow, 1).data().toString());
    ui->label_3->setText(labelInfo);
}

void mainWindow::foodItemUpdate()
{
    //���ʳ���������
    int i = 0;
    //����һ���ϴ���к�
    ui->tableWidget->setRowCount(100);

    ui->tableWidget->setItem(i++,0,new QTableWidgetItem(QString("����")));
    ui->tableWidget->setItem(i++,0,new QTableWidgetItem(QString("������")));
    ui->tableWidget->setItem(i++,0,new QTableWidgetItem(QString("�ɶ�")));
    ui->tableWidget->setItem(i++,0,new QTableWidgetItem(QString("�߲�")));
    ui->tableWidget->setItem(i++,0,new QTableWidgetItem(QString("����")));
    ui->tableWidget->setItem(i++,0,new QTableWidgetItem(QString("ˮ��")));
    ui->tableWidget->setItem(i++,0,new QTableWidgetItem(QString("�������")));
    ui->tableWidget->setItem(i++,0,new QTableWidgetItem(QString("����")));
    ui->tableWidget->setItem(i++,0,new QTableWidgetItem(QString("����")));
    ui->tableWidget->setItem(i++,0,new QTableWidgetItem(QString("����")));
    ui->tableWidget->setItem(i++,0,new QTableWidgetItem(QString("����")));
    ui->tableWidget->setItem(i++,0,new QTableWidgetItem(QString("��Ϻз��")));
    ui->tableWidget->setItem(i++,0,new QTableWidgetItem(QString("Ӥ�׶�ʳƷ")));
    ui->tableWidget->setItem(i++,0,new QTableWidgetItem(QString("С�����")));
    ui->tableWidget->setItem(i++,0,new QTableWidgetItem(QString("��ʳʳƷ")));
    ui->tableWidget->setItem(i++,0,new QTableWidgetItem(QString("������")));
    ui->tableWidget->setItem(i++,0,new QTableWidgetItem(QString("�ƾ�����")));
    ui->tableWidget->setItem(i++,0,new QTableWidgetItem(QString("���۽�")));
    ui->tableWidget->setItem(i++,0,new QTableWidgetItem(QString("��֬")));
    ui->tableWidget->setItem(i++,0,new QTableWidgetItem(QString("��ζƷ")));
    ui->tableWidget->setItem(i++,0,new QTableWidgetItem(QString("ҩʳ������")));

    //����Ϊ��������
    ui->tableWidget->setRowCount(i);
    ui->tableWidget->setColumnWidth(0, ui->tableWidget->width());
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    //ȥ��tableWidget�Դ����к�
    QHeaderView* headerView = ui->tableWidget->verticalHeader();
    headerView->setHidden(true);
}

void mainWindow::cookbookItemUpdate()
{
    //���ʳ�׷�������
    int i = 0;
    ui->tableWidget_2->setRowCount(100);

    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("˽�Ҳ�")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("�ҳ���")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("������")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("����")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("���ϲ�")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("���ղ�")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("������")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("ɽ����")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("�Ϻ���")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("�����")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("�Ĵ���")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("������")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("������")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("���ݲ�")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("�㽭��")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("���ϲ�")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("��ի��")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("ɽ����")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("������")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("�����")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("�㶫��")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("���ղ�")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("������")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("��ǭ��")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("̨���")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("���ϲ�")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("�½���")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("������")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("���Ĳ�")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("�ຣ��")));
    ui->tableWidget_2->setItem(i++,0,new QTableWidgetItem(QString("������")));

    ui->tableWidget_2->setRowCount(i);
    ui->tableWidget_2->setColumnWidth(0, ui->tableWidget_2->width());
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    QHeaderView* headerView = ui->tableWidget_2->verticalHeader();
    headerView->setHidden(true);
}
void mainWindow::sportsItemUpdate()
{
    //����˶���������
    int i = 0;
    ui->tableWidget_4->setRowCount(100);

    ui->tableWidget_4->setItem(i++,0,new QTableWidgetItem(QString("��������")));
    ui->tableWidget_4->setItem(i++,0,new QTableWidgetItem(QString("��·")));
    ui->tableWidget_4->setItem(i++,0,new QTableWidgetItem(QString("����ѵ��")));
    ui->tableWidget_4->setItem(i++,0,new QTableWidgetItem(QString("�赸")));
    ui->tableWidget_4->setItem(i++,0,new QTableWidgetItem(QString("���г��˶�")));
    ui->tableWidget_4->setItem(i++,0,new QTableWidgetItem(QString("ˮ���˶�")));
    ui->tableWidget_4->setItem(i++,0,new QTableWidgetItem(QString("�ճ��˶�")));
    ui->tableWidget_4->setItem(i++,0,new QTableWidgetItem(QString("����")));
    ui->tableWidget_4->setItem(i++,0,new QTableWidgetItem(QString("����")));
    ui->tableWidget_4->setItem(i++,0,new QTableWidgetItem(QString("԰���˶�")));
    ui->tableWidget_4->setItem(i++,0,new QTableWidgetItem(QString("����")));
    ui->tableWidget_4->setItem(i++,0,new QTableWidgetItem(QString("�����˶�")));
    ui->tableWidget_4->setItem(i++,0,new QTableWidgetItem(QString("�ܲ�")));

    ui->tableWidget_4->setRowCount(i);
    ui->tableWidget_4->setColumnWidth(0, ui->tableWidget_4->width());
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    QHeaderView* headerView = ui->tableWidget_4->verticalHeader();
    headerView->setHidden(true);
}

void mainWindow::on_pushButton_12_clicked()
{
    //�޸�����
    pwdDlg.show();
}
