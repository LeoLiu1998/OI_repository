//ans :137846528820
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
ll a[50][50];
int main() {
	int n=25;
	a[1][1]=1;
	rep(i,1,n,1) {
		rep(j,1,n,1) {
			a[i][j]=a[i-1][j]+a[i][j-1];
			a[1][1]=1;
		}
	}
	cout<<a[21][21]<<endl;
}
