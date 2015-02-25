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
    if (tables.contains("car", Qt::CaseInsensitive)
            && tables.contains("goods", Qt::CaseInsensitive)
            && tables.contains("orders", Qt::CaseInsensitive)
            && tables.contains("user", Qt::CaseInsensitive)
            && tables.contains("expresscom", Qt::CaseInsensitive)
            )
    {
        //������������Ѵ���,����Ҫ�ٴδ���
        //qDebug("table exsited\n");
    }
    else
    {
        QSqlQuery query;
        //����������(���,˾��,���ƺ�,����)
        query.exec("create table car(carid int primary key, name varchar, carnum varchar, type int)");
        //������Ʒ��(���,����,����,����)
        query.exec("create table goods(goodsid int primary key, name varchar, type int, date datetime)");
        //����������(���,������,��ݹ�˾)
        query.exec("create table orders(ordersid int primary key, ordernum varchar, express int)");
        //������Ա��(���,�û���,����)
        query.exec("create table user(userid int primary key, name varchar, passwd varchar)");
        //������ݹ�˾��(���,��˾��,����)
        query.exec("create table expresscom(expresscomid int primary key, name varchar, codes varchar)");

        query.exec("insert into user values(0, 'ad', '')");

        query.exec("insert into expresscom values(0, '', '')");
        query.exec("insert into expresscom values(1, 'AAE���', 'aae')");
        query.exec("insert into expresscom values(2, '���ݿ��', 'anjie')");
        query.exec("insert into expresscom values(3, '���Ŵ���', 'anxinda')");
        query.exec("insert into expresscom values(4, 'Aramex���ʿ��', 'aramex')");
        query.exec("insert into expresscom values(5, '�ɶ����ڹ��ʿ��', 'benteng')");
        query.exec("insert into expresscom values(6, 'CCES���', 'cces')");
        query.exec("insert into expresscom values(7, '��ͨ����', 'changtong')");
        query.exec("insert into expresscom values(8, '�̹���', 'chengguang')");
        query.exec("insert into expresscom values(9, '�Ǽʿ��', 'chengji')");
        query.exec("insert into expresscom values(10, '����100', 'chengshi100')");
        query.exec("insert into expresscom values(11, '��ϲ���', 'chuanxi')");
        query.exec("insert into expresscom values(12, '��־���', 'chuanzhi')");
        query.exec("insert into expresscom values(13, 'CityLinkExpress', 'citylink')");
        query.exec("insert into expresscom values(14, '�������', 'coe')");
        query.exec("insert into expresscom values(15, '����֮��', 'cszx')");
        query.exec("insert into expresscom values(16, '��������', 'datian')");
        query.exec("insert into expresscom values(17, '�����������', 'dayang')");
        query.exec("insert into expresscom values(18, '�°�����', 'debang')");
        query.exec("insert into expresscom values(19, '�´�����', 'dechuang')");
        query.exec("insert into expresscom values(20, 'DHL���', 'dhl')");
        query.exec("insert into expresscom values(21, '��ͨ���', 'diantong')");
        query.exec("insert into expresscom values(22, '�ݴ���', 'dida')");
        query.exec("insert into expresscom values(23, '���ķ��ٵ�', 'disifang')");
        query.exec("insert into expresscom values(24, 'DPEX���', 'dpex')");
        query.exec("insert into expresscom values(25, 'D�ٿ��', 'dsu')");
        query.exec("insert into expresscom values(26, '�ٸ���������', 'ees')");
        query.exec("insert into expresscom values(27, 'EMS���', 'ems')");
        query.exec("insert into expresscom values(28, '������', 'fanyu')");
        query.exec("insert into expresscom values(29, 'Fardar', 'fardar')");
        query.exec("insert into expresscom values(30, '����Fedex', 'fedex')");
        query.exec("insert into expresscom values(31, 'Fedex����', 'fedexcn')");
        query.exec("insert into expresscom values(32, '�ɰ�����', 'feibang')");
        query.exec("insert into expresscom values(33, '�ɱ����', 'feibao')");
        query.exec("insert into expresscom values(34, 'ԭ�ɺ�����', 'feihang')");
        query.exec("insert into expresscom values(35, '�ɺ����', 'feihu')");
        query.exec("insert into expresscom values(36, '��Զ����', 'feiyuan')");
        query.exec("insert into expresscom values(37, '�����', 'fengda')");
        query.exec("insert into expresscom values(38, '�ɿ�����', 'fkd')");
        query.exec("insert into expresscom values(39, '�㶫��������', 'gdyz')");
        query.exec("insert into expresscom values(40, '��������С��', 'gnxb')");
        query.exec("insert into expresscom values(41, '���ٴ�����|���', 'gongsuda')");
        query.exec("insert into expresscom values(42, '��ͨ���', 'guotong')");
        query.exec("insert into expresscom values(43, 'ɽ��������', 'haihong')");
        query.exec("insert into expresscom values(44, '�����ٵ�', 'haimeng')");
        query.exec("insert into expresscom values(45, '�ʢ����', 'haosheng')");
        query.exec("insert into expresscom values(46, '�ӱ��������', 'hebeijianhua')");
        query.exec("insert into expresscom values(47, '��·����', 'henglu')");
        query.exec("insert into expresscom values(48, '������', 'huaqi')");
        query.exec("insert into expresscom values(49, '����������', 'huaxialong')");
        query.exec("insert into expresscom values(50, '��ػ�������', 'huayu')");
        query.exec("insert into expresscom values(51, '��ǿ���', 'huiqiang')");
        query.exec("insert into expresscom values(52, '��ͨ���', 'huitong')");
        query.exec("insert into expresscom values(53, '���⻷����', 'hwhq')");
        query.exec("insert into expresscom values(54, '�Ѽ�����', 'jiaji')");
        query.exec("insert into expresscom values(55, '��������', 'jiayi')");
        query.exec("insert into expresscom values(56, '���������', 'jiayunmei')");
        query.exec("insert into expresscom values(57, '�������', 'jinda')");
        query.exec("insert into expresscom values(58, '������', 'jingguang')");
        query.exec("insert into expresscom values(59, '��Խ���', 'jinyue')");
        query.exec("insert into expresscom values(60, '���ȴ�����', 'jixianda')");
        query.exec("insert into expresscom values(61, '�����ͨ����', 'jldt')");
        query.exec("insert into expresscom values(62, '��������', 'kangli')");
        query.exec("insert into expresscom values(63, '˳��(KCS)���', 'kcs')");
        query.exec("insert into expresscom values(64, '��ݿ��', 'kuaijie')");
        query.exec("insert into expresscom values(65, '��Խ���', 'kuayue')");
        query.exec("insert into expresscom values(66, '�ֽݵݿ��', 'lejiedi')");
        query.exec("insert into expresscom values(67, '���ͨ���', 'lianhaotong')");
        query.exec("insert into expresscom values(68, '�ɶ������Ϳ��', 'lijisong')");
        query.exec("insert into expresscom values(69, '������', 'longbang')");
        query.exec("insert into expresscom values(70, '�����', 'minbang')");
        query.exec("insert into expresscom values(71, '��������', 'mingliang')");
        query.exec("insert into expresscom values(72, '��ʢ���', 'minsheng')");
        query.exec("insert into expresscom values(73, '�����ܴ���', 'nengda')");
        query.exec("insert into expresscom values(74, 'OCS���', 'ocs')");
        query.exec("insert into expresscom values(75, 'ƽ����', 'pinganda')");
        query.exec("insert into expresscom values(76, '�й�����ƽ��', 'pingyou')");
        query.exec("insert into expresscom values(77, 'Ʒ���Ĵ���', 'pinsu')");
        query.exec("insert into expresscom values(78, 'ȫ�����', 'quanchen')");
        query.exec("insert into expresscom values(79, 'ȫ����', 'quanfeng')");
        query.exec("insert into expresscom values(80, 'ȫ��ͨ���', 'quanjitong')");
        query.exec("insert into expresscom values(81, 'ȫ��ͨ���', 'quanritong')");
        query.exec("insert into expresscom values(82, 'ȫһ���', 'quanyi')");
        query.exec("insert into expresscom values(83, 'RPX��ʱ��', 'rpx')");
        query.exec("insert into expresscom values(84, '������', 'rufeng')");
        query.exec("insert into expresscom values(85, '���ĵ�', 'saiaodi')");
        query.exec("insert into expresscom values(86, '��̬�ٵ�', 'santai')");
        query.exec("insert into expresscom values(87, 'ΰ��(SCS)���', 'scs')");
        query.exec("insert into expresscom values(88, 'ʥ������', 'shengan')");
        query.exec("insert into expresscom values(89, 'ʢ������', 'shengfeng')");
        query.exec("insert into expresscom values(90, 'ʢ������', 'shenghui')");
        query.exec("insert into expresscom values(91, '��ͨ���', 'shentong')");
        query.exec("insert into expresscom values(92, '˳����', 'shunfeng')");
        query.exec("insert into expresscom values(93, '�������', 'suijia')");
        query.exec("insert into expresscom values(94, '�ٶ����', 'sure')");
        query.exec("insert into expresscom values(95, '������', 'tiantian')");
        query.exec("insert into expresscom values(96, 'TNT���', 'tnt')");
        query.exec("insert into expresscom values(97, 'ͨ������', 'tongcheng')");
        query.exec("insert into expresscom values(98, 'ͨ����������', 'tonghe')");
        query.exec("insert into expresscom values(99, 'UPS', 'ups')");
        query.exec("insert into expresscom values(100, 'USPS���', 'usps')");
        query.exec("insert into expresscom values(101, '�������', 'wanjia')");
        query.exec("insert into expresscom values(102, '΢����', 'weitepai')");
        query.exec("insert into expresscom values(103, '������ͨ���', 'xianglong')");
        query.exec("insert into expresscom values(104, '�°�����', 'xinbang')");
        query.exec("insert into expresscom values(105, '�ŷ���', 'xinfeng')");
        query.exec("insert into expresscom values(106, 'ϣ���ؿ��', 'xiyoute')");
        query.exec("insert into expresscom values(107, 'Դ������', 'yad')");
        query.exec("insert into expresscom values(108, '�Ƿ���', 'yafeng')");
        query.exec("insert into expresscom values(109, 'һ����', 'yibang')");
        query.exec("insert into expresscom values(110, '���ݿ��', 'yinjie')");
        query.exec("insert into expresscom values(111, '��˳�����', 'yishunhang')");
        query.exec("insert into expresscom values(112, '���ٿ��', 'yousu')");
        query.exec("insert into expresscom values(113, '����һͳ�ɺ���', 'ytfh')");
        query.exec("insert into expresscom values(114, 'Զ������', 'yuancheng')");
        query.exec("insert into expresscom values(115, 'Բͨ���', 'yuantong')");
        query.exec("insert into expresscom values(116, 'Ԫ�ǽݳ�', 'yuanzhi')");
        query.exec("insert into expresscom values(117, 'Խ����', 'yuefeng')");
        query.exec("insert into expresscom values(118, '�ϴ���', 'yunda')");
        query.exec("insert into expresscom values(119, '��ͨ�иۿ��', 'yuntong')");
        query.exec("insert into expresscom values(120, 'Դΰ��', 'ywfex')");
        query.exec("insert into expresscom values(121, 'լ���Ϳ��', 'zhaijisong')");
        query.exec("insert into expresscom values(122, '֣�ݽ������', 'zhengzhoujianhua')");
        query.exec("insert into expresscom values(123, '֥�鿪�ſ��', 'zhima')");
        query.exec("insert into expresscom values(124, '������������', 'zhongtian')");
        query.exec("insert into expresscom values(125, '��������', 'zhongtie')");
        query.exec("insert into expresscom values(126, '��ͨ���', 'zhongtong')");
        query.exec("insert into expresscom values(127, '���Ŵ���', 'zhongxinda')");
        query.exec("insert into expresscom values(128, '��������', 'zhongyou')");

    }
}

void mydatabase::closedb()
{
    db.close();
}
