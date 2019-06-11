#include <iostream>
#ifndef NODE_H
#define NODE_H
template<typename E>
class Node{

public:
    E element;//El elemento usa un template

    Node<E>* next;
    Node(E element, Node<E>* next=NULL){
        this->element=element;
        this->next=next;
    }

    Node(Node<E>* next=NULL){
        this->next=next;
    }
};
#endif // NODE_H
