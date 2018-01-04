from test import testRepeated
tests = [["radar",True], ["madam",True], ["dog",False], ["I am working",False],\
        ["This should dluohs siht",True], ["RaDaR",True]]

def isPalindrome(word):
    if word.lower() == word[::-1].lower():
        return True
    return False

testRepeated(isPalindrome,tests)
