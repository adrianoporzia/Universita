% Predicati esami Prolog - Adriano P.
% Prima parte teoria, seconda parte esercizi.

/* Member verifica che un elemento X appartiene alla lista.
 * Caso Base -> se l'elemento è in testa, torna true.
 * Passo Induttivo -> se X non è in testa, richiama member sul resto degli elementi.
 * Query -> member(a, [a, b, c]) = true
 */
member(X, [X | _]).
member(X, [_ | T]):-
    member(X, T).

/* Append concatena due liste L1 e L2 e torna la lista risultante L.
 * Caso Base -> concateno una lista vuota con L e mi torna L.
 * Passo Induttivo -> aggiungo il primo elemento della lista L1 al risultato della concatenazione tra il resto di L1 e L2.
 * Query -> append([a, b, c], [d, e, f], [a, b, c, d, e, f]) = true
 */
append([], L, L).
append([H | T1], L2, [H | T2]):-
    append(T1, L2, T2).

/* Rivoltata inverte una lista L.
 * Caso Base -> invertendo una lista vuota si ottiene una lista vuota.
 * Passo Induttivo -> inverto il resto della lista e aggiungo la testa alla fine della lista invertita.
 * Query -> rivoltata([a, b, c], [c, b, a]) = true
 */
rivoltata([], []).
rivoltata([H | T], RL):-
    rivoltata(T, RT),
    append(RT, [H], RL).

/* Sottrazione rimuove un singolo elemento X dalla lista.
 * Caso Base -> se la lista è vuota, non c'è nulla da rimuovere.
 * Passo Induttivo -> se l'elemento da rimuovere è in testa, ritorna il resto della lista; altrimenti continua la ricerca nel resto della lista.
 * Query -> sottrazione(a, [a, b, c], [b, c]) = true
 */
sottrazione(_, [], []).
sottrazione(X, [X | T], T).
sottrazione(X, [H | T1], [H | T2]):-
    sottrazione(X, T1, T2).

/* SottrazioneSuper rimuove tutte le occorrenze di un elemento X dalla lista.
 * Caso Base -> se la lista è vuota, non c'è nulla da rimuovere.
 * Passo Induttivo -> se l'elemento da rimuovere è in testa, elimina quell'elemento e continua nel resto della lista; se non è uguale, lo mantiene e continua.
 * Query -> sottrazioneSuper(a, [a, b, a, c], [b, c]) = true
 */
sottrazioneSuper(_, [], []).
sottrazioneSuper(X, [X | T], T2):-
    sottrazioneSuper(X, T, T2).
sottrazioneSuper(X, [H | T1], [H | T2]):-
    X \= H,
    sottrazioneSuper(X, T1, T2).

/* Permutazione genera una permutazione della lista L a partire da L1.
 * Caso Base -> la permutazione di una lista vuota è una lista vuota.
 * Passo Induttivo -> si genera una permutazione di T e poi si inserisce H in uno dei punti di L.
 * Query -> permutazione([a, b, c], L) = L = [a, b, c]; L = [a, c, b]; ecc.
 */
permutazione([], []).
permutazione([H | T], L):-
    permutazione(T, L1),
    member(H, L),
    sottrazione(H, L, L1).

/* Len calcola la lunghezza di una lista L.
 * Caso Base -> la lunghezza di una lista vuota è 0.
 * Passo Induttivo -> se la lista non è vuota, si rimuove la testa e si calcola
 * la lunghezza del resto della lista, aggiungendo 1 per la testa rimossa.
 * Query -> len([a, b, c], L) = L = 3
 */
len([], 0).
len([_ | T], L):-
    len(T, L1),    % Passo ricorsivo: calcola la lunghezza del resto della lista
    L1 >= 0,       % La lunghezza non può essere negativa
    L is 1 + L1.   % Aggiunge 1 per l'elemento rimosso dalla testa


/* ContaOccorrenze conta quante volte l'elemento X appare nella lista.
 * Caso Base -> se la lista è vuota, X appare 0 volte.
 * Passo Induttivo -> se X è in testa, conta una volta e continua a contare nel resto della lista.
 * Query -> contaOccorrenze(a, [a, b, a, c, a], N) = N = 3
 */
