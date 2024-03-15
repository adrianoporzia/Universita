- #  Lezione 4 - 14/03/24
- ## Concetto di lista e struttura e induzione strutturale.
- **Lista** = struttura dati raccontata da parenti quadrate.
- ##### Es: 
        [a, b, c, d]
- ## Lista con modalità head and tail
- **[H | T]** = modalita di lista della forma testa-coda.
- Nella **coda** ci sono tutti gli elementi della lista, **esclusa** la testa.
- ### Esempi di applicazione.
- ##### ES 1:  
        [H | T] = [a, b, c, d, e] 
- E' un'unificazione dove: 
    1) **H = a**  
    2) **T = [b, c, d, e]**, T è una lista che contiene i restanti elementi. 
- ##### Es 2:

        [H | T] = [a]
- Dove:
    1) **H = a**;
    2) **T = [ ]**, ovvero lista vuota.

- ##### Es 3:  

        [H | T] = [] 

- Scrivendo ciò è come se dicessimo **"1 = 2"** ed è falso poichè 1 non è unificabile a 2, quindi nell'**esempio** 3 succede concettualmente la stessa cosa, e **ritornerà falso**.

- ## Predicati sulle liste 
-  **"predicato appartiene"** per verificare se un elemento appartiene a un insieme tipo una lista, se non ci sta torna falso.

        a ∈ A 
- #### Usiamo induzione strutturale 
        
        L = [H | T] 

               H         T
        L = [ ( ) | ----------]
- Se volessi **unificare** x a L (x ∈ L) ho due casi: 
    1) **x = H**
    2) **x ∈ T**

- ##### Es 4: 
        
        %caso 1
        appartiene(X, [X | _ ]).
        
        %caso 2
        appartiene(X, [ _ | T]) :-
            appartiene(X, T).  

- Utilizzando l'**underscore** mi permette di definire un valore che mi vorrei trovare, che non conosco, e con l'**esempio 4** ho due casi:
    1) **Caso 1** = verifico se **x** è **H**.
    2) **Caso 2** = verifico se X ∈ T, ovvero se è contenuto.

- #### Es 5:
- **Data la lista = [1, 2, 3]**.
- Se faccio specifiche domande ci sono varie casistiche.
- ##### Es 5.1:

        appartiene(X, [1, 2, 3]).
- Ciò che mi da è prima 1, poi se fai **next** ti da 2 e infine 3.
- ##### Es 5.2:

        H1, H2 | T] = [a, b, c]
- Dove:
    1) **H1 = a**
    2) **H2 = b**
    3) **T = [c]**

- ##### Es 5.3:
 
        [H1, H2, T] = [a, b, c]
- Dove:
    1) **H1 = a**
    2) **H2 = b**
    3) **T = c**, perche T è una lettera qualsiasi in questo caso e non viene considerata come Tail.

---------------------------------------------------------------
- ## Esercizio
- Sulle liste oltre ad **"appartiene"** c'è anche **concatena** (append) che è **vero** se:
1) **A** è una lista
2) **B** è una lista
3) **C** è una lista che ha come **proprietà**  la concatenzaione di **A** e **B**.
- #### Operiamo per induzione strutturale.
- Si può scrivere in due modi, uno più compatto e uno meno.
- **Caso 1**, meno compatto:
        
        concatena(A, B, C) :-
            A = [H | T],
            C = [H | L],
            concatenata(T, B, L)

- **Caso 2**, più compatto:
- Si può fare così perchè stiamo solamente attuando delle unificazioni su 

        %passo base
        concatena([], A, A).

        %passo induttivo
        concatena([H | T], B, [H | L]) :-
        concatena(T, B, L).







