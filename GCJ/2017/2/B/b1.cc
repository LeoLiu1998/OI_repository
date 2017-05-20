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
int T;
int n,c,m;
int pos[1005],b[1005];
int cnt[1003];
int cn[1003][1005];
int pre[1005];
bool check(int k) {
	for(int i=1;i<=n;++i) {
		if(pre[i]>k*i) {
			return 0;
		}
	}
	return 1;
}
int main() {
	R(T);
	for(int i=1;i<=T;++i) {
		pii ans;
		R(n); R(c); R(m);
		memset(pos,0,sizeof pos);
		memset(b,0,sizeof b);
		memset(cn,0,sizeof cn);
		memset(cnt,0,sizeof cnt);
		memset(pre,0,sizeof pre);
		for(int i=1;i<=m;++i) {
			R(pos[i]); R(b[i]);
			cnt[b[i]]++;
			cn[b[i]][pos[i]]++;
		}
		for(int i=1;i<=n;++i) {
			cnt[0]=cnt[cnt[0]]> cnt[i] ? cnt[0]:i;
			pre[i]=pre[i-1];
			for(int j=1;j<=c;++j) {
				cn[0][i]+=cn[j][i];
				pre[i]+=cn[j][i];
			}
		}
		int l=cnt[cnt[0]]-1,r=1005;
		while(r-l>1) {
			int mid=(l+r)>>1;
			if(check(mid)) {
				r=mid;
			} else {
				l=mid;
			}
		}
		ans.fi=r;
		for(int i=1;i<=n;++i) {
			ans.se+=max(0,cn[0][i]-ans.fi);//cn[i][0]-ans.fi;
		}
		printf("Case #%d: %d %d\n",i,ans.fi,ans.se);
	}
}

