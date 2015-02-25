#include "historydialog.h"
#include "ui_historydialog.h"

historyDialog::historyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::historyDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);

    currentView = ui->tableView;

    ui->dateEdit->setDate(QDate::currentDate());
}

historyDialog::~historyDialog()
{
    delete ui;
}

void historyDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/png/bj51.png").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}
void historyDialog::on_pushButton_clicked()
{
    //��ѯ
    QString weightStr;
    int intakeInt = 0;
    int sportInt = 0;
    QString sql;
    QSqlQuery query;

    sql = "select weight from weightrecord where date = '" + ui->dateEdit->date().toString("dd.MM.yyyy") + "'";
    query.exec(sql);
    while(query.next())
    {
        weightStr = query.value(0).toString();
    }
    ui->label->setText("���� : " + weightStr + " KG");

    sql = "select calories, calvariable, category from calrecord where date = '" + ui->dateEdit->date().toString("dd.MM.yyyy") + "'";
    query.exec(sql);
    while(query.next())
    {
        if(query.value(2).toInt() == 2)
        {
            //sports
            sportInt += query.value(0).toInt()*query.value(1).toInt();
        }
        else
        {
            intakeInt += query.value(0).toInt()*query.value(1).toInt()/100;
        }
    }

    ui->label_2->setText("���� : " + QString::number(intakeInt, 10) + " ǧ��");
    ui->label_3->setText("�˶� : " + QString::number(sportInt, 10) + " ǧ��");

    currentTableModel->setTable("calrecord");
    currentTableModel->setFilter("date = '" + ui->dateEdit->date().toString("dd.MM.yyyy") + "'");
    currentTableModel->removeColumn(0);

    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭
}
