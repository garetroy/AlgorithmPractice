def main():
        
    
    nummatrix = int(input())
   
    for i in range(nummatrix):
        print("graph number: " + str(i+1))     
        
        numverticies = int(input())
        numedge      = int(input())

        matrix   = [[False for _ in range(numverticies)] for _ in range(numverticies)]
        numpaths = [0 for _ in range(numverticies)] #the amount of paths given the corresponding vert
        curpath  = [0 for _ in range(numverticies)] #the current path

        numpaths[0] = 1
        maxpath     = 1
        minpath     = numverticies - 1
    
        for _ in range(numedge):
            edgefrom, edgeto = input().split() 
            edgefrom         = int(edgefrom)
            edgeto           = int(edgeto)
       
            matrix[edgefrom-1][edgeto-1] = True; 
        

        for k in range(0,numverticies):
            for j in range(1, numverticies):
                if(matrix[k][j]):
                    numpaths[j]   += numpaths[k] #counting amount of paths by counting the paths at the previous vertex
                    curpath[j-k]  += 1 #increments the current path
                if(curpath[j-k] != 0):
                    minpath = curpath[j-k] 
                maxpath = max(curpath)

        print("Shortest path: " + str(minpath))
        print("Longest path: " + str(maxpath))
        print("Number of paths: " + str(max(numpaths)))

        print()

main()
