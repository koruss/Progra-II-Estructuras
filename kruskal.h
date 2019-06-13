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

class GrafoKruskal{
private:
        int V,E;
        vector<pair<int,pair<int,int> > > ejes;
        vector<pair<int,pair<int,int> > > arbolExpMin;
public:
        GrafoKruskal(int V,int E);
        void addEdge(int u,int v,int w);
        int kruskal();
        void print(GrafoMatriz, LinkedList<string> *);
};
#endif // KRUSKAL_H
