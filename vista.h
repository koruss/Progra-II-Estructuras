#ifndef VISTA_H
#define VISTA_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "rectangle.h"
#include "arraylist.h"



class vista{

public:
    Rectangle *actual;
    Rectangle *final;
    Rectangle *inicial;
    ArrayList<Rectangle*> *lista;


    vista(){
        lista=new ArrayList<Rectangle*>;

    }

    void agregarEnEscena(QGraphicsScene* scene){
        for(lista->goToStart();!lista->atEnd();lista->next()){
            scene->addItem(lista->getElement());
        }
    }


    void crearParedes(QGraphicsScene* scene){
        for(int i=0;i<20;i+=2){
            lista->goToPos(i);
            Rectangle *cubito= lista->getElement();
            cubito->setRight(new Rectangle(cubito->posX+20,cubito->posY));

            cubito->right->setBrush(Qt::blue);

            scene->addItem(cubito->right);
        }

    }


    void crearGrafoInicial(int size){
        int x= 20;
        int y= 20;
        int cont=0;
        for(int i=0;i<size*size;i++){
            if(cont==size){
                y=y+40;
                x=20;
                cont=0;
            }
            Rectangle *rect= new Rectangle(x,y);
            rect->setBrush(Qt::green);
            this->lista->append(rect);
            x+=40;
            cont++;
        }
    }


};

#endif // VISTA_H
