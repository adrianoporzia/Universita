def MaxCase(R, G, B, n):
    OPT = [0] * n
    OPT[0] = min(R[0], B[0], G[0])
    for i in range(1, n): 
        R[i] += min(B[i - 1], G[i - 1])
        G[i] += min(R[i - 1], B[i - 1])
        B[i] += min(R[i - 1], G[i - 1])
    for i in range(1, n):
        OPT[i] = min(R[i], B[i], G[i])
    return OPT, OPT[-1]

R = [7, 6, 7, 8, 9, 20]
G = [3, 8, 9, 22, 12, 8]
B = [16, 10, 4, 2, 5, 7]
n = len(R)
print(MaxCase(R, G, B, n))










