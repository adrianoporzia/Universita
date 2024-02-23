def MaxDiff(A):
    Max = [0] * (len(A))
    Max[len(A)-1] = len(A) - 1  # Fix the initialization of Max[len(A)-1]
    
    for k in range(len(A) - 2, 0, -1):  # Fix the loop condition
        if A[k] > A[Max[k+1]]:
            Max[k] = k
        else:
            Max[k] = Max[k + 1]
    
    i_star = 0
    j_star = Max[1]
    M = A[j_star] - A[i_star]

    for i in range(1, len(A) - 1):  # Fix the loop condition
        if A[Max[i + 1]] - A[i] > M:
            i_star = i 
            j_star = Max[i + 1]
            M = A[j_star] - A[i_star]
    
    return (i_star, j_star)

l = [20, 11, 2, 5, 4, 10, 9, 2]
print(MaxDiff(l))
