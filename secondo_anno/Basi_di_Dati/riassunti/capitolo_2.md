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
- 
- ### Notazione del modello relazionale 
- Se t è una tupla su X e A è un attributo, con A ∈ X allora t [A] indica il valore di t su A.
- #### Es: se t è una prima tupla allora...
            
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
1) indipendenza dalle strutture fisiche( _si potrebbero avere anche con puntatori di alto livello_ ) che possono cambiare dinamiche;
2) si rappresenta solo ciò che è rilevante dal punto di vista dell'applicazione;
3) l'utente finale vede gli stessi dati dei programmatori;
4) i dati sono portabili più facilmente da un sistema all'altro;
5) i puntatori sono direzionali.

- ## Modello relazionale: Definizioni
- #### Schema di relazione: 
        Un nome **R** con un insieme di attributi A1, ..., An:
                 --> **R(A1, ..., An)**

        ES :
               STUDENTI(Matricola, Cognome, Nome, Data di Nascita) 

- #### Schema di base di dati: 
        insieme di schemi di relazione:
                --> **R = {R1(X1), ..., Rk(Xk)}** 

        Es:
                STUDENTI(Matricola, Cognome, Nome, Data di nascita)
                ESAMI(Matricola, Voto, Corso)
                CORSO(Codice, Titolo, Docente)

- ## Strutture nidificate
- E' fondamentale non avere all'interno di strutture di dati due righe che siano uguali, come per esempio nelle ricevute(scontrini) non ci devono
  essere uguali.

- ## Informazioni incomplete
- #### Se ci dovessero essere tabelle che hanno voci mancanti Sostanzialmente.
- **Non conviene** (anche se spesso si fa) usare valori del dominio, come:
    - ##### 0, stringa, nulla, "99", ...;
    - potrebbero non esistere valori **"non utilizzati"** ;
    - valori **"non utilizzati"** potrebbero diventare significativi;
    - in fase di utilizzo (nei programmi) sarebbe necessario ogni volta tener conto del "significato" di questi valori.
- ### Valore nullo nel modello relazionale 
- Per le informazioni incomplete si adotta una tecnica rudimentale ma efficacie:
    - **Valore nullo** : denota l'assenza di un valore del dominio;
    - t[A], per ogni attributo A, è un valore ndel dominio **dom(A)** oppure il valore è **NULL**;
    - si possono imporre restrizioni sulla presenza di valori nulli.
- #### Casi valore nullo:
    1) Valore **sconosciuto** .
    2) Valore **inesistente** .
    3) Valore **senza informazione** .
- ##### OSS :
- I DBMS non distinguono i tipi di valore nullo.

- ## 2.2 Vincoli d'integrita
- Esistono istanze di basi di dati che, pur sintatticamente corrette, non rappresentano informazioni possibili per l'applicazione. Come per esempio 
  due utenti con stessa matricola o se si considera il campo "Voto" e c'è magari 27 e lode.
- Proprietà che deve essere soddisfatta dalle istanze che rappresentano informazioni corrette per l'applicazione.
- ##### Un vincolo è una funzione booleana(un **predicato** basato sulla logica del primo ordine) che associa ad ogni istanza il valore VERO o FALSO.
- Consentono una descrizione più accurata della realtà e vengono usati dai DBMS nella esecuzione delle interrogazioni.
- 
- ### Tipologie di Vincoli 
1) Vincoli **intrarelazionali**:
   - vincoli su valori (o di dominio);
   - vincoli di enneupla.
2) Vincoli **interrelazionali** .

- ##### 1.2 Vincoli di enneupla
- Esprimono condizioni sui valori di ciascuna enneupla, indipendentemente dalle altre enneuple. Caso particolare è quando ci sono **vincoli di dominio** 
  che coinvolgono solo un attributo. Come per esempio:

        -Espressioni booleane del tipo:
            (Voto >= 18) AND (Voto <= 30)
            (Voto = 30) OR NOT (Lode = "e lode")
- Ma anche in casi in cui ho tabelle del tipo:

            Stipendi --> | Impiegato | Lordo       |  Ritenute   | Netto       |
                         |    ---    |     ---     |    ---      |     ---     |
                         | Rossi     | 55.000,00 £ | 12.500,00 £ | 42.500,00 £ | 

            Lordo = (Ritenute + Netto) 
- ## 2.2 Chiavi
- Non ci sono due enneuple con lo stesso valore sull'attributo **Matricola** . Non ci sono due enneuple uguali su tutti e tre gli atteibuti **Cognome,  
  Nome e Voto medio** .

         | Nome  | Cognome  | Matricola | Voto Medio |
         |  ---  |   ---    |    ---    |     ---    | 
         | Jack  | Pace     |     1     |     30     |
         | Luigi | Amato    |     2     |     18     |
         | Rosa  | Rossa    |     3     |     27     |
- ### Definizione chiave:
  - Insieme di attributi che identificano univocamente le enneuple di una relazione. 
  - 
