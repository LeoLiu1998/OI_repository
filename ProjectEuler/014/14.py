#837799
def solve(k):
	cnt=1
	while k!=1 :
		cnt+=1
		if(k&1) :
			k=k*3+1
		else:
			k=k/2
	return cnt

ans_cnt=0
for a in range(1,1000000):
	cur=solve(a)
	if(cur>ans_cnt):
		ans=a
		ans_cnt=cur
	print(a,cur)
print(ans)

