#include "frontwidget.h"
#include "ui_frontwidget.h"

frontWidget::frontWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frontWidget)
{
    ui->setupUi(this);

    //���ݿⲿ��
    currentTableModel_1 = new QSqlTableModel(this);
    currentView_1 = ui->tableView;
    currentTableModel_2 = new QSqlTableModel(this);
    currentView_2 = ui->tableView_2;
    on_pushButton_4_clicked();

    //��Ƶ���Ų���
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    mediaObject = new Phonon::MediaObject(this);
    connect(mediaObject, SIGNAL(stateChanged(Phonon::State,Phonon::State)),
            this, SLOT(stateChanged(Phonon::State,Phonon::State)));
    connect(mediaObject, SIGNAL(currentSourceChanged(Phonon::MediaSource)),
            this, SLOT(sourceChanged(Phonon::MediaSource)));
    connect(mediaObject, SIGNAL(aboutToFinish()), this, SLOT(aboutToFinish()));
    Phonon::createPath(mediaObject, audioOutput);

    //��������
    volumeSlider = new Phonon::VolumeSlider(this);
    volumeSlider->setAudioOutput(audioOutput);
    volumeSlider->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    volumeSlider->setGeometry(570, 350, 75, 32);

    //��յ��̨
    QString sql_1;
    QSqlQuery query_1;
    QString sql_2;
    QSqlQuery query_2;
    int idNum = 0;
    sql_1 = "select songsListid from songsList";
    query_1.exec(sql_1);
    while(query_1.next())
    {
        idNum = query_1.value(0).toInt();
        sql_2 = "delete from songsList where songsListid = '" + QString::number(idNum, 10) + "'";
        query_2.exec(sql_2);
    }

    connect(&loginw, SIGNAL(returnDialog()), this, SLOT(returnShow()));

    //��ͣ��־
    pauseFlag = false;
}

frontWidget::~frontWidget()
{
    delete ui;
}

void frontWidget::on_pushButton_4_clicked()
{
    //��ѯ
    QString tmp = ui->lineEdit->text().trimmed();
    currentTableModel_2->setTable("songsLibrary");
    if(!tmp.isEmpty())
        currentTableModel_2->setFilter("name like '%" + tmp + "%' or artist like '%" + tmp + "%'");

    currentTableModel_2->removeColumn(4);
    currentTableModel_2->removeColumn(3);
    currentTableModel_2->removeColumn(0);

    currentTableModel_2->select(); //ѡȡ�������������
    currentView_2->setModel(currentTableModel_2);
    currentView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    //ȥ��tableWidget�Դ����к�
    QHeaderView* headerView = currentView_2->verticalHeader();
    headerView->setHidden(true);
}

void frontWidget::on_pushButton_clicked()
{
    //�и�
    QString sql;
    QSqlQuery query;
    QString tmp;

    //��¼topId����
    sql = "select songsListid from songsList where name = '"
            + currentTableModel_1->index(0, 0).data().toString()
            + "' and artist ='" + currentTableModel_1->index(0, 1).data().toString() + "'";
    query.exec(sql);
    while(query.next())
        tmp = query.value(0).toString();

    sql = "delete from songsList where songsListid = '" + tmp + "'";
    query.exec(sql);

    currentTableModel_1->select();

    if(currentTableModel_1->rowCount() == 0)
    {
        sql = "select path from songsLibrary";
        query.exec(sql);
        while(query.next())
            tmp = query.value(0).toString();

        mediaObject->stop();
        mediaObject->setCurrentSource(Phonon::MediaSource(tmp));
        mediaObject->play();
        return;
    }

    sql = "select path from songsList where name = '"
            + currentTableModel_1->index(0, 0).data().toString()
            + "' and artist ='" + currentTableModel_1->index(0, 1).data().toString() + "'";
    query.exec(sql);
    while(query.next())
        tmp = query.value(0).toString();

    qDebug() << "tmp = " << tmp << endl;

    mediaObject->stop();
    mediaObject->setCurrentSource(Phonon::MediaSource(tmp));
    mediaObject->play();
}

