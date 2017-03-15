#This program checks to see if the input word has only unique strings
import sys

def main():
    if len(sys.argv) > 2:
        print("Too many arguments, just takes string")
        return

    string    = str(sys.argv[1])
    stringcpy = "" 
    for i in string:
        if i in stringcpy:
            print("String does not have unique characters")
            return
        else:
            stringcpy += i 
    
    print("The string has only unique characters")

main()
