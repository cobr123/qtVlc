/* libVLC and Qt sample code
 * Copyright © 2009 Alexander Maringer <maringer@maringer-it.de>
 */

#include "vlc_on_qt.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Player p;
    p.resize(640,480);
    p.playFile("http://88.191.111.120:8006"); // Replace with what you want to play
    p.show();
    return a.exec();
}

/*#include <vlc/vlc.h>
#include <vlc/libvlc.h>
#include <QtGui/QApplication>
#include <QtCore/QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    libvlc_instance_t *_vlcInstance = NULL;

    // Create new libvlc instance
    _vlcInstance = libvlc_new(0, NULL);


    // Check if instance is running
    if(_vlcInstance) {
        qDebug() << "libvlc-qt initialised";
        qDebug() << "Using libvlc version:";
    } else {
            qDebug() << "libvlc-qt Error: libvlc failed to load!";
            exit(-100);
    }
    return a.exec();
}*/
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
