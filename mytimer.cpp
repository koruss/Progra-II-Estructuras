#include "mytimer.h"
#include <QDebug>
#include "vista.h"
#include <QGraphicsTextItem>
#include <QGraphicsScene>


extern vista *juego;
extern int score;

MyTimer::MyTimer(/*QObject* parent,QGraphicsScene *scene*/)
{
    this->texto=texto;
//    this->scene=new QGraphicsScene();
//    this->scene=scene;
    //int playtime = 100;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(MySlot(/**scene*/)));
    timer->start(1000);

}

int MyTimer::getPlaytime()
{
    return playtime;
}

void MyTimer::setPlaytime(int value)
{
    playtime = value;
}


void MyTimer::MySlot(/*QGraphicsScene *scene*/)
{
    //qDebug()<<"Time left: "<<playtime;
    QString s = QString::number(playtime);
    QString textito = "Tiempo restante: ";
    textito.append(s);
    textito.append("                              ");
    textito.append(juego->laberinto->tipoLaberinto);

    juego->setWindowTitle(textito);



   if(playtime==0){

       juego->pantallaFinal();
       timer->stop();

   }
   playtime--;
}

void MyTimer::modifyTime(int timeAdded)
{
    playtime += timeAdded;
}
