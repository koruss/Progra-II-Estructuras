#ifndef META_H
#define META_H


#include <QGraphicsPixmapItem>

class Meta:public QGraphicsPixmapItem{


public:
    int posX;
    int posY;
    int zValue;

    Meta(int posX,int posY,int zValue){
        this->posX=posX;
        this->posY=posY;
        this->zValue=zValue;
        // setea la posicion

        //cambia la imagen
        setPixmap(QPixmap(":/images/meta.png").scaled(20,20));
        setPos(posX,posY);
        setZValue(zValue);

   }






};
#endif // META_H
