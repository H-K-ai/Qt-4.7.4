#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "donewdialog.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QPainter>
#include <QDebug>

extern QRgb backColor; 

MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags) :
    QMainWindow(parent, flags),ui(new Ui::MainWindowClass)
{
    ui->setupUi(this);

    //��ʼ��
    setWindowTitle(tr("��ͼ"));
    setWindowIcon(QIcon("image/Holiday.png"));
    setFixedSize(700,500);
    area = new PaintArea;
    scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(area);
    scrollArea->widget()->setMinimumSize(800,600);
    setCentralWidget(scrollArea);
    curFile = tr("δ����.png");
    creatColorComboBox(ui->pencolorcomboBox);
    creatColorComboBox(ui->brushcolorcomboBox);
}

MainWindow::~MainWindow()
{
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::doOpen()
{
    //���ļ�
    if (maybeSave())
    {
        QString fileName = QFileDialog::getOpenFileName(this,
                                                        tr("���ļ�"), QDir::currentPath());
        if (!fileName.isEmpty())
        {
            area->openImage(fileName);
            scrollArea->widget()->resize(area->getImageSize());
            isSaved = true;
            curFile = fileName;
        }
    }
}

void MainWindow::doNew()
{
    //�������ļ�
    if(maybeSave())
    {
        on_action_K_triggered();
        isSaved = false;
    }
}

bool MainWindow::maybeSave()
{
    //�Ƿ�Ҫ����
    if(area->isModified())
    {
        QMessageBox::StandardButton box;
        box = QMessageBox::warning(this,tr("�����ļ�"),tr("���뱣�浱ǰͼƬ��"),
                                   QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
        if(box == QMessageBox::Yes)
        {
            return doFileSaveAs();
        }
        else if(box == QMessageBox::Cancel)
        {
            return false;
        }
    }
    return true;
}

bool MainWindow::doFileSave()
{
    //�Ƿ񱣴��ļ�
    if(isSaved)
    {
        return saveFile(curFile);
    }
    else return doFileSaveAs();
}

bool MainWindow::saveFile(QString fileName)
{
    //�����ļ�����
    if(area->saveImage(fileName,"png"))
    {
        isSaved = true;
        return true;
    }
    else return false;
}

bool MainWindow::doFileSaveAs()
{
    //���Ϊ
    QString fileName = QFileDialog::getSaveFileName(this,tr("���Ϊ"),curFile);
    if(fileName.isEmpty())
    {
        return false;
    }
    else return saveFile(fileName);
}

void MainWindow::on_action_N_triggered()
{
    //�������ļ��Ĳۺ���
    doNew();
}

void MainWindow::on_action_O_triggered() 
{
    //���ļ��Ĳۺ���
    doOpen();
}

void MainWindow::on_action_S_triggered()
{
    //�����ļ��Ĳۺ���
    doFileSave();
}

void MainWindow::on_action_A_triggered()
{
    //���Ϊ�ļ��Ĳۺ���
    doFileSaveAs();
}

void MainWindow::on_action_W_triggered()
{
    //������ڵĲۺ���
    area->aboutus();
}

void MainWindow::on_action_triggered() 
{
    //�Ƿ񱣴�Ĳۺ���
    if(maybeSave())
        qApp->quit();
}

void MainWindow::closeEvent(QCloseEvent *event) 
{
    //���ڹرյĲۺ���
    if(maybeSave())
        qApp->quit();
    else event->ignore();
}

void MainWindow::on_action_R_triggered()
{
    //��ת�Ĳۺ���
    area->doRotate();
}

void MainWindow::on_action_Eraser_triggered() 
{
    //��Ƥ���Ĳۺ���
    area->setShape(PaintArea::None);
    area->setPenWidth(8);
    area->setPenColor (qRgb(255,255,255));
}

void MainWindow::on_action_C_triggered() 
{
    //��յĲۺ���
    area->doClear();
}

void MainWindow::creatColorComboBox(QComboBox *comboBox)
{
    //��ʼ��һ����ɫ������ؼ�
    QPixmap pix(16,16);
    QPainter painter(&pix);
    painter.fillRect(0,0,16,16,Qt::black);
    comboBox->addItem(QIcon(pix),tr("��ɫ"),Qt::black);
    painter.fillRect(0,0,16,16,Qt::white);
    comboBox->addItem(QIcon(pix),tr("��ɫ"),Qt::white);
    painter.fillRect(0,0,16,16,Qt::red);
    comboBox->addItem(QIcon(pix),tr("��ɫ"),Qt::red);
    painter.fillRect(0,0,16,16,Qt::green);
    comboBox->addItem(QIcon(pix),tr("��ɫ"),Qt::green);
    painter.fillRect(0,0,16,16,Qt::blue);
    comboBox->addItem(QIcon(pix),tr("��ɫ"),Qt::blue);
    painter.fillRect(0,0,16,16,Qt::yellow);
    comboBox->addItem(QIcon(pix),tr("��ɫ"),Qt::yellow);
    comboBox->addItem(tr("����ɫ"),Qt::transparent);
}

void MainWindow::on_shapecomboBox_currentIndexChanged(QString shape) 
{
    //�ʻ���ѡ��
    if(shape == tr("��ͨ����"))
        area->setShape(PaintArea::None);
    else if(shape == tr("����"))
        area->setShape(PaintArea::Rectangle);
    else if(shape == tr("ֱ��"))
        area->setShape(PaintArea::Line);
    else if(shape == tr("��Բ"))
        area->setShape(PaintArea::Ellipse);
    else if(shape == tr("������"))
        area->setShape(PaintArea::Triangle);
    else if(shape == tr("�����ı���"))
        area->setShape(PaintArea::Fourline);
}

void MainWindow::on_penstylecomboBox_currentIndexChanged(QString style) 
{
    //������ѡ��
    if(style == tr("ʵ��"))
    {
        area->setPenStyle(Qt::SolidLine);
    }
    else if(style == tr("����"))
    {
        area->setPenStyle(Qt::DotLine);
    }
    else if(style == tr("������"))
    {
        area->setPenStyle(Qt::DashLine);
    }
}

void MainWindow::on_penwidthspinBox_valueChanged(int width)
{
    //ѡ���
    area->setPenWidth(width);
}

void MainWindow::on_pencolorcomboBox_currentIndexChanged(int index) 
{
    //����ɫѡ��
    QColor color = ui->pencolorcomboBox->itemData(index,Qt::UserRole).value<QColor>();
    area->setPenColor(color);
}

void MainWindow::on_brushcolorcomboBox_currentIndexChanged(int index) 
{
    //�����ɫѡ��
    QColor color = ui->brushcolorcomboBox->itemData(index,Qt::UserRole).value<QColor>();
    area->setBrushColor(color);
}

void MainWindow::on_action_K_triggered() 
{
    //�µĻ����ۺ���
    DoNewDialog dlg;
    dlg.show();
    if(dlg.exec()!=QDialog::Accepted)
        dlg.show();
    int width = dlg.getWidth();
    int height = dlg.getHeight();
    area->setImageSize(width,height);
    scrollArea->widget()->resize(width,height);
    area->setImageColor(dlg.getBackColor());
}
