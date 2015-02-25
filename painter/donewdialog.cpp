#include "donewdialog.h"
#include "ui_donewdialog.h"
#include <QColorDialog>

DoNewDialog::DoNewDialog(QWidget *parent,Qt::WFlags flags ):
    QDialog(parent),ui(new Ui::DoNewDialogClass)
{
    ui->setupUi(this);
    setWindowTitle(tr("��������"));
    setWindowIcon(QIcon("image/huabu.png"));
    backColor = Qt::white;
}
DoNewDialog::~DoNewDialog()
{
    delete ui;
}
void DoNewDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

int DoNewDialog::getWidth()
{
    //��ȡ���
    return ui->widthspinBox->text().toInt();
}
int DoNewDialog::getHeight()
{
    //��ȡ�߶�
    return ui->heightspinBox->text().toInt();
}
QColor DoNewDialog::getBackColor()
{
    //��ȡ����ɫ
    return backColor;
}
void DoNewDialog::on_toolButton_clicked()
{
    //�½�һ��
    QColor newColor = QColorDialog::getColor();
    if (newColor.isValid())
    {
        backColor = newColor;
        QPalette palette = ui->textBrowser->palette();
        palette.setColor(QPalette::Base,backColor);
        ui->textBrowser->setPalette(palette);

        update();
    }
}
bool DoNewDialog::on_buttonBox_clicked() 
{
    return close();
}
