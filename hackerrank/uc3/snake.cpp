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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int val[65][65];
map<char,pii> dir;
map<char,string> pref;
int n;
pii operator + (const pii &a, const pii &b) {
	pii ret=mp(a.fi+b.fi,a.se+b.se);
	return ret;
}

bool valid(pii pos) {
	return (pos.fi>=0)&&(pos.se>=0)&&(pos.fi<n)&&(pos.se<n);
}

char wind;
pii pos;

int main() {
	dir['n']=mp(-1,0);
	dir['s']=mp(1,0);
	dir['e']=mp(0,1);
	dir['w']=mp(0,-1);
	pref['n']="nwes";
	pref['s']="swen";
	pref['e']="ensw";
	pref['w']="wnse";
	R(n);	
	while(!isalpha(wind)) wind=getchar();
	R(pos.fi); R(pos.se);
	for(int i=1;i<=n*n;++i) {
		val[pos.fi][pos.se]=i;
		pii nex;
		for(int k=0;k<4;++k) {
			pii mov=dir[pref[wind][k]];
			nex=pos+mov;
			if(valid(nex)) {
				if(!val[nex.fi][nex.se]) break;
			}
		}
		pos=nex;
	}
	for(int i=0;i<n;++i) {
		for(int j=0;j<n;++j) {
			Ps(val[i][j]);
		}
		puts("");
	}


}
