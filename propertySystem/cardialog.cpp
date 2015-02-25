#include "cardialog.h"
#include "ui_cardialog.h"

carDialog::carDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::carDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlRelationalTableModel(this);
    currentView = ui->tableView;

    on_pushButton_3_clicked();

    QHeaderView* headerView = currentView->verticalHeader();
    headerView->setHidden(true); //�����к�
}

carDialog::~carDialog()
{
    delete ui;
}

void carDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/jpg/2.jpg").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void carDialog::on_pushButton_clicked()
{
    //��ӳ�λ
    int rowNum = currentTableModel->rowCount(); //��ñ������
    int id = currentTableModel->record(rowNum - 1).value(0).toInt() + 1;

    currentTableModel->insertRow(rowNum); //���һ��
    currentTableModel->setData(currentTableModel->index(rowNum, 0), id);
    currentTableModel->setData(currentTableModel->index(rowNum, 1), 0);

    ui->pushButton->setEnabled(false);
}

void carDialog::on_pushButton_2_clicked()
{
    //ɾ����λ
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������
}

void carDialog::on_pushButton_3_clicked()
{
    //ˢ�µ�ǰ
    currentTableModel->setTable("park");
    currentTableModel->setRelation(1, QSqlRelation("parkstatus", "parkstatusid", "status"));
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setItemDelegate(new QSqlRelationalDelegate(currentView));

    ui->pushButton->setEnabled(true);
}

void carDialog::on_pushButton_4_clicked()
{
    //�ύ�޸�
    currentTableModel->submitAll();

    ui->pushButton->setEnabled(true);
}
