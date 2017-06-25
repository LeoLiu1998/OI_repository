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
const int maxn=300500;
int n;
int a[maxn],b[maxn],c[maxn];
pii ra[maxn],rb[maxn],rc[maxn];
int st[4][maxn][14];
stack<pii> s;
#define clear(x) while(x.size()) x.pop();
void Build() {
	for(int i=1;i<=n;++i) {
		st[1][i][0]=a[i];
		st[2][i][0]=b[i];
		st[3][i][0]=c[i];
	}
	int k=floor(log((double)n)/log(2.0));
	for(int q=1;q<=3;++q) {
	for(int j=1;j<=k;++j) {
		for(int i=n;i;--i) {
			if(i+(1<<(j-1))<=n)
				st[q][i][j]=max(st[q][i][j-1],st[q][i+(1<<(j-1))][j-1]);	
		}
	}
	}
}
const int mod=(int)1e9+7;
ll ans=0;
ll qpow(ll x,ll n) {
	ll ret=1;
	while(n) {
		if(n&1) {
			ret=ret*x%mod;
		}
		x*=x;
		x%=mod;
		n>>=1;
	}
	return ret;
}
inline int Query(int q,int l,int r) {
	int k = floor(log((double)(r-l+1))/log(2.0));
	return max(st[q][l][k],st[q][r-(1<<k)+1][k]);
}
int ma[4];
int main() {
	R(n);
	rep(i,1,n,1) {
		R(a[i]); R(b[i]); R(c[i]);
		if(a[i]<b[i]) swap(a[i],b[i]);
		if(a[i]<c[i]) swap(a[i],c[i]);
		if(b[i]<c[i]) swap(b[i],c[i]);
	}
//	Build();
	//cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
	for(int i=1;i<=n;++i) {
		memset(ma,0,sizeof ma);	
		for(int j=i;j<=n;++j) {
			ll cur=1;
			ma[1]=max(ma[1],a[j]);
			ma[2]=max(ma[2],b[j]);
			ma[3]=max(ma[3],c[j]);
			for(int q=1;q<=3;++q) {
				//cur=cur*Query(q,i,j)%mod;
				cur=cur*ma[q]%mod;
			}

			ans+=cur;
		//	cerr<<i<<" "<<j<<" "<<cur<<endl;
			ans%=mod;
		}
	}
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
	ans=ans*qpow((ll)n*(n+1)/2,mod-2)%mod;
	cout<<ans<<endl;
/*	clear(s);
	s.push(mp(INT_MAX,0));
	for(int i=1;i<=n;++i) {
		pii cur=mp(a[i],i);
		while(cur.fi>=s.top().fi) s.pop();
		ra[i].fi=s.top().se;
		s.push(cur);
	}
	clear(s);
	s.push(mp(INT_MAX,n+1));
	for(int n;i;--i) {
		pii cur=mp(a[i],i);
		while(cur.fi>s.top().fi)  s.pop();
		ra[i].se=s.top().se;
		s.push(cur);
	}
	clear(s);
	s.push(mp(INT_MAX,0));
	for(int i=1;i<=n;++i) {
		pii cur=mp(b[i],i);
		while(cur.fi>=s.top().fi) s.pop();
		rb[i].fi=s.top().se;
		s.push(cur);
	}
	clear(s);
	s.push(mp(INT_MAX,n+1));
	for(int n;i;--i) {
		pii cur=mp(b[i],i);
		while(cur.fi>s.top().fi)  s.pop();
		rb[i].se=s.top().se;
		s.push(cur);
	}
	clear(s);
	s.push(mp(INT_MAX,0));
	for(int i=1;i<=n;++i) {
		pii cur=mp(c[i],i);
		while(cur.fi>=s.top().fi) s.pop();
		ra[i].fi=s.top().se;
		s.push(cur);
	}
	clear(s);
	s.push(mp(INT_MAX,n+1));
	for(int n;i;--i) {
		pii cur=mp(a[i],i);
		while(cur.fi>s.top().fi)  s.pop();
		ra[i].se=s.top().se;
		s.push(cur);
	}*/
}

