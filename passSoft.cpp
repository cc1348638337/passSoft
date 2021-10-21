#include "widget_play_music.h"
#include "ui_widget_play_music.h"
#include <QKeyEvent>
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>
#include <QByteArray>
#include <QSslConfiguration>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QTextToSpeech>

Widget_Play_Music::Widget_Play_Music(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Play_Music)
{
    ui->setupUi(this);
    delay = new QTimer(this);
    connect(delay,&QTimer::timeout,this,&Widget_Play_Music::clearInfo);
    QPalette pa3;
    pa3.setColor(QPalette::WindowText,Qt::blue);
    ui->resultLabel->setPalette(pa3);
    ui->resultLabel->setText("请扫码");
//    ui->resultLabel->adjustSize();

    /*
     * 两种使用QMediaPlayer播放音乐的方法
     *
     * 可以更具自己需要，使用
     *
     * 使用时将已注释的放开，后面的注视掉就可以了
     */



//    {
//        player = new QMediaPlayer;
//        //connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
//        player->setMedia(QUrl::fromLocalFile("D:\\KwDownload\\song\\张惠妹-连名带姓.mp3"));
//        player->setVolume(100);
//        player->play();
//    }




//    {
//        playlist = new QMediaPlaylist;
//        playlist->addMedia(QUrl::fromLocalFile("D:\\KwDownload\\song\\张惠妹-连名带姓.mp3"));
//        playlist->addMedia(QUrl::fromLocalFile("E:\\CloudMusic\\芭比 - 触电 (完整版).mp3"));
//        playlist->addMedia(QUrl::fromLocalFile("E:\\CloudMusic\\郭芯语 - 快点告诉你.mp3"));
//        playlist->setCurrentIndex(1);

//        player = new QMediaPlayer;
//        player->setPlaylist(playlist);

//        player->play();
//    }

//    QUrl url;
//    m_AccessManager = new QNetworkAccessManager(this);
//    url.setUrl(Info);
//    QSslConfiguration config;
//    config.setPeerVerifyMode(QSslSocket::VerifyNone);
//    config.setProtocol(QSsl::TlsV1SslV3);
//    m_Request.setSslConfiguration(config);
//    m_Request.setUrl(url);
//    QByteArray sendData;
//    sendData = QString::fromStdString("ip=27.106.204.0").toLocal8Bit();
//    m_Request.setRawHeader("Accept","*/*");
//    m_Request.setRawHeader("Accept-Language","zh-CN,zh;q=0.9");
//    m_Request.setRawHeader("Content-Type","application/x-www-form-urlencoded");
//    m_Request.setRawHeader("User-Agent","Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.181 Safari/537.36");
//    m_Request.setRawHeader("X-Requested-With:","XMLHttpRequest");
//    m_Request.setRawHeader("Referer","http://ip.taobao.com/ipSearch.html");
//    m_Reply = m_AccessManager->post(m_Request,sendData);

//    connect(m_AccessManager,&QNetworkAccessManager::finished,this,&Widget_Play_Music::ReplyReadFunc);
}

