#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<climits>
using namespace std;
typedef long long ll;
ll a[150000];
ll b[150000];
ll n,k,p;
ll Slove(ll mid)
{
    ll output=0;
    ll now=1;
    for(ll i=1;i<=n;i++)
    {
        while(now<=k&&abs(b[now]-a[i])+abs(b[now]-p)>mid)
        {
            now++;
        }
        if(now<=k)
        {
            now++;
            output++;
        }
        else break;
    }
    if(output>=n)return 1;
    else return 0;
}
int main()
{
    while(~scanf("%I64d%I64d%I64d",&n,&k,&p))
    {
        for(ll i=1;i<=n;i++)scanf("%I64d",&a[i]);
        for(ll i=1;i<=k;i++)scanf("%I64d",&b[i]);
        sort(a+1,a+1+n);
        sort(b+1,b+1+k);
        ll ans=-1;
        ll l=0;
        ll r=2000000000+50;
        while(r>=l)
        {
            ll mid=(l+r)/2;
            if(Slove(mid)==1)
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        printf("%I64d\n",ans);
    }
}
