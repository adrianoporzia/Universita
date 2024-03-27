- # Lezione 7
- ## Not  =/=
- #### Es:
- Mario e Maria sono amici 
    
        amici(mario, maria)
- ##### oss: 
- Se scrivo quache fatto diventa **vero**, tutto il resto è **falso*. 
- Però per verificare che sia falso devo verificare che non è stato scritto quindi.
- Se ho una lista di amici

        amici(mario, maria).
        amici(mario, dario).
        amici(mario, pino).
        
- ?- not amici(mario, rino) sostanzialmente
- **Algoritmo di risoluzione del prolog verifica ciò**. 
- ## predicato fail
- Ci costringe ogni volta a **esplorare un altro ramo della ricerca**.
- Arriveremo ad un punto che avremo esplorato tutto lo spazio di ricerca.
- ## predicato ! cut
- Si chiama **"cut"** e diciamo che non è un vero e proprio predicato.
- Taglierà un ramo sulla ricerca. 
- ##### Es:
- dato un **predicato p** che è **vero** che a, b, c

        p :- a, ! , b , c
- Se l'esecuzione va avanti (da sinistra a destra) e supero la **"a"**, se ottengo un **fail** dopo un **cut** non posso piu tornare prima del !. 
- Non posso nemmeno riandare a ristanziare la regola P, sotto c'è l'esempio. 
- **Oss**: ricorda che durante l'esecuzione si formano tutti rami(lezione 2).
1) ##### Primo fatto
    - il primo fatto dice che se **"a"** fosse verificato vado avanti nei rami dell'esecuzione e non posso ritornare indietro prima del cut.
2) ##### Secondo fatto
    - il secondo fatto dice che non posso verificare di nuovo il predicato se abbiamo superato un **cut**. 
- ##### es 
        
        p:- a, !, b, c
        p:-d

- Se durante l'esecuzione supero il "!" non potrò arrivare su "d" come dicevamo sopra. 
- ### nl - new line
- Predicato sempre vero.
- Una sorta di "\n"
- ### write
- **write(a)** è una sorta di print e serve per "stampare".


        f(a).
        f(b).
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



- Per vedere se una cosa è falsa dobbiamo vedere tutto per notare se quella cosa non è mai stata scritta.
- ## Predicato not 
- E' **falso** se ce una cosa vera. 
- #### Idea:
- Facciamo un cut sul fail

        fallimento_di_g(A):-
            g(A),
            !,
            fail.

        fallimento_di_g(_).
- Se g(a) è vero fallisce(poichè significa che un quell'elemento c'è quindi dve etornare false), supero il cut e torna false perche non riesce a ritornare sorpa e vederificare altre variabili siccome abbiamo messo il **cut**.
    1) Perchè se supera il primo g(a) vuol dire che ha trovato almeno un elemento e con il fail cosi torna falso. 
    2) Se non trova nessun elemento va sul secondo "fallimento_di_g"  e torna true perchè non abbiamo trovato nessun elemento.

- #### Mynot, ovvero il not 
- **Negation as failure** 
- ##### Ricorda che:
    - ciò che è dentro è vero, tutto il resto è falso.

            mynot(Predicato):-
            Predicato, !, fail.

            mynot(_).

- ### Esercizio di contare elementi lista 


        numerodiEl([],_,0).
        numerodiEl([A|_],A,+1).
        numerodiEl([_|T], El, N):-
            numerodiEl(T,El,N).


        nEl([],_,0). % caso base
        nEl([El|T],El,M):- % primo caso in cui l'elemento è in testa
            !, % cosi non ritorno sopra
            nEl(T,El,N),
            M is N+1.
        nEl([X|T],El,M):-
            nEl(T,El,M). 
- Se verifico i primi due **nEl** non entrerò nel 3, pero se ci sono piu elementi si ferma sulla prima occorrenza.
- Cioè non arriveremmo a controllare altri valori di occorrenze ma con il "!" ci fermeremo alla prima variabile 
- Quindi il **cut** bisogna saperlo usare perche qui mi serviva vedere tutti gli elementi se facevo **nEl([1,2 , 2, 3], A, X)**





