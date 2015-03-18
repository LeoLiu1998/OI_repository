/*Copyright (c)2014 YeGuanghao
 *This source-code is licensed under GPLv3
 */
#include<iostream>
#include<cstdio>
#include<iomanip>
#include<climits>
#include<cmath>
#include<ctime>
#include<vector>
#include<set>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
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

const int maxn=1001;

int n,to[maxn],way[maxn],state[maxn];

int main()
{
	//freopen("cycle.in","r",stdin);
	//freopen("cycle.out","w",stdout);

	scanf("%d",&n);
	for (int a=1;a<n;a++)
	{
		int s,e,how;
		scanf("%d%d%d",&s,&e,&how);
		to[s]=e;
		way[s]=how;
	}
	int now=1;
	while (now!=0)
	{
		state[to[now]]=state[now] ^ way[now];
		now=to[now];
	}
	printf("%d\n",state[n]);

	return 0;
}

