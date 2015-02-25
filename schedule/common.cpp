#include "common.h"


//�����ļ�
bool copyFileToPath(QString sourceDir, QString toDir, bool coverFileIfExist)
{
    toDir.replace("\\","/");
    if (sourceDir == toDir){
        return true;
    }
    if (!QFile::exists(sourceDir)){
        return false;
    }
    QDir *createfile = new QDir;
    bool exist = createfile->exists(toDir);
    if (exist){
        if(coverFileIfExist){
            createfile->remove(toDir);
        }
    }//end if

    if(!QFile::copy(sourceDir, toDir))
    {
        return false;
    }
    return true;
}

//�����ļ���
bool copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist)
{
    QDir sourceDir(fromDir);
    QDir targetDir(toDir);
    if(!targetDir.exists()){    // ���Ŀ��Ŀ¼�����ڣ�����д���
        if(!targetDir.mkdir(targetDir.absolutePath()))
            return false;
    }

    QFileInfoList fileInfoList = sourceDir.entryInfoList();
    foreach(QFileInfo fileInfo, fileInfoList){
        if(fileInfo.fileName() == "." || fileInfo.fileName() == "..")
            continue;

        if(fileInfo.isDir()){    // ��ΪĿ¼ʱ���ݹ�Ľ���copy
            if(!copyDirectoryFiles(fileInfo.filePath(),
                                   targetDir.filePath(fileInfo.fileName()),
                                   coverFileIfExist))
                return false;
        }
        else{            // �������ǲ���ʱ�������ļ�����ɾ������
            if(coverFileIfExist && targetDir.exists(fileInfo.fileName())){
                targetDir.remove(fileInfo.fileName());
            }

            // �����ļ�copy
            if(!QFile::copy(fileInfo.filePath(),
                            targetDir.filePath(fileInfo.fileName()))){
                return false;
            }
        }
    }
    return true;
}

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

//�������ڲ�
int datedef(QString dateStr, int rule)
{
    int expireFlag = false; //�Ƿ����

    int curYear = QDate::currentDate().toString("yyyy").toInt();
    int curMonth = QDate::currentDate().toString("MM").toInt();
    int curDay = QDate::currentDate().toString("dd").toInt();
    QString curWeek = QDate::currentDate().toString("ddd");
    int curWeekInt;

    QDate sqlDate = QDate::fromString(dateStr, "yyyy.MM.dd");
    int sqlYear = sqlDate.toString("yyyy").toInt();
    int sqlMonth = sqlDate.toString("MM").toInt();
    int sqlDay = sqlDate.toString("dd").toInt();
    QString sqlWeek = sqlDate.toString("ddd");
    int sqlWeekInt;

    int i;
    int day=0,dayt1=0,dayt2=0;
    int result;

    qDebug() << "curYear = " << curYear;
    qDebug() << "curMonth = " << curMonth;
    qDebug() << "curDay = " << curDay;
    qDebug() << "sqlYear = " << sqlYear;
    qDebug() << "sqlMonth = " << sqlMonth;
    qDebug() << "sqlDay = " << sqlDay;

    switch(rule)
    {
    case 0:        
        //0 ���ظ�
        if(curYear > sqlYear)
        {
            //���ظ�,������Ѿ�����
            swapNum(&curYear, &sqlYear);
            swapNum(&curMonth, &sqlMonth);
            swapNum(&curDay, &sqlDay);

            expireFlag = true;
        }
        else
        {
            //��û�й���
            if(curMonth > sqlMonth)
            {
                //�·ݹ���
                swapNum(&curMonth, &sqlMonth);
                swapNum(&curDay, &sqlDay);

                expireFlag = true;
            }
            else
            {
                //�·�û�й���
                if(curDay > sqlDay)
                {
                    //���ڹ���
                    swapNum(&curDay, &sqlDay);

                    expireFlag = true;
                }
            }
        }
        break;
    case 1:
        //1 �����ظ�
        curWeekInt = weekToInt(curWeek);
        sqlWeekInt = weekToInt(sqlWeek);
        if (curWeekInt > sqlWeekInt)
        {
            //���ڹ���
            result = sqlWeekInt+7-curWeekInt;
        }
        else
        {
            result = sqlWeekInt - curWeekInt;
        }
        qDebug() << "curWeekInt = " << curWeekInt;
        qDebug() << "sqlWeekInt = " << sqlWeekInt;
        qDebug() << "result = " << result;
        break;
    case 2:
        //2 �����ظ�
        sqlYear = curYear;
        if(curMonth > sqlMonth)
        {
            //�·ݹ���
            if(curDay > sqlDay)
            {
                //���ڹ���
                sqlMonth = curMonth+1;
            }
            else
            {
                //����û�й���
                sqlMonth = curMonth;
            }
        }
        else
        {
            //�·�û�й���
            if(curDay > sqlDay)
            {
                //���ڹ���
                sqlMonth = curMonth+1;
            }
            else
            {
                //����û�й���
                sqlMonth = curMonth;
            }
        }
        break;
    case 3:
        //3 �����ظ�
        if(curYear > sqlYear)
        {
            //���Ѿ�����
            sqlYear = curYear+1;
        }
        else
        {
            //��û�й���
            if(curMonth > sqlMonth)
            {
                //�·ݹ���
                sqlYear = curYear+1;
            }
            else
            {
                if(curDay > sqlDay)
                {
                    //���ڹ���
                    sqlYear = curYear+1;
                }
                else
                {
                }
            }
        }
        break;
    default:
        break;
    }

    int d[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
    for(i=curYear; i<sqlYear; i++)
        if(leap(i) == false)
            day += 365;
        else
            day += 366;

    for(i=1; i<curMonth; i++)
        dayt1 += d[leap(curYear)][i];
    dayt1 += curDay;

    for(i=1; i<sqlMonth; i++)
        dayt2 += d[leap(sqlYear)][i];
    dayt2 += sqlDay;


    if(rule == 1)
    {
        //����
    }
    else
    {
        result = day+dayt2-dayt1;
        if(expireFlag == true)
        {
            //���ڹ���
            result = 0-result;
        }
    }
    return result;
}
//�Ƿ�����
int leap(int year)
{
    if(year%400==0 ||(year%4==0&&year%100!=0))
        return true;
    else
        return false;
}

//������������
void swapNum(int *pre, int *next)
{
    int temp;
    temp = *pre;
    *pre = *next;
    *next = temp;
}

//����ת����
int weekToInt(QString weekStr)
{
    if(weekStr == QString("��һ"))
    {
        return 1;
    }
    else if(weekStr == QString("�ܶ�"))
    {
        return 2;
    }
    else if(weekStr == QString("����"))
    {
        return 3;
    }
    else if(weekStr == QString("����"))
    {
        return 4;
    }
    else if(weekStr == QString("����"))
    {
        return 5;
    }
    else if(weekStr == QString("����"))
    {
        return 6;
    }
    else if(weekStr == QString("����"))
    {
        return 7;
    }else
    {
        return 0;
    }

}

int itemDelButtonFlag;
QPoint windowsPos;
QString viewTitle;
