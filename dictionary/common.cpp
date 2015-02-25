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
    if (tables.contains("person", Qt::CaseInsensitive)
            && tables.contains("dictionary", Qt::CaseInsensitive)
            && tables.contains("myword", Qt::CaseInsensitive)
            )
    {
        //������������Ѵ���,����Ҫ�ٴδ���
        //qDebug("table exsited\n");
    }
    else
    {
        QSqlQuery query;
        //������Ա��(���, ����, ����)
        query.exec("create table person(personid int primary key, name varchar, passwd varchar)");
        //�������ֱ�(���, �û�, ����)
        query.exec("create table myword(mywordid int primary key, userid varchar, myword varchar)");
        //�����ֵ��(���, �ֵ�)
        query.exec("create table dictionary(dictionaryid int primary key, myword varchar)");

        //�������Ա��ʼ�û���������
        query.exec("insert into person values(1,'ad','')");

        //�����ֵ�
        query.exec("insert into dictionary values(1, 'һ')");
        query.exec("insert into dictionary values(2, '��')");
        query.exec("insert into dictionary values(3, '��')");
        query.exec("insert into dictionary values(4, '��')");
        query.exec("insert into dictionary values(5, '��')");
        query.exec("insert into dictionary values(6, 'ʮ')");
        query.exec("insert into dictionary values(7, '��')");
        query.exec("insert into dictionary values(8, 'ţ')");
        query.exec("insert into dictionary values(9, '��')");
        query.exec("insert into dictionary values(10, '��')");
        query.exec("insert into dictionary values(11, '��')");
        query.exec("insert into dictionary values(12, 'Ѽ')");
        query.exec("insert into dictionary values(13, '��')");
        query.exec("insert into dictionary values(14, '��')");
        query.exec("insert into dictionary values(15, '��')");
        query.exec("insert into dictionary values(16, 'С')");
        query.exec("insert into dictionary values(17, '��')");
        query.exec("insert into dictionary values(18, '��')");
        query.exec("insert into dictionary values(19, 'ͷ')");
        query.exec("insert into dictionary values(20, 'ֻ')");
        query.exec("insert into dictionary values(21, '��')");
        query.exec("insert into dictionary values(22, '��')");
        query.exec("insert into dictionary values(23, '��')");
        query.exec("insert into dictionary values(24, '��')");
        query.exec("insert into dictionary values(25, '��')");
        query.exec("insert into dictionary values(26, '��')");
        query.exec("insert into dictionary values(27, '��')");
        query.exec("insert into dictionary values(28, '��')");
        query.exec("insert into dictionary values(29, '��')");
        query.exec("insert into dictionary values(30, '��')");
        query.exec("insert into dictionary values(31, '��')");
        query.exec("insert into dictionary values(32, '��')");
        query.exec("insert into dictionary values(33, '��')");
        query.exec("insert into dictionary values(34, '��')");
        query.exec("insert into dictionary values(35, '��')");
        query.exec("insert into dictionary values(36, '��')");
        query.exec("insert into dictionary values(37, '��')");
        query.exec("insert into dictionary values(38, '��')");
        query.exec("insert into dictionary values(39, '��')");
        query.exec("insert into dictionary values(40, '��')");
        query.exec("insert into dictionary values(41, '��')");
        query.exec("insert into dictionary values(42, '��')");
        query.exec("insert into dictionary values(43, '��')");
        query.exec("insert into dictionary values(44, '��')");
        query.exec("insert into dictionary values(45, '��')");
        query.exec("insert into dictionary values(46, '��')");
        query.exec("insert into dictionary values(47, '��')");
        query.exec("insert into dictionary values(48, 'Ů')");
        query.exec("insert into dictionary values(49, '��')");
        query.exec("insert into dictionary values(50, '��')");
        query.exec("insert into dictionary values(51, '��')");
        query.exec("insert into dictionary values(52, 'ɽ')");
        query.exec("insert into dictionary values(53, 'ˮ')");
        query.exec("insert into dictionary values(54, '��')");
        query.exec("insert into dictionary values(55, '��')");
        query.exec("insert into dictionary values(56, '��')");
        query.exec("insert into dictionary values(57, 'Ҷ')");
        query.exec("insert into dictionary values(58, 'ɳ')");
        query.exec("insert into dictionary values(59, '��')");
        query.exec("insert into dictionary values(60, 'ľ')");
        query.exec("insert into dictionary values(61, '��')");
        query.exec("insert into dictionary values(62, '��')");
        query.exec("insert into dictionary values(63, '��')");
        query.exec("insert into dictionary values(64, '��')");
        query.exec("insert into dictionary values(65, '��')");
        query.exec("insert into dictionary values(66, '��')");
        query.exec("insert into dictionary values(67, '��')");
        query.exec("insert into dictionary values(68, '��')");
        query.exec("insert into dictionary values(69, '��')");
        query.exec("insert into dictionary values(70, '��')");
        query.exec("insert into dictionary values(71, '��')");
        query.exec("insert into dictionary values(72, '��')");
        query.exec("insert into dictionary values(73, '��')");
        query.exec("insert into dictionary values(74, '��')");
        query.exec("insert into dictionary values(75, '��')");
        query.exec("insert into dictionary values(76, '��')");
        query.exec("insert into dictionary values(77, '��')");
        query.exec("insert into dictionary values(78, 'ѩ')");
        query.exec("insert into dictionary values(79, '��')");
        query.exec("insert into dictionary values(80, '��')");
        query.exec("insert into dictionary values(81, '��')");
        query.exec("insert into dictionary values(82, 'ɫ')");
        query.exec("insert into dictionary values(83, '��')");
        query.exec("insert into dictionary values(84, '��')");
        query.exec("insert into dictionary values(85, '��')");
        query.exec("insert into dictionary values(86, '��')");
        query.exec("insert into dictionary values(87, '��')");
        query.exec("insert into dictionary values(88, '̫')");
        query.exec("insert into dictionary values(89, '��')");
        query.exec("insert into dictionary values(90, '��')");
        query.exec("insert into dictionary values(91, 'ү')");
        query.exec("insert into dictionary values(92, '��')");
        query.exec("insert into dictionary values(93, '��')");
        query.exec("insert into dictionary values(94, '��')");
        query.exec("insert into dictionary values(95, '��')");
        query.exec("insert into dictionary values(96, 'ĸ')");
        query.exec("insert into dictionary values(97, '��')");
        query.exec("insert into dictionary values(98, '��')");
        query.exec("insert into dictionary values(99, '��')");
        query.exec("insert into dictionary values(100, '֦')");
        query.exec("insert into dictionary values(101, '��')");
        query.exec("insert into dictionary values(102, '��')");
        query.exec("insert into dictionary values(103, '��')");
        query.exec("insert into dictionary values(104, '��')");
        query.exec("insert into dictionary values(105, '��')");
        query.exec("insert into dictionary values(106, '��')");
        query.exec("insert into dictionary values(107, 'ɭ')");
        query.exec("insert into dictionary values(108, '��')");
        query.exec("insert into dictionary values(109, '��')");
        query.exec("insert into dictionary values(110, '��')");
        query.exec("insert into dictionary values(111, '��')");
        query.exec("insert into dictionary values(112, '��')");
        query.exec("insert into dictionary values(113, '��')");
        query.exec("insert into dictionary values(114, '��')");
        query.exec("insert into dictionary values(115, 'ͬ')");
        query.exec("insert into dictionary values(116, 'ѧ')");
        query.exec("insert into dictionary values(117, '��')");
        query.exec("insert into dictionary values(118, 'ʦ')");
        query.exec("insert into dictionary values(119, 'ϰ')");
        query.exec("insert into dictionary values(120, '԰')");
        query.exec("insert into dictionary values(121, '��')");
        query.exec("insert into dictionary values(122, '��')");
        query.exec("insert into dictionary values(123, 'Ҳ')");
        query.exec("insert into dictionary values(124, '��')");
        query.exec("insert into dictionary values(125, '��')");
        query.exec("insert into dictionary values(126, '��')");
        query.exec("insert into dictionary values(127, '��')");
        query.exec("insert into dictionary values(128, '��')");
        query.exec("insert into dictionary values(129, '��')");
        query.exec("insert into dictionary values(130, '��')");
        query.exec("insert into dictionary values(131, '��')");
        query.exec("insert into dictionary values(132, '��')");
        query.exec("insert into dictionary values(133, '��')");
        query.exec("insert into dictionary values(134, '��')");
        query.exec("insert into dictionary values(135, '��')");
        query.exec("insert into dictionary values(136, '��')");
        query.exec("insert into dictionary values(137, '��')");
        query.exec("insert into dictionary values(138, '��')");
        query.exec("insert into dictionary values(139, '��')");
        query.exec("insert into dictionary values(140, '��')");
        query.exec("insert into dictionary values(141, '��')");
        query.exec("insert into dictionary values(142, '��')");
        query.exec("insert into dictionary values(143, '��')");
        query.exec("insert into dictionary values(144, '��')");
        query.exec("insert into dictionary values(145, '��')");
        query.exec("insert into dictionary values(146, '��')");
        query.exec("insert into dictionary values(147, '��')");
        query.exec("insert into dictionary values(148, '��')");
        query.exec("insert into dictionary values(149, 'ǰ')");
        query.exec("insert into dictionary values(150, '��')");
        query.exec("insert into dictionary values(151, 'Ϊ')");
        query.exec("insert into dictionary values(152, 'ʲ')");
        query.exec("insert into dictionary values(153, 'ô')");
        query.exec("insert into dictionary values(154, '֪')");
        query.exec("insert into dictionary values(155, '��')");
        query.exec("insert into dictionary values(156, '��')");
        query.exec("insert into dictionary values(157, '��')");
        query.exec("insert into dictionary values(158, 'ȥ')");
        query.exec("insert into dictionary values(159, '��')");
        query.exec("insert into dictionary values(160, '��')");
        query.exec("insert into dictionary values(161, '��')");
        query.exec("insert into dictionary values(162, '��')");
        query.exec("insert into dictionary values(163, '��')");
        query.exec("insert into dictionary values(164, '��')");
        query.exec("insert into dictionary values(165, '��')");
        query.exec("insert into dictionary values(166, 'ǧ')");
        query.exec("insert into dictionary values(167, '��')");
        query.exec("insert into dictionary values(168, 'û')");
        query.exec("insert into dictionary values(169, 'ë')");
        query.exec("insert into dictionary values(170, '��')");
        query.exec("insert into dictionary values(171, '��')");
        query.exec("insert into dictionary values(172, '��')");
        query.exec("insert into dictionary values(173, '��')");
        query.exec("insert into dictionary values(174, '��')");
        query.exec("insert into dictionary values(175, '��')");
        query.exec("insert into dictionary values(176, 'Բ')");
        query.exec("insert into dictionary values(177, '��')");
        query.exec("insert into dictionary values(178, '��')");
        query.exec("insert into dictionary values(179, '̨')");
        query.exec("insert into dictionary values(180, 'λ')");
        query.exec("insert into dictionary values(181, '��')");
        query.exec("insert into dictionary values(182, '��')");
        query.exec("insert into dictionary values(183, 'ס')");
        query.exec("insert into dictionary values(184, '��')");
        query.exec("insert into dictionary values(185, '��')");
        query.exec("insert into dictionary values(186, '��')");
        query.exec("insert into dictionary values(187, '��')");
        query.exec("insert into dictionary values(188, '��')");
        query.exec("insert into dictionary values(189, '��')");
        query.exec("insert into dictionary values(190, '��')");
        query.exec("insert into dictionary values(191, '��')");
        query.exec("insert into dictionary values(192, '��')");
        query.exec("insert into dictionary values(193, '��')");
        query.exec("insert into dictionary values(194, '��')");
        query.exec("insert into dictionary values(195, '��')");
        query.exec("insert into dictionary values(196, '��')");
        query.exec("insert into dictionary values(197, '��')");
        query.exec("insert into dictionary values(198, '��')");
        query.exec("insert into dictionary values(199, '��')");
        query.exec("insert into dictionary values(200, '��')");
        query.exec("insert into dictionary values(201, '��')");
        query.exec("insert into dictionary values(202, '��')");
        query.exec("insert into dictionary values(203, '��')");
        query.exec("insert into dictionary values(204, '��')");
        query.exec("insert into dictionary values(205, '׽')");
        query.exec("insert into dictionary values(206, '��')");
        query.exec("insert into dictionary values(207, '��')");
        query.exec("insert into dictionary values(208, '��')");
        query.exec("insert into dictionary values(209, '��')");
        query.exec("insert into dictionary values(210, '��')");
        query.exec("insert into dictionary values(211, '˵')");
        query.exec("insert into dictionary values(212, '��')");
        query.exec("insert into dictionary values(213, '��')");
        query.exec("insert into dictionary values(214, '��')");
        query.exec("insert into dictionary values(215, '��')");
        query.exec("insert into dictionary values(216, '��')");
        query.exec("insert into dictionary values(217, '��')");
        query.exec("insert into dictionary values(218, '��')");
        query.exec("insert into dictionary values(219, 'ÿ')");
        query.exec("insert into dictionary values(220, 'Ƭ')");
        query.exec("insert into dictionary values(221, '��')");
        query.exec("insert into dictionary values(222, '��')");
        query.exec("insert into dictionary values(223, '��')");
        query.exec("insert into dictionary values(224, '��')");
        query.exec("insert into dictionary values(225, '��')");
        query.exec("insert into dictionary values(226, '��')");
        query.exec("insert into dictionary values(227, '��')");
        query.exec("insert into dictionary values(228, '��')");
        query.exec("insert into dictionary values(229, '��')");
        query.exec("insert into dictionary values(230, '��')");
        query.exec("insert into dictionary values(231, '��')");
        query.exec("insert into dictionary values(232, '��')");
        query.exec("insert into dictionary values(233, 'Ҫ')");
        query.exec("insert into dictionary values(234, '��')");
        query.exec("insert into dictionary values(235, '��')");
        query.exec("insert into dictionary values(236, '��')");
        query.exec("insert into dictionary values(237, 'Ƥ')");
        query.exec("insert into dictionary values(238, '��')");
        query.exec("insert into dictionary values(239, '��')");
        query.exec("insert into dictionary values(240, '��')");
        query.exec("insert into dictionary values(241, '��')");
        query.exec("insert into dictionary values(242, '��')");
        query.exec("insert into dictionary values(243, '��')");
        query.exec("insert into dictionary values(244, 'ȫ')");
        query.exec("insert into dictionary values(245, '��')");
        query.exec("insert into dictionary values(246, '��')");
        query.exec("insert into dictionary values(247, '��')");
        query.exec("insert into dictionary values(248, 'Ц')");
        query.exec("insert into dictionary values(249, '��')");
        query.exec("insert into dictionary values(250, '��')");
        query.exec("insert into dictionary values(251, '��')");
        query.exec("insert into dictionary values(252, '��')");
        query.exec("insert into dictionary values(253, '��')");
        query.exec("insert into dictionary values(254, 'ֽ')");
        query.exec("insert into dictionary values(255, '��')");
        query.exec("insert into dictionary values(256, 'д')");
        query.exec("insert into dictionary values(257, '��')");
        query.exec("insert into dictionary values(258, '��')");
        query.exec("insert into dictionary values(259, 'ҹ')");
        query.exec("insert into dictionary values(260, '��')");
        query.exec("insert into dictionary values(261, '��')");
        query.exec("insert into dictionary values(262, '��')");
        query.exec("insert into dictionary values(263, 'ʱ')");
        query.exec("insert into dictionary values(264, '��')");
        query.exec("insert into dictionary values(265, '��')");
        query.exec("insert into dictionary values(266, '��')");
        query.exec("insert into dictionary values(267, '��')");
        query.exec("insert into dictionary values(268, '��')");
        query.exec("insert into dictionary values(269, '��')");
        query.exec("insert into dictionary values(270, '��')");
        query.exec("insert into dictionary values(271, '��')");
        query.exec("insert into dictionary values(272, 'ԭ')");
        query.exec("insert into dictionary values(273, '��')");
        query.exec("insert into dictionary values(274, '��')");
        query.exec("insert into dictionary values(275, '��')");
        query.exec("insert into dictionary values(276, '��')");
        query.exec("insert into dictionary values(277, '��')");
        query.exec("insert into dictionary values(278, '��')");
        query.exec("insert into dictionary values(279, '��')");
        query.exec("insert into dictionary values(280, 'ʯ')");
        query.exec("insert into dictionary values(281, '��')");
        query.exec("insert into dictionary values(282, '��')");
        query.exec("insert into dictionary values(283, '��')");
        query.exec("insert into dictionary values(284, '��')");
        query.exec("insert into dictionary values(285, '��')");
        query.exec("insert into dictionary values(286, '��')");
        query.exec("insert into dictionary values(287, '��')");
        query.exec("insert into dictionary values(288, '��')");
        query.exec("insert into dictionary values(289, '��')");
        query.exec("insert into dictionary values(290, '��')");
        query.exec("insert into dictionary values(291, 'У')");
        query.exec("insert into dictionary values(292, '��')");
        query.exec("insert into dictionary values(293, '��')");
        query.exec("insert into dictionary values(294, 'ҽ')");
        query.exec("insert into dictionary values(295, '��')");
        query.exec("insert into dictionary values(296, 'ҵ')");
        query.exec("insert into dictionary values(297, '��')");
        query.exec("insert into dictionary values(298, '��')");
        query.exec("insert into dictionary values(299, '��')");
        query.exec("insert into dictionary values(300, 'Ŀ')");
        query.exec("insert into dictionary values(301, '��')");
        query.exec("insert into dictionary values(302, '��')");
        query.exec("insert into dictionary values(303, '��')");
        query.exec("insert into dictionary values(304, '��')");
        query.exec("insert into dictionary values(305, '��')");
        query.exec("insert into dictionary values(306, '��')");
        query.exec("insert into dictionary values(307, '��')");
        query.exec("insert into dictionary values(308, '��')");
        query.exec("insert into dictionary values(309, '��')");
        query.exec("insert into dictionary values(310, '��')");
        query.exec("insert into dictionary values(311, '��')");
        query.exec("insert into dictionary values(312, 'Ͷ')");
        query.exec("insert into dictionary values(313, '��')");
        query.exec("insert into dictionary values(314, '��')");
        query.exec("insert into dictionary values(315, '��')");
        query.exec("insert into dictionary values(316, '��')");
        query.exec("insert into dictionary values(317, '��')");
        query.exec("insert into dictionary values(318, 'ͯ')");
        query.exec("insert into dictionary values(319, '��')");
        query.exec("insert into dictionary values(320, '��')");
        query.exec("insert into dictionary values(321, '��')");
        query.exec("insert into dictionary values(322, '��')");
        query.exec("insert into dictionary values(323, '��')");
        query.exec("insert into dictionary values(324, '��')");
        query.exec("insert into dictionary values(325, '��')");
        query.exec("insert into dictionary values(326, '��')");
        query.exec("insert into dictionary values(327, '��')");
        query.exec("insert into dictionary values(328, '��')");
        query.exec("insert into dictionary values(329, '��')");
        query.exec("insert into dictionary values(330, '��')");
        query.exec("insert into dictionary values(331, '��')");
        query.exec("insert into dictionary values(332, '��')");
        query.exec("insert into dictionary values(333, '��')");
        query.exec("insert into dictionary values(334, '��')");
        query.exec("insert into dictionary values(335, 'Ư')");
        query.exec("insert into dictionary values(336, '��')");
        query.exec("insert into dictionary values(337, '��')");
        query.exec("insert into dictionary values(338, '��')");
        query.exec("insert into dictionary values(339, '��')");
        query.exec("insert into dictionary values(340, '��')");
        query.exec("insert into dictionary values(341, '��')");
        query.exec("insert into dictionary values(342, '��')");
        query.exec("insert into dictionary values(343, '��')");
        query.exec("insert into dictionary values(344, '��')");
        query.exec("insert into dictionary values(345, '��')");
        query.exec("insert into dictionary values(346, '��')");
        query.exec("insert into dictionary values(347, 'ƿ')");
        query.exec("insert into dictionary values(348, '��')");
        query.exec("insert into dictionary values(349, '��')");
        query.exec("insert into dictionary values(350, '��')");
        query.exec("insert into dictionary values(351, 'ɡ')");
        query.exec("insert into dictionary values(352, 'ȹ')");
        query.exec("insert into dictionary values(353, '��')");
        query.exec("insert into dictionary values(354, '��')");
        query.exec("insert into dictionary values(355, 'Ⱥ')");
        query.exec("insert into dictionary values(356, '��')");
        query.exec("insert into dictionary values(357, '��')");
        query.exec("insert into dictionary values(358, '��')");
        query.exec("insert into dictionary values(359, 'ֱ')");
        query.exec("insert into dictionary values(360, '��')");
        query.exec("insert into dictionary values(361, '��')");
        query.exec("insert into dictionary values(362, '��')");
        query.exec("insert into dictionary values(363, '��')");
        query.exec("insert into dictionary values(364, '��')");
        query.exec("insert into dictionary values(365, '��')");
        query.exec("insert into dictionary values(366, '��')");
        query.exec("insert into dictionary values(367, 'ʵ')");
        query.exec("insert into dictionary values(368, '��')");
        query.exec("insert into dictionary values(369, '��')");
        query.exec("insert into dictionary values(370, '��')");
        query.exec("insert into dictionary values(371, '��')");
        query.exec("insert into dictionary values(372, '��')");
        query.exec("insert into dictionary values(373, '��')");
        query.exec("insert into dictionary values(374, 'Զ')");
        query.exec("insert into dictionary values(375, '��')");
        query.exec("insert into dictionary values(376, '��')");
        query.exec("insert into dictionary values(377, '��')");
        query.exec("insert into dictionary values(378, '��')");
        query.exec("insert into dictionary values(379, '��')");
        query.exec("insert into dictionary values(380, '��')");
        query.exec("insert into dictionary values(381, '��')");
        query.exec("insert into dictionary values(382, '��')");
        query.exec("insert into dictionary values(383, '��')");
        query.exec("insert into dictionary values(384, '��')");
        query.exec("insert into dictionary values(385, '��')");
        query.exec("insert into dictionary values(386, '��')");
        query.exec("insert into dictionary values(387, '˾')");
        query.exec("insert into dictionary values(388, '��')");
        query.exec("insert into dictionary values(389, '·')");
        query.exec("insert into dictionary values(390, '��')");
        query.exec("insert into dictionary values(391, '��')");
        query.exec("insert into dictionary values(392, '��')");
        query.exec("insert into dictionary values(393, '��')");
        query.exec("insert into dictionary values(394, '��')");
        query.exec("insert into dictionary values(395, '��')");
        query.exec("insert into dictionary values(396, '��')");
        query.exec("insert into dictionary values(397, '��')");
        query.exec("insert into dictionary values(398, '��')");
        query.exec("insert into dictionary values(399, '��')");
        query.exec("insert into dictionary values(400, '��')");
        query.exec("insert into dictionary values(401, '��')");
        query.exec("insert into dictionary values(402, '��')");
        query.exec("insert into dictionary values(403, '��')");
        query.exec("insert into dictionary values(404, '��')");
        query.exec("insert into dictionary values(405, '��')");
        query.exec("insert into dictionary values(406, '��')");
        query.exec("insert into dictionary values(407, '��')");
        query.exec("insert into dictionary values(408, '��')");
        query.exec("insert into dictionary values(409, '��')");
        query.exec("insert into dictionary values(410, '��')");
        query.exec("insert into dictionary values(411, 'ר')");
        query.exec("insert into dictionary values(412, '��')");
        query.exec("insert into dictionary values(413, '��')");
        query.exec("insert into dictionary values(414, '��')");
        query.exec("insert into dictionary values(415, '��')");
        query.exec("insert into dictionary values(416, '��')");
        query.exec("insert into dictionary values(417, '��')");
        query.exec("insert into dictionary values(418, 'ϯ')");
        query.exec("insert into dictionary values(419, '��')");
        query.exec("insert into dictionary values(420, '��')");
        query.exec("insert into dictionary values(421, 'ƽ')");
        query.exec("insert into dictionary values(422, '��')");
        query.exec("insert into dictionary values(423, '��')");
        query.exec("insert into dictionary values(424, 'æ')");
        query.exec("insert into dictionary values(425, '��')");
        query.exec("insert into dictionary values(426, '��')");
        query.exec("insert into dictionary values(427, 'ϴ')");
        query.exec("insert into dictionary values(428, 'ɨ')");
        query.exec("insert into dictionary values(429, '��')");
        query.exec("insert into dictionary values(430, '��')");
        query.exec("insert into dictionary values(431, '��')");
        query.exec("insert into dictionary values(432, 'ѡ')");
        query.exec("insert into dictionary values(433, 'è')");
        query.exec("insert into dictionary values(434, '��')");
        query.exec("insert into dictionary values(435, '��')");
        query.exec("insert into dictionary values(436, 'Ϻ')");
        query.exec("insert into dictionary values(437, '��')");
        query.exec("insert into dictionary values(438, '��')");
        query.exec("insert into dictionary values(439, '��')");
        query.exec("insert into dictionary values(440, '��')");
        query.exec("insert into dictionary values(441, '��')");
        query.exec("insert into dictionary values(442, '��')");
        query.exec("insert into dictionary values(443, '��')");
        query.exec("insert into dictionary values(444, 'ȡ')");
        query.exec("insert into dictionary values(445, '��')");
        query.exec("insert into dictionary values(446, '��')");
        query.exec("insert into dictionary values(447, '��')");
        query.exec("insert into dictionary values(448, '��')");
        query.exec("insert into dictionary values(449, '��')");
        query.exec("insert into dictionary values(450, '��')");
        query.exec("insert into dictionary values(451, 'ս')");
        query.exec("insert into dictionary values(452, '��')");
        query.exec("insert into dictionary values(453, '��')");
        query.exec("insert into dictionary values(454, '��')");
        query.exec("insert into dictionary values(455, '��')");
        query.exec("insert into dictionary values(456, '��')");
        query.exec("insert into dictionary values(457, '��')");
        query.exec("insert into dictionary values(458, '��')");
        query.exec("insert into dictionary values(459, '��')");
        query.exec("insert into dictionary values(460, '��')");
        query.exec("insert into dictionary values(461, '��')");
        query.exec("insert into dictionary values(462, 'Щ')");
        query.exec("insert into dictionary values(463, '��')");
        query.exec("insert into dictionary values(464, '��')");
        query.exec("insert into dictionary values(465, '��')");
        query.exec("insert into dictionary values(466, '��')");
        query.exec("insert into dictionary values(467, '��')");
        query.exec("insert into dictionary values(468, '��')");
        query.exec("insert into dictionary values(469, '��')");
        query.exec("insert into dictionary values(470, '��')");
        query.exec("insert into dictionary values(471, '��')");
        query.exec("insert into dictionary values(472, '��')");
        query.exec("insert into dictionary values(473, '��')");
        query.exec("insert into dictionary values(474, '��')");
        query.exec("insert into dictionary values(475, '��')");
        query.exec("insert into dictionary values(476, '��')");
        query.exec("insert into dictionary values(477, '��')");
        query.exec("insert into dictionary values(478, '��')");
        query.exec("insert into dictionary values(479, '��')");
        query.exec("insert into dictionary values(480, '��')");
        query.exec("insert into dictionary values(481, '��')");
        query.exec("insert into dictionary values(482, 'װ')");
        query.exec("insert into dictionary values(483, '��')");
        query.exec("insert into dictionary values(484, '��')");
        query.exec("insert into dictionary values(485, '¥')");
        query.exec("insert into dictionary values(486, 'ʩ')");
        query.exec("insert into dictionary values(487, '��')");
        query.exec("insert into dictionary values(488, 'Ӱ')");
        query.exec("insert into dictionary values(489, '��')");
        query.exec("insert into dictionary values(490, '��')");
        query.exec("insert into dictionary values(491, '��')");
        query.exec("insert into dictionary values(492, '��')");
        query.exec("insert into dictionary values(493, '��')");
        query.exec("insert into dictionary values(494, '��')");
        query.exec("insert into dictionary values(495, 'ת')");
        query.exec("insert into dictionary values(496, '��')");
        query.exec("insert into dictionary values(497, '��')");
        query.exec("insert into dictionary values(498, '��')");
        query.exec("insert into dictionary values(499, '��')");
        query.exec("insert into dictionary values(500, 'ֵ')");

    }
}

void database::closedb()
{
    db.close();
}

QString userid;


