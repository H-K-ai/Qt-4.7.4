#include "animation.h"

QState *myclothesState;
QState *fashionState;
QState *daydressStatue;
QState *settingState;
QState *clothesState;
QStateMachine *stateMachine;

QSignalTransition *myclothesToClothesST;
QSignalTransition *myclothesToFashionST;
QSignalTransition *myclothesToDaydressST;
QSignalTransition *myclothesToSettingST;

QSignalTransition *fashionToClothesST;
QSignalTransition *fashionToMyclothesST;
QSignalTransition *fashionToDaydressST;
QSignalTransition *fashionToSettingST;

QSignalTransition *daydressToMyclothesST;
QSignalTransition *daydressToFashionST;
QSignalTransition *daydressToSettingST;

QSignalTransition *settingToMyclothesST;
QSignalTransition *settingToFashionST;
QSignalTransition *settingToDaydressST;

QSignalTransition *clothesToMyclothesST;
QSignalTransition *clothesToFashionST;
QSignalTransition *clothesToDaydressST;
QSignalTransition *clothesToSettingST;

void createMainStateFunc()
{
    stateMachine = new QStateMachine;     //�½�״̬��
    myclothesState = new QState(stateMachine);     //״̬
    fashionState = new QState(stateMachine);     //״̬
    daydressStatue = new QState(stateMachine);   //״̬
    settingState = new QState(stateMachine);     //״̬
    clothesState = new QState(stateMachine);       //״̬

    stateMachine->setInitialState(settingState);

    createMainSettingStateFunc();
    createMainMyclothesStateFunc();
    createMainFashionStateFunc();
    createMainDayDressStateFunc();
    createMainClothesStateFunc();

    createMainSignalTransitionFunc();

    createMainPropertyAnimationFunc();

    stateMachine->start();     //����״̬��
}

