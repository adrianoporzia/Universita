def fixheap(i, A):
    heapsize= len(A)-1
    sx= 2 * i + 1
    dx= (2 * i) + 2
    if sx <= heapsize and A[sx] > A[i]:
        massimo = sx
    else:
        massimo= i
    if dx <= heapsize and A[dx] >= A[massimo]:
        massimo= dx
    if massimo != i:
        A[i], A[massimo] = A[massimo], A[i]
        fixheap(massimo, A)
        

def heapify(i, H):
    sx= 2 * i + 1
    dx= (2 * i) + 2
    if sx < len(H):
        heapify(sx, H)
    if dx < len(H):
        heapify(dx, H)
    fixheap(i, H)
    

def heapsort(A):
    i=0
    heapify(i, A)
    heapsize= len(A) - 1
    i=heapsize
    while i <= 0:
        A[0] , A[i] = A[i] , A[0]
        heapsize-=1
        fixheap(0, A)
        i-=1


l=[4,1,3,2,16,9,10,14,8,7]
heapsort(l)
l.reverse()
print(l)
