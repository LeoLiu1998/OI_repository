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
vector<int> v[27];
char a[1505],b[1505];
int la,lb;
int lis[10005];
int pos[10005];
int main() {
	while(~scanf("%s %s",a+1,b+1)) {
		la=strlen(a+1);
		lb=strlen(b+1);
		for(int i=0;i<=26;++i) v[i].clear();
		for(int i=1;i<=lb;++i) {
			v[b[i]-'a'+1].pb(i);
		}
		for(int i=1;i<=la;++i) {
			
		}
	}
}

