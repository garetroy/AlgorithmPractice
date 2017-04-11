#include <iostream>
#include <vector>
#include "node.h"

using namespace std;

template <typename T>
struct MinTree{
    
        Node<T>* root;

        MinTree(void) : root(NULL) {}
        
        Node<T>* BuildMinTree(T*, int, int);
        void     Traverse(Node<T>*, ostream&);

        friend ostream &operator<<(ostream& os, MinTree& mt)
        {
            mt.Traverse(mt.root,os);
            return os;
        } 
};

template <typename T>
Node<T>*
MinTree<T>::BuildMinTree(T* in, int start, int end)
{
    if(start > end || end == 0)
        return NULL;

    int middle    = ((start+end)/2);
    Node<T>* root = new Node<T>(in[middle]);
    root->left    = BuildMinTree(in,start,middle-1); 
    root->right   = BuildMinTree(in,middle+1,end);
    return root;
}

template <typename T>
void
MinTree<T>::Traverse(Node<T>* in, ostream& os)
{
    os << "->" << *in;
    cerr << in->value << endl;
    Traverse(in->left,os);
    Traverse(in->right,os);
}

int
main()
{
    MinTree<int> tree;
    int array[6] = {3,4,5,6,7,8};
    tree.BuildMinTree(array,0,5);
    
    cout << tree << endl;

    return 1;
}