void frontWidget::on_pushButton_2_clicked()
{
    //ɾ��
    QString sql;
    QSqlQuery query;
    int curRow = currentView_1->currentIndex().row(); //��ȡѡ�е���
    QString tmp;

    sql = "select songsListid from songsList where name = '"
            + currentTableModel_1->index(curRow, 0).data().toString()
            + "' and artist ='" + currentTableModel_1->index(curRow, 1).data().toString() + "'";
    query.exec(sql);
    while(query.next())
        tmp = query.value(0).toString();

    sql = "delete from songsList where songsListid = '" + tmp + "'";
    query.exec(sql);

    currentTableModel_1->select();

    if(currentTableModel_1->rowCount() == 0)
    {
        sql = "select path from songsLibrary";
        query.exec(sql);
        while(query.next())
            tmp = query.value(0).toString();

        mediaObject->stop();
        mediaObject->setCurrentSource(Phonon::MediaSource(tmp));
        mediaObject->play();
        return;
    }

    if(curRow == 0)
    {
        sql = "select path from songsLibrary where name = '"
                + currentTableModel_1->index(0, 0).data().toString()
                + "' and artist ='" + currentTableModel_1->index(0, 1).data().toString() + "'";
        query.exec(sql);
        while(query.next())
            tmp = query.value(0).toString();

        mediaObject->stop();
        mediaObject->setCurrentSource(Phonon::MediaSource(tmp));
        mediaObject->play();
    }
}

void frontWidget::on_pushButton_3_clicked()
{
    //����
    QString sql;
    QSqlQuery query;
    QString tmpSql;
    QSqlQuery tmpQuery;
    QString selectId;
    int topId = 0;
    int idNum = 0;
    int i = 0;
    QStringList queryValue[100];

    //��¼topId����
    sql = "select songsListid from songsList where name = '"
            + currentTableModel_1->index(0, 0).data().toString()
            + "' and artist ='" + currentTableModel_1->index(0, 1).data().toString() + "'";
    query.exec(sql);
    while(query.next())
        topId = query.value(0).toInt();

    //�ҳ�ѡ�е�ID����
    int curRow = currentView_1->currentIndex().row(); //��ȡѡ�е���
    sql = "select * from songsList where name = '"
            + currentTableModel_1->index(curRow, 0).data().toString()
            + "' and artist = '" + currentTableModel_1->index(curRow, 1).data().toString() + "'";
    query.exec(sql);
    while(query.next())
    {
        selectId = query.value(0).toString();
    }

    //������topId, ��ѡ�к���ɾ��
    sql = "select * from songsList where songsListid <> '" + QString::number(topId, 10) + "' and songsListid <> '" + selectId + "'";
    query.exec(sql);
    while(query.next())
    {
        queryValue[i++] << query.value(1).toString() << query.value(2).toString() << query.value(3).toString();

        tmpSql = "delete from songsList where songsListid = '" + query.value(0).toString() + "'";
        tmpQuery.exec(tmpSql);
    }

    //��ѡ�е�id���Ϊ id+1 ����
    idNum = topId + 1;
    sql = "update songsList set songsListid = '" + QString::number(idNum, 10)
            + "' where songsListid = '" + selectId + "'";
    query.exec(sql);

    //��ɾ���������
    for(int j=0; j<i; j++)
    {
        sql = "insert into songsList values ('" + QString::number(++idNum, 10)
                + "', '" + queryValue[j].at(0)
                + "', '" + queryValue[j].at(1)
                + "', '" + queryValue[j].at(2)
                + "')";
        query.exec(sql);
    }

    currentTableModel_1->select();
}

void frontWidget::on_pushButton_5_clicked()
{
    //��̨
    this->close();
    loginw.show();
}

