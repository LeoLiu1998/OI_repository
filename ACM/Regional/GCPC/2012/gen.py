from random import randint
m = randint(3, 4)
n = randint(5, 5)
print 1
print n, m

# for i in range(n):
#	print randint(10,100000000)
for i in range(m):
    u = randint(0, n)
    v = randint(0, n)
    w = randint(1, 10)
    print u, v, w

k = randint(1,4)
print k
for i in range(1,k+1):
    print i,
print " "
print 20



#	cmd=randint(1,2);
#	if cmd == 1:
#		print cmd,randint(1,20)
#	print "M",randint(1,n),randint(10,100000000)
#	elif cmd==2:
# l=randint(1,n);
# r=randint(l,n);
#		print 0,randint(1,20)
#	elif cmd==3:
#		l=randint(1,n);
#		r=randint(l,n);
#		print "A",l,r
