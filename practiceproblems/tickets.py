from random import shuffle
test1 = [["DAL","ATL"],["LON","PAR"],["ATL","NYC"],["SFO","DAL"],["NYC","LON"]]
res1  = "SFO -> DAL -> ATL -> NYC -> LON -> PAR"
test2 = [["ATL","DAL"],["LON","DAL"],["NYC","SFO"]]
res2  = "No path exists"

def findPath(in_tickets):
    """
    Finds paths from the given from shuffled tickets, returns a string.
    If there is no such path it will return "no such path exists"
    """

    path    = []
    path.append(in_tickets[0]) 
    tickets = [i for i in in_tickets]
    tickets = tickets[1:]
    twice   = 0

    while(len(tickets) > 0): #Check if we have any left
        if(twice == 10): #Checks if we cant find a place for a ticket
            return "No path exists"

        for ticket in tickets:
            for item in range(len(path)):
                if ticket[0] == path[item][0] or ticket[1] == path[item][0]:
                    path.insert(item,ticket) 
                    tickets.remove(ticket)
                    break
                elif ticket[0] == path[item][1] or ticket[1] == path[item][1]:
                    path.insert(item+1,ticket)
                    tickets.remove(ticket)
                    break
            twice += 1 #We can't find a place for this ticket.. let's try
                       #one more time, incase there is a place for tickets now

    printstring = ""
    for loc in path:
        printstring += loc[0] + " -> "
    printstring += path[-1][1]

    return printstring 

for i in range(10):

    shuffle(test1)
    shuffle(test2)

    if(findPath(test1) != res1):
        print("NOT WORKING - test 1")
        break

    if(findPath(test2) != res2):
        print("NOT WORKING - test 2")
        break

    if i == 9:
        print("Passed Tests")
