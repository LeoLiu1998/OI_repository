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
int ans;
int a[8];
int main()
{
	int s,ans;
	for(int i=0;i<6;i++)
    		R(a[i]);
	s=a[0]+a[1]+a[2];
   	ans=s*s-(a[0]*a[0]+a[2]*a[2]+a[4]*a[4]);
    	Pn(ans);
	return 0;
}
