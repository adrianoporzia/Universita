def tabulation(S: str) -> int:
    n = len(S)
    M = [[0] * n for _ in range(n)]

    for i in range(n):
        M[i][i] = 1

    for d in range(1, n):
        for i in range(n - d):
            j = i + d
            if S[i] == S[j]:
                M[i][j] = 2 + M[i + 1][j - 1]
            else:
                M[i][j] = max(M[i + 1][j], M[i][j - 1])
    return M[0][n - 1]


def memoization(s: str, i: int, j: int, cache: dict):
    if (i, j) in cache:
        return cache[i, j]

    if i > j:
        cache[i, j] = 0
    elif i == j:
        cache[i, j] = 1
    else:
        if s[i] == s[j]:
            cache[i, j] = 2 + memoization(s, i + 1, j - 1, cache)
        else:
            cache[i, j] = max(
                    memoization(s, i + 1, j, cache),
                    memoization(s, i, j - 1, cache),
                    )
    return cache[i, j]

S = "algoritmo"
n = len(S)
cache = {}
print(memoization(S, 0, n - 1, cache))
