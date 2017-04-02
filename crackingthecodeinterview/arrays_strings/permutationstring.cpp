/*
    This algorithms takes in two strings and compares the strings to see if the strings are permutations of eachother
*/
#include <algorithm>
#include <iostream>
#include <vector>

int 
main(int argc, char *argv[])
{
    if(argc > 3 || argc < 2){
        std::cerr << "This takes two strings only" << std::endl;
        return -1;
    }
    
    std::string word1 = argv[1];
    std::string word2 = argv[2];
    std::sort(word1.begin(), word1.end());//O(n)
    std::sort(word2.begin(), word2.end());//O(m)
    
    if(word1 == word2){
        std::cerr << "These two are permuatations of eachother" << std::endl;
        return 0;
    }
    
    std::cerr << "They are not permutations of eachother" << std::endl;
    return 0;
}
