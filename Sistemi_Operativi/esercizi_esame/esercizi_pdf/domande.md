## Domanda 1.
Il candidato discuta l’importanza dello scheduling nei sistemi batch, con particolare attenzione ai parametri
che si cercano di ottimizzare in questi sistemi. Si chiede di presentare e descrivere almeno tre metodi di
scheduling differenti applicati nei sistemi batch, specificando

- quali aspetti di performance ciascuno di essi mira a migliorare
- gli eventuali limiti.

## Risposta

Esistono vari tipi di ambienti relativi allo scheduling. Uno di questi è lo scheduling dei sistemi batch che ha come obiettivi:

1. Massimizzare il troghtput, ovvero il numero di job eseguiti in un tempo fissato;
2. Minimizzare il tempo di tornaraund, ovvero il tempo da quando inizia l'esecuzione a quando termina un determinato job;
3. Mantenere la CPU sempre attiva in modo tale che non ci siano inefficienze;

Bisogna sottolineare la differenza generica tra due tipi di approcci, ovvero:

- Senza prelazione, in cui lo scheduler manda in esecuzione i processi e rimaranno all'interno della CPU finchè non avranno
completato i loro compiti senza che nessuno possa fermarli prima.
- Con prelazione, in cui lo scheduler assegna un quanto di tempo di CPU ai processi in cui potranno svolgere compiti nella CPU,
quando il loro quanto termina lo scheduler li ferma e ne manda in esecuzione un altro anche se il processo non ha terminato.

Per quanto riguarda i sistemi batch esistono 3 tipi di algoritmi di scheuduling, tra cui:

- First-come First-served(FCFS) = attraverso questo algoritmo lo scheduler manda in esecuzione i processi nell'ordine in cui arrivano,
ovvero il primo che sarà disponibile verrà mandato in esecuzione finchè non avrà terminato tutti i suoi compiti, poichè questo
è un algoritmo di scheduling senza prelazione. Ha dei vantaggi e degli svantaggi tra cui:

    - Vantaggi = semplice da implementare e da gestire;
    - Svantaggi = potrebbero essere mandati in esecuzione processi molto lunghi e processi che hanno una esecuzione più rapida
dovrebbero aspettare tanto. Per esempio se viene mandato in esecuzione un processo CPU-bound(processi con burst di CPU lunghi 
e i/o infrequenti) e la sua esecuzione è per ipotesi di 10 secondi e successivamente tutti processi i/o-bound(processi con 
burst di CPU brevi e i/o frequenti) che magari ci mettono 1 secondo ad essere eseguiti ci sarebbero delle inefficienze poichè
dovreanno aspettare la lunga esecuzione del processo CPU-bound;

- Shortes Job First = lo SJF è un algoritmo di scheduling che sostanzialmente manda in esecuzione i processi più brevi in esecuzione
nella CPU conoscendo in anticipo i tempi di esecuzione di tutti i processi. E' un algoritmo che è non preemtive. Ha anche lui 
dei vantaggi e degli svantaggi:

    - Vantaggi = Minimizza il tempo di tornaraund poichè se io avessi per esempio 4 processi con i rispetivi tempi di esecuzione 8, 4,
    4, 4 secondi e utilizzo il FCFS avrò una media di esecuzione più alta rispetto allo SJB poichè manderebbe in esecuzione i processi
    rispettivamente nell'ordine 4, 4, 4 e 8 abbassando la media.
    - Svantaggi = sta proprio nel conoscere i tempi di esecuzione, poichè non sempre è possibile conoscere i tempi di esecuzione 
    in anticipo e quindi è molto limitatnte come cosa.

- Shortest remaining time next = è esattamente un SJB ma con prelazione. Manda in esecuzione i processi che hanno tempo rimanente di 
esecuzione minore. Avviene uno scheduling dinamico poichè se viene mandato in esecuzione un processo da 7 secondi e arriva a 4 secondi,
ma arriva un processo che ha una durata di 3 secondi il processo di 4 secondi attualmente nella CPU viene fermato e si fa 
entrare quello da 3 secondi. Ha una gestino più complessa dei primi due però permette una gestione dinamica ed efficiente dei vari
processi.

---------------------------------------------------------------------------------------------------------------------------------------------

2. Il candidato spieghi il concetto di memoria virtuale e il suo ruolo nella gestione della memoria RAM da parte
di un sistema operativo moderno. Si discuta come la memoria virtuale permetta di gestire programmi che su-
perano la capacità della memoria fisica disponibile. Si descrivano inoltre le tecniche di paging e segmentazione,
evidenziando come queste tecniche abbiano migliorato l’efficienza e la gestione della memoria nei computer.

