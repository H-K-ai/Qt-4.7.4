#include "coursedialog.h"
#include "ui_coursedialog.h"

courseDialog::courseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::courseDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    on_pushButton_4_clicked();

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox_3->setCurrentIndex(0);
    ui->comboBox_4->setCurrentIndex(0);

    initDialog();
}

courseDialog::~courseDialog()
{
    delete ui;
}

void courseDialog::showEvent(QShowEvent *)
{
    on_pushButton_4_clicked();

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox_3->setCurrentIndex(0);
    ui->comboBox_4->setCurrentIndex(0);

    initDialog();
}

void courseDialog::on_pushButton_5_clicked()
{
    //�γ̲�ѯ
    currentTableModel->setFilter("subjucts like '%" + ui->lineEdit->text().trimmed() + "%'");
    currentTableModel->select();
}

void courseDialog::on_pushButton_6_clicked()
{
    //�༶��ѯ
    currentTableModel->setFilter("classid like '%" + ui->lineEdit_2->text().trimmed() + "%'");
    currentTableModel->select();
}

void courseDialog::on_pushButton_clicked()
{
    //���
    QSqlQuery query;
    int idNum = 0;

    query.exec("select coursesid from courses");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    query.exec("insert into courses values('" + QString::number(idNum, 10) + "', '"
               + ui->comboBox->currentText() + "', '"
               + ui->comboBox_2->currentText() + "', '"
               + ui->comboBox_3->currentText() + "', '"
               + ui->comboBox_4->currentText() + "')");

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox_3->setCurrentIndex(0);
    ui->comboBox_4->setCurrentIndex(0);

    currentTableModel->select();
    QMessageBox::information(NULL, "success", "add success!");
}

void courseDialog::on_pushButton_2_clicked()
{
    //�޸�
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();
    query.exec("delete from courses where coursesid = '" + idNum + "'");

    query.exec("insert into courses values('" + idNum + "', '"
               + ui->comboBox->currentText() + "', '"
               + ui->comboBox_2->currentText() + "', '"
               + ui->comboBox_3->currentText() + "', '"
               + ui->comboBox_4->currentText() + "')");

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox_3->setCurrentIndex(0);
    ui->comboBox_4->setCurrentIndex(0);

    currentTableModel->select();
    QMessageBox::information(NULL, "success", "modefy success!");
}

void courseDialog::on_pushButton_3_clicked()
{
    //ɾ��
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox_3->setCurrentIndex(0);
    ui->comboBox_4->setCurrentIndex(0);

    QMessageBox::information(NULL, "success", "delete success!");
}

void courseDialog::on_pushButton_4_clicked()
{
    //ˢ��
    currentTableModel->setTable("courses");
    currentTableModel->select();
    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox_3->setCurrentIndex(0);
    ui->comboBox_4->setCurrentIndex(0);
}

void courseDialog::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();

    qDebug() << idNum << endl;
    query.exec("select * from courses where coursesid = '" + idNum + "'");
    while(query.next())
    {
        ui->comboBox->setCurrentIndex(ui->comboBox->findText(query.value(1).toString()));
        ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(query.value(2).toString()));
        ui->comboBox_3->setCurrentIndex(ui->comboBox_3->findText(query.value(3).toString()));
        ui->comboBox_4->setCurrentIndex(ui->comboBox_4->findText(query.value(4).toString()));

        qDebug() << query.value(1).toString() << endl;
    }
}

void courseDialog::initDialog()
{
    //��ʼ�������б�
    QSqlQuery query;
    ui->comboBox->clear();
    ui->comboBox_2->clear();

    ui->comboBox->addItem("");
    ui->comboBox_2->addItem("");

    query.exec("select name from subjucts");
    while(query.next())
        ui->comboBox->addItem(query.value(0).toString());

    query.exec("select classid from students");
    while(query.next())
        ui->comboBox_2->addItem(query.value(0).toString());
}