void createMainSettingStateFunc()
{
    //��ҳ״̬
    int buttonX = INTNUMBERINIT;
    int buttonY = INTNUMBERINIT;
    //�ҵ��³�->�·�
    buttonX = NOBUTTONRIGHTX;
    buttonY = NOBUTTONRIGHTY;
    settingState->assignProperty(clothesButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHTER));
    //�ҵ��³�->����
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + MYCLOTHESBUTTONXHEIGHTER + MYCLOTHESBUTTONXSPACE;
    settingState->assignProperty(bagButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHT));
    //�ҵ��³�->Ьñ
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + MYCLOTHESBUTTONXHEIGHT + MYCLOTHESBUTTONXSPACE;
    settingState->assignProperty(shoeButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHT));
    //�ҵ��³�->��Ʒ
    buttonX = NOBUTTONRIGHTX + MYCLOTHESBUTTONXWIDTH + MYCLOTHESBUTTONXSPACE;
    buttonY = NOBUTTONRIGHTY;
    settingState->assignProperty(decoButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHT));
    //�ҵ��³�->��ױƷ
    buttonX = NOBUTTONRIGHTX + MYCLOTHESBUTTONXWIDTH + MYCLOTHESBUTTONXSPACE;
    buttonY = buttonY + MYCLOTHESBUTTONXHEIGHT + MYCLOTHESBUTTONXSPACE;
    settingState->assignProperty(cosButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHT));
    //�ҵ��³�->�Զ���
    buttonX = NOBUTTONRIGHTX + MYCLOTHESBUTTONXWIDTH + MYCLOTHESBUTTONXSPACE;
    buttonY = buttonY + MYCLOTHESBUTTONXHEIGHT + MYCLOTHESBUTTONXSPACE;
    settingState->assignProperty(labelButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHTER));
    //������->����
    buttonX = NOBUTTONRIGHTX;
    buttonY = NOBUTTONRIGHTY;
    settingState->assignProperty(springButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->�＾
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + FASHIONBUTTONHEIGHT + FASHIONBUTTONSPACE;
    settingState->assignProperty(autumnButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->ְ��
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + FASHIONBUTTONHEIGHT + FASHIONBUTTONSPACE;
    settingState->assignProperty(workplaceButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->����
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + FASHIONBUTTONHEIGHT + FASHIONBUTTONSPACE;
    settingState->assignProperty(leisureButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->�˶�
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + FASHIONBUTTONHEIGHT + FASHIONBUTTONSPACE;
    settingState->assignProperty(sportButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->�ļ�
    buttonX = NOBUTTONRIGHTX + FASHIONBUTTONWIDTH + FASHIONBUTTONSPACE;
    buttonY = NOBUTTONRIGHTY;
    settingState->assignProperty(summerButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHTER));
    //������->����
    buttonX = NOBUTTONRIGHTX + FASHIONBUTTONWIDTH + FASHIONBUTTONSPACE;
    buttonY = buttonY + FASHIONBUTTONHEIGHTER + FASHIONBUTTONSPACE;
    settingState->assignProperty(winterButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHTER));
    //������->���
    buttonX = NOBUTTONRIGHTX + FASHIONBUTTONWIDTH + FASHIONBUTTONSPACE;
    buttonY = buttonY + FASHIONBUTTONHEIGHTER + FASHIONBUTTONSPACE;
    settingState->assignProperty(banquetButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHTER));
    //������->����
    buttonX = NOBUTTONRIGHTX + FASHIONBUTTONWIDTH + FASHIONBUTTONSPACE;
    buttonY = buttonY + FASHIONBUTTONHEIGHTER + FASHIONBUTTONSPACE;
    settingState->assignProperty(otherButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHTER));
    //�رհ�ť
    settingState->assignProperty(closeButton, "geometry", QRect(CLOSEBUTTONX, CLOSEBUTTONY, CLOSEBUTTONWIDTH, CLOSEBUTTONHEIGHT));
    //�·�ͼƬ�б�
    settingState->assignProperty(clothesListWidget, "geometry", QRect(NOBUTTONTOPX, NOBUTTONTOPY, CLOTHESLISTWIDGETWIDTH, CLOTHESLISTWIDGETHEIGHT));
    //ÿ��װ������
    settingState->assignProperty(daydressDateEdit, "geometry", QRect(NOBUTTONTOPX, NOBUTTONTOPY, DAYDRESSLISTWIDGETWIDTH, DAYDRESSLISTWIDGETHEIGHT));
    //ÿ��װ���б�
    settingState->assignProperty(daydressListWidget, "geometry", QRect(NOBUTTONTOPX, NOBUTTONTOPY, DAYDRESSLISTWIDGETWIDTH, DAYDRESSLISTWIDGETHEIGHT));
    //��Ӱ�ť
    settingState->assignProperty(addButton, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, ADDDELBUTTONWIDTH, ADDDELBUTTONHEIGHT));
    //ɾ����ť
    settingState->assignProperty(delButton, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, ADDDELBUTTONWIDTH, ADDDELBUTTONHEIGHT));
    //�ӱ�Сʱ��λ
    buttonX = DIGICLOCKTIMEX;
    buttonY = DIGICLOCKTIMEY;
    settingState->assignProperty(digiClockHourHigh, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ�Сʱ��λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = DIGICLOCKTIMEY;
    settingState->assignProperty(digiClockHourLow, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ��λ���λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = DIGICLOCKPOINTY;
    settingState->assignProperty(digiClockPointsHigh, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTH, DIGICLOCKTIMEHEIGHT));
    //�ӱ���Ӹ�λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTH + DIGICLOCKTIMESPACE;
    buttonY = DIGICLOCKTIMEY;
    settingState->assignProperty(digiClockMinuteHigh, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ���ӵ�λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = DIGICLOCKTIMEY;
    settingState->assignProperty(digiClockMinuteLow, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ��λ���λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = DIGICLOCKPOINTY;
    settingState->assignProperty(digiClockPointsLow, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTH, DIGICLOCKTIMEHEIGHT));
    //�ӱ�������λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTH + DIGICLOCKTIMESPACE;
    buttonY = DIGICLOCKTIMEY;
    settingState->assignProperty(digiClockSecondHigh, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ�������λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = DIGICLOCKTIMEY;
    settingState->assignProperty(digiClockSecondLow, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ�ʱ�䱳��
    buttonX = DIGICLOCKTIMEBKGX;
    buttonY = DIGICLOCKTIMEBKGY;
    settingState->assignProperty(digiClockTimeBkg, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEBKGWIDTH, DIGICLOCKTIMEBKGHEIGHT));
    //�ӱ����ڱ���
    buttonX = DIGICLOCKDATEBKGX;
    buttonY = DIGICLOCKDATEBKGY;
    settingState->assignProperty(digiClockDateBkg, "geometry", QRect(buttonX, buttonY, DIGICLOCKDATEBKGWIDTH, DIGICLOCKDATEBKGHEIGHT));
    //�ӱ����ڱ�������
    settingState->assignProperty(digiClockDateBkgText, "geometry", QRect(buttonX, buttonY-2, DIGICLOCKDATEBKGWIDTH, DIGICLOCKDATEBKGHEIGHT));
    //����Ԥ������ͼƬ
    settingState->assignProperty(weatherBackground, "geometry", QRect(WEATHERBACKGROUNDX, WEATHERBACKGROUNDY, WEATHERBACKGROUNDWIDTH, WEATHERBACKGROUNDHEIGHT));
    //����Ԥ����ʶ
    settingState->assignProperty(weatherImage, "geometry", QRect(WEATHERIMAGEX, WEATHERIMAGEY, WEATHERIMAGEWIDTH, WEATHERIMAGEHEIGHT));
    //����Ԥ���ص�
    settingState->assignProperty(weatherPlace, "geometry", QRect(WEATHERPLACEX, WEATHERPLACEY, WEATHERPLACEWIDTH, WEATHERPLACEHEIGHT));
    //����Ԥ���¶�
    settingState->assignProperty(weatherTemp, "geometry", QRect(WEATHERTEMPX, WEATHERTEMPY, WEATHERTEMPWIDTH, WEATHERTEMPHEIGHT));
    //����Ԥ����������
    settingState->assignProperty(weatherTitle, "geometry", QRect(WEATHERTITLEX, WEATHERTITLEY, WEATHERTITLEWIDTH, WEATHERTITLEHEIGHT));
}

void createMainMyclothesStateFunc()
{
    //�ҵ��³�״̬
    int buttonX = INTNUMBERINIT;
    int buttonY = INTNUMBERINIT;
    //�ҵ��³�->�·�
    buttonX = MYCLOTHESBUTTONXX;
    buttonY = MYCLOTHESBUTTONXY;
    myclothesState->assignProperty(clothesButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHTER));
    //�ҵ��³�->����
    buttonX = MYCLOTHESBUTTONXX;
    buttonY = buttonY + MYCLOTHESBUTTONXHEIGHTER + MYCLOTHESBUTTONXSPACE;
    myclothesState->assignProperty(bagButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHT));
    //�ҵ��³�->Ьñ
    buttonX = MYCLOTHESBUTTONXX;
    buttonY = buttonY + MYCLOTHESBUTTONXHEIGHT + MYCLOTHESBUTTONXSPACE;
    myclothesState->assignProperty(shoeButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHT));
    //�ҵ��³�->��Ʒ
    buttonX = MYCLOTHESBUTTONXX + MYCLOTHESBUTTONXWIDTH + MYCLOTHESBUTTONXSPACE;
    buttonY = MYCLOTHESBUTTONXY;
    myclothesState->assignProperty(decoButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHT));
    //�ҵ��³�->��ױƷ
    buttonX = MYCLOTHESBUTTONXX + MYCLOTHESBUTTONXWIDTH + MYCLOTHESBUTTONXSPACE;
    buttonY = buttonY + MYCLOTHESBUTTONXHEIGHT + MYCLOTHESBUTTONXSPACE;
    myclothesState->assignProperty(cosButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHT));
    //�ҵ��³�->�Զ���
    buttonX = MYCLOTHESBUTTONXX + MYCLOTHESBUTTONXWIDTH + MYCLOTHESBUTTONXSPACE;
    buttonY = buttonY + MYCLOTHESBUTTONXHEIGHT + MYCLOTHESBUTTONXSPACE;
    myclothesState->assignProperty(labelButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHTER));
    //������->����
    buttonX = NOBUTTONRIGHTX;
    buttonY = NOBUTTONRIGHTY;
    myclothesState->assignProperty(springButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->�＾
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + FASHIONBUTTONHEIGHT + FASHIONBUTTONSPACE;
    myclothesState->assignProperty(autumnButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->ְ��
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + FASHIONBUTTONHEIGHT + FASHIONBUTTONSPACE;
    myclothesState->assignProperty(workplaceButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->����
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + FASHIONBUTTONHEIGHT + FASHIONBUTTONSPACE;
    myclothesState->assignProperty(leisureButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->�˶�
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + FASHIONBUTTONHEIGHT + FASHIONBUTTONSPACE;
    myclothesState->assignProperty(sportButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->�ļ�
    buttonX = NOBUTTONRIGHTX + FASHIONBUTTONWIDTH + FASHIONBUTTONSPACE;
    buttonY = NOBUTTONRIGHTY;
    myclothesState->assignProperty(summerButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHTER));
    //������->����
    buttonX = NOBUTTONRIGHTX + FASHIONBUTTONWIDTH + FASHIONBUTTONSPACE;
    buttonY = buttonY + FASHIONBUTTONHEIGHTER + FASHIONBUTTONSPACE;
    myclothesState->assignProperty(winterButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHTER));
    //������->���
    buttonX = NOBUTTONRIGHTX + FASHIONBUTTONWIDTH + FASHIONBUTTONSPACE;
    buttonY = buttonY + FASHIONBUTTONHEIGHTER + FASHIONBUTTONSPACE;
    myclothesState->assignProperty(banquetButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHTER));
    //������->����
    buttonX = NOBUTTONRIGHTX + FASHIONBUTTONWIDTH + FASHIONBUTTONSPACE;
    buttonY = buttonY + FASHIONBUTTONHEIGHTER + FASHIONBUTTONSPACE;
    myclothesState->assignProperty(otherButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHTER));
    //�رհ�ť
    myclothesState->assignProperty(closeButton, "geometry", QRect(buttonX, buttonY, CLOSEBUTTONWIDTH, CLOSEBUTTONHEIGHT));
    //�·�ͼƬ�б�
    myclothesState->assignProperty(clothesListWidget, "geometry", QRect(NOBUTTONTOPX, NOBUTTONTOPY, CLOTHESLISTWIDGETWIDTH, CLOTHESLISTWIDGETHEIGHT));
    //ÿ��װ������
    myclothesState->assignProperty(daydressDateEdit, "geometry", QRect(NOBUTTONTOPX, NOBUTTONTOPY, DAYDRESSLISTWIDGETWIDTH, DAYDRESSLISTWIDGETHEIGHT));
    //ÿ��װ���б�
    myclothesState->assignProperty(daydressListWidget, "geometry", QRect(NOBUTTONTOPX, NOBUTTONTOPY, DAYDRESSLISTWIDGETWIDTH, DAYDRESSLISTWIDGETHEIGHT));
    //��Ӱ�ť
    myclothesState->assignProperty(addButton, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, ADDDELBUTTONWIDTH, ADDDELBUTTONHEIGHT));
    //ɾ����ť
    myclothesState->assignProperty(delButton, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, ADDDELBUTTONWIDTH, ADDDELBUTTONHEIGHT));
    //�ӱ�Сʱ��λ
    buttonX = NOBUTTONTOPX + DIGICLOCKTIMEX;
    buttonY = NOBUTTONTOPY;
    myclothesState->assignProperty(digiClockHourHigh, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ�Сʱ��λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    myclothesState->assignProperty(digiClockHourLow, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ��λ���λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    myclothesState->assignProperty(digiClockPointsHigh, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTH, DIGICLOCKTIMEHEIGHTER));
    //�ӱ���Ӹ�λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTH + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    myclothesState->assignProperty(digiClockMinuteHigh, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ���ӵ�λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    myclothesState->assignProperty(digiClockMinuteLow, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ��λ���λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    myclothesState->assignProperty(digiClockPointsLow, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTH, DIGICLOCKTIMEHEIGHTER));
    //�ӱ�������λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTH + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    myclothesState->assignProperty(digiClockSecondHigh, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ�������λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    myclothesState->assignProperty(digiClockSecondLow, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ�ʱ�䱳��
    buttonX = NOBUTTONTOPX + DIGICLOCKTIMEBKGX;
    buttonY = NOBUTTONTOPY;
    myclothesState->assignProperty(digiClockTimeBkg, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEBKGWIDTH, DIGICLOCKTIMEBKGHEIGHT));
    //�ӱ����ڱ���
    buttonX = NOBUTTONTOPX + DIGICLOCKDATEBKGX;
    buttonY = NOBUTTONTOPY;
    myclothesState->assignProperty(digiClockDateBkg, "geometry", QRect(buttonX, buttonY, DIGICLOCKDATEBKGWIDTH, DIGICLOCKDATEBKGHEIGHT));
    //�ӱ����ڱ�������
    myclothesState->assignProperty(digiClockDateBkgText, "geometry", QRect(buttonX, buttonY-2, DIGICLOCKDATEBKGWIDTH, DIGICLOCKDATEBKGHEIGHT));
    //����Ԥ������ͼƬ
    myclothesState->assignProperty(weatherBackground, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, WEATHERBACKGROUNDWIDTH, WEATHERBACKGROUNDHEIGHT));
    //����Ԥ����ʶ
    myclothesState->assignProperty(weatherImage, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, WEATHERIMAGEWIDTH, WEATHERIMAGEHEIGHT));
    //����Ԥ���ص�
    myclothesState->assignProperty(weatherPlace, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, WEATHERPLACEWIDTH, WEATHERPLACEHEIGHT));
    //����Ԥ���¶�
    myclothesState->assignProperty(weatherTemp, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, WEATHERTEMPWIDTH, WEATHERTEMPHEIGHT));
    //����Ԥ����������
    myclothesState->assignProperty(weatherTitle, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, WEATHERTITLEWIDTH, WEATHERTITLEHEIGHT));
}

