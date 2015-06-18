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
inline int  R(int &x)
{
    x=0;int f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
   x*=f;
}
#define P(x) printf("%d\n",x)
const int maxn=100;
char a[maxn][maxn];
int n,m;
bool judge(int y,int x){
	bool have[4];
	memset(have,0,sizeof(have));
	for(int i=y;i<=y+1;i++) {
		for(int j=x;j<=x+1;++j) {
			switch(a[i][j]) {
				case 'f':
					have[0]++;
					break;
				case 'a':
					have[1]++;
					break;
				case 'c':
					have[2]++;
					break;
				case 'e':
					have[3]++;
					break;
			}
		}
	}
	return have[0]&have[1]&have[2]&have[3];
}
int main()
{
	int ans=0;
	R(n); R(m);
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) a[i][j]=getchar();
		getchar();
	}
	for(int i=1;i<n;++i) {
		for(int j=1;j<m;++j)
			ans+=judge(i,j);	
	}
	P(ans);
}
