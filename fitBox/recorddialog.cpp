#include "recorddialog.h"
#include "ui_recorddialog.h"

recordDialog::recordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recordDialog)
{
    ui->setupUi(this);

    currentTableModel_1 = new QSqlTableModel(this);
    currentTableModel_2 = new QSqlTableModel(this);
    currentView_1 = ui->tableView;
    currentView_2 = ui->tableView_2;

    ui->label->clear();
    ui->label_2->clear();
    ui->label_5->setText("���� : ");
    ui->label_6->setText("��");
    ui->dateEdit->setDate(QDate::currentDate());
}

recordDialog::~recordDialog()
{
    delete ui;
}
void recordDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/png/bj2.png").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void recordDialog::on_comboBox_currentIndexChanged(int index)
{
    //ѡ��任
    ui->label->clear();
    ui->label_2->clear();
    ui->label_5->setText("���� : ");
    ui->label_6->setText("��");
    ui->dateEdit->setDate(QDate::currentDate());
}

void recordDialog::on_dateEdit_dateChanged(const QDate &date)
{
    //���ڱ任
    currentTableModel_2->setTable("calrecord");
    currentTableModel_2->setFilter("date = '" + ui->dateEdit->date().toString("dd.MM.yyyy") + "'");
    currentTableModel_2->select(); //ѡȡ�������������

    currentView_2->setModel(currentTableModel_2);
    currentView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭
}

void recordDialog::on_pushButton_clicked()
{
    //����
    QString titleStr = ui->lineEdit->text().trimmed();
    switch(ui->comboBox->currentIndex())
    {
    case 0:
        currentTableModel_1->setTable("food");
        currentTableModel_1->setFilter("name like '%" + titleStr + "%'");
        currentTableModel_1->select(); //ѡȡ�������������

        currentView_1->setModel(currentTableModel_1);
        currentView_1->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭
        break;
    case 1:
        currentTableModel_1->setTable("cookbook");
        currentTableModel_1->setFilter("name like '%" + titleStr + "%'");
        currentTableModel_1->select(); //ѡȡ�������������

        currentView_1->setModel(currentTableModel_1);
        currentView_1->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭
        break;
    case 2:
        currentTableModel_1->setTable("sports");
        currentTableModel_1->setFilter("name like '%" + titleStr + "%'");
        currentTableModel_1->select(); //ѡȡ�������������

        currentView_1->setModel(currentTableModel_1);
        currentView_1->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭
        break;
    default:
        break;
    }
}

void recordDialog::on_pushButton_2_clicked()
{
    //���
    int idNum = 0;
    int curRow = currentView_1->currentIndex().row(); //��ȡѡ�е���

    QString sql;
    QSqlQuery query;

    sql = "select calrecordid from calrecord";
    query.exec(sql);
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    if(ui->lineEdit_2->text().trimmed().toInt() > 0)
    {
        switch(ui->comboBox->currentIndex())
        {
        case 0:
            sql = "insert into calrecord values ('"
                    + QString::number(idNum, 10) + "', '"
                    + currentTableModel_1->index(curRow, 1).data().toString() + "', '"
                    + currentTableModel_1->index(curRow, 2).data().toString() + "', '"
                    + ui->lineEdit_2->text().trimmed() + "', '"
                    + QString::number(ui->comboBox->currentIndex(), 10) + "', '"
                    + ui->dateEdit->date().toString("dd.MM.yyyy") + "')";
            query.exec(sql);
            currentTableModel_2->select(); //ˢ��
            break;
        case 1:
            sql = "insert into calrecord values ('"
                    + QString::number(idNum, 10) + "', '"
                    + currentTableModel_1->index(curRow, 1).data().toString() + "', '"
                    + currentTableModel_1->index(curRow, 2).data().toString() + "', '"
                    + ui->lineEdit_2->text().trimmed() + "', '"
                    + QString::number(ui->comboBox->currentIndex(), 10) + "', '"
                    + ui->dateEdit->date().toString("dd.MM.yyyy") + "')";
            query.exec(sql);
            currentTableModel_2->select();
            break;
        case 2:
            sql = "insert into calrecord values ('"
                    + QString::number(idNum, 10) + "', '"
                    + currentTableModel_1->index(curRow, 1).data().toString() + "', '"
                    + currentTableModel_1->index(curRow, 2).data().toString() + "', '"
                    + ui->lineEdit_2->text().trimmed() + "', '"
                    + QString::number(ui->comboBox->currentIndex(), 10) + "', '"
                    + ui->dateEdit->date().toString("dd.MM.yyyy") + "')";
            query.exec(sql);
            currentTableModel_2->select();
            break;
        default:
            break;
        }
    }
    else
    {
        QMessageBox::information(NULL, tr("Warring"), tr("lineEdit is zero!"));
    }

}

