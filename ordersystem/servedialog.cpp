#include "servedialog.h"
#include "ui_servedialog.h"
#include<QComboBox>
#include<QDebug>
#include<QSqlQuery>
#include <QPushButton>
#include <QModelIndex>
#include <QMap>
#include <QWidget>
#include "dishlist.h"
serveDialog::serveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::serveDialog)
{
    ui->setupUi(this);
    init();
    show_desk_status();
    QPalette   palette;
    QPixmap pixmap("resource/4.jpg");
    palette.setBrush(backgroundRole(),QBrush(pixmap));
    setPalette(palette);

}

serveDialog::~serveDialog()
{
    delete ui;
}

void serveDialog::status_change(int x)
{
    desk_sta_map.insert(ui->table->currentRow()+1,x);
    //desk_sta_map.insert(ui->table->currentRow()+1,)
    show_desk_status();
    ui->table->setCurrentCell(0,0);
    ui->table->setFocus(Qt::OtherFocusReason);
}

void serveDialog::show_desk_status()
{
    ui->table->clear();
    ui->table->setRowCount(0);
    ui->table->setColumnCount(3);
    QStringList headers;
    headers<<"����"<<"״̬"<<"���";
    ui->table->setColumnWidth(0, 180);
    ui->table->setColumnWidth(1, 180);
    ui->table->setColumnWidth(2, 180);
    ui->table->setHorizontalHeaderLabels(headers);
    ui->table->verticalHeader()->setVisible(false);
    ui->table->horizontalHeader()->setVisible(true);
    //��ʾ����
    QMap<int,int>::Iterator it=desk_sta_map.begin();
    int i=0;
    while(it!=desk_sta_map.end())
    {
        ui->table->insertRow(ui->table->rowCount());
        QComboBox *sta=new QComboBox();
        sta->addItem("����");
        sta->addItem("ʹ����");
        sta->addItem("Ԥ��");
        QPushButton *but=new QPushButton();
        but->setText("���");
        connect(but,SIGNAL(clicked()),this,SLOT(push_but()));
        int role=it.value();
        if(role==0)
        {
            sta->setCurrentIndex(0);
            but->setDisabled(true);
        }
        else if(role==1)
        {
            sta->setCurrentIndex(1);
        }
        else
        {
            sta->setCurrentIndex(2);
        }
        connect(sta,SIGNAL(currentIndexChanged(int)),this,SLOT(status_change(int)));
        ui->table->setCellWidget(i,2,but);
        QString dno=QString::number(it.key(),10);
        ui->table->setItem(i,0,new QTableWidgetItem(dno));
        ui->table->setCellWidget(i,1,sta);
        i++;
        it++;
    }
    ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers );
}

void serveDialog::init()
{
    QSqlQuery query;//�����ݿ��ж�ȡ������Ϣ���뵽�ڴ�desk_sta_map��
    query.exec("select *from desk");
    int i=1;
    while(query.next())
    {
        desk_sta_map.insert(query.value(0).toInt(),query.value(1).toInt());
        QVector<int> abc;
        desk_dish_map.insert(i++,abc);
    }
}

void serveDialog::push_but()
{
    int index_c=ui->table->currentColumn();
    int index_r=ui->table->currentRow();
    ui->table->setCurrentCell(0,0);
    ui->table->setFocus(Qt::OtherFocusReason);
    QVector<int> list;
    list=desk_dish_map.value(index_r+1);
    dishlist d;
    d.set_list(list,index_r+1);//���������QVector<int>,����)
    d.exec();
    if(d.close())
    {
        d.save_Table();
        list=d.get_list();
    }
    //�رյ��
    desk_dish_map.insert(index_r+1,list);
}

