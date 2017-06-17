from random import randint
n=10000;
print n

#for i in range(n):
#	print randint(10,100000000)
for i in range(n):
	cmd=randint(1,3);
	l=randint(1,10**18);
	r=randint(l,10**18);
	print cmd,l,r


