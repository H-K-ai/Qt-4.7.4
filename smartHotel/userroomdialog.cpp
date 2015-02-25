#include "userroomdialog.h"
#include "ui_userroomdialog.h"

userRoomDialog::userRoomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userRoomDialog)
{
    ui->setupUi(this);

    scene.setSceneRect(0, 0, 795, 595);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setStyleSheet("background: transparent");

    //����
    room = new roomItem;
    room->setPos(int(scene.sceneRect().width() / 2),
                 int(scene.sceneRect().height() / 2));
    room->setRotation(0);
    scene.addItem(room);

    //�ƹ�
    light1 = new lightOneItem;
    light1->setPos(int(417 * 0.8 - 3),
                   int(341.5 * 0.8 - 3));
    light1->setRotation(0);
    scene.addItem(light1);

    light2 = new lightTwoItem;
    light2->setPos(int(852 * 0.8 - 3),
                   int(310 * 0.8) - 3);
    light2->setRotation(0);
    scene.addItem(light2);

    light3 = new lightThrItem;
    light3->setPos(int(429 * 0.8 - 3),
                   int(76.5 * 0.8 - 3));
    light3->setRotation(0);
    scene.addItem(light3);

    //ʱ��
    time = new timeItem;
    time->setPos(int(scene.sceneRect().width() - (time->timeWidth) / 2 - 20),
                 int(scene.sceneRect().height() - (time->timeHeight) / 2));
    time->setRotation(0);
    scene.addItem(time);

    //��ť
    ui->pushButton->setStyleSheet(QString("QPushButton{border-image:url(:/images/homeyellow.png);}\n"
                                          "QPushButton:hover{border-image:url(:/images/homeblue.png);}\n"
                                          "QPushButton:pressed{border-image:url(:/images/homegreen.png);}"));

    ui->pushButton_2->setStyleSheet(QString("QPushButton{border-image:url(:/images/buttonyellow.png)0, 0, 0, 0;}\n"
                                            "QPushButton:hover{border-image:url(:/images/buttongreen.png)0, 0, 0, 0;}\n"
                                            "QPushButton:pressed{border-image:url(:/images/buttonblue.png)0, 0, 0, 0;}"));

    ui->pushButton_3->setStyleSheet(QString("QPushButton{border-image:url(:/images/buttonyellow.png)0, 0, 0, 0;}\n"
                                            "QPushButton:hover{border-image:url(:/images/buttongreen.png)0, 0, 0, 0;}\n"
                                            "QPushButton:pressed{border-image:url(:/images/buttonblue.png)0, 0, 0, 0;}"));

    ui->pushButton_18->setStyleSheet(QString("QPushButton{border-image:url(:/images/buttonyellow.png)0, 0, 0, 0;}\n"
                                             "QPushButton:hover{border-image:url(:/images/buttongreen.png)0, 0, 0, 0;}\n"
                                             "QPushButton:pressed{border-image:url(:/images/buttonblue.png)0, 0, 0, 0;}"));
    lightAuto();

    //��������
    ui->label->clear();
    ui->label_2->clear();
    ui->label_3->clear();
    ui->label->setStyleSheet(QString("QLabel{border-image:url(:/images/emtemp.png)0 0 0 0;}"));
    ui->label_2->setStyleSheet(QString("QLabel{border-image:url(:/images/emwater.png)0 0 0 0;}"));
    ui->label_3->setStyleSheet(QString("QLabel{border-image:url(:/images/emfire.png)0 0 0 0;}"));
    ui->pushButton_4->setStyleSheet(QString("QPushButton{border-image:url(:/images/buttonred.png)0, 0, 0, 0;}\n"
                                            "QPushButton:hover{border-image:url(:/images/buttonteal.png)0, 0, 0, 0;}\n"
                                            "QPushButton:pressed{border-image:url(:/images/buttonteal.png)0, 0, 0, 0;}"));
    ui->lcdNumber->display("23 C");
    ui->lcdNumber_2->display("23 H");
    ui->lcdNumber_3->display("23 H");

    //����
    ui->timeEdit->setStyleSheet(QString("QTimeEdit {border: 2px solid gray; padding: 0 8px; background: #fcaad5; selection-background-color: darkgray;}"
                                        "QTimeEdit::up-button {width: 15px; border-image: url(:/images/arrowup.png);}"
                                        "QTimeEdit::down-button {width: 15px; border-image: url(:/images/arrowdown.png);}" ));
    ui->timeEdit_2->setStyleSheet(QString("QTimeEdit {border: 2px solid gray; padding: 0 8px; background: #fcaad5; selection-background-color: darkgray;}"
                                          "QTimeEdit::up-button {width: 15px; border-image: url(:/images/arrowup.png);}"
                                          "QTimeEdit::down-button {width: 15px; border-image: url(:/images/arrowdown.png);}" ));
    ui->timeEdit_3->setStyleSheet(QString("QTimeEdit {border: 2px solid gray; padding: 0 8px; background: #fcaad5; selection-background-color: darkgray;}"
                                          "QTimeEdit::up-button {width: 15px; border-image: url(:/images/arrowup.png);}"
                                          "QTimeEdit::down-button {width: 15px; border-image: url(:/images/arrowdown.png);}" ));
    ui->timeEdit_4->setStyleSheet(QString("QTimeEdit {border: 2px solid gray; padding: 0 8px; background: #fcaad5; selection-background-color: darkgray;}"
                                          "QTimeEdit::up-button {width: 15px; border-image: url(:/images/arrowup.png);}"
                                          "QTimeEdit::down-button {width: 15px; border-image: url(:/images/arrowdown.png);}" ));
    ui->timeEdit_5->setStyleSheet(QString("QTimeEdit {border: 2px solid gray; padding: 0 8px; background: #fcaad5; selection-background-color: darkgray;}"
                                          "QTimeEdit::up-button {width: 15px; border-image: url(:/images/arrowup.png);}"
                                          "QTimeEdit::down-button {width: 15px; border-image: url(:/images/arrowdown.png);}" ));
    ui->timeEdit_6->setStyleSheet(QString("QTimeEdit {border: 2px solid gray; padding: 0 8px; background: #fcaad5; selection-background-color: darkgray;}"
                                          "QTimeEdit::up-button {width: 15px; border-image: url(:/images/arrowup.png);}"
                                          "QTimeEdit::down-button {width: 15px; border-image: url(:/images/arrowdown.png);}" ));

    ui->checkBox_4->setStyleSheet(QString("QCheckBox::indicator{width: 64px; height: 64px;}\n"
                                          "QCheckBox::indicator:unchecked{border-image:url(:/images/bulb.png)0 0 0 0;}\n"
                                          "QCheckBox::indicator:checked{border-image:url(:/images/bulb_.png)0 0 0 0;}"));
    ui->checkBox_5->setStyleSheet(QString("QCheckBox::indicator{width: 64px; height: 64px;}\n"
                                          "QCheckBox::indicator:unchecked{border-image:url(:/images/bulb.png)0 0 0 0;}\n"
                                          "QCheckBox::indicator:checked{border-image:url(:/images/bulb_.png)0 0 0 0;}"));
    ui->checkBox_6->setStyleSheet(QString("QCheckBox::indicator{width: 64px; height: 64px;}\n"
                                          "QCheckBox::indicator:unchecked{border-image:url(:/images/bulb.png)0 0 0 0;}\n"
                                          "QCheckBox::indicator:checked{border-image:url(:/images/bulb_.png)0 0 0 0;}"));

    ui->checkBox->setStyleSheet(QString("QCheckBox::indicator{width: 83px; height: 34px;}\n"
                                        "QCheckBox::indicator:unchecked{border-image:url(:/images/off.png)0 0 0 0;}\n"
                                        "QCheckBox::indicator:checked{border-image:url(:/images/on.png)0 0 0 0;}"));
    ui->checkBox_2->setStyleSheet(QString("QCheckBox::indicator{width: 83px; height: 34px;}\n"
                                          "QCheckBox::indicator:unchecked{border-image:url(:/images/off.png)0 0 0 0;}\n"
                                          "QCheckBox::indicator:checked{border-image:url(:/images/on.png)0 0 0 0;}"));
    ui->checkBox_3->setStyleSheet(QString("QCheckBox::indicator{width: 83px; height: 34px;}\n"
                                          "QCheckBox::indicator:unchecked{border-image:url(:/images/off.png)0 0 0 0;}\n"
                                          "QCheckBox::indicator:checked{border-image:url(:/images/on.png)0 0 0 0;}"));

    //�绰
    ui->lineEdit->setStyleSheet(QString("QLineEdit {border: 2px solid gray; "
                                        "border-radius: 10px; padding: 0 8px; "
                                        "background: #f6b22d; selection-background-color: darkgray;}"));
    ui->pushButton_5->setStyleSheet(QString("QPushButton{border-image:url(:/images/1.png)0, 0, 0, 0;}\n"
                                            "QPushButton:hover{border-image:url(:/images/1_.png)0, 0, 0, 0;}\n"
                                            "QPushButton:pressed{border-image:url(:/images/1_.png)0, 0, 0, 0;}"));
    ui->pushButton_6->setStyleSheet(QString("QPushButton{border-image:url(:/images/2.png)0, 0, 0, 0;}\n"
                                            "QPushButton:hover{border-image:url(:/images/2_.png)0, 0, 0, 0;}\n"
                                            "QPushButton:pressed{border-image:url(:/images/2_.png)0, 0, 0, 0;}"));
    ui->pushButton_7->setStyleSheet(QString("QPushButton{border-image:url(:/images/3.png)0, 0, 0, 0;}\n"
                                            "QPushButton:hover{border-image:url(:/images/3_.png)0, 0, 0, 0;}\n"
                                            "QPushButton:pressed{border-image:url(:/images/3_.png)0, 0, 0, 0;}"));
    ui->pushButton_8->setStyleSheet(QString("QPushButton{border-image:url(:/images/4.png)0, 0, 0, 0;}\n"
                                            "QPushButton:hover{border-image:url(:/images/4_.png)0, 0, 0, 0;}\n"
                                            "QPushButton:pressed{border-image:url(:/images/4_.png)0, 0, 0, 0;}"));
    ui->pushButton_9->setStyleSheet(QString("QPushButton{border-image:url(:/images/5.png)0, 0, 0, 0;}\n"
                                            "QPushButton:hover{border-image:url(:/images/5_.png)0, 0, 0, 0;}\n"
                                            "QPushButton:pressed{border-image:url(:/images/5_.png)0, 0, 0, 0;}"));
    ui->pushButton_10->setStyleSheet(QString("QPushButton{border-image:url(:/images/6.png)0, 0, 0, 0;}\n"
                                             "QPushButton:hover{border-image:url(:/images/6_.png)0, 0, 0, 0;}\n"
                                             "QPushButton:pressed{border-image:url(:/images/6_.png)0, 0, 0, 0;}"));
    ui->pushButton_11->setStyleSheet(QString("QPushButton{border-image:url(:/images/7.png)0, 0, 0, 0;}\n"
                                             "QPushButton:hover{border-image:url(:/images/7_.png)0, 0, 0, 0;}\n"
                                             "QPushButton:pressed{border-image:url(:/images/7_.png)0, 0, 0, 0;}"));
    ui->pushButton_12->setStyleSheet(QString("QPushButton{border-image:url(:/images/8.png)0, 0, 0, 0;}\n"
                                             "QPushButton:hover{border-image:url(:/images/8_.png)0, 0, 0, 0;}\n"
                                             "QPushButton:pressed{border-image:url(:/images/8_.png)0, 0, 0, 0;}"));
    ui->pushButton_13->setStyleSheet(QString("QPushButton{border-image:url(:/images/9.png)0, 0, 0, 0;}\n"
                                             "QPushButton:hover{border-image:url(:/images/9_.png)0, 0, 0, 0;}\n"
                                             "QPushButton:pressed{border-image:url(:/images/9_.png)0, 0, 0, 0;}"));
    ui->pushButton_14->setStyleSheet(QString("QPushButton{border-image:url(:/images/10.png)0, 0, 0, 0;}\n"
                                             "QPushButton:hover{border-image:url(:/images/10_.png)0, 0, 0, 0;}\n"
                                             "QPushButton:pressed{border-image:url(:/images/10_.png)0, 0, 0, 0;}"));
    ui->pushButton_15->setStyleSheet(QString("QPushButton{border-image:url(:/images/0.png)0, 0, 0, 0;}\n"
                                             "QPushButton:hover{border-image:url(:/images/0_.png)0, 0, 0, 0;}\n"
                                             "QPushButton:pressed{border-image:url(:/images/0_.png)0, 0, 0, 0;}"));
    ui->pushButton_16->setStyleSheet(QString("QPushButton{border-image:url(:/images/11.png)0, 0, 0, 0;}\n"
                                             "QPushButton:hover{border-image:url(:/images/11_.png)0, 0, 0, 0;}\n"
                                             "QPushButton:pressed{border-image:url(:/images/11_.png)0, 0, 0, 0;}"));
    ui->pushButton_17->setStyleSheet(QString("QPushButton{border-image:url(:/images/12.png)0, 0, 0, 0;}\n"
                                             "QPushButton:hover{border-image:url(:/images/12_.png)0, 0, 0, 0;}\n"
                                             "QPushButton:pressed{border-image:url(:/images/12_.png)0, 0, 0, 0;}"));

    ui->frame_2->setGeometry(this->width(), 0, ui->frame_2->width(), ui->frame_2->height());
    ui->frame_3->setGeometry(this->width(), 0, ui->frame_3->width(), ui->frame_3->height());
    ui->frame_4->setGeometry(this->width(), 160, ui->frame_4->width(), ui->frame_4->height());

    lightTimer = new QTimer(this);
    connect(lightTimer, SIGNAL(timeout()), this, SLOT(lightTimeOut()));
    connect(lightTimer, SIGNAL(timeout()), &scene, SLOT(advance()));
    lightTimer->start(1000);

    //����һ���ṹ�壬������Ŵ��ڸ�������
    struct PortSettings myComSetting = {BAUD9600, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 500};
    //���崮�ڶ��󣬲����ݲ������ڹ��캯���������г�ʼ��
    myCom = new Win_QextSerialPort("com1", myComSetting, QextSerialBase::EventDriven);
    //�Կɶ�д��ʽ�򿪴���
    myCom->open(QIODevice::ReadWrite);
    //�źźͲۺ��������������ڻ�����������ʱ�����ж����ڲ���
    connect(myCom, SIGNAL(readyRead()), this, SLOT(readMyCom()));
    //д���ڲ���
    //myCom->write("99999");
}