Widget_Play_Music::~Widget_Play_Music()
{
    player->stop();
    delete ui;
}
void Widget_Play_Music::pass(){
//    player = new QMediaPlayer;
//    //connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
//    player->setMedia(QUrl::fromLocalFile("D:\\KwDownload\\song\\周杰伦-你怎么连话都说不清楚(Live).flac"));
//    player->setVolume(100);
//    player->play();
    QTextToSpeech *tts = new QTextToSpeech(this);
    tts->say("验证成功");
    delay->start(3000);
}
void Widget_Play_Music::notPass()
{
    QTextToSpeech *tts = new QTextToSpeech(this);
    tts->say("验证失败");
    delay->start(3000);
//    player = new QMediaPlayer;
//    //connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
//    player->setMedia(QUrl::fromLocalFile("D:\\KwDownload\\song\\张惠妹-连名带姓.mp3"));
//    player->setVolume(100);
//    player->play();
}
void Widget_Play_Music::clearInfo(){
    ui->nameLabel->setText("姓名：");
    ui->genderLabel->setText("性别：");
    ui->picLabel->clear();
    QPalette pa3;
    pa3.setColor(QPalette::WindowText,Qt::blue);
    ui->resultLabel->setPalette(pa3);
    ui->resultLabel->setText("请扫码");
    delay->stop();
}
void Widget_Play_Music::keyPressEvent(QKeyEvent *event){
    if(event->key() ==Qt::Key_Return){
        //QDesktopServices::openUrl(QUrl(QString(Info)));
        getInfo();
        qDebug()<<Info;
        Info.clear();
        Info = "http://we.buu123.com/api2/GoCard/goCheck.php?key=";
    }else {
        Info.append(event->key());
        Info = Info.replace(QString(" "),QString(""));
    }
}
void Widget_Play_Music::getInfo() {
//    QNetworkRequest request;
//    QNetworkAccessManager* naManager = new QNetworkAccessManager(this);
//    QMetaObject::Connection connRet = QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));
//    Q_ASSERT(connRet);

//    request.setUrl(QUrl(Info));
//    QNetworkReply* reply = naManager->get(request);

    QUrl url;
    m_AccessManager = new QNetworkAccessManager(this);
    url.setUrl(Info);
    QSslConfiguration config;
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    config.setProtocol(QSsl::TlsV1SslV3);
    m_Request.setSslConfiguration(config);
    m_Request.setUrl(url);
    QByteArray sendData;
    sendData = QString::fromStdString("ip=27.106.204.0").toLocal8Bit();
    m_Request.setRawHeader("Accept","*/*");
    m_Request.setRawHeader("Accept-Language","zh-CN,zh;q=0.9");
    m_Request.setRawHeader("Content-Type","application/x-www-form-urlencoded");
    m_Request.setRawHeader("User-Agent","Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.181 Safari/537.36");
    m_Request.setRawHeader("X-Requested-With:","XMLHttpRequest");
    m_Request.setRawHeader("Referer","http://ip.taobao.com/ipSearch.html");
    m_Reply = m_AccessManager->post(m_Request,sendData);

    connect(m_AccessManager,&QNetworkAccessManager::finished,this,&Widget_Play_Music::ReplyReadFunc);
}
void Widget_Play_Music::requestFinished(QNetworkReply* reply) {
//    // 获取http状态码
//    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
//    if(statusCode.isValid())
//        qDebug() << "status code=" << statusCode.toInt();

//    QVariant reason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
//    if(reason.isValid())
//        qDebug() << "reason=" << reason.toString();

//    QVariant name = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
//    if(name.isValid())
//        qDebug() << "name=" << name.toString();

//    QVariant gender = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute);
//    if(gender.isValid())
//        qDebug() << "gender=" << gender.toString();

//    QVariant pic = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute);
//    if(pic.isValid())
//        qDebug() << "pic=" << pic.toString();

//    QNetworkReply::NetworkError err = reply->error();
//    if(err != QNetworkReply::NoError) {
//        qDebug() << "Failed: " << reply->errorString();
//    }
//    else {
//        // 获取返回内容
//        qDebug() << reply->readAll();
//    }
}
void Widget_Play_Music::ReplyReadFunc(QNetworkReply* Reply)
{
    int NetworkErrors = -1;
    NetworkErrors = Reply->error();
    int code;
    QString name;
    QString pic;
    QString gender;
    QString information;

    if(NetworkErrors ==QNetworkReply::NoError)
    {
        QByteArray databuff = Reply->readAll();
        QString result = QString::fromStdString(databuff.toStdString()).toUtf8();
        QJsonDocument document;
        QJsonParseError ParseError;
        document =QJsonDocument::fromJson(result.toUtf8(),&ParseError);
        if(!document.isNull() && ParseError.error == QJsonParseError::NoError)
        {
            if(document.isObject())
            {
                QJsonObject Object = document.object(); //获取文档对象
                if(!Object.isEmpty())
                {
                    qDebug()<<Object;

                    if(Object.contains("code")){ //先判断有没有
                        QJsonValue codeVal = Object.value("code");
                        code = codeVal.toInt();
                        qDebug() << code;
                        if(code == 200){
                            pass();
                            QPalette pa2;
                            pa2.setColor(QPalette::WindowText,Qt::green);
                            ui->resultLabel->setPalette(pa2);
                            ui->resultLabel->setText("验证通过");
                        }else {
                            notPass();
                            QPalette pa;
                            pa.setColor(QPalette::WindowText,Qt::red);
                            ui->resultLabel->setPalette(pa);
                            ui->resultLabel->setText("验证失败");

                              }
                        }

                    if(Object.contains("userinfo")) //先判断有没有
                    {
                        QJsonValue dataObj = Object.value("userinfo");
                        if(dataObj.isObject())  //判断是否是对象
                        {
                            QJsonObject ObjectData = dataObj.toObject();
                            if(ObjectData.contains("name"))
                            {
                                QJsonValue nameVal = ObjectData.value("name");
                                if(nameVal.isString())
                                {
                                    name = nameVal.toString();
                                    ui->nameLabel->setText("名字："+name);
                                }
                            }
                            if(ObjectData.contains("gender"))
                            {
                                QJsonValue genderVal = ObjectData.value("gender");
                                if(genderVal.isString())
                                {
                                    gender = genderVal.toString();
                                    ui->genderLabel->setText("性别："+gender);

                                }
                            }
                            if(ObjectData.contains("pic"))
                            {
                                QJsonValue picVal = ObjectData.value("pic");
                                if(picVal.isString())
                                {
                                    pic = picVal.toString();
                                    qDebug()<<pic;
                                    setNetworkPic(pic);
                                }
                            }
                        }
                    }
                }
            }
//            information+="code:"+code;
//            information+="性别:"+gender;
//            information+="名字:"+name;
//            information+="图片:"+pic;

//            qDebug()<<information.toStdString().c_str();
        }
    }
}
void Widget_Play_Music::setNetworkPic(const QString &szUrl)
{
    QUrl url(szUrl);
    QNetworkAccessManager manager;
    QEventLoop loop;

    // qDebug() << "Reading picture form " << url;
    QNetworkReply *reply = manager.get(QNetworkRequest(url));
    //请求结束并下载完成后，退出子事件循环
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    //开启子事件循环
    loop.exec();

    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    pixmap.scaled(ui->picLabel->size(),Qt::KeepAspectRatio);
    ui->picLabel->setScaledContents(true);
    ui->picLabel->setPixmap(pixmap); // 你在QLabel显示图片
}
