class TwoStackQueue:
    def __init__(self):
        self.inbox  = []
        self.outbox = []
    
    def __str__(self):
        string = "inbox is: "
        string += ''.join(self.inbox)
        string += '\n' + "outbox is: " + ''.join(self.outbox)
        
        return string

    def __eq__(self,other):
        if is_instance(other, type(self)):
            return other.inbox == self.inbox and self.outbox == other.outbox

    def isEmpty(self):
        return self.indbox == [] and self.outbox == [] 


