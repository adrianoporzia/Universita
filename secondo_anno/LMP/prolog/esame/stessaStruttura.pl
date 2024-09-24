% FORMA FACILE

%haStessaStruttura([Sinistra1, Destra1], [Sinistra2, Destra2]) :-
%    stessaStrutturaFatto(Sinistra1, Sinistra2), 
%    stessaStrutturaLista(Destra1, Destra2).    

%stessaStrutturaFatto(F1, F2) :-
%    F1 =.. [_|Args1],  
%    F2 =.. [_|Args2],  
%    length(Args1, L1), 
%    length(Args2, L2), 
%    L1 =:= L2.      

%stessaStrutturaLista(L1, L2) :-
%    length(L1, Len1),
%    length(L2, Len2),
%    Len1 =:= Len2.


% Predicato per confrontare due fatti o due regole
haStessaStruttura(P1, P2) :-
    P1 =.. Lista1,
    P2 =.. Lista2,
    stessoNumeroArgomenti(Lista1, Lista2).

haStessaStruttura((P1 :- Corpo1), (P2 :- Corpo2)) :-
    haStessaStruttura(P1, P2),
    stessoNumeroComponenti(Corpo1, Corpo2).

% Controlla se due liste di predicati hanno lo stesso numero di argomenti
stessoNumeroArgomenti([_ | Arg1], [_ | Arg2]) :-
    length(Arg1, N1),
    length(Arg2, N2),
    N1 =:= N2.

% Controlla che i corpi delle regole abbiano lo stesso numero di componenti
stessoNumeroComponenti(C1, C2) :-
    C1 =.. Lista1,
    C2 =.. Lista2,
    length(Lista1, Lunghezza1),
    length(Lista2, Lunghezza2),
    Lunghezza1 =:= Lunghezza2.

