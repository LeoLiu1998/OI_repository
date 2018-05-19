//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#ifdef _WIN32
#define Pln(x) printf("%I64d\n",x)
#define Pls(x) printf("%I6d ",x)
#else
#define Pln(x) printf("%lld\n",x)
#define Pls(x) printf("%lld ",x)
#endif
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
#ifndef DEBUG
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int a[25];
ll nex[25];
ll ans=0;
int n=14;
int main() {
	rep(i,0,n-1,1) R(a[i]);
	rep(i,0,n-1,1) {
		ll cur=0;
		nex[i]=0;
		ll dis=a[i]/14;
		ll rem = a[i]%14;
		int qaq=a[i];
		a[i]=0;
		memset(nex,0,sizeof nex);
		for(int j=1;j<=n;++j) {
			int pos=(i+j)%14;
			nex[pos]=(ll)a[pos]+dis+(j<=rem);
			if(nex[pos]%2==0) {
				cur+= 1ll*nex[pos];
			}
		}
#ifdef DEBUG
		rep(i,0,n-1,1)
			Pls(nex[i]);
		puts("");
#endif 
		ans=max(ans,cur);
		a[i]=qaq;
	}
	Pln(ans);
}


