# node and ll disclaimer same as removeduplicates.py

class node:
    def __init__(self):
        self.data = None
        self.next = None

    def __eq__(self,other):
        if isinstance(other, type(self)):
            return self.data == other.data and self.next == other.next

    def __str__(self):
        return(str(self.data))

class linked_list:
    def __init__(self):
        self.curr_node = None
	
    def __str__(self):
        node = self.curr_node
        data = ""
        while node != None:
            data += str(node) + " "
            node = node.next
        return data

    def add_node(self,data):
        if self.curr_node == None:
            self.curr_node      = node()
            self.curr_node.data = data
            return
		
        new_node       = node()
        new_node.data  = data
        new_node.next  = self.curr_node
        self.curr_node = new_node

    def kthlastelement(self, kth):
        buffer = [0] * kth
        index  = 0
        node   = self.curr_node
        while node != None:
            index += 1
            buffer[index%kth] = node.data #I do data because of python's limited support for lists and ADT's
            node = node.next

        return buffer[kth - (index%kth) - 1]

def main():
    
        ll = linked_list()
        ll.add_node(10)
        ll.add_node(12)
        ll.add_node(11)
        ll.add_node(15)
        ll.add_node(2)

        print(ll.kthlastelement(4))

main()
