genitore(maria, dario).
genitore(maria, gino).
genitore(pino, rino).
genitore(mario, pino).
genitore(luca, pino).

fratello(X, Y) :- 
    genitore(Z, X), 
    genitore(Z, Y).

nonno(X, Y) :- 
    genitore(X, Z),
    genitore(Z, Y).

avo(X, Y) :- 
    genitore(X, Y). 

avo(X, Y) :- 
    genitore(X,Z), 
    avo(Z, Y).