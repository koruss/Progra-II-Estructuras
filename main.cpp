#include "arraylist.h"
#include <QApplication>
#include <QGraphicsScene>
#include "rectangle.h"
#include <QGraphicsView>
#include "vista.h"
#include "prim.h"
#include "grafomatriz.h"
#include "controlador.h"
#include <time.h>


LinkedList<string> * crearPrim(){
    Controlador cargar;
    GrafoMatriz vertice;
    LinkedList<string> *ListOfPrim=new LinkedList<string>();
    cargar.leerVertice(vertice);
    int V = vertice.numVerts;
    int numArcos=cargar.leerConexiones(vertice);
    ArbolExpansionMinimo prim(vertice);
    prim.arbolExpansionPrim(vertice, ListOfPrim);
    return ListOfPrim;
}


LinkedList<string> *crearKruskal(){
    LinkedList<string> *ListOfKruskal=new LinkedList<string>();
    GrafoMatriz vertice;
    Controlador cargar;

    cargar.leerVertice(vertice);
    int V = vertice.numVerts;
    int numArcos=cargar.leerConexiones(vertice);
    int E = numArcos;

    Graph g(V,E);
    cargar.leerKruskal(g, V);
    g.kruskalMST();
    g.printMST(vertice, ListOfKruskal);
    //ListOfKruskal->print();
    return ListOfKruskal;
}

LinkedList<string> *crearProfundidad(){
    LinkedList<string> *ListOfDepth=new LinkedList<string>();
    GrafoMatriz vertice;
    Controlador cargar;

    cargar.leerVertice(vertice);
    int V = vertice.numVerts;
    int numArcos=cargar.leerConexiones(vertice);
    GrapoProfundidad gp(numArcos);
    LinkedList<string> *prov=new LinkedList<string>();
    cargar.addEdge(gp, V);
    gp.addEdge(0,1);
    gp.DFS(1, vertice, ListOfDepth);
    int cont=0;
    ListOfDepth->goToStart();
    while (cont<ListOfDepth->getSize()-1) {
        string a=ListOfDepth->getElement();
        ListOfDepth->next();
        string b=ListOfDepth->getElement();
        prov->append(a+"-"+b);
        prov->append(b+"-"+a);
        cont++;
    }

    prov->print();
    return prov;
}

int main(int argc, char *argv[])
    {
    srand(time(NULL));
    ArrayList<Rectangle*> *lista= new ArrayList<Rectangle*>;
    //creo la estructura

    QApplication a(argc, argv);


    //cosas de los grafos :)
    vista *elementos = new vista();

    //creo una escena, como niño en supermercado
    QGraphicsScene * scene = new QGraphicsScene();

    //agrego la vista
    QGraphicsView * view = new QGraphicsView(scene);
    view->setFixedSize(1000,1000);//el tamanio
    view->setBackgroundBrush(Qt::black);//el fondo


    int size=9;// esta variable dice el tamanio del grafo, siempre son cuadrados

    elementos->crearGrafoInicial(size);//Crea el grafo matriz Inicial

    elementos->agregarEnEscena(scene);//mete los cuadritos en la

    LinkedList<string> *ListOfPrim=crearPrim();
    LinkedList<string> *ListOfKruskal=crearKruskal();
    LinkedList<string> *ListOfDepth=crearProfundidad();
    elementos->crearParedes(scene, ListOfPrim, size);// crea las paredecitas

    elementos->crearPuntoInicial();

    view->show();








    return a.exec();
}
