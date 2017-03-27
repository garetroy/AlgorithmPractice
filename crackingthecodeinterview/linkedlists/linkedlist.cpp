#include <iostream>

using namespace std;

struct node{
    node* next;
    int   data;

    inline bool operator==(const node& in) const
    {
        return (next == in.next) && (data == in.data);
    }
    
    friend ostream &operator<<(ostream &os, const node& n)
    {
        return os << n.data;
    }
};

struct ll{
    node* head;

    ll()
    {
        head = NULL;
    }
    
    ~ll()
    {
        node* temp = head;
        node* next = NULL;
        while(temp != NULL){
            next = temp->next;
            delete temp;
            temp = next;
        }
    }

    inline void add_node(node* in)
    {
        if(in == NULL)
            return;

        if(head == NULL){
            head = in;
            return;
        }

        in->next = head;
        head = in;
    }
            
    inline void add_node(const int data)
    {
        if(head == NULL){
            head  = (node*) new node;
            head->data  = data;
            return;
        }

        node* new_node = (node*) new node;
        new_node->next = head;
        new_node->data = data;
        head           = new_node;
    }
};

int
main()
{
    int i = 0;

    ll list = ll();
    list.add_node(42);
    list.add_node(18);
    list.add_node(5);
    list.add_node(8);
    list.add_node(7);
    list.add_node(8); 
    list.add_node(4);
    list.add_node(2);

    node* newnode = (node*) new node;
    newnode->data = 12;
    newnode->next = NULL;
    list.add_node(newnode);
    
    list.add_node(74);
    return 0;
}
