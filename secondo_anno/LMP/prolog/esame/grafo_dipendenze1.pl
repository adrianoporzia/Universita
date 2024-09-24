
edge(gatto, mangia).
edge(mangia, cane).
edge(cane, mangia).
edge(mangia, topo).

soggetto_verbo_oggetto(V, S, O):-
    edge(S, V),
    edge(V, O).












