#            Teoria di Java
- ## 1. Introduzione a Java 
- Java è un linguaggio di programmazione orientato agli oggetti, sviluppato negli anni '90 da Sun Microsystems (ora Oracle). È uno dei linguaggi più diffusi al mondo grazie alla sua portabilità e alla semplicità d'uso.
- ### Caratteristiche di Java:
    - **Portabilità:** Java è famoso per la sua filosofia "Write Once, Run Anywhere". I programmi scritti in Java possono essere eseguiti su qualsiasi piattaforma che supporti la JVM (Java Virtual Machine).
    - **Linguaggio orientato agli oggetti:** Java si basa su concetti come classi e oggetti.
    - **Sicurezza:** Java include vari meccanismi per garantire la sicurezza delle applicazioni, come il controllo di accesso e la gestione della memoria tramite il Garbage Collector.
    - **Multithreading:** Java supporta l'esecuzione simultanea di più thread.
    - **Garbage Collection:** Java gestisce automaticamente la memoria liberando quella non più utilizzata (garbage collection).

- ## 2. Java Virtual Machine (JVM)
- La JVM è il cuore di Java. Essa esegue il codice bytecode, che viene generato dal compilatore Java. Ogni piattaforma (Windows, Mac, Linux) ha la sua implementazione della JVM, permettendo ai programmi Java di essere eseguiti ovunque.
- ### Funzionamento della JVM:
    - **Compilazione del codice:** Il codice sorgente Java (file .java) viene compilato in bytecode (file .class)
    - **Esecuzione:** La JVM esegue il bytecode interpretando e compilando il codice in istruzioni macchina
- ### Componenti della JVM:
    - **Class Loader:** Carica le classi necessarie all’esecuzione del programma.
    - **Memory Management:** La JVM gestisce la memoria e assegna lo spazio per le variabili e gli oggetti.
    - **Garbage Collection:** Libera la memoria che non è più utilizzata.
    - **Execution Engine:** Interpreta il bytecode e lo trasforma in istruzioni macchina.

- ## 3. Programmazione Orientata agli oggetti(OOP)
- Java è un linguaggio fortemente orientato agli oggetti. Questo significa che tutto in Java è rappresentato sotto forma di oggetti.
- ### Concetti chiave dell’OOP:
    1. **Classe:** Una classe è un blueprint per creare oggetti. Definisce attributi (variabili) e comportamenti (metodi) che l'oggetto può avere. Le classi sono fondamentali nella programmazione orientata agli oggetti (OOP) e rappresentano l'idea di incapsulamento, dove i dati e i metodi sono racchiusi insieme.
    - Esempio: 

                    public class Persona {
                        String nome;
                        int età;

                        public void saluta() {
                        System.out.println("Ciao, mi chiamo " + nome);
                        }
                    }
    2. **Oggetto:**  Un oggetto è un'istanza di una classe. Quando crei un oggetto, utilizzi la struttura definita dalla classe per rappresentare un'entità concreta. Gli oggetti sono utilizzati per interagire con i dati e metodi definiti nella classe.
    
                    Persona p1 = new Persona();
                    p1.nome = "Mario";
                    p1.saluta();
    3. **Incapsulamento:** È il principio di nascondere i dettagli interni di un oggetto e permettere l'accesso ai dati solo tramite metodi specifici. Si usa attraverso i modificatori di accesso come private, public, protected.

                    public class Persona {
                        private String nome;

                        public String getNome() {
                            return nome;
                        }

                        public void setNome(String nome) {
                            this.nome = nome;
                     }
                    }
    4. **Ereditarietà:** na classe può ereditare da un'altra classe. In questo modo, una classe "figlia" eredita attributi e metodi della classe "genitore".

                    public class Animale {
                        public void mangia() {
                            System.out.println("Sto mangiando");
                        }
                    }

                    public class Cane extends Animale {
                        public void abbaia() {
                            System.out.println("Bau bau");
                        }
                    }
    5. **Polimorfismo:** Significa che un oggetto può assumere diverse forme. In Java, il polimorfismo si realizza tramite l’overriding dei metodi (metodi che vengono riscritti nelle sottoclassi).

                    Animale mioCane = new Cane();
                    mioCane.mangia();  // Chiama il metodo mangia della classe Animale

- ## 4. Tipi di Dati in Java:
- ### Tipi Primitivi:
- Java include otto tipi di dati primitivi, che vengono usati per rappresentare dati semplici.
    1. **byte:** 8-bit intero (-128 a 127)
    2. **short:** 16-bit intero (-32,768 a 32,767)
    3. **int:** 32-bit intero (valori interi)
    4. **long:** 64-bit intero (grandi valori interi)
    5. **float:** 32-bit numero in virgola mobile
    6. **double:** 64-bit numero in virgola mobile
    7. **boolean:** valori true o false
    8. **char:** caratteri Unicode

