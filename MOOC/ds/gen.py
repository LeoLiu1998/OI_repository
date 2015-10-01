from random import randint
m=randint(5,6)
n=randint(5,6)
print n,m
maxn=200
last=5
for i in range(n):
	last=randint(1,maxn);
	print last,
print ""
for i in range(m):
	l=randint(1,maxn);
	r=randint(l,maxn);
	print l,r
