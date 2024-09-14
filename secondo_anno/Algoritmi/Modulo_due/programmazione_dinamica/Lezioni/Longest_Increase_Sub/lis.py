# SOTTOPROBLEMA : OPT[Ỉ] = lunghezza della LIS di S[1],...,S[j] che termina con S[i]
# FORMULA BELLMAN : OPT[i] = 1 + max{0, max(j = 1,.., i - 1 tale che S[j] < S[i]) OPT[j]}
# COMPLESSITA' = O(n) per ogni sottoproblema, O(n**2)

def longest_sub(L):
    OPT = [0] * len(L)
    OPT[0] = 1
    max = 0
    for i in range(1, len(L)):
        for j in range(0, i):
            if L[i] > L[j] and OPT[j] >= max:
                max = OPT[j]
        OPT[i] = 1 + max
    return OPT
L = [4, 1, 8, 3, 4, 8, 2, 7, 5, 6, 9]
print(longest_sub(L))


