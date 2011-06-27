#include <vlc/vlc.h>
#include <QtGui/QApplication>
#include <QtCore/QDebug>
#include <QMutex>
#include <QWaitCondition>
#include <QDir>
#include <QFile>

#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <string>
class player
{
    public:

        player(const char* url, const char* TmpFile = NULL)
        {
            if(TmpFile)
            {
                char result[1000];   // array to hold the result.
//                QFile file(QDir::tempPath() + "\\myTmp.mpg");
//                if (file.open())
//                {
//                    tmpFileName = QDir::tempPath() + "/myTmp.mpg";
//                    const char* TmpFile = (char*)tmpFileName.toStdString().data();

                    strcpy(result,"--sout=file/ps:"); // copy string one into the result.
                    strcat(result,TmpFile); // append string two to the result.
                    qDebug() << QString(TmpFile);
//                }
//                else
//                {
//                    tmpFileName = "";
//                    qDebug() << "cant open temp file";
//                }

                const char * const vlc_args[] = {
                      "-I", "dummy", // Don't use any interface
                      "--ignore-config", // Don't use VLC's config
                      "--extraintf=logger", // Log anything
                      "--verbose=2", // Be much more verbose then normal for debugging purpose
                      result  // Stream to file
                       };
                // We launch VLC
                inst = libvlc_new(sizeof(vlc_args) / sizeof(vlc_args[0]), vlc_args);
            }
            else
            {
                qDebug() << "libvlc_new(0, NULL)";
                inst = libvlc_new(0, NULL);
            }
            // Check if instance is running
            if(inst) {
                qDebug() << "libvlc-qt initialised by " << QString(url);
            } else {
                qDebug() << "libvlc-qt Error: libvlc failed to load!";
                exit(-100);
            }
            /* Create a new item */
            m = libvlc_media_new_path (inst, url);

            /* Create a media player playing environement */
            mp = libvlc_media_player_new_from_media (m);

            /* No need to keep the media now */
            libvlc_media_release (m);

            /* play the media_player */
            libvlc_media_player_play (mp);
        }
        //sleep (10); /* Let it play a bit */
        ~player()
        {
            /* Stop playing */
            libvlc_media_player_stop (mp);

            /* Free the media_player */
            libvlc_media_player_release (mp);

            libvlc_release (inst);
        }
        const char* getTmpFileName() const
        {
            return tmpFileName.toUtf8().data();
        }

    private:

        libvlc_instance_t * inst;
        libvlc_media_player_t *mp;
        libvlc_media_t *m;
        QString tmpFileName;

};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    player* pl1 = new player("http://scfire-ntc-aa06.stream.aol.com:80/stream/1011", "tmp.mpg");
    //const char* tmp = pl1->getTmpFileName();

    qDebug() << "waiting...";
    QMutex dummy;
    dummy.lock();
    QWaitCondition waitCondition;
    waitCondition.wait(&dummy, 4000);


    player* pl2 = new player("tmp.mpg");
    return a.exec();
}
