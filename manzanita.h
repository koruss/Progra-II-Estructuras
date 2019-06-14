#ifndef MANZANITA_H
#define MANZANITA_H
#include <QGraphicsPixmapItem>

class Manzanita:public QGraphicsPixmapItem{


public:
    int posX;
    int posY;
    int zValue;

    Manzanita(int posX,int posY,int zValue){
        this->posX=posX;
        this->posY=posY;
        this->zValue=zValue;
        // setea la posicion

        //cambia la imagen
        setPixmap(QPixmap(":/images/bateria.png").scaled(20,20));
        setPos(posX,posY);
        setZValue(zValue);

   }






};


#endif // MANZANITA_H
