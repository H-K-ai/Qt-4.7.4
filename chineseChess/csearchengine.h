#ifndef CSEARCHENGINE_H
#define CSEARCHENGINE_H

#include "commfunc.h"
#include "CMoveGenerator.h"
#include "CEveluation.h"

//��������Ļ��� .����ӿڼ���������.
class CSearchEngine
{
public:
        CSearchEngine();
        virtual ~CSearchEngine();
        //���Ľӿ�,Ϊ��ǰ�����߳���һ����
        virtual void SearchAGoodMove(int position[10][9])=0;
        //�趨����������
        virtual void SetSearchDepth(int nDepth){m_nSearchDepth = nDepth;};
        //��ƹ�ֵ����
        virtual void SetEveluator(CEveluation *pEval){m_pEval = pEval;};
        //�趨�߷�������
        virtual void SetMoveGenerator(CMoveGenerator *pMG){m_pMG = pMG;};

protected:
        //����ĳһ�߷����������Ժ������
        virtual int MakeMove(CHESSMOVE* move);
        //�ָ�ĳһ�߷�����������Ϊ�߹�֮ǰ��
        virtual void UnMakeMove(CHESSMOVE* move,int type);
        //�����жϵ�ǰ�����Ƿ��Ѿ��ֳ�ʤ��
        virtual int IsGameOver(int position[10][9], int nDepth);
        //�������ڵ�ǰ�ڵ�����״̬������
        int CurPosition[10][9];
        //��¼����߷��ı���
        CHESSMOVE m_cmBestMove;
        //�߷�������ָ��
        CMoveGenerator *m_pMG;
        //��ֵ����ָ��
        CEveluation *m_pEval;
        //����������
        int m_nSearchDepth;
        //��ǰ����������������
        int m_nMaxDepth;

};

#endif // CSEARCHENGINE_H
