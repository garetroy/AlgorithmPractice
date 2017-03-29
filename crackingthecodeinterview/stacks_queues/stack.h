/* This is just an implementation of a stack that I created */
#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct Node{ //By default public
    T       value;
    Node<T> *next; 

    inline bool operator==(const Node& in) const
    {
        return (next == in.next) && (value == in.data);
    } 

    friend ostream &operator<<(ostream &os, const Node& n)
    {
        return os << n.data;
    }
};

template <class T> class Stack;
template <class T>
ostream& operator<<(ostream& out, Stack<T>& in);

template <class T>
class Stack{
    
    private://Classes default private
        Node<T> *head;
        int      size;

    public:
    
            Stack()  {head = NULL; size = 0;};
            ~Stack()   
            {
                Node<T> *temp = head;
                Node<T> *next = NULL;
                while(temp != NULL){
                    next = temp->next;
                    delete temp;
                    temp = next;
                }
            }

                   Node<T>* popHead(bool out=false);
                   void     readHead(ostream &os);
                   int      pushNode(Node<T> &in);
                   void     pushType(T in);
            inline bool     operator==(const Stack<T>& in) const;
            
            friend ostream &operator<<(ostream &os, Stack<T>& in);
                    
}; 
typedef Stack<int>  Stacki;
typedef Stack<char> Stackc;

#endif
