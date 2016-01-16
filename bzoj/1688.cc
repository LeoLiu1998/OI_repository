//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=1005;
bitset<17> cow[maxn];
int n,d,k;
int main() {
	R(n); R(d); R(k);
	for(int i=1;i<=n;++i) {
		cow[i].reset();
		int t,smg; R(t);
		while(t--) {
			R(smg);
			cow[i].set(smg-1);
		}
	}
	int ans=0;
	for(int i=1;i<(1<<d);++i) {
		int t=0;
		bitset<17> s(i);
		if(s.count()>k) continue;
		for(int j=1;j<=n;++j) {
			if((cow[j]|s)==s) t++;
		}
		ans=max(ans,t);
	}
	Pn(ans);
}

