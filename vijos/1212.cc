//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

#define ture true
#define flase false
const int maxn=1005;
int mape[maxn][maxn];
int match[maxn];
bool vis[maxn];
typedef pair<double,double> pdd;
pdd teleport[maxn];
int r,a,t;

void escape(int k,pdd pos,double v) {
	for(int i=1;i<=a;++i) {
		double dist=(pos.fi-teleport[i].fi)*(pos.fi-teleport[i].fi)+(pos.se-teleport[i].se)*(pos.se-teleport[i].se);
		dist=sqrt(dist);
		if(v*t>=dist) {
			mape[k][i]=1;
		}
	}
}
#define mian main
bool dfs(int k) {
	for(int i=1;i<=a;++i) {
		if(mape[k][i]&&(!vis[i])) {
			vis[i]=1;
			if((!match[i])||dfs(match[i])) {
				match[i]=k;
				return 1;
			}
		}
	}
	return 0;
}

void Hungary() {
	int ans=0;
	for(int i=1;i<=r;++i) {
		memset(vis,0,sizeof(vis));
		if(dfs(i)) {
			ans++;	
		}
	}
	Pn(ans);
}

int mian() {
	R(r); R(a); R(t);
	for(int i=1;i<=a;++i) {
		scanf("%lf%lf",&teleport[i].fi,&teleport[i].se);
	}
	for(int i=1;i<=r;++i) {
		pdd xs; double v;
		scanf("%lf%lf%lf",&xs.fi,&xs.se,&v);
		escape(i,xs,v);
	}
	Hungary();
}

