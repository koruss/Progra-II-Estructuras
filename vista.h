#ifndef VISTA_H
#define VISTA_H
#include <QGraphicsView>
#include <QGraphicsScene>
//#include "rectangle.h"
//#include "personaje.h"
//#include "arraylist.h"
//#include "linkedlist.h"
//#include "prim.h"
//#include "controlador.h"
//#include "grafomatriz.h"
#include "laberinto.h"
#include "mythread.h"
#include "mytimer.h"
#include <QMediaPlayer>
#include <QThread>
#include <QImage>
#include <QDialog>
#include <QInputDialog>
#include "leaderBoard.h"
#include <cstdlib>

extern int score;

class vista: public QGraphicsView{

  /*
  *
  *                              ESTA ES LA CLASE QUE MANEJA EL JUEGO, AQUI ES DONDE SE CREAN TODAS LAS COSAS NECESARIAS PARA EL JUEGO
  *
  */


public:

    QGraphicsScene *scene;
    QGraphicsScene *scene2;
    Laberinto *laberinto;
    int tamanio;
    int dificultad = 0;
    QMediaPlayer *sonidito;

    MyTimer *cronito;
    LeaderBoard *leaderBoard;
    int playtime = 100;




    vista(int tam){


        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        this->tamanio=tam;
        this->leaderBoard=new LeaderBoard();
        //setFixedSize(1000,1000);
        setBackgroundBrush(QBrush(QImage(":/images/background.png")/*scaled(1000,1000)*/));
        scene=new QGraphicsScene();
        //scene2=new QGraphicsScene();
        //scene->setSceneRect(0,0,1000,1000);
//        scene2->setSceneRect(500,0,1000,1000);
        setScene(scene);

//        setScene(scene2);

        this->laberinto=new Laberinto(scene,tamanio);
        //setWindowTitle(laberinto->tipoLaberinto);

        this->sonidito = new QMediaPlayer();
        this->sonidito->setMedia(QUrl("qrc:/sounds/codecopen.wav"));

        //inicializar el thread
//        QThread *mThread = new QThread;
//        mThread->start();
//                //crear un timer
//                MyTimer *mTimer = new MyTimer();
//                //conectarlo al thread
//                //mTimer->moveToThread(this);
        this->cronito=new MyTimer();




        //inicializar el thread
        //QThread *mThread = new QThread;
        //mThread->start();
        //crear un timer
       // MyTimer *mTimer = new MyTimer(QGraphicsTextItem timeScreen);
        //conectarlo al thread
        //mTimer->moveToThread(mThread);


        //scene->addText(s);
//        QGraphicsTextItem *timeScreen = scene->addText(s);
//        timeScreen->setPos(50, 50);
    }






//    void crearTimer(){
//        //inicializar el thread
//        QThread *mThread = new QThread;
//        mThread->start();
//        //crear un timer
//        MyTimer *mTimer = new MyTimer();
//        //conectarlo al thread
//        mTimer->moveToThread(mThread);
//    }


