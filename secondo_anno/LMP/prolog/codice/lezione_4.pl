%list([ 1, 2, 3, 4, 5, 6]).

appartiene(X, [X | _ ]).

appartiene(X, [ _ | T]) :-
    appartiene(X, T).


%passo base
concatena([], A, A).

%passo induttivo
concatena([H | T], B, [H | L]) :-
    concatena(T, B, L).