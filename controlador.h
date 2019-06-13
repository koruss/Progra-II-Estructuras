#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include <iostream>
#include "prim.h"
#include "grafomatriz.h"
#include "dijkstra.h"
#include "recorregrafo.h"
#include "kruskal.h"
#include "puntosdearticulacion.h"
#include "profundidad.h"


class Controlador
{
public:
    Controlador();

    void leerVertice(GrafoMatriz &g,int size);
    void introducirVertice(string, GrafoMatriz &g);

    int leerConexiones(GrafoMatriz &);
    void introducirConexiones(string, GrafoMatriz &);
    void leerKruskal(GrafoKruskal &, int);
    void introducirKruskal(string, GrafoKruskal &);
    void leerArticulacion(GrafoArticulacion &);
    void introducirArticulacion(string, GrafoArticulacion &);
    void leerProfundidad(GrapoProfundidad &, int);
    void introducirProfundidad(string, GrapoProfundidad &);
    void addEdge(GrapoProfundidad &, int);
};

#endif // CONTROLADOR_H
