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
const int maxn=200000;
int n,sum;
double a[maxn+5];
int main(){
	R(n); R(sum);
	rep(i,1,(n<<1),1) scanf("%lf",&a[i]); 
	sort(a+1,a+n+n+1);
	double ans=min(a[n+1],a[1]*2)*1.5;
	ans*=n;
	if(ans>sum) ans=sum;//ans=min(ans,double(sum));
	printf("%.6f\n",ans);	
}
