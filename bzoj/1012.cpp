//Copyright (c)2015 Yueguanghan
//This sourcecode is licensed under GPLv3
#include<iostream>
#include<cstdio>
#include<iomanip>
#include<climits>
#include<cmath>
#include<set>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<cctype>
using namespace std;
inline int lowbit(int &x)
{
    return x&(-x);
}
inline void Read(int &x)
{
    char ch=getchar();
    while (ch<'0'||ch>'9') ch=getchar();
    x=0;
    while (ch<='9' && ch>='0')
    {
        x*=10,x+=ch-'0';
        ch=getchar();
    }
}
struct item{
	int num;
    int maxn;
};
item BIT[200005];
int cnt=0;
void add();
int query(int,int);
int mod_num;
int t=0;
int main()
{
   // freopen("in.txt","r",stdin);
	int m;
    Read(m);
    Read(mod_num);
    char manu;
    while(m--)
    {
        while(manu=getchar())
		if(manu=='A'||manu=='Q')
			break;
        if(manu=='A')
			add();
		else {
				int l;
			Read(l);
			printf("%d\n",t=query(cnt-l+1,cnt));
		}
    }
}
int query(int l,int r)
{
	int ret=BIT[r].num;
    while(l<=r)
	{
        ret=max(BIT[r].num,ret);
        for(--r;r-l>=lowbit(r);r-=lowbit(r))
			ret=max(ret,BIT[r].maxn);
	}
	return ret;
}
void add()
{
	cnt++;
	int temp;
    Read(temp);
	BIT[cnt].num=(temp+t)%mod_num;
	BIT[cnt].maxn=max(query(cnt+1-lowbit(cnt),cnt-1),BIT[cnt].num);
}
