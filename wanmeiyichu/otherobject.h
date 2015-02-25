#ifndef OTHEROBJECT_H
#define OTHEROBJECT_H

#include "common.h"
#include "drawcontrols.h"

#define DIGICLOCKTIMEX 330                   //�ӱ�ʱ����ʼXλ��
#define DIGICLOCKTIMEY 125                   //�ӱ�ʱ����ʼYλ��
#define DIGICLOCKPOINTY 140                  //�ӱ��λ����ʼYλ��
#define DIGICLOCKTIMEWIDTH 9                 //�ӱ�ʱ����1
#define DIGICLOCKTIMEWIDTHER 52              //�ӱ�ʱ����2
#define DIGICLOCKTIMEHEIGHT 48               //�ӱ�ʱ��߶�1
#define DIGICLOCKTIMEHEIGHTER 79             //�ӱ�ʱ��߶�2
#define DIGICLOCKTIMESPACE 5                 //�ӱ�ʱ��������
#define DIGICLOCKTIMEBKGX 300                //�ӱ�ʱ�䱳����ʼXλ��
#define DIGICLOCKTIMEBKGY 175                //�ӱ�ʱ�䱳����ʼYλ��
#define DIGICLOCKTIMEBKGWIDTH 420            //�ӱ�ʱ�䱳�����
#define DIGICLOCKTIMEBKGHEIGHT 34            //�ӱ�ʱ�䱳���߶�
#define DIGICLOCKDATEBKGX 375                //�ӱ����ڱ�����ʼXλ��
#define DIGICLOCKDATEBKGY 210                //�ӱ����ڱ�����ʼYλ��
#define DIGICLOCKDATEBKGWIDTH 270            //�ӱ����ڱ������
#define DIGICLOCKDATEBKGHEIGHT 35            //�ӱ����ڱ����߶�

extern imageButton *digiClockHourHigh;       //�ӱ�Сʱ��λ
extern imageButton *digiClockHourLow;        //�ӱ�Сʱ��λ
extern imageButton *digiClockMinuteHigh;     //�ӱ���Ӹ�λ
extern imageButton *digiClockMinuteLow;      //�ӱ���ӵ�λ
extern imageButton *digiClockSecondHigh;     //�ӱ�������λ
extern imageButton *digiClockSecondLow;      //�ӱ�������λ
extern imageButton *digiClockPointsHigh;     //�ӱ��λ���λ
extern imageButton *digiClockPointsLow;      //�ӱ��λ���λ
extern imageButton *digiClockTimeBkg;        //�ӱ�ʱ�䱳��
extern imageButton *digiClockDateBkg;        //�ӱ����ڱ���
extern QLabel *digiClockDateBkgText;         //�ӱ����ڱ�������


#define WEATHERBACKGROUNDX 300               //����Ԥ��������ʼXλ��
#define WEATHERBACKGROUNDY 305               //����Ԥ��������ʼYλ��
#define WEATHERBACKGROUNDWIDTH 420           //����Ԥ���������
#define WEATHERBACKGROUNDHEIGHT 220          //����Ԥ�������߶�
#define WEATHERPLACEX 300                    //����Ԥ���ص���ʼXλ��
#define WEATHERPLACEY 305                    //����Ԥ���ص���ʼYλ��
#define WEATHERPLACEWIDTH 240                //����Ԥ���ص���
#define WEATHERPLACEHEIGHT 125               //����Ԥ���ص�߶�
#define WEATHERTEMPX 300                     //����Ԥ���¶���ʼXλ��
#define WEATHERTEMPY 450                     //����Ԥ���¶���ʼYλ��
#define WEATHERTEMPWIDTH 240                 //����Ԥ���¶ȿ��
#define WEATHERTEMPHEIGHT 75                 //����Ԥ���¶ȸ߶�
#define WEATHERIMAGEX 540                    //����Ԥ��ͼ����ʼXλ��
#define WEATHERIMAGEY 305                    //����Ԥ��ͼ����ʼYλ��
#define WEATHERIMAGEWIDTH 180                //����Ԥ��ͼ����
#define WEATHERIMAGEHEIGHT 160               //����Ԥ��ͼ��߶�
#define WEATHERTITLEX 540                    //����Ԥ��������ʼXλ��
#define WEATHERTITLEY 460                    //����Ԥ��������ʼYλ��
#define WEATHERTITLEWIDTH 180                //����Ԥ���������
#define WEATHERTITLEHEIGHT 65                //����Ԥ�������߶�
extern imageButton *weatherBackground;       //����Ԥ������
extern imageButton *weatherImage;            //����ͼ�갴ť
extern QLabel *weatherPlace;                 //����Ԥ���ص�
extern QLabel *weatherTemp;                  //����Ԥ���¶�
extern QLabel *weatherTitle;                 //����Ԥ������


