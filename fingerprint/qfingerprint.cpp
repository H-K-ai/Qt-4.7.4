#include "qfingerprint.h"

qFingerprint::qFingerprint(QObject *parent) :
    QObject(parent)
{
    /*
     QT��ʹ��ActiveX�ؼ���QAxBase��QAxWidget
     http://blog.163.com/lijiji_1515/blog/static/1268774462009921961893/

     http://blog.csdn.net/tszhangjunqiao/article/details/16946953

     http://blog.csdn.net/goodowxy/article/details/4294568

     */

    qFinger = new QAxWidget;

    qFinger->setControl(QString::fromUtf8("{CA69969C-2F27-41D3-954D-A48B941C3BA7}"));
    qFinger->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    qFinger->setObjectName(QString::fromUtf8("ZKFPEngXControl"));

    connect(qFinger, SIGNAL(OnImageReceived(bool&)), this, SLOT(finishImageReceived(bool&)));
    connect(qFinger, SIGNAL(OnCapture(bool, QVariant)), this, SLOT(finishCapture(bool, QVariant)));
    connect(qFinger, SIGNAL(OnEnroll(bool, QVariant)), this, SLOT(finishEnrool(bool, QVariant)));
    connect(qFinger, SIGNAL(OnFeatureInfo(int)), this, SLOT(finishFeatureInfo(int)));
}

qFingerprint::~qFingerprint()
{
    delete qFinger;
}

//��ʼ���豸
int qFingerprint::InitEngine()
{
    // 0 ��ʼ���ɹ�
    // 1 ָ��ʶ�������������ʧ��
    // 2 û������ָ��ʶ����
    // 3 ����SensorIndexָ����ָ���ǲ����ڣ�ע�⣺�ڵ���֮ǰ��������SensorIndex��
    // ���Ե�ʱ�� qFinger->dynamicCall("InitEngine()"); �ᱨ�� ԭ��δ֪
    int result = -1;
    QList<QVariant> params;

    params << qFinger->dynamicCall("InitEngine()");
    result = params[0].value<int>();

    return result;
}

//�ر��豸
void qFingerprint::EndEngine()
{
    qFinger->dynamicCall("EndEngine()");
}

//��ʼ�Ǽ�ָ��
void qFingerprint::BeginEnroll()
{
    qFinger->dynamicCall("BeginEnroll()");
}

//����ǼǴ���
int qFingerprint::EnrollIndex()
{
    int result = -1;
    QList<QVariant> params;

    params << qFinger->dynamicCall("EnrollIndex");
    result = params[0].value<int>();

    return result;
}

//�Ƿ����ڵǼ�
bool qFingerprint::IsRegister()
{
    bool result = false;
    QList<QVariant> params;

    params << qFinger->dynamicCall("IsRegister");
    result = params[0].value<bool>();

    return result;
}

//�رյǼ�ָ��
void qFingerprint::CancelEnroll()
{
    qFinger->dynamicCall("CancelEnroll()");
}

//����ָ��ͼ��
void qFingerprint::SaveBitmap()
{
    QList<QVariant> params;
    params << fingerBmpPath;

   qFinger->dynamicCall("SaveBitmap(QString)", params);
}

//����ָ��������
QString qFingerprint::EncodeTemplate(QVariant ATemplate)
{
    QString result = "false";
    QList<QVariant> params;

    params << qFinger->dynamicCall("EncodeTemplate1(QVariant)", ATemplate);
    result = params[0].value<QString>();

    return result;
}

//ָ��������ת��
QVariant qFingerprint::DecodeTemplate(QString UserZW)
{
    QVariant result = "false";
    QList<QVariant> params;

    params << qFinger->dynamicCall("DecodeTemplate1(QString)", UserZW);
    result = params[0];

    return result;
}

//�����Ƿ�ƥ��
bool qFingerprint::VerFinger(QVariant& FRegTemplate, QVariant ATemplate)
{
    bool result = false;
    bool ADoLearning = true;
    bool RegChanged = true;

    QList<QVariant> params;

    params << qFinger->dynamicCall("VerFinger(QVariant&, QVariant, bool, bool&) ", FRegTemplate, ATemplate, ADoLearning, RegChanged);
    result = params[0].value<bool>();

    return result;
}

//��ȡָ���������к�
QString qFingerprint::SensorSN()
{
    QString result = "";
    QList<QVariant> params;

    params << qFinger->dynamicCall("SensorSN()");
    result = params[0].value<QString>();

    return result;
}

//��ǰָ����������
int qFingerprint::SensorIndex()
{
    int result = -1;
    QList<QVariant> params;

    params << qFinger->dynamicCall("SensorIndex()");
    result = params[0].value<int>();

    return result;
}

//��ȡָ����������
int qFingerprint::SensorCount()
{
    int result = -1;
    QList<QVariant> params;

    params << qFinger->dynamicCall("SensorCount()");
    result = params[0].value<int>();

    return result;
}

//ͼƬ�������
void qFingerprint::finishImageReceived(bool& AImageValid)
{
    /*
        �豸ȡ��ָ��ͼ�����ͨ��AddImageFile��AddBitmap����ָ��ͼ��ʱ���ø��¼�
        AImageValid��ʾ�Ƿ����ģ����ȡ
        ����ΪFalse��,ϵͳ��ȡ��ָ��ͼ��󷵻�,������ģ����ȡ��
    */
    emit OnImageReceived();
}

void qFingerprint::finishCapture(bool ActionResult, QVariant ATemplate)
{
    /*
        ActionResult = True ��ʾ�ɹ�ȡ��ָ��ģ��, False ��ʾʧ��.
    */
    if(ActionResult)
    {
        emit OnCapture(ATemplate);
    }
}

//�Ǽ����
void qFingerprint::finishEnrool(bool ActionResult, QVariant ATemplate)
{
    /*
        BeginEnroll() ��ʼ�Ǽ�
        CancelEnroll() �����Ǽ�

        һ������֮����ɵǼ�,�õ�����ģ��
        �û��Ǽ�ָ�ƽ���ʱ���ø��¼�, ActionResult =true ��ʾ�ɹ��Ǽ�,
        QByteArray ��ATemplate���Կ�ȡ��ָ������ģ��, False ��ʾʧ�ܡ�
    */
    QString result = "false";
    if(ActionResult == true)
    {
        result = this->EncodeTemplate(ATemplate);
    }
    emit OnEnroll(result);
}

//ָ����Ϣ���
void qFingerprint::finishFeatureInfo(int AQuality)
{
    /*
        ȡ��ָ�Ƴ�ʼ������Quality��ʾ��ָ�������������������¿���ֵ��OnFeatureInfo(AQuality As Long)
        0: �õ�ָ������
        1: �����㲻��
        2: ����ԭ���²���ȡ��ָ������
    */
    emit OnFeatureInfo(AQuality);
}

