#ifndef CMOVEGENERATOR_H
#define CMOVEGENERATOR_H

#include "commfunc.h"

//�߷�������
class CMoveGenerator
{
public:
        CMoveGenerator();
        virtual ~CMoveGenerator();
        //���Լ��һ���߷��Ƿ�Ϸ��ľ�̬����
        static bool IsValidMove(int position[10][9],int nFromX,
                                                        int nFromY,int nToX,int nToY);
        //�������������ϵ����кϷ����߷�
        int CreatePossibleMove(int position[10][9],int nPly,int nSide);
        //���CreatePossibleMove ���������߷��Ķ���
        CHESSMOVE m_MoveList[8][80];

protected:
        //��m_MoveList�в���һ���߷�
        int AddMove(int nFromX,int nToX,int nFromY,int nToY,int nPly);
        //�������������ϵĸ���λ���ϵĽ�/˧���߷�
        void Gen_KingMove(int position[10][9],int i,int j,int nPly);
        //�������������ϵĸ���λ���ϵĺ��˵��߷�
        void Gen_RBishopMove(int position[10][9],int i,int j,int nPly);
        //�������������ϵĸ���λ���ϵĺ�ʿ���߷�
        void Gen_BBishopMove(int position[10][9],int i,int j,int nPly);
        //�������������ϵĸ���λ���ϵ���/����߷�
        void Gen_ElephantMove(int position[10][9],int i,int j,int nPly);
        //�������������ϵĸ���λ���ϵ�����߷�
        void Gen_HorseMove(int position[10][9],int i,int j,int nPly);
        //�������������ϵĸ���λ���ϵĳ����߷�
        void Gen_CarMove(int position[10][9],int i,int j,int nPly);
        //�������������ϵĸ���λ���ϵĺ�����߷�
        void Gen_RPawnMove(int position[10][9],int i,int j,int nPly);
        //�������������ϵĸ���λ���ϵĺڱ����߷�
        void Gen_BPawnMove(int position[10][9],int i,int j,int nPly);
        //�������������ϵĸ���λ���ϵ��ڵ��߷�
        void Gen_CanonMove(int position[10][9],int i,int j,int nPly);

        int m_nMoveCount;	//��¼m_MoveList���߷�������

};

#endif // CMOVEGENERATOR_H
