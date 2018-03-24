from random import randint

n = 100000

a = 10000000
b = 5000000

print n

used = set()
for i in range(n):
    x = randint(-a,a)
    y = randint(-b,b)
    while (x,y) in used:
        x = randint(-a,a)
        y = randint(-b,b)
    used.add((x,y))
    print x,y
