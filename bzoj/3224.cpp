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
#define PROB "3224"
using namespace std;
inline void Read(int & x)
{
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        ch = getchar();
    }
    x = 0;
    while(ch <= '9' && ch >= '0') {
        x *= 10, x += ch - '0';
        ch = getchar();
    }
}

struct node{
        node *l,*r,*f;
        int size,value,cnt;
        node()
        {
                l=r=f=NULL;
                cnt=size=value=0;
        }
}

struct splay_tree
{
        node *root;
        void update(node *p)
        {
                p->size=p->cnt+p->l>size+p->r->size;
        }
        void rot_l(node *cur)//cur is which want to be higher
        {
                node *temp=cur->f;
                temp->r=cur->l;
                temp->r->f=temp;
                if(root!=temp)
                {
                        if(temp!=cur->f->l)//cur's parent is not the lchild of the cur's grand parent
                        {
                                temp->f->r=cur;
                                ->f=
                        }
                        else
                        {
                                temp->f->l=cur;
                        }
                }
                else
                {
                        root=cur;
                }
        }
        void rot_r(node *cur)
        {
                node *temp=cur->l;
                cur->l=temp->r;
                temp->r=cur;
                if(root!=cur)
                {
                        if(cur!=cur->f->l)
                        {
                                cur->f->r=temp;
                        }
                        else
                        {
                                cur->f->l=temp;
                        }
                                temp->f=cur->f;
                }
                else
                {
                        root=temp;
                }
                cur->f=temp;
                update(cur);
                update(cur->f);
                return ;
        }
        void splay(node *cur)
        {
                if(cur->f==root)//zig
                {
                        if(root->l==cur)
                        {
                                rot_r(root);
                        }
                        else
                        {
                                rot_l(root);
                        }
                }
                else if(cur->f->f->l==cur->f&&cur->f->l==cur)//zig zig both left
                {
                        
                }
        }

}
