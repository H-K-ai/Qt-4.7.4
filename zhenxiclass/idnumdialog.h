#ifndef IDNUMDIALOG_H
#define IDNUMDIALOG_H

#include <QDialog>
#include "common.h"

namespace Ui {
    class idnumDialog;
}

class idnumDialog : public QDialog
{
    Q_OBJECT

public:
    explicit idnumDialog(QWidget *parent = 0);
    ~idnumDialog();

    QSqlTableModel *currentTableModel;
    QTableView *currentView;

    void showEvent(QShowEvent *);

private slots:
    void on_pushButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::idnumDialog *ui;
};

#endif // IDNUMDIALOG_H
