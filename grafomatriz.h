#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H
#include <string>
#include <iostream>

using namespace std;


class Vertice
{
    protected:


    public:
     Vertice () {}
     Vertice(string x)
     { // inicializa el nombre y pone el número de vértice e -1
         nombre = x;
         numVertice = -1;
     }
     Vertice(string x, int n)
     { // inicializa el nombre y el número de vértice
         nombre = x;
         numVertice = n;
     }
     string OnomVertice()
     { // retorna el nombre del vértice
             return nombre;
     }
     void PnomVertice(string nom)
     { // cambia el nombre del vértice
         nombre = nom;
     }
     bool igual(Vertice n)
     { // decide entre la igualdad de nombres
         return nombre == n.nombre;
     }
     void PnumVertice(int n)
     { // cambia el número del vértice
         numVertice = n;
     }
     int OnumVertice()
     { // retorna el número del vértice
         return numVertice;
     }

     string nombre;
     int numVertice;
};


class GrafoMatriz
{
 public:
     int maxVerts; // máximo numero de vértices
     int numVerts; // número de vértices actual
     Vertice * verts; // array de vértices
     int ** matAd; // matriz de adyacencia


 // métodos públicos de la clase GrafoMatriz
     GrafoMatriz();
     void GrafoMatrize(int);


     void nuevoVertice (string nom);
     int numVertice(string v);
     //añadir arco
     void nuevoArco(string a, string b);
     void nuevoArco(int va, int vb);
     void nuevoArco(string va, string vb, int valor);
     //adyacente
     bool adyacente(string a, string b);
     bool adyacente(int va, int vb);
     //valor de la matriz de adyacencia
     int Ovalor(string a, string b);
     int Ovalor( int va, int vb);
     //modificar el valor de la matriz de adyacencia
     void Pvalor(int va, int vb, int v);
     void Pvalor( char *a, char *b, int v);
     //vertice asociado a un numero entero
     Vertice Overtice(int va)
     {
          if (va < 0 || va >= numVerts)
          throw "Vértice no existe";
          else return verts[va];
     }
     void Pvertice( int va, Vertice vert)
     {
          if (va < 0 || va >= numVerts)
          throw "Vértice no existe";
          else verts[va] = vert;
     }
     int OnumeroDeVertices(){return numVerts;}
     void PnumeroDeVertices(int n){numVerts = n;}

     void verMatriz(int mx);

private:
 // métodos privados de la clase GrafoMariz


};

typedef int *pint; // para el dimensionamiento de la matriz
#endif // GRAFOMATRIZ_H
