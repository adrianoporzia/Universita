def somma(A, B):
    B_1 = [0] * len(B)
    sum = 0
    for i in range(len(B) - 1, -1, -1):
        B_1[i] = B[i] + sum 
        sum = B_1[i]
    
    sum = 0
    for i in range(0, len(A) - 1):
        sum += A[i]
        if sum > B_1[i]:
            return i
    
L = [2, 4, 10, 3, 1, 7]
L_1 = [1, 4, 5, 11, 1, 2]
print(somma(L, L_1))
