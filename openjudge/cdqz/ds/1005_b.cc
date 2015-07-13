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
const int maxn=100005;
int a[maxn];
int n,m;
int main() {
	R(n); R(m);
	rep(i,1,n,1) R(a[i]);
	char cmd;
	while(m--){
		cmd=0;
		int l,r; 
		while(!isalpha(cmd)) cmd=getchar();
		R(l); R(r);
		if(cmd=='M') {
			int v; R(v);
			rep(j,l,r,1) a[j]=v;
		} else  {
			int	ret=0;
			rep(i,l,r,1) ret+=a[i];
			Pn(ret);
		}
	}
}
