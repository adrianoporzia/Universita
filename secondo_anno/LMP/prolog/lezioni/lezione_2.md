- # Lezione 2
1) P.P. 
    - x := 2
    - x := x + 1
2) P.D. 
    - { x + y = 0
    - { x + 3y = 2
- in entrambe ci sono variabili.
- nella prima è un'assegnazione, come una cella di memoria
- **Programma prolog** = insieme di predicati.

- **Predicato** è descritto da un insieme:
   1) di fatti
   2) regole

- **Dimostrazione** = sequenza di passaggi fatti attraverso un meccanismo detta inferenza.
- ##### Es :
    - Modus Ponence.

- ##### Es :
    - X è fratello di Y se [Z genitore di X e Z genitore di Y], ovvero [genitore(Z, X), genitore(Z, Y)].
       - **vera** se Z è lo stesso
       - fratello(X, Y) --> **predicato** raccontato da **una** regola e fatti
- In prolog "e" --> "," e "se" --> ":-"
- Il per ogni X e Y è sottointeso
- #### Es codice:
            genitore(maria, dario).
            genitore(maria, gino).
            genitore(pino, rino).
            genitore(mario, pino).
            genitore(luca, pino)

            fratello(X, Y) :- 
                genitore(Z, X), 
                genitore(Z, Y).
                % fratello(dario, gino) - true

            nonno(X, Y) :- 
                genitore(X, Z),
                genitore(Z, Y).
                % nonno(mario, rino) - true
            
            % caso base induttivo e **non** ricorsivo
            avo(X, Y) :- 
                genitore(X, Y).

            avo(X, Y) :- 
                genitore(X,Z), 
                avo(Z, Y).
                % avo(luca, rino) - true
    
    - assegni nomi e se è verificata la proprietà ritorna vero
    - ##### oss:
        - per essere fratelli devono rispettare la regolare fratello(X, Y) con X dario e Y gino


- **Unificare:** come se in parentesi graffa assegno un valore a una variabile e nel sistema rimane per tutti

- ## Regole delle variabili
1) Stringa che inizia in maiuscolo variabile di cui voglia conoscere il valore
2) se minuscola e underscore non vogliamo conoscere il valore
3) se solo underscore quando non vogliamo unififcare parti di una regola, non si unificano.
4) parole che iniziano per minuscola es: a.... è una costante
5) tutte le cose che sono numeri, sono numeri
6) dentro apici ' ' diventa tutto costante, ci si può scrivere tutto
