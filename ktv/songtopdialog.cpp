#include "songtopdialog.h"
#include "ui_songtopdialog.h"

songTopDialog::songTopDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::songTopDialog)
{
    ui->setupUi(this);
    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    currentTableModel->setTable("songsLibrary");
    currentTableModel->select(); //ѡȡ�������������

    currentTableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("������"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("������"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("�������"));

    currentTableModel->removeColumn(4);
    currentTableModel->removeColumn(0);

    currentView->setModel(currentTableModel);
    currentView->sortByColumn(2);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭
}

songTopDialog::~songTopDialog()
{
    delete ui;
}

void songTopDialog::paintEvent(QPaintEvent *)
{
    //����ͼƬ
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/png/5.png").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}
