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
        for(arcos->goToStart();!arcos->atEnd();arcos->next()){
            string linea =arcos->getElement();
            listita=obtenerNumeros(linea);
            int num1=listita->getElement();
            listita->next();
            int num2=listita->getElement();

            cout<< num1<<"++++"<<num2<<endl;

            lista->goToPos(num1-1);

            Rectangle* cubo=lista->getElement();
            if(num1==num2-1){//significa que num2 es el siguiente en la lista o sea el de la derecha

                if(cubo->getRight()==NULL){
                    cout<<"entre"<<endl;
                    Rectangle* cuboNuevo= new Rectangle(cubo->getPosX()+20,cubo->getPosY());
                    cuboNuevo->setBrush(Qt::blue);
                    scene->addItem(cuboNuevo);
                    cubo->setRight(cuboNuevo);
                }
            }
            else if (num1+1==num2) {//significa que num2 es el anterior en la lista o sea el de la izquierda

                if(cubo->getLeft()==NULL){
                    Rectangle* cuboNuevo= new Rectangle(cubo->posX-20,cubo->posY);
                    scene->addItem(cuboNuevo);
                    cuboNuevo->setBrush(Qt::blue);
                    cubo->setLeft(cuboNuevo);
            }
            }

            else if (num1+size==num2){//significa que num2 esta abajo en la lista

                if(cubo->getDown()==NULL){
                    Rectangle* cuboNuevo= new Rectangle(cubo->posX,cubo->posY+20);
                    scene->addItem(cuboNuevo);
                    cuboNuevo->setBrush(Qt::blue);
                    cubo->setDown(cuboNuevo);
                }


            }
            else if(num1-size==num2){//significa que num2 esta arriba en la lista

                if(cubo->getUp()==NULL){
                    Rectangle* cuboNuevo= new Rectangle(cubo->posX,cubo->posY-20);
                    scene->addItem(cuboNuevo);
                    cuboNuevo->setBrush(Qt::blue);
                    cubo->setUp(cuboNuevo);
                }

            }

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
