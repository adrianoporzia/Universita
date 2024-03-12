class Node:
    def __init__(self, key, value, pos):
        self.key = key 
        self.value = value
        self.pos = pos

class P_queue:
    def __init__(self, size, d):
        self.nodes = []
        self.size = size
        self.d = d

    def parent(self, pos):
        if pos > 0:
            return (pos - 1) // 2 

    def left_son(self, pos):
        son = (pos * 2) + 1
        if son <= self.size:
            return son 
        else:
            return None

    def right_son(self, pos):
        son = (pos * 2) + 2
        if son <= self.size:
            return son 
        else:
            return None

    def min_son(self, pos):
        min = 0
        for i in range((pos * self.d) + 1, (pos * self.d) + self.d):
            if i.keys < min:
                min = i.keys

    def insert(self, key, value, pos):
        self.nodes.append(Node(key, value, pos))
        #self.move_up(len(self.nodes) - 1)

    def find_min(self):
        return self.nodes[0]

    def move_down(self, node):
        while True:
            


