#include "recorregrafo.h"

int * RecorreGrafo::recorrerProf(GrafoMatriz g, int v)
{
     int w;
     Pila pila;
     Pila profundidad;
     int * m;
     if (v < 0 || v > g.OnumeroDeVertices())
        throw "vertice no existe";
     m = new int[g.OnumeroDeVertices()];
     // inicializa los vértices como no marcados
     for (int i = 0; i < g.OnumeroDeVertices(); i++)
        m[i] = CLAVE;
     m[v] = 0; // vértice origen queda marcado
     pila.insertar(v);
     while (!pila.pilaVacia())
     {
         int cw;
         cw = pila.quitar();
         cout<<cw<<endl;
         w = cw;
         profundidad.insertar(w);
         cout << "V" << w << g.Overtice(w).OnomVertice()<< " visitado"<<endl;
         // inserta en la pila los adyacentes de w no marcados
         for (int u = 0; u < g.OnumeroDeVertices(); u++){
             cout<<"a"<<g.Ovalor(w,u)<<endl;
             cout<<"b"<<m[u]<<endl;
             if (g.Ovalor(w,u) && m[u] == CLAVE)
             {
                 // se marca vértice u con número de arcos hasta el
                 m[u] = m[w]+1;
                 pila.insertar(u);
//                 pila.Mostrar();
             }
        }
     }
//     profundidad.Mostrar();
     return m;
}


int * RecorreGrafo::recorrerProf(GrafoMatriz g, string org)
{
     int v = g.numVertice(org);
     if (v < 0) {
         throw "Vértice no existe";
     }
     recorrerProf(g,v);
}

int gradoEntrada(GrafoMatriz g, int v)
{
     int cuenta = 0;
     for (int origen = 0; origen < g.OnumeroDeVertices(); origen++)
     {
         if (g.adyacente(origen, v)) // arco incidente a v
            cuenta++;
     }
     return cuenta;
}

Pila::~Pila()
{
   pnodoPila aux;

   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   actual = NULL;
}

int Pila::largoLista(){
    int cont=0;

    pnodoPila aux;
    aux = primero;
    if(primero==NULL){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }

}

void Pila::insertar(int v)
{
   if (primero==NULL){
    primero = new nodoPila(v);
   }else{
    primero=new nodoPila (v,primero);
    }
}

bool Pila::pilaVacia(){
    if (largoLista()<1){
        return true;
    }else{
        return false;
    }
}

int Pila::quitar()
{
    int v;
    if (primero==NULL){
     cout << "No hay elementos en la lista" << endl;

    }else{
        if (primero->siguiente == NULL){
                v=primero->valor;
                primero= NULL;
        }else{
            pnodoPila aux = primero;
            while (aux->siguiente->siguiente != NULL) {
                aux = aux->siguiente;
            }

            v=aux->siguiente->valor;
            pnodoPila temp = aux->siguiente;
            aux->siguiente= NULL;

            delete temp;

            }
        return v;
     }

}


void Pila::Mostrar()
{
   nodoPila *aux;

   aux = primero;
   while(aux) {
      cout << aux->valor<<"->";
      aux = aux->siguiente;
   }
   cout << endl;
}

void Pila::Siguiente()
{
   if(actual) actual = actual->siguiente;
}
