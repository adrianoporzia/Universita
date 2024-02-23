def Somma(A, x):
    i, j = 0, len(A) - 1
    while i < j:
        if A[i] + A[j] == x:
            return (i, j)
        
        if A[i] + A[j] > x:
            j-=1
        else:
            i+=1
    return (-1, -1)

l=[2, 5, 9, 14, 20, 21, 25, 40]
print(Somma(l, 26))
