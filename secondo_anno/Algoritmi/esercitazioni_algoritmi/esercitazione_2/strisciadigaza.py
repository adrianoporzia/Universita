def ForzeDelMale(A):
    M = [0] * (len(A) + 1)
    i = len(A) - 1
    while i  >= 0:

        if A[i] == 'x':
            M[i] = 0

        if A[i] != 'x':
            M[i] = A[i] + M[i + 1]

        i-=1

    min = 1
    for i in range(1, len(A)):

        if A[i] == 'x':
            M[i] = 0

        if A[i] != 'x':
            min = A[i] + M[i - 1]

            if min < M[i]:
                M[i] = min
    return M 

l=[1, 1,  4, 10, 'x', 7, 'x', 'x', 6, 3, 0, 5, 2, 'x']
print(ForzeDelMale(l))
  
