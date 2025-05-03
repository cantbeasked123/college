woman(jia).
man(john).
healthy(john).
healhy(jia).
wealthy(john).
traveller(X):-healthy(X),wealthy(X).
can_travel(X):-traveller(X).