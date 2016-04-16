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
int pre[2][100050];
int succ[2][100050];
int a,b,n,T;
int ori[100050];
int lmax,rmax;
int ans=0;
void Pre() {
	memset(pre,0x3f,sizeof pre);
	memset(succ,0x3f,sizeof succ);
	pre[0][1]=ori[1]*b+1;
	for(int i=2;i<=n;++i) {
		pre[0][i]=pre[0][i-1]+a+ori[i]*b+1;
		if(pre[0][i]>T) {
			rmax=i;
			break;
		}
	}
	succ[0][n]=ori[n]*b+1;
	for(int i=n-1;i;--i) {
		succ[0][i]=succ[0][i+1]+a+ori[i]*b+1;
		
	}
	pre[1][1]=ori[1]*b+1;
	pre[1][n]=pre[1][1]+ori[i]*b+1+a;
	for(int i=n;i;--i) {
		
	}
}
int rSolve() {
}
int main() {
	R(n); R(a); R(b); R(T);
	for(int i=1;i<=n;++i) {
		char cmd=0; while(!isalpha(cmd)) {
			cmd=getchar();
		}
		ori[i]=(cmd=='w');
	}
	Pre();
	if(pre[0][1]>T) {
		cout<<0<<endl;
		return 0;
	} else  if(pre[0][n]<=T){
		cout<<n<<endl;
		return 0;
	}
	ans=rSolve();
	ans=max(ans,lSolve());
	ans=min(n,ans);
	cout<<ans<<endl;
}

