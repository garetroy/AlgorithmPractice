/*
    This program takes a single-linked-list of chars and checks to see if there is a palindrome
    (In any permutation of the chars)
*/
#include <iostream>
#include <forward_list>

using namespace std;

bool
palindrome_checker(forward_list<char> &list)
{
    int alpha[25] = {0};
    int countOdd  = 0;
    int position  = 0;

    for(char i : list){ //O(n)
        if(i == ' ')
            continue;
        tolower(i);
        position = i - 'a';
        alpha[position]++;
        if(alpha[position] % 2 == 1){
            countOdd++;
        } else {
            countOdd--;
        }
    }

    if(countOdd <= 1)
        return true;
    
    return false; 
}

int
main()
{
    forward_list<char> list {};

    list.emplace_front('t');
    list.emplace_front('a');
    list.emplace_front('c');
    list.emplace_front('o');
    list.emplace_front('c');
    list.emplace_front('a');
    list.emplace_front('t');
    
    if(palindrome_checker(list)){
        cout << "This is a palindrome." << endl;
    } else {
        cout << "This is not a palindrome." << endl;
    }

    return 0;
    
}
