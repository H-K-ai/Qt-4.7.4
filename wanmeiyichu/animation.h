#ifndef STMATION_H
#define STMATION_H

#include "common.h"
#include "createbutton.h"
#include "otherobject.h"

extern QState *myclothesState;                   //�ҵ��³�
extern QState *fashionState;                     //������
extern QState *daydressStatue;                   //ÿ��װ��
extern QState *settingState;                     //��ҳ
extern QState *clothesState;                     //�ڶ��㰴ť

extern QStateMachine *stateMachine;              //״̬��

extern QSignalTransition *myclothesToClothesST;  //�ҵ��³����ڶ���ת������
extern QSignalTransition *myclothesToFashionST;  //�ҵ��³���������
extern QSignalTransition *myclothesToDaydressST; //�ҵ��³���ÿ��װ��
extern QSignalTransition *myclothesToSettingST;  //�ҵ��³�����ҳ

extern QSignalTransition *fashionToClothesST;    //�����䵽�ڶ���ת������
extern QSignalTransition *fashionToMyclothST;    //�����䵽�ҵ��³�
extern QSignalTransition *fashionToDaydressST;   //�����䵽ÿ��װ��
extern QSignalTransition *fashionToSettingST;    //�����䵽��ҳ

extern QSignalTransition *daydressToMyclothesST; //ÿ��װ�絽�ҵ��³�
extern QSignalTransition *daydressToFashionST;   //ÿ��װ�絽������
extern QSignalTransition *daydressToSettingST;   //ÿ��װ�絽��ҳ

extern QSignalTransition *settingToMyclothesST;  //��ҳ���ҵ��³�
extern QSignalTransition *settingToFashionST;    //��ҳ��������
extern QSignalTransition *settingToDaydressST;   //��ҳ��ÿ��װ��

extern QSignalTransition *clothesToMyclothesST;   //�ڶ���ת�����ҵ��³�����
extern QSignalTransition *clothesToFashionST;     //�ڶ���ת����������
extern QSignalTransition *clothesToDaydressST;    //�ڶ���ת����ÿ��װ��
extern QSignalTransition *clothesToSettingST;     //�ڶ���ת������ҳ

void createMainStateFunc();

void createMainSettingStateFunc();
void createMainMyclothesStateFunc();
void createMainFashionStateFunc();
void createMainDayDressStateFunc();
void createMainClothesStateFunc();
void createMainSignalTransitionFunc();
void createMainPropertyAnimationFunc();

#endif // STMATION_H