userRoomDialog::~userRoomDialog()
{
    delete ui;
}

void userRoomDialog::on_pushButton_2_clicked()
{
    //�������
    QPropertyAnimation *ani = new QPropertyAnimation(ui->frame_3, "pos");
    ani->setDuration(500);
    ani->setStartValue(QPoint(ui->frame_3->pos().x(), ui->frame_3->pos().y()));
    ani->setEndValue(QPoint(this->width(), 0));
    ani->setEasingCurve(QEasingCurve::OutBounce);
    ani->start();

    ani = new QPropertyAnimation(ui->frame_2, "pos");
    ani->setDuration(500);
    if(ui->frame_2->pos().x() == this->width())
    {
        ani->setStartValue(QPoint(this->width(), 0));
        ani->setEndValue(QPoint(0, 0));
        ani->setEasingCurve(QEasingCurve::OutBounce);
    }
    else
    {
        ani->setStartValue(QPoint(ui->frame_2->pos().x(), ui->frame_2->pos().y()));
        ani->setEndValue(QPoint(this->width(), 0));
        ani->setEasingCurve(QEasingCurve::Linear);
    }
    ani->start();
}

void userRoomDialog::on_pushButton_3_clicked()
{
    //�ҵ��Զ�����
    QPropertyAnimation *ani = new QPropertyAnimation(ui->frame_2, "pos");
    ani->setDuration(500);
    ani->setStartValue(QPoint(ui->frame_2->pos().x(), ui->frame_2->pos().y()));
    ani->setEndValue(QPoint(this->width(), 0));
    ani->setEasingCurve(QEasingCurve::OutBounce);
    ani->start();

    ani = new QPropertyAnimation(ui->frame_3, "pos");
    ani->setDuration(500);
    if(ui->frame_3->pos().x() == this->width())
    {
        ani->setStartValue(QPoint(this->width(), 0));
        ani->setEndValue(QPoint(0, 0));
        ani->setEasingCurve(QEasingCurve::OutBounce);
    }
    else
    {
        ani->setStartValue(QPoint(ui->frame_3->pos().x(), ui->frame_3->pos().y()));
        ani->setEndValue(QPoint(this->width(), 0));
        ani->setEasingCurve(QEasingCurve::Linear);
    }
    ani->start();
}

