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
int a[105][105];
int b[105][105];
int n,m;
int tot;
int tot2;
vector<pair<pii,int> > ans2;
vector<pair<pii,int> > ans;
int main() {
	R(n); R(m);
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			R(a[i][j]);
			b[i][j]=a[i][j];
		}
	}
	int ma=-1,mi=INT_MAX;
	for(int i=1;i<=m;++i) {
		mi=min(mi,a[1][i]);
	}
	for(int i=1;i<=m;++i) {
		if(a[1][i]>mi) {
			int delta=a[1][i]-mi;
			ans.pb(mp(mp(1,i),delta));
			for(int j=1;j<=n;++j) {
				a[j][i]-=delta;
			}
			tot+=delta;
		}
	}
	mi=0;
	for(int i=1;i<=n;++i) {
		mi=min(mi,a[i][1]);
	}
	for(int i=1;i<=n;++i) {
		if(a[i][1]>mi) {
			int delta=a[i][1]-mi;
			ans.pb(mp(mp(2,i),delta));
			for(int j=1;j<=m;++j) {
				a[i][j]-=delta;
			}
			tot+=delta;
		}
	}
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			if(a[i][j]) {
				puts("-1");
				return 0;
			}
		}
	}
	swap(a,b);
	ma=-1,mi=INT_MAX;
	for(int i=1;i<=n;++i) {
		mi=min(mi,a[i][1]);
	}
	for(int i=1;i<=n;++i) {
		if(a[i][1]>mi) {
			int delta=a[i][1]-mi;
			ans2.pb(mp(mp(2,i),delta));
			for(int j=1;j<=m;++j) {
				a[i][j]-=delta;
			}
			tot2+=delta;
		}
	}
	mi=0;
	for(int i=1;i<=m;++i) {
		mi=min(mi,a[1][i]);
	}
	for(int i=1;i<=m;++i) {
		if(a[1][i]>mi) {
			int delta=a[1][i]-mi;
			ans2.pb(mp(mp(1,i),delta));
			for(int j=1;j<=n;++j) {
				a[j][i]-=delta;
			}
			tot2+=delta;
		}
	}
	bool flag;
	if(tot2<tot) {
		Pn(tot2);
		for(int i=0;i<ans2.size();++i)  {
			pii opt=ans2[i].fi; int k=ans2[i].se;
			for(int i=1;i<=k;++i) {
				if(opt.fi==1) {
					printf("col %d\n",opt.se);
				} else {
					printf("row %d\n",opt.se);
				}
			}
		}
		return 0;
	}
	Pn(tot);
	for(int i=0;i<ans.size();++i)  {
		pii opt=ans[i].fi; int k=ans[i].se;
		for(int i=1;i<=k;++i) {
			if(opt.fi==1) {
				printf("col %d\n",opt.se);
			} else {
				printf("row %d\n",opt.se);
			}
		}
	}
}

