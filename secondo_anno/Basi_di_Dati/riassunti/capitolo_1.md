#                                                     CAPITOLO 1 - INTRODUZIONE
- Nello svolgimento di un'attività sono essenziali la disponibilità di informazioni e la capacità di gestirli in modo efficace; ogni 
organizzazione è dotata di un 'Sistema Informativo', che organizza e gestisce le informazioni necessarie per perseguire gli scopi 
dell'organizzazione stessa. L'esistenza di un sistema informativo sono è in parte indipendente dalla sua ottimizzazione. Per indicare 
la porzione automatizzata del sistema informativo viene di solito utilizzato il termine 'sistema informatico'. Con lo sviluppo 
dell'informatica gran parte dei sistemi informativi stanno diventando anche sistemi informatici. 
Nei sistemi informatici per ragioni tecnologiche e di semplicità il concetto di codifica viene portato all'estremo e le 
informazioni vengono rappresentate per mezzo di 'dati', che hanno bisogno di essere interpretati per fornire informazioni.
- In breve il dato da solo non ha grande significato, ma, una volta interpretati d correlati opportunamente, essi forniscono 
informazioni, che consentono di arricchire la nostra conoscenza del mondo.

### Differenza tra dato e infomazione:
1) **Dato** = ciò che è immediatatmente presente alla conoscenza, pruma di ogni elaborazione; (in informatica) sono elementi di 
          informazione costituiti da simboli che devono essere elaborati.
2) **Informazione** = notizia, dato o elemento che consente di avere conoscenza più o meno esatta di fatti.
- #### Per esempio:
    la stringa 'Ferrari' e il numero 8, scritti su un foglio di carta sono solo due dati e da soli non hanno significato.
    Se pero il foglio è relativo alle ordinazioni presso il ristorante di un albergo si può dedurre che è stata ordinata una bottiglia di 
    Ferrari per la stanza numero 8.

- **Base di dati** : è una collezione di dati, utilizzati per rappresentare le informazioni di interesse per un sistema informativo.
                 Le basi di dati sono state concepite in buona misura per superare alcuni inconvenienti, come la duplicazione di 
                 dati che può portare a duplicazioni anche errate, gestendo in modo integrato e flessibile le informazioni di 
                 interesse per diversi soggetti, liitando rischi di ridonandanza e incoerenza.
- **DBMS** : un sistema di gestione di basi di dati, database management dystem, è un sistema software in grado di gestire collezioni
          di dati che siano grandi, condivise e persistenti, assicurando la loro affidabilità e privatezza. Il DBMS deve essere 
          efficiente ed efficace. Una base di dati è una collezione di dati gestita da un DBMS. 
- ###### Caratteristiche DBMS e basi di dati:
1) Le basi di dati sono grandi nel snso che possono avere anche dimensioni enormi e comunque in generale molto maggiori della 
   memoria centrale disponibile. Le basi di dati hanno dimensioni di centinaia o migliaia di tarbyte e contengono miliardi di 
   record. Di conseguenza i DBMS devono prevdere una gestione di questi dati. 
2) Le basi di dati sono condivise, nel senso che più utenti devono poter accedere, secondo opportune modalità a dati comuni. Così
   si riducono le ridondanze dei dati, poichè si evitano ripetizioni e conseguentemente si riduce anche la possibilità di 
   inconsistenze. Per garantire l'accesso condiviso ai dati da parte di molti utenti che operano contemporaneamente, il DBMS 
   dispone di un meccanismo apposito, detto controllo di concorrenza.
3) Le basi di dati sono persistenti, cioè hanno un tempo di vita che non è limitato a quello delle singole esecuzioni dei 
   programmi che le utilizzano. OSS = i dati gestti da un programma in memoria centrale hanno una vita che inizia e termina con 
   l'esecuzione del programma; tali dati, quindi, non sono persistenti. 
4) I DBMS garantiscono l'affidabilità, cioè la capacità del sistema di conservare intatto il contenuto della base dati o almeno 
   di permettere la ricostruzione in caso di malfunzionamenti hardware o software. I DBMS spesso gestiscono dati replicati su 
   dispositivi fisici anche a distanza per garantire affidabiità.
5) I DBMS garantiscono privatezza, perchè gli utenti opportunamente riconosciuti vengono abilitati solo a svolgere determinate 
   azioni sui dati attraverso meccanismi di autorizzazione.
6) I DBMS sono efficienti, cioè capaci di svolgere operazioni utilizzando un insieme di risorse(tempo e spazio) che sia accettabile
   per gli utenti. Questa caratteristica dipende dalle tecniche di implementazione del DBMS.
