#include <iostream>
#include <fstream>

using namespace std;

int
main(int argc, char *argv[])
{
    int    amountin = 0;
    int    x        = 0;
    int    y        = 0;

    ifstream infile(argv[1]);
    
    if(!(infile >> amountin)){
        cerr << "Could not read file" << endl;
        return -1;
    }

    while ( infile >> x >> y ){
        cout << to_string(x+y) << " "  << to_string(x*y) << endl;
    }
}
