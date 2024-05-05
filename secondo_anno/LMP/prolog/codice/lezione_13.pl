:-dynamic appoggio/1.
/*
predicato numeri
numeri(L) se ci sono i numeri di quei fatti
L è una lista
cut, fail, assert, retract
bagof con N struttura unificata su cosa vogliamo raccogliere, predicato di cui vogiamo fare analisi, lista riempita  CON DOPPIONI,
setof LEVA DOPPIONI e ordina anche
l^n... serve per dire che L deve eseistere
*/

n(11).
n(2).
n(4).
n(5).
n(8).

n(11, a).
n(2, m).
n(4, k).
n(5,k).
n(8, f).


appoggio([]).

numeri(L):-
    n(H),
    appoggio(L),
    append(L, [H], LN),
    retract(appoggio(L)),
    assert(appoggio(LN)),
    write(H),nl,
    fail.

numeri(L):-
    appoggio(L),
    retract(appoggio(L)),
    assert(appoggio([])),
    write(fine), nl.
    
l(L):-
    n(_, L).
num(L):-
    n(L, _).

len([], 0).
len([_|T], L) :-
    len(T, A),
    A >= 0,
	L is 1 + A.
num_lettere(V):-
     setof(L, N^n(N,L), Lista),
     len(Lista, V).



