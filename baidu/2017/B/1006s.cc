#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int anc[5];
struct splay_node
{
    int num,maxx,ls,rs,fath;
    bool lazy;
}p[5];
struct lct
{
    inline void _pushdown(int i)
    {
        p[i].lazy^=1;
        p[p[i].ls].lazy^=1;
        p[p[i].rs].lazy^=1;
        int t=p[i].ls;p[i].ls=p[i].rs;p[i].rs=t;
    }
    inline void _pushup(int i)
    {
        p[i].maxx=max(max(p[p[i].ls].maxx,p[p[i].rs].maxx),p[i].num);
    }
    inline void _zig(int i)
    {
        int j=p[i].fath,k;
        k=p[j].fath;
        if(k!=0&&j==p[k].ls)p[k].ls=i;
        else if(k!=0)p[k].rs=i;
        p[i].fath=k;
        p[j].fath=i;
        p[p[i].rs].fath=j;
        p[j].ls=p[i].rs;
        p[i].rs=j;
        anc[i]=anc[j];
        p[i].maxx=p[j].maxx;
        _pushup(j);
    }
    inline void _zag(int i)
    {
        int j=p[i].fath,k;
        k=p[j].fath;
        if(k!=0&&j==p[k].ls)p[k].ls=i;
        else if(k!=0)p[k].rs=i;
        p[i].fath=k;
        p[j].fath=i;
        p[p[i].ls].fath=j;
        p[j].rs=p[i].ls;
        p[i].ls=j;
        anc[i]=anc[j];
        p[i].maxx=p[j].maxx;
        _pushup(j);
    }
    void _splay(int i)
    {
        int j;
        while(p[i].fath!=0)
        {
            j=p[i].fath;
            if(p[p[j].fath].lazy==true)_pushdown(p[j].fath);
            if(p[j].lazy==true)_pushdown(j);
            if(p[i].lazy==true)_pushdown(i);
            if(p[j].fath==0)
            {
                if(i==p[j].ls)_zig(i);
                else _zag(i);
            }
            else if(j==p[p[j].fath].ls)
            {
                if(i==p[j].ls)_zig(j),_zig(i);
                else _zag(i),_zig(i);
            }
            else
            {
                if(i==p[j].rs)_zag(j),_zag(i);
                else _zig(i),_zag(i);
            }
        }
    }
    int _find_max(int i)
    {
        while(i!=0)
        {
            if(p[i].lazy==true)_pushdown(i);
            if(p[i].ls!=0&&p[i].maxx==p[p[i].ls].maxx)i=p[i].ls;
            else if(p[i].maxx==p[i].num)return i;
            else i=p[i].rs;
        }
        return i;
    }
    void _access(int i)
    {
        int j=0;
        while(i!=0)
        {
            _splay(i);
            if(p[i].lazy==true)_pushdown(i);
            if(p[i].rs!=0)
            {
                p[p[i].rs].fath=0;
                anc[p[i].rs]=i;
            }
            p[i].rs=j;
            p[j].fath=i;
            _pushup(i);
            j=i;i=anc[i];
        }
    }
    void _setroot(int i)
    {
        _access(i);
        _splay(i);
        p[i].lazy^=1;
    }
}T;
#define mod 1000000007
struct node{
	int l,r;
}cun[100005],cun2[100005];
int cmp(node a,node b)
{
	return a.l==b.l?a.r<b.r:a.l<b.l;
}
int vis[100005],len[100005],jian[100005];
int n,m;
int cnt;
void init()
{
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++) scanf("%d%d",&cun[i].l,&cun[i].r);
	sort(cun,cun+n,cmp);
	int pos=0;
	for(int i=1;i<n;i++)
	{
		if(cun[i].l<=cun[pos].r)
		{
			vis[i]=1;
			cun[pos].r=max(cun[i].r,cun[pos].r);
		}
		else pos++;
	}
	cnt=0;
	for(int i=0;i<n;i++)
	{
		if(!vis[i]) cun2[cnt++]=cun[i];
	}
	for(int i=1;i<=cnt;i++) len[i]=cun2[i-1].r-cun2[i-1].l+1;
	len[0]=0;
	jian[0]=cun2[0].l-1;
	for(int i=1;i<cnt;i++)
		jian[i]=cun2[i].l-cun2[i-1].r-1;
	jian[cnt]=mod;
}
void work()
{
	int sum=0,pos=0,ans=0,zui=0;
	for(int i=0;i<=cnt;i++)
	{
		sum+=jian[i];
		if(sum<=m)
		zui=max(zui,ans+len[i]);
		ans+=len[i]+jian[i];
		//cout<<len[i]<<" "<<jian[i]<<endl;
		//cout<<sum<<" "<<ans<<endl;
		while(sum>m&&pos<=i)
		{
			sum-=jian[pos];
			ans-=jian[pos]+len[pos];
			//if(sum<m) ans+=m-sum;
			if(sum<=m)
			{
				zui=max(zui,ans+m-sum+len[pos]);
			}
			pos++;
		}
		zui=max(ans,zui);
		//cout<<sum<<" "<<zui<<endl;
	}
	printf("%I64d\n",zui);
}
int main(){
	while(~scanf("%d%d",&n,&m))
	{
		init();
		work();
	}
	return 0;
}