- **Formalmente** :
  - un insieme **K** di attributi è superchiave per "r" se "r" non contiene due enneuple distinte **t1** e **t2** con **t1[K] = t2[K]**
  - **K** è una **chiave** per "r" se è una superchiave minimale per "r"(ossia, non contiene un'altra superchiave).
  - Nell'esempio sopra la Matricola è una chiave poichè è una **superchiave** e contiene un solo attributo e quindi è minimale. Ma anche Cognome, Voto 
    medio e Nome è un'altra chiave, superchiave ed è minimale.
- ### Vincoli, schemi e istanze 
- I vincoli corrispondono a proprietà del mondo reale modellato dalla base di dati. Interessano a livello di schema, ovvero a tutte le istanze, e ad 
  uno schema associamo un insieme di vincoli e consideriamo **corrette** (valide, ammissibili) le istanze che soddisfano tutti i vincoli. **OSS =** 
  un'istanza può soddisfare altri vincoli ("per caso").
- #### ES:
        Studenti 
        | Matricola | Cognome | Nome | Corso | Nascita |
        
        --> Chiavi:
            1) Matricola;
            2) Cognome, Nome, Nascita.
- L'esempio è **corretto** perchè soddisfa i vincoli, ma ne soddisfa anche altri (" **per caso** ");
  - Cognome, Corso è chiave;
- Una relazione non può contenere **enneuple distinte** ma **uguali** ; ogni relazione ha come **superchiave** l'insieme degli attributi su cui è definita.

- ## Differenza tra superchiave e chiave in un database:
- Immagina un database come un grande archivio di informazioni, organizzato in tabelle simili a fogli di calcolo. Ogni riga della tabella, chiamata tupla, 
 rappresenta un'entità specifica (ad esempio, un cliente, un prodotto o un ordine).

- ### Superchiave:
  - È un insieme di attributi (colonne) che identifica univocamente ogni tupla nella tabella.
   - In parole povere, se guardiamo due tuple con la stessa "superchiave", sappiamo che sono la stessa entità.
   - Pensa alla superchiave come a un'impronta digitale: ogni tupla ha la sua impronta unica.

- ##### Esempio:
 - Consideriamo una tabella Studenti con i seguenti attributi:

        - ID (numero intero)
        - Nome (stringa)
        - Cognome (stringa)

- In questo caso, sia {ID} che {Nome, Cognome} sono superchiavi:

        - Non ci sono due studenti con lo stesso ID.
        - Non ci sono due studenti con lo stesso nome e cognome.

- ### Chiave:
- È una superchiave "speciale" che soddisfa due proprietà:
  1) **Minimalità** : Non è possibile rimuovere alcun attributo dalla chiave senza perdere l'unicità.
  2) **Non ridondanza** : Non ci sono attributi che dipendono da altri attributi nella chiave.

- In parole povere:
  1) La chiave è la superchiave più piccola e "semplice" possibile.
  2) La chiave non contiene informazioni ridondanti.

- ##### Esempio:
        Nel nostro caso, {ID} è una chiave, mentre {Nome, Cognome} non lo è:

        - {ID} è minimale: se togliamo l'ID, non possiamo più identificare univocamente gli studenti.
        - {Nome, Cognome} non è minimale: possiamo ricavare il cognome dal nome e viceversa, quindi è ridondante.

- Perché la chiave è importante?
 1) La chiave primaria (una chiave specifica) è usata per identificare univocamente ogni tupla nella tabella.
 2) La chiave primaria è usata per collegare le tabelle tra loro.
 3) La chiave primaria deve essere univoca e non ridondante per garantire l'integrità dei dati.

- Riassumendo:
  - Una superchiave identifica univocamente le tuple.
  - Una chiave è una superchiave minimale e non ridondante.
  - Ogni tabella deve avere almeno una chiave primaria.
- ##### Analogia:

        Immagina una biblioteca con libri identificati da un numero ISBN (codice a barre) e da un titolo.

        - L'ISBN è una superchiave: ogni libro ha un ISBN univoco.
        - Il titolo non è una superchiave: potrebbero esserci libri con lo stesso titolo.
        - L'ISBN e il titolo insieme sono una superchiave: non ci sono due libri con lo stesso ISBN e lo stesso titolo.
        - L'ISBN è una chiave: è minimale e non ridondante.


- ## 2.2.3 Chiavi e valori nulli
- In presenza di **valori nulli** , i valori della chiave non permettono:
   1) di identificare le enneuple; 
   2) di realizzare facilmente i riferimenti da altre relazioni;
   3) la presenza di valori nulli nelle chiavi deve essere limitata.

- La **chiave primaria** è una chiave su cui non sono **ammessi nulli** .
- ## Integrità referenziale.
- Informazioni in relazioni diverse sono correllate attraverso valori comuni, correlazioni coerenti.
- Un vincolo di integrità referenziale **(“foreign key”)** fra gli attributi X di una relazione R1 e un’altra relazione R2 impone ai valori su X in
  R1 di comparire come valori della chiave primaria di R. Gestiscono situazioni scomode, come se **per esempio** :
  - viene eliminata una enneupla causando così una violazione. Azioni = 
     1) Rifiuto dell'operazione.
     2) Eliminazione in cascata.
     3) Introduzione di valori nulli.
