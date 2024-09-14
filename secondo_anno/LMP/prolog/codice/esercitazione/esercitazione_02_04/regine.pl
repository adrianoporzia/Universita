controlloRiga([A, B], [A, C]).

controlloColonna([A, B], [C, A]).

controlloDiagonale([A, B], [C, D]):-
	X is A - C,
	Y is B - D,
    X =\= Y,
    X =\= -Y.

controlloCoppie([A]).

controlloCoppie([A, B | T]):-
    controlloRiga(A, B),
    controlloColonna(A, B),
    controlloDiagonale(A, B),
    controlloCoppie([A | T]).


controlloSoluzione([A]).

controlloSoluzione([H | T]):-
    \+ controlloCoppie([H | T]),
    controlloSoluzione([T]).

/*
 * controlloSoluzione([[1, 3], [3, 4], [4, 2], [ 2,1 ]]).
 * */