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
const int maxv=300000;

int p[maxv],cnt,miu[maxv];

bool use[maxv];

long long n;

long long calc(long long n)
{
	long long ans=0;
	for (long long a=1;a<maxv;a++)
		ans=ans+n/(a*a)*miu[a];
	return n-ans;
}

int main()
{
	miu[1]=1;
	for (int a=2;a<maxv;a++)
	{
		if (!use[a]) p[++cnt]=a,miu[a]=-1;
		for (int b=1,v;b<=cnt && (v=p[b]*a)<maxv;b++)
		{
			use[v]=true;
			if (a%p[b]==0)
			{
				miu[v]=0;
				break;
			}
			miu[v]=-miu[a];
		}
	}
	scanf("%lld",&n);
	long long l=0,r=n*3+1;
	while (l+1!=r)
	{
		long long m=(l+r)>>1;
		if (calc(m)<n) l=m;
		else r=m;
	}
	printf("%lld\n",r);

	return 0;
}