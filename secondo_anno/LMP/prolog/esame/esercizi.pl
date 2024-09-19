
member(X, [X | _]).
member(X, [_ | T]):-
    member(X, T).


append([], X, X).
append([H | T], B, [H | L]):-
    append(T, B, L).

rivoltata([], []).
rivoltata([H | T] , RL):-
    rivoltata(T, RT),
    append(RT, [H], RL).

sottrazione(_, [], []).
sottrazione(X, [X | T], T).
sottrazione(X,  [H | T1], [H | T2]):-
    sottrazione(X, T1, T2).

sottrazioneSuper(_, [], []).
sottrazioneSuper(X, [X | T], T2):-
    sottrazioneSuper(X, T, T2).
sottrazioneSuper(X, [H | T1], [H | T2]):-
    X \= H,
    sottrazioneSuper(X, T1, T2).

permutazione([], []).
permutazione([H | T] , L):-
    permutazione(T, L1),
    member(H, L),
    sottrazione(H, L, L1).

%LISTE

len([], 0).
len([_ | T], L):-
    len(T, L1),
    L1 >= 0,
    L is 1 + L1.


contaOccorrenze(_, [], 0).
contaOccorrenze(X, [X | T], N):-
    contaOccorrenze(X, T, N1),
    !,
    N is N1 + 1.
contaOccorrenze(X, [_ | T], N):-
    contaOccorrenze(X, T, N).


%NOT
amici(adriano, ionut). % ?- not(amici(adriano, baudo)) --> true 
amici(pippo, baudo).

f(a).
f(c).
g(a).
g(b).
g(j).
k(a).

p(A) :-
    f(A),
    write('10: '), write(A), nl,
    !,
    g(A),
    write('13: '), write(A),nl, 
    k(A).

%FAIL
fallimento_di_g(A):-
    g(A),
    !,
    fail.
fallimento_di_g(_).


myNot(Predicato):-
	Predicato,
    !,
    fail.
myNot(_).
    

%ESAME 2023, OROSCOPO
vocale(a).
vocale(e).
vocale(i).
vocale(o).
vocale(u).

contaVocali([], 0).
contaVocali([H | T], V):-
    vocale(H),
    !,
    contaVocali(T, V1),
    V is 1 + V1.
contaVocali([_ | T], V):-
    contaVocali(T, V).

contaConsonanti([], 0).
contaConsonanti(L, C):-
    len(L, C1),
    contaVocali(L, C2),
    C1 >= C2,
    C is C1 - C2.


frequenzaMediaVocali(Segno, FrequenzaVocali):-
    contaVocali(Segno, Vocali),
    FrequenzaVocali is Vocali / 5. 

frequenzaMediaConsonanti(Segno, FrequenzaConsonanti):-
    contaConsonanti(Segno, Consonanti),
    FrequenzaConsonanti is Consonanti / 16.

giornataFortunata(Segno):-
    frequenzaMediaVocali(Segno, Vocali),
    frequenzaMediaConsonanti(Segno, Consonanti),
    Vocali = Consonanti,
    !,
    write("Oggi è una giornata fortunata"), nl.
giornataFortunata(_):-
    write("Oggi non è una giornata fortunata"), nl.















    
