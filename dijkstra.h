#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "grafomatriz.h"
#include "fstream"
#include "iostream"

class CaminoMinimo
{
     protected:
         int * ultimo; // array de predecesores
         int * D; // array de distancias mínimas

     private:
        int s, n; // vértice origen y número de vértices

     public:
         CaminoMinimo (GrafoMatriz g, int origen); // constructor
         void Dijkstra(GrafoMatriz g, int origen); // dijkstra
         void recuperaCamino(int v, GrafoMatriz g);
         int * OdistanciaMinima();
         int *Oultimo();
     private:
         int minimo( bool F[]); // metodo privado usado por dijkstra
};
#endif // DIJKSTRA_H

