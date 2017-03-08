#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtMultimedia/QMediaPlayer>

namespace Ui {
class MainWindow;
}
class QListWidgetItem;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_br_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private: // khai bao lớp ở đây để sdung toàn cục
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QTextStream *out;
};

#endif // MAINWINDOW_H
