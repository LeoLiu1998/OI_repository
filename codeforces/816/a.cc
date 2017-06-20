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
pii Nex(pii l) {
	l.se+=1;
	l.fi+= l.se/60;
	l.se%=60;
	l.fi%=24;
	return l;
}
bool Check(pii cur) {
	if((cur.fi%10)==(cur.se/10)) {
		if((cur.se%10)==(cur.fi/10)) {
			return 1;
		}
	}
	return 0;
}
pii x;
int ans=0;
int main() {
	R(x.fi); R(x.se);
	while(!Check(x)) {
		ans++;
		x=Nex(x);
	}
	cout<<ans<<endl;
}