void createMainFashionStateFunc()
{
    //������״̬
    int buttonX = INTNUMBERINIT;
    int buttonY = INTNUMBERINIT;
    //�ҵ��³�->�·�
    buttonX = NOBUTTONRIGHTX;
    buttonY = NOBUTTONRIGHTY;
    fashionState->assignProperty(clothesButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHTER));
    //�ҵ��³�->����
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + MYCLOTHESBUTTONXHEIGHTER + MYCLOTHESBUTTONXSPACE;
    fashionState->assignProperty(bagButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHT));
    //�ҵ��³�->Ьñ
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + MYCLOTHESBUTTONXHEIGHT + MYCLOTHESBUTTONXSPACE;
    fashionState->assignProperty(shoeButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHT));
    //�ҵ��³�->��Ʒ
    buttonX = NOBUTTONRIGHTX + MYCLOTHESBUTTONXWIDTH + MYCLOTHESBUTTONXSPACE;
    buttonY = NOBUTTONRIGHTY;
    fashionState->assignProperty(decoButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHT));
    //�ҵ��³�->��ױƷ
    buttonX = NOBUTTONRIGHTX + MYCLOTHESBUTTONXWIDTH + MYCLOTHESBUTTONXSPACE;
    buttonY = buttonY + MYCLOTHESBUTTONXHEIGHT + MYCLOTHESBUTTONXSPACE;
    fashionState->assignProperty(cosButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHT));
    //�ҵ��³�->�Զ���
    buttonX = NOBUTTONRIGHTX + MYCLOTHESBUTTONXWIDTH + MYCLOTHESBUTTONXSPACE;
    buttonY = buttonY + MYCLOTHESBUTTONXHEIGHT + MYCLOTHESBUTTONXSPACE;
    fashionState->assignProperty(labelButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHTER));
    //�رհ�ť
    fashionState->assignProperty(closeButton, "geometry", QRect(buttonX, buttonY, CLOSEBUTTONWIDTH, CLOSEBUTTONHEIGHT));
    //������->����
    buttonX = FASHIONBUTTONX;
    buttonY = FASHIONBUTTONY;
    fashionState->assignProperty(springButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->�＾
    buttonX = FASHIONBUTTONX;
    buttonY = buttonY + FASHIONBUTTONHEIGHT + FASHIONBUTTONSPACE;
    fashionState->assignProperty(autumnButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->ְ��
    buttonX = FASHIONBUTTONX;
    buttonY = buttonY + FASHIONBUTTONHEIGHT + FASHIONBUTTONSPACE;
    fashionState->assignProperty(workplaceButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->����
    buttonX = FASHIONBUTTONX;
    buttonY = buttonY + FASHIONBUTTONHEIGHT + FASHIONBUTTONSPACE;
    fashionState->assignProperty(leisureButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->�˶�
    buttonX = FASHIONBUTTONX;
    buttonY = buttonY + FASHIONBUTTONHEIGHT + FASHIONBUTTONSPACE;
    fashionState->assignProperty(sportButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->�ļ�
    buttonX = FASHIONBUTTONX + FASHIONBUTTONWIDTH + FASHIONBUTTONSPACE;
    buttonY = FASHIONBUTTONY;
    fashionState->assignProperty(summerButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHTER));
    //������->����
    buttonX = FASHIONBUTTONX + FASHIONBUTTONWIDTH + FASHIONBUTTONSPACE;
    buttonY = buttonY + FASHIONBUTTONHEIGHTER + FASHIONBUTTONSPACE;
    fashionState->assignProperty(winterButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHTER));
    //������->���
    buttonX = FASHIONBUTTONX + FASHIONBUTTONWIDTH + FASHIONBUTTONSPACE;
    buttonY = buttonY + FASHIONBUTTONHEIGHTER + FASHIONBUTTONSPACE;
    fashionState->assignProperty(banquetButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHTER));
    //������->����
    buttonX = FASHIONBUTTONX + FASHIONBUTTONWIDTH + FASHIONBUTTONSPACE;
    buttonY = buttonY + FASHIONBUTTONHEIGHTER + FASHIONBUTTONSPACE;
    fashionState->assignProperty(otherButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHTER));
    //�·�ͼƬ�б�
    fashionState->assignProperty(clothesListWidget, "geometry", QRect(NOBUTTONTOPX, NOBUTTONTOPY, CLOTHESLISTWIDGETWIDTH, CLOTHESLISTWIDGETHEIGHT));
    //ÿ��װ������
    fashionState->assignProperty(daydressDateEdit, "geometry", QRect(NOBUTTONTOPX, NOBUTTONTOPY, DAYDRESSLISTWIDGETWIDTH, DAYDRESSLISTWIDGETHEIGHT));
    //ÿ��װ���б�
    fashionState->assignProperty(daydressListWidget, "geometry", QRect(NOBUTTONTOPX, NOBUTTONTOPY, DAYDRESSLISTWIDGETWIDTH, DAYDRESSLISTWIDGETHEIGHT));
    //��Ӱ�ť
    fashionState->assignProperty(addButton, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, ADDDELBUTTONWIDTH, ADDDELBUTTONHEIGHT));
    //ɾ����ť
    fashionState->assignProperty(delButton, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, ADDDELBUTTONWIDTH, ADDDELBUTTONHEIGHT));
    //�ӱ�Сʱ��λ
    buttonX = NOBUTTONTOPX + DIGICLOCKTIMEX;
    buttonY = NOBUTTONTOPY;
    fashionState->assignProperty(digiClockHourHigh, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ�Сʱ��λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    fashionState->assignProperty(digiClockHourLow, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ��λ���λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    fashionState->assignProperty(digiClockPointsHigh, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTH, DIGICLOCKTIMEHEIGHTER));
    //�ӱ���Ӹ�λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTH + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    fashionState->assignProperty(digiClockMinuteHigh, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ���ӵ�λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    fashionState->assignProperty(digiClockMinuteLow, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ��λ���λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    fashionState->assignProperty(digiClockPointsLow, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTH, DIGICLOCKTIMEHEIGHTER));
    //�ӱ�������λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTH + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    fashionState->assignProperty(digiClockSecondHigh, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ�������λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    fashionState->assignProperty(digiClockSecondLow, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ�ʱ�䱳��
    buttonX = NOBUTTONTOPX + DIGICLOCKTIMEBKGX;
    buttonY = NOBUTTONTOPY;
    fashionState->assignProperty(digiClockTimeBkg, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEBKGWIDTH, DIGICLOCKTIMEBKGHEIGHT));
    //�ӱ����ڱ���
    buttonX = NOBUTTONTOPX + DIGICLOCKDATEBKGX;
    buttonY = NOBUTTONTOPY;
    fashionState->assignProperty(digiClockDateBkg, "geometry", QRect(buttonX, buttonY, DIGICLOCKDATEBKGWIDTH, DIGICLOCKDATEBKGHEIGHT));
    //�ӱ����ڱ�������
    fashionState->assignProperty(digiClockDateBkgText, "geometry", QRect(buttonX, buttonY-2, DIGICLOCKDATEBKGWIDTH, DIGICLOCKDATEBKGHEIGHT));
    //����Ԥ������ͼƬ
    fashionState->assignProperty(weatherBackground, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, WEATHERBACKGROUNDWIDTH, WEATHERBACKGROUNDHEIGHT));
    //����Ԥ����ʶ
    fashionState->assignProperty(weatherImage, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, WEATHERIMAGEWIDTH, WEATHERIMAGEHEIGHT));
    //����Ԥ���ص�
    fashionState->assignProperty(weatherPlace, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, WEATHERPLACEWIDTH, WEATHERPLACEHEIGHT));
    //����Ԥ���¶�
    fashionState->assignProperty(weatherTemp, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, WEATHERTEMPWIDTH, WEATHERTEMPHEIGHT));
    //����Ԥ����������
    fashionState->assignProperty(weatherTitle, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, WEATHERTITLEWIDTH, WEATHERTITLEHEIGHT));
}

