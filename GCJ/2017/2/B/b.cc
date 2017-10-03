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
int cnt[3];
int cn[3][1005];
int main() {
	R(T);
	for(int i=1;i<=T;++i) {
		pii ans;
		R(n); R(c); R(m);
		memset(pos,0,sizeof pos);
		memset(b,0,sizeof b);
		memset(cn,0,sizeof cn);
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=m;++i) {
			R(pos[i]); R(b[i]);
			cnt[b[i]]++;
			cn[b[i]][pos[i]]++;
		}
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=2;++j) {
				if(!cn[j][i]) continue;
				int cur=0;
				for(int k=1;k<=n;++k) {
					if(i==k) continue;
					cur=min(cn[j][i],cn[(j+1)>2 ? 1 : 2][k]);
					ans.fi+=cur;
					cn[j][i]-=cur;
					cn[(j+1)>2 ? 1:2][k]-=cur;
				}
			}
		}
		ans.fi+=cn[1][1]+cn[2][1];
		for(int i=2;i<=n;++i) {
			ans.fi+=max(cn[1][i],cn[2][i]);
			ans.se+=min(cn[1][i],cn[2][i]);
		}
NEX:
		printf("Case #%d: %d %d\n",i,ans.fi,ans.se);
	}
}

