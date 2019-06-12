#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QPen>
#include "arraylist.h"
#include "rectangle.h"


class Personaje: public QGraphicsRectItem{


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
        setRect(posX,posY,20,20);

    }

    Personaje(int posX,int posY, int pos,ArrayList<Rectangle*> *lista,Rectangle* actual){
        this->posX=posX;
        this->posY=posY;
        this->pos=pos;
        this->lista=lista;
        this->actual=actual;
        setRect(posX,posY,20,20);

    }





/*
   void keyPressEvent(QKeyEvent *event)//metodo para el manejo con los botones
    {
        if(event->key() == Qt::Key_Left){
            cout<<pos<<endl;
            lista->goToPos(pos);
            Rectangle *caja=lista->getElement();
            if(caja->getLeft()!=NULL){
                cambiarPos(caja->getLeft()->getPosX(),caja->getLeft()->getPosY());
                pos=pos-1;
            }
        }
        else if(event->key() == Qt:: Key_Right){
            cout<<pos<<endl;
            lista->goToPos(pos);
            Rectangle *caja=lista->getElement();
            if(caja->getRight()!=NULL){
                cambiarPos(caja->getRight()->getPosX(),caja->getRight()->getPosY());
                pos=pos+1;
            }
            else {
                cout<<"esta wea esta en NULL"<<endl;
            }
      }
        else if (event->key() == Qt:: Key_Down) {
            cout<<pos<<endl;
            lista->goToPos(pos);
            Rectangle *caja=lista->getElement();
            if(caja->getDown()!=NULL){
                cambiarPos(caja->getDown()->getPosX(),caja->getDown()->getPosY());
                pos=pos+sqrt(lista->getSize());
            }
            else {
                cout<<"esta wea esta en NULL"<<endl;
            }
        }

        else if (event->key() == Qt:: Key_Up) {
            cout<<pos<<endl;
            lista->goToPos(pos);
            Rectangle *caja=lista->getElement();
            if(caja->getUp()!=NULL){
                cambiarPos(caja->getUp()->getPosX(),caja->getUp()->getPosY());
                pos=pos-sqrt(lista->getSize());
            }
            else {
                cout<<"esta wea esta en NULL"<<endl;
            }
        }

    }


    void cambiarPos(int num1,int num2){
        setPos(num1,num2);
        posX=num1;
        posY=num2;
    }


*/


void keyPressEvent(QKeyEvent *event)//metodo para el manejo con los botones
    {
        if(event->key() == Qt::Key_Left){
            if(actual->getLeft()!=NULL){
                setPos(x()-20,y());
                actual=actual->getLeft();

            }
        }
        else if(event->key() == Qt:: Key_Right){
            if(actual->getRight()!=NULL){



                setPos(x()+20,y());
                actual=actual->getRight();
            }
        }
        else if (event->key() == Qt:: Key_Down) {
            if(actual->getDown()!=NULL){
                setPos(x(),y()+20);
                actual=actual->getDown();
            }
        }

        else if (event->key() == Qt:: Key_Up) {
            if(actual->getUp()!=NULL){
                setPos(x(),y()-20);
                actual=actual->getUp();
            }
        }
}





};

#endif // PERSONAJE_H
