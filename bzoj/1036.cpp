/*Copyright (c)2015 Ye Guanghao
 *This sourcecode is licensed under GPLv3
 */
#define DEBUG
#ifdef DEBUG
#include <iostream>
#endif
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cassert>
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
	int ma,sum,l,r,m;
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
		ret.m=(ret.l+ret.r)>>1;
		return ret;
	}
};
struct DOT
{
	int size;
	int parent;
	int heavy_child;
	int seg_pos,v;
	int depth;
	std::vector<int> vd;
	DOT()
	{
		seg_pos=0;
		vd.clear();
	}
};

SEG seg[maxn*4];
bool deal[maxn];
int tree_pos[maxn];
int f[maxn];
int n=1;
int cnt=1;
int temp=0;
int LCA;
int fa,fb;
DOT dot[maxn];
//SEG seg[maxn];
bool done=true;
int cur_father;
int ans=0;
int cur_depth=0;
void init(int);
void cut(int);
void Seg_build(int,int,int);
char manu[15];
void Query_max(int,int);
void Query_sum(int,int);
void Modify(int,int);
int main(int argc, char const *argv[])
{
	#ifndef ONLINEJUDGE
	freopen("1036.in","r",stdin);
	freopen("1036.out","w",stdout);
	#endif

	Read(n);
	register int a,b;
	for (int i = 1; i < n; ++i)
	{
		Read(a);
		Read(b); 
		dot[a].vd.push_back(b);
		dot[b].vd.push_back(a);
	}
	for (int i = 0; i < n; ++i)
	{
		Read(a);
		dot[i+1].v=a;
	}
	init(1);
	memset(deal,false,sizeof(deal));
	cut(1);
	Seg_build(1,1,n);
	int M;
	Read(M);
	while(M--)
	{
		//cout<<M<<endl;
		scanf("%s",manu);
		Read(a);
		Read(b);
		switch(manu[strlen(manu)-1])
		{
			case 'X':
				Query_max(a,b);
				break;
			case 'M':
				Query_sum(a,b);
				break;
			case 'E':
				Modify(a,b);
		}
	}
	return 0;
}

void init(int pos)
{
	cur_depth++;
	dot[pos].depth=cur_depth;
	deal[pos]=true;
	dot[pos].size=1;
	register int cur;
	int heavy_child_size=-1;
	for(int i=0;i<dot[pos].vd.size();i++)
	{
		cur=dot[pos].vd[i];
		if(deal[cur])	continue;
		dot[cur].parent=pos;
		init(cur);
		dot[pos].size+=dot[cur].size;
		if(dot[cur].size>heavy_child_size)
		{
			heavy_child_size=dot[cur].size;
			dot[pos].heavy_child=cur;
		}
	}
	cur_depth--;
	return ;
}

void cut(int cur_pos)
{
	if(deal[cur_pos])	return ;
	if(!done)
	{
		f[cur_pos]=cur_father;
	}
	else
	{
		done=false;
		f[cur_pos]=cur_pos;
		cur_father=cur_pos;
	}
	dot[cur_pos].seg_pos=cnt;
	tree_pos[cnt]=cur_pos;
	deal[cur_pos]=true;
	cnt++;
	if(cur_pos!=1&&dot[cur_pos].vd.size()==1)
		done=true;
	else{
		cut(dot[cur_pos].heavy_child);
	}
	for(int i=0;i<dot[cur_pos].vd.size();i++)
	{
		temp=dot[cur_pos].vd[i];
		if(deal[temp])	continue;
		cut(temp);
	}
}

void Seg_build(int pos,int l,int r)
{
	if(l==r)
	{
		seg[pos].l=l;
		seg[pos].r=r;
		seg[pos].m=l;
		seg[pos].ma=dot[tree_pos[l]].v;
		seg[pos].sum=seg[pos].ma;
		return ;
	}
	Seg_build(pos<<1,l,(l+r)>>1);
	Seg_build(pos<<1|1,((l+r)>>1)+1,r);
	seg[pos]=seg[pos<<1]+seg[pos<<1|1];
	return ;
}

int Seg_sum(int pos ,int l,int r)
{
	if(l>r)	swap(l,r);
	if(l==seg[pos].l&&r==seg[pos].r)	return seg[pos].sum;
	if(r<=seg[pos].m)
		return Seg_sum(pos<<1,l,r);
	else if(l>seg[pos].m)
		return Seg_sum(pos<<1|1,l,r);
	return Seg_sum(pos<<1,l,seg[pos].m)+Seg_sum(pos<<1|1,seg[pos].m+1,r);
}

int Seg_max(int pos ,int l,int r)
{
	if(l>r)	swap(l,r);
	if(l==seg[pos].l&&r==seg[pos].r)	return seg[pos].ma;
	if(r<=seg[pos].m)
		return Seg_max(pos<<1,l,r);
	else if(l>seg[pos].m)
		return Seg_max(pos<<1|1,l,r);
	return max(Seg_max(pos<<1,l,seg[pos].m),Seg_sum(pos<<1|1,seg[pos].m+1,r));
}

void Seg_modify(int seg_pos,int arr_pos,int v)
{
	if(seg[seg_pos].l==seg[seg_pos].r&&arr_pos==seg[seg_pos].l)
	{
		seg[seg_pos].ma=seg[seg_pos].sum=v;
		return ;
	}
	if(arr_pos<=seg[seg_pos].m)
	{
		Seg_modify(seg_pos<<1,arr_pos,v);
	}
	else
		Seg_modify(seg_pos<<1|1,arr_pos,v);
	seg[seg_pos]=seg[seg_pos<<1]+seg[seg_pos<<1|1];
	return ;
}

void Query_sum(int a,int b)
{
	ans=0;
	if(f[a]==f[b])
	{
		ans= Seg_sum(1,dot[a].seg_pos,dot[b].seg_pos);
	}
	else
	{
		while(f[a]!=f[b])
		{
			if(dot[f[a]].depth<dot[f[b]].depth)	swap(a,b);// make sure a is deepest
			ans+=Seg_sum(1,dot[a].seg_pos,dot[f[a]].seg_pos);
			a=dot[f[a]].parent;
		}
		ans+=Seg_sum(1,dot[a].seg_pos,dot[b].seg_pos);
	}
	printf("%d\n",ans);
}

void Query_max(int a,int b)
{
	ans=0;
	if(f[a]==f[b])
	{
		ans= max(ans,Seg_max(1,dot[a].seg_pos,dot[b].seg_pos));
	}
	else
	{
		while(f[a]!=f[b])
		{
			if(dot[f[a]].depth<dot[f[b]].depth)	swap(a,b);// make sure a is deepest
			ans=max(ans,Seg_max(1,dot[a].seg_pos,dot[f[a]].seg_pos));
			a=dot[f[a]].parent;
		}
		ans=max(ans,Seg_max(1,dot[a].seg_pos,dot[b].seg_pos));
	}
	printf("%d\n",ans);
}

void Modify(int a,int b)
{
	dot[a].v=b;
	Seg_modify(1,dot[a].seg_pos,b);
	return ;
}