void createMainDayDressStateFunc()
{
    //ÿ��װ��״̬
    int buttonX = INTNUMBERINIT;
    int buttonY = INTNUMBERINIT;
    //�ҵ��³�->�·�
    buttonX = NOBUTTONRIGHTX;
    buttonY = NOBUTTONRIGHTY;
    daydressStatue->assignProperty(clothesButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHTER));
    //�ҵ��³�->����
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + MYCLOTHESBUTTONXHEIGHTER + MYCLOTHESBUTTONXSPACE;
    daydressStatue->assignProperty(bagButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHT));
    //�ҵ��³�->Ьñ
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + MYCLOTHESBUTTONXHEIGHT + MYCLOTHESBUTTONXSPACE;
    daydressStatue->assignProperty(shoeButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHT));
    //�ҵ��³�->��Ʒ
    buttonX = NOBUTTONRIGHTX + MYCLOTHESBUTTONXWIDTH + MYCLOTHESBUTTONXSPACE;
    buttonY = NOBUTTONRIGHTY;
    daydressStatue->assignProperty(decoButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHT));
    //�ҵ��³�->��ױƷ
    buttonX = NOBUTTONRIGHTX + MYCLOTHESBUTTONXWIDTH + MYCLOTHESBUTTONXSPACE;
    buttonY = buttonY + MYCLOTHESBUTTONXHEIGHT + MYCLOTHESBUTTONXSPACE;
    daydressStatue->assignProperty(cosButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHT));
    //�ҵ��³�->�Զ���
    buttonX = NOBUTTONRIGHTX + MYCLOTHESBUTTONXWIDTH + MYCLOTHESBUTTONXSPACE;
    buttonY = buttonY + MYCLOTHESBUTTONXHEIGHT + MYCLOTHESBUTTONXSPACE;
    daydressStatue->assignProperty(labelButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHTER));
    //������->����
    buttonX = NOBUTTONRIGHTX;
    buttonY = NOBUTTONRIGHTY;
    daydressStatue->assignProperty(springButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->�＾
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + FASHIONBUTTONHEIGHT + FASHIONBUTTONSPACE;
    daydressStatue->assignProperty(autumnButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->ְ��
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + FASHIONBUTTONHEIGHT + FASHIONBUTTONSPACE;
    daydressStatue->assignProperty(workplaceButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->����
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + FASHIONBUTTONHEIGHT + FASHIONBUTTONSPACE;
    daydressStatue->assignProperty(leisureButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->�˶�
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + FASHIONBUTTONHEIGHT + FASHIONBUTTONSPACE;
    daydressStatue->assignProperty(sportButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->�ļ�
    buttonX = NOBUTTONRIGHTX + FASHIONBUTTONWIDTH + FASHIONBUTTONSPACE;
    buttonY = NOBUTTONRIGHTY;
    daydressStatue->assignProperty(summerButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHTER));
    //������->����
    buttonX = NOBUTTONRIGHTX + FASHIONBUTTONWIDTH + FASHIONBUTTONSPACE;
    buttonY = buttonY + FASHIONBUTTONHEIGHTER + FASHIONBUTTONSPACE;
    daydressStatue->assignProperty(winterButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHTER));
    //������->���
    buttonX = NOBUTTONRIGHTX + FASHIONBUTTONWIDTH + FASHIONBUTTONSPACE;
    buttonY = buttonY + FASHIONBUTTONHEIGHTER + FASHIONBUTTONSPACE;
    daydressStatue->assignProperty(banquetButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHTER));
    //������->����
    buttonX = NOBUTTONRIGHTX + FASHIONBUTTONWIDTH + FASHIONBUTTONSPACE;
    buttonY = buttonY + FASHIONBUTTONHEIGHTER + FASHIONBUTTONSPACE;
    daydressStatue->assignProperty(otherButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHTER));
    //�رհ�ť
    daydressStatue->assignProperty(closeButton, "geometry", QRect(buttonX, buttonY, CLOSEBUTTONWIDTH, CLOSEBUTTONHEIGHT));
    //�·�ͼƬ�б�
    daydressStatue->assignProperty(clothesListWidget, "geometry", QRect(NOBUTTONTOPX, NOBUTTONTOPY, CLOTHESLISTWIDGETWIDTH, CLOTHESLISTWIDGETHEIGHT));
    //ÿ��װ������
    daydressStatue->assignProperty(daydressDateEdit, "geometry", QRect(DAYDRESSDATEEDITX, DAYDRESSDATEEDITY, DAYDRESSDATEEDITWIDTH, DAYDRESSDATEEDITHEIGHT));
    //ÿ��װ���б�
    daydressStatue->assignProperty(daydressListWidget, "geometry", QRect(DAYDRESSLISTWIDGETX, DAYDRESSLISTWIDGETY, DAYDRESSLISTWIDGETWIDTH, DAYDRESSLISTWIDGETHEIGHT));
    //��Ӱ�ť
    buttonX = ADDDELBUTTONX;
    buttonY = ADDDELBUTTONY;
    daydressStatue->assignProperty(addButton, "geometry", QRect(buttonX, buttonY, ADDDELBUTTONWIDTH, ADDDELBUTTONHEIGHT));
    //ɾ����ť
    buttonX = buttonX + ADDDELBUTTONWIDTH + ADDDELBUTTONSPACE;
    buttonY = ADDDELBUTTONY;
    daydressStatue->assignProperty(delButton, "geometry", QRect(buttonX, buttonY, ADDDELBUTTONWIDTH, ADDDELBUTTONHEIGHT));
    //�ӱ�Сʱ��λ
    buttonX = NOBUTTONTOPX + DIGICLOCKTIMEX;
    buttonY = NOBUTTONTOPY;
    daydressStatue->assignProperty(digiClockHourHigh, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ�Сʱ��λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    daydressStatue->assignProperty(digiClockHourLow, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ��λ���λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    daydressStatue->assignProperty(digiClockPointsHigh, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTH, DIGICLOCKTIMEHEIGHTER));
    //�ӱ���Ӹ�λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTH + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    daydressStatue->assignProperty(digiClockMinuteHigh, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ���ӵ�λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    daydressStatue->assignProperty(digiClockMinuteLow, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ��λ���λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    daydressStatue->assignProperty(digiClockPointsLow, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTH, DIGICLOCKTIMEHEIGHTER));
    //�ӱ�������λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTH + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    daydressStatue->assignProperty(digiClockSecondHigh, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ�������λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    daydressStatue->assignProperty(digiClockSecondLow, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ�ʱ�䱳��
    buttonX = NOBUTTONTOPX + DIGICLOCKTIMEBKGX;
    buttonY = NOBUTTONTOPY;
    daydressStatue->assignProperty(digiClockTimeBkg, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEBKGWIDTH, DIGICLOCKTIMEBKGHEIGHT));
    //�ӱ����ڱ���
    buttonX = NOBUTTONTOPX + DIGICLOCKDATEBKGX;
    buttonY = NOBUTTONTOPY;
    daydressStatue->assignProperty(digiClockDateBkg, "geometry", QRect(buttonX, buttonY, DIGICLOCKDATEBKGWIDTH, DIGICLOCKDATEBKGHEIGHT));
    //�ӱ����ڱ�������
    daydressStatue->assignProperty(digiClockDateBkgText, "geometry", QRect(buttonX, buttonY-2, DIGICLOCKDATEBKGWIDTH, DIGICLOCKDATEBKGHEIGHT));
    //����Ԥ������ͼƬ
    daydressStatue->assignProperty(weatherBackground, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, WEATHERBACKGROUNDWIDTH, WEATHERBACKGROUNDHEIGHT));
    //����Ԥ����ʶ
    daydressStatue->assignProperty(weatherImage, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, WEATHERIMAGEWIDTH, WEATHERIMAGEHEIGHT));
    //����Ԥ���ص�
    daydressStatue->assignProperty(weatherPlace, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, WEATHERPLACEWIDTH, WEATHERPLACEHEIGHT));
    //����Ԥ���¶�
    daydressStatue->assignProperty(weatherTemp, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, WEATHERTEMPWIDTH, WEATHERTEMPHEIGHT));
    //����Ԥ����������
    daydressStatue->assignProperty(weatherTitle, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, WEATHERTITLEWIDTH, WEATHERTITLEHEIGHT));
}

