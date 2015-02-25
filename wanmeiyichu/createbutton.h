#ifndef CREATEBUTTON_H
#define CREATEBUTTON_H

#include "common.h"
#include "drawcontrols.h"

#define NOBUTTONLEFTX -500                //��ť�����������ʼXλ��
#define NOBUTTONLEFTY 15                  //��ť�����������ʼYλ��
#define NOBUTTONRIGHTX 1300               //��ť�������Ҳ����ʼYλ��
#define NOBUTTONRIGHTY 15                 //��ť�������Ҳ���ʼYλ��
#define NOBUTTONTOPX 295                  //��ť�������ϲ���ʼXλ��
#define NOBUTTONTOPY -500                 //��ť�������ϲ���ʼYλ��
#define NOBUTTONBOTTOMX 295               //��ť�������²����ʼYλ��
#define NOBUTTONBOTTOMY 1300              //��ť�������²���ʼYλ��

#define MAINBUTTONX 130                   //�����湦�ܰ�ť��ʼXλ��
#define MAINBUTTONY 15                    //�����湦�ܰ�ť��ʼYλ��
#define MAINBUTTONWIDTH 135               //�����湦�ܰ�ť���
#define MAINBUTTONHEIGHT 135              //�����湦�ܰ�ť�߶�
#define MAINBUTTONSPACE 10                //�����湦�ܰ�ť���

#define MYCLOTHESBUTTONXX 295              //�ҵ��³���ť��ʼXλ��
#define MYCLOTHESBUTTONXY 15               //�ҵ��³���ť��ʼYλ��
#define MYCLOTHESBUTTONXWIDTH 240          //�ҵ��³���ť���
#define MYCLOTHESBUTTONXHEIGHT 150         //�ҵ��³���ť�߶�1
#define MYCLOTHESBUTTONXHEIGHTER 250       //�ҵ��³���ť�߶�2
#define MYCLOTHESBUTTONXSPACE 10           //�ҵ��³���ť���

#define FASHIONBUTTONX 295                 //�����䰴ť��ʼXλ��
#define FASHIONBUTTONY 15                  //�����䰴ť��ʼYλ��
#define FASHIONBUTTONWIDTH 240             //�����䰴ť���
#define FASHIONBUTTONHEIGHT 106            //�����䰴ť�߶�1
#define FASHIONBUTTONHEIGHTER 135          //�����䰴ť�߶�2
#define FASHIONBUTTONSPACE 10              //�����䰴ť���

#define NOBUTTONPRESSED -1                 //û�а�ť����

#define MYCLOTHESPRESSED 0                 //�ҵ��³���ť����
#define FASHIONPRESSED 1                   //�ҵĴ��䰴ť����
#define DAYDRESSPRESSED 2                  //ÿ��װ�簴ť����
#define SETTINGPRESSED 3                   //��ҳ��ť����

#define CLOTHESBUTTONPRESSED 0             //�·���ť����
#define BAGBUTTONRESSED 1                  //������ť����
#define SHOEBUTTONRESSED 2                 //Ьñ��ť����
#define DECOBUTTONRESSED 3                 //��Ʒ��ť����
#define COSBUTTONRESSED 4                  //��ױƷ��ť����
#define LABELBUTTONRESSED 5                //������ť����

#define SPRINGBUTTONRESSED 0               //������ť����
#define SUMMERBUTTONRESSED 1               //�ļ���ť����
#define AUTUMNBUTTONRESSED 2               //�＾��ť����
#define WINTERBUTTONRESSED 3               //������ť����

#define WORKPLACEBUTTONRESSED 0            //ְ����ť����
#define BANQUETBUTTONRESSED 1              //��ᰴť����
#define LEISUREBUTTONRESSED 2              //���а�ť����
#define SPORTBUTTONRESSED 3                //�˶���ť����
#define OTHERBUTTONRESSED 4                //������ť����

#define LISTWIDGETNOSELECT -1              //�б�û��ѡ��

#define ADDDELBUTTONX 295                  //���ɾ����ť��ʼXλ��
#define ADDDELBUTTONY 495                  //���ɾ����ť��ʼXλ��
#define ADDDELBUTTONWIDTH 240              //���ɾ����ť���
#define ADDDELBUTTONHEIGHT 90              //���ɾ����ť�߶�
#define ADDDELBUTTONSPACE 10               //���ɾ����ť���

#define CLOSEBUTTONX 749                   //�رհ�ť��ʼXλ��
#define CLOSEBUTTONY 15                    //�رհ�ť��ʼYλ��
#define CLOSEBUTTONWIDTH 36                //�رհ�ť���
#define CLOSEBUTTONHEIGHT 36               //�رհ�ť�߶�

extern imageButton *myclothesButton;       //�ҵ��³�
extern imageButton *fashionButton;         //������
extern imageButton *daydressButton;        //ÿ��װ��
extern imageButton *settingButton;         //��ҳ

extern imageButton *clothesButton;         //�·�
extern imageButton *bagButton;             //����
extern imageButton *shoeButton;            //Ьñ
extern imageButton *decoButton;            //��Ʒ
extern imageButton *cosButton;             //��ױƷ
extern imageButton *labelButton;           //����

extern imageButton *springButton;          //����
extern imageButton *summerButton;          //�ļ�
extern imageButton *autumnButton;          //�＾
extern imageButton *winterButton;          //����
extern imageButton *workplaceButton;       //ְ��
extern imageButton *banquetButton;         //���
extern imageButton *leisureButton;         //����
extern imageButton *sportButton;           //�˶�
extern imageButton *otherButton;           //����

extern buttonsClicked *secondLayerButton;  //�ڶ��㰴ť���

extern imageButton *addButton;             //��Ӱ�ť
extern imageButton *delButton;             //ɾ����ť

extern int mainPressed;                    //�����水ťѡ��
extern int typePressed;                    //����ѡ��
extern int seasonPressed;                  //����ѡ��
extern int classtypePressed;               //����ѡ��
extern int addPressed;                     //��Ӱ�ťѡ��

extern imageButton *closeButton;           //������رհ�ť

void createMainButtonFunc(QWidget *parent);

#define PICBUTTONX 485                     //ͼƬ��ť��ʼXλ��
#define PICBUTTONY 15                      //ͼƬ��ť��ʼYλ��
#define PICBUTTONWIDTH 300                 //ͼƬ��ť���
#define PICBUTTONHEIGHT 400                //ͼƬ��ť�߶�

#define MODIFYBUTTONX 497                  //�޸İ�ť��ʼXλ��
#define MODIFYBUTTONY 430                  //�޸İ�ť��ʼYλ��
#define MODIFYBUTTONWIDTH 133              //�޸İ�ť���
#define MODIFYBUTTONHEIGHT 50              //�޸İ�ť�߶�
#define MODIFYBUTTONSPACE 10               //�޸İ�ť�������

extern imageButton *picButton;             //ͼƬ��ť
extern imageButton *modifyButton;          //�޸İ�ť
extern imageButton *cancelButton;          //ȡ����ť

void createClothesButtonFunc(QWidget *parent);

#define EXITBUTTONX 749                    //�رհ�ť��ʼXλ��
#define EXITBUTTONY 15                     //�رհ�ť��ʼXλ��
#define EXITBUTTONWIDTH 36                 //�رհ�ť���
#define EXITBUTTONHEIGHT 36                //�رհ�ť�߶�
extern imageButton *exitButton;            //�رհ�ť
void createFilterButtonFunc(QWidget *parent);

#endif // CREATEBUTTON_H
