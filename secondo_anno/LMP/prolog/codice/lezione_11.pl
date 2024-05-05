/*
 * 2 + 3 x 5 = ? quale è l'albero?
 *
 *                  +(300)
 *          2               X(100)
 *
 *                      3       5
 *
 *
 * definiamo la relazione di precedenza X > : > + > - 
 *
 * posso associare un numero a ogni operatori es: 
 *  100 > 200 > 300 > 400 cosi immediatamente posso individuare chi fare prima
 * nell'albero vedo se numero sopra è > di quello sotto
 *   2 + 3 X 5 
 *   + (2, X (3, 5))
 *
 *  :- op(priorità, {fx, xfx, xfy, yfx} , nome).
 *
 *  oss: la priorità in prolog è decrescente
 *  oss : xfx e yfx 
 *
 *  definiamo operatore somma che deve comportarsi come il +.
 *  mario ha macchina di dario.
 *  giovanni ha panino.
 *  elena ha panino di giovanni.
 *  giacomo ha borse di pelle di dario.x
 *
 *  var(_) ci dice se argomento è variabile o meno
 *  nonvar(_) contrario
 *
 *
 *  es ordina(X, LX):-
     *  nonvar(X).
 *  per definizione di ordina deve ordinare se trova var.
*/
:-op(700, xfx, ha).
:-op(600, xfy, di).

:-op(900, xfx, somma).
:-op(1000, xfx, moltiplica).
/*
ha(mario, di(macchina, dario)).
ha(giovanni, panino).
ha(elena, di(panino, giovanni)).
*/ 
 

mario ha macchina di dario.
giovanni ha panino.
elena ha panino di giovanni.
giocomo ha borsa di pelle di daino.
giacomo ha borsa di pelle di nonna.

due somma tre.




