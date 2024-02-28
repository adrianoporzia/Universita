# Capitolo 2 - Modello Relazionale
- Nasce nel 1970 per favorire l'indipendenza dei dati. Disponibile in DBMS reali pochi anni dopo e si basa sul concetto di ** relazione e tabelle **.
  Le relazioni hanno naturale rappresentazione per mezzo delle tabelle. 
- Il modello relazionale risponde al requisito dell'indipendenza dei dati, e prevede una distinizone, nella descrizione dei dati, fra il livello fisico
  e il livello logico.

## 2.1.2 Relazioni e tabelle 
- ** D1, ...., Dn: ** insiemi anche non distinti sono detti ** domini ** della relazione. 
- #### Def prodotto cartesiano: 
            -> D1 X .... X Dn è definito come l'insieme di tutte le n-uple(d1, ..., dn) tali che d1 £ D1, ..., dn £ Dn 
- Una ** relazione matematica ** su D1, ..., Dn è un sottoinsieme di D1 X ... Dn.
- ### Es = 
        D1 = {A, B}       D2 = {X, Y, Z}
- Prodotto cartesiano: 

        D1 X D2 = {(A, X), (A, Y), (A, Z), (B, X), (B, Y), (B, Z)}
- Una relazione (casuale) potrebbe es###sere però: 

        r = D1 X D2 = {(A, X), (B, X), (B, Y)}

- ##### OSS: 
1) Nella ** relazione matematica ** le n-uple sono ordinate.
2) ** La relazione ** è un ** insieme **, quindi:
   - ** non c'è ordinamento**;
   - le n-uple sono distinte; 
   - ciascuna n-upla è ordinata : l'i-esimo valore proviene dall'i-esimo dominio.

- ### Esesempio di relazione matematica: 

        Partite ⊆ string X string X int X int 

        |---|---|---|--- |
        | Juventus | Lazio | 1 | 3 |
        | Lazio | Milan | 2 | 0 |
        | Juventus | Roma | 0 | 2 |
        | Roma | Milan | 0 | 2 |
- Ciascuno dei domini ha due ** ruoli ** diversi, distinguibili attraverso la posizione, e la struttura è ** posizionale **.
- E' posizionale poichè non ci sono attributi.

- ### Esempio di struttura non posizionale: 

        | Casa | Ospite | Gol Casa | Gol Ospite |
        | --- | --- | --- | --- |
        | Juventus | Lazio | 1 | 3 |
        | Lazio | Milan | 2 | 0 |
        | Juventus | Roma | 2 | 0 |
        | Milan | Roma | 2 | 0 |
- Se a ciascun dominio si associa un nome (** attributo **), che ne descrive il 'ruolo', la struttura diviene non posizionale.
- ## Collezione di Funzioni
- Per catturare meglio il concetto di relazione del modello relazionale definiamo: 

        - X = {A1, ..., An}: un insieme (**non ordinato**) di attributi 
        - DOM = X --> D : funzione che associa ad un attributo il corrispondente dominio.
                -Una ennetulpa o tupla è una funzione _t_ che associa ad ogni A ∈ X un ** valore del dominio **.
                - ** t[A] ** denota il valore della ennetupla _t_ sull'attributo _A_ .

- Una ** relazione ** è una collezione di ** ennetuple **.



