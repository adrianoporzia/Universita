def BucketSort(A, k):
    X = [0] * (k + 1)
    
    for i in range(len(A)-1):
        X[A[i]] = A[i]

    for i in range(k - 1):
        A[i] = X[i]

    return A 