    void keyPressEvent(QKeyEvent *event)//metodo para el manejo con los botones
        {
            if(event->key() == Qt::Key_Left){
                if(laberinto->actual->getLeft()!=NULL){
                    laberinto->personaje->setPos(laberinto->personaje->x()-20,laberinto->personaje->y());
                    laberinto->setActual(laberinto->actual->getLeft());

                    if(laberinto->getActual()->getManzanita()){
                           laberinto->getActual()->setManzanita(false);
                           laberinto->manzanitas--;
                           //playSoundEffect();
                           sonidito->play();                           
                           cronito->modifyTime(5);
                           laberinto->destruirManzanita(laberinto->getActual()->getPosX(),laberinto->getActual()->getPosY());

                    }

                    if(laberinto->getActual()->getIsFinal()&&laberinto->manzanitas==0){
                        close();
                        scene->clear();
                        //scene->addItem(timeScreen);
                        this->laberinto=new Laberinto(scene,tamanio+=2);
                        cronito->modifyTime(15);
                        score+=10;
                        dificultad++;
                        evaluarDificultad(dificultad);
                        //laberinto->destruirMeta();
                        show();



                    }
                }
            }

            else if(event->key() == Qt:: Key_Right){

                if(laberinto->actual->getRight()!=NULL){
                    laberinto->personaje->setPos(laberinto->personaje->x()+20,laberinto->personaje->y());
                    laberinto->setActual(laberinto->getActual()->getRight());


                    if(laberinto->getActual()->getManzanita()){
                           laberinto->getActual()->setManzanita(false);
                           //laberinto->getActual()->setBrush(Qt::green);
                           laberinto->manzanitas--;
                           //playSoundEffect();
                           sonidito->play();
                           cronito->modifyTime(5);
                           laberinto->destruirManzanita(laberinto->getActual()->getPosX(),laberinto->getActual()->getPosY());
                    }
                    if(laberinto->getActual()->getIsFinal()&& laberinto->manzanitas==0){
                        close();
                        this->scene->clear();
                        //scene->addItem(timeScreen);
                        this->laberinto=new Laberinto(scene,tamanio+=2);
                        cronito->modifyTime(15);
                        score+=10;
                        dificultad++;
                        evaluarDificultad(dificultad);
                        //laberinto->destruirMeta();
                        show();


                    }
                }
            }

            else if (event->key() == Qt:: Key_Down) {
                if(laberinto->getActual()->getDown()!=NULL){

                    laberinto->personaje->setPos(laberinto->personaje->x(),laberinto->personaje->y()+20);
                    laberinto->setActual(laberinto->getActual()->getDown());


                    if(laberinto->getActual()->getManzanita()){
                           laberinto->getActual()->setManzanita(false);
                           //laberinto->getActual()->setBrush(Qt::green);
                           laberinto->manzanitas--;
                           //playSoundEffect();
                           sonidito->play();
                           cronito->modifyTime(5);
                           laberinto->destruirManzanita(laberinto->getActual()->getPosX(),laberinto->getActual()->getPosY());
                    }
                    if(laberinto->getActual()->getIsFinal()&&laberinto->manzanitas==0){
                        close();
                        this->scene->clear();
                        //scene->addItem(timeScreen);
                        this->laberinto=new Laberinto(scene,tamanio+=2);
                        cronito->modifyTime(15);
                        score+=10;
                        dificultad++;
                        evaluarDificultad(dificultad);
                        //laberinto->destruirMeta();
                        show();

                    }
                }
            }

            else if (event->key() == Qt:: Key_Up) {
                if(laberinto->getActual()->getUp()!=NULL){
                    laberinto->personaje->setPos(laberinto->personaje->x(),laberinto->personaje->y()-20);
                    laberinto->setActual(laberinto->getActual()->getUp());


                    if(laberinto->getActual()->getManzanita()){
                           laberinto->getActual()->setManzanita(false);
                           //laberinto->getActual()->setBrush(Qt::green);
                           laberinto->manzanitas--;
                           //playSoundEffect();
                           sonidito->play();
                           cronito->modifyTime(5);
                           laberinto->destruirManzanita(laberinto->getActual()->getPosX(),laberinto->getActual()->getPosY());
                    }
                    if(laberinto->getActual()->getIsFinal()&&laberinto->manzanitas==0){
                        close();
                        this->scene->clear();
                        //scene->addItem(timeScreen);
                        this->laberinto=new Laberinto(scene,tamanio+=2);
                        cronito->modifyTime(15);
                        score+=10;
                        dificultad++;
                        evaluarDificultad(dificultad);
                        //laberinto->destruirMeta();
                        show();

                    }
                }
            }
            else if(event->key()==Qt::Key_H){
                //laberinto->dibujarCamino(sqrt(laberinto->lista->getSize()));
            }
    }

    int evaluarDificultad(int dificultad){
        if(dificultad<3){
            cronito->modifyTime(10);
        }
        else if(dificultad<5 && dificultad>2){
            cronito->modifyTime(12);
        }
        else if(dificultad<7 && dificultad>4){
            cronito->modifyTime(15);
        }
        else if(dificultad>6){
            cronito->modifyTime(18);
        }
    }

    void pantallaFinal(){
        setFixedSize(1500,1000);
        setBackgroundBrush(QBrush(QImage(":/images/gameOver.jpg")/*.scaled(1000,1000)*/));
        scene=new QGraphicsScene();
        scene->setSceneRect(0,0,1500,1000);
        QGraphicsTextItem *textito=new QGraphicsTextItem();
        QString texto="Te has quedado sin tiempo.\n\n";
        texto.append("Score: ");
        texto.append(QString::number(score));
        textito->setPlainText(texto);
        textito->setDefaultTextColor(Qt::white);
        textito->setFont(QFont("times",24));
        textito->setPos(500,300);
        scene->addItem(textito);
        setScene(scene);
        QString leader=recibirNombre();


    }

    QString recibirNombre(){
        bool ok;
        QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                                 tr("User name:"), QLineEdit::Normal,
                                                 QDir::home().dirName(), &ok);
            if (ok && !text.isEmpty())
                return text;
                //textLabel->setText(text);
    }





    void playSoundEffect(){
        if(sonidito->state()==QMediaPlayer::PlayingState){
            sonidito->setPosition(0);
            }
        else if(sonidito->state()==QMediaPlayer::StoppedState){
            sonidito->play();
            }
        }

signals:

/*public slots:
    void MySlot()
    {
       //qDebug()<<"Time left: "<<playtime;
       //QGraphicsScene *scene;
       QString s = QString::number(playtime);
       QGraphicsTextItem *timeScreen = scene->addText(s);
       timeScreen->setPos(50, 50);
       playtime--;
    }*/


};

#endif // VISTA_H
