def zero_uno(A):
    num_z, num_u = 0, 0
    i = 0
    
    while i <= len(A) - 1:
        if A[i] == 1:
            num_u += 1
        i += 1

    i, j = 0, len(A) - 1
    pos = 0
    while i <= len(A) - 1:
        if num_u == num_z:
            pos = i
        if A[i] == 0:
            num_z += 1
        if A[i] == 1:
            num_u -=1
        i += 1
    return pos - 1
lista = [0, 0, 0, 0, 0, 0, 1]
print(zero_uno(lista))
