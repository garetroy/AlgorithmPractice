class Node:

    def __init__(self,data=None):
        self.left   = None
        self.right  = None
        self.parent = None
        self.data   = data 
        self.depth  = 0

    def __str__(self):
        return str(data)

    def __eq__(self,other):
        if is_instance(other, type(self)):
            return (other.left == self.left) and (other.right == self.right) and (other.parent == self.parent) and (self.data == other.data) and (self.depth == other.depth)

    def __lt__(self):
        if is_instance(other,type(self)):
            return self.data < other.data

    def __gt__(self):
        if is_instance(other,type(self)):
            return self.data > other.data

class MinTree:
    
    def __init__(self):
        self.root = None; 

    def BuildMinTree(self, value, start, end):
        if start > end or end == 0:
            return
    
        middle    = (start+end)/2
        middleval = value[int(middle)]

        root = Node(middleval)
        root.left = self.BuildMinTree(value,start,middle-1)
        root.right = self.BuildMinTree(value,middle+1,end)
        return root
         

def main():

    tree = MinTree()
    inar = [3,4,5,6,7,8]
        
    tree.root = tree.BuildMinTree(inar,0,5)
    
    tempnode = tree.root

main()
