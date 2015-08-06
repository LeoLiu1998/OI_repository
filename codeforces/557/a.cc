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
typedef pair<int,int> pi;
pi a[5];
#define mp make_pair
#define pb push_back
#define fi first
#define se second
inline pi getpi(){
	int a,b;
	R(a); R(b); 
	return mp(a,b);
}
int n;
int ans[5];
int main() {
	R(n);
	rep(i,1,3,1) a[i]=getpi(); 
	ans[1]=min(a[1].se,n-a[3].fi-a[2].fi);
	ans[2]=min(a[2].se,n-a[3].fi-ans[1]);
	ans[3]=n-ans[1]-ans[2];
	rep(i,1,2,1) Ps(ans[i]);
	Pn(ans[3]);

}
