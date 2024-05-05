% Predicato per risolvere il problema delle 8 regine
eight_queens(Board) :-
    length(Board, 8),        % La scacchiera è una lista di lunghezza 8
    permutation([1,2,3,4,5,6,7,8], Board),  % Permuta i numeri da 1 a 8 per le colonne
    safe_queens(Board).      % Verifica che le regine siano in posizioni sicure

% Verifica se le regine sono in posizioni sicure
safe_queens([]).
safe_queens([Queen|RestQueens]) :-
    safe_queens(RestQueens),
    no_attack(Queen, RestQueens, 1).

% Verifica che una regina non attacchi le altre regine
no_attack(_, [], _).
no_attack(Queen, [Y|RestQueens], N) :-
    Queen =\= Y,
    Queen + N =\= Y,
    Queen - N =\= Y,
    NextN is N + 1,
    no_attack(Queen, RestQueens, NextN).

% Esempio di utilizzo:
% ?- eight_queens(Board).

