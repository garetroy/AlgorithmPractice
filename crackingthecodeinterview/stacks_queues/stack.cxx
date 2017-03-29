#include "stack.h"

//Pops the head from the stack, prints the popped value/desiredostream if desired
template<typename T>
Node<T>*
Stack<T>::popHead(bool out)
{
    Node<T> *popped = head;
            head    = popped->next;
    
    if(out)
        cout << "Popped value is: " << head->value << endl; 
    
    size--;

    return popped;
}

//Prints the head of the stack into the given ostream
template<typename T>
void 
Stack<T>::readHead(ostream &os)
{
    os << "Head is: " << head->value << endl;
}

//Pushes a node onto the stack Returns 0 if failure; 1 on success
template<typename T>
int
Stack<T>::pushNode(Node<T> &in)
{
    in.next = head;
    head    = &in; 

    if(in == NULL)
        return 0; 

    if(*head != in)
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

template <typename T>
inline void
Stack::print(ostream &os)
{
    Node<T> *node = in;
    in.pushNode(in);
    while(node != NULL){
        os << node << " ";
        node = node->next;
    }

    return os;

}
