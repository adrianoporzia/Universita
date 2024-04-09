/*Programmazione dinamica
 * fibonacci
 *f(n) = f(n - 1) + f(n + 2)
 * predicato
 * f(n, M)
 * 
 * 
 * 
 * */
fibonacci(1, 1).
fibonacci(2, 1).
fibonacci(N, M):-
    write('in'), nl,
    A is N - 1,
    B is N - 2,
    fibonacci(A, M1),!,
    fibonacci(B, M2),!,
    M is M1 + M2.
  
	    



