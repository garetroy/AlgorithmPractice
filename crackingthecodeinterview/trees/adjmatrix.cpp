/*
    Implements an adjacency matrix (also a vauge adjacency list), designed by Garett Roberts
*/
#include <iostream>
#include <vector>

using namespace std;

struct Vertex{
    char           color;
    int            distance;
    Vertex*        predessesor; 
    vector<Vertex> neighbors;

    Vertex(void) : color('w'), distance(-1), predessesor(NULL) {}
    Vertex(int distance) : color('w'), distance(distance), predessesor(NULL) {}
};

struct Edge{
    bool    exists;
    int     weight;
    //Can add vertexes here if desired

    Edge(void) : exists(false), weight(0) {}
    Edge(bool exists, int weight) : exists(exists), weight(weight) {}

    friend ostream &operator<<(ostream& os, const Edge& in){ os << "Exists: " << in.exists << " Weight: " << in.weight << endl; return os;} 
};

struct AdjMatrix{
    vector<vector<Edge>> adjmatrix;

    AdjMatrix(void) : adjmatrix() {}
    AdjMatrix(int n) : adjmatrix(n, vector<Edge>(n)) {}
    AdjMatrix(int n, int m) : adjmatrix(n, vector<Edge>(m)) {} //allows for n by m matrices

    Edge* accessAt(int n, int m){ return &adjmatrix.at(n).at(m); } 
    
    friend ostream &operator<<(ostream& os, const AdjMatrix& in)
    {
        if(in.adjmatrix.size() == 0 || in.adjmatrix.at(0).size() == 0){
            os << "Empty matrix" << endl;
            return os;
        }
        //might want to modify if just want to see if exists/ want to have vertex defined rows/cols
        for(int i = 0; i < in.adjmatrix.size(); i++){
            for(int j = 0; j < in.adjmatrix.size(); j++)
                os << in.adjmatrix.at(i).at(j).weight << " ";
            os << endl;
        }
    
        return os;
    }
};

int
main()
{
    int n = 3;
    AdjMatrix matrix(3);  // n by n matrix
    //Initialize
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            matrix.accessAt(i,j)->weight = i+j;
            matrix.accessAt(i,j)->exists = true;
        }

    cout << matrix; 

    AdjMatrix matrix2;
    cout << matrix2;

    vector<Vertex> l(n); //list
 
}
