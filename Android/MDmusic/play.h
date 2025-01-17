#ifndef PLAY_H
#define PLAY_H

#include <QWidget>
#include <QStandardItemModel>
#include <QPushButton>
#include <QNetworkAccessManager>    //加载网络请求头文件
#include <QNetworkReply>
#include <QNetworkRequest>      //加载发送请求头文件
#include <QDebug>
#include <QFile>
#include <QTableView>
#include<QVector>
#include <QMediaPlayer>
#include <QFileDialog>
#include "music.h"
namespace Ui {
class Play;
}

class Play : public QWidget
{
    Q_OBJECT

public:
    explicit Play(QWidget *parent = 0);
    QMediaPlayer *player;
    MUsic playNow;  //用于让MainWidget查看当前播放歌曲
    QVector<MUsic> music_list;
    QVector<MUsic> down_list;
    ~Play();
    void Transmit(MUsic music);
    void addMusic(MUsic music);
    void updateDuration(qint64 duration);//更新播放歌曲的时间
    void updatePosition(qint64 position);//接收歌曲位置改变，那么滑块的位置也要变
    void updateNowUi(QString name,QString songer);
    void updatePlay(bool who);
    void updateViewList();
    void init();
    void progressSetValue(int va);
    QString savePath;
private:
    Ui::Play *ui;
    QStandardItemModel *standItemModel;

    quint64 duratime;
    QString timeall;
    int playindex;  //记录循环序列
    QString mode;


private slots:
    void slotNext();
    void on_horizontalSlider_sliderMoved(int position);

    void on_play_clicked();
     void freshViewList();

     void on_pushButton_4_clicked();

     void on_pushButton_3_clicked();

     void on_pushButton_clicked();

     void on_pushButton_7_clicked();

     void on_pushButton_6_clicked();

     void on_pushButton_5_clicked();

     void on_pushButton_8_clicked();

     void on_pushButton_9_clicked();

signals:
    void playend();
    void playChanged();
    void playOne();
    void removeOne();
    void begin();
    void downland();


};

#endif // PLAY_H
