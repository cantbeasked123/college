#2 water jug problem
a = int(input("Enter capacity of Jug A: "))
b = int(input("Enter capacity of Jug B: "))

ai = int(input("Enter initial water in Jug A: "))
bi = int(input("Enter initial water in Jug B: "))

af = int(input("Enter final water level required in Jug A: "))
bf = int(input("Enter final water level required in Jug B: "))

print("\nList of operations:")
print("1: Fill jug A completely")
print("2: Fill jug B completely")
print("3: Empty jug A")
print("4: Empty jug B")
print("5: Pour water from jug A to B until full")
print("6: Pour water from jug B to A until full")
print("7: Pour all water from jug A to B")
print("8: Pour all water from jug B to A")

while (ai != af or bi != bf):
    print(f"\nCurrent state: Jug A = {ai}, Jug B = {bi}")
    op = int(input("Choose an operation: "))

    if op == 1:
        ai = a
    elif op == 2:
        bi = b
    elif op == 3:
        ai = 0
    elif op == 4:
        bi = 0
    elif op == 5:
        if (b - bi > ai):
            bi = bi + ai
            ai = 0
        else:
            ai = ai - (b - bi)
            bi = b
    elif op == 6:
        if (a - ai > bi):
            ai = ai + bi
            bi = 0
        else:
            bi = bi - (a - ai)
            ai = a
    elif op == 7:
        bi = bi + ai
        ai = 0
    elif op == 8:
        ai = ai + bi
        bi = 0
    else:
        print("Invalid operation. Please choose a number between 1 and 8.")

print(f"\nFinal state reached: Jug A = {ai}, Jug B = {bi}")