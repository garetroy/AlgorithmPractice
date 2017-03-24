#include <iostream>
#include <list>

using namespace std;

int
findelement(int ktolastposition, list<int> &ll)
{
	int index = 0;
	int buffer[ktolastposition];
	
	for(int i = 0; i < ktolastposition; i++)
		buffer[i] = 0;

	for( int n : ll){
		index++;
		buffer[index%ktolastposition] = n;
	}
	
	return buffer[ktolastposition - (index%ktolastposition) - 1];
}

int
main(){
	
	int ktolastpos = 3;

	list<int> ll;

	ll.emplace_back(10);
	ll.emplace_back(2);	
	ll.emplace_back(5);
	ll.emplace_back(11);
	ll.emplace_back(15);

	if(ktolastpos > ll.size()){
		cerr << "ktolastposition is not proportionate to the size of ll" << endl;
		return -1;
	}
	
	cout << findelement(ktolastpos, ll) << endl;

	return 0;
}

