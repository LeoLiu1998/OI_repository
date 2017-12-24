/*
USER: yeguang2
PROB: range
LANG: C++14
*/
//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
#define rrep(name,start,end,steo) for(int name=start;name<=end;name-=step)
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
#define PROB "range"
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
char ori[255][255];
int lpre[255][255];
int upre[255][255];
int res[255][255];
int ans[255];
int n;
int main() {
	Redirect();
	R(n);
	for(int i=1;i<=n;++i) 
		scanf("%s",ori[i]+1);
	rep(i,1,n,1) {
		rep(j,1,n,1) {
			if(ori[i][j]=='0') {
				res[i][j]=upre[i][j]=lpre[i][j]=0;
			}
			else{
				lpre[i][j]=lpre[i][j-1]+1;
				upre[i][j]=upre[i-1][j]+1;
				res[i][j]=min(min(lpre[i][j],upre[i][j]),res[i-1][j-1]+1);		
			}
			rep(k,2,res[i][j],1) {
				ans[k]++;
			}
		}
	}
	rep(i,2,252,1) {
		if(ans[i]!=0) {
			Ps(i); Pn(ans[i]);
		}
	}
}


