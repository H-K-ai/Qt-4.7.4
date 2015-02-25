#include "adminwidget.h"
#include "ui_adminwidget.h"

adminWidget::adminWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminWidget)
{
    ui->setupUi(this);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;
    metaInformationResolver = new Phonon::MediaObject(this);
    connect(metaInformationResolver, SIGNAL(metaDataChanged()),
            this, SLOT(mataDataChanged()));

    on_pushButton_clicked();
}

adminWidget::~adminWidget()
{
    delete ui;
}

void adminWidget::on_pushButton_clicked()
{
    //������
    currentTableModel->setTable("songsLibrary");
    currentTableModel->select(); //ѡȡ�������������

    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    songOrMember = true;
}

void adminWidget::on_pushButton_2_clicked()
{
    //��Ա����
    currentTableModel->setTable("member");
    currentTableModel->select(); //ѡȡ�������������

    songOrMember = false;
}

void adminWidget::on_pushButton_3_clicked()
{
    //���
    int rowNum = currentTableModel->rowCount(); //��ñ������
    int id = currentTableModel->record(rowNum - 1).value(0).toInt() + 1;
    currentTableModel->insertRow(rowNum); //���һ��
    currentTableModel->setData(currentTableModel->index(rowNum, 0), id);

    if(songOrMember)
    {
        //������
        sourcePath = QFileDialog::getOpenFileName(this, tr("Open mp3"), ".", tr("Image Files(*.mp3)"));
        if(sourcePath.length() == 0) {
            QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
        } else {
            QMessageBox::information(NULL, tr("Path"), tr("You selected ") + sourcePath);
        }
       // metaInformationResolver->clear();
        metaInformationResolver->setCurrentSource(sourcePath);
        currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭
    }
    else
    {
        currentView->setEditTriggers(QAbstractItemView::DoubleClicked);  //ʹ��ɱ༭
    }
}

void adminWidget::on_pushButton_4_clicked()
{
    //ɾ��
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->removeRow(curRow); //ɾ������
}

void adminWidget::on_pushButton_5_clicked()
{
    //�޸�
    currentView->setEditTriggers(QAbstractItemView::DoubleClicked);  //ʹ��ɱ༭
}

void adminWidget::on_pushButton_6_clicked()
{
    //�ύ
    currentTableModel->submitAll();
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭
}

void adminWidget::mataDataChanged()
{
    QMap<QString, QString> metaData = metaInformationResolver->metaData();

    QString title = metaData.value("TITLE");
    if (title == "")
    {
        title = sourcePath;
        while(title.indexOf("/") != -1)
        {
            title = title.right(title.length()-title.indexOf("/")-1);
        }

        title.remove(".mp3", Qt::CaseInsensitive);
    }
    QString artist = metaData.value("ARTIST");
    if (artist == "")
        artist = "NOARTIST";

    QString targetPath = "songsLibrary/" + title + "-" + artist + ".mp3";
    qDebug() << targetPath << endl;

    int rowNum = currentTableModel->rowCount()-1; //��ñ������
    currentTableModel->setData(currentTableModel->index(rowNum, 1), title);
    currentTableModel->setData(currentTableModel->index(rowNum, 2), artist);
    currentTableModel->setData(currentTableModel->index(rowNum, 3), 0);
    currentTableModel->setData(currentTableModel->index(rowNum, 4), targetPath);

    copyFileToPath(sourcePath, targetPath, true); //����ʽ����

    currentTableModel->submitAll();
}

void adminWidget::on_pushButton_7_clicked()
{
    //�˳���¼
    this->close();
    emit returnDialog();
}

void adminWidget::paintEvent(QPaintEvent *)
{
    //����ͼƬ
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/png/1.png").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}
