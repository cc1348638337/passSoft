#ifndef WIDGET_PLAY_MUSIC_H
#define WIDGET_PLAY_MUSIC_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QTimer>

namespace Ui {
class Widget_Play_Music;
}

class Widget_Play_Music : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Play_Music(QWidget *parent = 0);
    ~Widget_Play_Music();

private:
    Ui::Widget_Play_Music *ui;
    QNetworkAccessManager *m_AccessManager;
    QMediaPlayer* player;
    QMediaPlaylist* playlist;
    QNetworkRequest m_Request;
    QNetworkReply *m_Reply;
    QTimer *delay;
    QString Info = "http://we.buu123.com/api2/GoCard/goCheck.php?key=";

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void getInfo();
    void requestFinished(QNetworkReply* reply);
    void ReplyReadFunc(QNetworkReply* Reply);
    void pass();
    void notPass();
    void setNetworkPic(const QString &szUrl);
    void clearInfo();
};

#endif // WIDGET_PLAY_MUSIC_H
