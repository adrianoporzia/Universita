/*
 * leaf(T, F). vero se t è un albero e f è una foglia
 * node(T, N) torna vero se n è un nodo T
*/

/*
 * t(R, Children) cioè albero dove children è una lista di elementi dell'albero
 * R(Children) =..[], con R testa e children la coda usando l'univ
 * */

/* Esempio di input nella riga di comando rispettivamente per:
 * somma --> t(3, 4).
 * leaf  -->t(a, [t(b, [t(a, []), t(b, [])]), t(c, []), t(d, [])]).
 * */


somma(t(A, B), S):-
    S is A + B.

/*
 * soluzione piu complessa e completa
 * somma(t(A, B), S):- 
 *      T =.. [t, A, B],
 *      S is A + B.
 * */

leaf(t(R, []), R).
leaf(t(R, Children), X):-
    member(C, Children),
    leaf(C, X).
    
node(t(R, _), R).
node(t(_, Children), N):-
    member(P, Children),
    node(P, N).
