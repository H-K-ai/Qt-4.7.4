#include "musicdialog.h"
#include "ui_musicdialog.h"

musicDialog::musicDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::musicDialog)
{
    ui->setupUi(this);

    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    mediaObject = new Phonon::MediaObject(this);

    connect(mediaObject, SIGNAL(tick(qint64)), this, SLOT(tick(qint64)));
    connect(mediaObject, SIGNAL(stateChanged(Phonon::State,Phonon::State)),
            this, SLOT(stateChanged(Phonon::State,Phonon::State)));
    connect(mediaObject, SIGNAL(currentSourceChanged(Phonon::MediaSource)),
            this, SLOT(sourceChanged(Phonon::MediaSource)));
    connect(mediaObject, SIGNAL(aboutToFinish()), this, SLOT(aboutToFinish()));

    Phonon::createPath(mediaObject, audioOutput);

    playAction = new QAction(style()->standardIcon(QStyle::SP_MediaPlay), tr("Play"), this);
    playAction->setShortcut(tr("Ctrl+P"));
    playAction->setDisabled(true);
    pauseAction = new QAction(style()->standardIcon(QStyle::SP_MediaPause), tr("Pause"), this);
    pauseAction->setShortcut(tr("Ctrl+A"));
    pauseAction->setDisabled(true);
    stopAction = new QAction(style()->standardIcon(QStyle::SP_MediaStop), tr("Stop"), this);
    stopAction->setShortcut(tr("Ctrl+S"));
    stopAction->setDisabled(true);

    connect(playAction, SIGNAL(triggered()), mediaObject, SLOT(play()));
    connect(pauseAction, SIGNAL(triggered()), mediaObject, SLOT(pause()) );
    connect(stopAction, SIGNAL(triggered()), mediaObject, SLOT(stop()));

    seekSlider = new Phonon::SeekSlider(this);
    seekSlider->setMediaObject(mediaObject);

    QPalette palette;
    palette.setBrush(QPalette::Light, Qt::darkGray);
    timeLcd = new QLCDNumber;
    timeLcd->setPalette(palette);

    bar = new QToolBar;
    bar->addAction(playAction);
    bar->addAction(pauseAction);
    bar->addAction(stopAction);

    volumeSlider = new Phonon::VolumeSlider(this);
    volumeSlider->setAudioOutput(audioOutput);
    volumeSlider->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    QHBoxLayout *seekerLayout = new QHBoxLayout;
    seekerLayout->addWidget(seekSlider);
    seekerLayout->addWidget(timeLcd);

    QHBoxLayout *playbackLayout = new QHBoxLayout;
    playbackLayout->addWidget(bar);
    playbackLayout->addStretch();
    playbackLayout->addWidget(volumeSlider);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(seekerLayout);
    mainLayout->addLayout(playbackLayout);

    ui->groupBox_3->setLayout(mainLayout);

    timeLcd->display("00:00");

    mediaObject->setTickInterval(1000);

    currentTableModel = new QSqlTableModel(this);
    currentView = ui->tableView;

    currentTableModel->setTable("music");
    currentTableModel->select();
    currentView->setModel(currentTableModel);
    currentView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

musicDialog::~musicDialog()
{
    delete ui;
}

void musicDialog::closeEvent(QCloseEvent *)
{
    mediaObject->stop();
}

void musicDialog::paintEvent(QPaintEvent *)
{
    //QPainter painter(this);
    //painter.drawPixmap(0, 0, QPixmap(":/frame.png").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void musicDialog::on_pushButton_clicked()
{
    //�������
    QString sourcePath = QFileDialog::getOpenFileName(this, tr("Open mp3"), ".", tr("MP3 Files(*.mp3)"));
    if(sourcePath.length() == 0)
    {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
        return;
    }
    else
    {
        QMessageBox::information(NULL, tr("Path"), tr("You selected ") + sourcePath);
    }

    QString title = sourcePath;
    while(title.indexOf("/") != -1)
    {
        title = title.right(title.length()-title.indexOf("/")-1);
    }

    title.remove(".mp3", Qt::CaseInsensitive);

    QSqlQuery query;
    query.exec("select name from music");
    while(query.next())
    {
        if(title == query.value(0).toString())
        {
            QMessageBox::information(NULL, tr("repeat"), tr("music title repeat!"));
            return;
        }
    }

    QString targetPath = "music/" + title + ".mp3";

    int rowNum = currentTableModel->rowCount(); //��ñ������
    int id = currentTableModel->record(rowNum - 1).value(0).toInt() + 1;
    currentTableModel->insertRow(rowNum); //���һ��
    currentTableModel->setData(currentTableModel->index(rowNum, 0), id);
    currentTableModel->setData(currentTableModel->index(rowNum, 1), title);
    currentTableModel->setData(currentTableModel->index(rowNum, 2), targetPath);
    currentTableModel->setData(currentTableModel->index(rowNum, 3), QString("0"));

    copyFileToPath(sourcePath, targetPath, true); //����ʽ����

    currentTableModel->submitAll();

    emit addMusic();
}

void musicDialog::on_pushButton_2_clicked()
{
    //ɾ������
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    int rowNum = currentTableModel->rowCount(); //��ñ������

    if(1 == currentTableModel->index(curRow, 3).data().toInt())
    {
        if(rowNum == 1)
        {
            //NULL
        }
        else
        {
            if(curRow != 0)
            {
                currentTableModel->setData(currentTableModel->index(0, 3), QString("1"));
                currentTableModel->submitAll();
            }
            else
            {
                currentTableModel->setData(currentTableModel->index(1, 3), QString("1"));
                currentTableModel->submitAll();
            }
        }
    }

    currentTableModel->removeRow(curRow); //ɾ������

    emit addMusic();
}

void musicDialog::on_tableView_clicked(const QModelIndex &index)
{
    //�б���
}

void musicDialog::on_tableView_doubleClicked(const QModelIndex &index)
{
    //�б�˫��
    QString musicPath;
    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    musicPath = currentTableModel->index(curRow, 2).data().toString();

    mediaObject->stop();
    mediaObject->setCurrentSource(Phonon::MediaSource(musicPath));
    mediaObject->play();
}

void musicDialog::stateChanged(Phonon::State newState, Phonon::State /* oldState */)
{
    switch (newState) {
    case Phonon::ErrorState:
        if (mediaObject->errorType() == Phonon::FatalError) {
            QMessageBox::warning(this, tr("Fatal Error"),
                                 mediaObject->errorString());
        } else {
            QMessageBox::warning(this, tr("Error"),
                                 mediaObject->errorString());
        }
        break;
    case Phonon::PlayingState:
        playAction->setEnabled(false);
        pauseAction->setEnabled(true);
        stopAction->setEnabled(true);
        break;
    case Phonon::StoppedState:
        stopAction->setEnabled(false);
        playAction->setEnabled(true);
        pauseAction->setEnabled(false);
        timeLcd->display("00:00");
        break;
    case Phonon::PausedState:
        pauseAction->setEnabled(false);
        stopAction->setEnabled(true);
        playAction->setEnabled(true);
        break;
    case Phonon::BufferingState:
        break;
    default:
        ;
    }
}

void musicDialog::tick(qint64 time)
{
    QTime displayTime(0, (time/60000)%60, (time/1000)%60);
    timeLcd->display(displayTime.toString("mm:ss"));
}

void musicDialog::sourceChanged(const Phonon::MediaSource &source)
{
    timeLcd->display("00:00");
}

void musicDialog::aboutToFinish()
{
}

void musicDialog::on_pushButton_3_clicked()
{
    //��Ϊ����
    QSqlQuery query;
    query.exec("update music set alarmsing = 0");

    int curRow = currentView->currentIndex().row(); //��ȡѡ�е���
    currentTableModel->setData(currentTableModel->index(curRow, 3), QString("1"));
    currentTableModel->submitAll();
}
