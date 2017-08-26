#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
struct sa
{
    ll l,r,len,dis;
}data[100005],res[100005];
bool cmp(sa x, sa y)
{
    if(x.l==y.l) return x.r<y.r;
    return x.l<y.l;
}
int main()
{
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&data[i].l,&data[i].r);
            if(data[i].l>data[i].r)
                swap(data[i].l,data[i].r);
        }
        if(n==1)
        {
            printf("%lld\n",data[0].r-data[0].l+1+m);
            continue;
        }
        sort(data,data+n,cmp);
//        for(int i=0;i<n;i++)
//        printf("%lld %lld*\n",data[i].l,data[i].r);
        memset(res,0,sizeof(res));
        int cnt=0;
        res[cnt++]=data[0];
        ll pos=data[0].r;
        for(int i=1;i<n;i++)
        {
            if(data[i].l<=pos)
                res[cnt-1].r=max(data[i].r,res[cnt-1].r);
            else
                res[cnt++]=data[i];
            pos=max(pos,data[i].r);
        }
//        for(int i=0;i<cnt;i++)
//        printf("%lld %lld**\n",res[i].l,res[i].r);
        ll ans=-1;
        for(int i=0;i<cnt;i++)
        {
            res[i].len=res[i].r-res[i].l+1;
            ans=max(ans,res[i].len);
        }
        for(int i=0;i<cnt-1;i++)
        {
            res[i].dis=res[i+1].l-res[i].r-1;
        }

//        for(int i=0;i<cnt;i++)
//        {
//            printf("%lld %lld\n",res[i].len,res[i].dis);
//        }
        ll mm=m;
        int posl=0,posr=0;
        ll sum=0;
        //cout<<"aaaaaaaaaaa"<<endl;
        int k=0;
        while(posr<cnt-1)
        {
            while(m>=res[posr].dis&&posr<cnt-1)
            {
                m-=res[posr].dis;
                posr++;
            }
            if(posr==cnt-1) break;
            //printf("%d %d %d\n",k++,posl,posr);
            sum=res[posr].r-res[posl].l+1;
            if(posl==0) sum+=m;
            ans=max(ans,sum);
            //printf("%d %d %d\n",k++,posl,posr);
            if(posl==posr)
            {
                posl++;
                posr++;
                m=mm;
                sum=0;
            }
            else
            {
                m+=res[posl].dis;
                posl++;
            }
        }
        sum=res[posr].r-res[posl].l+1+m;
        ans=max(ans,sum);
        //printf("%d %lld\n",posr,sum);
        printf("%lld\n",ans);
    }
    return 0;
}