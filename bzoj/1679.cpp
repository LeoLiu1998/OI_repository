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
int n;

long long z[10002],sum[10002];

int main()
{
	//freopen("volume.in","r",stdin);
	//freopen("volume.out","w",stdout);

	scanf("%d",&n);
	for (int a=1;a<=n;a++)
		scanf("%lld",&z[a]);
	sort(z+1,z+n+1);
	for (int a=1;a<=n;a++)
		sum[a]=sum[a-1]+z[a];
	long long ans=0;
	for (long long a=1;a<=n;a++)
		ans+=(a-1)*z[a]-sum[a-1]+sum[n]-sum[a]-(n-a)*z[a];
	printf("%lld\n",ans);

	return 0;
}