void userRoomDialog::on_pushButton_clicked()
{
    //��ҳ
    QPropertyAnimation *ani = new QPropertyAnimation(ui->frame_2, "pos");
    ani->setDuration(500);
    ani->setStartValue(QPoint(ui->frame_2->pos().x(), ui->frame_2->pos().y()));
    ani->setEndValue(QPoint(this->width(), 0));
    ani->setEasingCurve(QEasingCurve::Linear);
    ani->start();

    ani = new QPropertyAnimation(ui->frame_3, "pos");
    ani->setDuration(500);
    ani->setStartValue(QPoint(ui->frame_3->pos().x(), ui->frame_3->pos().y()));
    ani->setEndValue(QPoint(this->width(), 0));
    ani->setEasingCurve(QEasingCurve::Linear);
    ani->start();

    ani = new QPropertyAnimation(ui->frame_4, "pos");
    ani->setDuration(500);
    ani->setStartValue(QPoint(ui->frame_4->pos().x(), ui->frame_4->pos().y()));
    ani->setEndValue(QPoint(this->width(), 160));
    ani->setEasingCurve(QEasingCurve::Linear);
    ani->start();
}

void userRoomDialog::on_pushButton_18_clicked()
{
    //�绰����
    QPropertyAnimation *ani = new QPropertyAnimation(ui->frame_4, "pos");
    ani->setDuration(500);
    if(ui->frame_4->pos().x() == this->width())
    {
        ani->setStartValue(QPoint(ui->frame_4->pos().x(), ui->frame_4->pos().y()));
        ani->setEndValue(QPoint(430, 160));
        ani->setEasingCurve(QEasingCurve::OutBounce);
    }
    else
    {
        ani->setStartValue(QPoint(ui->frame_4->pos().x(), ui->frame_4->pos().y()));
        ani->setEndValue(QPoint(this->width(), 160));
        ani->setEasingCurve(QEasingCurve::Linear);
    }
    ani->start();
}

