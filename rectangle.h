#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QPen>


class Rectangle:public QGraphicsRectItem
{
public: 
    int num;
    Rectangle *up=NULL;
    Rectangle *down=NULL;
    Rectangle *left=NULL;
    Rectangle *right=NULL;
    int posX=0;
    int posY=0;

    Rectangle();
    Rectangle(int posX,int posY){
        this->posX=posX;
        this->posY=posY;
        setRect(posX,posY,20,20);
        setFlag(QGraphicsItem::ItemIsFocusable);

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

    void keyPressEvent(QKeyEvent *event)
    {
        if(event->key() == Qt::Key_Left){
            Rectangle *cubito=this->left;
            cubito->setBrush(Qt::yellow);


        }
        else if(event->key() == Qt:: Key_Right){

        }
        else if (event->key() == Qt:: Key_Down) {

        }

        else if (event->key() == Qt:: Key_Up) {

        }


    }







};

#endif // RECTANGLE_H
