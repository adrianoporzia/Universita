def ForzeDelMale(A):
    M = [0] * len(A)
    i = len(A) - 2
    while i  >= 0:

        if A[i] == 'x':
            M[i] = 0
            pos = i

        if A[i] != 'x':
            M[i] = A[i] + M[i + 1]

        i-=1
    min = 0
    for i in range(pos, len(A)):

        if A[i] == 'x':
            M[i] = 0
            pos = i

        if A[i] != 'x':
            min = A[i] + M[i - 1]

            if min < M[i]:
                M[i] = min
    for i in range(pos + 1, len(A)):
        M[i] = A[i] + M[i - 1]
        
        
    return M 

l=[1, 2, 3, 4, 5, 6,'x', 1,  4, 'x', 7, 'x', 'x', 6, 3, 0, 5, 2, 'x', 3, 2]
print(ForzeDelMale(l))
