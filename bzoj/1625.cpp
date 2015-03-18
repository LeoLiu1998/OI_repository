/*Copyright (c)2014 YeGuanghao
 *This source-code is licensed under GPLv3
 */
#include<iostream>
#include<cstdio>
#include<iomanip>
#include<climits>
#include<cmath>
#include<ctime>
#include<vector>
#include<set>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
inline void Read(int &x)
{
    char ch=getchar();
    while (ch<'0'||ch>'9') ch=getchar();
    x=0;
    while (ch<='9' && ch>='0')
    {
        x*=10,x+=ch-'0';
        ch=getchar();
    }
}
int dp[30000],n,m,ans;

int main()
{
	//freopen("gem.in","r",stdin);
	//freopen("gem.out","w",stdout);

	scanf("%d%d",&n,&m);
	dp[m]=1;
	for (int a=1;a<=n;a++)
	{
		int w,d;
		scanf("%d%d",&w,&d);
		for (int b=w;b<=m;b++)
			if (dp[b]!=0) dp[b-w]=max(dp[b-w],dp[b]+d),ans=max(dp[b-w],ans);
	}
	printf("%d\n",ans-1);

	return 0;
}