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
#include <vector>
#include <cmath>
#include <algorithm>
const double pi=3.1415926535898;
const int maxn=100005;
using namespace std;
void Read(int &x)
{
	scanf("%d ",&x);
}

struct DOT
{
	std::vector<int> vd;
	int seg_pos,parent,depth,v,heavy_child,size,f;
	DOT()
	{
		vd.clear();
		seg_pos=parent=depth=0;
	}
};

struct SEG
{
	int prev,succ,l,r,m,num,lazy_v;
	bool lazy;
	SEG()
	{
		prev=succ=-1;
		l=r=m=num=0;
	}
	SEG operator + (const SEG & a)
	{
		SEG ret;
		ret.prev=prev;
		ret.succ=a.succ;
		ret.num=a.num+num;
		if(succ==a.prev)
			ret.num-- ;
		ret.l=l;
		ret.r=a.r;
		ret.m=(l+r)>>1;
		return ret;
	}
};
char manu;
DOT dot[maxn];
SEG seg[4*maxn];
bool deal[maxn],done=true;
int n,cnt,M,a,b,cur_depth,cur,heavy_child_size=-1,cur_father,tree_pos[maxn];

void cut(int);
void init(int);
void Seg_build(int,int,int);
void Modify(int,int,int);
void Query(int,int);
int main(int argc, char const *argv[])
{
	#ifndef ONLINEJUDGE
	freopen("2243.in","r",stdin);
	#endif
	cout<<"WTF\n";
	Read(n);
	Read(M);
	for(int i=1;i<=n;++i)
		Read(dot[i].v);
	for (int i = 1; i < n; ++i)
	{
		Read(a);
		Read(b);

		dot[a].vd.push_back(b);
		dot[b].vd.push_back(a);
	}
	
	init(1);

	memset(deal,false,sizeof(deal));
	cut(1);
	Seg_build(1,1,n);
	
	while(M--)
	{
		manu=getchar();
		while(manu!='C'&&manu!='Q')	manu=getchar();
		switch (manu)
		{
			case'C':Read(a);
				Read(b);
				Read(cur);
				Modify(a,b,cur);
				break;
			case'Q':Read(a);
				Read(b);
				Query(a,b);
		}
	}
	return 0;
}

void Seg_modify(int,int,int,int);
SEG Seg_query(int,int,int);

void init(int pos)
{
	if(deal[pos])	return;
	deal[pos]=true;
	dot[pos].depth=cur_depth;
	dot[pos].size=1;
	heavy_child_size=-1;
	for (int i = 0; i < dot[pos].vd.size(); ++i)
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

void cut(int pos)
{
	if(deal[pos])	return;
	if(!done)	dot[pos].f=cur_father;
	else
	{
		done=false;
		cur_father=pos;
		dot[pos].f=cur_father;
	}
	dot[pos].seg_pos=cnt;
	tree_pos[cnt]=pos;
	deal[pos]=true;
	cnt++;
	if(pos!=1&&dot[pos].vd.size()==1)	done=true;
	else cut(dot[pos].heavy_child);
	for (int i = 0; i < dot[pos].vd.size(); ++i)
	{
		cur=dot[pos].vd[i];
		if(deal[cur])	continue;
		cut(cur);
	}
}
	// “C a b c”表示这是一个染色操作，把节点a到节点b路径上所有点（包括a和b）都染成颜色c；
// “Q a b”表示这是一个询问操作，询问节点a到节点b（包括a和b）路径上的颜色段数量。

void Modify(int a,int b,int v)
{
	while(dot[a].f!=dot[b].f)
	{
		if(dot[dot[a].f].depth<dot[dot[b].f].depth) swap(a,b);
		Seg_modify(1,dot[a].seg_pos,dot[dot[a].f].seg_pos,v);
		a=dot[dot[a].f].parent;
	}
	Seg_modify(1,dot[a].seg_pos,dot[b].seg_pos,v);
	return ;
}

void Query(int a,int b)
{
	SEG ans;
	while(dot[a].f!=dot[b].f)
	{
		if(dot[dot[a].f].depth<dot[dot[b].f].depth)	swap(a,b);
		ans=Seg_query(1,dot[a].seg_pos,dot[dot[a].f].seg_pos)+ans;
		a=dot[dot[a].f].parent;
	}
	ans=Seg_query(1,dot[a].seg_pos,dot[b].seg_pos);
	printf("%d\n",ans.num);
}

void Seg_build(int pos,int l,int r)
{
	if(l==r)
	{
		seg[pos].m=seg[pos].l=seg[pos].r=l;
		seg[pos].num=1;
		seg[pos].succ=seg[pos].prev=dot[tree_pos[l]].v;
		return ;
	}
	Seg_build(pos<<1,l,(l+r)>>1);
	Seg_build(pos<<1|1,((l+r)>>1)+1,r);
	seg[pos]=seg[pos<<1]+seg[pos<<1|1];
	return ;
}

void Seg_modify(int pos,int l,int r,int v)
{
	if(l>r)	swap(l,r);
	if(seg[pos].l==l&&seg[pos].r==r)
	{
		seg[pos].lazy=false;
		seg[pos].prev=seg[pos].succ=v;
		seg[pos].num=1;
		if(seg[pos].l!=seg[pos].r)
		{
			seg[pos<<1].lazy=true;
			seg[pos<<1|1].lazy=true;
			seg[pos<<1].lazy_v=v;
			seg[pos<<1|1].lazy_v=v;
		}
		return ;
	}
	else
	{
		if(r>=seg[pos].m)
			Seg_modify(pos<<1,l,r,v);
		else if(l<seg[pos].m)
			Seg_modify(pos<<1|1,l,r,v);
		else
			Seg_modify(pos<<1,l,seg[pos].m,v),Seg_modify(pos<<1|1,seg[pos].m+1,r,v);
		seg[pos]=seg[pos<<1]+seg[pos<<1|1];
		return ;
	}
}

SEG Seg_query(int pos,int l,int r)
{
	if(l>r)	swap(l,r);
	if(l==seg[pos].l&&r==seg[pos].r)	return seg[pos];
	if(r<=seg[pos].m)	return Seg_query(pos<<1,l,r);
	else if(l>seg[pos].m)	return Seg_query(pos<<1|1,l,r);
	return Seg_query(pos<<1,l,seg[pos].m)+Seg_query(pos<<1|1,seg[pos].m+1,r); 
}
