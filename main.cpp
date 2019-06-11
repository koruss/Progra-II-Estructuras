#include "arraylist.h"
#include <QApplication>
#include <QGraphicsScene>
#include "rectangle.h"
#include <QGraphicsView>
#include "vista.h"
#include "prim.h"
#include "grafomatriz.h"
#include "controlador.h"



int main(int argc, char *argv[])
    {
    ArrayList<Rectangle*> *lista= new ArrayList<Rectangle*>;
    //creo la estructura

    QApplication a(argc, argv);


    //cosas de los grafos :)
    Controlador cargar;
    GrafoMatriz vertice;
    LinkedList<string> *ListOfPrim=new LinkedList<string>();
    cargar.leerVertice(vertice);
    int V = vertice.numVerts;
    int numArcos=cargar.leerConexiones(vertice);
    ArbolExpansionMinimo prim(vertice);
    prim.arbolExpansionPrim(vertice, ListOfPrim);
    //ListOfPrim->print();





    vista *elementos = new vista();

    //creo una escena, como niño en supermercado
    QGraphicsScene * scene = new QGraphicsScene();

    //agrego la vista
    QGraphicsView * view = new QGraphicsView(scene);
    view->setFixedSize(1000,1000);//el tamanio
    view->setBackgroundBrush(Qt::black);//el fondo


    int size=5;// esta variable dice el tamanio del grafo, siempre son cuadrados

    elementos->crearGrafoInicial(size);//Crea el grafo matriz Inicial

    elementos->agregarEnEscena(scene);//mete los cuadritos en la


    elementos->crearParedes(scene, ListOfPrim, size);// crea las paredecitas

    view->show();





    return a.exec();
}
