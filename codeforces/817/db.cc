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
int a[100000];
int n;
ll ans;
ll man,mix;
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		R(a[i]);
		for(int l=1;l<=i;++l) {
			int ma=0,mi=INT_MAX;
			for(int k=l;k<=i;++k) {
				ma=max(ma,a[k]);
				mi=min(mi,a[k]);
			}
			ans=ans+ma-mi;
			man+=ma;
			mix+=mi;
		}
	}
	cout<<man<<endl<<mix<<endl;
	cout<<ans<<endl;
}

