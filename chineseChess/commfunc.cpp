#include "commfunc.h"

int chessGameOver;

//�����ļ���
bool createFolder(const QString dir)
{
    QDir *temp = new QDir;
    bool exist = temp->exists(dir);
    if(exist)
        qDebug() << "�ļ����Ѵ���" << endl;
    else
    {
        bool ok = temp->mkdir(dir);
        if(ok)
            qDebug() << "�ļ��д����ɹ�" << endl;
    }

    return true;
}

void chessmanDataFromFile(QString fileData, int chessmanData[10][9])
{
    qDebug() << fileData << fileData.size() << endl;
    int i = 0;
    int j = 0;

    for(i=0; i<10; i++)
        for(j=0; j<9; j++)
        {
            chessmanData[i][j] = fileData.at(9*i+j).unicode()-NUMTOUNICODE;
            qDebug() << i << j << 9*i+j << endl;
        }
}

QString chessmanDataToFile(const int chessmanData[10][9])
{
    int i = 0;
    int j = 0;
    QString fileData = "";

    for(i=0; i<10; i++)
        for(j=0; j<9; j++)
            fileData += QString(QChar(chessmanData[i][j]+NUMTOUNICODE));

    qDebug() << fileData.size() << endl;
    return fileData;
}

void gameIsOver(int position[10][9])
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

    chessGameOver = 0;
    if(!RedLive)	//�콫������
    {
        chessGameOver = 1;
    }
    if(!BlackLive)
    {
        chessGameOver = 2;
    }
}

