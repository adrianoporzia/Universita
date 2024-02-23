
def k_picco(A):
    k_min, k_max = 0, 0 
    i = 0
    while i < len(A) - 2: 
        k_1, k_2 = 0, 0
        while A[i] <= A[i + 1]:
            k_1 += 1
            i += 1 
            if A[i] > A[i + 1]:
                i += 1 
        while A[i] >= A[i + 1] and i < len(A) - 2: 
            k_2 += 1
            i += 1 

        if k_1 >= k_2:
            k_min = k_2
        else:
            k_min = k_1

        if k_min > k_max:
            k_max = k_min 
    return k_max 
L = [1, 2, 3, 10, 9, 8, 7, 6, 5, 8, 9, 10, 11, 12, 20, 18, 17, 16, 15, 14, 13, 12]
#L = [1, 2, 3, 10, 9, 8, 7, 6, 5, 8, 9, 10, 11, 12, 20, 18, 17]
print(k_picco(L))

            
