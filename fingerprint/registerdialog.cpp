#include "registerdialog.h"
#include "ui_registerdialog.h"

registerDialog::registerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerDialog)
{
    ui->setupUi(this);

    QDesktopWidget* desktop = QApplication::desktop();
    this->move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);
    this->setWindowTitle("ָ��¼�����");

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    qFinger = new qFingerprint(this);
    connect(qFinger, SIGNAL(OnImageReceived()), this, SLOT(finishImageReceived()));
    connect(qFinger, SIGNAL(OnFeatureInfo(int)), this, SLOT(finishFeatureInfo(int)));
    connect(qFinger, SIGNAL(OnEnroll(QString)), this, SLOT(finishEnroll(QString)));

    init();
}

registerDialog::~registerDialog()
{
    delete ui;
}

void registerDialog::showEvent(QShowEvent *)
{
    init();
    on_pushButton_clicked();
}

void registerDialog::paintEvent(QPaintEvent *)
{}

void registerDialog::closeEvent(QCloseEvent *)
{
    qFinger->EndEngine();
    emit OnClose();
}

void registerDialog::init()
{
    isLineToFinger = false;

    currentTableModel->setTable("users");
    currentTableModel->select();

    currentTableModel->setHeaderData(0, Qt::Horizontal, QString("���"));
    currentTableModel->setHeaderData(1, Qt::Horizontal, QString("����"));
    currentTableModel->setHeaderData(2, Qt::Horizontal, QString("���֤"));
    currentTableModel->setHeaderData(3, Qt::Horizontal, QString("Ȩ��"));
    currentTableModel->setHeaderData(4, Qt::Horizontal, QString("ָ������"));

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->comboBox->clear();
    ui->comboBox->addItem("Ա��");
    ui->comboBox->addItem("�ɹ�Ա");
    ui->comboBox->addItem("����Ա");
    ui->comboBox->addItem("����");
    ui->comboBox->setCurrentIndex(0);

    ui->lineEdit->setEnabled(false);
    ui->lineEdit_1->setEnabled(false);
    ui->lineEdit_1->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    QRegExp regExp("(^\\d{18}$)|(^\\d{17}(\\d|X|x)$)");
    QRegExpValidator *pRevalidotor = new QRegExpValidator(regExp, 0);
    ui->lineEdit_3->setValidator(pRevalidotor);
    ui->lineEdit_4->clear();
    ui->plainTextEdit->setReadOnly(true);
    ui->plainTextEdit->clear();

    ui->label_2->clear();
    ui->label_2->setScaledContents(true);
    ui->label_3->clear();
    ui->label_3->setText("ָ������ : ");
    ui->label_10->clear();
}

void registerDialog::on_lineEdit_4_textChanged(const QString &arg1)
{
    //����������ı�
    currentTableModel->setFilter("username like '%" + arg1 + "%'");
}

void registerDialog::on_pushButton_clicked()
{
    //����ָ����
    int result = -1;
    QString strSN = "ָ������δ����!";
    result = qFinger->InitEngine();
    if(result == 0)
    {
        strSN = qFinger->SensorSN();
        isLineToFinger = true;
    }
    else
    {
        qFinger->EndEngine();
        isLineToFinger = false;
        QMessageBox::information(NULL, "error.", "��ʼ��ָ����ʧ��!");
    }
    ui->lineEdit->setText(QString(strSN));

}

void registerDialog::on_pushButton_3_clicked()
{
    //��ʼ�Ǽ�ָ��
    if(isLineToFinger == false)
    {
        QMessageBox::information(NULL, "error.", "ָ����δ����!");
    }
    else
    {
        if(qFinger->IsRegister())
        {
            qFinger->CancelEnroll();
        }
        qFinger->BeginEnroll();
        ui->label_10->clear();
        ui->label_10->setText("���谴ѹ���� : 3 ��");
    }
}

void registerDialog::on_pushButton_8_clicked()
{
    //ȡ���Ǽ�ָ��
    if(isLineToFinger == false)
    {
        QMessageBox::information(NULL, "error.", "ָ����δ����!");
    }
    else
    {
        qFinger->CancelEnroll();
    }
}

