#include <iostream>
#include "stack.h"

void
push(Stacki *stacks, int in)
{
    if(stacks[0].readHead() == NULL){
        stacks[0].pushType(in);
        stacks[1].pushType(in);
        return;
    }else if(in < stacks[1].readHead()->value){
        stacks[0].pushType(in);
        stacks[1].pushType(in);
        return; 
    }

    stacks[0].pushType(in);
    return;
}

void
pop(Stacki *stacks)
{
    if(stacks[0].readHead() == NULL)
        return;

    int maindata = stacks[0].readHead()->value;
    int mindata  = stacks[1].readHead()->value;

    if(maindata == mindata){
        stacks[0].popHead(); 
        stacks[1].popHead();
    } else {
        stacks[0].popHead();
    }
}

int
getMin(Stacki *stacks)
{
    if(stacks[1].readHead() == NULL){
        cerr << "Error, stacks are empty" << endl;
        return -1;
    }

    return stacks[1].readHead()->value;
}

int
main()
{
    Stacki stacks[2]; 

    push(stacks, 2);
    push(stacks, 5);
    push(stacks, 8);
    push(stacks, 1);
    push(stacks, -4); 
    cout << stacks[0] << endl;
    cout << stacks[1] << endl;

    pop(stacks);
    pop(stacks);
    cout << stacks[0] << endl;
    cout << stacks[1] << endl;

    pop(stacks);
    cout << getMin(stacks) << endl;
    pop(stacks);
    pop(stacks);
    pop(stacks); // Testing

    cout << getMin(stacks) << endl; 

    return 0;
}    
