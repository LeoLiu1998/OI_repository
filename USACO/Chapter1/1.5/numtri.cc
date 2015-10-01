/*ID:yeguang2
PROG:numtri
LANG:C++
*/
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
#define min max
const int maxn=1005;
int a[maxn][maxn];
int n;
int main() {
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	R(n);
//	memset(a,0x3f,sizeof(a));
	rep(i,1,n,1) {
		rep(j,1,i,1) {
			R(a[i][j]);
			a[i][j]+=min(a[i-1][j],a[i-1][j-1]);
//			Ps(a[i][j]);
		}
//		puts("");
	}
	int ans=-4352;
	rep(i,1,n,1) {
		ans=min(a[n][i],ans);
	}
	Pn(ans);
}
