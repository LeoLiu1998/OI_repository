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
ll dp[20][10]; // leng mod 9
void init() {
	for(int i=0;i<=8;++i) {
		dp[1][i] = 1;
	}
	for(int i=2;i<=18;++i) {
		for(int j=0;j<=8;++j) {
			for(int k=0;k<=8;++k) {
				if((j+k)%9==0) continue;
				dp[i][(j+k)%9]+=dp[i-1][k];
			}
		}
	}
}

ll solve(ll k) {
	ll d[20];
	int len=0;
	while(k) {
		d[++len]=k%10;
		k/=10;
	}
	ll ans=0;
	int sum=0;
	for(int i=len;i;--i) {
		for(int j=0;j<d[i];++j) {
			for(int k=0;k<=8;++k) {
				if((sum+j+k)%9==0) continue;
				ans+=dp[i-1][k];
			}
		}
		if(i==1) {
			for(int j=0;j<=d[i];++j) {
				if((sum+j)%9!=0)
					ans++;
			}
		}
		sum+=d[i];
	}
	return ans;
}

bool check(int k) {
	if(k%9==0) return 0;
	while(k) {
		if(k%10==9) return 0;
		k/=10;
	}
	return 1;
}

ll solve(int l, int r) {
	ll ret=0;
	for(int i=l;i<=r;++i) {
		ret+=check(i);
	}
	return ret;
}

int main() {
	init();
	int T;
	R(T);
	for(int i=1;i<=T;++i) {
		ll l,r;
		cin>>l>>r;
		printf("Case #%d: %lld\n",i,solve(l,r));
	}
}


