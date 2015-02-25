#include "sizedialog.h"
#include "ui_sizedialog.h"

sizeDialog::sizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sizeDialog)
{
    ui->setupUi(this);
}

sizeDialog::~sizeDialog()
{
    delete ui;
}
void sizeDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/png/bj51.png").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void sizeDialog::on_pushButton_clicked()
{
    //����
    double height = ui->lineEdit_3->text().trimmed().toDouble();
    int gender = ui->radioButton_3->isChecked();
    double result = 0;

    if(height == 0)
    {
        QMessageBox::information(NULL, tr("height"), tr("height is zero!"));
    }
    else
    {
        if(gender==true)
        {
            //ѡ����
            qDebug() << "ѡ����" << endl;

            result = height*0.48;
            ui->label_10->setText("��Χ : " + QString::number(result, 'g') + " CM");
            result = height*0.47;
            ui->label_11->setText("��Χ : " + QString::number(result, 'g') + " CM");
            result = height*0.51;
            ui->label_12->setText("��Χ : " + QString::number(result, 'g') + " CM");
        }
        else
        {
            result = height*0.51;
            ui->label_10->setText("��Χ : " + QString::number(result, 'g') + " CM");
            result = height*0.34;
            ui->label_11->setText("��Χ : " + QString::number(result, 'g') + " CM");
            result = height*0.542;
            ui->label_12->setText("��Χ : " + QString::number(result, 'g') + " CM");
        }
    }
}
