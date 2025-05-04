father(david,emma).
mother(emma,liam).
mother(emma,olivia).
brother(liam,olivia).
daughter(olivia,emma).
grandmother(sophia,liam).
grandfather(michael,liam).
husband(david,emmas_mother).

parent(X,Y):-father(X,Y);mother(X,Y).
child(Y,X):-parent(X,Y).
sibling(X,Y):-parent(Z,X),parent(Z,Y),X\=Y.