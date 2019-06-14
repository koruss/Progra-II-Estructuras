#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QPen>
#include "arraylist.h"
#include "rectangle.h"



class Personaje: public QGraphicsPixmapItem{


public:
    ArrayList<Rectangle*> *lista;
    int posX;
    int posY;
    int pos;
    Rectangle* actual;


    Personaje(int posX,int posY, int pos,ArrayList<Rectangle*> *lista){
        this->posX=posX;
        this->posY=posY;
        this->pos=pos;
        this->lista=lista;
        //setRect(posX,posY,20,20);\
        //this->vista=vista;
        setPixmap(QPixmap(":/images/spaceCowboy.png").scaled(20,20));
        setPos(posX,posY);
        setZValue(12);
    }

    Personaje(int posX,int posY, int pos,ArrayList<Rectangle*> *lista,Rectangle* actual){
        this->posX=posX;
        this->posY=posY;
        this->pos=pos;
        this->lista=lista;
        this->actual=actual;
        setPixmap(QPixmap(":/images/spaceCowboy.png").scaled(20,20));
        setPos(posX,posY);
        setZValue(12);

    }





//void keyPressEvent(QKeyEvent *event)//metodo para el manejo con los botones
//    {
//        if(event->key() == Qt::Key_Left){
//            if(actual->getLeft()!=NULL){
//                setPos(x()-10,y());
//                setPos(x()-10,y());
//                actual=actual->getLeft();
//                if(actual->getManzanita()){
//                       actual->setManzanita(false);
//                       actual->setBrush(Qt::green);
//                }
//                if(actual->getIsFinal()){

//                    exit(5);
//                }
//            }
//        }

//        else if(event->key() == Qt:: Key_Right){
//            if(actual->getRight()!=NULL){
//                setPos(x()+10,y());
//                setPos(x()+10,y());
//                actual=actual->getRight();
//                if(actual->getManzanita()){
//                       actual->setManzanita(false);
//                       actual->setBrush(Qt::green);
//                }
//                if(actual->getIsFinal()){
//                    exit(5);


//                }
//            }
//        }

//        else if (event->key() == Qt:: Key_Down) {
//            if(actual->getDown()!=NULL){
//                setPos(x(),y()+10);
//                setPos(x(),y()+10);
//                actual=actual->getDown();
//                if(actual->getManzanita()){
//                       actual->setManzanita(false);
//                       actual->setBrush(Qt::green);
//                }
//                if(actual->getIsFinal()){
//                    exit(5);
//                }
//            }
//        }

//        else if (event->key() == Qt:: Key_Up) {
//            if(actual->getUp()!=NULL){
//                setPos(x(),y()-10);
//                setPos(x(),y()-10);
//                actual=actual->getUp();
//                if(actual->getManzanita()){
//                       actual->setManzanita(false);
//                       actual->setBrush(Qt::green);
//                }
//                if(actual->getIsFinal()){
//                    exit(5);
//                }
//            }
//        }
//}



};

#endif // PERSONAJE_H