contaOccorrenze(_, [], 0).
contaOccorrenze(X, [X | T], N):-
    contaOccorrenze(X, T, N1),
    !,
    N is N1 + 1.
contaOccorrenze(X, [_ | T], N):-
    contaOccorrenze(X, T, N).

/* MyNot nega un predicato: se il predicato P è vero, il risultato è false, altrimenti true.
 * Utilizza un cut e fail per impedire ulteriori backtracking una volta che il predicato è risultato vero.
 * Query -> myNot(member(a, [b, c])) = true
 */
myNot(Predicato):-
    Predicato,
    !, fail.
myNot(_).



% ---------------------------------------------------------------------------------------------
% 									operatore =.. (univ) in Prolog
% ---------------------------------------------------------------------------------------------

/* 
L'operatore =.. (chiamato anche univ) è un operatore molto utile in Prolog 
che consente di decomporre un termine (predicato, fatto o regola) in una lista, 
o di costruire un termine a partire da una lista.

Sintassi:
Termine =.. Lista

1. Se `Termine` è un termine composto, `=..` lo decomporrà in una lista in cui 
   il primo elemento è il nome del predicato (functor) e gli altri elementi 
   sono i suoi argomenti.
   
2. Se `Lista` è una lista, `=..` costruirà un termine a partire da essa, dove 
   il primo elemento della lista è il nome del predicato (functor) e i successivi 
   elementi sono gli argomenti del predicato.

Esempi:
1. Decomposizione di un termine in una lista.
2. Costruzione di un termine a partire da una lista.
3. Manipolazione dinamica di termini.
4. Decomposizione e manipolazione di regole.
*/


% -------------------------------------------------------------------
% Esempio 1: Decomposizione di un termine in una lista
% -------------------------------------------------------------------
/*
Decomponiamo il termine a(1, 2, 3) in una lista [a, 1, 2, 3].
Il primo elemento della lista sarà il functor (a) e i successivi saranno
gli argomenti (1, 2, 3).
*/

%?- X = a(1, 2, 3), X =.. L.
/* 
Risultato:
X = a(1, 2, 3),
L = [a, 1, 2, 3].
*/


% -------------------------------------------------------------------
% Esempio 2: Costruzione di un termine a partire da una lista
% -------------------------------------------------------------------
/*
Costruiamo il termine a(1, 2, 3) a partire dalla lista [a, 1, 2, 3].
Il primo elemento della lista diventa il functor (a) e i successivi 
sono gli argomenti del predicato (1, 2, 3).
*/

%?- L = [a, 1, 2, 3], X =.. L.
/* 
Risultato:
L = [a, 1, 2, 3],
X = a(1, 2, 3).
*/


% -------------------------------------------------------------------
% Esempio 3: Aggiunta dinamica di argomenti a un termine
% -------------------------------------------------------------------
/*
Usando =.., possiamo manipolare dinamicamente i termini. Qui prendiamo
il termine a(1, 2), lo decomponiamo in una lista, aggiungiamo un terzo
argomento e poi ricostruiamo il termine a(1, 2, 3).
*/

%?- Term = a(1, 2), Term =.. L, append(L, [3], L2), Term2 =.. L2.
/* 
Risultato:
Term = a(1, 2),
L = [a, 1, 2],
L2 = [a, 1, 2, 3],
Term2 = a(1, 2, 3).
*/


% -------------------------------------------------------------------
% Esempio 4: Decomposizione di una regola
% -------------------------------------------------------------------
/*
Possiamo usare =.. per decomporre anche una regola. In questo esempio,
scomponiamo la regola a(1) :- b(2) in una lista che mostra chiaramente
il functor ':-' e i termini coinvolti.
*/

%?- X = (a(1) :- b(2)), X =.. L.
/* 
Risultato:
X = (a(1):-b(2)),
L = [':-', a(1), b(2)].
*/


