n=int(raw_input())
remain=n
x=n
ans=1
for a in range(1,x+1):
	t=int(raw_input())
	if t==-1:
		continue
	t=t-1
	for b in range(0,t):
		ans=ans*(n-2-b)
	for b in range(2,t+1):
		ans=ans/b
	n=n-t
	remain=remain-1
n=n-2
while n<>0:
	n=n-1
	ans=ans*remain
print(ans)
