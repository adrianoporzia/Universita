def num(A, i, f):
    num_0 = 0
    num_1 = 0
    if A[0] == 0:
        num_0 +=1 
    if A[f - 1] == 1:
        num_1 += 1 

    f -= 2
    while i < f :
        i += 1
        if A[i] == 0:
            num_0 +=1 
            f -= 1
        if A[f] == 1:
            num_1 +=1 
    return i 
k = [0, 1, 0, 0, 1, 1, 0, 1]
print(num(k, 0, len(k)))
