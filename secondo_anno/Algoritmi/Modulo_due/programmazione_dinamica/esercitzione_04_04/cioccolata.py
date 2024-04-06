def cioccolata(G, n):
    OPT = [0] * n 
    S = []
    costruzione_sol(S, n)
    OPT[0] = G[0]
    i_star, j_star = 0, 0               
    for i in range(1, n):
        max = 0
        for j in range(i):
            val = G[i - j] + OPT[j]
            if val >= max:
                max = val
                i_star, j_star = i, j
        S[i].extend(S[j_star])
        S[i].append(G[i_star - j_star])

        OPT[i] = max

    print(OPT)
    print(S)
    return OPT[-1]

def costruzione_sol(S, n):
    for i in range(n):
        S.append([])
    S[0].append(0)

G = [0, 6, 10, 20, 21, 25]
print(cioccolata(G, 6))



