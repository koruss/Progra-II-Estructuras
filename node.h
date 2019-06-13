#include <iostream>
#include "arraylist.h"
#ifndef NODE_H
#define NODE_H
template<typename E>
class Node{

public:
    E element;//El elemento usa un template
    ArrayList<int> *listaAdyacentes;

    Node<E>* next;
    Node(E element, Node<E>* next=NULL){
        this->element=element;
        this->next=next;
        listaAdyacentes=new ArrayList<int>();
    }

    Node(Node<E>* next=NULL){
        this->next=next;
    }


    void appendList(int element){
        listaAdyacentes->append(element);
    }

};
#endif // NODE_H
