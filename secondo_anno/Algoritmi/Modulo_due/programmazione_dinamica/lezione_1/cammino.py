'''
def maxx(L):
    OPT = [0] * len(L)
    OPT[0] = L[0]
    OPT[1] = max(L[0], L[1])
    for j in range(2, len(L)):
        if OPT[j - 1] > (OPT[j - 2] + L[j]):
            OPT[j] = OPT[j - 1]
        else:
            OPT[j] = (OPT[j - 2] + L[j])
    return OPT[-1]
'''

'''
In max2() andiamo a calcolare la sequenza ottima e ritorniamo l'array OPT, mentre in path ritorniamo S,
che è una lista che contiene liste lunghe due dove in posziione 0 c'è l'indice dell'elemento nella lista L iniziale
e in posizione 1 il valore effettivo per arrivare all'ottimo.
'''
def max2(L):
    OPT = [0] * len(L)
    OPT[0], OPT[1] = L[0], max(L[0], L[1])
    for j in range(2, len(L)):
        OPT[j] = max(OPT[j - 1], (OPT[j - 2] + L[j]))
    return OPT
l = [1, 4, 8, 4, 3, 10]
print(max2(l))



def path(L, OPT):
    S = []
    j = len(L) - 1
    while j >= 2:
        if OPT[j - 1] >= (OPT[j - 2] + L[j]):
            j -=1
        else:
            S.append([j, L[j]])
            j -= 2
    if j == 2 and L[0] < L[1]:
        S.append([1, L[1]])
    else:
        S.append([0, L[0]])
    return S
l = [1, 4, 8, 4, 3, 10]
OPT = max2(l)
print(path(l, OPT))
