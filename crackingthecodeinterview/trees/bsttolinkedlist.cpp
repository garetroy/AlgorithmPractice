#include <iostream>
#include <vector>

#include "bst.h"

using std::ostream;
using std::vector;
using std::cerr;
using std::endl;


template <typename T>
void
GetLeveledLL(Node<T>* innode, vector<LinkedList<T>*>& in, int level=0)
{
    //This adds a link list per level of the tree
    if(innode == nullptr)
        return;

    LinkedList<T>* newlist;
    if(in.size() == level){
        newlist = (LinkedList<T>*) new LinkedList<T>();
        in.push_back(newlist);
    }else{
        newlist = in.at(level);
    }
    
    newlist->add_node(innode);
    GetLeveledLL(innode->left, in, level + 1);
    GetLeveledLL(innode->right, in, level + 1);
}

int
main()
{
    BST<double> in;
    in.Insert(3.2);
    in.Insert(1.2);
    in.Insert(4.2);
    
    vector<LinkedListd*> ll;
    GetLeveledLL(in.root,ll);
    cerr << *ll[1] << endl;
    cerr << in << endl;
    return 0;
}
