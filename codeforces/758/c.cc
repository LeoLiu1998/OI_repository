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
inline void R(long long &x) {
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
ll cnt[105][105];
ll n,m,t,x,y;
int main() {
	R(n); R(m); R(t); R(x); R(y);
	if(t<=n*m) {
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=m;++j) {
				cnt[i][j]=1;
				if((i-1)*m+j>=t) goto END;
			}
		}
	} else {
		if(n==1) {
			ll num=t/m;
			t=t%m;
			for(int i=1;i<=m;++i) {
				cnt[1][i]+=num;
			}
			for(int i=1;i<=t;++i) {
				cnt[1][i]++;
			}
			goto END;
		}
		for(int i=1;i<=m;++i) {
			cnt[1][i]=1;
		}
		t-=m;
		ll rnd=2*(n-1)*m;
		ll num=t/rnd;
		t%=rnd;
		for(int i=1;i<=m;++i) {
			cnt[1][i]+=num;
			cnt[n][i]+=num;
		}
		for(int i=2;i<n;++i) {
			for(int j=1;j<=m;++j) {
				cnt[i][j]+=2*num;
			}
		}
		for(int i=2;i<=2*n;++i) {
			for(int j=1;j<=m;++j) {
				t--;
				int p=i;
				if(p>n) p=2*n-p;
				cnt[p][j]++;
				if(t<=0) goto END;
			}
		}
	}
END:
	ll ma=0,mi=LLONG_MAX;
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			ma=max(ma,cnt[i][j]);
			mi=min(mi,cnt[i][j]);
#ifdef YGHDEBUG
			if(cnt[i][j]==0) {
				Ps(i); Pn(j);
			}
#endif
		}
	}
	cout<<ma<<" "<<mi<<" "<<cnt[x][y]<<endl;
}

