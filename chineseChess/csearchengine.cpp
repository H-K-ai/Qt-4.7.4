#include "csearchengine.h"

CSearchEngine::CSearchEngine()
{
}

CSearchEngine::~CSearchEngine()
{
    delete m_pMG;	//ɾ���������������ϵ��߷�������
    delete m_pEval;	//ɾ���������������ϵĹ�ֵ����
}

//���ݴ�����߷��ı�����
//move��Ҫ���е��߷�
int CSearchEngine::MakeMove(CHESSMOVE* move)
{
    int nChessID;
    //ȡĿ��λ�õ�����
    nChessID = CurPosition[move->To.y][move->To.x];
    //�������ƶ���Ŀ��λ����
    CurPosition[move->To.y][move->To.x] =
            CurPosition[move->From.y][move->From.x];
    //��ԭλ�����
    CurPosition[move->From.y][move->From.x] = NOCHESS;
    return nChessID;	//���ر��Ե�������
}

//����Ҫ������߷��ظ�����
//move��Ҫ�ָ����߷�
//nChessID��Ҫԭ������moveĿ��λ�õ���������
void CSearchEngine::UnMakeMove(CHESSMOVE *move,int nChessID)
{
    //��Ŀ��λ�ú����ӿ���ԭλ
    CurPosition[move->From.y][move->From.x] =
            CurPosition[move->To.y][move->To.x];
    //�ָ�Ŀ��λ�õ�����
    CurPosition[move->To.y][move->To.x] = nChessID;
}

//���Լ�����������Ϸ�Ƿ����
//���δ����,����0,���򷵻ؼ���/��Сֵ
int CSearchEngine::IsGameOver(int position[10][9],int nDepth)
{
    int i,j;
    bool RedLive = FALSE,BlackLive = FALSE;
    //���췽�Ź��Ƿ��н�˧
    for(i = 7;i < 10; i++)
    {
        for(j = 3; j < 6; j++)
        {
            if(position[i][j] == B_KING)
                BlackLive = TRUE;
            if(position[i][j] == R_KING)
                RedLive = TRUE;
        }
    }
    //���ڷ��Ź��Ƿ��н�˧
    for(i = 0; i < 3; i++)
    {
        for(j = 3; j < 6; j++)
        {
            if(position[i][j] == B_KING)
                BlackLive = TRUE;
            if(position[i][j] == R_KING)
                RedLive = TRUE;
        }
    }
    i = (m_nMaxDepth - nDepth + 1) % 2; //ȡ��ǰ����ż��־

    chessGameOver = 0;
    if(!RedLive)	//�콫������
    {
        chessGameOver = 1;
        if(i)
            return 19990 + nDepth;	//�����㷵�ؼ���ֵ
        else
            return - 19990 - nDepth;	//ż���㷵�ؼ�Сֵ
    }
    if(!BlackLive)
    {
        chessGameOver = 2;
        if(i)
            return - 19990 - nDepth;	//�����㷵�ؼ�Сֵ
        else
            return - 19990 + nDepth;	//ż���㷵�ؼ���ֵ
    }

    return 0;//����������,����0
}
