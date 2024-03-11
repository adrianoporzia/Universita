def InsertionSort(A):
    for i in range(1, len(A)):
        while i > 0:
            if A[i] < A[i-1]:
                A[i], A[i-1] = A[i-1], A[i]
            i-=1
    return A
l=[7,2,4,5,3,1]
print(InsertionSort(l))

