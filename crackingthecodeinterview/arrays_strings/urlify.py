import sys

def main():
    if len(sys.argv) > 2:
        print("Too many arguments, takes one string")
        return

    print(str(sys.argv[1]).replace(" ", "%20"))

main()
