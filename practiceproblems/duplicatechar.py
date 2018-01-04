test1 = "ddog"
test2 = "doooooog"
test3 = "dog"

def duplicateFinder(string : str):
    letters = set()
    dups    = ""
    for letter in string:
        if letter not in letters:
            letters.add(letter)
            continue
        if letter in letters:
            dups += letter + " "

    return dups


print(duplicateFinder(test1))
print(duplicateFinder(test2))
print(duplicateFinder(test3))
