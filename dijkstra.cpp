#include "dijkstra.h"

CaminoMinimo::CaminoMinimo (GrafoMatriz g, int origen)
{
     n = g.OnumeroDeVertices();
     s = origen;
     ultimo = new int[n];
     D = new int[n];
}

void CaminoMinimo::Dijkstra(GrafoMatriz g, int origen)
{
     bool * F;
     F = new bool [n];
     // valores iniciales
     for (int i = 0; i < n; i++)
     {
         F[i] = false;
         D[i] = g.Ovalor(s, i);
         ultimo[i] = s;
     }
     F[s] = true; D[s] = 0; //Marca origen e inicializa distancia
     // Pasos para marcar los n-1 vértices.
     for (int i = 1; i < n; i++)
     {
//         cout<<"valorDistancia: "<<D[i]<<endl;
//         cout<<"valor: "<<ultimo[i]<<endl;
         string t;
         for(int w=0; w<n; w++){
            t=(ultimo[w]);
         }

         int v = minimo(F);
         //selecciona vértice no marcado de menor distancia
         F[v] = true;
         if(F[v]==true){
             string s=to_string(v);
             t=t+","+s; /*atoi(v.c_str)*/
//             cout<<v<<endl;
         }
         // actualiza distancia de vértices no marcados
         for (int w = 0; w < n; w++){
             if (!F[w]){
                 if (D[v] + g.Ovalor(v, w) < D[w])
                 {
                     D[w] = D[v] + g.Ovalor(v, w);
                     ultimo[w] = v;
                 }
              }
          }
     }
}

int CaminoMinimo::minimo( bool F[])
 {
     double mx = 0xFFFF; // valor de infinito
     int v;
     for (int j = 0; j < n; j++){
         int c=D[j];
         if (!F[j] && (mx >= D[j]) && D[j]!=0)
         {
             mx = D[j];
             v = j;
         }
     }
     return v;
}

void CaminoMinimo::recuperaCamino(int v, GrafoMatriz g)
{
     int anterior = ultimo[v];
     if (v != s)
     {
         recuperaCamino(anterior, g); // vuelve al último del último
         for (int i=0; i<n; i++){
             if (g.verts[i].numVertice==v){
                   cout << g.verts[i].nombre << " V <--"<<endl;
             }
         }
     }
     else
         for (int i=0; i<n; i++){
             if (g.verts[i].numVertice==s){
                   cout << g.verts[i].nombre << " V <--"<<endl;
             }
         }
}


int * CaminoMinimo::OdistanciaMinima(){
    return D;
}
int * CaminoMinimo::Oultimo(){
    return ultimo;
}
