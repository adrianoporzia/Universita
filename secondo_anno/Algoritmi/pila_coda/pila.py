class Pila:
    
    def __init__(self):
        self.items = []

    def is_empty(self):
        if len(self.items) == 0:
            return 1
        else:
            return 0\

    def len_p(self): 
        return len(self.items)

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty:
            return self.items.pop() 
        else:
            print("Pila vuota. Impossibile pop")

    def top(self):
        if not self.is_empty:
            return self.items[-1]


pila = Pila()
i = 0
while i < 10:
    pila.push(i)
    i += 1
print(pila.items)

pila.pop()
print(pila.items)