% -------------------------------------------------------------------
% Esempio 5: Verifica della struttura di due termini
% -------------------------------------------------------------------
/*
Usiamo =.. per confrontare la struttura di due termini f(1, 2) e g(3, 4).
Con =.. possiamo verificare se hanno lo stesso numero di argomenti.
*/

%?- f(1, 2) =.. L1, g(3, 4) =.. L2, L1 = [Functor1 | Args1], L2 = [Functor2 | Args2], length(Args1, Len), length(Args2, Len).
/* 
Risultato:
L1 = [f, 1, 2],
L2 = [g, 3, 4],
Functor1 = f,
Functor2 = g,
Args1 = [1, 2],
Args2 = [3, 4],
Len = 2.
*/

% Query -> animale(toro, X). = X = [animale, toro]
animale(toro).
animale(A, X):-
	animale(A) =.. X.

/*Write e nl servono in prolog rispettivamente per stampare/mandare a schermo le cose
 * mentre nl serve per andare a capo.
 * 
 * Query -> p(a) = 10: a
 *				   13: a
 *				   true
 */

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

% Si puo pure far fallire un determinato predicato

fallimento_di_g(A):-
    g(A),
    !,
    fail.
fallimento_di_g(_).

%--------------------------------------------------------------------------------------------------
% 										Fibonacci / 2
/* Fibonacci calcola l'ennesimo numero della sequenza di Fibonacci.
 * Caso Base 1 -> Fibonacci(0) = 0
 * Caso Base 2 -> Fibonacci(1) = 1
 * Caso Base 3 -> Fibonacci(2) = 1
 * Passo Induttivo -> per N > 2, calcola i due numeri precedenti della sequenza
 * e somma i risultati.
 * Query -> fibonacci(5, M) = M = 5
 */
fibonacci(0, 0).
fibonacci(1, 1).
fibonacci(2, 1).

fibonacci(N, M):-
    N1 is N - 1,     % Calcola il numero precedente N1
    N2 is N - 2,     % Calcola il secondo numero precedente N2
    N1 > 0,          % Verifica che N1 sia maggiore di 0
    N2 > 0,          % Verifica che N2 sia maggiore di 0
    fibonacci(N1, M1),   % Induzione: calcola Fibonacci(N1)
    fibonacci(N2, M2),   % Induzione: calcola Fibonacci(N2)
    !,                   % Cut per evitare backtracking non necessario
    M is M1 + M2.        % Somma i risultati dei due Fibonacci precedenti


/* Fibonacci con il dynamic cosi per calcolare sottoproblemi gia calcolati lo fa rapidamente
 * senza ricalcolarli ogni volta.
 * 
 * :- dynamic fibonacci / 2.
 *fibonacci(0, 0).
 *fibonacci(1, 1).
 *fibonacci(2, 1).

 *fibonacci(N, M):-
 *  N1 is N - 1,
 *   N2 is N - 2,
 *   N1 > 0,
 *   N2 > 0,
 *   fibonacci(N1, M1),
 *   fibonacci(N2, M2),
 *   M is M1 + M2,
 *  asserta(fibonacci(N, M)), % Memorizza il risultato calcolato per N nella base di conoscenza
 *    !. 
 * */


% --------------------------------------------------------------------------------									
% 									Assert e retract

