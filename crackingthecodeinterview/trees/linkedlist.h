#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <iostream>
#include "node.h"

using std::ostream;

template <typename T>
struct LinkedList{
    
    Node<T>* head;
    int      length;

    LinkedList(void) : head(nullptr), length(0) {}
    ~LinkedList(void);

    inline int  size(void) { return length; }
    inline void add_node(Node<T>*);
    inline void add_node(const T);

    friend ostream& operator<<(ostream& os, LinkedList& in)
    {
        Node<T>* temp = in.head;
        for(;temp;temp = temp->next)
            os << *temp;
        return os;
    }
};
typedef LinkedList<int>    LinkedListi;
typedef LinkedList<float>  LinkedListf;
typedef LinkedList<double> LinkedListd;

template <typename T>
LinkedList<T>::~LinkedList(void)
{
    Node<T>* temp = head;
    for(;temp;temp = temp->next)
        delete temp;
}

template <typename T>
inline void
LinkedList<T>::add_node(Node<T>* in)
{
    if(in == nullptr)
        return;

    length += 1;

    if(head == nullptr){
        head = in;
        return;
    }

    Node<T>* temp = head;
    for(;temp->next;temp = temp->next)
        continue;

    temp->next = in;
}

template <typename T>
inline void
LinkedList<T>::add_node(const T in)
{
    Node<T>* newnode = (Node<T>*) new Node<T>;
    
    this->add_node(newnode); 
}
#endif
