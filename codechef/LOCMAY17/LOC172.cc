//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define CL(x) memset(x,0,sizeof(x))
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
int w,h;
int n;
pii ro[1005];
pii l[1005];
pii r[1005];
int lc,rc=0;
int cnt=0,ans=0;
int main() {
	while(scanf("%d%d",&w,&h)&&(w!=-1)&&(h!=-1)) {
		lc=rc=cnt=ans=0;
		R(n); int x,y,d;
		CL(ro); CL(l); CL(r);	
		for(int i=1;i<=n;++i) {
			R(x); R(y); R(d);
			//ro[i]=mp(max(1,y-d),min(y+d,h));
			ro[i]=mp(y-d,y+d);
		}
		sort(ro+1,ro+n+1);
		for(int i=1;i<=n;++i) {
			l[i]=mp(ro[i].fi,i);
			r[i]=mp(ro[i].se,i);
		}
		sort(l+1,l+n+1);
		sort(r+1,r+n+1);
		l[n+1]=r[n+1]=mp(INT_MAX,INT_MAX);
		r[n+1].fi--;
		x=0;
		do{
			if(l[lc+1].fi<=r[rc+1].fi) {
				lc++;
				x=l[lc].fi;
				cnt++;
				ans=max(cnt,ans);
			} else {
				rc++;
				x=r[rc].fi;
				cnt--;
			}
		}while(rc!=n);
		Pn(ans);
	};
}

