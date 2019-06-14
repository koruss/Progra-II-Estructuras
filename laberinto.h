#ifndef LABERINTO_H
#define LABERINTO_H
#include "rectangle.h"
#include "personaje.h"
#include "linkedlist.h"
#include "arraylist.h"
#include "prim.h"
#include "controlador.h"
#include "grafomatriz.h"
#include <QGraphicsScene>
#include <QFont>
#include "manzanita.h"
#include "meta.h"


class Laberinto{


public:
    ArrayList<Rectangle*> *lista;
    Rectangle *actual;
    Rectangle *final;
    Rectangle *inicial;
    QGraphicsScene *scene;
    LinkedList<string> *dijkstra;
    int manzanitas;
    QString tipoLaberinto;
    int nivel=5;
    Personaje *personaje;
    QGraphicsTextItem *textoLaberinto;
    ArrayList<Manzanita*> *cestaManzanas;
    Meta *meta;


    Laberinto(QGraphicsScene *scene,int tam){
        this->scene=scene;
        this->tipoLaberinto="";
        this->textoLaberinto=new QGraphicsTextItem();
        lista=new ArrayList<Rectangle*>;
        cestaManzanas=new ArrayList<Manzanita*>;
        actual=NULL;
        final=NULL;
        inicial=NULL;
        personaje=NULL;
        this->nivel=tam;
        this->meta=NULL;
        crearJuego(nivel);

        //dibujarCamino(tam);
    }



    void crearJuego(int size){
        int random= rand()%2;
        crearGrafoInicial(size);
        crearManzanitas();
        crearFinal(size);
        agregarEnEscena();
        if(random==0){
            crearParedes(crearPrim(size),size);
            this->tipoLaberinto="Creado con el algoritmo de Prim";

        }
        else{
            crearParedes(crearKruskal(size),size);
            this->tipoLaberinto="Creado con el algoritmo de Kruskal";
        }

        crearParedesExtra(size);
        crearPuntoInicial();
       }

    //GETTERS N SETTERS
    void setLista(ArrayList<Rectangle *> *value)
    {
    lista = value;
    }

    Rectangle *getActual()
    {
    return actual;
    }

    void setActual(Rectangle *value)
    {
    actual = value;
    }

    Rectangle *getFinal()
    {
    return final;
    }

    void setFinal(Rectangle *value)
    {
    final = value;
    }

    Rectangle *getInicial()
    {
    return inicial;
    }

