#include "maindialog.h"
#include "ui_maindialog.h"

mainDialog::mainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainDialog)
{
    ui->setupUi(this);

    connect(&groupw, SIGNAL(addGroup()), &addw, SLOT(initComboBox_2()));
    connect(&groupw, SIGNAL(addGroup()), &sgroupw, SLOT(initComboBox_2()));
}

mainDialog::~mainDialog()
{
    delete ui;
}

void mainDialog::on_pushButton_clicked()
{
    //��ַ��
    addw.show();
}

void mainDialog::on_pushButton_2_clicked()
{
    //��Ϣ����
    smsw.show();
}

void mainDialog::on_pushButton_3_clicked()
{
    //��Ա����
    userw.show();
}

void mainDialog::on_pushButton_4_clicked()
{
    //����Excel
    QExcel *saveXls = 0;
    QSqlQuery query;
    int saveRow = 2;
    QString saveXlsName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                       "",
                                                       tr("Excel (*.xls)"));

    if(saveXlsName.length() == 0)
    {
        QMessageBox::information(NULL, tr("Path"), tr("û��ѡ���κ��ļ�."));
    }
    else
    {
        saveXls = new QExcel;
        if(saveXls->setXlsFilePath(saveXlsName))
        {
            QMessageBox::information(NULL, tr("Path"), tr("�ļ��Ѿ�����."));
        }
        else
        {
            //create file
            copyFileToPath(":/book.xls", saveXlsName, true);

            QFile fileChange(saveXlsName);
            fileChange.setPermissions(QFile::WriteOwner);

            if(saveXls->setXlsFilePath(saveXlsName))
            {
                //success
                saveXls->setSheetName(1, QDate::currentDate().toString("yyyy.MM.dd"));
                saveXls->selectSheet(1);

                query.exec("select * from address");
                while(query.next())
                {
                    saveXls->setCellString(saveRow, 1, query.value(1).toString());
                    saveXls->setCellString(saveRow, 2, query.value(2).toString());
                    saveXls->setCellString(saveRow, 3, query.value(3).toString());
                    saveXls->setCellString(saveRow, 4, query.value(4).toString());
                    saveXls->setCellString(saveRow, 5, query.value(5).toString());
                    saveXls->setCellString(saveRow, 6, query.value(6).toString());
                    saveXls->setCellString(saveRow, 7, query.value(7).toString());
                    saveXls->setCellString(saveRow, 8, query.value(8).toString());
                    saveXls->setCellString(saveRow, 9, query.value(9).toString());
                    saveRow++;
                }

                saveXls->save();
                delete saveXls;
            }
            else
            {
                QMessageBox::information(NULL, QString("ʧ��"), QString("�ļ�����ʧ��!"));

                delete saveXls;
                return;
            }
        }
        QMessageBox::information(NULL, tr("Save"), tr("Success!"));
    }
}

void mainDialog::on_pushButton_5_clicked()
{
    //������Ϣ
    groupw.show();
}

void mainDialog::on_pushButton_6_clicked()
{
    //�����ѯ
    sgroupw.show();
}
