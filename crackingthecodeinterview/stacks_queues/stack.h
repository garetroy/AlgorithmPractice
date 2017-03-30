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

    inline bool operator!=(const Node& in) const
    {
        return (next != in.next) || (value != in.data);

    }

    friend ostream &operator<<(ostream &os, const Node& n)
    {
        return os << n.value;
    }
};

template <class T> class Stack;
template <class T>
ostream& operator<<(ostream& out, const Stack<T>& in);

template <class T>
class Stack{
    
    protected://Classes default private
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
                   Node<T>* readHead();
                   int      pushNode(Node<T> *in);
                   void     pushType(T in);
            inline bool     operator==(const Stack<T>& in) const;
            
            friend ostream &operator<<(ostream &os, const Stack<T>& in)
            {
                Node<T> *node = in.head;
                while(node != NULL){
                    os << *node << " ";
                    node = node->next;
                }

                return os;
            }
}; 
typedef Stack<int>    Stacki;
typedef Stack<float>  Stackf;
typedef Stack<double> Stackd;
typedef Stack<char>   Stackc;
typedef Stack<string> Stacks;

template<typename T>
Node<T>*
Stack<T>::popHead(bool out)
{
    if(head == NULL)
        return NULL;

    Node<T> *popped = head;
            head    = popped->next;
    
    if(out)
        cout << "Popped value is: " << popped->value << endl; 
    
    size--;

    return popped;
}
//Prints the head of the stack into the given ostream
template<typename T>
Node<T>*
Stack<T>::readHead()
{
    return head;
}

//Pushes a node onto the stack Returns 0 if failure; 1 on success
template<typename T>
int
Stack<T>::pushNode(Node<T> *in)
{
    in->next = head;
    head     = in; 

    if(in == NULL)
        return 0; 

    if(head != in)
        return 0;

    size++;

    return 1;
}

template<typename T>
void
Stack<T>::pushType(T in)
{
    Node<T> *newnode = (Node<T>*) new Node<T>;

    newnode->value = in;
    newnode->next  = head;
    head           = newnode;
    
    size++;

}

template<typename T>
inline bool Stack<T>::operator==(const Stack<T>& in) const
{  
    Node<T> *firstnode = in.popHead(); 
    Node<T> *currentno = head;

    in.pushNode(firstnode);

    if(currentno == NULL && firstnode == NULL)
        return true;

    while(firstnode != NULL && currentno != NULL){
        if(currentno != firstnode)
            return false;

        currentno  = currentno->next;
        firstnode = firstnode->next;
    }         

    if(!(currentno != NULL) != !(firstnode != NULL))
            return false;

    return true;
} 
#endif
