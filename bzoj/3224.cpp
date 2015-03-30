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
#define PROB ""
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
const int maxn=100001;
const int INF=123456789;

int n;

struct node
{
	int l,r,f,size,value,cnt;
	node()
	{
		l=r=f=size=value=cnt=0;
	}
};

struct splay_tree
{
	int size,root;
	node z[maxn];
	splay_tree()
	{
		size=root=0;
	}
	void update(int now)
	{
		z[now].size=z[z[now].l].size+z[z[now].r].size+z[now].cnt;
	}
	void rot_l(int now)
	{
		int a=z[now].r;
		z[now].r=z[a].l;
		z[a].l=now;
		update(now);
		update(a);
		if (now==root) root=a;
		else
		{
			if (z[z[now].f].l==now) z[z[now].f].l=a;
			else z[z[now].f].r=a;
		}
		z[a].f=z[now].f;
		z[now].f=a;
		z[z[now].r].f=now;
	}
	void rot_r(int now)
	{
		int a=z[now].l;
		z[now].l=z[a].r;
		z[a].r=now;
		update(now);
		update(a);
		if (root==now) root=a;
		else
		{
			if (z[z[now].f].l==now) z[z[now].f].l=a;
			else z[z[now].f].r=a;
		}
		z[a].f=z[now].f;
		z[now].f=a;
		z[z[now].l].f=now;
	}
	void splay(int now,int goal)
	{
		while (z[now].f!=goal)
		{
			int f=z[now].f;
			int ff=z[f].f;
			if (ff==goal)
			{
				if (z[f].l==now) rot_r(f);
				else rot_l(f);
			}
			else
			{
				if ((z[f].l==now) && (z[ff].l==f))
				{
					rot_r(ff);
					rot_r(f);
				}
				if ((z[f].r==now) && (z[ff].r==f))
				{
					rot_l(ff);
					rot_l(f);
				}
				if ((z[f].r==now) && (z[ff].l==f))
				{
					rot_l(f);
					rot_r(ff);
				}
				if ((z[f].l==now) && (z[ff].r==f))
				{
					rot_r(f);
					rot_l(ff);
				}
			}
		}
		if (goal==0) root=now;
	}
	void insert(int x)
	{
		size++;
		z[size].value=x;
		z[size].size=1;
		z[size].cnt=1;
		if (root==0) root=size;
		else
		{
			int pos=root,lastp;
			while (pos!=0)
			{
				lastp=pos;
				z[pos].size++;
				if (z[pos].value==x)
				{
					z[pos].cnt++;
					size--;
					splay(pos,0);
					return;
				}
				if (x<z[pos].value) pos=z[pos].l;
				else pos=z[pos].r;
			}
			if (x<z[lastp].value) z[lastp].l=size;
			else z[lastp].r=size;
			z[size].f=lastp;
			splay(size,0);
		}
	}
	void del(int x)
	{
		int pos=root;
		while ((z[pos].value!=x) && (pos!=0))
		{
			if (z[pos].value>x) pos=z[pos].l;
			else pos=z[pos].r;
		}
		if (pos==0) return;
		if (z[pos].cnt!=1)
		{
			z[pos].cnt--;
			int nowp=pos;
			while (nowp!=0)
			{
				z[nowp].size--;
				nowp=z[nowp].f;
			}
			splay(pos,0);
		}
		else
		{
			splay(pos,0);
			while (z[z[pos].r].l!=0)
				rot_r(z[pos].r);
			if (z[pos].r==0)
			{
				if (z[pos].l==0) root=0;
				else
				{
					root=z[pos].l;
					z[root].f=0;
				}
			}
			else
			{
				root=z[pos].r;
				z[root].l=z[pos].l;
				z[z[pos].l].f=root;
				z[root].f=0;
			}
		}
	}
	void get_rank(int x)
	{
		int pos=root;
		while (z[pos].value!=x && pos!=0)
		{
			if (z[pos].value>x) pos=z[pos].l;
			else pos=z[pos].r;
		}
		splay(pos,0);
		printf("%d\n",z[z[pos].l].size+1);
	}
	void get_number(int x)
	{
		int pos=root;
		while (!((z[z[pos].l].size+1<=x) && (z[z[pos].l].size+z[pos].cnt>=x) ) && (pos!=0))
		{
			if (x<=z[z[pos].l].size) pos=z[pos].l;
			else 
			{
				x-=z[z[pos].l].size+z[pos].cnt;
				pos=z[pos].r;
			}
		}
		printf("%d\n",z[pos].value);
		splay(pos,0);
	}
	void get_pre(int x)
	{
		int pos=root,ans=-INF,ansp=0;
		while (pos!=0)
		{
			if (z[pos].value<x) 
			{
				if (z[pos].value>ans)
				{
					ans=z[pos].value;
					ansp=pos;
				}
			}
			if (z[pos].value>=x) pos=z[pos].l;
			else pos=z[pos].r;
		}
		printf("%d\n",ans);
		splay(ansp,0);
	}
	void get_next(int x)
	{
		int pos=root,ans=INF,ansp=0;
		while (pos!=0)
		{
			if (z[pos].value>x) 
			{
				if (z[pos].value<ans)
				{
					ans=z[pos].value;
					ansp=pos;
				}
			}
			if (z[pos].value<=x) pos=z[pos].r;
			else pos=z[pos].l;
		}
		printf("%d\n",ans);
		splay(ansp,0);
	}
}tree;

int main()
{

	scanf("%d",&n);
	for (int a=1;a<=n;a++)
	{
		int opt,x;
		scanf("%d%d",&opt,&x);
		//printf("%d %d %d %d %d\n",a,opt,x,tree.root,tree.z[tree.root].size);
		switch(opt)
		{
			case 1:
				{
					tree.insert(x);
					break;
				}
			case 2:
				{
					tree.del(x);
					break;
				}
			case 3:
				{
					tree.get_rank(x);
					break;
				}
			case 4:
				{
					tree.get_number(x);
					break;
				}
			case 5:
				{
					tree.get_pre(x);
					break;
				}
			case 6:
				{
					tree.get_next(x);
					break;
				}
		}
	}

	return 0;
}