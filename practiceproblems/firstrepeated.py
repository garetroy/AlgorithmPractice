test1 = "frog"
res1  = "f"
test2 = "ffrrog"
res2  = "o"
test3 = "ffrroogg"
res3  = "None"

answer = [[test1,res1],[test2,res2],[test3,res3]]

def firstRepeated(word):
    hashtable = {}
    for letter in word:
        if letter not in hashtable:
            hashtable[letter] = 1 
        else:
            hashtable[letter] += 1

    for letter in hashtable:
        if hashtable[letter] == 1:
            return letter
    return "None"

def testRepeated():
    for item in range(len(answer)):
        if firstRepeated(answer[item][0]) != answer[item][1]:
            print("Does not work - Test# " + str(item))
            return
    print("Tests Passed")


testRepeated()