- ## 5. Incapsulamento
- L'incapsulamento è il concetto che racchiude dati e metodi all'interno di una classe, nascondendo i dettagli di implementazione e proteggendo i dati dall'accesso diretto. Questo viene realizzato tramite modificatori di accesso (private, public, protected) che controllano chi può vedere o modificare variabili o metodi.

- ### Modificatori di accesso:
    - **private:** Accessibile solo all'interno della stessa classe.
    - **public:** Accessibile da qualsiasi altra classe.
    - **protected:** Accessibile solo dalle classi del pacchetto o da sottoclassi.

- ## 6. Ereditarietà
- L'ereditarietà è un meccanismo tramite il quale una classe può derivare da un'altra classe, ereditando attributi e metodi della classe base (o superclasse). Permette di riutilizzare il codice e di estendere la funzionalità di una classe senza doverla riscrivere.

- Parola chiave **extends:** Una classe derivata può estendere una classe base. Ad esempio:

                    class Cane extends Animale {
                        // La classe Cane eredita i metodi e i campi della classe Animale
                    }

- ## 7. Polimorfismo
- Il polimorfismo significa "molte forme". In Java, questo concetto consente a una classe di comportarsi in modo diverso a seconda del contesto. Il polimorfismo si realizza attraverso:

    1. **Sovraccarico di metodi (Overloading):** Quando più metodi nella stessa classe hanno lo stesso nome, ma diversi parametri.
    2. **Sovrascrittura dei metodi (Overriding):** Quando una sottoclasse fornisce una nuova implementazione di un metodo ereditato dalla superclasse.

- ## 8. Interfacce
- Un'interfaccia è un contratto che una classe può implementare. Definisce un insieme di metodi che devono essere implementati dalla classe che adotta l'interfaccia. In altre parole, un’interfaccia contiene solo dichiarazioni di metodi (senza corpo), lasciando l’implementazione alle classi.

- Parola chiave **interface:** Le interfacce sono definite con la parola chiave interface.

                    interface Animale {
                        void suono();
                    }

                    class Cane implements Animale {
                        public void suono() {
                            System.out.println("Bau Bau");
                        }
                    }
- ### Caratteristiche delle interfacce:

- Tutti i metodi in un'interfaccia sono implicitamente public e abstract.
    Le interfacce possono avere variabili, ma queste sono sempre public, static e final.
    Una classe può implementare più interfacce (polimorfismo di interfacce).

- ## 9. Classi astratte
- Una classe astratta è una classe che non può essere istanziata direttamente. Può contenere sia metodi astratti (senza implementazione) sia metodi concreti (con implementazione). Le classi astratte sono utilizzate quando vuoi fornire una base comune alle sottoclassi, ma non vuoi consentire la creazione diretta di oggetti dalla classe base.

- Parola chiave **abstract:** Definisce una classe astratta o un metodo astratto.

                    abstract class Animale {
                        public abstract void suono(); // metodo astratto
                    }

                    class Cane extends Animale {
                        public void suono() {
                            System.out.println("Bau Bau");
                        }
                    }

- ### Caratteristiche:
1) Le classi astratte possono avere metodi astratti e non astratti.
2) Le sottoclassi di una classe astratta devono fornire l’implementazione per i metodi astratti, altrimenti anch'esse devono essere dichiarate astratte.

- ## 10. Generics
- I Generics permettono di creare classi, interfacce e metodi che funzionano con qualsiasi tipo di dato. Consentono al codice di essere più flessibile e riutilizzabile, garantendo al tempo stesso la sicurezza del tipo (type safety) durante la compilazione.

- Uso dei **Generics:** Invece di specificare il tipo di dati in anticipo, si utilizza un parametro di tipo (come <T>).

                    public class Scatola<T> {
                        private T contenuto;

                        public void set(T contenuto) {
                            this.contenuto = contenuto;
                        }

                        public T get() {
                            return contenuto;
                        }
                    }

                    Scatola<String> scatolaStringa = new Scatola<>();
                    scatolaStringa.set("Ciao");
                    System.out.println(scatolaStringa.get());  // Stampa: Ciao

- ### Vantaggi dei Generics:

1) **Riusabilità:** Le classi e i metodi possono essere utilizzati con qualsiasi tipo di dato.
2) **Type Safety:** Gli errori di tipo vengono rilevati durante la compilazione.
3) **Riduzione del cast:** Non è necessario effettuare il casting di oggetti quando si utilizzano generici.

- ## 11. Eccezioni
- Le eccezioni sono eventi anomali che possono verificarsi durante l'esecuzione di un programma. Java gestisce le eccezioni attraverso il meccanismo del try-catch. Quando si verifica un'eccezione, il normale flusso del programma viene interrotto, e l'eccezione può essere catturata e gestita.

