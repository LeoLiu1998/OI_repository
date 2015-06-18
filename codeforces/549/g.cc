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
const int maxn=200500;
int a[maxn];
int n;
int main()
{
	R(n);
	for(int i=1;i<=n;++i) {
		R(a[i]);
	}
	int k=2700;
	while(k--){
	for(int i=1;i<n;++i) {
		if(a[i]>a[i+1]) {
			a[i]--;
			a[i+1]++;
			swap(a[i],a[i+1]);
		}
	}
	}
	for(int i=2;i<=n;++i) {
		if(a[i-1]>a[i]) {
			puts(":(");
			return 0;
		}
	}
	for(int i=1;i<=n;++i) {
		if(i!=n) printf("%d ",a[i]);
		else printf("%d\n",a[i]);
	}
	
}
