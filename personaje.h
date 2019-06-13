#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QPen>
#include "vista.h"
//#include "arraylist.h"
//#include "rectangle.h"

class Personaje: public QGraphicsRectItem{


public:
    ArrayList<Rectangle*> *lista;
    int posX;
    int posY;
    int pos;
    Rectangle* actual;
    vista *vista;

    Personaje(int posX,int posY, int pos,ArrayList<Rectangle*> *lista,class vista *vista){
        this->posX=posX;
        this->posY=posY;
        this->pos=pos;
        this->lista=lista;
        setRect(posX,posY,20,20);\
        this->vista=vista;


    }

    Personaje(int posX,int posY, int pos,ArrayList<Rectangle*> *lista,Rectangle* actual){
        this->posX=posX;
        this->posY=posY;
        this->pos=pos;
        this->lista=lista;
        this->actual=actual;
        setRect(posX,posY,20,20);

    }



void keyPressEvent(QKeyEvent *event)//metodo para el manejo con los botones
    {
        if(event->key() == Qt::Key_Left){
            if(actual->getLeft()!=NULL){
                setPos(x()-20,y());
                actual=actual->getLeft();
                if(actual->getManzanita()){
                       actual->setManzanita(false);
                       actual->setBrush(Qt::green);
                }

            }
        }

        else if(event->key() == Qt:: Key_Right){
            if(actual->getRight()!=NULL){
                setPos(x()+20,y());
                actual=actual->getRight();
                if(actual->getManzanita()){
                       actual->setManzanita(false);
                       actual->setBrush(Qt::green);
                }
                if(actual->getIsFinal()){


                }
            }
        }

        else if (event->key() == Qt:: Key_Down) {
            if(actual->getDown()!=NULL){
                setPos(x(),y()+20);
                actual=actual->getDown();
                if(actual->getManzanita()){
                       actual->setManzanita(false);
                       actual->setBrush(Qt::green);
                }
                if(actual->getIsFinal()){

                }
            }
        }

        else if (event->key() == Qt:: Key_Up) {
            if(actual->getUp()!=NULL){
                setPos(x(),y()-20);
                actual=actual->getUp();
                if(actual->getManzanita()){
                       actual->setManzanita(false);
                       actual->setBrush(Qt::green);
                }
            }
        }
}



};

#endif // PERSONAJE_H
