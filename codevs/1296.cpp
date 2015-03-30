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
using namespace std;
struct NODE
{
	int cnt,f,l,r,v,size;
	NODE()
	{
	       f=l=r=v=0;
	       cnt=f;
        }
};
long long ans=0;
const int maxn=40000;
struct Splay
{
	int size;
	int root;
	NODE node[40000];
	Splay()
	{
		root=0;
		size=-1;
	}
	void update(int pos)
	{
		int l=node[pos].l;
		int r=node[pos].r;
		node[pos].size=node[l].size+node[r].size;
		return ;
	}
	void rot_r(int pos)//pos is the upper node pos;
	{
		int a=node[pos].l;
		node[pos].l=node[a].r;
                node[node[pos].l].f=pos;
                node[a].r=pos;
                if(root==pos)   root=a;
                else
                {
                        if(node[node[pos].f].l==pos) node[node[pos].f].l=a;   
                        else node[node[pos].f].r=a;
                }
                node[a].f=node[pos].f;
                node[pos].f=a;
                update(pos);
                update(a);
	}
	void rot_l(int pos)
	{
		int a=node[pos].r;
                node[pos].r=node[a].l;
                node[node[pos].r].f=pos;
                node[a].l=pos;
                if(root==pos)   root=a;
                else
                {
                        if(node[node[pos].f].l==pos) node[node[pos].f].l=a;
                        else node[node[pos].f].r=a;
                }
                node[a].f=node[pos].f;
                node[pos].f=a;
                update(pos);
                update(a);	
        }
        void splay(int cur_pos,int aim) //node [cur_pos] want to be the subnode of aim
        {
                while(node[cur_pos].f!=aim)
                {
                        int f=node[cur_pos].f;
                        int ff=node[f].f;
                        if(ff==aim)
                        {
                                if(cur_pos==node[f].l) rot_r(f);
                                else rot_l(f);
                        }
                        else
                        {
                                if(node[ff].r==f&&node[f].r==cur_pos)
                                {
                                        rot_l(ff);
                                        rot_l(f);
                                }
                                else if(node[ff].l==f&&node[f].l==cur_pos)
                                {
                                        rot_r(ff);
                                        rot_r(f);
                                }
                                else if(node[ff].l==f&&node[f].r==cur_pos)
                                {
                                        rot_l(f);
                                        rot_r(ff);
                                }
                                else if(node[ff].r==f&&node[f].l==cur_pos)
                                {
                                        rot_r(f);
                                        rot_l(ff);
                                }
                        }
                }
                if(aim==0)      root=cur_pos;
        }
        void insert(int value)
        {
                size++;
                node[size].v=value;
                node[size].size=node[size].cnt=1;
                if(root==0)     root=size;
                else
                {
                        int pos=root,lastpos; 
                        while(pos!=0)
                        {
                                lastpos=pos;
                                node[pos].size++;
                                if(node[pos].size==value)
                                {
                                        node[pos].cnt++;
                                        size--;
                                        splay(pos,0);
                                        return ;
                                }
                                if(value<node[lastpos].v)       pos=node[lastpos].l;
                                else pos=node[lastpos].r;
                        }
                        if(value<node[lastpos].v)       node[lastpos].l=size;
                        else node[lastpos].r=size;
                        node[size].f=lastpos;
                        splay(size,0);
                        return ;
                }
        }
        void Insert(int value)
        {
                insert(value);
                if(node[root].cnt>1)   return ;
                int pos=node[root].l;
                while(node[pos].r!=0)//l
                {
                        pos=node[pos].r;
                }
                int lv=node[pos].v;
                int rv;
                pos=node[root].r;
                while(node[pos].l!=0)
                {
                        pos=node[pos].l;
                }
                rv=node[pos].v;
                lv=abs(value-lv);
                rv=abs(value-rv);
                int delta=min(lv,rv);
                cout<<value<<": "<< delta<<endl;
                ans+=delta;
                return;
        }
}tree;

int main(int argc, char const *argv[])
{
        #ifndef ONLINEJUDGE
        freopen("1296.in","r",stdin);
        #endif
        int n;
        scanf("%d",&n);
        int temp;
        scanf("%d",&temp);
        tree.insert(temp);
        ans+=temp;
        while(scanf("%d",&temp)!=EOF)
        {
                tree.Insert(temp);
        }
        printf("%lld\n",ans );
        return 0;

}
