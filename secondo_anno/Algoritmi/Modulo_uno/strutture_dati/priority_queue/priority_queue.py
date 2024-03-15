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
            return (pos - 1) // self.d
        else:
            return -1

    def left_son(self, pos):
        son = (pos * 2) + 1
        if son <= self.size:
            return son 
        else:
            return -1

    def son(self, pos, j):
        son = (pos * self.d) + j + 1
        if son <= self.size:
            return son
        else:
            return -1 
    
    def right_son(self, pos):
        son = (pos * 2) + 2
        if son <= self.size:
            return son 
        else:
            return -1
    
    def min_son(self, pos):
        min = self.son(pos, 0)
        if min != None:
            for i in range(self.d):
                child = self.son(pos, i)
                if self.nodes[min].key >= self.nodes[child].key:
                    min = child 
            return min
        else:
            return None

    def insert(self, key, value, pos):
        self.nodes.append(Node(key, value, pos))
        self.move_up(pos)
        self.size += 1
    
    def delete(self, node):
        self.nodes[node].key += 1000
        self.move_down(node)
        self.size -= 1

    def delete_min(self):
        self.nodes[0].key += 1000
        self.move_down(0)
        self.size -= 1
 

    def find_min(self):
        return self.nodes[0]

    def move_down(self, node):
        while True: 
            child = self.min_son(node)
            if child == None or self.nodes[node].key <= self.nodes[child].key:
                break 
            self.nodes[node], self.nodes[child] = self.nodes[child], self.nodes[node]

    def move_up(self, node):
        while self.parent(node) != -1 and self.nodes[node].key < self.nodes[self.parent(node)].key:
            parent_node = self.parent(node)
            self.nodes[node], self.nodes[parent_node] = self.nodes[parent_node], self.nodes[node]
            node = parent_node


    
    def decrease_key(self, node, val):
        self.nodes[node].key -= val
        self.move_up(node)

    def increase_key(self, node, val):
        self.nodes[node].key += val 
        self.move_down(node)

    def print_q(self):
        for i in self.nodes:
            print(f"({i.key}, {i.value}, {i.pos}), ", end = " ")
        print()

import random as rn 
queue = P_queue(0, 2)
i = 0
while i < 10:
    key = rn.randint(0, 30)
    value = rn.randint(0, 100)
    pos = i
    queue.insert(key, value, pos)
    i += 1
queue.print_q()

queue.increase_key(0, 20)

#queue.print_q()
##delete
#queue.delete_min()
#queue.print_q()
