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
bool f[55][1005];
int ans=-5466;
int begin;
int high;
int n;
int delta;
int main(){
	R(n); R(begin); R(high);
	f[0][begin]=1;
	rep(i,1,n,1) {
		R(delta);
		int   flag=0;
		rep(j,0,high,1) {	
			if(!f[i-1][j]) continue;
			if(j+delta<=high) {
				flag=1;
				f[i][j+delta]=1;
			} if(j-delta>=0) {
				flag=1;
				f[i][j-delta]=1;
			}
		}
		if(!flag) {
			puts("-1");
			return 0;
		}
	}
	for(int i=0;i<=high;++i) {
		if(f[n][i]) {
			ans=max(ans,i);
		}
	}
	Pn(ans);
}
