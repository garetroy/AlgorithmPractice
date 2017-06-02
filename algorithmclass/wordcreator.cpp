#include <algorithm>
#include <unordered_set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

string
get_string(bool memo, int *location, string instring)
{
    string outstring = "";
    if(!memo){ 
        outstring = "No, cannot be split\n";  
    }else{
        outstring = "Yes, can be split\n";
        for(int i = 0; i < instring.size() - 1; i++){
            outstring += instring.substr(i,location[i]+1) + " ";
            i          = location[i];
        }
    }
    return outstring;
}

/*bool
recursive_find(unordered_set<string>&dictionary, bool *memo, int *location, string instring, int i=0)
{
    if(i == instring.size())
        return true;
    
    if(memo[i])
        return memo[i];
    
    memo[i] = false;
    for(int j = i; i < instring.size(); j++)
        if((dictionary.find(instring.substr(i,j+1)) != dictionary.end()) && recursive_find(dictionary,memo,location,instring,j+1)){
            memo[i]     = true;
            location[i] = j;
        }
    return memo[i];
}*/

string
iterative_find(unordered_set<string>&dictionary, string instring)
{
    bool   memo[instring.size()+1];
    int    location[instring.size()+1];
    string outstring("");
    string substring("");

    memo[instring.size()] = true;
    for(int i = instring.size()-1; i >= 0; i--){
        memo[i] = false;
        for(int j = i; j < instring.size(); j++)
            if((dictionary.find(instring.substr(i,j+1)) != dictionary.end())  && memo[j+1]){
                memo[i]     = true;
                location[i] = j; 
            }
    }

    return get_string(memo[0],location,instring);
}

void
initialize_array(bool* memo, int *location, int size)
{
    for(int i = 0; i < size; i++){
        memo[i]     = false;
        location[i] = 0; 
    }
}

int
main()
{
    unordered_set<string> dictionary(58114);
    ifstream myfile("diction10k.txt");

    int           numphrase(0);
    bool          found(false);
    string        in("");

    //init dictionary
    while(getline(myfile, in)){
        istringstream iss(in);
        iss >> in;
        dictionary.emplace(in);
    } 

    cin >> numphrase; 
    string phrases[numphrase];
    for(int i = 0; i < numphrase; i++)
        cin >> phrases[i];
    
    for(int i = 0; i < numphrase; i++){
        cout << "phrase number: 1" << endl;
        cout << phrases[i] << endl << endl;
        cout << "iterative attempt:" << endl;
        cout << iterative_find(dictionary,phrases[i]) << endl; 
        cout << "memoized attempt:" << endl;
//        int  location[phrases[i].size()+1];
//        bool memo[phrases[i].size()+1];
//        initialize_array(memo,location,phrases[i].size()+1);
//        found = recursive_find(dictionary,memo,location,phrases[i]);
//        for(int i = 0; i < phrases[i].size();i++)
//            cout << location[i];
//        cout << get_string(found,location,phrases[i]) << endl << endl;
        
    }

    myfile.close();
    
    return 1;
}
