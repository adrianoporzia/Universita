- # Lezione 5
- ## Rivoltare una lista
- ###### Es: 
        rivoltata([], []).
        rivoltata([H|T], RL):-
            concatenazione(RT,[H],RL), %sarebbe la nostra concatenazione, definita tra due liste per questo [H]
            rivoltata(T,RT).

- #### Es esecuzione:
- ##### Prova con rivoltata([a,b,c],[c,a,b])
  - **H** = a, **T** = [b,c], **RL** = [c,a,b]
  - **GOAL** = concatena(RT, a, [c,a,b]) --> da **false**, perche non termiina con la lettera **"a"**.
 
- ##### Prova con riv([a,b,c],[b,c,a])
  - **H** = a, **T** = [b,c], **RL** = [b,c,a]
  - **GOAL** = concatenazione(RT, a, [b,c,a]) --> da **true**, a questo punto bisogna vedere se **RT = bc**
  - **GOAL** = rivoltata([b,c],[b,c]) --> darà **false**

- ## Sottrazione elemento (remove)

        appartiene(X, [X|_]). 
        appartiene(X, [_|T]):-
            appartiene(X,T).

        substract(_, [], []).
        substract(H, [H|R], R). 
        substract(H, [A|R1], [A|R2]):-
            substract(H, R1, R2).

- #### Primo caso 
- Nel **primo caso** se sottraggo qualsiasi elemento dalla lista vuota ho una lista vuota.
- Se lo inseriamo **H** può non appartenere alla lista.
- Altrimenti **H** deve appartenere alla lista.
- #### Secondo caso
- Nel **secondo caso** se **H** è l'elemento in testa da cancellare ottengo la coda. 
- se l'elemento **H** da cancellare è nella coda allora sicuramente la testa di entrambe le liste è la stessa e devo sottrarre l'elemento H dalla lista R1 trovando la lista R2.
    
- ## Permutazione degli elementi nella lista
        permutazione([], []).
        permutazione([H|T], B):-
            permutazione(T, PT1_2),
            appartiene(H, B),
            substract(H,B,PT1_2).
- #### oss:
- Sostanzialmente con l'induzione arriviamo alla lista vuota, passo base e poi verifichiamo volta per volta se l'elemento appartiene alla testa mome ntanea e poi con substract lo rimuoviamo cosi possiamo verificare gli altri elementi.
    