void userRoomDialog::on_pushButton_4_clicked()
{
    //ˢ��
}

void userRoomDialog::on_checkBox_4_clicked()
{
    //����һ(��)
    light1->lightStepChange();
}

void userRoomDialog::on_checkBox_5_clicked()
{
    //���ݶ�(��)
    light2->lightStepChange();
}

void userRoomDialog::on_checkBox_6_clicked()
{
    //������(��)
    light3->lightStepChange();
}

void userRoomDialog::lightAuto()
{
    //��ȡ�Զ�����
    QSqlQuery query;
    query.exec("select * from lightauto");
    while(query.next())
    {
        switch(query.value(1).toInt())
        {
        case 1:
            ui->timeEdit->setTime(QTime::fromString(query.value(2).toString(), QString("hh:mm:ss")));
            ui->timeEdit_2->setTime(QTime::fromString(query.value(3).toString(), QString("hh:mm:ss")));
            ui->checkBox->setChecked(bool(query.value(4).toInt()));
            break;
        case 2:
            ui->timeEdit_3->setTime(QTime::fromString(query.value(2).toString(), QString("hh:mm:ss")));
            ui->timeEdit_4->setTime(QTime::fromString(query.value(3).toString(), QString("hh:mm:ss")));
            ui->checkBox_2->setChecked(bool(query.value(4).toInt()));
            break;
        case 3:
            ui->timeEdit_5->setTime(QTime::fromString(query.value(2).toString(), QString("hh:mm:ss")));
            ui->timeEdit_6->setTime(QTime::fromString(query.value(3).toString(), QString("hh:mm:ss")));
            ui->checkBox_3->setChecked(bool(query.value(4).toInt()));
            break;
        default:
            break;
        }
    }
}

