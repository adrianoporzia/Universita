def cerca_max(A, i, f):
    
    if i <= f:
        m = (i + f) // 2

        if A[0] > A[1]:
            return 0
        if A[len(A)-1] > A[len(A)-2] :
            return len(A) - 1
        

        if A[m] > A[m + 1] and A[m] > A[m - 1]:
            return m
        
        if A[m] > A[m + 1]:
            return cerca_max(A, 0, m-1)
        
        else:
            return cerca_max(A, m+1, f)
    else: 
        return -1
l= [2, 4, 20, 30, 31, 32]
print(cerca_max(l, 0, len(l)))


def Merge(A, i, m, f):
    X = []
    j = 0 
    k1, k2 = 0, f - 1

    while k1 <= m and k2 >= m:
        if A[k1] <= A[k2]:
            X[j] = A[k1]
            i +=1 
            k1 +=1 
        else:
            X[i] = A[k2]
            i+=1 
            j -=1 
    if k1 <= m:
    #DA FINIRE IL MERGE