--> La memoria virtuale è la gestione della memoria RAM e avviene referenziando uno spazio di indirizzi(virtuali) per ogni processo che
    a sua volta sono suddivisi in pagine di dimensione fisse all'interno della quale i processi possono salvare informazioni. Le pagine sono
    delle aree di memoria e avviene una sorta di gestione come un libro ad anelli da parte della CPU che assegna pagine ai processi per
    salvare informazioni.

    A) La paginaione è una tecnica utilizzata su quasi tutti i computer moderni che permette, come già detto sopra, di suddividere lo spazio
    di indirizzi di un processo in pagine. Gli indirizzi virtuali possono essere gestiti attraverso varie operazioni, come per esempio
    l'indicizzazione. Ci sono due tipi di gestioni di questi inidirizzi virtuali:
        -Senza memoria virtuale = la CPU attraverso il bus arriva alla locazione di memoria del frame fisico.
        -Con memoria virtuale = la CPU utilizza gli indirizzi virtuali e attraverso la MMU(che si trova nel pacchetto della CPU), 
        che permette di convertire l'indirizzo virtuale in fisico. 
    La paginazione viene attuata attraverso l'MMU. L'MMU come già preannunciato converte gli indirizzi virtuali in fisici. Funziona
    in modo molto efficiente, per esempio se abbiamo una macchina a 16 bit e pagine da 4KB saranno necessari 12 bit per codificare
    4096 byte(ovvero 4 KB) e il resto dei bit sono il numero di pagine presenti nella tabella delle pagine presenti nella MMU, ovvero
    le pagine assegnate a ogni singolo processo, in questo caso sono 2^4, ovvero 16 pagine per processo. L'offset invece permette
    di spostarci all'interno della pagina specificata dai primi bit. Per esempio con l'indirizzo 0010 000000100100 stiamo considerando
    la seconda voce della tabelle delle ppagine alla locazione 000000100100. Questa gestione è molto efficiente poichè da l'illusione
    al processo di avere uno spazio di memoria contiguo dove salvare le informazioni e soprattutto anche attraverso la memoria virtuale
    il processo ha l'illusione di avere una memoria disponibile molto ampia. All'interno della MMU c'è la tabella delle pagine che
    permette la gestione delle pagine, poichè la tabella delle pagine contiene: 
        1- Il numero del frame fisico che si sostituisce a quello virtuale quando bisogna salvare informazioni sulla memoria attraverso
        il bus;
        2- Il bit presente/assente per capire se quella determinata pagina è in memoria, se il bit è settato a 0 significa che quella
        pagina non è in memoria e quindi avviene un pagefault. L'MMu quando vede che manca una determinata pagina in memoria genera una
        trap dalla CPU al Sistema operativo.
        3- Il bit Supervisor che serve per specificaere chi può accedere a quella determinata pagina, per esempio se sono il sistema
        oppure anche gli utenti.
        4- Il bit di protezione per verificare i bit r-w-x relativi a lettura, scrittura ed esecuzione.
        5- I bit R e M rispettivamente di referenziato(per vedere se sono avvenuti riferimenti alla pagina) e di modificato(per vedere
        se la pagina è stata modificata).

    Quando una determinata pagina non è in memoria e il SO se ne accorge attraverso un algoritmo di sostituzione delle pagine va a 
    caricare quella determinata pagina in memoria.
    Ricapitolando la paginazione è un'ottima tecnica per gestire la memoria di un computer e soprattutto, va gestita in modo efficiente
    nel caso in cui ci siano computer con tanta memoria o comunque architetture a 64 bit.

    B) La segmentazione invece è una tecnica che si utilizzava molto di più nel passato. Il concetto dietro la segmentazione è quello
    di non avere uno spazio di indirizzi unico ma di avere un segmento che può crescere e diminuire dinamicamente per ogni specifica 
    istruzione, poichè se per esempio in un indirizzo unico avevamo la tabella dei simboli che aumentava la sua dimensione poteva magari
    invadere aree di altre istruzioni e per far fronte a ciò si utilizzò la segmentazione. Ogni segmento cresceva e diminuiva in modo dinamico
    senza rischi di memoria. I vantaggi della segmentazione erano 3:
        1- Maggiore flessibilità, poichè i segmente potevano gestire la dimensione in modo dinamico. Quindi in fase di compilazione
        le varie istruzioni non andavano in aree di memoria sbagliate.
        2- Linking migliore poichè ogni segmento era specifico di una istruzione bastava solamente trovare il segmento giusto senza lunghe
        ricerche nello spazio degli indirizzi. E inoltre se avvenivano modifiche era necessario aggiornare solo il singolo segmento.
        3- Sicurezza, poichè ogni segmento era indipendente e quindi avevano una gestione più sicura e specifica ma soprattutto non
        vi era la necessità di riallocare istruzioni poichè tutte separate.
    Per prelevare informazioni da un segmento era necessario specificare il numero del segmento e l'indirizzo all'interno del singolo segmento.

