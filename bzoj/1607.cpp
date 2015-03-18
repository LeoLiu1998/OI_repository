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

const int maxn=100010;

int cnt[1000010],z[maxn],f[maxn],n;

int main()
{
	scanf("%d",&n);
	for (int a=1;a<=n;a++)
	{
		scanf("%d",&z[a]);
		cnt[z[a]]++;
	}
	for (int a=1;a<=n;a++)
		for (int b=1;b*b<=z[a];b++)
			if (z[a] % b==0)
			{
				f[a]+=cnt[b];
				if (b*b!=z[a]) f[a]+=cnt[z[a]/b];
			}
	for (int a=1;a<=n;a++)
		printf("%d\n",f[a]-1);

	return 0;
}
