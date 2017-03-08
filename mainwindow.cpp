#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTextStream>
#include<QFileDialog>
#include<QString>
#include<QFile>
#include<QtMultimedia/QMediaPlayer>
#include<QDir>
#include<QFileInfoList>
#include<QLabel>
#include<QMediaPlaylist>
#include<QMessageBox>
#include<QObject>
#include<QList>
#include<QListWidgetItem>
#include<QLinkedList>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(player);
    player->setPlaylist(playlist);
    QTextStream out (stdout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_br_clicked()
{
    ui->listWidget->clear();
    QTextStream out (stdout);
    QString directory = QFileDialog::getExistingDirectory(this,tr("Folder"));
    if(directory.isEmpty())
      return;
    playlist->clear();
    QDir dir(directory);
    QFileInfoList list = dir.entryInfoList(QStringList()<< "*.mp3"<<"*.mp4",QDir::Files,QDir::Time);

    for (int i = 1; i < list.size(); i++) {
        QFileInfo fileInfo = list.at(i);
        QString str = fileInfo.fileName();
        ui->listWidget->addItem(QString::number(i)+" "+str);
        QMediaContent absPath = fileInfo.absoluteFilePath();
        playlist->addMedia(absPath);
      }
}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    playlist->setCurrentIndex(index.row());
    player->play();

}
void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    ui->label->setText(item->text());
}
