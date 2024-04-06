class Casa:
    def __init__(self, red, green, blue):
        self.red = red
        self.green = green 
        self.blue = blue 

class Case:

    def __init__(self):
        self.case = []

    def add_casa(self, red, green, blue):
        self.case.append(Casa(red, green, blue))

    def size(self):
        return len(self.case) 
            

    def print_case(self):
        for i in self.case:
            print(f"({i.red}, {i.green}, {i.blue})")
        print()
    
    def alghoritm(self, n):
        R = [0] * n
        G = [0] * n
        B = [0] * n
        i = 0
        while(i < n):
            R[i] = self.case[i].red 
            G[i] = self.case[i].green 
            B[i] = self.case[i].blue
            i += 1
        OPT = [0] * n
        OPT[0] = min(R[0], B[0], G[0])
        for i in range(1, n):
            R[i] = R[i] + min(B[i - 1], G[i - 1])
            G[i] = G[i] + min(B[i - 1], R[i - 1])
            B[i] = B[i] + min(R[i - 1], G[i - 1])
            OPT[i] = min(R[i], G[i], B[i])
        return OPT


case = Case()
case.add_casa(7, 3, 16)
case.add_casa(6, 8, 10)
case.add_casa(7, 9, 4)
case.add_casa(8, 22, 2)
case.add_casa(9, 12, 5)
case.add_casa(20, 8, 7)

n = case.size()
OPT = [0] * n
OPT = case.alghoritm(n)

print(OPT)

case.print_case()






    

