import sys

def main():
    if(len(sys.argv) < 2 and len(sys.argv) > 3):
        print("This only takes one string")
        return

    countOdd = 0;
    input    = sys.argv[1];
    parse    = "";

    for letter in input:
        if letter in parse:
            countOdd -= 1;
        elif letter == " ":
            continue;
        else:
            countOdd += 1;
            parse += letter;
    
    if countOdd == 1:
        print("This String has a permutation that is a palindrome")
        return
    else:
        print("This String does not have a permutiation that is a palindrome")
        return

main()
