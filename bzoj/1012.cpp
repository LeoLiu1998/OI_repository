/*Copyright (c)2014 Ye Guanghao
 *This sourcecode is licensed under GPLv3
 */
#ifdef DEBUG
#include <iostream>
#endif
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
const double pi=3.1415926535898;
using namespace std;
const int maxn=200001;
int ans[maxn],tail,last,m,d;
int max(int a,int b)
{
	if (a>b) return(a);
	else return(b);
}
int main()
{
	scanf("%d%d",&m,&d);
	tail=0;
	for (int a=1;a<=m;a++)
	{
		char c[2];
		scanf("%s",c);
		if (c[0]=='A')
		{
			int n;
			scanf("%d",&n);
			if (tail==0)
			{
				tail++;
				ans[1]=n % d;
			}
			else
			{
				tail++;
				ans[tail]=(n+last) % d;
				int now=tail-1;
				while ((now>0) && (ans[now]<ans[tail]))
				{
					ans[now]=ans[tail];
					now--;
				}
			}
		}
		else
		{
			int l;
			scanf("%d",&l);
			if (tail==0) 
			{
				printf("0\n");
				last=0;
			}
			else 
			{
				printf("%d\n",ans[max(1,tail-l+1)]);
				last=ans[max(1,tail-l+1)];
			}
		}
	}
	return(0);
}