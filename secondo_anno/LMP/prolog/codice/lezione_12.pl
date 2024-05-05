node([], [], []).
node([a, b, c], [], []).
node([a, b], [c], []).
node([a], [c], [b]).
node([a], [], [b, c]).
node([], [a], [b, c]).
node([c], [a], [b]).
node([c], [a, b], []).
node([], [a, b, c], []).
node([a, c], [b], []).
node([a], [], [b, c]).

edge(node([a, b, c], [], []), node([a, b], [c], [])).

edge(node([X | A], B, C), node(A, [X | B], C)):- 
        ord([x|  a]),
        ord([X| B]),
        ord(C).

edge(node([X | A], B, C), node(A, [X | B], C)):- 
        ord([x|  a]),
        ord([X| B]),
        ord(C).

ord([]).
ord([_]).
ord([H1, H2| T]):-
    H1 > H2,
    ord([H2 | T]).
    




