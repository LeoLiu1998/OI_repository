/*Copyright (c)2014 Ye Guanghao
 *This sourcecode is licensed under GPLv3
 */
#define DEBUG
#define ONLINEJUDGE
#ifdef DEBUG
#include <iostream>
#endif
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
const double pi=3.1415926535898;
using namespace std;
int n;
struct Building
{
	int dead,time;
	bool operator < (const Building &a) const 
	{
		return time<a.time; 
	}
};
bool cmp(Building a ,Building b)
{
	return a.dead< b.dead;
}
const int maxn=150050;
Building a[maxn];
priority_queue <Building> q;
int ans=0;
void init();
void solve();
int main(int argc, char const *argv[])
{
	#ifndef ONLINEJUDGE
	freopen("1029.in","r",stdin);
	#endif
	init();
	solve();
	printf("%d\n",ans);
}

void init()
{
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d",&a[i].time,&a[i].dead);
	}
	sort(a+0,a+n,cmp);
}

void solve()
{
	int cur=0;
	for (int i = 0; i < n; ++i)
	{
		if(a[i].time+cur<=a[i].dead)
		{
			ans++;
			cur+=a[i].time;
			q.push(a[i]);
		}
		else
		{
			if(q.empty())	continue;
			Building temp=q.top();
			if(temp.time<a[i].time) continue;
			cur-=(temp.time-a[i].time);
			q.pop();
			q.push(a[i]);		
		}
	}
}