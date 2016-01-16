exp,t=int(raw_input()),int(raw_input())
l,r=0,1
while(r**exp<t):
	l=r;r=r*2
def check(x):
	if(x**exp>t):
		return False;
	else :
		return True;
while(r-l>1):
	mid=(l+r)//2
	if(check(mid)):
		l=mid
	else :
	 	r=mid
print l
