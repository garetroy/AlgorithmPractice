class MinStack:
    def __init__(self):
        self.main = []
        self.mins = []

    def __str__(self):
        return "stack is: " + ','.join(str(i) for i in self.main)
    
    def __eq__(self,other):
        if is_instance(other, type(self)):
            return other.main == self.main and self.mins == other.mins

    def isEmpty(self):
        return self.mains == []

    def push(self, inval):

        if len(self.mins) == 0:
            self.mins.append(inval)
        elif inval < self.mins[len(self.mins) - 1]:
            self.mins.append(inval)

        self.main.append(inval)

    def pop(self):
        poppeditem = self.main.pop()
        if poppeditem == self.mins[len(self.mins)-1]:
            self.mins.pop()

        return poppeditem

    def min(self):
        return self.mins[len(self.mins)-1]


def main():

    mystack = MinStack()

    mystack.push(5)
    mystack.push(3)
    
    print(mystack.min())
    
    mystack.pop()

    print(mystack.min())
    print(mystack)

main()
