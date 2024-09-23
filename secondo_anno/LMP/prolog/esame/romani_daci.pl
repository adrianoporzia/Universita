dardo(7, 8).

controlloSoluzione(_, [_]).
controlloSoluzione(M, [H | T]):-
    \+controlloCorte(M, H),
    controlloSoluzione(M, T).


controlloCorte(M, (X1, Y1)):-
    dardo(X2, Y2),
    controlloRiga(M, (X1 , Y1), (X2 , Y2)),
    controlloColonna(M, (X1 , Y1), (X2 , Y2)),
    controlloDiagonale(M, (X1 , Y1), (X2 , Y2)).
    
controlloRiga(M, (X1 , _), (X2 , _)):-
    abs(X1 - X2) =< M.

controlloColonna(M, (_ , Y1), (_ , Y2)):-
    abs(Y1 - Y2) =< M.

controlloDiagonale(M, (A, B), (C, D)):-
    X is A - C,  
    Y is B - D,  
    abs(X) =< M,  
    abs(Y) =< M.  



