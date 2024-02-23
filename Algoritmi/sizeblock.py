def createoracle(A):
    Y = [0] * (len(A) - 1)
    n = len(A) - 1
    if A[0] == 0:
        Y[0] += 1
    for i in range(1, n):
        if A[i] == 0:
            Y[i] = Y[i - 1] + 1
        else:
            Y[i] = 0

    if A[n] == 0:
        Y[n] = 0
    i = n - 1
    for i in range(len(A)-2, -1, -1): 
        if A[i] == 1:
            continue
        elif A[i] == 0 and A[i + 1] == 0:
            Y[i] = Y[i + 1]
    return Y

def query(Y, i):
    createoracle(Y)
    return Y[i]


L = [0, 0, 1, 1, 0, 1, 0, 0, 1]
L = createoracle(L)
print(query(L, 0))
