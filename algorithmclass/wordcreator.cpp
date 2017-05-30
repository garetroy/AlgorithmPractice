#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

string
recursive_find(unordered_set<string>&dictionary, unordered_map<int,bool>& memo, string instring)
{
    //if(memo.find(instring) != memo.end())
     //   return instring;      

    if(dictionary.find(instring) != dictionary.end())
        return "yes";

    //recurse here
    return "no";
}

string
iterative_find(unordered_set<string>&dictionary, string instring)
{
    bool   memo[instring.size()+1];
    int    location[instring.size()+1];
    string outstring("");
    string substring("");

    memo[instring.size()] = true;
    for(int i = 0; i < instring.size(); i++){
        memo[i] = false;
        for(int j = i; j < instring.size(); i++)
            if((dictionary.find(instring.substr(i,j+1)) != dictionary.end())  && memo[j+1]){
                memo[i]     = true;
                location[i] = j; 
            }
    }
        
    if(!memo[0]){ 
        outstring = "No, cannot be split\n";  
    }else{
        outstring = "Yes, can be split\n";
        for(int i = 0; i < instring.size() - 1; i++){
            outstring += instring.substr(i,location[i]+1) + " ";
            i = location[i];
        }
    }
    return outstring;
}

int
main()
{
    unordered_set<string>      dictionary(58114);
    unordered_map<int,bool> memo(900);
    ifstream myfile("diction10k.txt");

    int           numphrase(0);
    string        in("");

    //init dictionary
    while(getline(myfile, in)){
        istringstream iss(in);
        iss >> in;
        dictionary.emplace(in);
    } 

    cin >> numphrase; 
    for(int i = 0; i < numphrase; i++){
        cin >> in;
        cout << "phrase number: 1" << endl;
        cout << in << endl << endl;
        cout << "iterative attempt:" << endl;
        cout << iterative_find(dictionary,in) << endl; 
        cout << "memoized attempt:" << endl;
        cout << recursive_find(dictionary,memo,in) << endl;
    }

    myfile.close();
    
    return 1;
}
