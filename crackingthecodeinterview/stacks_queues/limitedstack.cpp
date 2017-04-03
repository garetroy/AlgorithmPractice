#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void
pushLimited(vector<stack<int>> &in, int invar)
{
    if(in.size() == 0 || in.at(in.size() - 1).size() == 3)
        in.emplace_back(stack<int>());
    
    in.at(in.size() - 1).emplace(invar); 

    return;
}

void
popLimited(vector<stack<int>> &in)
{
    int insize = in.size() - 1;
    in.at(insize).pop();
    
    if(in.at(insize).size() == 0)
        in.erase(in.end() - 1);

    return;
}

void
printHead(vector<stack<int>> &in)
{
    if(in.size() == 0)
        return;

    cout << in.at(in.size() - 1).top() << endl;
    
    return;
}  

int
main()
{
    vector<stack<int>> in;
    pushLimited(in,3);
    printHead(in);
    pushLimited(in,4);
    pushLimited(in,5);
    cout << "size is: " << in.size() << endl;
    pushLimited(in,10);
    cout << "size is: " << in.size() << endl;
    printHead(in);
    popLimited(in);
    cout << "size is: " << in.size() << endl;
    printHead(in);
    popLimited(in);
    popLimited(in);
    popLimited(in);
    printHead(in);
    cout << "size is: " << in.size() << endl;
    
    return 0;
}
