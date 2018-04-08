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
bool done[1005];
bool field[1005][5];

int main() {
	int T;
	R(T);
	rep(qwq,1,T,1) {
		int A; R(A);
		memset(done,0,sizeof done);
		memset(field,0,sizeof done);
		int n = A/3+(A%3!=0)+2;
		while(1) {
			for(int i=1;i<=n;++i) {
				if(!done[i]) {
					Ps(min(i+1,n-1)); Pn(2);
					fflush(stdout);
					int dx,dy; R(dx); R(dy);
					if(dx==0&&dy==0) goto NEXT;
					if(dx==-1&&dy==-1) goto NEXT;
					field[dx][dy]=1;
					done[dx]=field[dx][1]&&field[dx][2]&&field[dx][3];
				}
			}
		}
NEXT:
		continue;
	}
}


