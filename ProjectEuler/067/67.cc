//7273
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
int a[150][150];
int ans[150][150];
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int n;
int main() {
	R(n);
	rep(i,1,n,1) {
		rep(j,1,i,1) {
			R(a[i][j]);
		}
	}
	int out=0;
	rep(i,1,n,1) {
		rep(j,1,i,1) {
			ans[i][j]=a[i][j]+max(ans[i-1][j],ans[i-1][j-1]);
			out=max(out,ans[i][j])	;//			cout<<ans[i][j]<<" ";
		}
//		cout<<endl;
	}
	cout<<out<<endl;
}
	
