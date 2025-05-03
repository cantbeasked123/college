likes(john,susie).
likes(everyone,susie).
likes(john,everyone).
not_likes(john,pizza).
likes(john,everyone), likes(everyone, john).
likes(john,susie); likes(john,mary).
likes(john,susie):-likes(john,mary).