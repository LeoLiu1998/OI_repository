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
int n;
int d[1305];
int adj[1305][1305];
int tot=0;
int buff[1305];
int m;
pii rk[1305];
bool check() {
	rep(i,1,n,1) {
		rk[i]=mp(d[i],i);
	}
	sort(rk+1,rk+n+1,greater<pii>());
	int cur=0;
	memset(adj,0,sizeof adj);
	for(int p=1;p<=n;++p) {
		int i=rk[p].se;
		for(int q=p+1;q<=n;++q) {
			int j=rk[q].se;
			if(buff[i]&&buff[j]) {
				adj[i][j]=1;
				adj[j][i]=1;
				buff[i]-=1;
				buff[j]-=1;
				cur++;
			}
		}
	}
//	Pn(buff[n]);
	return cur==m;
}
bool appear=0;
void print() {
	Pn(m);
	for(int i=1;i<=n;++i) {
		for(int j=i+1;j<=n;++j) {
			if(adj[i][j]) {
				Ps(i); Pn(j);
			}
		}
	}
}

int main() {
	srand(time(0));
	R(n); 
	rep(i,1,n,1) {
		R(d[i]);
		tot+=d[i];
	}
	/*if(d[n]==n) {
		buff[n+1]=d[n];
		tot+=d[n];
		rep(i,1,n,1) {
			buff[i]=d[i];
		}
		n++;
		if(check())
			print();
		return 0;
	}*/
	for(int i=n+1;i<=d[n];++i) {
		d[i]=d[n];
		tot+=d[i];
	}
//	d[d[n]]=d[n];
	n=d[n];
	n++;
	//cerr<<n<<endl;
	for(int i=1;i<n;++i) {
		if(tot%2==d[i]%2) {
			buff[n]=d[i];
			m=(tot+buff[n])/2;
			for(int j=1;j<n;++j)
				buff[j]=d[j];
			if(check()) {
				print();
				return 0;
			}
		}
	}
}


