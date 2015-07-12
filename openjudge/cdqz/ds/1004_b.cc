#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;

#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
typedef long long ll;
inline void R(ll &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
}
int n,m;
const int maxn=100;
ll a[maxn];
const ll Kmod=1000000007; 
void QueryAll(int l,int r) {
	ll ret=0;
	rep(i,l,r,1) {
		rep(j,i+1,r,1) {
			ret+=a[i]*a[j];		
			ret%=Kmod;
		}
	}
	printf("%lld\n",ret);
}

void QueryAdj(int l,int r) {
	ll ret=0;
	rep(i,l,r-1,1){
		ret+=a[i]*a[i+1];
		ret%=Kmod;
	}
	printf("%lld\n",ret);
}
int main() {
	R(n); R(m);
	rep(i,1,n,1) {
		R(a[i]);
	}
	char cmd=0;
	while(m--) {
		cmd=0;
		while(!isalpha(cmd)) cmd=getchar();
		if(cmd=='M') {
			int pos,v;
			R(pos); R(v);
			a[pos]=v;
		} else if(cmd=='Q') {
			int l,r; R(l);R(r);
			QueryAll(l,r);
		} else {
			int l,r;
			R(l); R(r);
			QueryAdj(l,r);
		}
	}
}
