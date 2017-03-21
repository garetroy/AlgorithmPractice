from random import randint

def main():
    
    matrix = [[randint(0,9) for _ in range(6)] for _ in range(6)]
    top    = [0 for _ in range(6)]
    left   = [0 for _ in range(6)]
    top    = [0 for _ in range(6)]
    bottom = [0 for _ in range(6)]
    right  = [0 for _ in range(6)]

    printMatrix(matrix)
    
    matrix = list(reversed(list(zip(*matrix))))

    printMatrix(matrix)
         
def printMatrix(matrix):
    for i in range(6):
        print('\n')
        for j in range(6): 
            print(matrix[i][j], end=' ')
    print('\n')

main()