/*
 * assert/1 e asserta/1 aggiungono fatti o regole dinamicamente nella base di conoscenza di Prolog.
 * - `asserta(X)`: aggiunge il fatto o la regola `X` **all'inizio** della base di conoscenza.
 * - `assert(X)` o `assertz(X)`: aggiunge `X` **alla fine** della base di conoscenza.
 * 
 * Esempi:
 * ?- asserta(fatto(a)).
 * Aggiunge il fatto `fatto(a)` all'inizio della base di conoscenza.
 *
 * ?- assert(fatto(b)).
 * Aggiunge il fatto `fatto(b)` alla fine della base di conoscenza.
 *
 * retract/1 rimuove fatti o regole dalla base di conoscenza.
 * - `retract(X)`: cerca e rimuove la prima occorrenza del fatto o della regola `X` dalla base di conoscenza.
 *
 * Esempio:
 * ?- retract(fatto(a)).
 * Rimuove il fatto `fatto(a)` dalla base di conoscenza.
 *
 * retractall/1 rimuove tutte le occorrenze di un fatto o regola.
 * - `retractall(X)`: rimuove **tutti** i fatti o le regole che corrispondono a `X` dalla base di conoscenza.
 *
 * Esempio:
 * ?- retractall(fatto(_)).
 * Rimuove tutti i fatti che hanno la forma `fatto(X)`, indipendentemente dal valore di `X`.
 *
 * dynamic/1 permette di dichiarare che un predicato può essere modificato dinamicamente.
 * - `:- dynamic X/N`: indica che il predicato `X` con `N` argomenti è dinamico, quindi può essere aggiunto o rimosso dalla base di conoscenza.
 *
 * Esempio:
 * :- dynamic fatto/1.
 * Dichiara che il predicato `fatto/1` può essere manipolato dinamicamente.
 *
 * Questi predicati permettono di aggiornare la base di conoscenza durante l'esecuzione del programma.
 */


%---------------------------------------------------------------------------------------------------
%											Alberi


/* Leaf trova una foglia dell'albero binario t(R, Child).
 * Caso Base -> una foglia è un nodo senza figli (lista vuota di figli).
 * Passo Induttivo -> se il nodo ha figli, controlla ciascun figlio ricorsivamente.
 * Query -> leaf(t(1, [t(2, []), t(3, [])]), L) = L = 2; L = 3
 */
leaf(t(R, []), R).   % Caso base: un nodo senza figli è una foglia.
leaf(t(_, Child), L):- 
    member(C, Child), % Scorre i figli del nodo.
    leaf(C, L).       % Verifica se i figli sono foglie.

/* Node trova un nodo nell'albero binario t(R, Child).
 * Caso Base -> il nodo corrente è un nodo valido (la radice).
 * Passo Induttivo -> se il nodo ha figli, scorre i figli e li verifica come nodi ricorsivamente.
 * Query -> node(t(1, [t(2, []), t(3, [])]), N) = N = 1; N = 2; N = 3
 */
node(t(R, _), R).     % Caso base: il nodo corrente è un nodo valido.
node(t(_, Child), L):- 
    member(C, Child), % Scorre i figli del nodo.
    node(C, L).       % Verifica se i figli sono nodi.



%---------------------------------------------------------------------------------------------
%											:-OP


% Definizione di operatori personalizzati per operazioni aritmetiche e relazioni
:- op(500, xfy, somma).       % Precedenza 500, associatività a destra
:- op(600, xfy, moltiplica).  % Precedenza 600, associatività a destra
:- op(100, yfx, di).          % Precedenza 100, associatività a sinistra
:- op(200, yfx, ha).          % Precedenza 200, associatività a sinistra

% Predicati per somma e moltiplicazione di due numeri in un termine t(X, Y)
somma(t(X, Y), S):- 
    S is X + Y.
moltiplica(t(X, Y), M):- 
    M is X * Y.

% Fatti che descrivono relazioni di possesso e appartenenza
mario ha macchina di dario.
luca ha scarpe di ionut.
jack ha capelli di maradona.
jack ha borsa di pelle di daino.

% Esempi di query:
% - Somma: ?- t(3, 5) somma S.  % S = 8
% - Chi ha Cosa di Chialtro
% - Moltiplicazione: ?- t(4, 6) moltiplica M.  % M = 24
% - Relazioni: ?- mario ha macchina di dario.  % true
% - Rimozione: ?- retract(jack ha borsa di pelle di daino). % true


%-------------------------------------------------------------------------------------------------
%									Bagof e setof
%-------------------------------------------------------------------------------------------------
vive(mario, roma).
vive(luigi, roma).
vive(massimo, roma).
vive(luisa, milano).

n(11, a, xx).
n(7, b, xx).
n(2, b, dx).
n(1, q, x).

