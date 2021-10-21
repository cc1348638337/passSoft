#include "widget_play_music.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget_Play_Music w;
    w.showFullScreen();

    return a.exec();
}