---------------------------------------------------------------------------------------------------------------------------------------------------
3. Discutere dell’importanza dei file, delle tipologie di file e della loro implementazione.

--> I file sono l'astrazione fondamentale di un computer poichè permettono di salvare informazioni sul disco. In Unix si dice che tutto 
    è un file (everything is a file). I file nascondono i dettagli tecnici all'utente. Intanto per quanto riguarda la nomenclatura ci sono
    sui vari sistemi caratteri speciali che non si possono utilizzare quando si assegna un nome al file e solitamente hanno una lunghezza
    di 255 caratteri(ad oggi). 
    Importanti sono le estenzioni per quanto riguarda i nomi dei file perchè permettono l'identificazione della tipologia del file, 
    come per esempio '.txt'. In alcuni sistemi come Unix sono convenzionali le estensioni però in alcuni sistemi come Windows sono 
    fondamentali poichè permettono di associare quel file a un programma specifico. Per esempio se apro un file .docx in Windows si 
    apre automaticamente Microsoft Word. 
    Esistono 3 tipologie di struttura del file:
        1) Sequenza non strutturata di byte = in Unix e Windows sono di questa tipologia. Il sistema operativo li vede come una semplice
        sequenza di byte e il significato è definito dal programma utente.
        2) Sequenza di record = i file sono gestiti attraverso una struttura a record di dimensioni fisse ed è una gestione che si utilizzava sui mainframe,
        inoltre è molto poco flessibile. Le operazioni avvengono a unità di record.
        3) Gestione ad albero = i file sono gestiti attraverso una gestione ramificata ad albero che è poco flessibile e la ricerca 
        è buona poichè ogni nodo è identificato in modo univoco da una chiave. Un esempio di file di questa tipologia sono i file SQL.
    In unix ci sono vari tipi di file, tra cui file normali che sono la struttura più basilare e le directory che sono file che contengono
    altri file. Poi ci sono due tipi di file speciali:
        a) File speciali a caratteri = che permettono la gestione dei dispositivi seriali di i/o, come stampanti.
        b) File speciali a blocchi = permettono la gestione dei dischi, come per esempio la swap.
    E infine esistono due tipi di file normali: 
        I) File ASCII = che sono quei file che sono leggibili per l'utente e possono essere stampati.
        II) File binari = che sono quei file che se li leggiamo non hanno un significato particolare ma hanno una struttura specifica.
                        Sono gli eseguibili e hanno una struttura specifica, ovvero intestazione(contine il numero magico per capire
                        se sono binari eseguibili o meno e tutti gli attributi del file), tabella di simboli(che serve per il debug)
                        e infine il testo e i dati da caricare in memoria.
    Per quanto riguarda i file esistono due tipi di accessi al file, sequenziale e casuale.
        A) Accesso sequenziale = ovvero dall'inizio del file e se si vuole leggere una cosa alla metà del file bisgona scorrerlo tutto.
                             E' un utilizzo vecchio e molto lento se si vuole leggere una determinata informazione.
        B) Accesso casuale = permette di spostare il puntatore del file in una posizione specifica e da quella posizione avviene una
                             lettura sequenziale. E' stat fondamentale in applicazioni di database poichè non era più necessario 
                             scorrere tutto il file da 0. Questo tipo di file può avvenire in due modi, o con la funzione LSEEK che 
                             sostanzialmente sposta il puntatore in una posizione specifica oppure in una posizione specificata nel file.
    Importanti sono gli I-node poichè ogni file ha un I-node specifico che ha la funzione di rappresentare il file e tutte i suoi
    attributi ma non contiene il nome e il contenuto. Infine i file hanno vari attributi, tra i più importanti ci sono:
        1)Protezione e accesso = che identificano chi può accedere al file, se solo il proprietario o gli utenti.
        2)Flag specifici = come per esempio se il file è in sola lettura o per identificare se è un file nascosto
        3)Dimensione = che ci specificano le dimensioni del file e il massimo possibile che possono raggiungere.
        4)Attributi temporali = data di creazione del file e ultima modifica.
        5)Gestione dei record.
    Ci sono varie operazioni che si possono fare sui file tra cui create(che crea un file in lettura), open(per aprire il file),
    close(per chiudere il file), read(per leggere da un file), write(per scrivere su un file), seek(per spostare il puntatore su quel file), 
    append(aggiunge elementi alla fine del file), get e set attributes(per vedere e modificare gli attributi del file).
            



# ciao
## ciao
### ciao


