def speciale(A):
    SP, SF = 0, 0 
    for i in range(len(A) - 1):
        SP += A[i]
    for i in range(len(A) - 1):
        SF += A[i]
        SP -= A[i]
        if SF > SP:
            return i 
L = [3, 4, 7, 9, 11, 2]
print(speciale(L))
