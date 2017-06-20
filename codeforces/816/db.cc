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
const int LEN=100;
struct Num{
	int a[LEN];
	Num() {
		memset(a,0,sizeof a);
	}
	Num operator + (const Num &x) const {
		Num ret;
		for(int i=1;i<LEN;++i) {
			ret.a[i]=a[i]+x.a[i];
		}
		return ret;
	}
	Num operator -(const Num &x) const {
		Num ret;
		for(int i=1;i<LEN;++i) {
			ret.a[i]=a[i]-x.a[i];
		}
		return ret;
	}
};
Num num[2][105];
int n;
int sta=1;
int main() {
	int T; R(T);
	for(int n=4;n<=T;n+=4) {
	memset(num,0,sizeof num);
	int cur=1,nex=0;
	for(int i=1;i<=n;++i) {
		num[cur][i].a[i]=1;
	}
	for(int i=1;i<n;++i) {
		for(int j=1;j<=n-i;++j) {
			sta^=1;
			if(sta==1) {
				num[nex][j]=num[cur][j]+num[cur][j+1];
			} else {
				num[nex][j]=num[cur][j]-num[cur][j+1];
			}
		}
		cur^=1;
		nex^=1;
	}
	for(int i=1;i<=n;i+=1) {
		printf("%4d ",num[cur][1].a[i]);
	}
	puts("");
	}
}

