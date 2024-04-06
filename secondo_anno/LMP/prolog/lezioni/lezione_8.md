- # Lezione 8
- ## Possibilità di cambiare il programma in RunTime.
- In prolog è possibile in RunTime definire regole, predicati e fatti.
- ## Assert(_):
  - fatti che vogliamo **"asserire"**, di default lo mette in coda.
- ### Assertz(_):
  - Come assert, mette il predicato in **coda**.
- ### Asserta(_):
  - Come assert, però mette il predicato in **testa**.
- ## Retract(_):
  - elimina fatti/predicati se esistono, il primo che unifica(incontra). 
- ## RetractAll(_):
  - elimina tutti i fatti/predicati che si unificano insieme, come se ho due predicati len, invece di levare solo il primo come in retract, li leva entrambi.
- ## Consult(_):
  - legge una determinata riga fino al punto ed esegue l'assert.
- ## :- dynamic(predicato/n), con n numero di argomenti:
  - dichiara che per un predicato può asserire o fare il retract, e viene usato per i predicati che sono gia scritti all'interno del programma.
  - ###### Es:
        
            :- dynamic(lun/2).
- ## Univ, =..
  - ##### Es:  
  
        =.. (univ) -> lun(0, 1) =.. [lun, 0, 1]
            A =.. [lun, 0, 1] 
  - Possiamo generare predicati e unificarli ad una variabile.

- ### Esercizio Funtore:
- **OSS**: predicato che ci torna il nome di un predicato
- ##### Es:
    - Funtore = nome di A
    - funtore(lun([], 0), X)

            funtore(A, Funtore) :-
            A =.. [Funtore|_].











    
