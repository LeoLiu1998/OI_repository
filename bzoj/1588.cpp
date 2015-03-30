#include<cstdio>
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
struct NODE
{
        int l,r,f,v;
        NODE()
        {
                kl=r=f=v=0;
        }
`};
const int maxn=100005;
struct SPLAY
{
       int root,size;
       NODE node[maxn];
       SPLAY()
       {
                root=0;
                size=-1;
       }
       void update(int pos)
       {
                int l=node[pos].l;
                int r=node[pos].r;
                node[pos].size=node[l].size+node[r].size+1;
       }
       void rot_r(int pos)
       {
                int  a=node[pos].l;
                node[pos].l=node[]
       }
       void rot_l(int pos)//pos is the upper node's pos
       {
                                
       }
};
SPLAY tree;
int main()
{
         int n;
         int temp;
         scanf("%d",&n);
         while(~scanf("%d",temp))
         {
                tree.insert(temp);
         }

}
