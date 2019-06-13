#ifndef VISTA_H
#define VISTA_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "rectangle.h"
#include "arraylist.h"
#include "linkedlist.h"
#include <cstdlib>




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


    void crearParedes(QGraphicsScene* scene,LinkedList<string>* arcos, int size){
        ArrayList<int> *listita=new ArrayList<int>();
        cout<<lista->getSize()<<endl;
        for(arcos->goToStart();!arcos->atEnd();arcos->next()){
            string linea =arcos->getElement();
            listita=obtenerNumeros(linea);
            int num1=listita->getElement();
            listita->next();
            int num2=listita->getElement();// lista es la que tiene todos los nodos
                                           //num1 es el de partida y num2 el de llegada
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
                    Rectangle* cuboNuevo= new Rectangle(cubo->posX-20,cubo->posY);
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
                    Rectangle* cuboNuevo= new Rectangle(cubo->posX,cubo->posY+20);
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
                    Rectangle* cuboNuevo= new Rectangle(cubo->posX,cubo->posY-20);
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

    void crearParedesExtra(int size,QGraphicsScene* scene){
        int valor=(size*size)*0.05;
        cout<<valor<<endl;

        while(valor>0){
            int num=size+(rand()%(lista->getSize()-size));
            int alea=rand()%4;
            if(num>(size*size)||num<size){
                alea==1;
            }
            cout<<num<<endl;

            lista->goToPos(num);
            Rectangle* cuadrito=lista->getElement();

            if(alea==0){//izq
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
            else if (alea==1) {//der
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
            else if (alea==2) {//up
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
            else if (alea==3) {//down
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
            int pos;
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
        Rectangle* manzanita = lista->getElement();
        lista->goToPos(pos);
        Rectangle* final = lista->getElement();
        final->setIsFinal(true);
        final->setBrush(Qt::yellow);

    }





};

#endif // VISTA_H
