from random import randint
m=randint(5,6)
n=randint(5,6)
print n,m
for i in range(n):
	print randint(10,100000000)
for i in range(m):
	cmd=randint(1,3);
	if cmd == 1:
		print "M",randint(1,n),randint(10,100000000)
	elif cmd==2:
		l=randint(1,n);
		r=randint(l,n);
		print "Q",l,r
	elif cmd==3:
		l=randint(1,n);
		r=randint(l,n);
		print "A",l,r