- ### Eccezioni checked e unchecked:
1) **Checked Exception:** Devono essere dichiarate o gestite con un blocco try-catch o una dichiarazione throws. Esempi: IOException, SQLException.
2) **Unchecked Exception:** Non devono essere dichiarate o gestite esplicitamente. Esempi: ArithmeticException, NullPointerException.
- ##### oss: try-catch e throws 

- ## 12. Collezioni
- Il Collections Framework di Java fornisce un insieme di classi e interfacce per gestire gruppi di oggetti. È una parte essenziale del linguaggio che permette di lavorare con strutture dati come liste, set, mappe, ecc.
- ### Principali interfacce del framework delle collezioni:
1) **List:** Un'interfaccia che rappresenta una collezione ordinata, che può contenere elementi duplicati. Gli elementi sono indicizzati.
    - Implementazioni principali:
        1) **ArrayList**: Un array ridimensionabile dinamicamente.
        2) **LinkedList:** Una lista a doppio collegamento.
2) **Set:** Un'interfaccia che rappresenta una collezione non ordinata di elementi unici (nessun duplicato).
    - Implementazioni principali:
        1) **HashSet:** Un set che non mantiene l'ordine degli elementi.
        2) **TreeSet:** Un set che ordina automaticamente gli elementi.
3) **Map:** Un'interfaccia che rappresenta una collezione di coppie chiave-valore. Ogni chiave è unica e viene associata a un solo valore.
    - Implementazioni principali:
        1) **HashMap:** Una mappa non ordinata basata su hash.
- ## 13. Modificatori di Accesso
- I modificatori di accesso controllano la visibilità delle classi, dei metodi e delle variabili in Java. Definiscono chi può accedere e modificare una risorsa.
- ### Tipi di modificatori:
1) **public:** La risorsa è accessibile da qualsiasi altra classe.
2) **private:** La risorsa è accessibile solo all'interno della stessa classe.
3) **protected:** La risorsa è accessibile all'interno del pacchetto e dalle sottoclassi.
4) **Default (nessun modificatore):** La risorsa è accessibile solo all'interno del pacchetto.

- ## 14. Ereditarietà Multipla
- ’ereditarietà multipla è un concetto della programmazione orientata agli oggetti che permette a una classe di ereditare da più di una classe base. In linguaggi come C++, è possibile ereditare attributi e metodi da più classi madri. Tuttavia, Java non supporta l'ereditarietà multipla diretta delle classi per evitare problemi di ambiguità, come il problema del diamante (quando una classe eredita da due classi madri che hanno un metodo con lo stesso nome, non si sa quale metodo ereditare).
- ### Motivazioni per cui Java non supporta l'Ereditarietà Multipla di classi:
1) **Ambiguità:** L’ereditarietà multipla può creare ambiguità, poiché una sottoclasse potrebbe ereditare lo stesso metodo da più classi. Java evita queste ambiguità vietando l'ereditarietà multipla delle classi.
2) **Manutenzione complessa:** L’ereditarietà multipla può portare a una progettazione del codice complessa e difficile da mantenere.
- ### Ereditarietà multipla indiretta: Le Interfacce
- In Java, sebbene non sia possibile ereditare da più classi, è possibile implementare più interfacce. Le interfacce, a differenza delle classi, non contengono implementazione, ma solo dichiarazioni di metodi. Questo permette alla classe che le implementa di definire i metodi richiesti.
- **Implementazione di più interfacce:** Una classe può implementare più interfacce utilizzando la parola chiave implements.
- ### Conclusioni:
- **Ereditarietà Multipla di classi:** Non è supportata in Java per evitare ambiguità e complessità.
- **Ereditarietà Multipla con Interfacce:** Java consente a una classe di implementare più interfacce, permettendo così una forma di ereditarietà multipla senza i problemi associati. Questo offre flessibilità e riduce i rischi di conflitto.

- ## 15. Reference Type 
- In Java, esistono due principali categorie di tipi di dati:
    1) **Tipi primitivi:** rappresentano valori semplici come numeri interi, numeri decimali, valori booleani, e caratteri (es: int, double, boolean, char).
    2) **Tipi di riferimento:** rappresentano oggetti e contengono riferimenti a dati più complessi. Questi includono le classi (come String, Integer e altre Wrapper Class), array, e oggetti creati dall’utente.

- ### Differenza chiave:

    - Un tipo primitivo contiene direttamente il valore, ad esempio, una variabile di tipo int contiene un valore numerico.
    - Un tipo di riferimento contiene un riferimento o indirizzo di memoria che punta all'oggetto effettivo in memoria heap.



 



















