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
const int mod=1000000007;
typedef long long LL;
int n,num[6],f[16][16][16][16][16][6];
bool vis[16][16][16][16][16][6];
LL dp(int a,int b,int c,int d,int e,int last)
{
	if(vis[a][b][c][d][e][last])
		return f[a][b][c][d][e][last];
	vis[a][b][c][d][e][last]=true;
	if(!(a+b+c+d+e))
		return f[a][b][c][d][e][last]=1;
	LL ans=0;
	if(a)
		ans=(ans+(a-(last==2))*dp(a-1,b,c,d,e,1))%mod;
	if(b)
		ans=(ans+(b-(last==3))*dp(a+1,b-1,c,d,e,2))%mod;
	if(c)
		ans=(ans+(c-(last==4))*dp(a,b+1,c-1,d,e,3))%mod;
	if(d)
		ans=(ans+(d-(last==5))*dp(a,b,c+1,d-1,e,4))%mod;
	if(e)
		ans=(ans+e*dp(a,b,c,d+1,e-1,5))%mod;
	return f[a][b][c][d][e][last]=ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int c;
		R(c);
		num[c]++;
	}
	printf("%lld\n",dp(num[1],num[2],num[3],num[4],num[5],0));
	return 0;
}
