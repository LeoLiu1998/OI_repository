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
int pre[1505][27];
int ans[1505][27];
int n;
int a[1505];
bool check(int col,int pos,int l,int cost) {
	if(pos+l-1>n) return 0;
	return (pre[min(pos+l-1,n)][col]-pre[pos-1][col])<=cost;
}
int main() {
	memset(ans,-1,sizeof ans);
	R(n);
	for(int i=1;i<=n;++i) {
		char ch=0; while(!isalpha(ch))ch=getchar();
		a[i]=ch-'a'+1;
	}
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=26;++j) {
			if(a[i]==j) {
				pre[i][j]=pre[i-1][j];
			} else {
				pre[i][j]=pre[i-1][j]+1;
			}
		}
	}
	int t; R(t);
	while(t--) {
		int p,c; R(p);
		char ch=0; while(!isalpha(ch)) ch=getchar();
		c=ch-'a'+1;
		if(ans[p][c]!=-1) {
			Pn(ans[p][c]);
			continue;
		} 
		if(check(c,1,n,p)) {
			for(int i=p;i<=n;++i) {
				ans[i][c]=n;
			}
			Pn(ans[p][c]); 
			continue;

		} else {
			int an=0;
			for(int i=n;i;--i) {
				int l=0,r=n;
				while(r-l>1) {
					int mid=(l+r)>>1;
					if(check(c,i,mid,p)) l=mid;
					else r=mid;
				}
				an=max(an,l);
			}
			ans[p][c]=an;
			Pn(ans[p][c]);
		}
	}
}

