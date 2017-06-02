from random import randint
t=100
print(t)
for x in range(t):
	n=10
	l=randint(2,7)
	print(n),
	print(l),
	al=randint(1,50)
	b=al+(n*l)
	b=b+(randint(0,30))
	print (al),
	print(b)
	for i in range(n):
		print(randint(1,30)),
	print("")
