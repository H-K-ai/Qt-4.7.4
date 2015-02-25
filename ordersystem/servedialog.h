#ifndef SERVEDIALOG_H
#define SERVEDIALOG_H

#include <QDialog>
#include <QMap>
#include <QVector>
#include <QList>
#include "dishlist.h"


namespace Ui {
class serveDialog;
}

class serveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit serveDialog(QWidget *parent = 0);
    ~serveDialog();

    void init();
    void show_desk_status();

private slots:
    void push_but();
    void status_change(int x);

private:
    Ui::serveDialog *ui;
    QMap<int,int> desk_sta_map;//��ȡ���ݿ����������ʱʹ��QMap

    QMap<int, QVector<int> > desk_dish_map;//����-�˵�


};

#endif // SERVEDIALOG_H
