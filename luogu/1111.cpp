/*Copyright (c)2014 Ye Guanghao
 *This sourcecode is licensed under GPLv3
 */
#define DEBUG
#ifdef DEBUG
#include<iostream>
#endif
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>
const double pi=3.1415926535898;
using namespace std;
const int maxn=100010;
struct Valley
{
	int f;
	int t;
	int size;
	Valley()
	{
		size=f = t = 0;
	}

};
Valley val[maxn];
struct  Edge
{
	int begin,end,time;
	bool operator < (const Edge a)const
	{
		return time<a.time;
	}
};
int size=0;
Edge edge[maxn];
int v_n,e_n;
int ask(int);
void merge(int,int);
int ask_size(int);
void init()
{
	for(int i=1;i<=v_n;i++)
	{
		val[i].f=i;
		val[i].size=1;
	}

}
void print()
{
	cout<<endl;
	for(int i=1;i<=v_n;i++)
	{
		cout<<i<<"f: "<<ask(i)<<" ";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	#ifndef ONLINEJUDGE
	freopen("1111.in","r",stdin);
	#endif
	scanf("%d%d",&v_n,&e_n);
	init();
	for(int i=0;i<e_n;i++)
	{
		scanf("%d%d%d",&edge[i].begin,&edge[i].end,&edge[i].time);
	}
	sort(edge+0,edge+e_n);
	for(int i=0;i<e_n;i++)
	{
		if(ask(edge[i].begin)!=ask(edge[i].end))
		{
			merge(edge[i].begin,edge[i].end);
			//print();
			if(ask_size(edge[i].begin)==v_n)
			{
				printf("%d\n",edge[i].time);
				return 0;
			}
		}
		
	}
	printf("-1\n");
	return 0;
}

int ask(int pos)
{
	if(val[pos].f==pos)
	{
		return pos;
	}
	else
	{
		val[pos].f=ask(val[pos].f);
	}
	return val[pos].f;
}

int ask_size(int pos)
{
	int f=ask(pos);
	return val[f].size;
}

void merge(int a,int b)
{
	int af=ask(a);
	int bf=ask(b);
	val[bf].f=af;
	//cout<<"bf:"<<bf<<endl
	//<<"af:"<<af<<endl;
	val[af].size+=val[bf].size;
	//cout<<val[af].size<<endl;
}

