#include "arraylist.h"
#include <QApplication>
#include <QGraphicsScene>
#include "rectangle.h"
#include <QGraphicsView>


int main(int argc, char *argv[])
    {
    ArrayList<Rectangle*> *lista= new ArrayList<Rectangle*>;

    ArrayList<Rectangle*> *listaB= new ArrayList<Rectangle*>;



    //creo la estructura

    QApplication a(argc, argv);

    // crea una escena, es como un Contenedor
    QGraphicsScene * scene = new QGraphicsScene();
    lista->goToStart();
    for(int i=30;i<=200;i+=20){//tengo que cambiar la forma de crear los rectangulos
         for(int c=30;c<=200;c+=20){

             Rectangle * rect = new Rectangle();
             rect->setBrush(Qt::green);
             rect->setRect(c*2,i*2,20,20);

             //scene->addItem(rect);
             lista->append(rect);
        }
    }



    // add a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->setFixedSize(600,600);//el tamanio
    view->setBackgroundBrush(Qt::black);//el fondo

    lista->goToPos(12);
    lista->getElement()->setBrush(Qt::yellow);
    for(lista->goToStart();!lista->atEnd();lista->next()){
        scene->addItem(lista->getElement());
    }








    view->show();

    return a.exec();
}
