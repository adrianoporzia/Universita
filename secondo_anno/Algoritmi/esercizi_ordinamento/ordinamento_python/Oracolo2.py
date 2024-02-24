def CreazioneOracolo(X):
    k = max(X)
    y=[0] * (k+1)

    for i in range(len(X) ):
        y[X[i]] +=1

    for i in range(1, k +1):
        y[i] = y[i] + y[i-1]

    return y



def InterrogaOracolo(X, k, a, b):

    X= CreazioneOracolo(X)


    if b > k:
        b = k -1
    if a <= 1:
        return X[b]
    else:
        return X[b] - X[a - 1]
    
l=[1, 10, 4, 5, 5, 20, 3, 3]

print(InterrogaOracolo(l, 20 , 5, 15))
