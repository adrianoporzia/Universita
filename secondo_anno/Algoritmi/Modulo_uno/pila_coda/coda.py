class Queue:
    def __init__(self): 
        self.items = []
    
    def len_q(self):
        return len(self.items)

    def is_empty(self):
        return len(self.items) == 0 

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        if not self.is_empty():
            return self.items.pop(0)
        else:
            print("Coda vuota. Dequeue impossibile")
            return None

    def first(self):
        if not self.is_empty():
            return self.items[0]
        else:
            print("Coda vuota. Impossibile first")
            return None 


