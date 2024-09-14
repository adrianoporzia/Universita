def ripetitori(L, H, n):
    OPT = [0] * (n + 2)
    OPT[n], OPT[n + 1] = 0, 0
    OPT[n - 1] = min(L[n - 1], H[n - 1])
    for i in range(n - 2, -1, -1):
        OPT[i] = min((L[i] + OPT[i + 1]), (L[i] + OPT[i + 2]), (H[i] + OPT[i + 3]))
    print(OPT)
    return OPT

'''
def soluzione(L, H, OPT, n):
    S = []
    j = n - 2
    while j >= 0:
        S.append( min((L[j] + OPT[j + 1]), (L[j] + OPT[j + 2]), (H[j] + OPT[j + 3])))
        j -= 1
    return S
'''

L = [2, 1, 3, 4, 4, 7, 1]
H = [5, 8, 3, 5, 4, 8, 5]
n = len(L)
OPT = ripetitori(L, H, n)
#print(soluzione(L, H, OPT, n))


