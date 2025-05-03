dog(fido).
dog(rover).
dog(tom).
cat(mary).
cat(bill).
large(fido).
large(rover).
large(bill).
large_animal(X):-dog(X), large(X).