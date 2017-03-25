#include <iostream>

using namespace std;

typedef struct node{
        int  data;
        node *next;
}node;

typedef struct ll{
    node *head;
}ll;

void
remove_item(node &input)
{
    node *nextnode   = NULL;
    node *currnode   = &input;

    while(currnode->next != NULL){
        nextnode       = currnode->next;
        currnode->data = nextnode->data;
        currnode       = nextnode;
    }

    delete currnode;
}

void
insert_item(ll &list, int num)
{
    node *newnode  = new node;
    newnode->data  = num;
    newnode->next  = list.head;
    list.head      = newnode; 
}

void
clean_ll(ll &list)
{
    node *curr = list.head;
    node *next = NULL;
    while(next != NULL){
        curr =  next;
        next = curr->next;
        delete curr;
    }

    if(curr != NULL)
        delete curr;
}

void
print_ll(ll &list)
{
    node *curr = list.head;

    while(curr->next != NULL){
        cout << curr->data;
        curr = curr->next;
    }
    cout << endl;
}
        

int
main(void)
{
    
    ll list; 
    list.head       = new node;
    list.head->data = 10;
    list.head->next = NULL;
    
    insert_item(list,15);
    insert_item(list,20);
    insert_item(list,9);
    insert_item(list,14);
    insert_item(list,12);

    print_ll(list);
    
    //Geting the node to pass to function
    node *currnode = list.head;
    for(int i = 0; i < 3; i++)
        currnode = currnode->next;

    remove_item(*currnode);

    print_ll(list);

    clean_ll(list);

    return 0;
}
