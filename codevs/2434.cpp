/*Copyright (c)2014 Ye Guanghao
 *This sourcecode is licensed under GPLv3
 */
#ifdef DEBUG
#include<iostream>
#endif
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
const double pi=3.1415926535898;
using namespace std;
std::vector<int> v;
int main(int argc, char const *argv[])
{
	#ifndef ONLINEJUDGE
	freopen("2434.in","r",stdin);
	#endif
	int n,m,t;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(m>=v[i])
		{
			m-=v[i];
			ans++;
		}
		else
			break;
	}
	printf("%d\n",ans );
	return 0;
}