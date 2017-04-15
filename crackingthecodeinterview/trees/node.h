#ifndef _NODE_H_
#define _NODE_H_

using namespace std;

template <typename T>
struct Node{
    
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
    Node<T>* next;
    T        data;
    int      depth;

    Node(void)   : left(nullptr), right(nullptr), parent(nullptr), next(nullptr), depth(0), data(T())  {}
    Node(T data) : left(nullptr), right(nullptr), parent(nullptr), next(nullptr), depth(0), data(data) {}

    bool operator<=(Node<T>& in){return data < in.data;}
    bool operator>(Node<T>& in){return data > in.data;}
    bool operator==(Node<T>& in){return data == in.data;}

    friend ostream& operator<<(ostream& os, const Node<T>& in)
    {
        os << "Node:data=" << in.data << " depth=" << in.depth << " ";
        return os;
    }
};

#endif
