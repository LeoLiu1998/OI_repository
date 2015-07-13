from random import randint
m=randint(5,6)
n=randint(5,6)
print n,m
maxn=20
for i in range(n):
	print randint(1,maxn),
print ""
for i in range(m):
	cmd=randint(1,2);
	if cmd == 1:
		l=randint(1,n)
		r=randint(l,n)
		print "M",l,r,randint(1,maxn)
	elif cmd==2:
		l=randint(1,n-1);
		r=randint(l,n);
		print "Q",l,r

