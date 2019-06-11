#ifndef KRUSKAL_H
#define KRUSKAL_H
#include "grafomatriz.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "iostream"
#include "fstream"
#include "linkedlist.h"
using namespace std;

class Graph{
private:
        int V,E;
        vector<pair<int,pair<int,int> > > edges;
        vector<pair<int,pair<int,int> > > MST;
public:
        Graph(int V,int E);
        void addEdge(int u,int v,int w);
        int kruskalMST();
        void printMST(GrafoMatriz, LinkedList<string> *);
};
#endif // KRUSKAL_H
