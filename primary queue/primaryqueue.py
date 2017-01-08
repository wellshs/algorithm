class pqnode:
    def __init__(self, priority):
        self.priority = priority
class binaryheap:
    def __init__(self):
        self.length = 0
        self.list = []
    def push(self, node):
        self.list.append(node)
        index = self.list.index(node)
        while index!=0:
            if list[index].priority>list[(index-1)//2].priority:
                list[index], list[(index-1)//2] =  list[(index-1)//2],list[index]
                index = (index-1)//2
            else:
                break
    def pop(self):
        ret = self.list[0]
        if len(self.list)!=1:
            self.list[0] = self.list.pop()
            index = 0
            while len(self.list)>2*index:
                if len(self.list)==2*index+1:
                    if self.list[index].priority<self.list[2*index+1].priority:
                        self.list[index], self.list[2*index+1] = self.list[2*index+1], self.list[index]
                else:
                    if self.list[2*index+1].priority<self.list[2*index+2].priority:
                        bigger = 2*index+2
                    else:
                        bigger = 2*index+1
                    if self.list[index].priority<self.list[bigger].priority:
                        self.list[index], self.list[bigger] = self.list[bigger], self.list[index]
                        index = bigger
        return ret



