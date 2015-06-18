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
const int maxn=150;
char s[maxn];
int a[maxn];
int n;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;++i)
	{
		a[i]=s[i]-'0';
	}
	for(int i=0;i<n;++i) {
		if(a[i]%8==0 ) {
			puts("YES");
			P(a[i]);
			return 0;
		}
	}
	if(n>=2) {
		int tem;
		for(int i=0;i<n-1;++i) {
			for(int j=i+1;j<n;++j) {
				tem=a[i]*10+a[j];
				if(tem%8==0) {
					puts("YES");
					P(tem);
					return 0;
				}
			}
		}
	}
	if(n>=3) {
		int temp;
		for(int i=0;i<n-2;++i) {
			for(int j=i+1;j<n-1;++j) {
				for(int k=j+1;k<n;++k) {
					temp=a[i]*100+a[j]*10+a[k];
					if(temp%8==0) {
						puts("YES");
						P(temp);
						return 0;
					}
				}
			}
		}
	}
	puts("NO");
}
