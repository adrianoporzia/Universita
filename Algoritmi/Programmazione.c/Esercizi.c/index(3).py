


# %%
def intersection(d0,d1):
    l=[]
    for k in d0.keys():
        if k in l:
            continue
        else:
            l.append(k)
    for k in d1.keys():
        if k in l:
            continue
        else:
            l.append(k)
    return l
d0={'prova':6, 'salve ':'codice', 6:3.14}
d1={'prova1':6, '3.14':'(1,2)', 55:3.14}
print(intersection(d0,d1))
# %%
