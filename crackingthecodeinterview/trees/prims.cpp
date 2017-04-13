#include <iostream>
#include <algorithm>
#include <vector>
#include <utilities>

using std::ostream;
using std::cout;
using std::vector;
using std::make

struct Vertex{
    char                      color;
    int                       weight;
    Vertex*                   predessesor; 
    vector<Vertex*>           neighbors;

    Vertex(void) : color('w'), weight(0), predessesor(nullptr) {}
    Vertex(char name) : color('w'), name(name), predessesor(nullptr) {}
    Vertex(char name, int weight) : color('w'), name(name), weight(weight), predessesor(nullptr) {}

    bool operator>(const Vertex& in) const { return weight; 

    bool operator==(const Vertex& in)const {return (in.color == color) && (name == in.name) && (in.predessesor == predessesor) && (neighbors.size() == in.neighbors.size());}

};

Vertex*
prims(priority_queue& pq)
{
    return nullptr;
}

int 
main()
{

    return 1;
}
