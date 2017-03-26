/*
    This program takes two single-linked-lists with integers represented as chars and adds them together
*/

#include <iostream>
#include <forward_list>
#include <string>

using namespace std;

/*
    In this method I am using string concatination, which is logn time.... This can create more complexity than needed
    if this was a bottole neck, or absolute preformance was needed, then I would create a buffer of set size and keep track
    of the size of the buffer, so I could append in O(1) time.
*/
//list1 number of elements represented as n, list2's as m
signed int
add_lls(forward_list<char> &list1, forward_list<char> &list2)
{
    string number1 = "";
    string number2 = "";

    for(char i : list1)//O(n)
        number1 += i;//O(logn)

    for(char i : list2)//O(m)
        number2 += i;//O(logm)

    //If i wanted to reverse the direction that of linked lists input, (e.g. instead of reading in 5->4 as 54, I could read
    // it in as 45) I would just use the insert function

    return stoi(number1) + stoi(number2);//(O(n+m)
}

int
main()
{
    forward_list<char> list1 {};
    forward_list<char> list2 {};

    list1.emplace_front('1');
    list1.emplace_front('4');
    list2.emplace_front('3');
    list2.emplace_front('6');

    cout << add_lls(list1,list2) << endl;
}
