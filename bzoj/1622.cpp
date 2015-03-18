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
inline long long  read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,ans[1005];
char a[1005][1005],b[105][35];
inline bool equ(char a,char b)
{
	if(a<'a'||a>'z')a=a-'A'+'a';
	if(b<'a'||b>'z')b=b-'A'+'a';
	return a==b;
}
inline bool jud(int x,int y)
{
	int l1=strlen(b[x]+1),l2=strlen(a[y]+1);
	int now=1;
	for(int i=1;i<=l2;i++)
		if(equ(b[x][now],a[y][i]))now++;
	if(now==l1+1)return 1;
	return 0;
}
void solve(int x)
{
	for(int i=1;i<=n;i++)
		if(jud(x,i))ans[i]++;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	for(int i=1;i<=m;i++)
		scanf("%s",b[i]+1);
	for(int i=1;i<=m;i++)
		solve(i);
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
	return 0;
}