#define CLOTHESLISTWIDGETX 295               //�·�ͼƬ�б���ʼXλ��
#define CLOTHESLISTWIDGETY 15                //�·�ͼƬ�б���ʼYλ��
#define CLOTHESLISTWIDGETWIDTH 490           //�·�ͼƬ�б���
#define CLOTHESLISTWIDGETHEIGHT 470          //�·�ͼƬ�б�߶�
#define CLOTHESLISTWIDGETCOLUMNNUM 2         //�·�ͼƬ�б�����
#define CLOTHESLISTWIDGETCOLUMNWIDTH 227     //�·�ͼƬ�б���(490-36)/2-1
#define CLOTHESLISTWIDGETCOLUMNHEIGHT 297    //�·�ͼƬ�б�߶�
#define CLOTHESLISTWIDGETPICWIDTH 220        //����ͼƬ���227-2*3-1
#define CLOTHESLISTWIDGETPICHEIGHT 291       //����ͼƬ�߶�297-2*3
#define CLOTHESLISTWIDGETITEMLEFT 0          //�·��б����
#define CLOTHESLISTWIDGETITEMRIGHT 1         //�·��б��Ҳ�
extern QTableWidget *clothesListWidget;      //�·�ͼƬ�б�

#define DAYDRESSDATEEDITX 295                //ÿ��װ�����ڱ༭����ʼXλ��
#define DAYDRESSDATEEDITY 15                 //ÿ��װ�����ڱ༭����ʼYλ��
#define DAYDRESSDATEEDITWIDTH 220            //ÿ��װ�����ڱ༭����
#define DAYDRESSDATEEDITHEIGHT 40            //ÿ��װ�����ڱ༭��߶�
extern QDateEdit *daydressDateEdit;          //ÿ��װ�����ڱ༭��

#define DAYDRESSLISTWIDGETX 295              //ÿ��װ��ͼƬ�б���ʼXλ��
#define DAYDRESSLISTWIDGETY 65               //ÿ��װ��ͼƬ�б���ʼYλ��
#define DAYDRESSLISTWIDGETWIDTH 490          //ÿ��װ��ͼƬ�б���
#define DAYDRESSLISTWIDGETHEIGHT 420         //ÿ��װ��ͼƬ�б�߶�
#define DAYDRESSLISTWIDGETCOLUMNNUM 6        //ÿ��װ��ͼƬ�б�����
#define DAYDRESSLISTWIDGETCOLUMNWIDTH 75     //ÿ��װ��ͼƬ�б���(490-36)/6-1
#define DAYDRESSLISTWIDGETCOLUMNHEIGHT 97    //ÿ��װ��ͼƬ�б�߶�
#define DAYDRESSLISTWIDGETPICWIDTH 70        //����ͼƬ���75-2*2-1
#define DAYDRESSLISTWIDGETPICHEIGHT 93       //����ͼƬ�߶�97-2*2
#define DAYDRESSLISTWIDGETITEMNOSELECT -1    //ÿ��װ���б�δѡ������
#define DAYDRESSLISTWIDGETITEMUPCLOTHESONE 0 //ÿ��װ���б���װһ����
#define DAYDRESSLISTWIDGETITEMUPCLOTHESTWO 1 //ÿ��װ���б���װ������
#define DAYDRESSLISTWIDGETITEMDOWNCLOTHES 2  //ÿ��װ���б���װ����
#define DAYDRESSLISTWIDGETITEMBAG 3          //ÿ��װ���б��������
#define DAYDRESSLISTWIDGETITEMSHOE 4         //ÿ��װ���б�Ьñ����
#define DAYDRESSLISTWIDGETITEMDECO 5         //ÿ��װ���б���Ʒ����
extern QTableWidget *daydressListWidget;     //ÿ��װ��ͼƬ�б�

