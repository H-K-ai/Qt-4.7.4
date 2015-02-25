#ifndef MUSICDIALOG_H
#define MUSICDIALOG_H

#include <QDialog>
#include "myfunc.h"

namespace Ui {
    class musicDialog;
}

class musicDialog : public QDialog
{
    Q_OBJECT

public:
    explicit musicDialog(QWidget *parent = 0);
    ~musicDialog();

    Phonon::SeekSlider *seekSlider;//����������
    Phonon::MediaObject *mediaObject;//����ý����Դ
    Phonon::AudioOutput *audioOutput;//���������豸
    Phonon::VolumeSlider *volumeSlider;//����
    QToolBar *bar;
    QLCDNumber *timeLcd;//LCD��

    QAction *playAction;
    QAction *pauseAction;
    QAction *stopAction;

    QSqlTableModel *currentTableModel;
    QTableView *currentView;

    void closeEvent(QCloseEvent *);

    void paintEvent(QPaintEvent *);

signals:
    void addMusic();

private slots:
    void stateChanged(Phonon::State newState, Phonon::State oldState);
    void tick(qint64 time);
    void sourceChanged(const Phonon::MediaSource &source);
    void aboutToFinish();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::musicDialog *ui;
};

#endif // MUSICDIALOG_H
