class Vertex:
    
    def __init__(self, char=''):
        self.color    = 'w'
        self.firstime = -1
        self.lastime  = -1
        self.char     = char
        self.prevVert = None
        self.distance = 0
        self.adjvert  = []

    def __str__(self):
        return ("Vertex(" + self.char + "): " + str(self.distance) + '-' + self.color + "-(" + str(self.firstime) + ")-(" + str(self.lastime) + ")")

class AdjList:
    
    def __init__(self):
        self.list = []

    def __str__(self):
        string = ""
        for i in self.list:
            string += (str(i))
            for j in i.adjvert:
                string += ("->" + str(j))
            string += "\n"
        return string

def BFS(v):
    inqueue = []
    tempver = Vertex()
    
    v.color    = 'g'
    v.distance = 0

    inqueue.append(v)
    while(len(inqueue) != 0):
        tempver = inqueue.pop()

        for i in tempver.adjvert:
            if i.color == 'w':
                i.color = 'g'
                i.distance = tempver.distance + 1
                i.prevVert = tempver
                inqueue.append(i)
        v.color = 'b'

global time
def DFSVisit(adjlist, vertex):
    global time 
    time           += 1
    vertex.firstime = time 
    vertex.color    = 'g'
    for v in vertex.adjvert:
        if v.color == 'w':
            v.prevVert = vertex
            DFSVisit(adjlist,v)

    vertex.color    = 'b'
    time           += 1
    vertex.lasttime = time

def DFS(adjlist):

    global time
    time = 0
    for v in adjlist.list:
        if v.color == 'w':
            DFSVisit(adjlist,v)

    return time


def main():
    temp = AdjList()
    
    a = Vertex('a')
    b = Vertex('b')
    c = Vertex('c')
    d = Vertex('d')
    e = Vertex('e')
    f = Vertex('f')
    #g = Vertex('g')

    ''' FOR BFS TESTING
    temp.list.append(a);
    temp.list[0].adjvert.append(b);
    temp.list.append(b);
    temp.list[1].adjvert.append(c);
    temp.list[1].adjvert.append(d);
    temp.list.append(c);
    temp.list[2].adjvert.append(d);
    temp.list[2].adjvert.append(e);
    temp.list.append(d);
    temp.list[3].adjvert.append(a);
    temp.list[3].adjvert.append(e);
    temp.list.append(e);
    temp.list[4].adjvert.append(f);
    temp.list.append(f);
    temp.list.append(g);
    temp.list[6].adjvert.append(d); 

    BFS(a)

    print(temp)
    
    vert = e 
    while(vert.prevVert != None):
        vert = vert.prevVert

    print(vert)
    '''
    temp.list.append(a);
    temp.list[0].adjvert.append(c);
    temp.list[0].adjvert.append(d);
    temp.list.append(b);
    temp.list[1].adjvert.append(a);
    temp.list[1].adjvert.append(d);
    temp.list.append(c);
    temp.list[2].adjvert.append(e);
    temp.list.append(d);
    temp.list[3].adjvert.append(c);
    temp.list[3].adjvert.append(e);
    temp.list.append(e);
    
    DFS(temp)

    tempv = e
    while tempv != None:
        print(str(tempv) + " -> ", end = "")
        tempv = tempv.prevVert
    
    print() 

main()
