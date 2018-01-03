import urllib.request
import threading
import json

base_url = "https://challenge.curbside.com/"
urls     = []
header   = {}

class Tree:
    def __init__(self,info={},depth=0,link=""):
        self.children = []
        self.info     = info
        self.depth    = depth
        self.link     = link
        self.header   = header

    def __repr__(self):
        return str(self.info)

    def create_self(self,link):
        jdat = getjdata(link,header)
        print(link)
        print(jdat)
        self.info  = jdat
        self.depth = jdat['depth']
        self.link  = link
        return jdat['next']
            
    def add_child(self,link,stop=10):
        link = base_url + link
        urls.append(link)

        if(len(self.children) != 0):
            for child in self.children:
                if child.link == link:
                    return

        jdat = getjdata(link,header)
        if(jdat == {}):
            return

        if(self.depth >= stop): #stop at depth
            return

        tree = Tree(jdat,jdat['depth'],link)
        if "next" in jdat:
            nex = jdat["next"]
            if type(nex) is list: #if list, let's seperate
                for i in nex: 
                    if i in urls: #no duplicate accesss
                        continue 
                    urls.append(i)
                    tree.add_child(i,stop)
            else:
                if nex in urls: #no duplicate accesses
                    return
                urls.append(nex)
                tree.add_child(nex,stop)
     
        print(tree)
        self.children.append(tree)
                    
        if(self.depth <= 6):
            print("Depth: " + str(self.depth) + " finished!")

    def add_children(self,links):
        if type(links) == type([]):
            for i in links:
                self.add_child(i)  
        else:
            self.add_child(links)

    def printInorder(self):
        for i in self.children:
            i.printInorder()
            if('secret' not in i.info):
                continue 
            if(i.info['secret'] != ''):
                print(i.info['secret'])

def getjdata(url,header={}):
    req = urllib.request.Request(url, headers=header)
    for attempts in range(3):
        try:
            with urllib.request.urlopen(req) as response:
                data = response.read().decode()
                jdat = json.loads(data)
                return jdat
        except urllib.error.URLError as e:
            if attempts == 2:
                print("Attempted three times, connection error")
                print(e)
                print("Url: " + str(url))
                print("Header: " + str(header))
        except urllib.error.URLError as e:
            print("Url error")
            print(e)
            print("Url: " + str(url))
            print("Header: " + str(header))
            return
        except urllib.error.ContentTooShortError as e:
            print("Too short error")
            print(e)
            print("Url: " + str(url))
            print("Header: " + str(header))
            return
        except json.JSONDecodeError as e:
            print("Requested information was not json content")
            print(e)
            print("Url: " + str(url))
            print("Header: " + str(header))
            return
        else:
            print("Unknown error in getjdata with connecting") 
            print("Url: " + str(url))
            print("Header: " + str(header))
        
        continue

    return {}

def setupHeader():
    header = {}
    jdat = getjdata("https://challenge.curbside.com/get-session")
    header["expire_at"] = jdat["expire_at"]
    header["session"] = jdat["session"]
    return header
   
def setupTree(depth,tree_list,threads):
    global header
    header = setupHeader()
    jdat = getjdata("https://challenge.curbside.com/start",header)
    base_tree = Tree(jdat,0,jdat['id'])
    for i in jdat['next']:
        base_tree.add_child(i,stop=depth)

    print("Children Added")
    #Initialize threads for depth 
    for i in base_tree.children:
        for w in i.children:
            for k in range(len(w.children)):
                tree_list.append(w.children[k])
                new_links = tree_list[k].create_self(tree_list[k].link)
                threads.append(threading.Thread(target=tree_list[k].add_children,\
                args=(new_links,)))

    print("Threads Added")
    
if __name__ == "__main__":
    threads   = []
    tree_list = []
    setupTree(3,tree_list,threads)
    print(threads)
    print(tree_list)
    print("Starting threads")
    for i in threads:
        i.start() 
    for i in threads:
        print(i)
        print("Thread finished")
        i.join()
    
    print("SECRET")
    for i in tree_list:
        i.printInorder()
