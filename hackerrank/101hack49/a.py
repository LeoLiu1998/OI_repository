import math
n=int(input(''))
numbers = list(map(int, input().split()))
sum=4
for i in numbers :
	sum=sum*i
print(int(math.floor(sum/1024)))


