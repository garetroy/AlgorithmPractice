/*
    This program partitions a single-linked-list from a given integer. Ex: 8->4->3->7->5 partitioned at 5 would look like this..
    4->3->8->7->5 (they only need to be partitioned, not ordered
*/

#include <iostream>
#include <forward_list>

using namespace std;

forward_list<int>
partition_list(forward_list<int> &list, int num)
{
    forward_list<int> lessthan {};
    forward_list<int> greatereq {};
    
    for(int i : list) //O(n)
        if(i < num){
            lessthan.emplace_front(i);
        } else {
            greatereq.emplace_front(i);
        }
    
    lessthan.merge(greatereq); //O(n)

    return lessthan;
}     


int
main()
{
    forward_list<int> list {};
    list.emplace_front(10);
    list.emplace_front(15);
    list.emplace_front(2);
    list.emplace_front(13);
    list.emplace_front(7);
    list.emplace_front(44);
    list.emplace_front(12);

    forward_list<int> result = partition_list(list,15);

    for(int i : result)
        cout << i << " ";

    cout << endl;
}