    void setInicial(Rectangle *value)
    {
    inicial = value;
    }
    ArrayList<Rectangle *> *getLista()
    {
    return lista;
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
           rect->setNum(i);
           rect->setBrush(Qt::magenta);
           this->lista->append(rect);

           x+=40;
           cont++;
       }
   }

    void crearManzanitas(){
            int cantMan =3 +rand()%(8-3);
            this->manzanitas=cantMan;
            while(cantMan>0){
                int pos = rand()%(lista->getSize()-1);
                lista->goToPos(pos);
                Rectangle *cuadrito = lista->getElement();
                cuadrito->setManzanita(true);
                Manzanita *manzanita= new Manzanita(cuadrito->getPosX(),cuadrito->getPosY(),10);
                cestaManzanas->append(manzanita);
                scene->addItem(manzanita);
                cantMan--;
            }
    }

    void destruirManzanita(int posX,int posY){
        for(cestaManzanas->goToStart();!cestaManzanas->atEnd();cestaManzanas->next()){
            Manzanita *manzanaPodrida= cestaManzanas->getElement();
            if(manzanaPodrida->posX==posX && manzanaPodrida->posY==posY){
                scene->removeItem(manzanaPodrida);
                delete manzanaPodrida;
                return;
            }
        }
    }

    void destruirMeta(){
        scene->removeItem(meta);
    }

    void crearFinal(int size){
        int pos =(size*size/2) +rand()%(size*size/2);
        lista->goToPos(pos);
        Rectangle* final = lista->getElement();

    {    if(final->getManzanita()){
            return crearFinal(size);
        }

        else
            final->setIsFinal(true);
            meta =new Meta(final->getPosX(),final->getPosY(),12);
            scene->addItem(meta);
            return;
        }

    }


    void agregarEnEscena(){
        for(lista->goToStart();!lista->atEnd();lista->next()){
            scene->addItem(lista->getElement());
        }
    }

    LinkedList<string> *crearDijkstra(LinkedList<string> *grafo, int size){

        GrafoMatriz verticeDijkstra;
        Controlador cargarDijkstra;
        LinkedList<string> *ListOfDijkstra=new LinkedList<string>();
        cargarDijkstra.leerVertice(verticeDijkstra, size);
        cargarDijkstra.leerConexionesDijkstra(verticeDijkstra, grafo);
        int inicio=5;

        int destino=25;
        CaminoMinimo dij(verticeDijkstra, inicio);
        dij.Dijkstra(verticeDijkstra, 0);
        dij.recuperaCamino(destino, verticeDijkstra, ListOfDijkstra);
           LinkedList<string> *provDijkstra=new LinkedList<string>();
           int cont=0;
           ListOfDijkstra->goToStart();
           while (cont<ListOfDijkstra->getSize()-1) {
               string a=ListOfDijkstra->getElement();
               ListOfDijkstra->next();
               string b=ListOfDijkstra->getElement();
               provDijkstra->append(a+"-"+b);
               cont++;
           }
           //provDijkstra->print();
           return provDijkstra;
    }


    LinkedList<string> * crearPrim(int size){
        Controlador cargar;
        GrafoMatriz vertice;
        LinkedList<string> *ListOfPrim=new LinkedList<string>();
        LinkedList<string> *ListToDijkstra=new LinkedList<string>();
        cargar.leerVertice(vertice,size);
        cargar.leerConexiones(vertice);
        ArbolExpansionMinimo prim(vertice);
        prim.arbolExpansionPrim(vertice, ListOfPrim, ListToDijkstra);
        this->dijkstra=crearDijkstra(ListToDijkstra, size);

        return ListOfPrim;
    }

    LinkedList<string> *crearKruskal(int size){
        LinkedList<string> *ListOfKruskal=new LinkedList<string>();        
        LinkedList<string> *ListToDijkstra=new LinkedList<string>();
        GrafoMatriz vertice;
        Controlador cargar;

        cargar.leerVertice(vertice,size);
        int V = vertice.numVerts;
        int numArcos=cargar.leerConexiones(vertice);
        int E = numArcos;

        GrafoKruskal g(V,E);
        cargar.leerKruskal(g, V);
        g.kruskal();
        g.print(vertice, ListOfKruskal, ListToDijkstra);
        this->dijkstra=crearDijkstra(ListToDijkstra, size);
        return ListOfKruskal;
    }

private:

    ArrayList<int>* obtenerNumeros(string linea){
        string x;
        ArrayList<int> *lista=new ArrayList<int>();
        for(unsigned int i=0; i<linea.size();i++){
            char letra=linea[i];
            if(letra=='-'){
                lista->append(std::stoi(x));
                x="";
            }
            else{
                x=x+=letra;
            }
        }
        lista->append(std::stoi(x));
        return lista;

    }

