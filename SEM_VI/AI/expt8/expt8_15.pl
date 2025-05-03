furniture(chair).
furniture(table).
furniture(bed).
utensil(spoon).
utensil(fork).
utensil(knife).
electronic_device(laptop).

category(X,furniture):-furniture(X).
category(X,utensil):-utensil(X).
category(X,electronic_device):-electronic_device(X).