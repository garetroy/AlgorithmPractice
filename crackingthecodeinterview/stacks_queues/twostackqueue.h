/* A queue implemented from two stacks */
#ifndef _TWOSTACKQUEUE_H_
#define _TWOSTACKQUEUE_H_

#include "stack.h"

template <class T>
class TwoStackQueue{
    
    protected:
        Stack<T> *instack;
        Stack<T> *outstack;
        int      size;

    public:
            TwoStackQueue() {size = 0; instack = (Stack<T>*) new Stack<T>; outstack = (Stack<T>*) new Stack<T>;}
            ~TwoStackQueue() {delete instack; delete outstack;}

            void    pushType(T in);
            void    pushNode(Node<T> *in);
            Node<T> *dequeue();

    friend ostream &operator<<(ostream &os, const TwoStackQueue<T> &in)
    {
        os << "Instack is:" << endl;
        os << *in.instack << endl;
        os << "Outstack is:" << endl;
        os << *in.outstack << endl;
        return os;
    }
};
typedef TwoStackQueue<int>    TwoStackQueuei;
typedef TwoStackQueue<float>  TwoStackQueuef;
typedef TwoStackQueue<double> TwoStackQueued;
typedef TwoStackQueue<char>   TwoStackQueuec;
typedef TwoStackQueue<string> TwoStackQueues;

template <typename T>
void
TwoStackQueue<T>::pushType(T in)
{
    instack->pushType(in);
}

template <typename T>
void
TwoStackQueue<T>::pushNode(Node<T> *in)
{
    instack->pushNode(in);
}

template <typename T>
Node<T>*
TwoStackQueue<T>::dequeue()
{
    Node<T> *popped = instack->popHead();
    
    while(popped != NULL){
        outstack->pushNode(popped);
        popped = instack->popHead();
    }
    
    if(outstack->readHead() == NULL)
        return NULL;

    return outstack->popHead();
}
        
#endif 
