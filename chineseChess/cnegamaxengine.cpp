#include "cnegamaxengine.h"

CNegaMaxEngine::CNegaMaxEngine()
{

}

CNegaMaxEngine::~CNegaMaxEngine()
{

}
//�˺���ָ��Դ����position�ҳ�һ������㷨
//���޸���������Ϊ�߹���״̬
void CNegaMaxEngine::SearchAGoodMove(int position[10][9])
{
    //�趨��������Ϊ m_nSearchDepth
    m_nMaxDepth = 2; //��������Ϊ2
    //����������̸��Ƶ���Ա����
    memcpy(CurPosition, position, 4*90);
    //���ø�����ֵ��������������߷�
    NegaMax(m_nMaxDepth);
    MakeMove(&m_cmBestMove);
    //���޸Ĺ������̸��Ƶ����������,����
    memcpy(position, CurPosition, 4*90);
}

//������ֵ��������
//depth��ʾ�ڵ���Ҷ�ӽڵ�Ĳ���
int CNegaMaxEngine::NegaMax(int depth)
{
    int current = -20000;
    int score;
    long Count,i;
    int type;
    i = IsGameOver(CurPosition, depth);	//�������Ƿ����
    if(i != 0)
        return i;	//��ֽ���,���ؼ���/��Сֵ
    if(depth <= 0)	//Ҷ�ӽڵ�ȡ��ֵ
        //���ع�ֵ
        return m_pEval->Eveluate(CurPosition, (m_nMaxDepth - depth) % 2);
    //�оٳ���ǰ������һ�����п��ܵ��߷�
    Count = m_pMG->CreatePossibleMove(CurPosition, depth, (m_nMaxDepth - depth) % 2);
    for(i = 0; i < Count; i++)
    {
        //�����߷������¾���
        type = MakeMove(&m_pMG->m_MoveList[depth][i]);
        //�ݹ���ø�����ֵ������һ��Ľڵ�
        score = -NegaMax(depth - 1);
        //�ָ���ǰ����
        UnMakeMove(&m_pMG->m_MoveList[depth][i],type);
        if(score > current)	//���score������֪�����ֵ
        {
            current = score;	//�޸ĵ�ǰ���ֵΪscore;
            if(depth == m_nMaxDepth)
            {
                //��������ʱ��������߷�
                m_cmBestMove = m_pMG->m_MoveList[depth][i];
            }
        }
    }
    return current;	//���ؼ���ֵ
}
