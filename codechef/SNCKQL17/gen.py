from random import randint

m=10

def gen():
	t=randint(1,10000)
	if(t%2==1) :
		x=randint(1,m)
		y1=randint(1,m)
		y2=randint(1,m)
		print(x),
		print(y1),
		print(x),
		print(y2)
	else :
		x1=randint(1,m)
		x2=randint(1,m)
		y=randint(1,m)
		print(x1),
		print(y),
		print(x2),
		print(y)


T=1000;
print(T)
for i in range(T):
	gen()
	gen()


