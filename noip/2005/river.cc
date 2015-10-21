//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

int l,r;
int m;
int n;
const int maxn=1e6;
int dp[maxn+5];
bool stone[maxn+5];
int a[105];
int del[105];
int main() {
	R(n);R(l); R(r); R(m);
	for(int i=1;i<=m;++i) {
		R(a[i]);
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=m;++i) {
		del[i]=a[i]-a[i-1];
		if(del[i]>1000)  del[i]=100*r+del[i]%r;
	}
	for(int i=1;i<=m;++i) {
		a[i]=a[i-1]+del[i];
		stone[a[i]]=1;
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=0;i<=maxn;++i) {
		for(int j=l;j<=r;++j) {
			if(i-j>=0) {
				dp[i]=min(dp[i],dp[i-j]+stone[i]);
			}
		}
	}
	int ans=0x3f3f3f3f;
	for(int i=maxn-100;i<=maxn;++i) ans=min(ans,dp[i]);
	Pn(ans);
}
