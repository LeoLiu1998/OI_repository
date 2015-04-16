#include <cstdio>
#include <cmath>
using namespace std;
const long double pi=acos(-1.0),e=exp(1),eps=1e-10;
long double log(long double a,long double b){return log(a)/log(b);}
int n,k;
int main()
{
	while(scanf("%d%d",&n,&k)!=EOF)
		if(n<=10000)
		{
			double ans=0.0;
			for (int i=1;i<=n;i++)ans+=log(i);
			ans/=log(k);
			ans=ceil(ans+eps);
			printf("%.0lf\n",ans);
		}else printf("%lld\n",(long long)(0.5*log(2*pi*n,k)+n*log(n,k)-n*log(e,k))+1);
}