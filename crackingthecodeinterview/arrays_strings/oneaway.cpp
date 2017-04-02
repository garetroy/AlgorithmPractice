/*
    This program takes two strings and tries to see if there is only one difference between the two
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int 
main(int argc, char *argv[])
{
    if(argc < 2 || argc > 3){
        cerr << "This takes two strings" << endl;
        return -1; 
    }

    string firststring = argv[1]; 
    string secondstr   = argv[2];

    int  difference  = 0; 
    int  sizeone     = firststring.length();
    int  sizetwo     = secondstr.length();   
    bool samesize    = (sizeone == sizetwo); 
    int  biggerstr   = max(sizeone,sizetwo);
    int  smallstr    = min(sizeone,sizetwo);
    
    if((not samesize) and (smallstr + 1 != biggerstr)){
        cout << firststring << "," << secondstr << " -> " << "false" << endl;  
        return 0;
    } else if(not samesize){
        difference++;
    }

    for(int i = 0; i < smallstr; i++){
        if(firststring[i] == secondstr[i]){
            difference++; 
            if(difference > 1){
                cout << firststring << "," << secondstr << " -> " << "false" << endl;  
                return 0; 
            }
        }


    }

    cout << firststring << "," << secondstr << " -> " << "true" << endl;  
    return 0;
}
