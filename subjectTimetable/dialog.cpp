#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    init();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::init()
{
    //��ʼ��
    QSqlQuery query;
    selectClass = 0;

    currentTableModel->setTable("classcon");
    currentTableModel->select();
    currentTableModel->removeColumn(11);
    currentTableModel->setHeaderData(0, Qt::Horizontal, QString("ID"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QString("�γ̲��"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QString("�γ����"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QString("�γ�����"));
    currentTableModel->setHeaderData(4, Qt::Horizontal, QString("�γ̴���"));
    currentTableModel->setHeaderData(5, Qt::Horizontal, QString("�γ�����"));
    currentTableModel->setHeaderData(6, Qt::Horizontal, QString("�γ�ѧʱ"));
    currentTableModel->setHeaderData(7, Qt::Horizontal, QString("�γ�ѧ��"));
    currentTableModel->setHeaderData(8, Qt::Horizontal, QString("ѧʱʵ��"));
    currentTableModel->setHeaderData(9, Qt::Horizontal, QString("ѧʱѧ��"));
    currentTableModel->setHeaderData(10, Qt::Horizontal, QString("���˷�ʽ"));
    currentView->setModel(currentTableModel);
    currentView->setColumnWidth(0, 0);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QHeaderView* headerView = currentView->verticalHeader();
    headerView->setHidden(true);

    ui->lineEdit_level->clear();
    ui->lineEdit_type->clear();
    ui->lineEdit_code->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_hrs->clear();
    ui->lineEdit_crs->clear();
    ui->lineEdit_test->clear();
    ui->comboBox_level->clear();
    ui->comboBox_level->addItem("");
    query.exec("select name from classLevel");
    while(query.next())
    {
        ui->comboBox_level->addItem(query.value(0).toString());
    }
    ui->comboBox_level->setCurrentIndex(0);
    ui->comboBox_type->clear();
    ui->comboBox_type->addItem("");
    query.exec("select name from classType");
    while(query.next())
    {
        ui->comboBox_type->addItem(query.value(0).toString());
    }
    ui->comboBox_type->setCurrentIndex(0);
    ui->comboBox_nature->setCurrentIndex(0);
    ui->comboBox_time->setCurrentIndex(0);
    ui->comboBox_exam->setCurrentIndex(0);
}

void Dialog::on_pushButton_5_clicked()
{
    //��Ӳ��
    QString name = ui->lineEdit_level->text();

    if(name == "")
    {
        QMessageBox::information(NULL, "error.", "û����д�γ̲������!");
        return;
    }
    QString sql;
    QSqlQuery query;
    int idNum = 0;

    sql = "select * from classLevel where name = '" + name + "'";
    query.exec(sql);
    while(query.next())
    {
        QMessageBox::information(NULL, "error.", "�Ѵ��ڸÿγ̲������!");
        return;
    }

    sql = "select * from classLevel";
    query.exec(sql);
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }
    idNum++;

    sql = "insert into classLevel values('" + QString::number(idNum, 10)
            + "', '" + name
            + "')";
    query.exec(sql);

    QMessageBox::information(NULL, "success.", "��ӳɹ�!");

    ui->lineEdit_level->clear();
    ui->comboBox_level->clear();
    ui->comboBox_level->addItem("");
    query.exec("select name from classLevel");
    while(query.next())
    {
        ui->comboBox_level->addItem(query.value(0).toString());
    }
    ui->comboBox_level->setCurrentIndex(0);
}

void Dialog::on_pushButton_7_clicked()
{
    //�޸Ĳ��
    QString name = ui->lineEdit_level->text();

    if(name == "")
    {
        QMessageBox::information(NULL, "error.", "û����д�γ̲������!");
        return;
    }
    QString sql;
    QSqlQuery query;
    int idNum = ui->comboBox_level->currentIndex();

    if(idNum == 0)
    {
        QMessageBox::information(NULL, "error.", "û��ѡ��Ҫ�޸ĵĿγ̲��!");
        return;
    }

    sql = "select * from classLevel where name = '" + name
            + "' and classLevelId <> '" + QString::number(idNum, 10) + "'";
    query.exec(sql);
    while(query.next())
    {
        QMessageBox::information(NULL, "error.", "�Ѵ��ڸÿγ̲������!");
        return;
    }


    sql = "update classLevel set name = '" + name + "' "
            + "where classLevelId = '" + QString::number(idNum, 10) + "'";
    query.exec(sql);

    QMessageBox::information(NULL, "success.", "�޸ĳɹ�!");

    ui->lineEdit_level->clear();
    ui->comboBox_level->clear();
    ui->comboBox_level->addItem("");
    query.exec("select name from classLevel");
    while(query.next())
    {
        ui->comboBox_level->addItem(query.value(0).toString());
    }
    ui->comboBox_level->setCurrentIndex(0);
}

void Dialog::on_pushButton_6_clicked()
{
    //ɾ�����
    QString sql;
    QSqlQuery query;
    int idNum = ui->comboBox_level->currentIndex();

    if(idNum == 0)
    {
        QMessageBox::information(NULL, "error.", "û��ѡ��Ҫɾ���Ŀγ̲��!");
        return;
    }

    sql = "delete from classLevel where classLevelId = '" + QString::number(idNum, 10) + "'";
    query.exec(sql);

    QMessageBox::information(NULL, "success.", "ɾ���ɹ�!");

    ui->lineEdit_level->clear();
    ui->comboBox_level->clear();
    ui->comboBox_level->addItem("");
    query.exec("select name from classLevel");
    while(query.next())
    {
        ui->comboBox_level->addItem(query.value(0).toString());
    }
    ui->comboBox_level->setCurrentIndex(0);
}

void Dialog::on_pushButton_8_clicked()
{
    //������
    QString name = ui->lineEdit_type->text();

    if(name == "")
    {
        QMessageBox::information(NULL, "error.", "û����д�γ��������!");
        return;
    }
    QString sql;
    QSqlQuery query;
    int idNum = 0;

    sql = "select * from classType where name = '" + name + "'";
    query.exec(sql);
    while(query.next())
    {
        QMessageBox::information(NULL, "error.", "�Ѵ��ڸÿγ��������!");
        return;
    }

    sql = "select * from classType";
    query.exec(sql);
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }
    idNum++;

    sql = "insert into classType values('" + QString::number(idNum, 10)
            + "', '" + name
            + "')";
    query.exec(sql);

    QMessageBox::information(NULL, "success.", "��ӳɹ�!");

    ui->lineEdit_type->clear();
    ui->comboBox_type->clear();
    ui->comboBox_type->addItem("");
    query.exec("select name from classType");
    while(query.next())
    {
        ui->comboBox_type->addItem(query.value(0).toString());
    }
    ui->comboBox_type->setCurrentIndex(0);
}

void Dialog::on_pushButton_9_clicked()
{
    //�޸����
    QString name = ui->lineEdit_type->text();

    if(name == "")
    {
        QMessageBox::information(NULL, "error.", "û����д�γ��������!");
        return;
    }
    QString sql;
    QSqlQuery query;
    int idNum = ui->comboBox_type->currentIndex();

    if(idNum == 0)
    {
        QMessageBox::information(NULL, "error.", "û��ѡ��Ҫ�޸ĵĿγ����!");
        return;
    }

    sql = "select * from classType where name = '" + name
            + "' and classTypeId <> '" + QString::number(idNum, 10) + "'";
    query.exec(sql);
    while(query.next())
    {
        QMessageBox::information(NULL, "error.", "�Ѵ��ڸÿγ��������!");
        return;
    }

    sql = "update classType set name = '" + name + "' "
            + "where classTypeId = '" + QString::number(idNum, 10) + "'";
    query.exec(sql);

    QMessageBox::information(NULL, "success.", "�޸ĳɹ�!");

    ui->lineEdit_type->clear();
    ui->comboBox_type->clear();
    ui->comboBox_type->addItem("");
    query.exec("select name from classType");
    while(query.next())
    {
        ui->comboBox_type->addItem(query.value(0).toString());
    }
    ui->comboBox_type->setCurrentIndex(0);
}

void Dialog::on_pushButton_10_clicked()
{
    //ɾ�����
    QString sql;
    QSqlQuery query;
    int idNum = ui->comboBox_type->currentIndex();

    if(idNum == 0)
    {
        QMessageBox::information(NULL, "error.", "û��ѡ��Ҫɾ���Ŀγ����!");
        return;
    }

    sql = "delete from classType where classTypeId = '" + QString::number(idNum, 10) + "'";
    query.exec(sql);

    QMessageBox::information(NULL, "success.", "ɾ���ɹ�!");

    ui->lineEdit_type->clear();
    ui->comboBox_type->clear();
    ui->comboBox_type->addItem("");
    query.exec("select name from classType");
    while(query.next())
    {
        ui->comboBox_type->addItem(query.value(0).toString());
    }
    ui->comboBox_type->setCurrentIndex(0);
}

void Dialog::on_pushButton_clicked()
{
    //��ӿγ�
    QString level = QString::number(ui->comboBox_level->currentIndex());
    QString type = QString::number(ui->comboBox_type->currentIndex());
    QString nature = QString::number(ui->comboBox_nature->currentIndex());
    QString code = ui->lineEdit_code->text().trimmed();
    QString name = ui->lineEdit_name->text().trimmed();
    QString hrs = ui->lineEdit_hrs->text().trimmed();
    QString crs = ui->lineEdit_crs->text().trimmed();
    QString test = ui->lineEdit_test->text().trimmed();
    QString time = QString::number(ui->comboBox_time->currentIndex());
    QString exam = QString::number(ui->comboBox_exam->currentIndex());

    if(level == "0")
    {
        QMessageBox::information(NULL, "error.", "û��ѡ��γ̲��!");
        return;
    }
    if(type == "0")
    {
        QMessageBox::information(NULL, "error.", "û��ѡ��γ����!");
        return;
    }
    if(code == "")
    {
        QMessageBox::information(NULL, "error.", "û����д�γ̴���!");
        return;
    }
    QString sql;
    QSqlQuery query;
    int idNum = 0;

    sql = "select * from classCon where cCode = '" + code + "'";
    query.exec(sql);
    while(query.next())
    {
        QMessageBox::information(NULL, "error.", "�Ѵ��ڸÿγ̴���!");
        return;
    }

    sql = "select classConId from classCon";
    query.exec(sql);
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }
    idNum++;

    sql = "insert into classCon values('" + QString::number(idNum, 10)
            + "', '" + level
            + "', '" + type
            + "', '" + nature
            + "', '" + code
            + "', '" + name
            + "', '" + hrs
            + "', '" + crs
            + "', '" + test
            + "', '" + time
            + "', '" + exam
            + "')";
    query.exec(sql);

    QMessageBox::information(NULL, "success.", "��ӳɹ�!");

    selectClass = 0;
    ui->lineEdit_code->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_hrs->clear();
    ui->lineEdit_crs->clear();
    ui->lineEdit_test->clear();
    ui->comboBox_level->setCurrentIndex(0);
    ui->comboBox_type->setCurrentIndex(0);
    ui->comboBox_nature->setCurrentIndex(0);
    ui->comboBox_time->setCurrentIndex(0);
    ui->comboBox_exam->setCurrentIndex(0);

    currentTableModel->select();
}

