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
        qDebug("db file open error!");
        return false;
    }
    return true;
}

void mydatabase::createtable()
{
    QStringList tables = db.tables();
    if (tables.contains("person", Qt::CaseInsensitive)
            &&tables.contains("place", Qt::CaseInsensitive)
            &&tables.contains("hotel", Qt::CaseInsensitive))
    {
        //������������Ѵ���,����Ҫ�ٴδ���
        qDebug("table exsited!");
    }
    else
    {
        QSqlQuery query;
#if 0
        �ɹ��������ɹ�������� ������������ ��������� ��Ӧ�̱�ţ�
        �ɹ�������Ʒ��ϸ����Ʒ��� �ɹ�������� ��Ʒ���� ��Ʒ���ۣ�
        �ɹ���ͬ���ɹ���ͬ�� ��ͬ�������� ��ͬ����� ��
        �ɹ���ͬ��Ʒ��ϸ���ɹ���ͬ�� ��Ʒ��� ��Ʒ���� ��Ʒ���ۣ�
        ��Ʒ��Ϣ����Ʒ��� ��Ʒ���� ��Ʒ���� ��Ʒ���
        ��Ӧ����Ϣ����Ӧ�̱�� ��Ӧ������ ��
        �ջ������ջ������ �Ƶ����� �Ƶ������ �ջ���ϸ��
        �ջ���Ʒ��ϸ���ջ������ ��Ʒ��� ��Ʒ������
        �ɹ������������ �Ƶ����� �����  ������ ������ �����˺ţ�

#endif
        //������Ա��(���,����,����)
        query.exec("create table person(personid int primary key, name varchar, passwd varchar)");
        //�����ͻ���(���,����,�绰,��ַ,����,��ע)
        query.exec("create table client(clientid int primary key, name varchar, phone varchar, address varchar, email varchar, note varchar)");
        //����������(���,�������,���������,��Ӧ�̱��,��Ʒ���,��Ʒ����,��Ʒ����,��������,����״̬)
        query.exec("create table orderform(orderformid int primary key, orderformcode varchar, name varchar, officecode varchar, goodscode varchar, goodsnum varchar, goodsprice varchar, orderdata varchar, status int)");
        //������Ʒ��(���,��Ʒ����,��Ʒ����,��Ʒ���,��Ʒ����,������)
        query.exec("create table goods(goodsid int primary key, name varchar, goodsnum varchar, goodscode varchar, goodsprice varchar, goodssupplier varchar)");
        //�������Ա��ʼ�û���������
        query.exec("insert into person values(1,'ad','')");

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

