#ifndef PRIM_H
#define PRIM_H
#include "grafomatriz.h"
#include "iostream"
#include "fstream"
#include "linkedlist.h"

class ArbolExpansionMinimo
{
    protected :
         int ** matrizadyacencia;
         int longMin;
    private:
         int n;
         int INFINITO;
    public:
         int ** OT(){ return matrizadyacencia;} // Arbol de expansión
         int OlongMin(){ return longMin;} // peso del Árbol expansión
         ArbolExpansionMinimo(GrafoMatriz g); // constructor
         int arbolExpansionPrim(GrafoMatriz g, LinkedList<string> *); // algoritmo de Prim

};



#endif // PRIM_H
