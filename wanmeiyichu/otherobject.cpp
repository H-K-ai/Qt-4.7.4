#include "otherobject.h"

imageButton *digiClockHourHigh;
imageButton *digiClockHourLow;
imageButton *digiClockMinuteHigh;
imageButton *digiClockMinuteLow;
imageButton *digiClockSecondHigh;
imageButton *digiClockSecondLow;
imageButton *digiClockPointsHigh;
imageButton *digiClockPointsLow;
imageButton *digiClockTimeBkg;
imageButton *digiClockDateBkg;
QLabel *digiClockDateBkgText;

imageButton *weatherBackground;
imageButton *weatherImage;
QLabel *weatherPlace;
QLabel *weatherTemp;
QLabel *weatherTitle;

QTableWidget *clothesListWidget;
QDateEdit *daydressDateEdit;
QTableWidget *daydressListWidget;

void createMainOtherObjectFunc(QWidget *parent)
{
    digiClockHourHigh = new imageButton(parent);
    digiClockHourLow = new imageButton(parent);
    digiClockMinuteHigh = new imageButton(parent);
    digiClockMinuteLow = new imageButton(parent);
    digiClockSecondHigh = new imageButton(parent);
    digiClockSecondLow = new imageButton(parent);
    digiClockPointsHigh = new imageButton(parent);
    digiClockPointsLow = new imageButton(parent);
    digiClockTimeBkg = new imageButton(parent);
    digiClockDateBkg = new imageButton(parent);
    digiClockDateBkgText = new QLabel(parent);

    weatherBackground = new imageButton(parent);
    weatherImage = new imageButton(parent);
    weatherPlace = new QLabel(parent);
    weatherTemp = new QLabel(parent);
    weatherTitle = new QLabel(parent);

    clothesListWidget = new QTableWidget(parent);
    daydressDateEdit = new QDateEdit(parent);
    daydressListWidget = new QTableWidget(parent);

    int buttonX = INTNUMBERINIT;
    int buttonY = INTNUMBERINIT;

    //�ӱ�Сʱ��λ
    buttonX = DIGICLOCKTIMEX;
    buttonY = DIGICLOCKTIMEY;
    digiClockHourHigh->setButtonPicture(QPixmap(":/digiclock/0.png"));
    digiClockHourHigh->setPressPicture(QPixmap(":/digiclock/0.png"));
    digiClockHourHigh->setReleasePicture(QPixmap(":/digiclock/0.png"));
    digiClockHourHigh->set_X_Y_width_height(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER);
    //�ӱ�Сʱ��λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = DIGICLOCKTIMEY;
    digiClockHourLow->setButtonPicture(QPixmap(":/digiclock/0.png"));
    digiClockHourLow->setPressPicture(QPixmap(":/digiclock/0.png"));
    digiClockHourLow->setReleasePicture(QPixmap(":/digiclock/0.png"));
    digiClockHourLow->set_X_Y_width_height(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER);
    //�ӱ��λ���λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = DIGICLOCKPOINTY;
    digiClockPointsHigh->setButtonPicture(QPixmap(":/digiclock/points.png"));
    digiClockPointsHigh->setPressPicture(QPixmap(":/digiclock/points.png"));
    digiClockPointsHigh->setReleasePicture(QPixmap(":/digiclock/points.png"));
    digiClockPointsHigh->set_X_Y_width_height(buttonX, buttonY, DIGICLOCKTIMEWIDTH, DIGICLOCKTIMEHEIGHT);
    //�ӱ���Ӹ�λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTH + DIGICLOCKTIMESPACE;
    buttonY = DIGICLOCKTIMEY;
    digiClockMinuteHigh->setButtonPicture(QPixmap(":/digiclock/0.png"));
    digiClockMinuteHigh->setPressPicture(QPixmap(":/digiclock/0.png"));
    digiClockMinuteHigh->setReleasePicture(QPixmap(":/digiclock/0.png"));
    digiClockMinuteHigh->set_X_Y_width_height(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER);
    //�ӱ���ӵ�λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = DIGICLOCKTIMEY;
    digiClockMinuteLow->setButtonPicture(QPixmap(":/digiclock/0.png"));
    digiClockMinuteLow->setPressPicture(QPixmap(":/digiclock/0.png"));
    digiClockMinuteLow->setReleasePicture(QPixmap(":/digiclock/0.png"));
    digiClockMinuteLow->set_X_Y_width_height(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER);
    //�ӱ��λ���λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = DIGICLOCKPOINTY;
    digiClockPointsLow->setButtonPicture(QPixmap(":/digiclock/points.png"));
    digiClockPointsLow->setPressPicture(QPixmap(":/digiclock/points.png"));
    digiClockPointsLow->setReleasePicture(QPixmap(":/digiclock/points.png"));
    digiClockPointsLow->set_X_Y_width_height(buttonX, buttonY, DIGICLOCKTIMEWIDTH, DIGICLOCKTIMEHEIGHT);
    //�ӱ�������λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTH + DIGICLOCKTIMESPACE;
    buttonY = DIGICLOCKTIMEY;
    digiClockSecondHigh->setButtonPicture(QPixmap(":/digiclock/0.png"));
    digiClockSecondHigh->setPressPicture(QPixmap(":/digiclock/0.png"));
    digiClockSecondHigh->setReleasePicture(QPixmap(":/digiclock/0.png"));
    digiClockSecondHigh->set_X_Y_width_height(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER);
    //�ӱ�������λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = DIGICLOCKTIMEY;
    digiClockSecondLow->setButtonPicture(QPixmap(":/digiclock/0.png"));
    digiClockSecondLow->setPressPicture(QPixmap(":/digiclock/0.png"));
    digiClockSecondLow->setReleasePicture(QPixmap(":/digiclock/0.png"));
    digiClockSecondLow->set_X_Y_width_height(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER);
    //�ӱ�ʱ�䱳��
    buttonX = DIGICLOCKTIMEBKGX;
    buttonY = DIGICLOCKTIMEBKGY;
    digiClockTimeBkg->setButtonPicture(QPixmap(":/digiclock/time_bkg.png"));
    digiClockTimeBkg->setPressPicture(QPixmap(":/digiclock/time_bkg.png"));
    digiClockTimeBkg->setReleasePicture(QPixmap(":/digiclock/time_bkg.png"));
    digiClockTimeBkg->set_X_Y_width_height(buttonX, buttonY, DIGICLOCKTIMEBKGWIDTH, DIGICLOCKTIMEBKGHEIGHT);
    //�ӱ����ڱ���
    buttonX = DIGICLOCKDATEBKGX;
    buttonY = DIGICLOCKDATEBKGY;
    digiClockDateBkg->setButtonPicture(QPixmap(":/digiclock/date_bkg.png"));
    digiClockDateBkg->setPressPicture(QPixmap(":/digiclock/date_bkg.png"));
    digiClockDateBkg->setReleasePicture(QPixmap(":/digiclock/date_bkg.png"));
    digiClockDateBkg->set_X_Y_width_height(buttonX, buttonY, DIGICLOCKDATEBKGWIDTH, DIGICLOCKDATEBKGHEIGHT);
    //�ӱ����ڱ�������
    digiClockDateBkgText->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    digiClockDateBkgText->setFont(digiClockDateFont);
    digiClockDateBkgText->setGeometry(buttonX, buttonY, DIGICLOCKDATEBKGWIDTH, DIGICLOCKDATEBKGHEIGHT);

    //����Ԥ������ͼƬ
    weatherBackground->setButtonPicture(QPixmap(":/weather/weather_background.png"));
    weatherBackground->setPressPicture(QPixmap(":/weather/weather_background.png"));
    weatherBackground->setReleasePicture(QPixmap(":/weather/weather_background.png"));
    weatherBackground->set_X_Y_width_height(WEATHERBACKGROUNDX, WEATHERBACKGROUNDY, WEATHERBACKGROUNDWIDTH, WEATHERBACKGROUNDHEIGHT);
    //����Ԥ����ʶ
    weatherImage->setButtonPicture(QPixmap(":/weather/54.png"));
    weatherImage->setPressPicture(QPixmap(":/weather/54.png"));
    weatherImage->setReleasePicture(QPixmap(":/weather/54.png"));
    weatherImage->set_X_Y_width_height(WEATHERIMAGEX, WEATHERIMAGEY, WEATHERIMAGEWIDTH, WEATHERIMAGEHEIGHT);
    //����Ԥ���ص�
    weatherPlace->setFont(weatherPlaceFont);
    weatherPlace->setAlignment(Qt::AlignHCenter|Qt::AlignBottom);
    weatherPlace->setGeometry(WEATHERPLACEX, WEATHERPLACEY, WEATHERPLACEWIDTH, WEATHERPLACEHEIGHT);
    //����Ԥ���¶�
    weatherTemp->setFont(weatherTempFont);
    weatherTemp->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
    weatherTemp->setGeometry(WEATHERTEMPX, WEATHERTEMPY, WEATHERTEMPWIDTH, WEATHERTEMPHEIGHT);
    //����Ԥ����������
    weatherTitle->setFont(weatherTempFont);
    weatherTitle->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    weatherTitle->setGeometry(WEATHERTITLEX, WEATHERTITLEY, WEATHERTITLEWIDTH, WEATHERTITLEHEIGHT);
    //�·�ͼƬ�б�
    clothesListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //ʹ�䲻�ɱ༭
    clothesListWidget->setSelectionMode(QAbstractItemView::SingleSelection); //����Ϊ��ѡ
    clothesListWidget->setColumnCount(CLOTHESLISTWIDGETCOLUMNNUM);
    clothesListWidget->setColumnWidth(CLOTHESLISTWIDGETITEMLEFT, CLOTHESLISTWIDGETCOLUMNWIDTH);
    clothesListWidget->setColumnWidth(CLOTHESLISTWIDGETITEMRIGHT, CLOTHESLISTWIDGETCOLUMNWIDTH);
    clothesListWidget->horizontalHeader()->setResizeMode(CLOTHESLISTWIDGETITEMLEFT, QHeaderView::Fixed);  //��Ȳ��ɵ���
    clothesListWidget->horizontalHeader()->setResizeMode(CLOTHESLISTWIDGETITEMRIGHT, QHeaderView::Fixed);
    clothesListWidget->setShowGrid(false); //ȥ�������
    QHeaderView* headerView = clothesListWidget->verticalHeader(); //ȥ����ͷ
    headerView->setHidden(true);
    headerView = clothesListWidget->horizontalHeader();
    headerView->setHidden(true);
    clothesListWidget->setStyleSheet(QString("QTableWidget {border-image: url(:/images/transparent.png);}") //���ñ���ͼƬ
                                     + QString("QTableWidget::item:selected {border-image: url(:/images/clothes_list_click.png); border: 0px; solid #6a6ea9;}") //����ѡ��ͼƬ
                                     + QString("QScrollBar:vertical {border-image: url(:/images/transparent.png); width: 36px; margin: 36px 0 36px 0;}")  //���ù�������ͼƬ
                                     + QString("QScrollBar::handle:vertical {border-image: url(:/images/btn_info_handle.png); border: 22px 0 22px 0; min-height: 87px;}")  //���ù�����ͼƬ
                                     + QString("QScrollBar::sub-line:vertical {image: url(:/images/btn_info_up.png); height: 36px; subcontrol-position: top; subcontrol-origin: margin;}")  //�����ϼ�ͷͼƬ
                                     + QString("QScrollBar::add-line:vertical {image: url(:/images/btn_info_down.png); height: 36px; subcontrol-position: bottom; subcontrol-origin: margin;}") //�����¼�ͷͼƬ
                                     + QString("QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {border-image: url(:/images/transparent.png);}")); //���ù���������ͼƬ

    //ÿ��װ������
    daydressDateEdit->setStyleSheet(QString("QDateEdit {border: 2px solid gray; padding: 0 8px; background: #fcaad5; selection-background-color: darkgray;}")
                                    + QString("QDateEdit::up-button {width: 15px; border-image: url(:/images/cloth_date_up.png);}")
                                    + QString("QDateEdit::down-button {width: 15px; border-image: url(:/images/cloth_date_down.png);}"));
    daydressDateEdit->setFont(clothesFont);
    daydressDateEdit->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    daydressDateEdit->setGeometry(DAYDRESSDATEEDITX, DAYDRESSDATEEDITY, DAYDRESSDATEEDITWIDTH, DAYDRESSDATEEDITHEIGHT);
    //ÿ��װ���б�
    daydressListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    daydressListWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    daydressListWidget->setColumnCount(DAYDRESSLISTWIDGETCOLUMNNUM);
    daydressListWidget->setColumnWidth(DAYDRESSLISTWIDGETITEMUPCLOTHESONE, DAYDRESSLISTWIDGETCOLUMNWIDTH);
    daydressListWidget->setColumnWidth(DAYDRESSLISTWIDGETITEMUPCLOTHESTWO, DAYDRESSLISTWIDGETCOLUMNWIDTH);
    daydressListWidget->setColumnWidth(DAYDRESSLISTWIDGETITEMDOWNCLOTHES, DAYDRESSLISTWIDGETCOLUMNWIDTH);
    daydressListWidget->setColumnWidth(DAYDRESSLISTWIDGETITEMBAG, DAYDRESSLISTWIDGETCOLUMNWIDTH);
    daydressListWidget->setColumnWidth(DAYDRESSLISTWIDGETITEMSHOE, DAYDRESSLISTWIDGETCOLUMNWIDTH);
    daydressListWidget->setColumnWidth(DAYDRESSLISTWIDGETITEMDECO, DAYDRESSLISTWIDGETCOLUMNWIDTH);
    daydressListWidget->horizontalHeader()->setResizeMode(DAYDRESSLISTWIDGETITEMUPCLOTHESONE, QHeaderView::Fixed);
    daydressListWidget->horizontalHeader()->setResizeMode(DAYDRESSLISTWIDGETITEMUPCLOTHESTWO, QHeaderView::Fixed);
    daydressListWidget->horizontalHeader()->setResizeMode(DAYDRESSLISTWIDGETITEMDOWNCLOTHES, QHeaderView::Fixed);
    daydressListWidget->horizontalHeader()->setResizeMode(DAYDRESSLISTWIDGETITEMBAG, QHeaderView::Fixed);
    daydressListWidget->horizontalHeader()->setResizeMode(DAYDRESSLISTWIDGETITEMSHOE, QHeaderView::Fixed);
    daydressListWidget->horizontalHeader()->setResizeMode(DAYDRESSLISTWIDGETITEMDECO, QHeaderView::Fixed);
    daydressListWidget->setShowGrid(false);
    headerView = daydressListWidget->verticalHeader();
    headerView->setHidden(true);
    headerView = daydressListWidget->horizontalHeader();
    headerView->setHidden(true);
    daydressListWidget->setStyleSheet(QString("QTableWidget {border-image: url(:/images/transparent.png);}")
                                      + QString("QTableWidget::item:selected {border-image: url(:/images/daydress_list_click.png); border: 0px; solid #6a6ea9;}")
                                      + QString("QScrollBar:vertical {border-image: url(:/images/transparent.png); width: 36px; margin: 36px 0 36px 0;}")
                                      + QString("QScrollBar::handle:vertical {border-image: url(:/images/btn_info_handle.png); border: 22px 0 22px 0; min-height: 87px;}")
                                      + QString("QScrollBar::sub-line:vertical {image: url(:/images/btn_info_up.png); height: 36px; subcontrol-position: top; subcontrol-origin: margin;}")
                                      + QString("QScrollBar::add-line:vertical {image: url(:/images/btn_info_down.png); height: 36px; subcontrol-position: bottom; subcontrol-origin: margin;}")
                                      + QString("QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {border-image: url(:/images/transparent.png);}"));
}

