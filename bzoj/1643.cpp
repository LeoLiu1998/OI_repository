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

int main()
{
	int ans=0,n;
	scanf("%d",&n);
	for (int a=0;a*a<=n;a++)
		for (int b=0;b*b<=n-a*a;b++)
			for (int c=0;c*c<=n-a*a-b*b;c++)
			{
				int d=(int)sqrt(n-a*a-b*b-c*c);
				if (a*a+b*b+c*c+d*d==n) ans++;
			}
	printf("%d\n",ans);

	return 0;
}