void userRoomDialog::lightTimeOut()
{
    //���ݼ��
    ui->checkBox_4->setChecked(light1->lightStep%2);
    ui->checkBox_5->setChecked(light2->lightStep%2);
    ui->checkBox_6->setChecked(light3->lightStep%2);

    QTime timePre;
    QTime timeNxt;
    QTime timeCur;

    QSqlQuery query;
    query.exec("select * from lightauto where lightid = 1");
    while(query.next())
    {
        timePre = QTime::fromString(query.value(2).toString(), QString("hh:mm:ss"));
        timeNxt = QTime::fromString(query.value(3).toString(), QString("hh:mm:ss"));
        timeCur = QTime::currentTime();

        if((timeCur <= timeNxt) && (timeCur >= timePre))
        {
            if(query.value(4).toInt() == 2)
            {
                light1->lightOn();
            }
            else
            {
                light1->lightOff();
            }
        }
    }

    query.exec("select * from lightauto where lightid = 2");
    while(query.next())
    {
        timePre = QTime::fromString(query.value(2).toString(), QString("hh:mm:ss"));
        timeNxt = QTime::fromString(query.value(3).toString(), QString("hh:mm:ss"));
        timeCur = QTime::currentTime();

        if((timeCur <= timeNxt) && (timeCur >= timePre))
        {
            if(query.value(4).toInt() == 2)
            {
                light2->lightOn();
            }
            else
            {
                light2->lightOff();
            }
        }
    }

    query.exec("select * from lightauto where lightid = 3");
    while(query.next())
    {
        timePre = QTime::fromString(query.value(2).toString(), QString("hh:mm:ss"));
        timeNxt = QTime::fromString(query.value(3).toString(), QString("hh:mm:ss"));
        timeCur = QTime::currentTime();

        if((timeCur <= timeNxt) && (timeCur >= timePre))
        {
            if(query.value(4).toInt() == 2)
            {
                light3->lightOn();
            }
            else
            {
                light3->lightOff();
            }
        }
    }
}

