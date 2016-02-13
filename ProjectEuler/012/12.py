#76576500
import math
def divisor(a):
	ret=0
	b=int(math.sqrt(a+1))
#print(b)
	for i in range(1,b+1):
		#print(i)
		if a%i == 0:
			ret+=1
			if(a!=i*i):
				ret+=1
	return ret

cnt=1
cur=0
while(divisor(cur)<500):
	cur=cur+cnt
	cnt=cnt+1
print(cur)
