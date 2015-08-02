from random import randint
m=randint(490000,500000)
n=randint(190000,200000)
print n,m
for i in range(m):
	cmd=randint(1,3);
	if cmd == 1:
		print cmd,randint(1,n),randint(1,n)
#	print "M",randint(1,n),randint(10,100000000)
	elif cmd==2:
		print cmd,randint(1,n),randint(1,n);
	elif cmd==3:
		l=randint(1,n);
		r=randint(l,n);
		print cmd,l,r


