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
int a[100];
int k;
int n;
int ans=0;
vector<int> v;
int vis[100];
bool Check(int l,int r) {
	memset(vis,0,sizeof vis);
	for(int i=l;i<=r;++i) {
		vis[a[i]]=1;
	}
	for(int i=0;i<=k;++i) {
		if(!vis[i]) return 1;
	}
	return 0;
}

bool Check(int x) {
	v.clear();
	v.pb(0);
	for(int i=0;i<n-1;++i) {
		if((1<<i)&x) {
			v.pb(i+1);
		}
	}
	v.pb(n);
	for(int i=0;i<v.size()-1;++i) {
		if(!Check(v[i]+1,v[i+1])) {
//			Pn(x);
			return 0;
		}
	}
	for(int i=0;i<n-1;++i) {
		printf("%d",((1<<i)&x)!=0);
	}
	puts("");
	for(int i=0;i<v.size()-1;++i) {
		for(int j=v[i]+1;j<=v[i+1];++j) {
			Ps(a[j]);
		}
		printf("|");
	}
	puts("");
	return 1;
}
int main() {
	R(n); R(k);
	for(int i=1;i<=n;++i) {
		R(a[i]);
	}
	for(int i=(1<<(n-1))-1;~i;--i) {
		ans+=Check(i);
	}
	cout<<ans<<endl;
}

