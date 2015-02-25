#include "mydatabase.h"

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
    if (tables.contains("users", Qt::CaseInsensitive)
            && tables.contains("students", Qt::CaseInsensitive)
            && tables.contains("books", Qt::CaseInsensitive)
            && tables.contains("borrow", Qt::CaseInsensitive)
            && tables.contains("message", Qt::CaseInsensitive)
            )
    {
        //������������Ѵ��ڣ�����Ҫ�ٴδ���
        //qDebug("table exsited\n");
    }
    else
    {
        QSqlQuery query;
        //������¼����Ϣ(���,����,����)
        query.exec("create table users(usersid int primary key, name varchar, passwd varchar, role int)");
        //����ѧ����Ϣ��(���,����,����,����֤���,��ϵ��ʽ,����֤״̬,ѧ����Ƭ)
        query.exec("create table students(studentsid int primary key, name varchar, passwd varchar, stucode varchar, phone varchar, status int, pic varchar)");
        //����ͼ���(���,����,ͼ����,������,����,����,���ʱ��,��ǰ״̬)
        query.exec("create table books(booksid int primary key, name varchar, bookcode varchar, publish varchar, aurhor varchar, type varchar, storagedate varchar, status int)");
        //�������ı�(���,ͼ����,ѧ�����,��������,�黹����,ʵ�ʹ黹����)
        query.exec("create table borrow(borrowid int primary key, bookcode varchar, stucode varchar, borrowdate varchar, returndate varchar, realreturndate varchar)");
        //�������ѱ�(���,ͼ����,ѧ�����,�黹����)
        query.exec("create table message(messageid int primary key, bookcode varchar, stucode varchar, returndate varchar)");

        //�������Ա��ʼ�û���������
        query.exec("insert into users values(1,'ad','', 0)");
        query.exec("insert into users values(2,'us','', 1)");
    }
}

void mydatabase::closedb()
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

QString loginName;
