#include "database.h"

database::database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

bool database::opendb(QString dbname)
{
    db.setDatabaseName(dbname);
    if(!db.open())
    {
        qDebug("db file open error");
        return false;
    }
    return true;
}

void database::createtable()
{
    QStringList tables = db.tables();
    if (tables.contains("filepathTb", Qt::CaseInsensitive)
            && tables.contains("timeTb", Qt::CaseInsensitive)
            && tables.contains("unitTb", Qt::CaseInsensitive)
            )
    {
        //������������Ѵ��ڣ�����Ҫ�ٴδ���
        //qDebug("table exsited\n");
    }
    else
    {
        QSqlQuery query;
        //�����ļ�����Ϣ��(���,��λ�ļ���,�����ļ���)
        query.exec("create table filepathTb(filepathTbid int primary key, filepathcom varchar, filepathsum varchar)");
        //����ͳ��ʱ���(���,ʱ��1,ʱ��2,�Զ���ȡ)
        query.exec("create table timeTb(timeTbid int primary key, timepre timedate, timenext timedate, role int)");
        //������λ��Ϣ��(���,����)
        query.exec("create table unitTb(unitTbid int primary key, name varchar)");

        //�������Ա��ʼ����
        query.exec("insert into filepathTb values(1,'','')");
        query.exec("insert into timeTb values(1,'17:00:00','18:00:00', 2)");

        query.exec("insert into unitTb values(1,'����')");
        query.exec("insert into unitTb values(2,'����')");
        query.exec("insert into unitTb values(3,'��б')");
        query.exec("insert into unitTb values(4,'�����')");
        query.exec("insert into unitTb values(5,'Ȩú��˾')");
        query.exec("insert into unitTb values(6,'����úҵ')");
        query.exec("insert into unitTb values(7,'������˾')");
        query.exec("insert into unitTb values(8,'��������')");
    }
}

void database::closedb()
{
    db.close();
}

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
