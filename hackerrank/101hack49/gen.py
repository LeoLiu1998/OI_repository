from random import randint 
n=10
m=10
print (n),
print (m)
for i in range(n):
	print(randint(1,10)),
print("")

for i in range(m):
	cmd=randint(1,2)
	l=randint(1,n-1)
	r=randint(l,n)
	if(cmd==1):
		k=randint(1,10)
		print (cmd),
		print (l),
		print (r),
		print (k)
	else: 
	 	print (cmd),
		print (l),
		print (r)