void Dialog::on_pushButton_2_clicked()
{
    //�޸Ŀγ�
    QString level = QString::number(ui->comboBox_level->currentIndex());
    QString type = QString::number(ui->comboBox_type->currentIndex());
    QString nature = QString::number(ui->comboBox_nature->currentIndex());
    QString code = ui->lineEdit_code->text().trimmed();
    QString name = ui->lineEdit_name->text().trimmed();
    QString hrs = ui->lineEdit_hrs->text().trimmed();
    QString crs = ui->lineEdit_crs->text().trimmed();
    QString test = ui->lineEdit_test->text().trimmed();
    QString time = QString::number(ui->comboBox_time->currentIndex());
    QString exam = QString::number(ui->comboBox_exam->currentIndex());

    if(selectClass == 0)
    {
        QMessageBox::information(NULL, "error.", "û��ѡ��Ҫ�޸ĵĿγ�!");
        return;
    }

    if(level == "0")
    {
        QMessageBox::information(NULL, "error.", "û��ѡ��γ̲��!");
        return;
    }
    if(type == "0")
    {
        QMessageBox::information(NULL, "error.", "û��ѡ��γ����!");
        return;
    }
    if(code == "")
    {
        QMessageBox::information(NULL, "error.", "û����д�γ̴���!");
        return;
    }
    QString sql;
    QSqlQuery query;
    int idNum = selectClass;

    sql = "select * from classCon where cCode = '" + code
            + "' and classConId <> '" + QString::number(idNum, 10) + "'";
    query.exec(sql);
    while(query.next())
    {
        QMessageBox::information(NULL, "error.", "�Ѵ��ڸÿγ̴���!");
        return;
    }

    sql = "update classCon set cLevel = '" + level + "', "
            + "cType = '" + type + "', "
            + "cNature = '" + nature + "', "
            + "cCode = '" + code + "', "
            + "cName = '" + name + "', "
            + "cHrs = '" + hrs + "', "
            + "cCrs = '" + crs + "', "
            + "cTest = '" + test + "', "
            + "cTime = '" + time + "', "
            + "cExam = '" + exam + "' "
            + "where classConId = '" + QString::number(idNum, 10) + "'";
    qDebug() << sql;
    query.exec(sql);

    QMessageBox::information(NULL, "success.", "�޸ĳɹ�!");

    selectClass = 0;
    ui->lineEdit_code->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_hrs->clear();
    ui->lineEdit_crs->clear();
    ui->lineEdit_test->clear();
    ui->comboBox_level->setCurrentIndex(0);
    ui->comboBox_type->setCurrentIndex(0);
    ui->comboBox_nature->setCurrentIndex(0);
    ui->comboBox_time->setCurrentIndex(0);
    ui->comboBox_exam->setCurrentIndex(0);

    currentTableModel->select();
}