/* 
Bagof raccoglie tutte le soluzioni di un'espressione in una lista.
- Bagof permette di ottenere duplicati.
- In questo caso, raccoglie tutte le persone che vivono in una città, città è irrilevante pero.
Query -> provaBagof(Lista) = Lista = [mario, luigi, massimo, luisa]
 */
provaBagof(Lista):-
    bagof(Persona, Citta^vive(Persona, Citta), Lista).

/* 
Setof raccoglie tutte le soluzioni di un'espressione in una lista **ordinata** e senza duplicati.
- Setof rimuove i duplicati e ordina i risultati.
- In questo caso, raccoglie tutte le città dove vive qualcuno.
Query -> provaSetof(Lista) = Lista = [milano, roma]
 */
provaSetof(Lista):-
    setof(Citta, Persona^vive(Persona, Citta), Lista).

/* 
Setof per rimuovere duplicati basati su un valore specifico (Vocali).
- Qui rimuove i duplicati di Vocali dalla lista n/3.
Query -> removeDuplicatiDaN(L) = L = [a, b, q]
 */
removeDuplicatiDaN(L):-
    setof(Vocali, (Num, Val)^n(Num, Vocali, Val), L).

/* 
Differenza tra bagof e setof:
1. **bagof/3**:
   - Raccoglie tutte le soluzioni possibili e mantiene i duplicati.
   - Le soluzioni non sono ordinate automaticamente.
   
2. **setof/3**:
   - Raccoglie tutte le soluzioni, rimuove i duplicati e ordina i risultati.
   - Se non ci sono risultati, fallisce (bagof invece restituisce una lista vuota).
 */


%-------------------------------------------------------------------------------------------------
%									Visita in Profondità, DFS
%-------------------------------------------------------------------------------------------------

/* Definizione degli archi (edge) per il grafo.
 * Ogni fatto edge(X, Y) rappresenta un bordo diretto da X a Y.
 */
edge(a, b).
edge(b, c).
edge(c, d).
edge(a, e).
edge(d, m).
edge(e, f).
edge(f, k).
edge(f, c).

/* PathDFS trova un percorso tra due nodi in un grafo usando la ricerca in profondità (DFS).
 * Caso Base -> se esiste un bordo diretto tra X e Y, restituisce il percorso [X, Y].
 * Passo Induttivo -> se esiste un arco da X a un nodo Z, cerca induttivamente un percorso
 *                    da Z a Y, aggiungendo X all'inizio del percorso.
 * Query -> pathDfs(a, m, Percorso) = Percorso = [a, b, c, d, m]
 */

pathDfs(X, Y, [X, Y]):-
    edge(X, Y).

pathDfs(X, Y, [X | P_Z_Y]):-
    edge(X, Z),           % Trova un nodo Z collegato a X
    pathDfs(Z, Y, P_Z_Y). % Cerca il percorso da Z a Y ricorsivamente


%----------------------------------------------------------------------------------------------
%										Visita ampiezza, BFS
%----------------------------------------------------------------------------------------------

/* BFS (Breadth-First Search) trova un percorso tra due nodi in un grafo cercando
 * in ampiezza, esaminando i nodi strato per strato (livello per livello).
 * - La frontiera rappresenta i nodi che devono ancora essere esplorati.
 * - Si aggiungono nuovi nodi alla frontiera esaminando i nodi raggiungibili dagli attuali.
 * Query -> pathBfs(a, m, P) = P = [a, b, c, d, m]
 */

/* pathBfs(X, Y, P) -> Trova un percorso tra i nodi X e Y utilizzando BFS.
 * - Genera la frontiera iniziale con il nodo X.
 * - Verifica se Y si trova nella frontiera corrente.
 * - Inverte il percorso trovato per restituirlo nell'ordine corretto.
 * Caso Base -> Se Y è trovato, restituisce il percorso.
 * Passo Induttivo -> Espande la frontiera esplorando i nodi raggiungibili.
 */

