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
int co[10];
int n;
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		int t; R(t);
		if(t>=3200)  {
			co[9]+=1;
			continue;
		} else {
			t/=400;
			co[t]=1;
		}
	}
	int cnt=0;
	for(int i=0;i<=9;++i) {
		cnt+=co[i];
	}
	if(cnt==co[9]) {
		Ps(1);
	} else if(cnt>=2&&co[9]) {
		Ps(cnt-co[9]);
	} else {
		Ps(cnt);
	}
	Pn(cnt);
}

