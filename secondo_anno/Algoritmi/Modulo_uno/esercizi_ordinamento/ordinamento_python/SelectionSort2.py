def SelectionSort(A):
    m=0
    k=0
    for k in range(len(A)-1):
        m=k
        for j in range (k, len(A)):
            if A[j] < A[m]:
                m=j
        A[m], A[k] = A[k], A[m]
        print(A)
    return A
l= [7, 2, 4, 5, 3, 1]
print(SelectionSort(l)) 
