#include "stack.h"
#include "twostackqueue.h"

//Pops the head from the stack, prints the popped value/desiredostream if desired

int
main()
{
    Stacki ourstack;

    ourstack.pushType(5);
    ourstack.pushType(10);

    cout << ourstack << endl;

    Node<string> *node = (Node<string>*) new Node<string>;
    
    node->value = "I'm here!";
    node->next  = NULL;

    Stacks ourstringstack;
    ourstringstack.pushType("Cow Bow");
    ourstringstack.pushNode(node);
    cout << ourstringstack << endl;

    Node<string> *temp = ourstringstack.popHead(true); 
    cout << "Should be == 1: " << (temp == node) << endl;
    temp = ourstringstack.popHead(true);
    cout << "Should be == 1: " << (temp != node) << endl;

    TwoStackQueuei twostack;

    twostack.pushType(15);
    twostack.pushType(43);

    cout << twostack << endl;
    cout << "Dequeued and popped: " << *twostack.dequeue() << endl;
    cout << twostack << endl;

    twostack.pushType(12);
    
    cout << twostack << endl;

    for(int i = 0; i < 2; i++)
        twostack.dequeue(); 

    cout << twostack << endl; 

    return 0;
}
