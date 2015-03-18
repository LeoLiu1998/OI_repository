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
int f[105][1050];
int main(int argc, char* argv[])
{
	int K,N;
	Read(N);
	Read(K);
	f[0][0]=1;
	for(int i=1;i<=K;i++)	f[i][0]=1;
	for(int i=1;i<=N;i++)	f[1][i]=1;
	for(int i=2;i<=K;i++)
	{
		for(int j=i;j<=N;j++)
		{
			for(int k=0;k*i<=j;k++)
			{
				f[i][j]+=f[i-1][j-k*i];
			}
		}
	}
	cout<<f[K][N];
}
