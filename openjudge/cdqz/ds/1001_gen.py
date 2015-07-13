from random import randint
m=randint(5,6)
n=randint(5,6)
print n,m
maxn=2000
for i in range(n):
	print randint(1,maxn)
for i in range(m):
	cmd=randint(1,2);
	if cmd == 1:
		print "M",randint(1,n),randint(1,maxn)
	elif cmd==2:
		l=randint(1,n);
		r=randint(0,i+1);
		print "Q",l,r

