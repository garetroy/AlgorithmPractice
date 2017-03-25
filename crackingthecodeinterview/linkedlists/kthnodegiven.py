class node:
    def __init__(self):
        self.next = None
        self.data = None

    def __str__(self):
        return str(self.data)

    def __eq__(self,other):
        if isinstance(other, type(self)):
            return self.next == other.next and self.data == other.data

class ll:
    def __init__(self):
        self.head = None

    def __str__(self):
        node = self.head        
        data = ""
        while node != None:
            if(str(node) == "None"):
                node = node.next
                continue;
            data += str(node) + " "
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

    def remove_node(self,data):
        node = self.head
        if(node == None):
            return

        while node.data != data:
            node = node.next 

        if(node == None):
            return

        while node.next != None:
            node.data = node.next.data
            node      = node.next
        
        node.data = None
        node      = None 

def main():

    list = ll()

    list.add_node(5)
    list.add_node(8)
    list.add_node(12)
    list.add_node(15)
    
    print(list)

    list.remove_node(8)

    print(list)

main()
