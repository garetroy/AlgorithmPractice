#This program checks to see if two given strings are permutations of eachother
import sys

def main():
    if len(sys.argv) > 3:
        print("Too many arguments, only takes two strings")
        return
    
    if(''.join(sorted(str(sys.argv[1]))) == ''.join(sorted(str(sys.argv[2])))):
        print("The two strings are permutations")
        return 

    print("Not permutations")
    return

main()
