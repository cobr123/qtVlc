/* libVLC and Qt sample code
 * Copyright © 2009 Alexander Maringer <maringer@maringer-it.de>
 */
/*
#include "vlc_on_qt.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Player p;
    p.resize(640,480);
    p.playFile("http://scfire-ntc-aa06.stream.aol.com:80/stream/1011"); // Replace with what you want to play
    p.show();
    return a.exec();
}
*/
#include <vlc/vlc.h>
#include <QtGui/QApplication>
#include <QtCore/QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    libvlc_instance_t * inst;
    libvlc_media_player_t *mp;
    libvlc_media_t *m;

    /* Load the VLC engine */
    inst = libvlc_new (0, NULL);

    // Check if instance is running
    if(inst) {
        qDebug() << "libvlc-qt initialised";
    } else {
            qDebug() << "libvlc-qt Error: libvlc failed to load!";
            exit(-100);
    }
    /* Create a new item */
    m = libvlc_media_new_path (inst, "http://scfire-ntc-aa06.stream.aol.com:80/stream/1011");

    /* Create a media player playing environement */
    mp = libvlc_media_player_new_from_media (m);

    /* No need to keep the media now */
    libvlc_media_release (m);

    /* play the media_player */
    libvlc_media_player_play (mp);

    //sleep (10); /* Let it play a bit */

    /* Stop playing */
    //libvlc_media_player_stop (mp);

    /* Free the media_player */
    //libvlc_media_player_release (mp);

    //libvlc_release (inst);

    return a.exec();
}
/*#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
*/
