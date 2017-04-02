/*
   This program takes in a string and checks to see if there is any permutation of the string in which there exists a palidrome
*/
#import <iostream>
#import <string>
#import <algorithm>

using namespace std;

int 
main(int argc, char *argv[])
{
    if(argc > 3 || argc < 2){
        cerr << "This only takes one string" << endl;
        return -1;
    }

    int    position   = 0;
    int    countOdd   = 0;
    int    alpha[27]  = {0};
    string ourstring  = argv[1];
    
    transform(ourstring.begin(), ourstring.end(), ourstring.begin(), ::tolower);

    for(char &c : ourstring) {
        if(!isalpha(c)){
            cerr << "String cannot contain numeric or special values" << endl;
            return -1;
        }
        position = c - 'a';
        alpha[position]++;
        if(alpha[position] % 2 == 1){
            countOdd++;
        } else {
            countOdd--;
        }
    }

    if(countOdd <= 1){
        cout << "This string does contain a palindrome" << endl;
        return 0;
    }

    cout << "This string does not contain a palindrome" << endl; 
    return 0;         
} 
