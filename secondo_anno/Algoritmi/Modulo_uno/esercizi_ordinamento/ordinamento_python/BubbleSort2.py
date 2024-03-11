def BubbleSort(A):
    k=0
    for k in range(len(A)):
        for i in range(len(A)-k-1):
            if A[i] > A[i+1]:
                A[i] , A[i+1] = A[i+1] , A[i]
    return A
a= [7, 2, 4, 5, 3, 1]
print(BubbleSort(a))

