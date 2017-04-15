#ifndef _BST_H_
#define _BST_H_

#include <iostream>

#include "node.h"
#include "linkedlist.h"

template <typename T>
struct BST{
    
    Node<T>* root;

    BST(void) : root(nullptr) {}

    Node<T>* find(T);
    Node<T>* find(Node<T>*);
    Node<T>* find(Node<T>*,T);
    void     Insert(T);
    void     Insert(Node<T>*, Node<T>&);
    void     Delete(T);
    void     Delete(Node<T>*);
    void     RemoveParent(Node<T>*);
    void     Traverse(Node<T>*,ostream&);

    friend ostream& operator<<(ostream& os, BST<T>& in)
    {
        os << "BST(pre-order): " << endl; 
        in.Traverse(in.root,os);
        return os;
    }
};

template <typename T>
Node<T>*
BST<T>::find(T in)
{
    if(root == nullptr || in == root->data)
        return root;
    
    return find(root,in);
}

template <typename T>
Node<T>*
BST<T>::find(Node<T>* in)
{
    return find(in, in->data);
}

template <typename T>
Node<T>*
BST<T>::find(Node<T>* innode, T in)
{
    if(innode == nullptr || in == innode->data)
        return innode;

    if(in < innode->data)
        return find(innode->left,in); 

    if(in > innode->data)
        return find(innode->right,in);

    return nullptr; 
}

template <typename T>
void
BST<T>::Insert(T in)
{
    Node<T>* newnode = (Node<T>*) new Node<T>(in);

    if(root == nullptr){
        root = newnode;
        newnode->depth = 1;
        return;
    }
    
    Node<T>* tempnode = root;
    this->Insert(tempnode,*newnode);
}

template <typename T>
void
BST<T>::Insert(Node<T>* traversenode, Node<T>& addingnode)
{
    if(addingnode <= *traversenode){
        if(traversenode->left == nullptr){
            traversenode->left = &addingnode;
            addingnode.parent  = traversenode;
            addingnode.depth   = traversenode->depth + 1;
        }else{
            Insert(traversenode->left,addingnode);
        }

    }else if(addingnode > *traversenode){
        if(traversenode->right == nullptr){
            traversenode->right = &addingnode;
            addingnode.parent   = traversenode;
            addingnode.depth    = traversenode->depth + 1;
        }else{
            Insert(traversenode->right,addingnode);
        }
    
    }
}

template <typename T>
void
BST<T>::Delete(T in)
{
    Node<T>* found = find(in);

    if(found->left == nullptr && found->right == nullptr){
        RemoveParent(found);
        delete found;
    }else if(found->left == nullptr){
        RemoveParent(found->right);
        found->data = found->right->data;
        delete found;
    }else if(found->right == nullptr){
        RemoveParent(found->left);
        found->data = found->left->data;
        delete found;
    }else{
        Node<T>* temp = found->right;
        for(;temp->left;temp = temp->left)
            continue;
        RemoveParent(temp);
        found->data = temp->data;
        delete temp;
    }
}

template <typename T>
void
BST<T>::RemoveParent(Node<T>* in)
{
    if(*in->parent->left == *in)
        in->parent->left = nullptr;
    
    if(*in->parent->right == *in)
        in->parent->right = nullptr;
}

template <typename T>
void
BST<T>::Delete(Node<T>* in)
{
    this->Delete(in->data);
}

template <typename T>
void
BST<T>::Traverse(Node<T>* in, ostream& os)
{
    if(in == nullptr)
        return; 

    os << "  " << *in << endl;
    Traverse(in->left,os);
    Traverse(in->right,os);
}
#endif
