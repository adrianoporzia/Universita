def MaxDiff(A):
    i_star, j_star, j, min = 0, 1, 1, 0
    M = A[j_star] - A[i_star]
   
    for i in range(len(A)-1):
        if A[min] > A[i]:
            min = i 

        if A[j] - A[min] > M:
            j_star = j 
            i_star = min
            M = A[j_star] - A[i_star]
        j+=1
    return (j_star, i_star)
l=[20, 11, 2, 5, 4, 10, 9, 2]
print(MaxDiff(l))


