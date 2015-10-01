//This sourcecode is under GPLv3
//yeguanghao
#include <cstdlib>
#include <cstdio>
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
const int maxk=10000000;
int a[maxk+10];
int pre[maxk+10];
int n;
int m;
int l,r;
int main() {
	R(n); R(m);
	while(n--)  {
		R(l); a[l]++;
	}
	pre[0]=a[0];
	for(int i=1;i<=maxk;++i) {
		pre[i]=a[i]+pre[i-1];
	}
	while(m--) {
		R(l); R(r);
		Pn(pre[r]-pre[l-1]);
	}
}
