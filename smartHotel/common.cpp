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
    if(!targetDir.exists()){    // ���Ŀ��Ŀ¼������, ����д���
        if(!targetDir.mkdir(targetDir.absolutePath()))
            return false;
    }

    QFileInfoList fileInfoList = sourceDir.entryInfoList();
    foreach(QFileInfo fileInfo, fileInfoList){
        if(fileInfo.fileName() == "." || fileInfo.fileName() == "..")
            continue;

        if(fileInfo.isDir()){    // ��ΪĿ¼ʱ, �ݹ�Ľ���copy
            if(!copyDirectoryFiles(fileInfo.filePath(),
                                   targetDir.filePath(fileInfo.fileName()),
                                   coverFileIfExist))
                return false;
        }
        else{            // �������ǲ���ʱ, �����ļ�����ɾ������
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
    if (tables.contains("users", Qt::CaseInsensitive)
            && tables.contains("guests", Qt::CaseInsensitive)
            && tables.contains("rooms", Qt::CaseInsensitive)
            && tables.contains("orders", Qt::CaseInsensitive)
            && tables.contains("lightauto", Qt::CaseInsensitive)
            )
    {
        //������������Ѵ���,����Ҫ�ٴδ���
        //qDebug("table exsited\n");
    }
    else
    {
        QSqlQuery query;
        //������Ա��(���, ����, ����, Ȩ��)
        query.exec("create table users(usersid int primary key, name varchar, passwd varchar, role int)");
        //�����ͻ���Ϣ��(���, ����, �Ա�, ����, ���֤��, �ֻ���, ��Ա)
        query.exec("create table guests(guestsid int primary key, name varchar, sex int, age int, idcard varchar, phone varchar, member int)");
        //����������Ϣ��(���, �����, ��������, ����, ��Ա��)
        query.exec("create table rooms(roomsid int primary key, number varchar, type int, price int, mprice varchar)");
        //��������Ԥ����(���, �ͻ�����, �����, Ԥ��ʱ��, �˷�ʱ��)
        query.exec("create table orders(ordersid int primary key, name varchar, number varchar, pre datetime, next datetime)");
        //���������Զ���(���, �Ʊ��, ��ʼʱ��, ����ʱ��, �Ƿ��Զ�)
        query.exec("create table lightauto(lightautoid int primary key, lightid int, pre varchar, next varchar, autoflag int)");

        //�������Ա��ʼ�û���������
        query.exec("insert into users values(1, 'ad', '', 0)");
        query.exec("insert into users values(2, 'us', '', 1)");

        //��������Զ���
        query.exec("insert into lightauto values(1, 1, '20:00:00', '23:30:00', 0)");
        query.exec("insert into lightauto values(2, 2, '20:00:00', '23:30:00', 0)");
        query.exec("insert into lightauto values(3, 3, '20:00:00', '23:30:00', 0)");
    }
}

void database::closedb()
{
    db.close();
}


QString loginName;