7) I DBMS sono efficaci in quanto sono capaci di rendere produttive, in ogni senso, le attività dei loro utenti.
Il dato è un mezzo per memorizzare i dati, meno sofisticati dei DBMS, che gestiscono localmente i dati. I DBMS sono stati concepiti
e realizzati per estendere le funzionalità di file system, fornendo la possibilità di accesso condiviso agli stessi dati da parte di
piu utenti e applicazioni. Osserva che i DBMS a loro volta utilizzano file per memorizzare dati; i file del DBMS ammettono pero organizzazioni dei dati più sofisticate.
## 1.3 Modelli di Dati 
- Un modello dei dati è un insieme di concetti utilizzati per organizzare i dati di interesse e descriverne la struttura in modo che 
essa risulti comprendibile a un'elaborazione. Ogni modello di dati fornisce meccanismi di strutturazione, analoghi ai costrutti 
di tipo dei linguaggi di programmazione che permettono di definire nuovi tipi di dato. Pese esempio il C che permette di costruire
tipi per mezzo dei costrutti struct, union etc..
- Il modello relazionale ei dati, attualmente il più diffuso, permette di definire tipi per mezzo del costruttore relazione, che 
consente di  organizzare i dati in insiemi di record a struttura fissa. Una relazione viene spesso rappresentata per mezzo di una 
tabella, le cui righe rappresentano specifici record e le cui colonne corrispondono ai campi dei record; l'ordine delle righe e 
delle colonne è sostanzialmente irrilevante. Per esempio, i dati relativi ai corsi universitari e ai loro docenti e all'inserimento
dei corsi nel manifesto degli studi dei vari corsi di laurea possono essere organizzati per mezzo di due relazioni, DOCENZA e 
MANIFESTO, rappresentabili con tabelle.
- Il modello relazionale è il più diffuso e viene utilizzato in questo libro come riferimento. Oltre a questo modello ne esistono 
altri 4:
1) Modello Gerarchico, basato sull'uso di strutture ad albero, definito durante la prima fase di sviluppo dei DBMS. Si usa ancora.
2) Modello reticolare, o modello CODASYL, basato sull'uso di grafi, sviluppato successivamente ad (A).
3) Modello a oggetti, sviluppato nel 80' come evoluzione del modello relazionale, che estende alle basi di dati il paradigma di 
   programmazione ad oggetti. 
4) Modelli semistrutturati e flessibili, sviluppati nel contesto dei cosidetti sistemi NOSQL, che cercano di superare alcune delle 
   limitazioni dei sistemi relazionali, in prestazioni e organizzazione.
- Questi modelli disponibili su DBMS vengono detti 'logici' per sottolineare che nonostante siano astratti riflettano una particolare
organizzazione. Più recentemente sono stati introdotti i modelli di dati 'concettuali', utilizzati per descrivere i dati in maniera
completamente indipendente dalla scekta del modello logico. Si chiamano cosi perchè tendono a descrivere concetti del mondo reale 
per la gestione delle basi di dati, per analizzare nel modo migliore la realtà di interesse senza 'contaminazioni' di tipo realizza-tivo. 
## 1.3.1 Schemi e istanze
Lo schema serve per gestire le caratteristiche dei dati.
- **Colonne**
Lo schema di una relazione è costituito dalla sua intestazione, cioè dal nome della relazione seguito dai nomi dei suoi attributi
che sono le colonne delle tabelle. ES = DOCENZA(Corso, NomeDocente).
- **Righe** 
Variano nel tempo, e corrispondono ai corsi attualmenteofferti relativi ai docenti. Durante la vita della base di dati, docenti e 
corsi vengono aggiunti, tolti o modificati.
- #### ES =  
      Basi di dati   Rossi
      Reti           Neri 
      Linguaggi      Verdi
- Le tre righe fanno chiaramente riferimento allo schema e solo attraversi du esso possono essere interpretate. Si dice anche che lo 
schema è la componente intensionale della base di dati e l'stanza la componente estenzionale.

