#ifndef VISTA_H
#define VISTA_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "rectangle.h"
#include "arraylist.h"
#include "linkedlist.h"
#include "personaje.h"
#include <cstdlib>
class vista: public QGraphicsView{
 /*
  *
  *                              ESTA ES LA CLASE QUE MANEJA EL JUEGO, AQUI ES DONDE SE CREAN TODAS LAS COSAS NECESARIAS PARA EL JUEGO
  *
  * */


public:
    Rectangle *actual;
    Rectangle *final;
    Rectangle *inicial;
    ArrayList<Rectangle*> *lista;
    QGraphicsScene *scene;


    vista(QWidget *parent=NULL){
        setFixedSize(1000,1000);
        setBackgroundBrush(Qt::black);
        lista=new ArrayList<Rectangle*>;
        scene=new QGraphicsScene();
        //scene->setSceneRect(0,0,1000,1000);
        setScene(scene);
        this->actual=NULL;
        this->final=NULL;
        this->inicial=NULL;
    }


    void agregarEnEscena(){
        for(lista->goToStart();!lista->atEnd();lista->next()){
            scene->addItem(lista->getElement());
        }
    }

    /*
     * ESTE METODO complementario del metodoCrearParedes
     * */
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
                    cuboNuevo->setBrush(Qt::green);
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
                    cuboNuevo->setBrush(Qt::green);
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
                    cuboNuevo->setBrush(Qt::green);
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
                    cuboNuevo->setBrush(Qt::green);
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
//            if(num>(size*size)||num<size){
//                alea=1;
//            }
            lista->goToPos(num);
            Rectangle* cuadrito=lista->getElement();

            if(alea==0){//Asginar a la izquierda del nodo escogido
                if(cuadrito->getLeft()==NULL){
                    if(num%size!=0){
                        lista->goToPos(num-1);
                        Rectangle* cuadrito2=lista->getElement();

                        Rectangle* paredcita=new Rectangle(cuadrito->getPosX()-20,cuadrito->getPosY());
                        paredcita->setBrush(Qt::green);
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
                        paredcita->setBrush(Qt::green);
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
                         paredcita->setBrush(Qt::green);
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
                        paredcita->setBrush(Qt::green);
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

     ArrayList<Rectangle*> *crearGrafoInicial(int size){
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
        return lista;
    }


    void crearManzanitas(){
            int cantMan = 3;
            while(cantMan>0){
                int pos = rand()%(lista->getSize()-1);
                lista->goToPos(pos);
                Rectangle* manzanita = lista->getElement();
                manzanita->setManzanita(true);
                manzanita->setBrush(Qt::red);
                cantMan--;
            }
    }


    void crearFinal(int size){
        int pos =(size*size/2) +rand()%(size*size/2);
        lista->goToPos(pos);
        Rectangle* final = lista->getElement();
        final->setIsFinal(true);
        final->setBrush(Qt::yellow);
    }


    void crearPuntoInicial(){
        int pos=0;
        lista->goToPos(pos);
        actual=lista->getElement();
        Personaje *puntito=new Personaje(actual->getPosX(),actual->getPosY(),pos,lista,actual);
        puntito->setFlag(QGraphicsItem::ItemIsFocusable);
        puntito->setFocus();
        puntito->setBrush(Qt::blue);
        scene->addItem(puntito);
    }

    void mostrar(){
        show();
    }


    void crearJuego(int size,LinkedList<string> *lista){

        crearGrafoInicial(size);
        crearManzanitas();
        crearFinal(size);
        agregarEnEscena();
        crearParedes(lista,size);
        crearParedesExtra(size);
        crearPuntoInicial();
        mostrar();
    }





};

#endif // VISTA_H
