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
#define size sze
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
pii a[100050];
int f[100050];
int size[100500];
multiset<int> ss;
int n;
int seg=0;
int ans=0;
int max_seg = 0;
int getf(int x) {
	if(f[x]==x) return x;
	else return f[x]=getf(f[x]);
}

void Merge(int x,int y) {
	int fx=getf(x),fy=getf(y);
	if(fx==fy) return; 
	int l=min(fx,fy),r=max(fx,fy);
	f[r]=f[l];
	ss.erase(size[f[l]]);
	ss.erase(size[f[r]]);
	size[f[l]]+=size[f[r]];
	ss.insert(size[f[l]]);
	seg--;
}

int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		R(a[i].fi); a[i].se=i; 
	}
	sort(a+1,a+n+1);
	a[n+1].fi=a[n].fi+1;
	memset(f,-1,sizeof f);
	for(int i=1;i<=n;++i) {
		int cur_k = a[i].fi+1;
		int cp = a[i].se;
		f[cp]=cp;
		size[cp]=1;
		ss.insert(1);
		seg++;
		if(f[cp-1]!=-1) {
			Merge(getf(cp-1),cp);
		}
		if(f[cp+1]!=-1) {
			Merge(getf(cp+1),cp);
		}
		auto mit=ss.begin();
		auto mait = ss.end();
		mait--;
		if(*mit==*mait&&seg>=max_seg) {
			if(seg==max_seg) {
				ans=min(ans,cur_k);
			} else {
				ans=cur_k;
			}
			max_seg=seg;
		}
	}
	Pn(ans);
}


