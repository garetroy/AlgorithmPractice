# node and linkedlist taken from https://stackoverflow.com/questions/280243/python-linked-list from user Nick Stinemates
# remove duplicates linked_list method implemented by myself and __eq__ in node
class node:
    def __init__(self):
        self.data = None
        self.next = None
        self.prev = None

    def __eq__(self,other):
        if isinstance(other, type(self)):
            return self.prev == other.prev and self.data == other.data and self.next == other.next
        return False

    def __str__(self):
        return ("Node data: " + str(self.data))

class linked_list:
    def __init__(self):
        self.curr_node = None
        
    def add_node(self,data):
        if self.curr_node == None:
            self.curr_node      = node()
            self.curr_node.data = data
            return

        new_node           = node()
        new_node.data      = data
        new_node.next      = self.curr_node
        new_node.next.prev = new_node
        self.curr_node     = new_node

    def __str__(self):
        node = self.curr_node
        data = ""
        while node != None:
            data += str(node) + "\n"
            node = node.next 
        return data
    
    def remove_doubles(self):
        same_items = []
        curr_node  = self.curr_node;
        next_node  = self.curr_node
        while next_node != None:
            if next_node.data in same_items:
                curr_node           = next_node
                next_node           = curr_node.next
                next_node.prev      = curr_node.prev
                curr_node.prev.next = next_node
                curr_node.next      = None
                curr_node.data      = None
                continue
            else:
                same_items.append(next_node.data)
                next_node           = next_node.next
    
def main():

    ll = linked_list() 
    ll.add_node(1)
    ll.add_node(2)
    ll.add_node(3)
    ll.add_node(3)
    ll.add_node(5)
    ll.add_node(6)
    ll.add_node(8)
    ll.add_node(8)
    ll.add_node(9)
    ll.add_node(10)
    ll.add_node(11)

    print(ll) 
    ll.remove_doubles()
    print(ll)

main()
