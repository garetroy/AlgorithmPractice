#include <iostream>
#include <vector>
#include <queue>

using std::ostream;
using std::cout;
using std::cerr;
using std::vector;
using std::queue;
using std::endl;
using std::cin;

struct Vertex{
    char            color;
    int             firsttime;
    int             lasttime;
    int             distance;
    Vertex*         predessesor; 
    vector<Vertex*> verticies;

    Vertex(void) : color('w'), firsttime(1), lasttime(1), distance(-1), predessesor(NULL) {}

    friend ostream &operator<<(ostream& os, const Vertex& in)
    {
        os << in.color << "-" << in.firsttime << "-" << in.lasttime << " ";
        return os;
    }
};

struct Adjlist{
    vector<Vertex*> list;

    friend ostream &operator<<(ostream& os, const Adjlist& in)
    {
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

void
ResetColor(Adjlist& in)
{
    //Resets color of vertices
    for(auto i : in.list)
        i->color = 'w';
}

void
CleanUp(Adjlist& in)
{
    //Removes all pointers created
    for(auto i : in.list)
        delete i;

    in.list.clear(); 
}

int
main()
{
    int graphnum  = 0;
    int verticies = 0;
    int edges     = 0;
    int k         = 0;
    int edgefrom  = 0;
    int edgeto    = 0;
    int time      = 1;
    Adjlist ingraph; 
    Vertex* iterator;

    cin >> graphnum;
    for(int i = 0; i < graphnum; i++){
        cout << "graph number: " << (i+1) << endl;
        //create nodes
        cin >> verticies;
        cin >> edges; 

        //This creates the appropriate number of Vertecies in our ingraph
        for(k = 0; k < verticies; k++){
            Vertex* in = (Vertex*) new Vertex();
            ingraph.list.push_back(in);
        }

        //This is just adding the edges to the adjlist
        for(k = 0; k < edges; k++){
            cin >> edgefrom >> edgeto;
            ingraph.list[edgefrom-1]->verticies.push_back(ingraph.list[edgeto-1]);
        }
    
        BFS(ingraph.list[0]);

        time = 0;
        //Go through from the first item to the llast item in the graph created by BFS to calculate time
        for(iterator = ingraph.list[ingraph.list.size()-1]->predessesor;iterator;iterator = iterator->predessesor){
            time++;
        }
        cout << "Shortest path: " << time << endl;
        time = 0;
        
        //sets all nodes back to white
        ResetColor(ingraph);

        // divide by two because we "access" every node twice, minus one for extra path
        cout << "Longest path: " << (DFS(ingraph)/2 - 1) << endl;
        
        //resets AdjList
        CleanUp(ingraph);
        //only prints '\n' if not last graph iteraton
        if(i != graphnum - 1)
            cout << endl;
    }
        
    return 0;
}