public:
    /*
     * ESTE METODO CREA LAS UNIONES O PAREDES ENTRE LOS NODOS DEL GRAFO
     *
     */


    void crearParedes(LinkedList<string>* arcos, int size){
        ArrayList<int> *listita=new ArrayList<int>();
        for(arcos->goToStart();!arcos->atEnd();arcos->next()){
            string linea =arcos->getElement();
            listita=obtenerNumeros(linea);
            int num1=listita->getElement();
            listita->next();
            int num2=listita->getElement();// lista es la que tiene todos los nodos     //num1 es el de partida y num2 el de llegada
            lista->goToPos(num1-1);
            Rectangle* cubo=lista->getElement();// cubo es nodo de la lista
            lista->goToPos(num2-1);
            Rectangle* cubo2=lista->getElement();
            if(num1==num2-1){//significa que num2 es el siguiente en la lista o sea el de la derecha
                if(cubo->getRight()==NULL){
                    Rectangle* cuboNuevo= new Rectangle(cubo->getPosX()+20,cubo->getPosY());//cuboNuevo= a la pared o arco
                    cuboNuevo->setBrush(Qt::magenta);
                    cubo->setRight(cuboNuevo);
                    cuboNuevo->setLeft(cubo);
                    cubo2->setLeft(cuboNuevo);
                    cuboNuevo->setRight(cubo2);
                    scene->addItem(cuboNuevo);
                }
            }
            else if (num1+1==num2) {//significa que num2 es el anterior en la lista o sea el de la izquierda
                if(cubo->getLeft()==NULL){
                    Rectangle* cuboNuevo= new Rectangle(cubo->getPosX()-20,cubo->getPosY());
                    scene->addItem(cuboNuevo);
                    cuboNuevo->setBrush(Qt::magenta);
                    cubo->setLeft(cuboNuevo);
                    cubo2->setRight(cuboNuevo);
                    cuboNuevo->setLeft(cubo2);
                    cuboNuevo->setRight(cubo);
                }
            }
            else if (num1+size==num2){//significa que num2 esta abajo en la lista
                if(cubo->getDown()==NULL){
                    Rectangle* cuboNuevo= new Rectangle(cubo->getPosX(),cubo->getPosY()+20);
                    scene->addItem(cuboNuevo);
                    cuboNuevo->setBrush(Qt::magenta);
                    cubo->setDown(cuboNuevo);
                    cuboNuevo->setUp(cubo);
                    cubo2->setUp(cuboNuevo);
                    cuboNuevo->setDown(cubo2);
                }
            }
            else if(num1-size==num2){//significa que num2 esta arriba en la lista

                if(cubo->getUp()==NULL){
                    Rectangle* cuboNuevo= new Rectangle(cubo->getPosX(),cubo->getPosY()-20);
                    scene->addItem(cuboNuevo);
                    cuboNuevo->setBrush(Qt::magenta);
                    cubo->setUp(cuboNuevo);
                    cuboNuevo->setDown(cubo);
                    cuboNuevo->setUp(cubo2);
                    cubo2->setDown(cuboNuevo);
                }

            }

        }
    }


    void crearParedesExtra(int size){
        int valor=(size*size)*0.05;
        while(valor>0){
            int num=size+(rand()%(lista->getSize()-size));//ESTE ES EL NUMERO ALEATORIO PARA ESCOGER EL NODO DE LA LISTA
            int alea=rand()%4;//ESTE NUMERO ALEATORIO SE USA PARA ESCOGER LA POSICION ARRIBA,ABAJO,IZQ,DER a ASIGNAR
            if(num>(size*size)||num<size){
                alea=1;
            }
            lista->goToPos(num);
            Rectangle* cuadrito=lista->getElement();

            if(alea==0){//Asginar a la izquierda del nodo escogido
                if(cuadrito->getLeft()==NULL){
                    if(num%size!=0){
                        lista->goToPos(num-1);
                        Rectangle* cuadrito2=lista->getElement();
                        Rectangle* paredcita=new Rectangle(cuadrito->getPosX()-20,cuadrito->getPosY());
                        paredcita->setBrush(Qt::magenta);
                        cuadrito->setLeft(paredcita);
                        paredcita->setRight(cuadrito);
                        cuadrito2->setRight(paredcita);
                        paredcita->setLeft(cuadrito2);
                        scene->addItem(paredcita);
                    }
                }
            }
            else if (alea==1) {//a la derecha del nodo escogido
                if(cuadrito->getRight()==NULL){
                    if((num+1)%size!=0){
                        lista->goToPos(num+1);
                        Rectangle* cuadrito2=lista->getElement();
                        Rectangle* paredcita=new Rectangle(cuadrito->getPosX()+20,cuadrito->getPosY());
                        paredcita->setBrush(Qt::magenta);
                        cuadrito->setRight(paredcita);
                        paredcita->setLeft(cuadrito);
                        paredcita->setRight(cuadrito2);
                        cuadrito2->setLeft(paredcita);
                        scene->addItem(paredcita);
                    }
                }
            }

            else if (alea==2) {//arriba del nodo escogido
                if(cuadrito->getUp()==NULL){
                    if(num>size){
                         lista->goToPos(num-size);
                         Rectangle* cuadrito2=lista->getElement();
                         Rectangle* paredcita=new Rectangle(cuadrito->getPosX(),cuadrito->getPosY()-20);
                         paredcita->setBrush(Qt::magenta);
                         cuadrito->setUp(paredcita);
                         paredcita->setDown(cuadrito);
                         cuadrito2->setDown(paredcita);
                         paredcita->setUp(cuadrito2);
                         scene->addItem(paredcita);
                    }
                }
            }
            else if (alea==3) {//
                if(cuadrito->getDown()==NULL){
                    if(num<((size*size)-size)){
                        lista->goToPos(num+size);
                        Rectangle* cuadrito2=lista->getElement();
                        Rectangle* paredcita=new Rectangle(cuadrito->getPosX(),cuadrito->getPosY()-20);
                        paredcita->setBrush(Qt::magenta);
                        cuadrito->setDown(paredcita);
                        paredcita->setUp(cuadrito);
                        cuadrito2->setUp(paredcita);
                        paredcita->setDown(cuadrito2);
                        scene->addItem(paredcita);
                    }
                }
            }
    valor--;
        }
    }


    void crearPuntoInicial(){
        int pos=0;
        lista->goToPos(pos);
        setActual(lista->getElement());
        setInicial(lista->getElement());
        Personaje *puntito=new Personaje(actual->getPosX(),actual->getPosY(),pos,lista,actual);
        puntito->setFlag(QGraphicsItem::ItemIsFocusable);
        puntito->setFocus();
        //puntito->setBrush(Qt::blue);
        scene->addItem(puntito);
        this->personaje=puntito;
    }


    void dibujarCamino(int size){
        ArrayList<int> *listita=new ArrayList<int>();
        for(dijkstra->goToStart();!dijkstra->atEnd();dijkstra->next()){

            string linea =dijkstra->getElement();
            cout<<linea<<endl;
            listita=obtenerNumeros(linea);
            int num1=listita->getElement();
            cout<<num1<<endl;
            listita->next();
            int num2=listita->getElement();// lista es la que tiene todos los nodos     //num1 es el de partida y num2 el de llegada
            cout<<num2<<endl;
            lista->goToPos(num1-1);
            Rectangle* cubo=lista->getElement();// cubo es nodo de la lista
            lista->goToPos(num2-1);
            Rectangle* cubo2=lista->getElement();
            if(cubo->getManzanita()!=true && cubo2->getManzanita()!=true && cubo->getIsFinal()!=true && cubo2->getIsFinal()!=true){
                if(num1==num2-1){//significa que num2 es el siguiente en la lista o sea el de la derecha
                    if(cubo->getRight()!=NULL){

                            cubo->setBrush(Qt::white);
                            cubo2->setBrush(Qt::white);
                            cubo->getRight()->setBrush(Qt::white);
                    }

                }
                else if (num1+1==num2) {//significa que num2 es el anterior en la lista o sea el de la izquierda
                    if(cubo->getLeft()!=NULL){
                        cubo->setBrush(Qt::white);
                        cubo2->setBrush(Qt::white);
                        cubo->getLeft()->setBrush(Qt::white);



                    }
                }
                else if (num1+size==num2){//significa que num2 esta abajo en la lista
                    if(cubo->getDown()!=NULL){
                        cubo->setBrush(Qt::white);
                        cubo2->setBrush(Qt::white);
                        cubo->getDown()->setBrush(Qt::white);
                    }
                }
                else if(num1-size==num2){//significa que num2 esta arriba en la lista

                    if(cubo->getUp()!=NULL){
                        cubo->setBrush(Qt::white);
                        cubo2->setBrush(Qt::white);
                        cubo->getUp()->setBrush(Qt::white);
                    }

                }
            }

        }
    }





};

#endif // LABERINTO_H