void createMainClothesStateFunc()
{
    //����Ŀ¼״̬
    int buttonX = INTNUMBERINIT;
    int buttonY = INTNUMBERINIT;
    //�ҵ��³�->�·�
    buttonX = NOBUTTONRIGHTX;
    buttonY = NOBUTTONRIGHTY;
    clothesState->assignProperty(clothesButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHTER));
    //�ҵ��³�->����
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + MYCLOTHESBUTTONXHEIGHTER + MYCLOTHESBUTTONXSPACE;
    clothesState->assignProperty(bagButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHT));
    //�ҵ��³�->Ьñ
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + MYCLOTHESBUTTONXHEIGHT + MYCLOTHESBUTTONXSPACE;
    clothesState->assignProperty(shoeButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHT));
    //�ҵ��³�->��Ʒ
    buttonX = NOBUTTONRIGHTX + MYCLOTHESBUTTONXWIDTH + MYCLOTHESBUTTONXSPACE;
    buttonY = NOBUTTONRIGHTY;
    clothesState->assignProperty(decoButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHT));
    //�ҵ��³�->��ױƷ
    buttonX = NOBUTTONRIGHTX + MYCLOTHESBUTTONXWIDTH + MYCLOTHESBUTTONXSPACE;
    buttonY = buttonY + MYCLOTHESBUTTONXHEIGHT + MYCLOTHESBUTTONXSPACE;
    clothesState->assignProperty(cosButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHT));
    //�ҵ��³�->�Զ���
    buttonX = NOBUTTONRIGHTX + MYCLOTHESBUTTONXWIDTH + MYCLOTHESBUTTONXSPACE;
    buttonY = buttonY + MYCLOTHESBUTTONXHEIGHT + MYCLOTHESBUTTONXSPACE;
    clothesState->assignProperty(labelButton, "geometry", QRect(buttonX, buttonY, MYCLOTHESBUTTONXWIDTH, MYCLOTHESBUTTONXHEIGHTER));
    //������->����
    buttonX = NOBUTTONRIGHTX;
    buttonY = NOBUTTONRIGHTY;
    clothesState->assignProperty(springButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->�＾
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + FASHIONBUTTONHEIGHT + FASHIONBUTTONSPACE;
    clothesState->assignProperty(autumnButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->ְ��
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + FASHIONBUTTONHEIGHT + FASHIONBUTTONSPACE;
    clothesState->assignProperty(workplaceButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->����
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + FASHIONBUTTONHEIGHT + FASHIONBUTTONSPACE;
    clothesState->assignProperty(leisureButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->�˶�
    buttonX = NOBUTTONRIGHTX;
    buttonY = buttonY + FASHIONBUTTONHEIGHT + FASHIONBUTTONSPACE;
    clothesState->assignProperty(sportButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHT));
    //������->�ļ�
    buttonX = NOBUTTONRIGHTX + FASHIONBUTTONWIDTH + FASHIONBUTTONSPACE;
    buttonY = NOBUTTONRIGHTY;
    clothesState->assignProperty(summerButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHTER));
    //������->����
    buttonX = NOBUTTONRIGHTX + FASHIONBUTTONWIDTH + FASHIONBUTTONSPACE;
    buttonY = buttonY + FASHIONBUTTONHEIGHTER + FASHIONBUTTONSPACE;
    clothesState->assignProperty(winterButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHTER));
    //������->���
    buttonX = NOBUTTONRIGHTX + FASHIONBUTTONWIDTH + FASHIONBUTTONSPACE;
    buttonY = buttonY + FASHIONBUTTONHEIGHTER + FASHIONBUTTONSPACE;
    clothesState->assignProperty(banquetButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHTER));
    //������->����
    buttonX = NOBUTTONRIGHTX + FASHIONBUTTONWIDTH + FASHIONBUTTONSPACE;
    buttonY = buttonY + FASHIONBUTTONHEIGHTER + FASHIONBUTTONSPACE;
    clothesState->assignProperty(otherButton, "geometry", QRect(buttonX, buttonY, FASHIONBUTTONWIDTH, FASHIONBUTTONHEIGHTER));
    //�رհ�ť
    clothesState->assignProperty(closeButton, "geometry", QRect(buttonX, buttonY, CLOSEBUTTONWIDTH, CLOSEBUTTONHEIGHT));
    //�·�ͼƬ�б�
    clothesState->assignProperty(clothesListWidget, "geometry", QRect(CLOTHESLISTWIDGETX, CLOTHESLISTWIDGETY, CLOTHESLISTWIDGETWIDTH, CLOTHESLISTWIDGETHEIGHT));
    //ÿ��װ������
    clothesState->assignProperty(daydressDateEdit, "geometry", QRect(NOBUTTONTOPX, NOBUTTONTOPY, DAYDRESSLISTWIDGETWIDTH, DAYDRESSLISTWIDGETHEIGHT));
    //ÿ��װ���б�
    clothesState->assignProperty(daydressListWidget, "geometry", QRect(NOBUTTONTOPX, NOBUTTONTOPY, DAYDRESSLISTWIDGETWIDTH, DAYDRESSLISTWIDGETHEIGHT));
    //��Ӱ�ť
    buttonX = ADDDELBUTTONX;
    buttonY = ADDDELBUTTONY;
    clothesState->assignProperty(addButton, "geometry", QRect(buttonX, buttonY, ADDDELBUTTONWIDTH, ADDDELBUTTONHEIGHT));
    //ɾ����ť
    buttonX = buttonX + ADDDELBUTTONWIDTH + ADDDELBUTTONSPACE;
    buttonY = ADDDELBUTTONY;
    clothesState->assignProperty(delButton, "geometry", QRect(buttonX, buttonY, ADDDELBUTTONWIDTH, ADDDELBUTTONHEIGHT));
    //�ӱ�Сʱ��λ
    buttonX = NOBUTTONTOPX + DIGICLOCKTIMEX;
    buttonY = NOBUTTONTOPY;
    clothesState->assignProperty(digiClockHourHigh, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ�Сʱ��λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    clothesState->assignProperty(digiClockHourLow, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ��λ���λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    clothesState->assignProperty(digiClockPointsHigh, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTH, DIGICLOCKTIMEHEIGHTER));
    //�ӱ���Ӹ�λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTH + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    clothesState->assignProperty(digiClockMinuteHigh, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ���ӵ�λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    clothesState->assignProperty(digiClockMinuteLow, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ��λ���λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    clothesState->assignProperty(digiClockPointsLow, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTH, DIGICLOCKTIMEHEIGHTER));
    //�ӱ�������λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTH + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    clothesState->assignProperty(digiClockSecondHigh, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ�������λ
    buttonX = buttonX + DIGICLOCKTIMEWIDTHER + DIGICLOCKTIMESPACE;
    buttonY = NOBUTTONTOPY;
    clothesState->assignProperty(digiClockSecondLow, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEWIDTHER, DIGICLOCKTIMEHEIGHTER));
    //�ӱ�ʱ�䱳��
    buttonX = NOBUTTONTOPX + DIGICLOCKTIMEBKGX;
    buttonY = NOBUTTONTOPY;
    clothesState->assignProperty(digiClockTimeBkg, "geometry", QRect(buttonX, buttonY, DIGICLOCKTIMEBKGWIDTH, DIGICLOCKTIMEBKGHEIGHT));
    //�ӱ����ڱ���
    buttonX = NOBUTTONTOPX + DIGICLOCKDATEBKGX;
    buttonY = NOBUTTONTOPY;
    clothesState->assignProperty(digiClockDateBkg, "geometry", QRect(buttonX, buttonY, DIGICLOCKDATEBKGWIDTH, DIGICLOCKDATEBKGHEIGHT));
    //�ӱ����ڱ�������
    clothesState->assignProperty(digiClockDateBkgText, "geometry", QRect(buttonX, buttonY-2, DIGICLOCKDATEBKGWIDTH, DIGICLOCKDATEBKGHEIGHT));
    //����Ԥ������ͼƬ
    clothesState->assignProperty(weatherBackground, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, WEATHERBACKGROUNDWIDTH, WEATHERBACKGROUNDHEIGHT));
    //����Ԥ����ʶ
    clothesState->assignProperty(weatherImage, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, WEATHERIMAGEWIDTH, WEATHERIMAGEHEIGHT));
    //����Ԥ���ص�
    clothesState->assignProperty(weatherPlace, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, WEATHERPLACEWIDTH, WEATHERPLACEHEIGHT));
    //����Ԥ���¶�
    clothesState->assignProperty(weatherTemp, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, WEATHERTEMPWIDTH, WEATHERTEMPHEIGHT));
    //����Ԥ����������
    clothesState->assignProperty(weatherTitle, "geometry", QRect(NOBUTTONBOTTOMX, NOBUTTONBOTTOMY, WEATHERTITLEWIDTH, WEATHERTITLEHEIGHT));
}


