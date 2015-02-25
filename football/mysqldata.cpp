#include "mysqldata.h"

mysqldata::mysqldata()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

bool mysqldata::opendb(QString dbname)
{
    db.setDatabaseName(dbname);
    if(!db.open())
    {
        qDebug("db file open error");
        return false;
    }
    return true;
}

void mysqldata::createtable()
{
    QStringList tables = db.tables();
    if (tables.contains("person", Qt::CaseInsensitive)
            && tables.contains("info", Qt::CaseInsensitive)
            && tables.contains("score", Qt::CaseInsensitive)
            && tables.contains("account", Qt::CaseInsensitive)
            && tables.contains("game", Qt::CaseInsensitive)
            )
    {
        //������������Ѵ���,����Ҫ�ٴδ���
        //qDebug("table exsited\n");
    }
    else
    {
        QSqlQuery query;
        //������Ա��(���,����,����)
        query.exec("create table person(personid int primary key, name varchar, passwd varchar)");
        //������Ա��Ϣ��(���,����,���֤,����,סַ,����,�绰,н��,��Ƭ)
        query.exec("create table info(infoid int primary key, name varchar, idcard varchar, birthday datetime, address varchar, email varchar, phonenum varchar, price int, pic varchar)");
        //������Ա�ɼ���(���,����,��������,����ʱ��)
        query.exec("create table score(scoreid int primary key, name varchar, game varchar, scoretime datetime)");
        //�������ֲ���֧��(���,��Ŀ,����,֧��,����)
        query.exec("create table account(accountid int primary key, name varchar, come int, go int, curdate datetime)");
        //�������¹����(���,��Ŀ,����,�ص�,��������,Ԥ��֧��)
        query.exec("create table game(gameid int primary key, name varchar, gamedate datetime, address varchar, personnum int, price int)");

        //�������Ա��ʼ�û���������
        query.exec("insert into person values(1,'ad','')");
    }
}

void mysqldata::closedb()
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
