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
int q[4];
int main(int argc, char* argv[])
{
	int n;
	Read(n);
	long long ans=0;
	for(int a=1;a<n&&a*2<n;a++)
	{
		for(int b=1;a+b<n&&b*2<n;b++)
		{
			for(int c=1;a+b+c<n;c++)
			{
				int d=n-a-b-c;
				if ((a+b+c>d) && (a+b+d>c) && (a+c+d>b) && (b+c+d>a)) 
				{
					ans+=(long long)(abs(d-c)+1);
					break;
				}
			}
		}
	}
	cout<<ans;
}