/* prossimafrontiera(CurrentFrontier, NewFrontier) -> Espande la frontiera attuale
 * - Prende ogni percorso nella frontiera corrente e trova tutti i nodi raggiungibili.
 * - Aggiunge i nuovi nodi alla frontiera per continuare la ricerca.
 * Caso Base -> Se la frontiera corrente è vuota, la ricerca termina.
 * Passo Induttivo -> Espande la frontiera esplorando i nodi raggiungibili.
 */

% Predicato principale per trovare un percorso da X a Y usando BFS
pathBfs(X, Y, P):-
    prossimafrontiera([[X]], F),   % Genera la frontiera iniziale partendo da X
    member([Y|P_Y], F),            % Trova Y nella frontiera, con il percorso associato
    reverse([Y|P_Y], P).           % Inverte il percorso trovato per restituirlo correttamente

% Caso base: Se la frontiera è vuota, termina la ricerca
prossimafrontiera([], []).

% Espande la frontiera esplorando nuovi nodi raggiungibili
prossimafrontiera([[X|PX] | R], F):-
    findall([Z | [X|PX]], edge(X, Z), RZ),  % Trova i nodi raggiungibili da X e costruisce nuovi percorsi
    prossimafrontiera(R, FF),               % Continua a espandere il resto della frontiera
    append(RZ, FF, F).                      % Aggiunge i nuovi nodi alla frontiera


/*
 * prossimafrontiera([], []).
prossimafrontiera([[X,PX]|R], F):-
    setof([Z|[X|PX]], edge(X,Z), RZ),  % Lista di nodi raggiungibili
    prossimafrontiera(R, FF),
    append(RZ, FF, F).

opf(F,FR,Y):-
    prossimafrontiera(F,FR),
    member(Y, FR).

opf(F,FR,Y):-
    prossimafrontiera(F,FRZ),
    opf(FRZ,FR,Y).

pathBfs(X,Y,P):-
    prossimafrontiera([[X|R]],F),
    member(Y,F),
    reverse(F,P),
    opf([X],FF,Y).
 * */

%-------------------------------------------------------------------------------------------------
% 											Grammatiche
%-------------------------------------------------------------------------------------------------

/*
 * Scopo e utilizzo di queste regole grammaticali:
 * - Questi predicati vengono utilizzati per descrivere e riconoscere stringhe che appartengono a un linguaggio formale.
 * - Utilizzando predicati come 'A', 'B', e 'C', possiamo definire regole grammaticali per generare e validare stringhe.
 * - I predicati permettono di verificare se una stringa segue le regole definite della grammatica.

 * Quando usarle:
 * - Usa queste regole per eseguire il **parsing** di una stringa o per generare stringhe che seguono una grammatica specifica.
 * - Sono utili nei linguaggi di programmazione, nei compilatori, o per riconoscere strutture linguistiche (ad es. parser di linguaggi).
 * - Le regole possono essere estese per rappresentare sintassi complesse come espressioni matematiche o strutture di linguaggi naturali.

 * Come funzionano:
 * - Ogni predicato rappresenta una regola grammaticale.
 * - I predicati terminali (come 'B' o 'C') verificano simboli di base nella stringa.
 * - I predicati non terminali (come 'A') combinano le regole e chiamano altri predicati per definire strutture più complesse.

 * Esempio pratico:
 * - Puoi usare questi predicati per verificare se una stringa appartiene a un linguaggio formale, ad esempio:
 *   - 'A'([a,b,a], []) verifica se la stringa "aba" appartiene al linguaggio definito dalle regole.
 */

/* 
 * Questa grammatica riconosce un insieme di stringhe formate dalle lettere 'a' e 'b'.
 * Le regole della grammatica sono definite come segue:
 * - 'A' è il simbolo iniziale e può derivare in due possibili forme:
 *    1. 'B' seguito da 'C' -> Una stringa che inizia con 'a' e termina con 'b'.
 *    2. 'C' seguito da due 'B' -> Una stringa che inizia con 'b' e contiene due 'a'.
 * - 'B' è associato alla lettera 'a'.
 * - 'C' è associato alla lettera 'b'.
 */

