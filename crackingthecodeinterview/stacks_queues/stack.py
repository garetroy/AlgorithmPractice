#This stack implementation was created with the help from https://interactivepython.org/courselib/static/pythonds/BasicDS/ImplementingaStackinPython.html
class Stack:
    def __init__(self):
        self.items = []

    def __str__(self):
        string = ""
        for i in self.items:
            string += i
        return string

    def __eq__(self, other):
        if is_instance(other, type(self)):
            return other.items == self.items
    
    def isEmpty(self):
        return self.items == []

    def push(self, item):
        return self.items.append(item)

    def pop(self):
        return self.items.pop()

    def size(self):
        return len(self.items) 

