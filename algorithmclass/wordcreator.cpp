#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

string
recursive_find(unordered_set<string>&dictionary, unordered_map<string,bool>& memo, string instring)
{
    if(memo.find(instring) != memo.end())
        return instring;      

    if(dictionary.find(instring) != dictionary.end())
        return "yes";

    //recurse here
    return "no";
}

int
main()
{
    unordered_set<string>      dictionary(58114);
    unordered_map<string,bool> memo(900);
    ifstream myfile("diction10k.txt");

    int           i(0);
    string        in("");

    while(getline(myfile, in)){
        istringstream iss(in);
        iss >> in;
        dictionary.emplace(in);
    } 

    myfile.close();
    
    for(i = 1; i > 0; i--){
       cout << recursive_find(dictionary,memo,"zig") << endl; 
    } 

    return 1;
}