int selectClothesIdNumInt;
int selectDaydressIdNumInt;
int daydressColSelectInt;
QLineEdit *nameLineEdit;
noMoveComboBox *typeComboBox;
noMoveComboBox *seasonComboBox;
noMoveComboBox *classtypeComboBox;
QLineEdit *brandLineEdit;
QLineEdit *priceLineEdit;
QDateEdit *timeDateEdit;
QLineEdit *storePlaceLineEdit;
QLineEdit *buyPlaceLineEdit;
QTextEdit *noteTextEdit;
QString clothesPicPathString;

void createClothesOtherObjectFunc(QWidget *parent)
{
    nameLineEdit = new QLineEdit(parent);
    typeComboBox = new noMoveComboBox(parent);
    seasonComboBox = new noMoveComboBox(parent);
    classtypeComboBox = new noMoveComboBox(parent);
    brandLineEdit = new QLineEdit(parent);
    priceLineEdit = new QLineEdit(parent);
    timeDateEdit = new QDateEdit(parent);
    storePlaceLineEdit = new QLineEdit(parent);
    buyPlaceLineEdit = new QLineEdit(parent);
    noteTextEdit = new QTextEdit(parent);
    clothesPicPathString = "";

    //�۸�������ʽ
    QRegExp regExp("^[0-9]+$");
    QRegExpValidator *pRevalidotor = new QRegExpValidator(regExp, 0);
    priceLineEdit->setValidator(pRevalidotor);

    int buttonX = INTNUMBERINIT;
    int buttonY = INTNUMBERINIT;

    //���Ʊ༭��
    buttonX = NAMELINEEDITX;
    buttonY = NAMELINEEDITY;
    nameLineEdit->setStyleSheet("QLineEdit {border: 2px solid gray; border-radius: 10px; padding: 0 8px; background: #f0bcd7; selection-background-color: darkgray;}");
    nameLineEdit->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    nameLineEdit->setFont(clothesFont);
    nameLineEdit->setGeometry(buttonX, buttonY, NAMELINEEDITWIDTH, NAMELINEEDITHEIGHT);
    //������Ͽ�
    buttonX = NAMELINEEDITX;
    buttonY = buttonY + NAMELINEEDITHEIGHT + NAMELINEEDITSPACE;
    typeComboBox->addItems(QStringList()
                           << "                       �·�"
                           << "                       ����"
                           << "                       Ьñ"
                           << "                       ��Ʒ"
                           << "                     ��ױƷ"
                           << "                       ����");
    typeComboBox->setStyleSheet(QString("QComboBox {border: 2px solid gray; border-radius: 10px; padding: 0px 10px 0px 8px; min-width: 6em;}")
                                + QString("QComboBox:editable {background: #fcaad5;}")
                                + QString("QComboBox:!editable, QComboBox::drop-down:editable {background: #fcaad5}")
                                + QString("QComboBox:!editable:on, QComboBox::drop-down:editable:on {background: #fcaad5}")
                                + QString("QComboBox:on {padding-top: 0px; padding-left: 8px;}")
                                + QString("QComboBox::drop-down {subcontrol-origin: padding; subcontrol-position: top right; width: 15px; border-left-width: 2px; border-left-color: gray; border-left-style: solid; border-top-right-radius: 10px; border-bottom-right-radius: 10px;}")
                                + QString("QComboBox QAbstractItemView {border: 2px solid gray; background: #fcaad5; padding: 0px 10px 0px 8px; selection-background-color: #fcaad5;}"));
    typeComboBox->setFont(clothesFont);
    typeComboBox->setGeometry(buttonX, buttonY, NAMELINEEDITWIDTH, NAMELINEEDITHEIGHT);
    //������Ͽ�
    buttonX = NAMELINEEDITX;
    buttonY = buttonY + NAMELINEEDITHEIGHT + NAMELINEEDITSPACE;
    seasonComboBox->addItems(QStringList()
                             << "                       ����"
                             << "                       �ļ�"
                             << "                       �＾"
                             << "                       ����");
    seasonComboBox->setStyleSheet(QString("QComboBox {border: 2px solid gray; border-radius: 10px; padding: 0px 10px 0px 8px; min-width: 6em;}")
                                  + QString("QComboBox:editable {background: #f3b7b7;}")
                                  + QString("QComboBox:!editable, QComboBox::drop-down:editable {background: #f3b7b7}")
                                  + QString("QComboBox:!editable:on, QComboBox::drop-down:editable:on {background: #f3b7b7}")
                                  + QString("QComboBox:on {padding-top: 0px; padding-left: 8px;}")
                                  + QString("QComboBox::drop-down {subcontrol-origin: padding; subcontrol-position: top right; width: 15px; border-left-width: 2px; border-left-color: gray; border-left-style: solid; border-top-right-radius: 10px; border-bottom-right-radius: 10px;}")
                                  + QString("QComboBox QAbstractItemView {border: 2px solid gray; background: #f3b7b7; padding: 0px 10px 0px 8px; selection-background-color: #f3b7b7;}"));
    seasonComboBox->setFont(clothesFont);
    seasonComboBox->setGeometry(buttonX, buttonY, NAMELINEEDITWIDTH, NAMELINEEDITHEIGHT);
    //������Ͽ�
    buttonX = NAMELINEEDITX;
    buttonY = buttonY + NAMELINEEDITHEIGHT + NAMELINEEDITSPACE;
    classtypeComboBox->addItems(QStringList()
                                << "                       ְ��"
                                << "                       ����"
                                << "                       �˶�"
                                << "                       ���"
                                << "                       ����");
    classtypeComboBox->setStyleSheet(QString("QComboBox {border: 2px solid gray; border-radius: 10px; padding: 0px 10px 0px 8px; min-width: 6em;}")
                                     + QString("QComboBox:editable {background: #f3c599;}")
                                     + QString("QComboBox:!editable, QComboBox::drop-down:editable {background: #f3c599}")
                                     + QString("QComboBox:!editable:on, QComboBox::drop-down:editable:on {background: #f3c599}")
                                     + QString("QComboBox:on {padding-top: 0px; padding-left: 8px;}")
                                     + QString("QComboBox::drop-down {subcontrol-origin: padding; subcontrol-position: top right; width: 15px; border-left-width: 2px; border-left-color: gray; border-left-style: solid; border-top-right-radius: 10px; border-bottom-right-radius: 10px;}")
                                     + QString("QComboBox QAbstractItemView {border: 2px solid gray; background: #f3c599; padding: 0px 10px 0px 8px; selection-background-color: #f3c599;}"));
    classtypeComboBox->setFont(clothesFont);
    classtypeComboBox->setGeometry(buttonX, buttonY, NAMELINEEDITWIDTH, NAMELINEEDITHEIGHT);
    //Ʒ�Ʊ༭��
    buttonX = NAMELINEEDITX;
    buttonY = buttonY + NAMELINEEDITHEIGHT + NAMELINEEDITSPACE;
    brandLineEdit->setStyleSheet("QLineEdit {border: 2px solid gray; border-radius: 10px; padding: 0 8px; background: #d7e69e; selection-background-color: darkgray;}");
    brandLineEdit->setFont(clothesFont);
    brandLineEdit->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    brandLineEdit->setGeometry(buttonX, buttonY, NAMELINEEDITWIDTH, NAMELINEEDITHEIGHT);
    //�۸�༭��
    buttonX = NAMELINEEDITX;
    buttonY = buttonY + NAMELINEEDITHEIGHT + NAMELINEEDITSPACE;
    priceLineEdit->setStyleSheet("QLineEdit {border: 2px solid gray; border-radius: 10px; padding: 0 8px; background: #a5dfe0; selection-background-color: darkgray;}");
    priceLineEdit->setFont(clothesFont);
    priceLineEdit->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    priceLineEdit->setGeometry(buttonX, buttonY, NAMELINEEDITWIDTH, NAMELINEEDITHEIGHT);
    //ʱ��༭��
    buttonX = NAMELINEEDITX;
    buttonY = buttonY + NAMELINEEDITHEIGHT + NAMELINEEDITSPACE;
    timeDateEdit->setStyleSheet(QString("QDateEdit {border: 2px solid gray; border-radius: 10px; padding: 0 8px; background: #a9d1e1; selection-background-color: darkgray;}")
                                + QString("QDateEdit::up-button {width: 15px; border-image: url(:/images/cloth_date_up.png);}")
                                + QString("QDateEdit::down-button {width: 15px; border-image: url(:/images/cloth_date_down.png);}"));
    timeDateEdit->setFont(clothesFont);
    timeDateEdit->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    timeDateEdit->setGeometry(buttonX, buttonY, NAMELINEEDITWIDTH, NAMELINEEDITHEIGHT);
    //��ŵر༭��
    buttonX = NAMELINEEDITX;
    buttonY = buttonY + NAMELINEEDITHEIGHT + NAMELINEEDITSPACE;
    storePlaceLineEdit->setStyleSheet("QLineEdit {border: 2px solid gray; border-radius: 10px; padding: 0 8px; background: #a8c2e2; selection-background-color: darkgray;}");
    storePlaceLineEdit->setFont(clothesFont);
    storePlaceLineEdit->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    storePlaceLineEdit->setGeometry(buttonX, buttonY, NAMELINEEDITWIDTH, NAMELINEEDITHEIGHT);
    //����ر༭��
    buttonX = NAMELINEEDITX;
    buttonY = buttonY + NAMELINEEDITHEIGHT + NAMELINEEDITSPACE;
    buyPlaceLineEdit->setStyleSheet("QLineEdit {border: 2px solid gray; border-radius: 10px; padding: 0 8px; background: #beb5e5; selection-background-color: darkgray;}");
    buyPlaceLineEdit->setFont(clothesFont);
    buyPlaceLineEdit->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    buyPlaceLineEdit->setGeometry(buttonX, buttonY, NAMELINEEDITWIDTH, NAMELINEEDITHEIGHT);
    //��ע�ı���
    buttonX = NAMELINEEDITX;
    buttonY = buttonY + NAMELINEEDITHEIGHT + NAMELINEEDITSPACE;
    noteTextEdit->setStyleSheet("QTextEdit {border: 2px solid gray; border-radius: 10px; padding: 0px 0px; background: #afa5de; selection-background-color: darkgray;}");
    noteTextEdit->setFont(clothesFont);
    noteTextEdit->setGeometry(buttonX, buttonY, NOTETEXTEDITWIDTH, NOTETEXTEDITHEIGHT);
}

