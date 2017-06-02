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
const int maxn=5005;
int l[maxn],r[maxn],a[maxn];
int cnt;
int ans=0,n;
set<int> s;
int rm=0;
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		R(a[i]);
		if(!l[a[i]]) l[a[i]]=i;
		r[a[i]]=i;
	}
	for(int i=1;i<=n;++i) {
		s.insert(a[i]);
		if(rm<r[a[i]]) {
			rm=r[a[i]];
		}
		if(i==rm) {
			for(auto x:s) {
				cnt=cnt^x;
			}
			ans+=cnt;
			cnt=0;
			s.clear();
			rm=0;
			continue;
		}
		
	}
	Pn(ans);
}

