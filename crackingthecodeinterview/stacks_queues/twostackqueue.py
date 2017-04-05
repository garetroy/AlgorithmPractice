class TwoStackQueue:
    def __init__(self):
        self.inbox  = []
        self.outbox = []
    
    def __str__(self):
        string = "inbox is: "
        string += ','.join(str(i) for i in self.inbox)
        string += '\n' + "outbox is: " + ','.join(str(i) for i in self.outbox)
        
        return string

    def __eq__(self,other):
        if is_instance(other, type(self)):
            return other.inbox == self.inbox and self.outbox == other.outbox

    def isEmpty(self):
        return self.indbox == [] and self.outbox == [] 

    def enqueue(self, inval):
        self.inbox.append(inval)

    def dequeue(self):
        for _ in range(len(self.inbox)):
            self.outbox.append(self.inbox.pop())
        
        return self.outbox.pop()


def main():

    myqueue = TwoStackQueue()

    myqueue.enqueue(5)
    myqueue.enqueue(3)
    myqueue.enqueue(1)
    myqueue.enqueue(10)
    print(myqueue.dequeue())
    print(myqueue)
    myqueue.enqueue(8)
    myqueue.enqueue(12)
    myqueue.enqueue(14)
    print(myqueue)
    print(myqueue.dequeue())
    print(myqueue)

main()
