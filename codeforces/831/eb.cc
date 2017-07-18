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
int ans=0;
bool vis[10005];
int a[10005];
int ori[1005];
int cur=0;
int n;
int pos;
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		R(a[i]);
		ori[i]=a[i];
		vis[i]=1;
	}
	sort(a+1,a+n+1);
	pos=n;
	for(int i=1;i<=n;++i) {
		for(int j=pos+1;;++j) {
			if(j>n) j-=n;
			ans+=vis[j];
			if(ori[j]==a[i]) {
				vis[j]=0;
				pos=j;
				break;
			}
		}
#ifdef YGHDEBUG
		Pn(ans);
#endif
	}
	Pn(ans);
}

