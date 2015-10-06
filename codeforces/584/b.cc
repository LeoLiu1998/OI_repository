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
typedef long long ll;
ll ans=0;
const ll mod=1e9+7;
long long qpow(long long a, long long b, long long c)
{
    long long ans=1;
    a=a%c;
    while(b>0)
    {
        if(b&1) ans=(ans*a)%c;
        b>>=1;
        a=(a*a)%c;
    }
    return ans;
}
int main() {
	int n;
	R(n);
	int cura=qpow(3,3*n,mod);
	int curb=qpow(7,n,mod);
	cout<<(cura-curb+mod)%mod<<endl;
}
