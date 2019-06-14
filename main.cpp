#include "arraylist.h"
#include <QApplication>
#include <QGraphicsScene>
#include "rectangle.h"
#include <QGraphicsView>
#include "vista.h"
#include "prim.h"
#include "grafomatriz.h"
#include "controlador.h"
#include <time.h>
#include "personaje.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>



vista *juego;
int score;


void playBackgroundMusic(){
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/bgsound.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();
}

int main(int argc, char *argv[])
    {
    srand(time(NULL));
    //creo la estructura
    QApplication a(argc, argv);
    juego=new vista(7);
    playBackgroundMusic();


    juego->show();

   // }
    return a.exec();



    }




