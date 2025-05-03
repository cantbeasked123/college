man(marcus).
pompeian(marcus).
ruler(caesar).
tried_to_assassinate(marcus,caesar).
roman(X):-pompeian(X).
person(X):-man(X).

% If someone tries to assassinate a ruler, they are not loyal
not_loyal_to(X,Y):-tried_to_assassinate(X,Y),ruler(Y).

% A person hates a ruler if they are not loyal to them
hates(X,Y):-not_loyal_to(X,Y).

assassin(X,Y):-tried_to_assassinate(X,Y),ruler(Y).