void registerDialog::on_pushButton_4_clicked()
{
    //�����Ϣ
    QSqlQuery query;
    QString sql;
    int idNum = 0;
    QString oldUsername = "";
    QString oldUserzw = "";
    QString username = ui->lineEdit_2->text().trimmed();
    QString idcard = ui->lineEdit_3->text().trimmed();
    QString role = QString::number(ui->comboBox->currentIndex(), 10);
    QString userzw = ui->plainTextEdit->toPlainText();

    if(username == "")
    {
        QMessageBox::information(NULL, "error.", "û����д����!");
        return;
    }

    if(idcard == "")
    {
        QMessageBox::information(NULL, "error.", "û����д���֤!");
        return;
    }

    sql = "select usersid from users where userzw = '" + userzw + "'";
    query.exec(sql);
    while(query.next())
    {
        QMessageBox::information(NULL, "error.", "ָ���ظ�,������¼��ָ��!");
        return;
    }

    sql = "select usersid from users where idcard = '" + idcard + "' and role = '" + role + "'";
    query.exec(sql);
    while(query.next())
    {
        QMessageBox::information(NULL, "error.", "���֤�ظ�,��Ȩ���´�Ա���Ѿ�����!");
        return;
    }

    sql = "select username, userzw from users where idcard = '" + idcard + "'";
    query.exec(sql);
    while(query.next())
    {
        oldUsername = query.value(0).toString();
        oldUserzw = query.value(1).toString();

        if(oldUsername != username)
        {
            QMessageBox::information(NULL, "error.", "������¼������֤��Ӧ��������ͬ! ԭ���� : " + oldUsername);
            return;
        }

        if(oldUserzw == userzw)
        {
            QMessageBox::information(NULL, "error.", "��ͬȨ������Ҫ��ͬ��ָ��,������¼����һ����ָָ��!");
            return;
        }
    }

    query.exec("select usersid from users");
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    sql = "insert into users values('" + QString::number(idNum, 10) + "', '" + username + "', '" + idcard + "', '" + role + "', '" + userzw + "')";
    query.exec(sql);

    ui->lineEdit_1->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->plainTextEdit->clear();

    currentTableModel->select();
    ui->label_10->clear();

    if(userzw != "")
    {
        QVariant fingerTempVar;
        fingerTempVar = qFinger->DecodeTemplate(userzw);
        insertFingerTempMap(idNum, fingerTempVar);
    }
}

void registerDialog::on_pushButton_5_clicked()
{
    //�޸���Ϣ
    QSqlQuery query;
    QString sql;
    QString oldUsername = "";
    QString oldRole = "";
    QString idNum = ui->lineEdit_1->text().trimmed();
    QString username = ui->lineEdit_2->text().trimmed();
    QString idcard = ui->lineEdit_3->text().trimmed();
    QString role = QString::number(ui->comboBox->currentIndex(), 10);
    QString userzw = ui->plainTextEdit->toPlainText();

    if(username == "")
    {
        QMessageBox::information(NULL, "error.", "û����д����!");
        return;
    }

    if(idcard == "")
    {
        QMessageBox::information(NULL, "error.", "û����д���֤!");
        return;
    }

    sql = "select usersid from users where idcard = '" + idcard + "' and role = '" + role + "' and usersid <> '" + idNum + "'";
    query.exec(sql);
    while(query.next())
    {
        QMessageBox::information(NULL, "error.", "���֤�ظ�,���û��Ѿ�����!");
        return;
    }

    sql = "select username, role from users where idcard = '" + idcard + "'";
    query.exec(sql);
    while(query.next())
    {
        oldUsername = query.value(0).toString();
        oldRole = query.value(1).toString();

        if(oldUsername != username)
        {
            QMessageBox::information(NULL, "error.", "������¼������֤��Ӧ��������ͬ! ԭ���� : " + oldUsername);
            return;
        }

        if(oldRole != role)
        {
            sql = "select stockslogid from stockslog where buyerid = '" + idNum + "' or keeperid = '" + idNum + "' or leaderid = '" + idNum + "'";
            query.exec(sql);
            while(query.next())
            {
                QMessageBox::information(NULL, "error.", "�������ǼǼ�¼,�޷��޸�Ȩ��,���������!");
                return;
            }

            sql = "select borrowlogid from borrowlog where keeperid = '" + idNum + "' or userid = '" + idNum + "'";
            query.exec(sql);
            while(query.next())
            {
                QMessageBox::information(NULL, "error.", "���н軹��Ʒ��¼,�޷��޸�Ȩ��,���������!");
                return;
            }
        }
    }


    sql = "update users set username = '" + username + "' , idcard = '" + idcard + "' , role = '" + role + "' , userzw = '" + userzw + "' where usersid = '" + idNum + "'";
    query.exec(sql);

    ui->lineEdit_1->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->plainTextEdit->clear();
    currentTableModel->select();
    ui->label_10->clear();

    if(userzw != "")
    {
        int userid = idNum.toInt();
        QVariant fingerTempVar;
        fingerTempVar = qFinger->DecodeTemplate(userzw);
        modifyFingerTempMap(userid, fingerTempVar);
    }
}