## 1.3.2 Livelli di astrazione del DBMS 
La nozione di modello e di schema descritta in precedenza può essere ulteriormente sviluppata tenendo presenti altre dimensioni 
nella descrizione dei dati. L'architettura del DBMS standardizzata è articolata su 3 livelli:
1) Lo schema logico costituise una descrizione dell'intera base di dati per mezzo del modello logico adattato dal DBMS(es quello
relazionale o ad oggetti citati prima).
2) Lo schema interno costituisce la rappresentazione dello schema logico per mezzo di strutture fisiche di memorizzazione. Come 
per esempio per mezzo di un file sequenziale o di un file hash.
3) Lo schema esterno costituisce la descrizione di una porzione della base di dati di interesse, per mezzo del modello logico. 
Nei sistemi più moderni il livello esterno non è esplicitamente presente, ma è possibile definire relazioni derivate. 

## 1.3.3 Indipendenza dei dati 
L'architettura a livello così definita garantusce l'indipendenza dei dati, la principale proprietà dei DBMS. L'indipendenza dei 
dati può essere fisica o logica:
1) **Fisica** , consente di interagire con il DBMS in modo indipendente dalla struttura fisica dei dati.
2) **Logica** , consente di interagire con il livello esterno della base di dati in modo indipendente dal livello logico.
##### OSS = 
    gli accessi alla base di dati avvengono solo attraverso il livello esterno(che puo coincidere con quello logico); è il DBMS 
    che traduce le operazioni in termini dei livelli sottostanti. Architettura a livelli è fondamentale per l'indipendenza dei dati 
    nel DBMS.

## 1.4 Linguaggi e utenti delle basi di dati 
I DBMS sono caratterizzati da un lato dalla presenza di molteplici linguaggi per la gestione dei dati, dall'altro dalla presenza di 
molteplici tipologie di utenti.
## 1.4.1 Lingusggi per basi di dati 
Su un DBMS è possibile specificare operazioni di vario tipo, in particolare quelle relative a schemi e istanze. Esistono due 
categorie di linguaggi:
1) Linguaggi di definizione dei dati o Data Definition Language(DDL), utilizzati per definire gli schemi logici, esterni e fisici 
   e le autorizzazioni per l'accesso;
2) Linguaggi di manipolazione dei dati o Data Manipulation Language(DML), utilizzati per l'interrogazione e l'aggiornamente delle 
   istanzee di basi di dati.
#### ES = 
SQL comprende funzionalità di entrambe le categorie.
L'accesso ai dati può essere effettuato con varie modalità: 
1) tramite linguaggi testuali interattivi, come SQL, nelle varie versioni; per esempio attraverso SQL si possono definire strutture
   come quella di DOCENZA, sottoponendo a un interprete SQL(disponibile in tutti i DBMS, appartiene al DDL l'istruzione);
   Es = create table Dpcenza(
          Corso        character(20),
          NomeDocente  character(30)
   )
   C'è anche la possibilità di fare altre operazioni come select ... from ... where ... e cosi via.
2) tramite comadi simili a quelli dei linguaggi di programmazione etc..
## 1.4.2 Utenti e proggettisti
Varie categorie di persone possono interagire con una base di dati o con un DBMS.
1) L'amministratore(DBA) della base di dati è la persona responsabile della proggettazione, controllo e amministrazione della base 
   di dati. 
2) Proggettisti e programmatori di applicazioni, definiscono e realizzano i programmi che accedono alla base di dati. Essi 
   utilizzano il linguaggio di manipolazione dei dati (DML) oppure i vari strumenti di supporto alla generazione di interfacce verso   la base di dati. 
3) Utenti, utiizzano la base di dati per le proprie attività.
    -utenti finali, che utilizzano transazioni, cioè programmi che realizzano attività predefinite e di frequenza elevate, con 
                    poche eccezioni.
    -utentu casuali.

## 1.5 Vantaggi e svantaggi DBMS 
- ### Vantaggi:
1) I DBMS permettono di considerare i dati come una risorsa comune di una organizzazione, a disposizione di tutte le sue componenti.
2) La base di dati fornisce un modello unificiato e preciso della parte del mondo reale di interesse perl'organizzazione.
3) Con l'uso di un DBMS è possibile un controllo centralizzato dei dati, che può essere arricchito da forme di standardizzazione
   e beneficiare di 'economie di scala'.
4) La condivisione permette di ridurre ridondanze e inconsistenze.
5) L'indipendenza dei dati, fondamentale nei DBMS, favorisce lo sviluppo di applicazioni più flessibili e facilmente modificabili.

- ### Svantaggi:
1) I DBMS sono prodotti spesso costosi, complessi e abbastanza diversi da molti altri strumenti informatici. La loro introduzione 
comporta notevoli investimenti, diretti(acquisti prodotto) e indiretti(acquisizione risorse hardware o formazione del personale).
2) I DBMS forniscono una serie di servizi che sono necessariamente associati a un costo. 