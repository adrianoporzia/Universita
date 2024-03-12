# Lezione 3 
- ## Rappresentazione dei grafi
- Raccontiamo il grafo, attraverso gli archi.
- #### ES:
        edge(b, c).
        edge(a, b).
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

        %passo base
        ciclo(X) :- 
            edge(X, Z),
            edge(Z, X).

        %passo induttivo
        ciclo(X) :- 
            edge(X, Z),
            path(Z, X).

- **Non è ricorsione ma Induzione**.
- ## Algoritmo di risoluzione.
- In un programma c'è la possibilità anche di avere un **GOAL** e generare un albero delle soluzioni.
- #### ES: 
        ? - edge(A, B)
               |
               |
               |
             A = a
             B = b
- Tutto si svolge dall'alto al basso e da destra verso sinistra. 
- Quando eseguiamo il path lui scorre da sopra e incontra prima edge e vede che è un **Fail** , poi incontra la funzione 'PATH' ed eseguirà risolvendo il **GOAL**.

        ? - path(a, d)
               |
               |
               | 
          X = a, Y = d
        ---------------
          edge(a, Z)
          path(Z, d)        nuovo goal
        ---------------
          Z = b             goal risolto
          edge(a, b)
          path(b, d)        nuovo goal 
        ---------------
              .
              .
              .
- Si crea un albero delle soluzioni e che termina con **VERO** o **FALSO**.
- Se fallisce con un valore con un **Fail** si riesegue e si risolve con un'altra lettera finchè non arriva alla fine.
- Il **GOAL** a sinistra è soddisfatto se tutti i **GOAL** a destra sono **soddisfatti**. Come nella Logica
 , difatti riprende il nome di pro-log.
- Il **GOAL** è un teorema da dimostrare sostanzialmente, dimostriamo al contrario tornando indietro attraverso il **Modus-Ponens** ("Se" e "Allora", un fatto è verificato allora quelli indietro sono verificati), e alla fine avremo un **TRUE** o **FALSE**.
