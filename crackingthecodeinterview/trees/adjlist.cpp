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
    char            vertexchar;
    char            color;
    int             firsttime;
    int             lasttime;
    int             distance;
    Vertex*         predessesor; 
    vector<Vertex*> verticies;

    Vertex(void) : vertexchar('a'), color('w'), distance(-1), firsttime(1), lasttime(1), predessesor(NULL) {}
    Vertex(char vertchar) : vertexchar(vertchar), color('w'), distance(-1), firsttime(1), lasttime(1), predessesor(NULL) {}
    Vertex(char vertchar, int distance) : vertexchar(vertchar), color('w'), distance(distance), firsttime(1), lasttime(1), predessesor(NULL) {}

    friend ostream &operator<<(ostream& os, const Vertex& in)
    {
        os << in.vertexchar << "-" << in.color << "-" << in.firsttime << "-" << in.lasttime << " ";
        return os;
    }
};

struct Adjlist{
    vector<Vertex*> list;

    friend ostream &operator<<(ostream& os, const Adjlist& in)
    {
        for(int i = 0; i < in.list.size(); i++){
            os << in.list[i]->vertexchar << ": ";
            for(int j = 0; j < in.list[i]->verticies.size(); j++)
                os << *in.list[i]->verticies[j];
            os << endl;
        }
        return os;
    }
};

void
BFS(Vertex* v)
{
    queue<Vertex*> inqueue;
    Vertex*        tempvertex;
    int            i = 0;

    v->color    = 'g';
    v->distance = 0;  

    inqueue.emplace(v);
    while(!inqueue.empty()){
        tempvertex = inqueue.front();
        inqueue.pop();
        //need to add iterator here.. to modify pointers
        for( Vertex* k : tempvertex->verticies )
            if(k->color == 'w'){
                k->color       = 'g';
                k->distance    = tempvertex->distance + 1;
                k->predessesor = tempvertex; 
                inqueue.emplace(k);
            }
        v->color = 'b';
    }
} 

void
DFSVisit(Adjlist& in, Vertex* v, int& time)
{
    time++;
    v->firsttime = time;
    v->color     = 'g';
    for( Vertex *k : v->verticies ){
        if(k->color == 'w'){
            k->predessesor = v;
            DFSVisit(in,k,time);

        }
    }
    v->color = 'b';
    time++;
    v->lasttime = time;
}

int 
DFS(Adjlist& in)
{
    int time = 0;
    for( Vertex* k : in.list){
        if(k->color == 'w')
            DFSVisit(in, k, time);
    }
    return time; 
}

int
main()
{
    Adjlist temp;
    Vertex* a = new Vertex('a');
    Vertex* b = new Vertex('b');
    Vertex* c = new Vertex('c');
    Vertex* d = new Vertex('d');
    Vertex* e = new Vertex('e');
    Vertex* f = new Vertex('f');
    Vertex* g = new Vertex('g');

    //for DFS
    temp.list.push_back(a);
    temp.list[0]->verticies.push_back(c);
    temp.list[0]->verticies.push_back(d);
    temp.list.push_back(b);
    temp.list[1]->verticies.push_back(a);
    temp.list[1]->verticies.push_back(d);
    temp.list.push_back(c);
    temp.list[2]->verticies.push_back(e);
    temp.list.emplace_back(d);
    temp.list[3]->verticies.push_back(c);
    temp.list[3]->verticies.push_back(e);
    temp.list.push_back(e);

    /* for BFS
    temp.list.push_back(a);
    temp.list[0]->verticies.push_back(b);
    temp.list.push_back(b);
    temp.list[1]->verticies.push_back(c);
    temp.list[1]->verticies.push_back(d);
    temp.list.push_back(c);
    temp.list[2]->verticies.push_back(d);
    temp.list[2]->verticies.push_back(e);
    temp.list.emplace_back(d);
    temp.list[3]->verticies.push_back(a);
    temp.list[3]->verticies.push_back(e);
    temp.list.push_back(e);
    temp.list[4]->verticies.push_back(f);
    temp.list.push_back(f);
    temp.list.push_back(g);
    temp.list[6]->verticies.emplace_back(d); 
    */

    //Vertex* to   = a;
    Vertex* from = e; 
    bool    swch  = false;

    DFS(temp);
    //BFS(from);

    while(from != NULL){
        cout << *from << endl;
        from = from->predessesor;
    }
    //cout <<  swch << endl;
    //cout << temp << endl;
    return 0;
}
