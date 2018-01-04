from test import testRepeated
tests = [["dog","god"],["life","efil"],["dod","dod"]]

def reverseIter(word):
    new  = ""
    for i in range(len(word)):
        new += word[len(word)-i-1]

    return new

def reverseRecur(word):
    if len(word) == 1:
        return word

    return reverseRecur(word[1:]) + word[0]
    

testRepeated(reverseIter,tests)
testRepeated(reverseRecur,tests)
