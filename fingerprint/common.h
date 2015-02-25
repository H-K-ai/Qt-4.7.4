#ifndef COMMON_H
#define COMMON_H

#include <QtGui>
#include <QtDebug>
#include <QtSql>
#include <QList>
#include <QDateTime>
#include <QTextCodec>
#include <QDialog>
#include <QObject>
#include <QAxWidget>
#include <QAbstractItemModel>
#include <QSqlDatabase>
#include <QCryptographicHash>

//�����ļ�
bool copyFileToPath(QString sourceDir, QString toDir, bool coverFileIfExist);
//�����ļ���
bool copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist);
//�����ļ���
bool createFolder(const QString dir);

//����
QString Encrypt(QString s);

//Ȩ��
#define STAFF_ROLE  0       /* Ա�� */
#define BUYER_ROLE  1       /* �ɹ�Ա */
#define KEEPER_ROLE 2       /* ����Ա */
#define LEADER_ROLE 3       /* ���� */
#define ADMIN_ROLE  4       /* ����Ա */


#define BORROW_FLAG 0       /* �����־ */
#define BACK_FALG   1       /* �黹��־ */

//ָ��ͼƬ·��
extern QString fingerBmpPath;

//��Աָ��ģ��
extern QMap<int, QVariant> fingerTemplateMap;

//�����Աָ��ģ��
void insertFingerTempMap(int userid, QVariant ATemplate);
//ɾ����Աָ��ģ��
void removeFingerTempMap(int userid);
//�޸���Աָ��ģ��
void modifyFingerTempMap(int userid, QVariant ATemplate);

#endif // COMMON_H
