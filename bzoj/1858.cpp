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
#include<cassert>
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
int n;
const int maxn=100100;
int a[maxn];
struct SEG
{
	int pre,suf,mid;
	int sum;
	int l,m,r;
	bool lazy;
	short lazy_data;
	SEG()
	{
		lazy=false;
		lazy_data = -1;
	}
};
void Build();
void To0(int,int,int);
void To1(int,int,int);
void Reverse(int,int,int);
void Query(int,int,int);
void QueryC(int,int,int);
SEG seg[maxn<<1];
int main(int argc, char* argv[])
{
	int M;
	Read(n);
	Read(M);
	for(int i=1;i<=n;i++)
		Read(a[i]);
	Build();
	register int l,r,manu;
	while(M--)
	{
		Read(manu);
		switch(manu)
		{
			case 0:	To0(1,l,r);
				break;
			case 1:	To1(1,l,r);
				break;
			case 2:	Reverse(1,l,r);
				break;
			case 3:	Query(1,l,r);
				break;
			case 4: QueryC(1,l,r);
		}
	}
	return 0;
}

void lazydown(int segpos)
{
	seg[segpos].sum=seg[segpos].pre=seg[segpos].suf=seg[segpos].mid=lazy_data*(r-l+1);
	seg[segpos<<1].lazy=seg[segpos<<1|1].lazy=true;
	seg[segpos<<1].lazy_data=seg[segpos<<1|1].lazy_data=lazy_data;
	lazy_data=-1;
	lazy=false;
	return ;
}

SEG merge(int a_segpos,int b_segpos)
{
	SEG &a=seg[a_segpos];
	SEG &b=seg[b_segpos];
	assert(a.r==b.l)
	SEG ret;
	ret.l=a.l;
	ret.r=b.r;
	ret.m=(ret.l+ret.r)>>1;
	if(a.lazy)	lazydown(a_segpos);
	if(b.lazy)	lazydown(b_segpos);
	ret.pre= a.pre== (a.r-a.l+1) ? a.pre+b.pre : a.pre;
	ret.mid= a.suf+b.pre;
	ret.suf= b.suf== (b.r-b.l+1) ? a.suf+b.suf : b.suf;
	ret.sum=a.sum +b.sum;
	return ret;
}

void Build(int segpos,int l,int r)
{
	seg[segpos].l=l;
	seg[segpos].r=r;
	seg[segpos].m=(l+r)>>1;
	if(l==r)
	{
		sge[segpos].sum=a[l];
		if(a[l]==1)
		{
			seg[segpos].pre=seg[segpos].mid=seg[segpos].suf=1;
		}
		else
		{
			seg[segpos].pre=seg[segpos].mid=seg[segpos].suf=0;
		}
		return ;
	}
	Build(segpos<<1,l,seg[segpos].m);
	Build(segpos<<1|1,seg[segpos].m+1,r);
	seg[segpos]=merge(seg[segpos].m,seg[segpos].m+1);
	return ;
}

void To0(int segpos,int l, int r)
{
	if(l==r)
	{
		SEG &cur=seg[segpos];
		cur.pre=cur.suf=cur.mid=cur.sum=0;
		return ;
	}
	seg[segpos<<1].lazy=seg[segpos<<1|1].lazy=true;
	seg[segpos<<1].lazy_data=seg[segpos<<1|1].lazy_data=0;
	return ;
}

void To1(int segpos,int l, int r)
{
	SEG &cur=seg[segpos];
	cur.pre=cur.suf=cur.mid=cur.sum=(r-l+1);
	if(l==r)
	{
		return ;
	}
	seg[segpos<<1].lazy=seg[segpos<<1|1].lazy=true;
	seg[segpos<<1].lazy_data=seg[segpos<<1|1].lazy_data=1;
	return ;
}
void Reverse(int segpos,int l,int r)
{
	SEG &cur=seg[segpos];
	if()
}