QTableWidget *filterListWidget;
void createFilterOtherObjectFunc(QWidget *parent)
{
    filterListWidget = new QTableWidget(parent);

    //ÿ��װ��ɸѡ�б�
    filterListWidget->setGeometry(FILTERLISTWIDGETX, FILTERLISTWIDGETY, FILTERLISTWIDGETWIDTH, FILTERLISTWIDGETHEIGHT);
    filterListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    filterListWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    filterListWidget->setColumnCount(FILTERLISTWIDGETCOLUMNNUM);
    filterListWidget->setColumnWidth(FILTERLISTWIDGETITEMONE, FILTERLISTWIDGETCOLUMNWIDTH);
    filterListWidget->setColumnWidth(FILTERLISTWIDGETITEMTWO, FILTERLISTWIDGETCOLUMNWIDTH);
    filterListWidget->setColumnWidth(FILTERLISTWIDGETITEMTHREE, FILTERLISTWIDGETCOLUMNWIDTH);
    filterListWidget->horizontalHeader()->setResizeMode(FILTERLISTWIDGETITEMONE, QHeaderView::Fixed);
    filterListWidget->horizontalHeader()->setResizeMode(FILTERLISTWIDGETITEMTWO, QHeaderView::Fixed);
    filterListWidget->horizontalHeader()->setResizeMode(FILTERLISTWIDGETITEMTHREE, QHeaderView::Fixed);
    filterListWidget->setShowGrid(false);
    QHeaderView* headerView = filterListWidget->verticalHeader();
    headerView->setHidden(true);
    headerView = filterListWidget->horizontalHeader();
    headerView->setHidden(true);
    filterListWidget->setStyleSheet(QString("QTableWidget {border-image: url(:/images/transparent.png);}") //���ñ���ͼƬ
                                    + QString("QTableWidget::item:selected {border-image: url(:/images/clothes_list_click.png); border: 0px; solid #6a6ea9;}") //����ѡ��ͼƬ
                                    + QString("QScrollBar:vertical {border-image: url(:/images/transparent.png); width: 36px; margin: 36px 0 36px 0;}")  //���ù�������ͼƬ
                                    + QString("QScrollBar::handle:vertical {border-image: url(:/images/btn_info_handle.png); border: 22px 0 22px 0; min-height: 87px;}")  //���ù�����ͼƬ
                                    + QString("QScrollBar::sub-line:vertical {image: url(:/images/btn_info_up.png); height: 36px; subcontrol-position: top; subcontrol-origin: margin;}")  //�����ϼ�ͷͼƬ
                                    + QString("QScrollBar::add-line:vertical {image: url(:/images/btn_info_down.png); height: 36px; subcontrol-position: bottom; subcontrol-origin: margin;}") //�����¼�ͷͼƬ
                                    + QString("QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {border-image: url(:/images/transparent.png);}")); //���ù���������ͼƬ
}
