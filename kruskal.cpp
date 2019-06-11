#include "kruskal.h"
#include "linkedlist.h"

Graph::Graph(int V,int E){
    this->V = V;
    this->E = E;
}
void Graph::addEdge(int u,int v,int w){
    edges.push_back({w,{u,v}});
}

void Graph::printMST(GrafoMatriz grafo, LinkedList<string> *listOfVerts){
    string a;
    string b;

    vector<pair<int,pair<int,int> > >::iterator it;
    for(it = MST.begin();it!=MST.end();it++){

        for (int i=0; i<V+1; i++){
           if (grafo.verts[i].numVertice==it->second.first ){
                 a=grafo.verts[i].nombre;
           }
       }

       for (int e=0; e<V+1; e++){
           if (grafo.verts[e].numVertice==it->second.second ){
                 b=grafo.verts[e].nombre;
           }
       }
//       cout << it->second.first << " - " << it->second.second << endl;
       listOfVerts->append(to_string(it->second.first)+"-"+to_string(it->second.second));
       listOfVerts->append(to_string(it->second.second)+"-"+to_string(it->second.first));
    }
}
struct DisjointSet{
    int *parent,*rnk;
    int n;

    DisjointSet(int n){
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];

        for(int i=0;i<=n;i++){
            rnk[i] = 0;
            parent[i] = i;
        }
    }
    int Find(int u){
        if(u == parent[u]) return parent[u];
        else return Find(parent[u]);
    }

    void Union(int x,int y){
        x = Find(x);
        y = Find(y);
        if(x != y){
            if(rnk[x] < rnk[y]){
                rnk[y] += rnk[x];
                parent[x] = y;
            }
            else{
                rnk[x] += rnk[y];
                parent[y] = x;
            }
        }
    }
};

int Graph::kruskalMST(){
    int MSTWeight = 0;
    sort(edges.begin(),edges.end());
    DisjointSet ds(this->V);

    vector<pair<int,pair<int,int> > >::iterator it;
    // para todos los ejes en G
    for(it = edges.begin(); it!=edges.end();it++){
        int u = it->second.first;
        int v = it->second.second;

        int setU = ds.Find(u);
        int setV = ds.Find(v);


        if(setU != setV){
            int w = it->first;
            MST.push_back({w,{u,v}});
            MSTWeight += it->first;

            ds.Union(setU,setV);
        }
    }
    return MSTWeight;
}
