def init_dictionary():
    hash_set = set();
    file = open('diction10k.txt','r')
    for line in file:
        hash_set.add(line.strip('\n')) 
    
    file.close()
    return hash_set

dictionary = init_dictionary()
memo       = list()
location   = list()

def recursive_find(string,i=0):
    global memo
    global location
    global dictionary

    if i == len(string):
        return True
    
    if memo[i] != -1:
        return memo[i]
    
    memo[i] = False
    j = i
    while(j < len(string)):
        found = string[i:j+1] in dictionary
        if(found and recursive_find(string,j+1)):
            memo[i]     = True
            location[i] = j
        j += 1 
    
    return memo[i] 
         
def iterative_find(string):
    global memo
    global location
    global dictionary

    memo     = [False for _ in range(len(string)+1)] 
    location = [0 for _ in range(len(string)+1)] 
    
    
    memo[len(string)] = True
    i = len(string)-1
    while(i >= 0):
        memo[i] = False
        j = i; 
        while(j < len(string)):
            found = string[i:j+1] in dictionary
            if(found and memo[j+1]):
                memo[i]     = True;
                location[i] = j;
            j+=1
        i = i - 1

    print_string(string, memo[0])


def print_string(string, can_be_split):
    global location

    if(not can_be_split):
        print("No, cannot be split\n")
        return
    
    outstring = "Yes, can be split\n"
    i = 0
    while(i < len(string)-1):
        outstring += string[i:location[i]+1] + " "
        i          = location[i]
        i         += 1
   
    print(outstring + "\n")

 
def main():
    global memo
    global location
    global dictionary

    amount_phrase = int(input())
    phrases = []
    for _ in range(amount_phrase):
        phrases.append(input())  
    
    for i in range(amount_phrase):
        print("phrase number: " + str(i+1))
        print(phrases[i],end="\n\n")
        print("iterative attempt:")
        iterative_find(phrases[i])
        memo     = [-1 for _ in range(len(phrases[i])+1)] 
        location = [0 for _ in range(len(phrases[i])+1)] 
        print("memoized attempt:")
        found = recursive_find(phrases[i])
        print_string(phrases[i],found)
        print()

main()
