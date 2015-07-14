from random import randint
m=randint(5,6)
n=randint(10,60)
print n

#for i in range(n):
#	print randint(10,100000000)
for i in range(n):
	cmd=randint(1,2);
	if cmd == 1:
		print cmd,randint(1,20)
#	print "M",randint(1,n),randint(10,100000000)
	elif cmd==2:
#l=randint(1,n);
#r=randint(l,n);
		print 0,randint(1,20)
	elif cmd==3:
		l=randint(1,n);
		r=randint(l,n);
		print "A",l,r