/* Regola 1: 'A' deriva da 'B' seguito da 'C'. 
 * Una stringa che appartiene a 'A' può iniziare con 'a' e finire con 'b'.
 */
'A'(L, R1) :-
    'B'(L, R),
    'C'(R, R1).

/* Regola 2: 'A' deriva da 'C' seguito da due 'B'. 
 * Una stringa che appartiene a 'A' può iniziare con 'b' e contenere due 'a'.
 */
'A'(L, R2) :-
    'C'(L, R),
    'B'(R, R1),
    'B'(R1, R2).

/* 'B' rappresenta la lettera 'a'. 
 * Verifica se la testa della lista è 'a' e consuma l'elemento.
 */
'B'([H|T], T) :-
    H = 'a'.

/* 'C' rappresenta la lettera 'b'. 
 * Verifica se la testa della lista è 'b' e consuma l'elemento.
 */
'C'([H|T], T) :-
    H = 'b'.
% Query 
% ?- 'A'([b,a,a], []).
% Risultato: true (la stringa appartiene al linguaggio)
%?- 'A'([b,b,b], []).
% Risultato: false (la stringa non appartiene al linguaggio)


%-------------------------------------------- 2° Parte ----------------------------------------

%-----------------------------------------------------------------------------------------------
%											Torri di Hanoi
%-----------------------------------------------------------------------------------------------
/* Hanoi risolve il problema della torre di Hanoi spostando i dischi tra tre pile.
 * Caso Base -> se non ci sono dischi, non è necessario spostare nulla.
 * Passo Induttivo -> sposta un disco dalla pila A alla pila B e verifica l'ordinamento.
 * Query -> hanoi([4, 3, 2, 1], [], []) = true
 *
 * Ordinata verifica se una pila è ordinata (dal disco più grande al più piccolo).
 * Caso Base -> una pila vuota o con un solo disco è sempre ordinata.
 * Passo Induttivo -> il primo disco deve essere più grande del secondo.
 * Query -> ordinata([4, 3, 2, 1]) = true
 */
hanoi([], _).
hanoi([X | A], B, C):-
    ordinata([X | A]),          % Verifica che la pila A sia ordinata
    ordinata(B),                % Verifica che la pila B sia ordinata
    ordinata(C),                % Verifica che la pila C sia ordinata
    hanoi(A, [X | B], C).       % Sposta il disco dalla pila A alla pila B

ordinata([]).
ordinata([_]).
ordinata([H1, H2 | T]):-
    H1 > H2,
    ordinata([H2 | T]).

%-----------------------------------------------------------------------------------------------
%									8 regine
%-----------------------------------------------------------------------------------------------

controlloCoppia([_]).

controlloCoppia([H1, H2 | T]):-
    controlloRiga(H1, H2),
    controlloColonna(H1, H2),
    controlloDiagonale(H1, H2),
    controlloCoppia([H1 | T]).
    

controlloDiagonale([A, B], [C, D]):-
    X is A - C,
    Y is B - D,
    X =\= Y,
    X =\= -Y.

controlloRiga([A, _], [A, _]).
controlloColonna([A, _], [_, A]).

controlloSoluzione([_]).
controlloSoluzione([H | T]):-
    \+controlloCoppia([H | T]),
    controlloSoluzione([T]).

%-----------------------------------------------------------------------------------------------
%									Esame Oroscopo
%-----------------------------------------------------------------------------------------------

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


%-----------------------------------------------------------------------------------------------
%										Daci e Romani
%-----------------------------------------------------------------------------------------------

% Query ?- controlloSoluzione(2, [(3,4), (6,7), (9,10)]).

dardo(7, 8).

controlloSoluzione(_, [_]).
controlloSoluzione(M, [H | T]):-
    \+controlloCorte(M, H),
    controlloSoluzione(M, T).


controlloCorte(M, (X1, Y1)):-
    dardo(X2, Y2),
    controlloRiga(M, (X1 , Y1), (X2 , Y2)),
    controlloColonna(M, (X1 , Y1), (X2 , Y2)),
    controlloDiagonale(M, (X1 , Y1), (X2 , Y2)).
    
