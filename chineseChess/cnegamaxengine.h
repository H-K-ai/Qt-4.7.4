#ifndef CNEGAMAXENGINE_H
#define CNEGAMAXENGINE_H

#include "commfunc.h"
#include "CSearchEngine.h"

//��������. ʹ�ø�����ֵ���� ��CSearchEngine������
class CNegaMaxEngine : public CSearchEngine
{
public:
        CNegaMaxEngine();
        virtual ~CNegaMaxEngine();
        //�����ҳ������������һ���߷�
        virtual void SearchAGoodMove(int position[10][9]);

protected:
        int NegaMax(int depth);	//������ֵ��������
};

#endif // CNEGAMAXENGINE_H