void createMainOtherObjectFunc(QWidget *parent);

#define NAMELINEEDITX 148                    //���Ʊ༭����ʼXλ��145+3
#define NAMELINEEDITY 18                     //���Ʊ༭����ʼYλ��
#define NAMELINEEDITWIDTH 300                //���Ʊ༭����
#define NAMELINEEDITHEIGHT 38                //���Ʊ༭��߶�
#define NAMELINEEDITSPACE 15                 //���Ʊ༭��������
#define NOTETEXTEDITWIDTH 630                //��ע�ı�����
#define NOTETEXTEDITHEIGHT 88                //��ע�ı���߶�

extern int selectClothesIdNumInt;            //ѡ�е�������
extern int selectDaydressIdNumInt;           //ѡ�е�ÿ��װ���·����
extern int daydressColSelectInt;             //ÿ��װ�����ѡ���к�
extern QLineEdit *nameLineEdit;              //���Ʊ༭��
extern noMoveComboBox *typeComboBox;         //������Ͽ�
extern noMoveComboBox *seasonComboBox;       //������Ͽ�
extern noMoveComboBox *classtypeComboBox;    //������Ͽ�
extern QLineEdit *brandLineEdit;             //Ʒ�Ʊ༭��
extern QLineEdit *priceLineEdit;             //�۸�༭��
extern QDateEdit *timeDateEdit;              //ʱ��༭��
extern QLineEdit *storePlaceLineEdit;        //��ŵر༭��
extern QLineEdit *buyPlaceLineEdit;          //����ر༭��
extern QTextEdit *noteTextEdit;              //��ע�ı���
extern QString clothesPicPathString;         //ͼƬ;��

void createClothesOtherObjectFunc(QWidget *parent);

#define FILTERLISTWIDGETX 15                 //ɸѡ�����б���ʼXλ��
#define FILTERLISTWIDGETY 60                 //ɸѡ�����б���ʼYλ��
#define FILTERLISTWIDGETWIDTH 770            //ɸѡ�����б���
#define FILTERLISTWIDGETHEIGHT 525           //ɸѡ�����б�߶�
#define FILTERLISTWIDGETCOLUMNNUM 3          //ɸѡ�����б�����
#define FILTERLISTWIDGETCOLUMNWIDTH 244      //ɸѡ�����б���(770-36)/3-1
#define FILTERLISTWIDGETCOLUMNHEIGHT 325     //ɸѡ�����б�߶�
#define FILTERLISTWIDGETPICWIDTH 237         //����ͼƬ���244-2*3-1
#define FILTERLISTWIDGETPICHEIGHT 319        //����ͼƬ�߶�325-2*3
#define FILTERLISTWIDGETITEMONE 0            //�·��б��һ��
#define FILTERLISTWIDGETITEMTWO 1            //�·��б�ڶ���
#define FILTERLISTWIDGETITEMTHREE 2          //�·��б�ڶ���
extern QTableWidget *filterListWidget;       //ÿ��װ��ɸѡ�����б�
void createFilterOtherObjectFunc(QWidget *parent);

#endif // OTHEROBJECT_H
