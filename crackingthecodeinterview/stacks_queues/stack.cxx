#include "stack.h"

//Pops the head from the stack, prints the popped value/desiredostream if desired

int
main()
{
    Stacki ourstack;

    ourstack.pushType(5);
    ourstack.pushType(10);

    cout << ourstack << endl;

    return 0;
}
