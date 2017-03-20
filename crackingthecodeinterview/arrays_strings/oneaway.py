from sys import argv

def main():
    argc = len(argv) #len is O(1)
    if(argc > 3 or argc < 2):
        print("This takes two strings")
        return -1

    differencecounter = 0
    firststring       = argv[1]
    firstlength       = len(argv[1])
    secondstring      = argv[2]
    secondlength      = len(argv[2])
    samesize          = firstlength == secondlength
    smallstringlen    = min(firstlength,secondlength) #O(1)
    biggerstringlen   = max(firstlength,secondlength)
    
    if((not samesize) and (smallstringlen + 1 != biggerstringlen)):
        print(firststring + "," + secondstring + " -> " + "false")
        return 0
    elif((not samesize)):
        differencecounter += 1
 
    for i in range(smallstringlen): #O(n)
        if(firststring[i] != secondstring[i]):
            differencecounter += 1

        if(differencecounter > 1):
            print(firststring + "," + secondstring + " -> " + "false")
            return 0

    
    print(firststring + "," + secondstring + " -> " + "true")
    return 0

main()
