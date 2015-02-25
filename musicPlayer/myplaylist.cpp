#include "myplaylist.h"
#include <QContextMenuEvent>
#include <QMenu>


MyPlaylist::MyPlaylist(QWidget *parent) :
    QTableWidget(parent)
{
    //setWindowTitle(tr("�����б�"));
    //����Ϊһ�������Ĵ��ڣ���ֻ��һ���رհ�ť
    //setWindowFlags(Qt::Window | Qt::WindowTitleHint);

    //resize(400, 400);
    //setMaximumWidth(400);
    //setMinimumWidth(400);//�̶����ڴ�С

    //resize(parent->height(),
    //       parent->width());

    setRowCount(0);//��ʼ������Ϊ0
    setColumnCount(3);//��ʼ������Ϊ1

    //���õ�һ����ǩ
    QStringList list;
    list << tr("����") << tr("����") << tr("����");
    setHorizontalHeaderLabels(list);

    setSelectionMode(QAbstractItemView::SingleSelection);//����ֻ��ѡ����
    setSelectionBehavior(QAbstractItemView::SelectRows);

    setShowGrid(false);//���ò���ʾ����
}


void MyPlaylist::clear_play_list()
{
    while(rowCount())
    {
        removeRow(0);
    }

    QSqlQuery query;
    query.exec("delete from music");

    emit play_list_clean();//ɾ����󣬷�����ճɹ��ź�
}

void MyPlaylist::del_play_list()
{
    int curRow = currentIndex().row(); //��ȡѡ�е���

    QSqlQuery query;
    QString mtitle = item(curRow, 0)->data(Qt::DisplayRole).toString();
    QString msinger = item(curRow, 1)->data(Qt::DisplayRole).toString();
    QString mlength = item(curRow, 2)->data(Qt::DisplayRole).toString();
    query.exec("delete from music where mtitle = '" + mtitle + "' and msinger = '" + msinger + "' and mlength = '" + mlength + "'");

    removeRow(curRow); //ɾ������

    emit play_list_delete(curRow);//ɾ����󣬷���ɾ���ɹ��ź�
}


void MyPlaylist::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu;
    menu.addAction(tr("ɾ������"), this, SLOT(del_play_list()));//����ֱ��������ָ���ۺ���
    menu.addAction(tr("����б�"), this, SLOT(clear_play_list()));//����ֱ��������ָ���ۺ���
    menu.exec(event->globalPos());//�������ָ���ȫ��λ��
}


void MyPlaylist::closeEvent(QCloseEvent *event)
{
    if(isVisible()) {
        hide();
        event->ignore();//������ձ�־
    }
}
