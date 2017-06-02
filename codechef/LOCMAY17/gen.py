from random import randint
n=20000
m=100000
print (n),
print(m)
for i in range(n):
	print(2**randint(1,63)),
print(" ")
for i in range(m):
	print(randint(1,(n)*(n-1)/2))
print("")
