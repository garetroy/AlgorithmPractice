class node:
    def __init__(self):
        self.data = None
        self.next = None

    def __eq__(self,other):
        if isinstance(other, type(self)):
            return other.data == self.data and other.next == self.next

    def __str__(self):
        return str(self.data)

class ll:
    def __init__(self):
        self.head = None

    def __str__(self):
        node = self.head
        data = ''
        while node != None:
            data += node.data
            node = node.next
        return data

    def add_node(self,data):
        if self.head == None:
            self.head      = node()
            self.head.data = data
            return

        new_node      = node()
        new_node.data = data
        new_node.next = self.head
        self.head     = new_node

    def is_palindrome(self):
        alpha    = ""
        node     = self.head
        countOdd = 0

        while node != None:
            if(node.data == " "):
                pass   
            elif node.data in alpha:
                countOdd -= 1
            else:
                countOdd += 1
                alpha += node.data

            node = node.next

        if countOdd <= 1:
            return True
        
        return False

def main():

    list = ll()
    list.add_node('t')
    list.add_node('a')
    list.add_node('c')
    list.add_node('o')
    list.add_node('c')
    list.add_node(' ')
    list.add_node('a')
    list.add_node('t')

    print(list.is_palindrome()) 
            
main()             
