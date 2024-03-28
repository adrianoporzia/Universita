/* Esercitazione:
Abbiamo individuato un business molto interessante: vendere sogni alle persone. Si vuol far credere che il
futuro delle persone dipenda dall’uso delle vocali all’interno dell’oroscopo per il loro segno zoodiacale. La
giornata è positiva se nell’oroscopo il la frequenza media delle vocali è esattamente uguale alla frequenza
media delle consonanti.
Si vuole dunque definire un predicato prolog che consenta di calcolare la frequenza media delle vocali e
quella delle consonanti e di un altro che poi permetta di dire se una giornata è fortunata.
*/

vocale(a).
vocale(e).
vocale(i).
vocale(o).
vocale(u).


mynot(A):-
    A, !, fail.
mynot(_).

len([], 0).
len([_|T], L) :-
    len(T, A),
    A >= 0,
	L is 1 + A.

conta_vocali([], 0).
conta_vocali([H|T], Count) :-
    vocale(H), 
    conta_vocali(T, Count1), 
    Count is Count1 + 1.
conta_vocali([_|T], Count) :-
    conta_vocali(T, Count).


conta_consonanti([], 0).
conta_consonanti([H|T], Count) :-
    mynot(vocale(H)),
    conta_consonanti(T, Count1),
    Count is Count1 + 1.
conta_consonanti([_|T], Count) :-
    conta_consonanti(T, Count).


frequenza(Segno) :-
    len(Segno, L), 
    conta_vocali(Segno, V),
    conta_consonanti(Segno, C),
    !,
    A is V / 5,
    A is C / 16.	








    
   
    
    

    

