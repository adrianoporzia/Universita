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

my_not(Predicato):-
    Predicato, 
    !,
    fail.
my_not(_).


count_vocali([], 0).
count_vocali([H|T], Count):-
    vocale(H),
    !,
    count_vocali(T, Count1),
    Count is Count1 + 1.
count_vocali([_|T], Count):-
    count_vocali(T, Count).

count_consonanti([], 0).
count_consonanti([H|T], Count):-
    my_not(vocale(H)),
    !,
    count_consonanti(T, Count1),
    Count is Count1 + 1.
count_consonanti([_|T], Count):-
    count_consonanti(T, Count).


frequenza_vocali(Oroscopo, Freq):-
    count_vocali(Oroscopo, Vocali),
    !,
    Freq is Vocali / 5.

frequenza_consonanti(Oroscopo, Freq):-
    count_consonanti(Oroscopo, Consonanti),
    !,
    Freq is Consonanti / 16.

giornata(A):-
    write("Giornata Fortunata").
    

frequenza_lettere(Oroscopo):-
    frequenza_vocali(Oroscopo, V),
    frequenza_consonanti(Oroscopo, C),
    !,
    A is V,
    A is C,
    giornata(A).

    
    

    













