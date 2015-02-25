#ifndef CEVELUATION_H
#define CEVELUATION_H

#include "commfunc.h"

//����һ��궨��ÿ�����ӵĻ�����ֵ
//��100,ʿ250,��250,��500,��350,��350
//��˧ 10000
#define BASEVALUE_PAWN 100
#define BASEVALUE_BISHOP 250
#define BASEVALUE_ELEPHANT 250
#define BASEVALUE_CAR 500
#define BASEVALUE_HORSE 350
#define BASEVALUE_CANON 350
#define BASEVALUE_KING 10000

//����һ��궨��������ӵ������
//��ÿ��һ������λ����Ӧ���ϵķ�ֵ
//��15,ʿ1,��1,��6,��12,��6,��0
#define FLEXIBILITY_PAWN		15
#define FLEXIBILITY_BISHOP		1
#define FLEXIBILITY_ELEPHANT	1
#define FLEXIBILITY_CAR			6
#define FLEXIBILITY_HORSE		12
#define FLEXIBILITY_CANON		6
#define FLEXIBILITY_KING		0

//��ֵ����
class CEveluation
{
public:
    CEveluation();
    virtual ~CEveluation();
    //��ֵ����,�Դ�������̴��,BIsRedTurn �����ֵ�˭����
    virtual int Eveluate(int position[10][9], bool bIsRedTurn);

protected:
    //�о���ָ��λ�õ�������ص�����
    int GetRelatePiece(int position[10][9],int j,int i);
    //�ж�λ��From�������Ƿ����ߵ�λ��To
    bool CanTouch(int position[10][9],int nFromX,
                  int nFromY,int nToX,int nToY);
    //��һ��λ�ü������λ�õĶ���
    void AddPoint(int x,int y);
    int m_BaseValue[15];//������ӻ�����ֵ������
    int m_FlexValue[15];//�����������Է���������
    int m_AttackPos[10][9];//���ÿһ��λ�ñ���в����Ϣ
    int m_GuardPos[10][9];//���ÿһλ�ñ���������Ϣ
    int m_FlexibilityPos[10][9];//���ÿһ��λ���ϵ���������Է���
    int m_chessValue[10][9];//���ÿһλ���ϵ����ӵ��ܼ�ֵ
    int nPosCount;	//��¼һ���ӵ����λ�ø���
    QPoint RelatePos[20];	//��¼һ���������λ�õ�����
};

#endif // CEVELUATION_H
