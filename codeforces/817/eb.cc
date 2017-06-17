#include<bits/stdc++.h>
using namespace std;
#define maxn 3001000
int ch[maxn][2];
int val[maxn];
int tot;
int bit[30];
int rt;
void update(int x,int v)
{
    for(int i=0;i<30;++i)
    {
        bit[i]=x&1;
        x>>=1;
    }
    int now=0;
    for(int i=29;i>=0;--i)
    {
        val[now]+=v;
        int c=bit[i];
        if(ch[now][c]==-1) ch[now][c]=++tot;
        now=ch[now][c];
    }
    val[now]+=v;
}
int b2[30];
int query(int x,int y)
{
    for(int i=0;i<30;++i)
    {
        bit[i]=x&1;
        x>>=1;
        b2[i]=y&1;
        y>>=1;
    }
    int ans=0;
    int now=0;
    for(int i=29;i>=0;--i)
    {
        if(now==-1) break;
        if(!b2[i])
        {
            now=ch[now][bit[i]];
        }
        else
        {
            if(ch[now][bit[i]]!=-1)
                ans+=val[ch[now][bit[i]]];
            now=ch[now][bit[i]^1];
        }
    }
    return ans;
}
int main()
{
    int q;
    int op,x,y;
    scanf("%d",&q);
    rt=tot;
    memset(ch,-1,sizeof(ch));
    while(q--)
    {
        scanf("%d%d",&op,&x);
        if(op==1) update(x,1);
        else if(op==2)update(x,-1);
        else
        {
            scanf("%d",&y);
            printf("%d\n",query(x,y));
        }
    }
    return 0;
}
