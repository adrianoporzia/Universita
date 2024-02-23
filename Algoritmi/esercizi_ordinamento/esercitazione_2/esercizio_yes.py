def ricerca_primo_e(A, i, f):
    
    if i <=f:

        m = (i + f) // 2

        if A[m] == 'E' and A[m - 1] == 'Y':
            return m 
        
        if A[m] == 'Y' and A[m + 1] == 'E':
            return m + 1
        
        if A[m] == 'E' or A[m] == 'S':
            return ricerca_primo_e(A, 0 , m - 1)
        
        if A[m] == 'Y':
            return ricerca_primo_e(A, m + 1, f)
        
    else:
        return -1



def ricerca_primo_s(A, i, f):
    
    if i <=f:

        m = (i + f) // 2

        if A[m] == 'S' and A[m - 1] == 'E':
            return m 
        
        if A[m] == 'E' and A[m + 1] == 'S':
            return m + 1
        
        if A[m] == 'E' or A[m] == 'Y':
            return ricerca_primo_s(A, m + 1, f)
            
        
        if A[m] == 'S':
            return ricerca_primo_s(A, 0 , m - 1)

    else:
        return -1



def contaoccorrenze(A):
    s= ricerca_primo_s(A, 0 , len(A)-1)
    e= ricerca_primo_e(A, 0 , len(A)-1)
    #y = ricerca_primo_e(A, 0 , len(A)-1) -1
    
    occorrenze_s= len(A) - s
    occorrenze_e = (s+1)-(e+1)
    occorrenze_y= len(A) - occorrenze_e - occorrenze_s
    

    return occorrenze_y, occorrenze_e, occorrenze_s

l=['Y', 'Y', 'E', 'E', 'E', 'E','S']
print(contaoccorrenze(l))
