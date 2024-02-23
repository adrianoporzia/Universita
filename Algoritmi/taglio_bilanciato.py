def oracolo(A):
    x = [0] * len(A)
    x[0] = A[0]
    i = 1
    for i in range(len(A)):
        x[i] = A[i] + x[i - 1]
    return x

def bin_search_special(x, i, f, alpha):
    if i >= f:
        return 0
    else:
        m = (i + f) // 2
        if (x[m] + alpha) >= (x[f] - (x[m] + alpha) and (x[m - 1] + alpha) < (x[f] - (x[m - 1] + alpha))):
            return m
        else:
            bin_search_special(x, i, m - 1, alpha)
    

def query(x, alpha):
    x = oracolo(x)
    k = bin_search_special(x, 0, len(x) - 1, alpha)
    return k


L = [3, 4, 5, 2, 4, 3, 1]
oracolo(L)
alpha = 20
alpha_1 = 0
print(query(L, alpha))
print(query(L, alpha_1))
