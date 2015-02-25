#include <QtGui/QApplication>
#include "logindialog.h"
#include "mydatabase.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

    QApplication app(argc, argv);

    //�����ݿ�
    mydatabase db;
    if(db.opendb("book.db"))
    {
        //�������ݿ��
        db.createtable();
    }

    //������Ӧ���ļ���
    createFolder("user");  //��Ա

    //��������
    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
        // Get saved network configuration
        QSettings settings(QSettings::UserScope, QLatin1String("Trolltech"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        // If the saved network configuration is not currently discovered use the system default
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
            QNetworkConfiguration::Discovered) {
            config = manager.defaultConfiguration();
        }

        QNetworkSession *networkSession = new QNetworkSession(config, &app);
        networkSession->open();
        networkSession->waitForOpened();

        if (networkSession->isOpen()) {
            // Save the used configuration
            QNetworkConfiguration config = networkSession->configuration();
            QString id;
            if (config.type() == QNetworkConfiguration::UserChoice) {
                id = networkSession->sessionProperty(
                        QLatin1String("UserChoiceConfiguration")).toString();
            } else {
                id = config.identifier();
            }

            QSettings settings(QSettings::UserScope, QLatin1String("Trolltech"));
            settings.beginGroup(QLatin1String("QtNetwork"));
            settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
            settings.endGroup();
        }
    }

    loginDialog w;
    w.show();

    return app.exec();
}

#if 0

ͼ�����ʱ����ϵͳ
�����ܣ���¼ģ�飬ͼ�����ģ�飬ѧ������ģ�飬�軹��Ϣģ�飬ͼ�����ģ��ͷ�����Ϣģ��
��¼ģ�飺ѡ������ͨ�û���¼���ǹ���Ա��¼������Ա��¼��ת������Ա���棬��ͨ�û���¼����ת����ͨ�û����档
ͼ�����ģ�飺����Աͨ����֤�������ϵͳ�󣬽��뵽ͼ�����ģ�飬���Զ�ͼ�������ӡ�ɾ�����޸�ͼ����Ϣ����ѯ���鿴��һϵ�еĲ�����
�û�����ģ�飺����Աͨ����֤�������ϵͳ�󣬽��뵽�û�����ģ�飬���������û����ṩ���Ŀ�����ɾ���û����޸��û���Ϣ����ѯ���鿴���������ݿ����û���Ϣ�����������ֻ���������롣�ֻ�����Ĭ��Ϊ���Ŀ���ţ���Ϊ��¼�˺š�����Ա����û���ʱ������������һ�
���Ĺ���ģ�飺����Ա�����ģ���п���Ϊ�û��������ͼ�飬�黹ͼ�飬�����Բ鿴�û��Ľ�����Ϣ��
ͼ�����ģ�飺��ͨ�û�ͨ����֤�������ϵͳ���ܹ�����ͼ��ID�����������ߵȶ���������ͼ����в�ѯ������
�ص㹦�ܡ�����������Ϣģ��
������Ϣģ�飺����Ա��������ݿ���ͼ��Ĺ黹���ڣ��Թ黹ʣ��ʱ��Ϊ1��ʱ������Ա�����û�����������Ϣ����ʱ����ͬ���ͻ������û�Ⱥ����Ϣ��

#endif
