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

typedef unsigned long long LL;
const int S=25; 
LL modular_multi(LL x,LL y,LL mo)
{
	LL t;
	x%=mo;
	for(t=0;y;x=(x<<1)%mo,y>>=1)
		if (y&1)
			t=(t+x)%mo;
	return t;
}
 
LL modular_exp(LL num,LL t,LL mo)
{
	LL ret=1,temp=num%mo;
	for(;t;t>>=1,temp=modular_multi(temp,temp,mo))
		if (t&1)
			ret=modular_multi(ret,temp,mo);
	return ret;
}
bool sqrt_prime(LL);
bool miller_rabbin(const LL &n)
{
	if (n==2)return true;
	if (n<2||!(n&1))return false;
	int t=0;
	LL a,x,y,u=n-1;
	while((u&1)==0) t++,u>>=1;
	for(int i=0;i<S;i++)
	{
		a=rand()%(n-1)+1;
		x=modular_exp(a,u,n);
		for(int j=0;j<t;j++)
		{
			y=modular_multi(x,x,n);
			if (y==1&&x!=1&&x!=n-1)
				return false;
			x=y;
		}
		if (x!=1)///根据费马小定理,若n是素数，有a^(n-1)≡1(mod n).因此n不可能是素数
			return false;
	}
	return sqrt_prime(n);
}
bool sqrt_prime(LL a) {
	for(LL i=2;i*i<=a;++i) {
		if(a%i==0) return 0;
	}
	return 1;
}
vector<LL> ans;
LL a;
int main() {
	srand(time(NULL));
	cin>>a;
	if(miller_rabbin(a)) {
		cout<<1<<endl<<a<<endl;
		return 0;
	}
	ans.pb(3);
	a-=3;
	LL mid=a>>1;
	for(int i=mid;;++i) {
		if(miller_rabbin(i)&&miller_rabbin(a-i)) {
			ans.pb(i); ans.pb(a-i);
			break;
		}
	}
	Pn((int)ans.size());
	for(int i=0;i<(int)ans.size();++i) {
		cout<<ans[i]<<" ";
	}
}
