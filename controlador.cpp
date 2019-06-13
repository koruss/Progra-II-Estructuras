#include <iostream>
#include <math.h>
#include "controlador.h"
#include "arraylist.h"

Controlador::Controlador(){}

void Controlador::leerVertice(GrafoMatriz &g, int num){
    int largo=num;
    int ancho=num;
    int tamanno=largo*ancho;

    for(int i=1; i<=tamanno; i++){
        string texto=to_string(i);
        introducirVertice(texto, g);
    }
}

void Controlador::introducirVertice(string texto, GrafoMatriz &g){
        string Vert="";
        for(int i=0; i<texto.size(); i++){
            Vert=Vert+texto[i];
        }
        g.nuevoVertice(Vert);
}

int Controlador::leerConexiones(GrafoMatriz &g){
    int numVerts=g.numVerts;
    int limit=sqrt(numVerts);
    int cont=0;

    for(int i=1; i<numVerts; i++){
        if(i%limit!=0){
            string salida=to_string(i);
            string llegada=to_string(i+1);
            string texto;
            texto= salida+";"+llegada+";1";
            introducirConexiones(texto, g);
            cont++;
        }
    }

    for(int i=1; i<=numVerts-limit; i++){
        string salida=to_string(i);
        string llegada=to_string(i+limit);
        string texto;
        texto= salida+";"+llegada+";1";
        introducirConexiones(texto, g);
        cont++;
    }
    return cont;
}

void Controlador::introducirConexiones(string texto, GrafoMatriz &g){
    int cambiarVariable=0;
    string salida="";
    string salida2="";
    string llegada="";
    string llegada2="";
    string peso="";

    for(unsigned int i=0; i<texto.size(); i++){
            if(texto[i]!=';'){
                   if(cambiarVariable==0){
                        salida=salida+texto[i];
                        llegada2=llegada2+texto[i];
                   }else if (cambiarVariable==1){
                        llegada=llegada+texto[i];
                        salida2=salida2+texto[i];
                   }else{
                       peso=peso+texto[i];
                   }
            }else{
                cambiarVariable=cambiarVariable+1;
            }

    }
    int pesoNumero=rand()%5;
    g.nuevoArco(salida, llegada, pesoNumero);
    g.nuevoArco(salida2, llegada2, pesoNumero);
}

void Controlador::leerKruskal(GrafoKruskal &g, int numVerts){
    int limit=sqrt(numVerts);
    for(int i=1; i<numVerts; i++){
        if(i%limit!=0){
            string salida=to_string(i);
            string llegada=to_string(i+1);
            string texto;
            texto= salida+";"+llegada+";1";
            introducirKruskal(texto, g);
        }
    }

    for(int i=1; i<=numVerts-limit; i++){
        string salida=to_string(i);
        string llegada=to_string(i+limit);
        string texto;
        texto= salida+";"+llegada+";1";
        introducirKruskal(texto, g);
    }
}

void Controlador::introducirKruskal(string texto, GrafoKruskal &g){
    int cambiarVariable=0;
    string salida="";
    string llegada="";
    string peso="";

    for(int i=0; i<texto.size(); i++){
            if(texto[i]!=';'){
                   if(cambiarVariable==0){
                        salida=salida+texto[i];
                   }else if (cambiarVariable==1){
                        llegada=llegada+texto[i];
                   }else{
                       peso=peso+texto[i];
                   }
            }else{
                cambiarVariable=cambiarVariable+1;
            }

    }

    int sal=atoi(salida.c_str());
    int lleg=atoi(llegada.c_str());
    int pesoNumero=rand()%9;
    g.addEdge(sal, lleg, pesoNumero);
}

void Controlador::leerArticulacion(GrafoArticulacion &g1){
    ifstream archivo;
    string texto;

    archivo.open("C:\\Users\\admin\\Desktop\\Conexiones.txt", ios::in);

    if(archivo.fail()){
        cout<<"Error al abrir el archivo archivo"<<endl;
        exit(1);
    }

    while(!archivo.eof()){
        getline(archivo, texto);
        introducirArticulacion(texto, g1);
    }
    archivo.close();
}

void Controlador::introducirArticulacion(string texto, GrafoArticulacion &g1){
    int cambiarVariable=0;
    string salida="";
    string llegada="";

    for(int i=0; i<texto.size(); i++){
            if(texto[i]!=';'){
                   if(cambiarVariable==0){
                        salida=salida+texto[i];
                   }else if (cambiarVariable==1){
                        llegada=llegada+texto[i];
                   }
            }else{
                cambiarVariable=cambiarVariable+1;
            }

    }
    int sal=atoi(salida.c_str());
    int lleg=atoi(llegada.c_str());

    g1.insertarVertice(sal, lleg);
}

void Controlador::addEdge(GrapoProfundidad &g1, int numVerts){
    int limit=sqrt(numVerts);
        for(int i=1; i<numVerts; i++){
            if(i%limit!=0){
                int salida=i;
                int llegada=i+1;
                g1.addEdge(salida, llegada);
            }
        }

        for(int i=1; i<=numVerts-limit; i++){
            int salida=i;
            int llegada=i+limit;
            g1.addEdge(salida, llegada);
        }
}