void userRoomDialog::on_pushButton_5_clicked()
{
    //�绰1
    ui->lineEdit->insert(QString("1"));
}

void userRoomDialog::on_pushButton_6_clicked()
{
    //�绰2
    ui->lineEdit->insert(QString("2"));
}

void userRoomDialog::on_pushButton_7_clicked()
{
    //�绰3
    ui->lineEdit->insert(QString("3"));
}

void userRoomDialog::on_pushButton_8_clicked()
{
    //�绰4
    ui->lineEdit->insert(QString("4"));
}

void userRoomDialog::on_pushButton_9_clicked()
{
    //�绰5
    ui->lineEdit->insert(QString("5"));
}

void userRoomDialog::on_pushButton_10_clicked()
{
    //�绰6
    ui->lineEdit->insert(QString("6"));
}

void userRoomDialog::on_pushButton_11_clicked()
{
    //�绰7
    ui->lineEdit->insert(QString("7"));
}

void userRoomDialog::on_pushButton_12_clicked()
{
    //�绰8
    ui->lineEdit->insert(QString("8"));
}

void userRoomDialog::on_pushButton_13_clicked()
{
    //�绰9
    ui->lineEdit->insert(QString("9"));
}

void userRoomDialog::on_pushButton_14_clicked()
{
    //�绰*
    ui->lineEdit->insert(QString("*"));
}

void userRoomDialog::on_pushButton_15_clicked()
{
    //�绰0
    ui->lineEdit->insert(QString("0"));
}

void userRoomDialog::on_pushButton_16_clicked()
{
    //�绰#
    ui->lineEdit->insert(QString("#"));
}

