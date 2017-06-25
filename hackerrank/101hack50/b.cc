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
int n;
const int maxn=100050;
int a[maxn];
ll sum=0;
int ans=0;
int cnt1,cnt2;
int main() {
	R(T);
	while(T--) {
		R(n);
		sum=0;
		ans=0;
		cnt1=cnt2=0;
		for(int i=1;i<=n;++i) {
			R(a[i]);
			sum+=a[i];
			if(a[i]%2==i%2) {
				if(a[i]==1) cnt1++;
				else cnt2++;
			}
		}
		ll on=n/2;
		if(sum<on+(n-on)*2) {
			Pn(-1);
			continue;
		}
		if(on%2!=sum%2) {
			Pn(-1);
			continue;
		}
		ans+=min(cnt1,cnt2);
		cnt1-=ans;
		cnt2-=ans;
		if(cnt1) {
			ans+=cnt1;
		} else {
			ans+=(cnt2+1)/2;
		}
		Pn(ans);
	}
}

