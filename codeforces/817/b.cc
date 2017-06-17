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
int a[300050];
int b[300050];
int cnt[5];
int n;
ll Cn3(int k) {
	ll ret=1;
	for(int i=0;i<3;++i) {
		ret*=(k-i);
	}
	ret/=6;
	return ret;
}
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		R(a[i]);
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	unique(a+1,a+n+1);
	for(int i=1;i<=n;++i) {
		if(b[i]==a[1]) cnt[1]++;
		if(b[i]==a[2]) cnt[2]++;
		if(b[i]==a[3]) cnt[3]++;
	}
	if(cnt[1]>=3) {
		cout<<Cn3(cnt[1])<<endl;
		return 0;
	} else if(cnt[1]==2) {
		cout<<cnt[2]<<endl;
	} else if(cnt[1]==1) {
		if(cnt[2]>=2) {
			cout<<(ll)cnt[2]*(cnt[2]-1)/2<<endl;
		} else {
			cout<<cnt[3]<<endl;
		}
	}
}

