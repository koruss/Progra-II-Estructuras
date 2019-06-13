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
#include "personaje.h"


LinkedList<string> * crearPrim(int size){
    Controlador cargar;
    GrafoMatriz vertice;
    LinkedList<string> *ListOfPrim=new LinkedList<string>();
    cargar.leerVertice(vertice,size);
    int V = vertice.numVerts;
    int numArcos=cargar.leerConexiones(vertice);
    ArbolExpansionMinimo prim(vertice);
    prim.arbolExpansionPrim(vertice, ListOfPrim);

    return ListOfPrim;

}


LinkedList<string> *crearKruskal(int size){
    LinkedList<string> *ListOfKruskal=new LinkedList<string>();
    GrafoMatriz vertice;
    Controlador cargar;

    cargar.leerVertice(vertice,size);
    int V = vertice.numVerts;
    int numArcos=cargar.leerConexiones(vertice);
    int E = numArcos;

    GrafoKruskal g(V,E);
    cargar.leerKruskal(g, V);
    g.kruskal();
    g.print(vertice, ListOfKruskal);
    //ListOfKruskal->print();
    return ListOfKruskal;
}

LinkedList<string> *crearProfundidad(int size){
    LinkedList<string> *ListOfDepth=new LinkedList<string>();
    GrafoMatriz vertice;
    Controlador cargar;

    cargar.leerVertice(vertice,size);
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

    //prov->print();
    return prov;
}

void crearPuntoInicial(QGraphicsScene* scene,ArrayList<Rectangle*> *lista, vista *vista){
    int pos=0;
    lista->goToPos(pos);
    vista->actual=lista->getElement();
    Personaje *puntito=new Personaje(vista->actual->getPosX(),vista->actual->getPosY(),pos,lista,vista->actual);
    puntito->setFlag(QGraphicsItem::ItemIsFocusable);
    puntito->setFocus();
    puntito->setBrush(Qt::blue);
    scene->addItem(puntito);

}


//void game(int size){

//    //cosas de los grafos :)
//    vista *elementos = new vista();

//    //creo una escena, como niño en supermercado
//    QGraphicsScene * scene = new QGraphicsScene();
//    //agrego la vista
//    QGraphicsView * view = new QGraphicsView(scene);
//    view->setFixedSize(1000,1000);//el tamanio
//    view->setBackgroundBrush(Qt::black);//el fondo
//    //int size=20;// esta variable dice el tamanio del grafo, siempre son cuadrados
//    ArrayList<Rectangle*> *listaNodos=elementos->crearGrafoInicial(size);//Crea el grafo matriz Inicial
//    elementos->crearManzanitas();
//    elementos->crearFinal(size);
//    elementos->agregarEnEscena(scene);//mete los cuadritos en la
//    LinkedList<string> *ListOfPrim=crearPrim( size);
//    LinkedList<string> *ListOfKruskal=crearKruskal(size);
//    //  LinkedList<string> *ListOfDepth=crearProfundidad(size);

//    elementos->crearParedes(scene, ListOfKruskal, size);// crea las paredecitas
//    elementos->crearParedesExtra(size,scene);
//    crearPuntoInicial(scene,listaNodos,elementos);
//}




int main(int argc, char *argv[])
    {
    srand(time(NULL));
    ArrayList<Rectangle*> *lista= new ArrayList<Rectangle*>;
    //creo la estructura

    QApplication a(argc, argv);




//    for(int num=5;num>0;num5){
//        LinkedList<string> *ListOfPrim=crearPrim( num);
//        LinkedList<string> *ListOfKruskal=crearKruskal(num);
//        vista *juego=new vista();

//        juego->crearJuego(num,ListOfPrim);
//    }


    int size=15;
    LinkedList<string> *ListOfPrim=crearPrim(size);
    vista* juego=new vista();
    juego->crearJuego(size,ListOfPrim);



    //cosas de los grafos :)
    //    vista *elementos = new vista();

    //        //creo una escena, como niño en supermercado
    //        QGraphicsScene * scene = new QGraphicsScene();
    //        //agrego la vista
    //        QGraphicsView * view = new QGraphicsView(scene);
    //        view->setFixedSize(1000,1000);//el tamanio
    //        view->setBackgroundBrush(Qt::black);//el fondo
    //        int size=20;// esta variable dice el tamanio del grafo, siempre son cuadrados
    //        ArrayList<Rectangle*> *listaNodos=elementos->crearGrafoInicial(size);//Crea el grafo matriz Inicial
    //        elementos->crearManzanitas();
    //        elementos->crearFinal(size);
    //        elementos->agregarEnEscena(scene);//mete los cuadritos en la
    //        LinkedList<string> *ListOfPrim=crearPrim( size);
    //        LinkedList<string> *ListOfKruskal=crearKruskal(size);
    //    //  LinkedList<string> *ListOfDepth=crearProfundidad(size);

    //        elementos->crearParedes(scene, ListOfKruskal, size);// crea las paredecitas
    //        crearPuntoInicial(scene,listaNodos,elementos);
    //        elementos->crearParedesExtra(size,scene);
            //view->show();
        return a.exec();
    }




