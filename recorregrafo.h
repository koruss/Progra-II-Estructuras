#ifndef RECORREGRAFO_H
#define RECORREGRAFO_H
#include "grafomatriz.h"

class nodoPila {
   public:
    nodoPila(int v)
    {
       valor = v;
       siguiente = NULL;
    }

nodoPila(int v, nodoPila * signodo)
    {
       valor = v;
       siguiente = signodo;
    }

   private:
    int valor;
    nodoPila *siguiente;


   friend class Pila;
};

typedef nodoPila *pnodoPila;

class Pila{
    public:
     Pila() { primero = actual = NULL; }
     ~Pila();

     void insertar(int v);
     void Mostrar();
     void Siguiente();
     bool pilaVacia();
     int quitar();

     int largoLista();


    private:
     pnodoPila primero;
     pnodoPila actual;


};

class RecorreGrafo
{
 public:
 int CLAVE ; // Clave para vértice no marcado
 RecorreGrafo(){CLAVE = 0xffff;} //Clave vértice no marcado
 //operaciones con los recorridos
 int *recorrerProf(GrafoMatriz g, string org);
 // sobrecarga de los métodos pasando el número de vértice
 int * recorrerProf(GrafoMatriz g, int v);
};


#endif // RECORREGRAFO_H
