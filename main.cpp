#include "arraylist.h"
#include <QApplication>
#include <QGraphicsScene>
#include "rectangle.h"
#include <QGraphicsView>
#include "vista.h"






//ArrayList<Rectangle*>* crearGrafoInicial(int size){
//    ArrayList<Rectangle*> *lista= new ArrayList<Rectangle*>;
//    int x= 20;
//    int y= 20;
//    int cont=0;
//    for(int i=0;i<size*size;i++){
//        if(cont==size){
//            y=y+40;
//            x=20;
//            cont=0;
//        }
//        Rectangle *rect= new Rectangle(x,y);
//        rect->setBrush(Qt::green);
//        lista->append(rect);
//        x+=40;
//        cont++;
//    }
//    return lista;


//}

//void crearParedes(ArrayList<Rectangle*> *lista,QGraphicsScene * scene){
//    for(int i=0;i<20;i+=2){
//        lista->goToPos(i);
//        Rectangle *cubito= lista->getElement();
//        cubito->setRight(new Rectangle(cubito->posX+20,cubito->posY));

//        cubito->right->setBrush(Qt::blue);

//        scene->addItem(cubito->right);
//    }

//}

//void crearParedes2(List<int> * lista,QGraphicsScene * scene){

//}




int main(int argc, char *argv[])
    {
    ArrayList<Rectangle*> *lista= new ArrayList<Rectangle*>;
    //creo la estructura

    QApplication a(argc, argv);

//    // crea una escena, es como un Contenedor
//    QGraphicsScene * scene = new QGraphicsScene();

//    // add a view to visualize the scene
//    QGraphicsView * view = new QGraphicsView(scene);
//    view->setFixedSize(1000,1000);//el tamanio
//    view->setBackgroundBrush(Qt::black);//el fondo

//    lista=crearGrafoInicial(10);//creo el grafo inicial con cualquier tama;io

//    lista->goToPos(1);
//    Rectangle *cubito= lista->getElement();
//    cubito->setBrush(Qt::yellow);

//    cubito->setRight(new Rectangle(cubito->posX+20,cubito->posY));

//    cubito->right->setBrush(Qt::blue);

//    scene->addItem(cubito->right);


//    lista->goToPos(2);


//    Rectangle *cubito2= lista->getElement();
// //   cubito2->setBrush(Qt::yellow);

//    cubito2->setRight(new Rectangle(cubito2->posX,cubito2->posY+20));

//    cubito2->right->setBrush(Qt::blue);

//    scene->addItem(cubito2->right);

//    for(lista->goToStart();!lista->atEnd();lista->next()){
//        scene->addItem(lista->getElement());
//    }
//    crearParedes(lista,scene);

//    view->show();



    vista *elementos = new vista();
    QGraphicsScene * scene = new QGraphicsScene();

    QGraphicsView * view = new QGraphicsView(scene);
    view->setFixedSize(1000,1000);//el tamanio
    view->setBackgroundBrush(Qt::black);//el fondo

    elementos->crearGrafoInicial(15);
    elementos->agregarEnEscena(scene);

    view->show();





    return a.exec();
}
