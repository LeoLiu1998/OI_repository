/*ID: yeguang2
PROG:combo
LANG:C++
 */
//This sourcecode is under GPLv3
//yeguanghao
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
int n;
int a[2][3];
int cur[3];
int ans=0;
int d(int x,int y){
	int mi=min(x,y),ma=max(x,y);
	return min(ma-mi,mi+n-ma);
}
bool check(int x,int y,int z,int k) {
	int d1=d(x,a[k][0]);
	int d2=d(y,a[k][1]);
	int d3=d(z,a[k][2]);
	if(d1<=2&&d2<=2&&d3<=2) return 1;
	return 0;
}
#define PROB "combo"
int main() {
	freopen(PROB".in","r",stdin);
	freopen(PROB ".out","w",stdout);
	R(n);
	rep(i,0,1,1) {
		rep(j,0,2,1) {
			R(a[i][j]);
		}
	}
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			for(int k=1;k<=n;++k) {
				ans+=(check(i,j,k,0)||check(i,j,k,1));
			}
		}
	}
	Pn(ans);
}
