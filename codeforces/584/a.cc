//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const int maxn=50;
bool v[maxn+1];
bool h[maxn+1];
int n;
int main() {
	R(n);
	for(int i=1,a,b;i<=n*n;++i) {
		R(a); R(b);
		if(h[a]==0&&v[b]==0) {
			h[a]=v[b]=1;
			Ps(i);
		}
	}
}
