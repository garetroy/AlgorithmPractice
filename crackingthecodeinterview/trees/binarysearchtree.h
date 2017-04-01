#ifndef _BINARYSEARCHTREE_H_
#define _BINARYSEARCHTREE_H_

#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct Tree{
    Tree<T> *left;
    Tree<T> *right;
    T       data;

    Tree(){};
    ~Tree(){if(left!=NULL)delete left; if(right!=NULL)delete right;}
};

template <class T>
class BST{

    private:
        Tree<T> *root; 
    
    public:

        BST(){root->data = 0; root = (Tree<T>*) new Tree<T>; root->left = NULL; root->right = NULL;}
        BST(T _data){root->data = _data; root->left = NULL; root->right = NULL;}
       ~BST(){delete root;}


        void     addType(T in);
        void     removeData(T in);
        Tree<T>* find(T in);
        Tree<T>* popData(T in);
};

template <typename T>
void
BST<T>::addType(Tree<T>* current, T in)
{
    if(in < current->root->data){
        if(current->root->left == NULL){
            current->root->left = (Tree<T>*) new Tree<T>;
            current->root->left->root>data = data;
            return;
        }else{
            addNode(current->root->left,in);
        }
    }else if(in >= current->root->data){
        if(current->root->right == NULL){
            current->root->right = (Tree<T>*) new Tree<T>;
            current->root->right->root->data = data;
            return;
        }else{
            addNode(current->root->right,in);
        }
    }
}

template <typename T>
void
BST<T>::removeData(T in)
{
    Tree<T>* node = find(in);
    if(node->left == NULL && node->right == NULL)
        delete node;
    if(node->left == NULL && node->right != NULL){
        node->root->data = node->root->right->data;
        

}

template <typename T>
Tree<T>*
BST<T>::find(Tree<T>* current, T in)
{
    if(in < current->root->data){
            addNode(current->root->left,in);
    }else if(in > current->root->data){
            addNode(current->root->right,in);
    }
}
#endif
