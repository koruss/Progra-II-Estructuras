#ifndef PUNTOSDEARTICULACION_H
#define PUNTOSDEARTICULACION_H
#include "grafomatriz.h"
#include <iostream>
#include "fstream"
#include <list>
#define NIL -1
using namespace std;

// Esta clase representa un grafo no dirigido
class GrafoArticulacion
{
    int V;    // No. de vertices
    list<int> *adj;    // Una lista dinamica para los vertices de adyacencia
    void APUtil(int v, bool visited[], int disc[], int low[],
                int parent[], bool ap[]);
public:
    GrafoArticulacion(int V);   // Constructor
    void insertarVertice(int v, int w);   // Funcion que agrega un vertice nuevo
    void AP(GrafoMatriz g, int entrada);    // Imprime los puntos de articulacion

    void escribirArchivo(string dato);
};

#endif // PUNTOSDEARTICULACION_H
