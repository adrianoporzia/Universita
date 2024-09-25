:-dynamic ingrediente / 1.



piatto(carbonara, [(uovo, 2), (guanciale, 1)], 30).
piatto(amatriciana, [(sugo, 150), (guanciale,2 )], 30).
piatto(polpette, [(macinato, 600), (spezie, 20)], 50).

piatto_per_oggi(Tempo, NumPersone, NomePiatto, IngredientiConQuantità):-
    piatto(NomePiatto, IngredientiPerPiatto, X),
    Tempo >= X,
    checkIngredienti(NumPersone, IngredientiPerPiatto, IngredientiConQuantità).

checkIngredienti(_, [], _).
checkIngredienti(NumPersona, [(Nome,QuantiNeServono) | T], IngredientiConQuantità):-
    Necessari is NumPersona * QuantiNeServono,
    member((Nome, Necessari), IngredientiConQuantità),
    ingrediente(Nome, Disponibili),
    Disponibili >=0,
    retract(ingrediente((Nome, Disponibili))),
    X is Disponibili - Necessari,
    asserta(ingrediente((Nome, X))),
    checkIngredienti(NumPersona, T, IngredientiConQuantità).
	



