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
const int maxn=1005;
char s[maxn],t[maxn];
int n,m;
int ans=INT_MAX;
vector<int> an,cu;
int main() {
	R(n); R(m);
	scanf("%s",s+1);
	scanf("%s",t+1);
	for(int i=1;i<=m;++i) {
		int cur=0;
		cu.clear();
		if(i+n-1>m) continue;
		for(int j=1;j<=n;++j) {
			if(t[i-1+j]!=s[j]) {
				cur++;
				cu.pb(j);
			}
		}
		if(ans>cur) {
			ans=cur;
			swap(an,cu);
		}
	}
	Pn(ans);
	for(int i=1;i<=ans;++i) {
		Ps(an[i-1]);
	}
	puts("");
}

