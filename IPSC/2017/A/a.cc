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
int r,c;
int main() {
	R(T);
	while(T--)  {
		cin>>r>>c;
		if(r==c) {
			Pn(r);
			for(int i=0;i<r;++i) {
				Ps(i); Pn(i);
			}
		} else if(r>c) {
			Pn(c+ (r-c+1)/2);
			for(int i=0;i<c;++i) {
				Ps(i); Pn(i);
			}
			for(int i=c;i<r;++i) {
				if(((i-c)%2)||(i==r-1)) {
					Ps(i); Pn(0);
				}
			}
		} else {
			Pn(r+(c-r+1)/2);
			for(int i=0;i<r;++i) {
				Ps(i); Pn(i);
			}
			for(int i=r;i<c;++i) {
				if(((i-r)%2)||(i==c-1)) {
					Ps(0); Pn(i);
				}
			}
		}
	}
}