controlloRiga(M, (X1 , _), (X2 , _)):-
    abs(X1 - X2) =< M.

controlloColonna(M, (_ , Y1), (_ , Y2)):-
    abs(Y1 - Y2) =< M.

controlloDiagonale(M, (A, B), (C, D)):-
    X is A - C,  
    Y is B - D,  
    abs(X) =< M,  
    abs(Y) =< M.  


%-----------------------------------------------------------------------------------------------
%										Dispensa e cibo
%-----------------------------------------------------------------------------------------------

%Query ? -  assert(ingrediente((uovo, 2))), assert(ingrediente((guanciale, 1))).
%			piatto_per_oggi(40, 1, carbonara, [(uovo, 2), (guanciale, 1)]) = true

:-dynamic ingrediente / 1.

piatto(carbonara, [(uovo, 2), (guanciale, 1)], 30).
piatto(amatriciana, [(sugo, 150), (guanciale,2 )], 30).
piatto(polpette, [(macinato, 600), (spezie, 20)], 50).

piatto_per_oggi(TempoDisposizione, NumPersone, NomePiatto, IngredientiConQuantità):-
    piatto(NomePiatto, IngredientiPerPiatto, X),
    TempoDisposizione >= X,
    checkIngredienti(NumPersone, IngredientiPerPiatto, IngredientiConQuantità).

checkIngredienti(_, [], _).
checkIngredienti(NumPersona, [(Nome,QuantiNeServono) | T], IngredientiConQuantità):-
    Necessari is NumPersona * QuantiNeServono,
    member((Nome, Necessari), IngredientiConQuantità),
    ingrediente(Nome, Disponibili),
    Disponibili >=0,
    retract(ingrediente((Nome, Disponibili))),
    X is Disponibili - Necessari,
    asserta(ingrediente((Nome, X))),
    checkIngredienti(NumPersona, T, IngredientiConQuantità).
	

%-----------------------------------------------------------------------------------------------
%									 Grafo delle dipendense 1
%-----------------------------------------------------------------------------------------------


arco(gatto, mangia).
arco(mangia, cane).
arco(cane, mangia).
arco(mangia, topo).

soggetto_verbo_oggetto(V, S, O):-
    arco(S, V),
    arco(V, O).


%-----------------------------------------------------------------------------------------------
%										Stessa Struttura
%-----------------------------------------------------------------------------------------------

% FORMA FACILE

%haStessaStruttura([Sinistra1, Destra1], [Sinistra2, Destra2]) :-
%    stessaStrutturaFatto(Sinistra1, Sinistra2), 
%    stessaStrutturaLista(Destra1, Destra2).    

%stessaStrutturaFatto(F1, F2) :-
%    F1 =.. [_|Args1],  
%    F2 =.. [_|Args2],  
%    length(Args1, L1), 
%    length(Args2, L2), 
%    L1 =:= L2.      

%stessaStrutturaLista(L1, L2) :-
%    length(L1, Len1),
%    length(L2, Len2),
%    Len1 =:= Len2.


% Predicato per confrontare due fatti o due regole
haStessaStruttura(P1, P2) :-
    P1 =.. Lista1,
    P2 =.. Lista2,
    stessoNumeroArgomenti(Lista1, Lista2).

haStessaStruttura((P1 :- Corpo1), (P2 :- Corpo2)) :-
    haStessaStruttura(P1, P2),
    stessoNumeroComponenti(Corpo1, Corpo2).

% Controlla se due liste di predicati hanno lo stesso numero di argomenti
stessoNumeroArgomenti([_ | Arg1], [_ | Arg2]) :-
    length(Arg1, N1),
    length(Arg2, N2),
    N1 =:= N2.

% Controlla che i corpi delle regole abbiano lo stesso numero di componenti
stessoNumeroComponenti(C1, C2) :-
    C1 =.. Lista1,
    C2 =.. Lista2,
    length(Lista1, Lunghezza1),
    length(Lista2, Lunghezza2),
    Lunghezza1 =:= Lunghezza2.



