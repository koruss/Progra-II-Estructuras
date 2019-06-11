#include "puntosdearticulacion.h"

GrafoArticulacion::GrafoArticulacion(int V)
{
    ofstream archivo;
    archivo.open("PuntosArticulacion.txt", ios::out);
    archivo<<"DOCUMENTO DEL RECORRIDO PUNTOS DE ARTICULACION\n\n"<<endl;
    archivo<<"Recorrido:"<<endl;
    archivo.close();

    this->V = V;
    adj = new list<int>[V];
}

void GrafoArticulacion::insertarVertice(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

// Funcion para encontrar los puntos de articulacion
// u --> Vertice a visitar
// visited[] --> realiza un seguimiento de los vértices visitados
// disc[] --> Almacena tiempos de descubrimiento de vértices visitados.
// parent[] --> Almacena los vértices padre en el árbol
// ap[] --> Almacenar puntos de articulación.
void GrafoArticulacion::APUtil(int u, bool visited[], int disc[],int low[], int parent[], bool ap[])
{

    // Se usa una variable estática para simplificar, podemos evitar el uso de estática
    // variable pasando un puntero.
    static int time = 0;

    // Conteo de los hijos en el arbol
    int children = 0;

    // Marque el nodo actual como visitado
    visited[u] = true;

    // Inicializar tiempo de descubrimiento y bajo valor.
    disc[u] = low[u] = ++time;

    // Ir a través de todos los vértices adyacentes a este
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {

        int v = *i;  // v is current adjacent of u

        // Si v no se ha visitado todavía, entonces conviértalo en un hijo de u
        // en el árbol DFS y se repite para ello
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            APUtil(v, visited, disc, low, parent, ap);

            // Compruebe si el subárbol arraigado con v tiene una conexión a
            // uno de los ancestros de u
            low[u]  = min(low[u], low[v]);

            // u es un punto de articulación en los siguientes casos

            // (1) u es la raíz del árbol y tiene dos o más hijos.
            if (parent[u] == NIL && children > 1){
               ap[u] = true;
               cout<<ap[u]<<" Es punto de articulacion, pues tiene dos hijos"<<endl;
            }


            // (2) Si u no es raiz y el valor bajo de uno de sus hijos es mayor
            // que el valor de descubrimiento de u.
            if (parent[u] != NIL && low[v] >= disc[u]){
               ap[u] = true;
               cout<<ap[v]<<" Es punto de articulacion "<< disc[u]<<" es menor que "<<low[v]<<endl;
            }
        }

        // Actualice el valor bajo de u para las llamadas de la función principal.
        else if (v != parent[u]){
            low[u]  = min(low[u], disc[v]);

        }
    }

}

// La función para hacer el recorrido DFS. Utiliza función recursiva APUtil ()
void GrafoArticulacion::AP(GrafoMatriz g, int entrada)
{
    string a;

    // Marca todos los vértices como no visitados.
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    bool *ap = new bool[V]; // Almacenar puntos de articulación.

    // Inicializar matrices de padres y visitas, y ap (punto de articulación)
    for (int i = 0; i < V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
        ap[i] = false;
    }

    // Llame a la función de ayuda recursiva para encontrar puntos de articulación
    // en el árbol DFS arraigado con el vértice 'i'
    if (visited[entrada] == false)
        APUtil(entrada, visited, disc, low, parent, ap);


    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            APUtil(i, visited, disc, low, parent, ap);

    for (int i = entrada+1; i < V; i++)
        if (visited[i] == false)
            APUtil(i, visited, disc, low, parent, ap);

    // Ahora ap [] contiene puntos de articulación, imprímelos
    for (int i = 0; i < V; i++){
        if (ap[i] == true){
            for (int j=0; j<g.numVerts; j++){
                if (g.verts[j].numVertice==i ){
                      a=g.verts[j].nombre;
                }
            }
          escribirArchivo(a);
          cout << a << "->";
        }
    }
    cout<<endl;
}

void GrafoArticulacion::escribirArchivo(string dato){
        ofstream archivo;
        string flecha="->";

        archivo.open("PuntosArticulacion.txt", ios::app);

        if (archivo.fail()) {
            cout << "No se pudo abrir el archivo" << endl;
        }else{
           archivo<<dato<<flecha;
        }
        archivo.close();
}
