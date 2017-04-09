#include <iostream>
#include <vector>
#include <queue>

using std::ostream;
using std::cout;
using std::cerr;
using std::vector;
using std::queue;
using std::endl;

struct Vertex{
    char           vertexchar;
    char           color;
    int            distance;
    Vertex*        predessesor; 
    vector<Vertex> verticies;

    Vertex(void) : vertexchar('a'), color('w'), distance(-1), predessesor(NULL) {}
    Vertex(char vertchar) : vertexchar(vertchar), color('w'), distance(-1), predessesor(NULL) {}
    Vertex(char vertchar, int distance) : vertexchar(vertchar), color('w'), distance(distance), predessesor(NULL) {}

    friend ostream &operator<<(ostream& os, const Vertex& in)
    {
        os << in.vertexchar << "-" << in.color << "-" << in.predessesor << " ";
        return os;
    }
};

struct Adjlist{
    vector<Vertex> list;

    friend ostream &operator<<(ostream& os, const Adjlist& in)
    {
        for(int i = 0; i < in.list.size(); i++){
            os << in.list[i].vertexchar << ": ";
            for(int j = 0; j < in.list[i].verticies.size(); j++)
                os << in.list[i].verticies[j];
            os << endl;
        }
        return os;
    }
};

void
BFS(Vertex& v)
{
    queue<Vertex> inqueue;
    Vertex        tempvertex;
    int           i = 0;

    v.color    = 'g';
    v.distance = 0;  

    inqueue.emplace(v);
    while(!inqueue.empty()){
        tempvertex = inqueue.front();
        inqueue.pop();
        //need to add iterator here.. to modify pointers
        for( Vertex k : tempvertex.verticies )
            if(k.color == 'w'){
                k.color       = 'g';
                k.distance    = tempvertex.distance + 1;
                k.predessesor = &tempvertex; 
                inqueue.emplace(k);
            }
        v.color = 'b';
    }
}        
            

int
main()
{
    Adjlist temp;
    //setting up sample  
    temp.list.emplace_back(Vertex('a'));
    temp.list[0].verticies.emplace_back(Vertex('b'));
    temp.list.emplace_back(Vertex('b')); 
    temp.list[1].verticies.emplace_back(Vertex('c'));
    temp.list[1].verticies.emplace_back(Vertex('d'));
    temp.list.emplace_back(Vertex('c'));
    temp.list[2].verticies.emplace_back(Vertex('d'));
    temp.list[2].verticies.emplace_back(Vertex('e')); 
    temp.list.emplace_back(Vertex('d'));
    temp.list[3].verticies.emplace_back(Vertex('e'));
    temp.list[3].verticies.emplace_back(Vertex('a'));
    temp.list.emplace_back(Vertex('e'));
    temp.list[4].verticies.emplace_back(Vertex('f'));
    temp.list.emplace_back(Vertex('f'));
    temp.list.emplace_back(Vertex('g'));
    temp.list[6].verticies.emplace_back(Vertex('d'));

    vector<Vertex>::iterator it = temp.list.begin();
    
    Vertex* newvertex = &(*it);
    Vertex* inpath    = newvertex+4;
    
    
    BFS(*newvertex);
    cout << *newvertex << endl;

    cout << temp;
    return 0;
}
