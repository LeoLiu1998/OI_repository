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
#define PROB "div7"
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
const int maxn=50005;
int pre[maxn];
int firo[10];
int n;
int temp;
int ans=0;
int main() {
	Redirect();
	R(n);
	for(int i=0;i<7;++i) {
		firo[i]=INT_MAX;
	}
	for(int i=1;i<=n;++i) {
		register int t; R(t);
		pre[i]=pre[i-1]+t;
		pre[i]%=7;
		if(firo[pre[i]]==INT_MAX) {
			firo[pre[i]]=i;
		}
	}
	for(int i=n;i;--i) {
		int len=i-firo[pre[i]];	
		ans=max(ans,len);
	}
	Pn(ans);
}

