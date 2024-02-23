def Merge(A, i, m, f):
    x=[]
    k1=i
    k2= m + 1
    while k1 <= m and k2 <= f:
        if A[k1] <= A[k2]:
            x.append(A[k1])
            k1+=1
        else:
            x.append(A[k2])
            k2+=1
    if k1 <= m:
        for i in range(k1,m):
            x.append(A[i])
    else:
        for i in range(k2, f):
            x.append(A[i])
    b = 0
    for i in range(i,f):
        A[i] = x[b]
        b+=1

def MergeSort(A, i , f):
    if i < f:
        m = (i + f) // 2
        MergeSort(A, i , m)
        MergeSort(A, m+1, f)
        Merge( A, i , m, f)
l= [7, 2, 4, 5, 3, 1, 5, 6]

print(MergeSort(l,0, len(l)-1))