void createMainSignalTransitionFunc()
{
    //�ź�ת������
    myclothesToClothesST = myclothesState->addTransition(secondLayerButton, SIGNAL(clicked()), clothesState);
    myclothesToFashionST = myclothesState->addTransition(fashionButton, SIGNAL(clicked()), fashionState);
    myclothesToDaydressST = myclothesState->addTransition(daydressButton, SIGNAL(clicked()), daydressStatue);
    myclothesToSettingST = myclothesState->addTransition(settingButton, SIGNAL(clicked()), settingState);

    fashionToClothesST = fashionState->addTransition(secondLayerButton, SIGNAL(clicked()), clothesState);
    fashionToMyclothesST = fashionState->addTransition(myclothesButton, SIGNAL(clicked()), myclothesState);
    fashionToDaydressST = fashionState->addTransition(daydressButton, SIGNAL(clicked()), daydressStatue);
    fashionToSettingST = fashionState->addTransition(settingButton, SIGNAL(clicked()), settingState);

    daydressToMyclothesST = daydressStatue->addTransition(myclothesButton, SIGNAL(clicked()), myclothesState);
    daydressToFashionST = daydressStatue->addTransition(fashionButton, SIGNAL(clicked()), fashionState);
    daydressToSettingST = daydressStatue->addTransition(settingButton, SIGNAL(clicked()), settingState);

    settingToMyclothesST = settingState->addTransition(myclothesButton, SIGNAL(clicked()), myclothesState);
    settingToFashionST = settingState->addTransition(fashionButton, SIGNAL(clicked()), fashionState);
    settingToDaydressST = settingState->addTransition(daydressButton, SIGNAL(clicked()), daydressStatue);

    clothesToMyclothesST = clothesState->addTransition(myclothesButton, SIGNAL(clicked()), myclothesState);
    clothesToFashionST = clothesState->addTransition(fashionButton, SIGNAL(clicked()), fashionState);
    clothesToDaydressST = clothesState->addTransition(daydressButton, SIGNAL(clicked()), daydressStatue);
    clothesToSettingST = clothesState->addTransition(settingButton, SIGNAL(clicked()), settingState);
}