void recordDialog::on_pushButton_3_clicked()
{
    //ɾ��
    int curRow = currentView_2->currentIndex().row(); //��ȡѡ�е���
    currentTableModel_2->removeRow(curRow); //ɾ������
    currentTableModel_2->submitAll();
}

void recordDialog::on_tableView_clicked(const QModelIndex &index)
{
    //���б���
    int curRow = currentView_1->currentIndex().row(); //��ȡѡ�е���

    switch(ui->comboBox->currentIndex())
    {
    case 0:
        ui->label_4->setText("���� : " + currentTableModel_1->index(curRow, 2).data().toString() + " ǧ��/�ٿ�");
        ui->label_5->setText("���� : ");
        ui->label_6->setText("��");
        ui->lineEdit_2->setText("100");
        break;
    case 1:
        ui->label_4->setText("���� : " + currentTableModel_1->index(curRow, 2).data().toString() + " ǧ��/�ٿ�");
        ui->label_5->setText("���� : ");
        ui->label_6->setText("��");
        ui->lineEdit_2->setText("100");
        break;
    case 2:
        ui->label_4->setText("���� : " + currentTableModel_1->index(curRow, 2).data().toString() + " ǧ��/Сʱ");
        ui->label_5->setText("ʱ�� : ");
        ui->label_6->setText("Сʱ");
        ui->lineEdit_2->setText("1");
        break;
    default:
        break;
    }
    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(currentTableModel_1->index(curRow, 5).data().toString()));

    ui->label_2->setText(currentTableModel_1->index(curRow, 1).data().toString());
}

void recordDialog::on_tableView_2_clicked(const QModelIndex &index)
{
    //���б���
    int curRow = currentView_2->currentIndex().row(); //��ȡѡ�е���
    QString picPath;
    QString sql;
    QSqlQuery query;

    ui->label_2->setText(currentTableModel_2->index(curRow, 1).data().toString());

    switch(currentTableModel_2->index(curRow, 4).data().toInt())
    {
    case 0:
        ui->label_4->setText("���� : " + currentTableModel_2->index(curRow, 2).data().toString() + " ǧ��/�ٿ�");
        ui->label_5->setText("���� : ");
        ui->label_6->setText("��");
        ui->lineEdit_2->setText(currentTableModel_2->index(curRow, 3).data().toString());

        sql = "select pic from food where name = '" + currentTableModel_2->index(curRow, 1).data().toString() + "'";
        query.exec(sql);
        while(query.next())
        {
            picPath = query.value(0).toString();
        }
        break;
    case 1:
        ui->label_4->setText("���� : " + currentTableModel_2->index(curRow, 2).data().toString() + " ǧ��/�ٿ�");
        ui->label_5->setText("���� : ");
        ui->label_6->setText("��");
        ui->lineEdit_2->setText(currentTableModel_2->index(curRow, 3).data().toString());

        sql = "select pic from cookbook where name = '" + currentTableModel_2->index(curRow, 1).data().toString() + "'";
        query.exec(sql);
        while(query.next())
        {
            picPath = query.value(0).toString();
        }
        break;
    case 2:
        ui->label_4->setText("���� : " + currentTableModel_2->index(curRow, 2).data().toString() + " ǧ��/Сʱ");
        ui->label_5->setText("ʱ�� : ");
        ui->label_6->setText("Сʱ");
        ui->lineEdit_2->setText(currentTableModel_2->index(curRow, 3).data().toString());

        sql = "select pic from sports where name = '" + currentTableModel_2->index(curRow, 1).data().toString() + "'";
        query.exec(sql);
        while(query.next())
        {
            picPath = query.value(0).toString();
        }
        break;
    default:
        break;
    }
    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(picPath));
}
