#include <iostream>
#include <stack>

using namespace std;

void
dequeue(stack<int> &instack, stack<int> &outstack)
{
    while(!instack.empty()){
        outstack.emplace(instack.top());
        instack.pop();
    }

}

void
enqueue(stack<int> &instack, int in)
{
    instack.emplace(in);
}

int
main()
{
    stack<int> instack;
    stack<int> outstack;

    for(int i = 1; i < 11; i++){
        instack.emplace(i);
        if(i % 5 == 0)
            dequeue(instack, outstack);
    }
    
    dequeue(instack,outstack);
        
    cout << "Outstack became: ";
    
    while(!outstack.empty()){
        cout << outstack.top() << " ";
        outstack.pop();
    }

    cout << endl;    

    return 0;

}


