def solve(a):
	if(a == 0):
		return 0
	if(a == 1):
		return 1
	if(a%2 == 0):
		return solve(a/2)
	else:
		return solve(a/2)+solve(a/2 +1)

n=input();
for i in range(1,n+1):
	a=input()
	print(solve(a))