Esercizio lab01

Dato il seguente problema:

min 4x1 + 2x2 – 3x3
s.t.
 2x1 + 3x2 + x3  ≤ 6
-4x1 + 3x2 - x3  ≤ 12
x1 ≤ 0, x2 ≥ 0, x3  ≥ 0; 

a) implementare e risolvere il problema in AMPL usando .mod e .dat
b) scrivere il modello in lp (comando expand)
c) considerare il modello in cui il termine noto b è sostituito dal termine noto b + α, con α ≥ 0. Studiare il comportamento del modello (valore della soluzione ottima, variabili in base, valore delle variabili in base) al variare di  α da 0 a 10. A tal fine implementare uno script che utilizzi il comando let di AMPL e utilizzi il file .run
d) riportare valori di slack e variabili duali associati alla soluzione ottima (nomevincolo.slack, nomevincolo)

Esercizio lab02

Dato il seguente problema:

min 2x1 + x2 + 3x4 - x5 + 4x6 + x7 + x8
s.t.
 x1 - x2 – x3 + x8  ≤ 80
 x4 + x5 + x6 - x7 ≤ 60
 x4 + x4  ≥ 60
 x2 + x5  = 40
 x3 + x6  ≥ 20
x1 x2, x4, x6, x7, x8  ≥ 0;   x5 ≤ 0, x3 libero; 

a) implementare e risolvere il problema in AMPL usando .mod e .dat
b) scrivere il modello in lp (comando expand)
c) considerare il modello in cui il termine noto b è sostituito dal termine noto b + α, con α ≥ 0. Studiare il comportamento del modello (valore della soluzione ottima, variabili in base, valore delle variabili in base) al variare di  α da 0 a 10. A tal fine implementare uno script che utilizzi il comando let di AMPL e utilizzi il file .run
d) riportare valori di slack e variabili duali associati alla soluzione ottima (nomevincolo.slack, nomevincolo)


Esercizio lab02
Un'azienda manifatturiera produce 2 modelli di centrifuga denominati rispettivamente “STD” e “HIQ”. Per la produzione di ciascuna delle due lavatrici servono dei macchinari di assemblaggio (ASM), e test (TST) oltre che dei materiali (MAT). Ciascuno dei due prodotti ha un diverso assorbimento di ore di lavoro per ciascuna macchina e per i materiali, e ci sono dei limiti massimi di utilizzo come mostrato nella seguente tabella. La tabella mostra anche il profitto (P) guadagnato dall’azienda per la vendita di una unità di ciascun prodotto:


     STD  HIQ  MAX
ASM   3   2    80
TST   2   4    60
MAT   4   4
P     10  15


a) implementare il modello di programmazione lineare AMPL ipotizzando che la produzione di un’unità di prodotto possa essere interrotta (variabili continue) e calcolare la produzione che massimizza il profitto

b) calcolare quale risorsa conviene aumentare di un’unità al fine di aumentare il profitto e di quanto questo aumenterebbe. Mostrare lo slack dei vincoli e il valore delle variabili duali all’ottimo.
