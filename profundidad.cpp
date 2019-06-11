#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "profundidad.h"
#include "arraylist.h"
#include "linkedlist.h"

GrapoProfundidad::GrapoProfundidad(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void GrapoProfundidad::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void GrapoProfundidad::DFSUtil(int v, bool visited[], GrafoMatriz g, LinkedList<string> *listOfVerts)
{
    string a="";

    // Marca si el nodo esta visitado y lo imprime
    visited[v] = true;
    for (int i=0; i<V; i++){
        if (g.verts[i].numVertice==v ){
              a=g.verts[i].nombre;
        }
    }
    listOfVerts->append(to_string(v));

    // Recurren para todos los vértices adyacentes
    // a este vértice
    list<int>::iterator i;

    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited, g, listOfVerts);
}

// Recorrido DFS de los vértices accesibles desde v.
// Utiliza DFSUtil recursivo ()
void GrapoProfundidad::DFS(int v, GrafoMatriz g, LinkedList<string> *listOfVerts)
{
    // Marca todos los vértices como no visitados.
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Llamar a la función de ayuda recursiva.
    // para imprimir el recorrido DFS
    DFSUtil(v, visited, g, listOfVerts);
    cout<<endl;
}