void userRoomDialog::on_pushButton_17_clicked()
{
    //�绰����
}

void userRoomDialog::on_checkBox_clicked()
{
    //����1�Զ�
    QSqlQuery query;
    query.exec("update lightauto set autoflag = '" + QString::number(ui->checkBox->checkState(), 10) + "' where lightid = 1");
}

void userRoomDialog::on_checkBox_2_clicked()
{
    //����2�Զ�
    QSqlQuery query;
    query.exec("update lightauto set autoflag = '" + QString::number(ui->checkBox_2->checkState(), 10) + "' where lightid = 2");
}

void userRoomDialog::on_checkBox_3_clicked()
{
    //����3�Զ�
    QSqlQuery query;
    query.exec("update lightauto set autoflag = '" + QString::number(ui->checkBox_3->checkState(), 10) + "' where lightid = 3");
}

void userRoomDialog::on_timeEdit_timeChanged(const QTime &date)
{
    //ʱ��1
    QSqlQuery query;
    query.exec("update lightauto set pre = '" + ui->timeEdit->time().toString("hh:mm:ss") + "' where lightid = 1");
}

void userRoomDialog::on_timeEdit_2_timeChanged(const QTime &date)
{
    //ʱ��2
    QSqlQuery query;
    query.exec("update lightauto set next = '" + ui->timeEdit_2->time().toString("hh:mm:ss") + "' where lightid = 1");
}

void userRoomDialog::on_timeEdit_3_timeChanged(const QTime &date)
{
    //ʱ��3
    QSqlQuery query;
    query.exec("update lightauto set pre = '" + ui->timeEdit_3->time().toString("hh:mm:ss") + "' where lightid = 2");
}

void userRoomDialog::on_timeEdit_4_timeChanged(const QTime &date)
{
    //ʱ��4
    QSqlQuery query;
    query.exec("update lightauto set next = '" + ui->timeEdit_4->time().toString("hh:mm:ss") + "' where lightid = 2");
}

void userRoomDialog::on_timeEdit_5_timeChanged(const QTime &date)
{
    //ʱ��5
    QSqlQuery query;
    query.exec("update lightauto set pre = '" + ui->timeEdit_5->time().toString("hh:mm:ss") + "' where lightid = 3");
}

void userRoomDialog::on_timeEdit_6_timeChanged(const QTime &date)
{
    //ʱ��6
    QSqlQuery query;
    query.exec("update lightauto set next = '" + ui->timeEdit_6->time().toString("hh:mm:ss") + "' where lightid = 3");
}


void userRoomDialog::readMyCom()
{
    //��ȡ��������
    //��ȡ���ڻ��������������ݸ���ʱ����temp
    QByteArray temp = myCom->readAll();
    QString portString(temp);

    if(portString == "")
    {
        return;
    }
    QStringList portStringList = portString.split(":");
    qDebug() << portStringList;

    //en:�¶�:ʪ��:����
    if(portStringList.at(0) == "en")
    {
        ui->lcdNumber->display("23 C");
        ui->lcdNumber_2->display("23 H");
        ui->lcdNumber_3->display("23 H");
        ui->lcdNumber->display(portStringList.at(1) + " C");
        ui->lcdNumber_2->display(portStringList.at(2) + " H");
        ui->lcdNumber_3->display(portStringList.at(3) + " H");
    }
    //led:1:0
    if(portStringList.at(0) == "led")
    {
        switch(portStringList.at(1).toInt())
        {
        case 1:
            switch(portStringList.at(2).toInt())
            {
            case 0:
                light1->lightOff();
                break;
            case 1:
                light1->lightOn();
                break;
            }
            break;
        case 2:
            switch(portStringList.at(2).toInt())
            {
            case 0:
                light2->lightOff();
                break;
            case 1:
                light2->lightOn();
                break;
            }
            break;
        case 3:
            switch(portStringList.at(2).toInt())
            {
            case 0:
                light3->lightOff();
                break;
            case 1:
                light3->lightOn();
                break;
            }
            break;
        default:
            break;
        }
    }
}

