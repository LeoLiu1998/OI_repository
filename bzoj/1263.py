def delen(n):
	return len("%d"%n)

n=input()
n=int(n);
ans=1
if(n==1 or n==0):
	print 1;
	print n;
	exit()
while (n>=1):
	if n>=3:
		ans*=3;
		n-=3;
	elif n==2:
		ans*=2;
		n-=2;
	elif n==1:
		ans*=4
		ans/=3;
		n-=1;
l= delen(ans)
print l
if l<=100:
	print ans
else: 
	while l>100:
		ans/=10;
		l-=1;
	print(ans)