void createMainPropertyAnimationFunc()
{
    //��������
    myclothesToClothesST->addAnimation(new QPropertyAnimation(clothesButton, "geometry"));
    myclothesToClothesST->addAnimation(new QPropertyAnimation(bagButton, "geometry"));
    myclothesToClothesST->addAnimation(new QPropertyAnimation(shoeButton, "geometry"));
    myclothesToClothesST->addAnimation(new QPropertyAnimation(decoButton, "geometry"));
    myclothesToClothesST->addAnimation(new QPropertyAnimation(cosButton, "geometry"));
    myclothesToClothesST->addAnimation(new QPropertyAnimation(labelButton, "geometry"));
    myclothesToClothesST->addAnimation(new QPropertyAnimation(springButton, "geometry"));
    myclothesToClothesST->addAnimation(new QPropertyAnimation(summerButton, "geometry"));
    myclothesToClothesST->addAnimation(new QPropertyAnimation(autumnButton, "geometry"));
    myclothesToClothesST->addAnimation(new QPropertyAnimation(winterButton, "geometry"));
    myclothesToClothesST->addAnimation(new QPropertyAnimation(workplaceButton, "geometry"));
    myclothesToClothesST->addAnimation(new QPropertyAnimation(banquetButton, "geometry"));
    myclothesToClothesST->addAnimation(new QPropertyAnimation(leisureButton, "geometry"));
    myclothesToClothesST->addAnimation(new QPropertyAnimation(sportButton, "geometry"));
    myclothesToClothesST->addAnimation(new QPropertyAnimation(otherButton, "geometry"));
    myclothesToClothesST->addAnimation(new QPropertyAnimation(closeButton, "geometry"));

    myclothesToFashionST->addAnimation(new QPropertyAnimation(clothesButton, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(bagButton, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(shoeButton, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(decoButton, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(cosButton, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(labelButton, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(springButton, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(summerButton, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(autumnButton, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(winterButton, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(workplaceButton, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(banquetButton, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(leisureButton, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(sportButton, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(otherButton, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(closeButton, "geometry"));

    myclothesToDaydressST->addAnimation(new QPropertyAnimation(clothesButton, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(bagButton, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(shoeButton, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(decoButton, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(cosButton, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(labelButton, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(springButton, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(summerButton, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(autumnButton, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(winterButton, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(workplaceButton, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(banquetButton, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(leisureButton, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(sportButton, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(otherButton, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(closeButton, "geometry"));

    myclothesToSettingST->addAnimation(new QPropertyAnimation(clothesButton, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(bagButton, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(shoeButton, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(decoButton, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(cosButton, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(labelButton, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(springButton, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(summerButton, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(autumnButton, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(winterButton, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(workplaceButton, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(banquetButton, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(leisureButton, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(sportButton, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(otherButton, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(closeButton, "geometry"));

    fashionToClothesST->addAnimation(new QPropertyAnimation(clothesButton, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(bagButton, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(shoeButton, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(decoButton, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(cosButton, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(labelButton, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(springButton, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(summerButton, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(autumnButton, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(winterButton, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(workplaceButton, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(banquetButton, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(leisureButton, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(sportButton, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(otherButton, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(closeButton, "geometry"));

    fashionToMyclothesST->addAnimation(new QPropertyAnimation(clothesButton, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(bagButton, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(shoeButton, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(decoButton, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(cosButton, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(labelButton, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(springButton, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(summerButton, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(autumnButton, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(winterButton, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(workplaceButton, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(banquetButton, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(leisureButton, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(sportButton, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(otherButton, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(closeButton, "geometry"));

    fashionToDaydressST->addAnimation(new QPropertyAnimation(clothesButton, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(bagButton, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(shoeButton, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(decoButton, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(cosButton, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(labelButton, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(springButton, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(summerButton, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(autumnButton, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(winterButton, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(workplaceButton, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(banquetButton, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(leisureButton, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(sportButton, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(otherButton, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(closeButton, "geometry"));

    fashionToSettingST->addAnimation(new QPropertyAnimation(clothesButton, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(bagButton, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(shoeButton, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(decoButton, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(cosButton, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(labelButton, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(springButton, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(summerButton, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(autumnButton, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(winterButton, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(workplaceButton, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(banquetButton, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(leisureButton, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(sportButton, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(otherButton, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(closeButton, "geometry"));

    daydressToMyclothesST->addAnimation(new QPropertyAnimation(clothesButton, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(bagButton, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(shoeButton, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(decoButton, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(cosButton, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(labelButton, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(springButton, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(summerButton, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(autumnButton, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(winterButton, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(workplaceButton, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(banquetButton, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(leisureButton, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(sportButton, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(otherButton, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(closeButton, "geometry"));

    daydressToFashionST->addAnimation(new QPropertyAnimation(clothesButton, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(bagButton, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(shoeButton, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(decoButton, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(cosButton, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(labelButton, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(springButton, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(summerButton, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(autumnButton, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(winterButton, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(workplaceButton, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(banquetButton, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(leisureButton, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(sportButton, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(otherButton, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(closeButton, "geometry"));

    daydressToSettingST->addAnimation(new QPropertyAnimation(clothesButton, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(bagButton, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(shoeButton, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(decoButton, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(cosButton, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(labelButton, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(springButton, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(summerButton, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(autumnButton, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(winterButton, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(workplaceButton, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(banquetButton, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(leisureButton, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(sportButton, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(otherButton, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(closeButton, "geometry"));

    settingToMyclothesST->addAnimation(new QPropertyAnimation(clothesButton, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(bagButton, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(shoeButton, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(decoButton, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(cosButton, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(labelButton, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(springButton, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(summerButton, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(autumnButton, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(winterButton, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(workplaceButton, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(banquetButton, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(leisureButton, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(sportButton, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(otherButton, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(closeButton, "geometry"));

    settingToFashionST->addAnimation(new QPropertyAnimation(clothesButton, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(bagButton, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(shoeButton, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(decoButton, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(cosButton, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(labelButton, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(springButton, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(summerButton, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(autumnButton, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(winterButton, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(workplaceButton, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(banquetButton, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(leisureButton, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(sportButton, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(otherButton, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(closeButton, "geometry"));

    settingToDaydressST->addAnimation(new QPropertyAnimation(clothesButton, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(bagButton, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(shoeButton, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(decoButton, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(cosButton, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(labelButton, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(springButton, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(summerButton, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(autumnButton, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(winterButton, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(workplaceButton, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(banquetButton, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(leisureButton, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(sportButton, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(otherButton, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(closeButton, "geometry"));

    clothesToMyclothesST->addAnimation(new QPropertyAnimation(clothesButton, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(bagButton, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(shoeButton, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(decoButton, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(cosButton, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(labelButton, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(springButton, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(summerButton, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(autumnButton, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(winterButton, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(workplaceButton, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(banquetButton, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(leisureButton, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(sportButton, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(otherButton, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(closeButton, "geometry"));

    clothesToFashionST->addAnimation(new QPropertyAnimation(clothesButton, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(bagButton, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(shoeButton, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(decoButton, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(cosButton, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(labelButton, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(springButton, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(summerButton, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(autumnButton, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(winterButton, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(workplaceButton, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(banquetButton, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(leisureButton, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(sportButton, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(otherButton, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(closeButton, "geometry"));

    clothesToDaydressST->addAnimation(new QPropertyAnimation(clothesButton, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(bagButton, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(shoeButton, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(decoButton, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(cosButton, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(labelButton, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(springButton, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(summerButton, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(autumnButton, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(winterButton, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(workplaceButton, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(banquetButton, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(leisureButton, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(sportButton, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(otherButton, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(closeButton, "geometry"));

    clothesToSettingST->addAnimation(new QPropertyAnimation(clothesButton, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(bagButton, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(shoeButton, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(decoButton, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(cosButton, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(labelButton, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(springButton, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(summerButton, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(autumnButton, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(winterButton, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(workplaceButton, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(banquetButton, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(leisureButton, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(sportButton, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(otherButton, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(closeButton, "geometry"));

    myclothesToClothesST->addAnimation(new QPropertyAnimation(clothesListWidget, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(clothesListWidget, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(clothesListWidget, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(clothesListWidget, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(clothesListWidget, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(clothesListWidget, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(clothesListWidget, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(clothesListWidget, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(clothesListWidget, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(clothesListWidget, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(clothesListWidget, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(clothesListWidget, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(clothesListWidget, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(clothesListWidget, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(clothesListWidget, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(clothesListWidget, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(clothesListWidget, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(clothesListWidget, "geometry"));

    myclothesToClothesST->addAnimation(new QPropertyAnimation(daydressListWidget, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(daydressListWidget, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(daydressListWidget, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(daydressListWidget, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(daydressListWidget, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(daydressListWidget, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(daydressListWidget, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(daydressListWidget, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(daydressListWidget, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(daydressListWidget, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(daydressListWidget, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(daydressListWidget, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(daydressListWidget, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(daydressListWidget, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(daydressListWidget, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(daydressListWidget, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(daydressListWidget, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(daydressListWidget, "geometry"));

    myclothesToClothesST->addAnimation(new QPropertyAnimation(digiClockHourHigh, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(digiClockHourHigh, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(digiClockHourHigh, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(digiClockHourHigh, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(digiClockHourHigh, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(digiClockHourHigh, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(digiClockHourHigh, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(digiClockHourHigh, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(digiClockHourHigh, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(digiClockHourHigh, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(digiClockHourHigh, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(digiClockHourHigh, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(digiClockHourHigh, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(digiClockHourHigh, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(digiClockHourHigh, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(digiClockHourHigh, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(digiClockHourHigh, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(digiClockHourHigh, "geometry"));

    myclothesToClothesST->addAnimation(new QPropertyAnimation(digiClockHourLow, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(digiClockHourLow, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(digiClockHourLow, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(digiClockHourLow, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(digiClockHourLow, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(digiClockHourLow, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(digiClockHourLow, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(digiClockHourLow, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(digiClockHourLow, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(digiClockHourLow, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(digiClockHourLow, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(digiClockHourLow, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(digiClockHourLow, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(digiClockHourLow, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(digiClockHourLow, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(digiClockHourLow, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(digiClockHourLow, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(digiClockHourLow, "geometry"));

    myclothesToClothesST->addAnimation(new QPropertyAnimation(digiClockMinuteHigh, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(digiClockMinuteHigh, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(digiClockMinuteHigh, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(digiClockMinuteHigh, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(digiClockMinuteHigh, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(digiClockMinuteHigh, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(digiClockMinuteHigh, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(digiClockMinuteHigh, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(digiClockMinuteHigh, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(digiClockMinuteHigh, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(digiClockMinuteHigh, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(digiClockMinuteHigh, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(digiClockMinuteHigh, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(digiClockMinuteHigh, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(digiClockMinuteHigh, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(digiClockMinuteHigh, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(digiClockMinuteHigh, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(digiClockMinuteHigh, "geometry"));

    myclothesToClothesST->addAnimation(new QPropertyAnimation(digiClockMinuteLow, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(digiClockMinuteLow, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(digiClockMinuteLow, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(digiClockMinuteLow, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(digiClockMinuteLow, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(digiClockMinuteLow, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(digiClockMinuteLow, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(digiClockMinuteLow, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(digiClockMinuteLow, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(digiClockMinuteLow, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(digiClockMinuteLow, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(digiClockMinuteLow, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(digiClockMinuteLow, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(digiClockMinuteLow, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(digiClockMinuteLow, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(digiClockMinuteLow, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(digiClockMinuteLow, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(digiClockMinuteLow, "geometry"));

    myclothesToClothesST->addAnimation(new QPropertyAnimation(digiClockSecondHigh, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(digiClockSecondHigh, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(digiClockSecondHigh, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(digiClockSecondHigh, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(digiClockSecondHigh, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(digiClockSecondHigh, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(digiClockSecondHigh, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(digiClockSecondHigh, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(digiClockSecondHigh, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(digiClockSecondHigh, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(digiClockSecondHigh, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(digiClockSecondHigh, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(digiClockSecondHigh, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(digiClockSecondHigh, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(digiClockSecondHigh, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(digiClockSecondHigh, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(digiClockSecondHigh, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(digiClockSecondHigh, "geometry"));

    myclothesToClothesST->addAnimation(new QPropertyAnimation(digiClockSecondLow, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(digiClockSecondLow, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(digiClockSecondLow, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(digiClockSecondLow, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(digiClockSecondLow, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(digiClockSecondLow, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(digiClockSecondLow, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(digiClockSecondLow, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(digiClockSecondLow, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(digiClockSecondLow, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(digiClockSecondLow, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(digiClockSecondLow, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(digiClockSecondLow, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(digiClockSecondLow, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(digiClockSecondLow, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(digiClockSecondLow, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(digiClockSecondLow, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(digiClockSecondLow, "geometry"));

    myclothesToClothesST->addAnimation(new QPropertyAnimation(digiClockPointsHigh, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(digiClockPointsHigh, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(digiClockPointsHigh, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(digiClockPointsHigh, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(digiClockPointsHigh, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(digiClockPointsHigh, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(digiClockPointsHigh, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(digiClockPointsHigh, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(digiClockPointsHigh, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(digiClockPointsHigh, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(digiClockPointsHigh, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(digiClockPointsHigh, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(digiClockPointsHigh, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(digiClockPointsHigh, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(digiClockPointsHigh, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(digiClockPointsHigh, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(digiClockPointsHigh, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(digiClockPointsHigh, "geometry"));

    myclothesToClothesST->addAnimation(new QPropertyAnimation(digiClockPointsLow, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(digiClockPointsLow, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(digiClockPointsLow, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(digiClockPointsLow, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(digiClockPointsLow, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(digiClockPointsLow, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(digiClockPointsLow, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(digiClockPointsLow, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(digiClockPointsLow, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(digiClockPointsLow, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(digiClockPointsLow, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(digiClockPointsLow, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(digiClockPointsLow, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(digiClockPointsLow, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(digiClockPointsLow, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(digiClockPointsLow, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(digiClockPointsLow, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(digiClockPointsLow, "geometry"));

    myclothesToClothesST->addAnimation(new QPropertyAnimation(digiClockTimeBkg, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(digiClockTimeBkg, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(digiClockTimeBkg, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(digiClockTimeBkg, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(digiClockTimeBkg, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(digiClockTimeBkg, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(digiClockTimeBkg, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(digiClockTimeBkg, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(digiClockTimeBkg, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(digiClockTimeBkg, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(digiClockTimeBkg, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(digiClockTimeBkg, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(digiClockTimeBkg, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(digiClockTimeBkg, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(digiClockTimeBkg, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(digiClockTimeBkg, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(digiClockTimeBkg, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(digiClockTimeBkg, "geometry"));

    myclothesToClothesST->addAnimation(new QPropertyAnimation(digiClockDateBkg, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(digiClockDateBkg, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(digiClockDateBkg, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(digiClockDateBkg, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(digiClockDateBkg, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(digiClockDateBkg, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(digiClockDateBkg, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(digiClockDateBkg, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(digiClockDateBkg, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(digiClockDateBkg, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(digiClockDateBkg, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(digiClockDateBkg, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(digiClockDateBkg, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(digiClockDateBkg, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(digiClockDateBkg, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(digiClockDateBkg, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(digiClockDateBkg, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(digiClockDateBkg, "geometry"));

    myclothesToClothesST->addAnimation(new QPropertyAnimation(digiClockDateBkgText, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(digiClockDateBkgText, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(digiClockDateBkgText, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(digiClockDateBkgText, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(digiClockDateBkgText, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(digiClockDateBkgText, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(digiClockDateBkgText, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(digiClockDateBkgText, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(digiClockDateBkgText, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(digiClockDateBkgText, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(digiClockDateBkgText, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(digiClockDateBkgText, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(digiClockDateBkgText, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(digiClockDateBkgText, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(digiClockDateBkgText, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(digiClockDateBkgText, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(digiClockDateBkgText, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(digiClockDateBkgText, "geometry"));

    myclothesToClothesST->addAnimation(new QPropertyAnimation(addButton, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(addButton, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(addButton, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(addButton, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(addButton, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(addButton, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(addButton, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(addButton, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(addButton, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(addButton, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(addButton, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(addButton, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(addButton, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(addButton, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(addButton, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(addButton, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(addButton, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(addButton, "geometry"));

    myclothesToClothesST->addAnimation(new QPropertyAnimation(delButton, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(delButton, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(delButton, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(delButton, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(delButton, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(delButton, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(delButton, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(delButton, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(delButton, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(delButton, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(delButton, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(delButton, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(delButton, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(delButton, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(delButton, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(delButton, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(delButton, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(delButton, "geometry"));

    myclothesToClothesST->addAnimation(new QPropertyAnimation(daydressDateEdit, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(daydressDateEdit, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(daydressDateEdit, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(daydressDateEdit, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(daydressDateEdit, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(daydressDateEdit, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(daydressDateEdit, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(daydressDateEdit, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(daydressDateEdit, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(daydressDateEdit, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(daydressDateEdit, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(daydressDateEdit, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(daydressDateEdit, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(daydressDateEdit, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(daydressDateEdit, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(daydressDateEdit, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(daydressDateEdit, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(daydressDateEdit, "geometry"));

    myclothesToClothesST->addAnimation(new QPropertyAnimation(weatherBackground, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(weatherBackground, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(weatherBackground, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(weatherBackground, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(weatherBackground, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(weatherBackground, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(weatherBackground, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(weatherBackground, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(weatherBackground, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(weatherBackground, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(weatherBackground, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(weatherBackground, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(weatherBackground, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(weatherBackground, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(weatherBackground, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(weatherBackground, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(weatherBackground, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(weatherBackground, "geometry"));

    myclothesToClothesST->addAnimation(new QPropertyAnimation(weatherImage, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(weatherImage, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(weatherImage, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(weatherImage, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(weatherImage, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(weatherImage, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(weatherImage, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(weatherImage, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(weatherImage, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(weatherImage, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(weatherImage, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(weatherImage, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(weatherImage, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(weatherImage, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(weatherImage, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(weatherImage, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(weatherImage, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(weatherImage, "geometry"));

    myclothesToClothesST->addAnimation(new QPropertyAnimation(weatherPlace, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(weatherPlace, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(weatherPlace, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(weatherPlace, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(weatherPlace, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(weatherPlace, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(weatherPlace, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(weatherPlace, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(weatherPlace, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(weatherPlace, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(weatherPlace, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(weatherPlace, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(weatherPlace, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(weatherPlace, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(weatherPlace, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(weatherPlace, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(weatherPlace, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(weatherPlace, "geometry"));

    myclothesToClothesST->addAnimation(new QPropertyAnimation(weatherTemp, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(weatherTemp, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(weatherTemp, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(weatherTemp, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(weatherTemp, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(weatherTemp, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(weatherTemp, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(weatherTemp, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(weatherTemp, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(weatherTemp, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(weatherTemp, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(weatherTemp, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(weatherTemp, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(weatherTemp, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(weatherTemp, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(weatherTemp, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(weatherTemp, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(weatherTemp, "geometry"));

    myclothesToClothesST->addAnimation(new QPropertyAnimation(weatherTitle, "geometry"));
    myclothesToFashionST->addAnimation(new QPropertyAnimation(weatherTitle, "geometry"));
    myclothesToDaydressST->addAnimation(new QPropertyAnimation(weatherTitle, "geometry"));
    myclothesToSettingST->addAnimation(new QPropertyAnimation(weatherTitle, "geometry"));
    fashionToClothesST->addAnimation(new QPropertyAnimation(weatherTitle, "geometry"));
    fashionToMyclothesST->addAnimation(new QPropertyAnimation(weatherTitle, "geometry"));
    fashionToDaydressST->addAnimation(new QPropertyAnimation(weatherTitle, "geometry"));
    fashionToSettingST->addAnimation(new QPropertyAnimation(weatherTitle, "geometry"));
    daydressToMyclothesST->addAnimation(new QPropertyAnimation(weatherTitle, "geometry"));
    daydressToFashionST->addAnimation(new QPropertyAnimation(weatherTitle, "geometry"));
    daydressToSettingST->addAnimation(new QPropertyAnimation(weatherTitle, "geometry"));
    settingToMyclothesST->addAnimation(new QPropertyAnimation(weatherTitle, "geometry"));
    settingToFashionST->addAnimation(new QPropertyAnimation(weatherTitle, "geometry"));
    settingToDaydressST->addAnimation(new QPropertyAnimation(weatherTitle, "geometry"));
    clothesToMyclothesST->addAnimation(new QPropertyAnimation(weatherTitle, "geometry"));
    clothesToFashionST->addAnimation(new QPropertyAnimation(weatherTitle, "geometry"));
    clothesToDaydressST->addAnimation(new QPropertyAnimation(weatherTitle, "geometry"));
    clothesToSettingST->addAnimation(new QPropertyAnimation(weatherTitle, "geometry"));
}
