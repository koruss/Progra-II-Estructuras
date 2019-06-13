#include "prim.h"
#include "linkedlist.h"


ArbolExpansionMinimo::ArbolExpansionMinimo(GrafoMatriz g)
{
     n = g.OnumeroDeVertices();
     INFINITO = 0xFFFF;
     longMin = 0;
     typedef int * pint;
     matrizadyacencia = new pint [n];
     for ( int i = 0 ; i < n; i++)
     {
         matrizadyacencia[i] = new int [n];
         for(int j = 0; j < n; j++)
             matrizadyacencia[i][j] = INFINITO;
     }
}

int ArbolExpansionMinimo::arbolExpansionPrim(GrafoMatriz g, LinkedList<string> *listOfVerts)
{
     string a;
     string b;

     int menor;
     int *coste = new int [n];
     int *masCerca = new int [n];
     bool *W = new bool [n];
     for (int i = 0; i < n; i++){
         W[i] = false; // conjunto vacío
     }
     W[0] = true; //se parte del vértice 0
     // inicialmente, coste[i] es la arista (0,i)
     for (int i = 1; i < n; i++)
     {
         coste[i] = g.Ovalor(0, i);
         masCerca[i] = 0;
     }
     coste[0] = INFINITO;
     for (int i = 1; i < n; i++)
     { // busca vértice z de V-W mas cercano,
       // de menor longitud de arista, a algún vértice de W
         menor = coste[1];
         int z = 1;
         for (int j = 2; j < n; j++)
             if (coste[j] < menor)
             {
                 menor = coste[j];
                 z = j;
             }
         longMin += menor;
         // se escribe el arco incorporado al árbol de expansión
         for (int i=0; i<n; i++){
             if (g.verts[i].numVertice==z ){
                   a=g.verts[i].nombre;
             }
         }

         for (int i=0; i<n; i++){
             if (g.verts[i].numVertice==masCerca[z] ){
                   b=g.verts[i].nombre;
             }
         }
         listOfVerts->append(b+"-"+a);
         listOfVerts->append(a+"-"+b);

         W[z] = true; // vértice z se añade al conjunto W
         matrizadyacencia[masCerca[z]][z] = matrizadyacencia[z][masCerca[z]] = coste[z];
         coste[z] = INFINITO;
         // debido a la incorporación de z,
         // se ajusta coste[] para el resto de vértices
         for (int j = 1; j < n; j++)
             if ((g.Ovalor(z, j) < coste[j]) && !W[j])
             {
                 coste[j] = g.Ovalor(z, j);
                 masCerca[j] = z;
             }
     }
     return longMin;
}