void registerDialog::on_pushButton_6_clicked()
{
    //ɾ����Ϣ
    QSqlQuery query;
    QString sql;
    QString idNum = ui->lineEdit_1->text().trimmed();
    QString username = ui->lineEdit_2->text().trimmed();
    QString idcard = ui->lineEdit_3->text().trimmed();
    QString role = QString::number(ui->comboBox->currentIndex(), 10);
    QString userzw = ui->plainTextEdit->toPlainText();

    if(idNum == "")
    {
        QMessageBox::information(NULL, "error.", "û��ѡ��Ҫɾ������Ա!");
        return;
    }

    if(username == false)
    {
        QMessageBox::information(NULL, "error.", "û����д����!");
        return;
    }

    if(idcard == false)
    {
        QMessageBox::information(NULL, "error.", "û����д���֤!");
        return;
    }

    sql = "select stockslogid from stockslog where buyerid = '" + idNum + "' or keeperid = '" + idNum + "' or leaderid = '" + idNum + "'";
    query.exec(sql);
    while(query.next())
    {
        QMessageBox::information(NULL, "error.", "�������ǼǼ�¼,�޷�ɾ��!");
        return;
    }

    sql = "select borrowlogid from borrowlog where keeperid = '" + idNum + "' or userid = '" + idNum + "'";
    query.exec(sql);
    while(query.next())
    {
        QMessageBox::information(NULL, "error.", "���н軹��Ʒ��¼,�޷�ɾ��!");
        return;
    }

    sql = "delete from users where username = '" + username + "' and idcard = '" + idcard + "' and role = '" + role + "' and usersid = '" + idNum + "'";
    query.exec(sql);

    ui->lineEdit_1->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->plainTextEdit->clear();
    currentTableModel->select();
    ui->label_10->clear();

    if(userzw != "")
    {
        int userid = idNum.toInt();
        removeFingerTempMap(userid);
    }
}

void registerDialog::on_pushButton_7_clicked()
{
    //ˢ����Ϣ
    init();
}

void registerDialog::on_tableView_clicked(const QModelIndex &index)
{
    //����б�
    int curRow = index.row(); //��ȡѡ�е���

    ui->lineEdit_1->setText(currentTableModel->index(curRow, 0).data().toString());
    ui->lineEdit_2->setText(currentTableModel->index(curRow, 1).data().toString());
    ui->lineEdit_3->setText(currentTableModel->index(curRow, 2).data().toString());
    ui->comboBox->setCurrentIndex(currentTableModel->index(curRow, 3).data().toInt());
    ui->plainTextEdit->setPlainText(currentTableModel->index(curRow, 4).data().toString());
}

void registerDialog::finishImageReceived()
{
    //ָ��ͼ�����
    qFinger->SaveBitmap();
    ui->label_2->setPixmap(QPixmap(fingerBmpPath));
}

void registerDialog::finishFeatureInfo(int Aquality)
{
    //ָ����������
    switch(Aquality)
    {
    case 0:
        ui->label_3->setText("ָ������ : �ϸ�");
        break;
    case 1:
        ui->label_3->setText("ָ������ : �����㲻��");
        break;
    case 2:
        ui->label_3->setText("ָ������ : �޷�ȡ��ָ������");
        break;
    default:
        ui->label_3->setText("ָ������ : ");
        break;
    }

    if(qFinger->IsRegister())
    {
        ui->label_10->clear();
        ui->label_10->setText("���谴ѹ���� : " + QString::number(qFinger->EnrollIndex()-1, 10) + " ��");
    }
}

void registerDialog::finishEnroll(QString ATemplate)
{
    //�Ǽ����
    if(ATemplate == "false")
    {
        QMessageBox::information(NULL, "error.", "�Ǽ�ʧ��,�����µǼ�.");
    }
    else
    {
        //ָ�ƶԱ�
        QVariant fingerTempVar = qFinger->DecodeTemplate(ATemplate);
        QMapIterator<int, QVariant> i(fingerTemplateMap);
        while (i.hasNext())
        {
            i.next();
            if(qFinger->VerFinger(fingerTempVar, i.value()))
            {
                QMessageBox::information(NULL, "error.", "�Ѿ��Ǽǹ�����ָ,�������ָ�Ǽ�.");
                return;
            }
        }
        ui->label_10->clear();
        ui->label_10->setText("�Ǽǳɹ�!");
        ui->plainTextEdit->setPlainText(ATemplate);
    }
}
