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
const int maxn=200050;
int next[maxn];int n,m;
int f[maxn];
void init(){
	for(int i=1;i<=n;++i){
		next[i]=f[i]=i;
	}
}
int getf(int x) {
	if(f[x]==x) return x;
	f[x]=getf(f[x]);
	return f[x];
}
inline void Merge(int x,int y) {
	int fx=getf(x),fy=getf(y);
	f[fx]=f[fy]=min(fx,fy);
}
inline void MergeS(int l,int r) {
	if(l>r) swap(l,r);
	for(int i=l+1;i<=r;++i) {
		Merge(i-1,i);
	}
}
void Query(int x,int y) {
	int fx=getf(x); int fy=getf(y);
	printf(fx==fy ? "YES\n" : "NO\n");
	return ;
}

int main() {
	R(n); R(m);
	init();
	int cmd,x,y;
	while(m--) {
		R(cmd); R(x); R(y);
		if(cmd==1) {
			Merge(x,y);
		} else if(cmd==2) {
			MergeS(x,y);
		} else {
			Query(x,y);
		}
 	}
}