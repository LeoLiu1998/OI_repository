//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
void Redirect() {
	freopen(PROB".in","r",stdin);
#ifndef YGHDEBUG
	freopen(PROB".out","w",stdout);
#endif
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll a[505][505];
int n;
pii pos;
ll sum;
ll ans;
bool CheckRow(int k) {
	ll cur=0;
	for(int i=1;i<=n;++i)
		cur=cur+a[k][i];
	return cur==sum;
}
bool CheckCol(int k) {
	ll cur=0;
	for(int i=1;i<=n;++i) 
		cur=cur+a[i][k];
	return cur==sum;
}
bool CheckL() {
	ll cur=0;
	for(int i=1;i<=n;++i) 
		cur=cur+a[i][i];
	return cur==sum;
}
bool CheckR() {
	ll cur=0;
	for(int i=1;i<=n;++i)
		cur=cur+a[i][n+1-i];
	return cur==sum;
}
bool Check() {
	if(ans<=0) return 0;
	for(int i=1;i<=n;++i) {
		if(!CheckRow(i))
			return 0;
		if(!CheckCol(i))
			return 0;
	}
	if(!CheckL())
		return 0;
	if(!CheckR()) 
		return 0;
	return 1;
}
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			int t; R(t);
			(a[i][j])=t;
			if(!a[i][j]) {
				pos=mp(i,j);
			}
		}
	}
	if(n==1) {
		puts("1");
		return 0;
	}
	int temp= (pos.fi==1) ? n:1;
	for(int i=1;i<=n;++i) {
		sum=sum+a[temp][i];
	}
	ans=sum;
	for(int i=1;i<=n;++i) {
		ans=ans-a[pos.fi][i];
	}
	a[pos.fi][pos.se]=ans;
	cout<<(Check()? ans: -1)<<endl;
}

