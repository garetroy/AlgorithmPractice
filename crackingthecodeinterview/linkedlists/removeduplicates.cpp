#include <iostream>
#include <list>
#include <set>

using namespace std;

int
main()
{
    list<int> myllist; 
    myllist.emplace_back(1);
    myllist.emplace_back(2);
    myllist.emplace_back(3);
    myllist.emplace_back(3);
    myllist.emplace_back(10);
    myllist.emplace_back(15);
    myllist.emplace_back(15);
    myllist.emplace_back(15);

    set<int> myset;  //choose ordered set because lgn search
    for( int n : myllist) {
        myset.emplace(n);
    }

    /* NOTE: for list you can use .unique to remove duplicates
    myllist.unique();
    for(int n : myllist) 
        cout << n << endl;
    */
    

    for(int n : myset)
        cout << n << endl; 
    
}
