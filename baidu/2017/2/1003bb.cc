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
int a[1005];
int n;
bool check() {
	for(int i=2;i<=n;++i) {
		if(a[i]%2==1) {
			int del=a[i]-a[i-1];
			if((del>=-2)&&(del<=3)) continue;
			return -1;
		} else {
			int del=a[i]-a[i-1];
			if((del<=2)&&(del>=-3)) continue;
			return -1;
		}
	}
	return 1;
}
ll ans=0;

void Solve() {
do {
		ans+=check();
		continue;
	}while(next_permutation(a+1,a+n+1));
}
int main() {
	
	R(n); n*=2;
	for(int i=1;i<=n;++i) 
		a[i]=i;

	cout<<ans<<endl;
}

