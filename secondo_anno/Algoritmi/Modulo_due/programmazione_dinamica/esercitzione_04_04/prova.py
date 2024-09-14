def prova(L, H):
    OPT = [0] * (len(L) + 3)
    n = len(L) - 1
    OPT[n] =  min(L[n], H[n])
    for i in range(n, -1, -1):
        OPT[i] = min(L[i] + OPT[i + 1], L[i] + OPT[i + 2], H[i] + OPT[i + 3])
    return OPT[0]
L =[2, 1, 3, 4, 4, 7, 1]
H =[5, 8, 3, 5, 4, 8, 5]
print(prova(L, H))
