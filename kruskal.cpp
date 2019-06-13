#include "kruskal.h"
#include "linkedlist.h"

GrafoKruskal::GrafoKruskal(int V,int E){
    this->V = V;
    this->E = E;
}
void GrafoKruskal::addEdge(int salida,int llegada,int peso){
    ejes.push_back({peso,{salida,llegada}});
}

void GrafoKruskal::print(GrafoMatriz grafo, LinkedList<string> *listOfVerts){
    string a;
    string b;

    vector<pair<int,pair<int,int> > >::iterator position;
    for(position = arbolExpMin.begin();position!=arbolExpMin.end();position++){

        for (int i=0; i<V+1; i++){
           if (grafo.verts[i].numVertice==position->second.first ){
                 a=grafo.verts[i].nombre;
           }
       }

       for (int e=0; e<V+1; e++){
           if (grafo.verts[e].numVertice==position->second.second ){
                 b=grafo.verts[e].nombre;
           }
       }
       listOfVerts->append(to_string(position->second.first)+"-"+to_string(position->second.second));
       listOfVerts->append(to_string(position->second.second)+"-"+to_string(position->second.first));
    }
}

struct conjDisjuntos{
    int *padre;
    int *rank;
    int n;

    conjDisjuntos(int n){
        this->n = n;
        padre = new int[n+1];
        rank = new int[n+1];

        for(int i=0;i<=n;i++){
            rank[i] = 0;
            padre[i] = i;
        }
    }

    int Find(int u){
        if(u == padre[u]){
            return padre[u];
        }else {
            return Find(padre[u]);
        }
    }

    void Union(int x,int y){
        x = Find(x);
        y = Find(y);
        if(x != y){
            if(rank[x] < rank[y]){
                rank[y] += rank[x];
                padre[x] = y;
            }
            else{
                rank[x] += rank[y];
                padre[y] = x;
            }
        }
    }
};

int GrafoKruskal::kruskal(){
    int peso = 0;
    sort(ejes.begin(),ejes.end());
    conjDisjuntos conjDisj(this->V);

    vector<pair<int,pair<int,int> > >::iterator position;
    // para todos los ejes en G
    for(position = ejes.begin(); position!=ejes.end();position++){
        int u = position->second.first;
        int v = position->second.second;

        int setU = conjDisj.Find(u);
        int setV = conjDisj.Find(v);


        if(setU != setV){
            int w = position->first;
            arbolExpMin.push_back({w,{u,v}});
            peso += position->first;

            conjDisj.Union(setU,setV);
        }
    }
    return peso;
}
