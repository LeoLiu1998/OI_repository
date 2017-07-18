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
int a[2005],b[2005],s[2005];
int k,n;
set<int> ans;
int main() {
	R(k); R(n);
	rep(i,1,k,1) {
		R(a[i]);
		s[i]=s[i-1]+a[i];
	}
	sort(s+1,s+k+1);
	rep(i,1,n,1) {
		R(b[i]);
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=k;++i) { // b[1] = a[k]
		if(i+n-1>k) break ;
		int cur=b[1]-s[i];
		int cp=1;
		for(int j=1;j<=n;++j) {
			int cv=b[j]-b[1]+s[i];
			int pos=lower_bound(s+cp,s+k+1,cv)-s;
			if(s[pos]!=cv) {
				goto NEX;
			} else {
				cp=pos+1;
			}
		}
		ans.insert(cur);
NEX:
		continue;
	}
	Pn(ans.size());
}

