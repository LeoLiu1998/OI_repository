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
const int maxn=6010000;
int a[maxn];
int l[maxn],r[maxn];
stack<pii> s;
ll mi,ma;
int n;
#define clear(x);  while(x.size()) x.pop();
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		R(a[i]);
	}
	clear(s);
	s.push(mp(INT_MAX,0));
	for(int i=1;i<=n;++i) {
		pii cur=mp(a[i],i);
		while(cur>=s.top()) s.pop();
		l[i]=s.top().se;
		s.push(cur);
	}
	clear(s);
	s.push(mp(INT_MAX,n+1));
	for(int i=n;i;--i) {
		pii cur=mp(a[i],i);
		while(cur.fi>s.top().fi) s.pop();
		r[i]=s.top().se;
		s.push(cur);
	}
	for(int i=1;i<=n;++i) {
		ll lr=(i-l[i]),rr=(r[i]-i);
		mi=mi+lr*rr*a[i];
	}
	clear(s);
	s.push(mp(0,0));
	for(int i=1;i<=n;++i) {
		pii cur=mp(a[i],i);
		while(cur.fi<s.top().fi) s.pop();
		l[i]=s.top().se;
		s.push(cur);
	}
	clear(s);
	s.push(mp(0,n+1));
	for(int i=n;i;--i) {
		pii cur=mp(a[i],i);
		while(cur.fi<=s.top().fi) s.pop();
		r[i]=s.top().se;
		s.push(cur);
	}
	for(int i=1;i<=n;++i) {
		ll lr=(i-l[i]),rr=(r[i]-i); // [i,r)
		ma=ma+lr*rr*a[i];
	}
#ifdef YGHDEBUG
	cout<<mi<<endl;
	cout<<ma<<endl;
#endif
	cout<<mi-ma<<endl;
}