void Dialog::on_pushButton_3_clicked()
{
    //ɾ���γ�
    if(selectClass == 0)
    {
        QMessageBox::information(NULL, "error.", "û��ѡ��Ҫɾ���Ŀγ�!");
        return;
    }

    QString sql;
    QSqlQuery query;
    int idNum = selectClass;

    sql = "delete from classCon where classConId = '" + QString::number(idNum, 10) + "'";
    query.exec(sql);

    QMessageBox::information(NULL, "success.", "ɾ���ɹ�!");

    selectClass = 0;
    ui->lineEdit_code->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_hrs->clear();
    ui->lineEdit_crs->clear();
    ui->lineEdit_test->clear();
    ui->comboBox_level->setCurrentIndex(0);
    ui->comboBox_type->setCurrentIndex(0);
    ui->comboBox_nature->setCurrentIndex(0);
    ui->comboBox_time->setCurrentIndex(0);
    ui->comboBox_exam->setCurrentIndex(0);

    currentTableModel->select();
}

void Dialog::on_pushButton_4_clicked()
{
    //��������
    QMessageBox::information(NULL, "error.", "����Excel������δʵ��!");
    init();
}

void Dialog::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    int curRow = index.row(); //��ȡѡ�е���
    selectClass = currentTableModel->index(curRow, 0).data().toInt();

    int i = 1;
    ui->comboBox_level->setCurrentIndex(currentTableModel->index(curRow, i++).data().toInt());
    ui->comboBox_type->setCurrentIndex(currentTableModel->index(curRow, i++).data().toInt());
    ui->comboBox_nature->setCurrentIndex(currentTableModel->index(curRow, i++).data().toInt());
    ui->lineEdit_code->setText(currentTableModel->index(curRow, i++).data().toString());
    ui->lineEdit_name->setText(currentTableModel->index(curRow, i++).data().toString());
    ui->lineEdit_hrs->setText(currentTableModel->index(curRow, i++).data().toString());
    ui->lineEdit_crs->setText(currentTableModel->index(curRow, i++).data().toString());
    ui->lineEdit_test->setText(currentTableModel->index(curRow, i++).data().toString());
    ui->comboBox_time->setCurrentIndex(currentTableModel->index(curRow, i++).data().toInt());
    ui->comboBox_exam->setCurrentIndex(currentTableModel->index(curRow, i++).data().toInt());
}

void Dialog::on_comboBox_level_currentIndexChanged(const QString &arg1)
{
    //�γ̲㼶ѡ��
    ui->lineEdit_level->setText(arg1);
}

void Dialog::on_comboBox_type_currentIndexChanged(const QString &arg1)
{
    //�γ����ѡ��
    ui->lineEdit_type->setText(arg1);
}
