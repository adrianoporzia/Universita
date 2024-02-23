def Partition(A, i, f):
    x = A[i]
    inf = i + 1
    sup = f
    done = False
    while not done:
        while inf <= sup and A[inf] <= x:
            inf += 1
        while A[sup] >= x and sup >= inf:
            sup -= 1
        if sup < inf:
            done = True
        else:
            A[inf], A[sup] = A[sup], A[inf]
    A[i], A[sup] = A[sup], A[i]
    return sup

def QuickSort(A, i, f):
    if i < f:
        m = Partition(A, i, f)
        QuickSort(A, i, m - 1)
        QuickSort(A, m + 1, f)

l = [45, 12, 93, 3, 67, 43, 85, 29, 24, 92, 63, 3, 21]
QuickSort(l, 0, len(l) - 1)

print(l)  # Stampa la lista ordinata
