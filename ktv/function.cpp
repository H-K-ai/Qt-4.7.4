#include "function.h"

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

mydatabase::mydatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

bool mydatabase::opendb(QString dbname)
{
    db.setDatabaseName(dbname);
    if(!db.open())
    {
        qDebug("db file open error");
        return false;
    }
    return true;
}

void mydatabase::createtable()
{
    QStringList tables = db.tables();
    if (tables.contains("person", Qt::CaseInsensitive)
            && tables.contains("member", Qt::CaseInsensitive)
            && tables.contains("songsLibrary", Qt::CaseInsensitive)
            && tables.contains("songsList", Qt::CaseInsensitive)
            && tables.contains("roomNum", Qt::CaseInsensitive)
            && tables.contains("roomStatus", Qt::CaseInsensitive)
            )
    {
        //������������Ѵ��ڣ�����Ҫ�ٴδ���
        //qDebug("table exsited\n");
    }
    else
    {
        QSqlQuery query;
        //������Ա��(���,����,����,��ɫ)   ��ɫ��0Ϊ����Ա,1Ϊ����Ա
        query.exec("create table person(personid int primary key, name varchar, passwd varchar, role int)");
        //������Ա��(���,��Ա��,��Ա���Ѷ��,ͼƬ·��)
        query.exec("create table member(memberid int primary key, name varchar, amount varchar)");
        //�����������(���,������,�ݳ���,�������,����·��)
        query.exec("create table songsLibrary(songsLibraryid int primary key, name varchar, artist varchar, selected int, path varchar)");
        //��������(���,������,�ݳ���,����·��)
        query.exec("create table songsList(songsListid int primary key, name varchar, artist varchar, path varchar)");
        //���������(���,״̬)
        query.exec("create table roomNum(roomNumid int primary key, status int)");
        //����״̬��(���,״̬) ״̬: δʹ�� ʹ�� Ԥ��
        query.exec("create table roomStatus(roomStatusid int primary key, status varchar)");

        //�������Ա��ʼ�û���������
        query.exec("insert into person values(1,'admin','admin',0)");
        query.exec("insert into person values(2,'ad','',0)");
        query.exec("insert into person values(3,'sv','',1)");

        query.exec("insert into roomStatus values(0, 'δʹ��')");
        query.exec("insert into roomStatus values(1, 'ʹ��')");
        query.exec("insert into roomStatus values(2, 'Ԥ��')");
    }
}

void mydatabase::closedb()
{
    db.close();
}

