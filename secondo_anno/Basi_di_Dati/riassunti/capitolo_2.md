# Capitolo 2 - Modello Relazionale
- Nasce nel 1970 per favorire l'indipendenza dei dati. Disponibile in DBMS reali pochi anni dopo e si basa sul concetto di **relazione e tabelle** .
  Le relazioni hanno naturale rappresentazione per mezzo delle tabelle. 
- Il modello relazionale risponde al requisito dell'indipendenza dei dati, e prevede una distinizone, nella descrizione dei dati, fra il livello fisico
  e il livello logico.

## 2.1.2 Relazioni e tabelle 
- **D1, ...., Dn:** insiemi anche non distinti sono detti **domini** della relazione. 
- #### Def prodotto cartesiano: 
            -> D1 X .... X Dn è definito come l'insieme di tutte le n-uple(d1, ..., dn) tali che d1 £ D1, ..., dn £ Dn 
- Una ** relazione matematica ** su D1, ..., Dn è un sottoinsieme di D1 X ... Dn.
- ### Es = 
        D1 = {A, B}       D2 = {X, Y, Z}
- Prodotto cartesiano: 

        D1 X D2 = {(A, X), (A, Y), (A, Z), (B, X), (B, Y), (B, Z)}
- Una relazione (casuale) potrebbe essere però: 

        r = D1 X D2 = {(A, X), (B, X), (B, Y)}

- ##### OSS: 
1) Nella **relazione matematica** le n-uple sono ordinate.
2) **La relazione** è un **insieme**, quindi:
   - **non c'è ordinamento** ;
   - le n-uple sono distinte; 
   - ciascuna n-upla è ordinata : l'i-esimo valore proviene dall'i-esimo dominio.

- ### Esesempio di relazione matematica: 

        Partite ⊆ string X string X int X int 

        |   ---    |  ---  |---|---|
        | Juventus | Lazio | 1 | 3 |
        | Lazio    | Milan | 2 | 0 |
        | Juventus | Roma  | 0 | 2 |
        | Roma     | Milan | 0 | 2 |
- Ciascuno dei domini ha due **ruoli** diversi, distinguibili attraverso la posizione, e la struttura è **posizionale**.
- E' posizionale poichè non ci sono attributi.

- ### Esempio di struttura non posizionale: 

        | Casa      | Ospite | Gol Casa | Gol Ospite |
        | ---       | ---    |    ---   |    ---     |
        | Juventus  | Lazio  |     1    |     3      |
        | Lazio     | Milan  |     2    |     0      |
        | Juventus  | Roma   |     2    |     0      |
        | Milan     | Roma   |     2    |     0      |
- Se a ciascun dominio si associa un nome ( **attributo** ), che ne descrive il 'ruolo', la struttura diviene non posizionale.
- ## Collezione di Funzioni
- Per catturare meglio il concetto di relazione del modello relazionale definiamo: 

        - X = {A1, ..., An}: un insieme ( **non ordinato** ) di attributi 
        - DOM = X --> D : funzione che associa ad un attributo il corrispondente dominio.
                -Una ennetulpa o tupla è una funzione _t_ che associa ad ogni A ∈ X un **valore del dominio** .
                - **t[A]** denota il valore della ennetupla _t_ sull'attributo _A_ .

- Una **relazione** è una collezione di **ennetuple**.
- ## Notazione del modello relazionale 
- Se t è una tupla su X e A è un attributo, con A ∈ X allora t [A] indica il valore di t su A.
- ### Es: se t è una prima tupla allora...
            
        t[Cognome] --> 'Pace'
        | Nome  | Cognome  | Matricola | Voto Medio |
        |  ---  |   ---    |    ---    |     ---    | 
        | Jack  | Pace     |     1     |     30     |
        | Luigi | Amato    |     2     |     18     |
        | Rosa  | Rossa    |     3     |     27     |

- ## Tabelle e relazioni 
- Una tabella rappresenta una relazione se:
 1) i valori di ogni colonna sono fra loro **omogenei** 
 2) le righe sono **diverse** fra loro 
 3) le **intestazioni** delle **colonne** sono diverse tra loro 

- In una **tabella** che rappresenta una **relazione**
 1) l'ordinamento tra le righe è irrilevante
 2) l'ordinamento tra le colonne è irrilevante 
- ##### OSS :
- Non ci sono mai due righe uguali e non ci sono dati omogenei.

- I riferimenti fra i dati in relazioni diverse sono rappresentati per mezzo di valori dei domini che compaiono nelle enneuple. Sostanzialmente tra 
  tabelle ci sono riferimenti ad altre tabelle in base ad attributi specifici.

- ## Vantaggi della struttura basata sui valori 
1) indipendenza dalle strutture fisiche(_si potrebbero avere anche con puntatori di alto livello_) che possono cambiare dinamiche;
2) si rappresenta solo ciò che è rilevante dal punto di vista dell'applicazione;
3) l'utente finale vede gli stessi dati dei programmatori;
4) i dati sono portabili più facilmente da un sistema all'altro;
5) i puntatori sono direzionali.

- ## Modello relazionale: Definizioni
- #### Schema di relazione: 
        Un nome ** R ** con un insieme di attributi ** A1, ..., An:
                 --> ** R(A1, ..., An)

        ES :
               STUDENTI(Matricola, Cognome, Nome, Data di Nascita) 

- #### Schema di base di dati: 
        insieme di schemi di relazione:
                --> ** R = {R1(X1), ..., Rk(Xk)}

        Es:
                STUDENTI(Matricola, Cognome, Nome, Data di nascita)
                ESAMI(Matricola, Voto, Corso)
                CORSO(Codice, Titolo, Docente)

- ## Strutture nidificate
- E' fondamentale non avere all'interno di strutture di dati due righe che siano uguali, come per esempio nelle ricevute(scontrini) non ci devono
  essere uguali.

- ## Informazioni incomplete
- #### Se ci dovessero essere tabelle che hanno voci mancanti Sostanzialmente.
- ** Non conviene ** (anche se spesso si fa) usare valori del dominio, come:
    - ##### 0, stringa, nulla, "99", ...;
    - potrebbero non esistere valori ** "non utilizzati" ** ;
    - valori ** "non utilizzati" ** potrebbero diventare significativi;
    - in fase di utilizzo (nei programmi) sarebbe necessario ogni volta tener conto del "significato" di questi valori.
- ### Valore nullo nel modello relazionale 
- Per le informazioni incomplete si adotta una tecnica rudimentale ma efficacie:
    - ** Valore nullo ** : denota l'assenza di un valore del dominio;
    - t[A], per ogni attributo A, è un valore ndel dominio ** dom(A) ** oppure il valore è ** NULL **;
    - si possono imporre restrizioni sulla presenza di valori nulli.
- #### Casi valore nullo:
    1) Valore ** sconosciuto ** .
    2) Valore ** inesistente ** .
    3) Valore ** senza informazione ** .
- ##### OSS :
- I DBMS non distinguono i tipi di valore nullo.
