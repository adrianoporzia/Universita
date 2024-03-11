def IntergerSort2(X):
    #faccio una sorta di intergersort per avere
    #la lista ordinata in O(n+k)
    i=0
    k = max(X)
    y=[0] * (k+1)

    for i in range(len(X)):
        y[X[i]]+=1
    j = 0
    for i in range(len(y)):
        while y[i] > 0:
            X[j] = i
            j+=1
            y[i] -= 1
    return X

#lista ordinata, ora creo l'oracolo

def oracolo1(X):

    IntergerSort2(X) #lista ordinata O(n+k), ora creo l'oracolo

    k = max(X)
    y=[0] * (k+1)

    for i in range(len(X)):
        y[X[i]] +=1

    for i in range(1, k):
        y[i] = y[i] + y[i-1]

    return y


def InterrogaOracolo(X,k, a, b):
     
    oracolo1(X)

    if b > k:
        b = k
    
    if a <=1:
        return X[b]

    if a > b:
        a, b = b, a

    return X[b] - X[a-1]

    
l=[4, 2, 1, 1]
k = max(l)
print(InterrogaOracolo(l, k, 2, 3))