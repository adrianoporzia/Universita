amci(mario, maria).
amici(mario, dario).
amici(mario, pino).

/* predicato not*/
f(a).
f(b).
g(a).
g(b).
g(j).
k(a).
/*fail e cut*/


p(A) :-
    f(A),
    write('10: '), write(A), nl,
    !,
    g(A),
    write('13: '), write(A),nl, 
    k(A).

fallimento_di_g(A):-
    g(A),
    !,
    fail.

fallimento_di_g(_).

mynot(Predicato):-
    Predicato, !, fail.
mynot(_).


numerodiEl([],_,0).
numerodiEl([A|_],A,+1).
numerodiEl([_|T], El, N):-
      numerodiEl(T,El,N).


nEl([],_,0). % caso base
nEl([El|T],El,M):- % primo caso in cui l'elemento è in testa
    !, % cosi non ritorno sopra
    nEl(T,El,N),
    M is N+1.
nEl([X|T],El,M):-
    nEl(T,El,M). 
% se verificco i primi duer nEl non entrerò nel 3, pero se ci sono piu elementi si ferma sulla prima occorrenza
% quindi il cut bisogna saperlo usare perche qui mi serviva vedere tutti gli ele se facevo nEl([1,2 , 2, 3], A, X)



















    
