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

//����
QString Encrypt(QString s)
{
    QByteArray sourceStr = s.toAscii();
    QCryptographicHash *md4Hash = new QCryptographicHash(QCryptographicHash::Md4);
    md4Hash->addData(sourceStr);
    QByteArray targetStr = md4Hash->result();
    QString resStr = targetStr.toHex();

    resStr = resStr + "lichao";
    sourceStr = resStr.toAscii();
    QCryptographicHash *md5Hash = new QCryptographicHash(QCryptographicHash::Md5);
    md5Hash->addData(sourceStr);
    targetStr = md5Hash->result();
    resStr = targetStr.toHex();

    resStr = resStr + "lichao";
    sourceStr = resStr.toAscii();
    QCryptographicHash *sha1Hash = new QCryptographicHash(QCryptographicHash::Sha1);
    sha1Hash->addData(sourceStr);
    targetStr = sha1Hash->result();
    resStr = targetStr.toHex();

    return resStr;
}

QString fingerBmpPath = "f.bmp";
QMap<int, QVariant> fingerTemplateMap;


//�����Աָ��ģ��
void insertFingerTempMap(int userid, QVariant ATemplate)
{
    fingerTemplateMap.insert(userid, ATemplate);
}

//ɾ����Աָ��ģ��
void removeFingerTempMap(int userid)
{
    fingerTemplateMap.remove(userid);
}

//�޸���Աָ��ģ��
void modifyFingerTempMap(int userid, QVariant ATemplate)
{
    removeFingerTempMap(userid);
    insertFingerTempMap(userid, ATemplate);
}

