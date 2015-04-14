/*Copyright (c)2015 Ye Guanghao
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
#include <vector>
#include <algorithm>
const double pi=3.1415926535898;
using namespace std;
const int maxn=30050;
void Read(int &x)
{
	char ch;
	int f=1;
	x=0;
	ch=getchar();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9')
	{
		x*=10;
		x+=ch-'0';
		ch=getchar();
	}
	x*=f;
	return ;
}
struct SEG
{
	int ma,sum,l,r;
	SEG()
	{
		ma=sum=0;
	}
	SEG operator + (const SEG &a) const
	{
		SEG ret;
		ret.ma=max(ma,a.ma);
		ret.sum=sum+a.sum;
		ret.l=min(a.l,l);
		ret.r=max(a.r,r);
		return ret;
	}
};
struct DOT
{
	bool use;
	int size;
	int heavy_child;
	int seg_pos,v;
	std::vector<int> vd;
	DOT()
	{
		seg_pos=0;
		vd.clear();
	}
};

std::vector<int> link;
bool deal[maxn];
int tree_pos[maxn];
int f[maxn];
int n=1;
int cnt=1;
int temp=0;
DOT dot[maxn];
SEG seg[maxn];

void init();
void cut(int);
void Seg_build(int,int,int);



int main(int argc, char const *argv[])
{
	Read(n);
	register int a,b;
	for (int i = 1; i < n; ++i)
	{
		Read(a);
		Read(b);
		a.ve.push_back(b);
		b.ve.push_back(a);
	}
	for (int i = 0; i < n; ++i)
	{
		Read(a);
		dot[i+1].v=a;
	}
	init(pos);
	cut(1);
	Seg_build(1,1,n);
	return 0;
}

void init(int pos)
{
	deal[pos]=true;
	dot[pos].size=1;
	register int cur;
	int heavy_child_size=-1;
	for(int i=0;i<dot[pos].vd.size();i++)
	{
		cur=dot[pos].vd[i];
		if(deal[cur])	continue;
		init(cur);
		dot[pos].size+=dot[cur].size;
		if(dot[cur].size>heavy_child_size)
		{
			heavy_child_size=dot[cur].size;
			dot[pos].heavy_child=cur;
		}
	}
	return ;
}



void cut(int cur_pos)
{
	if(deal[cur_pos])	return ;
	dot[1].seg_pos=cnt;
	tree_pos[cnt]=cur_pos;
	deal[cur_pos]=true;
	cnt++;
	for(int i=0;i<dot[cur_pos].vd.size();i++)
	{
		temp=dot[cur_pos].vd[i];
		if(deal[temp])	continue;
		cut(temp);
	}
}