edge(a, b).
edge(b, c).
edge(a, e).
edge(e, f).
edge(f, k).
edge(c, d).
edge(f, c).
edge(d, a).

%passo base
path(X, Y) :-
    edge(X,Y).

%passo induttivo
path(X, Y) :-
    edge(X, Z), 
    path(Z, Y).

	%oppure
	%path(X, Z),
	%path(Z, Y).

%PROVA
%passo base
cicle(X) :- 
    edge(X, Z),
    edge(Z, X).

%passo induttivo
cicle(X) :- 
    edge(X, Z),
    path(Z, X).
