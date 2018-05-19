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
int T;
ll a[10],d;
ll b[10];
void Brute() {
	ll ans=0;
	for(int i=0;i<=d;++i) {
		for(int j=0;j<=d;++j) {
			if(i+j>d) break;
			b[1]=a[1]+i;
			b[2]=a[2]+j;
			b[3]=a[3]+(d-i-j);
			sort(b+1,b+4);
			ans=max(ans,b[1]*b[1]+b[2]*b[2]+b[3]*b[3]+7*b[1]);
		}
	}
	cout<<ans<<endl;
}
int main() {
	R(T);
	while(T--) {
		rep(i,1,3,1) cin>>a[i];
		cin>>d;
		sort(a+1,a+4);
		if(a[3]<=100&&d<=100) {
			Brute();
		} else {
			a[3]+=d;
			cout<<(a[1]*a[1]+a[2]*a[2]+a[3]*a[3]+7*a[1])<<endl;
		}
	}
}


