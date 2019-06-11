#ifndef PROFUNDIDAD_H
#define PROFUNDIDAD_H
#include "grafomatriz.h"

#include<iostream>
#include "fstream"
#include "list.h"
#include "linkedlist.h"
#include<list>
using namespace std;

// Clase de gráfico representa un gráfico dirigido
// usando la representación de lista de adyacencia
class GrapoProfundidad
{
    int V;    // No. de vertices

    // Puntero a una matriz que contiene
    // listas de adyacencia
    list<int> *adj;
//    List<int> *adj;

    // Una función recursiva utilizada por DFS
    void DFSUtil(int v, bool visited[], GrafoMatriz g, LinkedList<string> *);
public:
    GrapoProfundidad(int V);   // Constructor

    // Función para agregar un borde al gráfico
    void addEdge(int v, int w);

    // DFS transversal de los vértices
    // accesible desde v
    void DFS(int v, GrafoMatriz g, LinkedList<string> *);
};

#endif // PROFUNDIDAD_H
