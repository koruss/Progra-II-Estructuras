#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QPen>


class Rectangle:public QGraphicsRectItem
{//Herencia de la clase QGraphicsRectItem

public:     //atributos de la clase
    int num;
    Rectangle *up;
    Rectangle *down;
    Rectangle *left;
    Rectangle *right;
    int posX=0;
    int posY=0;

    Rectangle(){//Constructor inicial

    }
    Rectangle(int posX,int posY){//Este constructor inicializa los atributos y establece el tamanio del rectangulo
        this->posX=posX;
        this->posY=posY;
        setRect(posX,posY,20,20);
        setFlag(QGraphicsItem::ItemIsFocusable);
        this->up=NULL;
        this->down=NULL;
        this->right=NULL;
        this->left=NULL;

    }



    void keyPressEvent(QKeyEvent *event)//metodo para el manejo con los botones
    {
        if(event->key() == Qt::Key_Left){
            Rectangle *cubito=this->left;
            cubito->setBrush(Qt::yellow);
            this->clearFocus();
            cubito->setFocus();
            this->setBrush(Qt::green);
        }
        else if(event->key() == Qt:: Key_Right){
            Rectangle *cubito=this->right;
            cubito->setBrush(Qt::yellow);
            this->clearFocus();
            cubito->setFocus();
            this->setBrush(Qt::green);

        }
        else if (event->key() == Qt:: Key_Down) {
            Rectangle *cubito=this->down;
            cubito->setBrush(Qt::yellow);
            this->clearFocus();
            cubito->setFocus();
            this->setBrush(Qt::green);

        }

        else if (event->key() == Qt:: Key_Up) {
            Rectangle *cubito=this->up;
            cubito->setBrush(Qt::yellow);
            this->clearFocus();
            cubito->setFocus();
            this->setBrush(Qt::green);

        }


    }






    void setUp(Rectangle* pUp){
        this->up=pUp;
    }
    void setDown(Rectangle* down){
        this->down=down;
    }
    void setRight(Rectangle* right){
        this->right=right;
    }

    void setLeft(Rectangle* left){
        this->left=left;
    }

    Rectangle *getUp()
    {
        return up;
    }

    Rectangle *getDown()
    {
        return down;
    }

    Rectangle *getLeft()
    {
        return left;
    }

    Rectangle *getRight()
    {
        return right;
    }

    int getPosX()
    {
        return posX;
    }

    void setPosX(int value)
    {
        posX = value;
    }

    int getPosY()
    {
        return posY;
    }

    void setPosY(int value)
    {
        posY = value;
    }

};

#endif // RECTANGLE_H
