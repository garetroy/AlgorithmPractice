#include <iostream>
#include <fstream>

using namespace std;

int
main()
{
    int    amountin = 0;
    int    x        = 0;
    int    y        = 0;

    for(cin >> amountin; amountin > 0; amountin--){
        cin >> x >> y;
        cout << to_string(x+y) << " "  << to_string(x*y) << endl;
    }
}
