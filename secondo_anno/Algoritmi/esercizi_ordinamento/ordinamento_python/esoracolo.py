def binary_search(arr, low, high, x):
 
    if high >= low:
 
        mid = (high + low) // 2
 
        if arr[mid] == x:
            return mid
 
        elif arr[mid] > x:
            return binary_search(arr, low, mid - 1, x)
 
        else:
            return binary_search(arr, mid + 1, high, x)
 
    else:
        return -1


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



#risposte oracolo

def InterrogaOracolo(X, k, a, b):
    
    QuickSort(X, 0 , len(X)-1)

    sx = 0
    dx =0 

    if b > k:
        b = k -1
    
    if a > b:
        a , b = b, a
    
    sx = binary_search(X, 0, len(X)-1 , a)
    dx = binary_search(X, 0, len(X)-1 , b)

    return dx - (sx)

l=[1, 10, 4, 5, 20]
k= max(l)
print(InterrogaOracolo(l, k, 4, 10))


    