void frontWidget::on_tableView_2_doubleClicked(const QModelIndex &index)
{
    //�б�˫�����
    int selected = 0;
    currentTableModel_1->setTable("songsList");
    currentTableModel_1->removeColumn(3);
    currentTableModel_1->removeColumn(0);
    currentTableModel_1->select(); //ѡȡ�������������
    currentView_1->setModel(currentTableModel_1);
    currentView_1->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭

    QString sql;
    QSqlQuery query;
    int curRow = currentView_2->currentIndex().row(); //��ȡѡ�е���
    QString tmp;
    int idNum = 0;

    sql = "select path, selected from songsLibrary where name = '"
            + currentTableModel_2->index(curRow, 0).data().toString()
            + "' and artist ='" + currentTableModel_2->index(curRow, 1).data().toString() + "'";
    query.exec(sql);
    while(query.next())
    {
        tmp = query.value(0).toString();
        selected = query.value(1).toInt()+1;
    }
    query.exec("update songsLibrary set selected = '" + QString::number(selected, 10) + "' where name = '"
               + currentTableModel_2->index(curRow, 0).data().toString()
               + "' and artist ='" + currentTableModel_2->index(curRow, 1).data().toString() + "'");

    sql = "select songsListid from songsList";
    query.exec(sql);
    while(query.next())
    {
        if(idNum < query.value(0).toInt())
            idNum = query.value(0).toInt();
    }

    idNum++;

    sql = "insert into songsList values ('"
            + QString::number(idNum, 10) + "', '"
            + currentTableModel_2->index(curRow, 0).data().toString() + "', '"
            + currentTableModel_2->index(curRow, 1).data().toString() + "', '"
            + tmp + "')";
    query.exec(sql);

    currentTableModel_1->select(); //ѡȡ�������������

    if(currentTableModel_1->rowCount() == 1)
    {
        //����б��
        mediaObject->stop();
        mediaObject->setCurrentSource(Phonon::MediaSource(tmp));
        mediaObject->play();
    }
}

void frontWidget::stateChanged(Phonon::State newState, Phonon::State /* oldState */)
{
    qDebug() << "stateChanged" << newState << endl;

    QString sql;
    QSqlQuery query;
    QString tmp;

    switch (newState)
    {
    case Phonon::ErrorState:
        if (mediaObject->errorType() == Phonon::FatalError)
            QMessageBox::warning(this, tr("Fatal Error"), mediaObject->errorString());
        else
            QMessageBox::warning(this, tr("Error"), mediaObject->errorString());
        break;

    case Phonon::PlayingState:
        break;
    case Phonon::StoppedState:
        break;
    case Phonon::PausedState:
        //���������������ͣ
        if(pauseFlag == false)
        {
            if(currentTableModel_1->rowCount() == 0)
            {
                sql = "select path from songsLibrary where name = '"
                        + currentTableModel_2->index(0, 0).data().toString()
                        + "' and artist ='" + currentTableModel_2->index(0, 1).data().toString() + "'";
                query.exec(sql);
                while(query.next())
                    tmp = query.value(0).toString();
            }
            else
            {
                //����б��
                sql = "select path from songsList where name = '"
                        + currentTableModel_1->index(0, 0).data().toString()
                        + "' and artist ='" + currentTableModel_1->index(0, 1).data().toString() + "'";
                query.exec(sql);
                while(query.next())
                    tmp = query.value(0).toString();
            }

            mediaObject->stop();
            mediaObject->setCurrentSource(Phonon::MediaSource(tmp));
            mediaObject->play();
        }
        else
        {
            //��ͣ
        }
        break;
    case Phonon::BufferingState:
        break;
    default:
        break;
    }
}

void frontWidget::sourceChanged(const Phonon::MediaSource &source)
{
    qDebug() << "sourceChanged" << endl;
}

void frontWidget::aboutToFinish()
{
    //������������źŲ�
    qDebug() << "aboutToFinish" << endl;
    QString sql;
    QSqlQuery query;
    QString tmp;

    //��¼topId����
    sql = "select songsListid from songsList where name = '"
            + currentTableModel_1->index(0, 0).data().toString()
            + "' and artist ='" + currentTableModel_1->index(0, 1).data().toString() + "'";
    query.exec(sql);
    while(query.next())
        tmp = query.value(0).toString();

    sql = "delete from songsList where songsListid = '" + tmp + "'";
    query.exec(sql);

    currentTableModel_1->select();
}

void frontWidget::returnShow()
{
    //������ʾ
    this->show();
}

void frontWidget::on_pushButton_6_clicked()
{
    //��ͣ
    if(pauseFlag == false)
    {
        mediaObject->pause();
        pauseFlag = true;
    }
    else
    {
        pauseFlag = false;
        mediaObject->play();
    }
}

void frontWidget::on_pushButton_7_clicked()
{
    //���а�
    songTopw.show();
}

void frontWidget::paintEvent(QPaintEvent *)
{
    //����ͼƬ
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/png/2.png").scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}
