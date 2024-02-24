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
l=[0, 0, 1, 0, 1, 1, 1 , 0]
print(IntergerSort2(l))

