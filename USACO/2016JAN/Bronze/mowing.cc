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
#define PROB "mowing"
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
void Redirect() {
	freopen(PROB".in","r",stdin);
#ifndef YGHDEBUG
	freopen(PROB".out","w",stdout);
#endif
}
map<char,pii> mov;
map<pii,int> tik;
pii pos=mp(0,0);
int ans=INT_MAX;
int cur;
int n;
pii add(pii a,pii b) {
	pii ret; ret.fi=a.fi+b.fi;
	ret.se=a.se+b.se;
	return ret;
}
void Move(char cmd) {
	cur++;
	pos=add(pos,mov[cmd]);
	if(tik[pos]==0) {
		tik[pos]=cur;
	} else {
		int delta=cur-tik[pos];
		ans=min(ans,delta);
		tik[pos]=cur;
	}
}
int main() {
	Redirect();
	mov['N']=mp(0,1); mov['S']=mp(0,-1); mov['W']=mp(-1,0); mov['E']=mp(1,0);
	R(n);
	tik[pos]=1; cur=1;
	for(int i=1;i<=n;++i) {
		char cmd=0;
		while((!isalpha(cmd))) cmd=getchar();
		int k; R(k);
		for(int j=1;j<=k;j++) {
			Move(cmd);
		}
	}
	if(ans==INT_MAX) {
		puts("-1");
	} else {
		Pn(ans);
	}
}



