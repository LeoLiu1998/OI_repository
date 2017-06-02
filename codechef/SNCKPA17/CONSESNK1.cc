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
int n,l,a,b;
const int maxn=100050;
int p[maxn];
int del[maxn];
ll ans=0;
ll tl=0;
int cnt[3];
ll mv;
int main() {
	R(T);
	while(T--) {
		ans=0;
		mv=0;
		memset(cnt,0,sizeof cnt);
		R(n); R(l); R(a); R(b);	
		tl=(ll)l*(n-1);
		ll rr=b-tl;
		for(int i=1;i<=n;++i) {
			R(p[i]);
		}
		sort(p+1,p+n+1);
		for(int i=1;i<=n;++i) {
			del[i]=(p[i]-p[1])-l*(i-1);
			ans+=abs(del[i]);
			if(!del[i]) cnt[1]++;
			else if(del[i]>0) cnt[2]++;
			else cnt[0]++;
		}
		sort(del+1,del+n+1);
		if(p[1]<=rr&&p[1]>=a) {
			cout<<ans<<endl;
			continue;
		} else if(p[1]<a) {
			mv=((ll)a-p[1])*((ll)cnt[2]+cnt[1]-cnt[0]);
		} else {
			mv=min(mv,((ll)p[1]-rr)*((ll)cnt[0]+cnt[1]-cnt[2]));
		}
		ans+=mv;
		//ans+=(ll)min(abs(rr-p[1]),abs((ll)a-p[1]))*n;
		cout<<ans<<endl;
	}
}

