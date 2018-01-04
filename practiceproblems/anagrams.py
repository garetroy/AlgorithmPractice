test1 = ["MaRy","ArMy"]
res1  = True
test2 = ["frog","gorf"]
res2  = True
test3 = ["egg","egg"]
res3  = True
test4 = ["blah","nope"]
res4  = False

answer = [[test1,res1],[test2,res2],[test3,res3],[test4,res4]]

def isAnogram(words):
    return sorted(words[0].lower()) == sorted(words[1].lower())

def testAnogram():
    for item in range(len(answer)):
        if isAnogram(answer[item][0]) != answer[item][1]:
            print("Does not work - Test# " + str(item))
            return
    print("Tests Passed")

testAnogram()
