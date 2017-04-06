class LimitedStack:
    def __init__(self):
        self.multistack = [[]]
    
    def __str__(self):
        return "stack is: " + ','.join([','.join(str(i) for i in lst) for lst in self.multistack])

    def __eq__(self,other):
        if is_instance(other, type(self)):
            return other.multistack == self.multistack
    
    def isEmpty(self):
        return self.mains[0] == []

    def push(self, inval):
        if len(self.multistack[len(self.multistack)-1]) == 3:
            self.multistack.append([])

        self.multistack[len(self.multistack)-1].append(inval)

    def pop(self):
        poppeditem = self.multistack[len(self.multistack)-1].pop()

        if len(self.multistack[len(self.multistack)-1]) == 0:
            self.multistack.pop()

        return poppeditem

def main():
    
    stack = LimitedStack()
    stack.push(4)
    stack.push(10)
    stack.push(15)
    stack.push(12)
    for i in range(100):
        stack.push(i)

    for i in range(100):
        if i % 3 == 0:
            stack.pop()

    print(stack)
    

main()
