#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#define DEFAULT_MAX_SIZE 1024
#include "list.h"
#include "node.h"
#include <stdexcept>
#include <iostream>


using namespace std;

template <typename E>
class LinkedList : public List <E>
{
private:
    Node<E>* head;
    Node<E>* tail;
    Node<E>* current;
    int size;
public:
    LinkedList(){
        head=tail=current=new Node<E>();
        size=0;
    }
    ~LinkedList(){
        clear();
        delete head;
    }

    void insert(E element){
        current->next=new Node<E>(element, current->next);
        if(current==tail){
            tail=tail->next;
        }
        size++;
    }

    void append(E element){
        tail->next=new Node<E>(element);
        tail=tail->next;
        size++;
    }

    E remove(){
        if(current->next==NULL){
            throw runtime_error("No element to remove.");
        }
        E result=current->next->element;
        Node<E> *temp=current->next;
        current->next=current->next->next;
        if(current->next==NULL){
            tail=current;
        }
        delete temp;
        size--;
        return result;
    }

    void clear(){
        current = head->next;
        while(head->next!=NULL){
            head->next=current->next;
            delete current;
            current =head->next;
        }
        size=0;
        tail=current=head;
    }

    E getElement(){
        if(size==0)throw runtime_error("list is empty");
        if(current==tail)throw runtime_error("No current element");
        return current->next->element;
    }

    void goToStart(){
        current=head;
    }


    void goToEnd(){
        current=tail;
    }

    void goToPos(int pos){
        if(0>pos||pos>size)throw runtime_error("Index out of Bounds");
        current=head;
        for(int i=0;i<pos;i++){
            current=current->next;
        }
    }

    void previous(){
        if(current!=head){
            Node<E> *temp=head;
            while (temp->next!=current) {
                temp=temp->next;
            }
            current=temp;
        }
    }

    void next(){
        if(current!=tail)current=current->next;
    }


    bool atStart(){
        return current==head;
    }

    bool atEnd(){
        return current==tail;
    }

    int getPos(){
        int pos=0;
        Node<E> *temp= head;
        while(temp!=current){
            pos++;
            temp=temp->next;
        }
        return pos;
    }

    int getSize(){
        return size;

    }

    void print(){
        cout<<endl<<"Lista: ";
        for(goToStart();!atEnd();next()){
            cout<<getElement()<<"   ";
        }
    }

    bool contains(E key){
        Node<E> *aux;
        aux=head->next;
        while(aux){
            if(aux->element==key){
                return true;
            }
        }
        return false;
    }

    int indexOf(E key){
        Node<E> *aux;
        aux=head->next;
        int cont=0;
        while(aux){
            if(aux->element==key){
                return cont;
            }
            cont++;
        }
        return -1;
    }


    void reverse(){
        Node<E> *newElement;
        Node<E> *first=head->next;
        Node<E> *prev=tail->next;

        while(first!=NULL){
            newElement=first;
            first=first->next;
            newElement->next=prev;
            prev=newElement;
        }
        head->next=prev;
    }

    bool equals(List<E> *L1){
        bool is;
        if(L1->getSize()==size){
            while(getElement()==L1->getElement() && current->next!=tail){
                next();
                L1->next();
                is=true;
            }
            if(is){
                return true;
            }else {
                return false;
            }
        }else{
            is=false;
        }
        return is;
    }

    int find(E element){
        for(goToStart();!atEnd();next()){
            if(element==getElement()){
                return getPos();
            }
        }
    }

    void appendMod(E element, E element2){
        if(!contains(element)){
            tail->next=new Node<E>(element);
            tail=tail->next;
            tail->listaAdyacentes->append(element2);
            size++;
        }else{
            int pos=find(element);
            goToPos(pos);
            current->appendList(element2);
        }



    }


    Node<E> *getCurrent()
    {
        return current;
    }

    void setCurrent(Node<E> *value)
    {
        current = value;
    }

};




#endif // LINKEDLIST_H
