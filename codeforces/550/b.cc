/*Copyright (c)2015 YeGuanghao
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
inline void  R(int &x)
{
    x=0;int f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
   x*=f;
}
#define P(x) printf("%d\n",x)
int n,l,r,x;
int a[20];
bool use[20];
int ans=0;
#define lowbit(x) ((x)&(-x))
int v[1<<16];
bool check(int k) {
	int sum=0;
	int ma=-54564156,mi=52146546;
	while(k) {
		int cur=v[lowbit(k)];	
		sum+=a[cur];
		ma=max(ma,a[cur]);
		mi=min(mi,a[cur]);
		k-=lowbit(k);
	}
	return sum<=r&&sum>=l&&(ma-mi>=x);
}
int main()
{
	R(n); R(l); R(r); R(x);
	for(int i=1;i<=n;++i) R(a[i]);
	for(int i=0;i<=n;++i) {
		v[1<<i]=i+1;
	}
	for(int i=0;i<=(1<<n)-1;++i){
		ans+=check(i);
	}
	P(ans);
}
