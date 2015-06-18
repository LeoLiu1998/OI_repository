#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int n,k,ans=0;
void dfs(int n,int k)
{
	if (n<2+k||(n+k)%2==1) 
	{
		ans++;
		return;
	}
	dfs((n+k)/2,k);
	dfs((n-k)/2,k);
}
int main()
{
    scanf("%d%d",&n,&k);
	ans=0;
	dfs(n,k);
	printf("%d\n",ans);
	return 0;
}
