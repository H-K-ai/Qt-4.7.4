#include "adstudialog.h"
#include "ui_adstudialog.h"

adStuDialog::adStuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adStuDialog)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    currentTableModel->setTable("students");
    currentTableModel->setSort(0, Qt::AscendingOrder);
    currentTableModel->select();

    currentTableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("���"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("֤�����"));
    currentTableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("��ϵ��ʽ"));
    currentTableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("״̬"));
    currentTableModel->setHeaderData(6, Qt::Horizontal, QObject::tr("��Ƭ"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->comboBox->setCurrentIndex(0);

    connect(&adModifyStuw, SIGNAL(modifyStu()), this, SLOT(updateStuTable()));
}

adStuDialog::~adStuDialog()
{
    delete ui;
}

void adStuDialog::showEvent(QShowEvent *)
{
    //��ʾ����
    currentTableModel->setTable("students");
    currentTableModel->setSort(0, Qt::AscendingOrder);
    currentTableModel->select();

    currentTableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("���"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("֤�����"));
    currentTableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("��ϵ��ʽ"));
    currentTableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("״̬"));
    currentTableModel->setHeaderData(6, Qt::Horizontal, QObject::tr("��Ƭ"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->comboBox->setCurrentIndex(0);
}

void adStuDialog::on_pushButton_4_clicked()
{
    //ͷ��
    picPath = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg)"));
    if(picPath.length() == 0) {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
        return;
    } else {
        QMessageBox::information(NULL, tr("Path"), tr("You selected ") + picPath);
    }
    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap(picPath));
}

void adStuDialog::on_pushButton_clicked()
{
    //��������֤
    QSqlQuery query;
    int idNum = 0;

    if(ui->lineEdit->text().trimmed().length() == 0)
    {
        QMessageBox::information(NULL, "Warring", "���ʧ��!��������Ϊ��.");
        return;
    }

    if(ui->lineEdit_3->text().trimmed().length() == 0)
    {
        QMessageBox::information(NULL, "Warring", "���ʧ��!֤����Ų���Ϊ��.");
        return;
    }

    if(ui->lineEdit_4->text().trimmed().length() == 0)
    {
        QMessageBox::information(NULL, "Warring", "���ʧ��!��ϵ��ʽ����Ϊ��.");
        return;
    }

    query.exec("select studentsid,stucode,phone from students");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
        if(query.value(1).toString() == ui->lineEdit_3->text().trimmed())
        {
            QMessageBox::information(NULL, "Warring", "���ʧ��!֤������ظ�.");
            return;
        }
        if(query.value(2).toString() == ui->lineEdit_4->text().trimmed())
        {
            QMessageBox::information(NULL, "Warring", "���ʧ��!�ֻ������ظ�.");
            return;
        }
    }

    idNum++;

    QString targetPath = "user/" + QString::number(idNum, 10) + ".jpg";
    copyFileToPath(picPath, targetPath, true); //����ʽ����

    query.exec("insert into students values('" + QString::number(idNum, 10) + "', '"
               + ui->lineEdit->text().trimmed() + "', '"
               + ui->lineEdit_2->text().trimmed() + "', '"
               + ui->lineEdit_3->text().trimmed() + "', '"
               + ui->lineEdit_4->text().trimmed() + "', '"
               + QString::number(ui->comboBox->currentIndex(), 10) + "', '"
               + targetPath + "')");

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->comboBox->setCurrentIndex(0);

    currentTableModel->select();
    QMessageBox::information(NULL, "success", "��ӳɹ�!");

    emit addStu();
}

void adStuDialog::on_pushButton_2_clicked()
{
    //ע������֤
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();

    query.exec("update students set status = 1" + QString(" where studentsid = '") + idNum + "'");

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->comboBox->setCurrentIndex(0);

    currentTableModel->select();
    QMessageBox::information(NULL, "success", "ע���ɹ�!");

    emit addStu();
}

void adStuDialog::on_pushButton_3_clicked()
{
    //�޸Ľ���֤
#if 0
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();

    query.exec("delete from students where studentsid = '" + idNum + "'");

    QString targetPath = "user/" + idNum + ".jpg";
    copyFileToPath(picPath, targetPath, true); //����ʽ����

    query.exec("insert into students values('" + idNum + "', '"
               + ui->lineEdit->text().trimmed() + "', '"
               + ui->lineEdit_2->text().trimmed() + "', '"
               + ui->lineEdit_3->text().trimmed() + "', '"
               + ui->lineEdit_4->text().trimmed() + "', '"
               + QString::number(ui->comboBox->currentIndex(), 10) + "', '"
               + targetPath + "')");


    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->comboBox->setCurrentIndex(0);

    currentTableModel->select();
    QMessageBox::information(NULL, "success", "�޸ĳɹ�!");
#endif
    adModifyStuw.show();

    emit addStu();
}

void adStuDialog::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    QSqlQuery query;
    QString idNum = currentTableModel->index(curRow, 0).data().toString();

    query.exec("select * from students where studentsid = '" + idNum + "'");
    while(query.next())
    {
        ui->lineEdit->setText(query.value(1).toString());
        ui->lineEdit_2->setText(query.value(2).toString());
        ui->lineEdit_3->setText(query.value(3).toString());
        ui->lineEdit_4->setText(query.value(4).toString());
        ui->comboBox->setCurrentIndex(query.value(5).toInt());
        ui->label->setScaledContents(true);
        ui->label->setPixmap(QPixmap(query.value(6).toString()));
    }
}

void adStuDialog::updateStuTable()
{
    //ˢ��
    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    currentTableModel->setTable("students");
    currentTableModel->setSort(0, Qt::AscendingOrder);
    currentTableModel->select();

    currentTableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("���"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("����"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QObject::tr("֤�����"));
    currentTableModel->setHeaderData(4, Qt::Horizontal, QObject::tr("��ϵ��ʽ"));
    currentTableModel->setHeaderData(5, Qt::Horizontal, QObject::tr("״̬"));
    currentTableModel->setHeaderData(6, Qt::Horizontal, QObject::tr("��Ƭ"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->label->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->comboBox->setCurrentIndex(0);
}
