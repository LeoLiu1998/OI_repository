//Copyright (c)2014 Ye Guanghao
//This sourcecode is licensed under GPLv3
#include<iostream>
#include<cstdio>
#include<iomanip>
#include<climits>
#include<cmath>
#include<set>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
const int maxn=50005;
struct Seg
{
    int left,right;
    int flag; 
    int maxem;
    int empty;
    int preem;
    int sufem;
};
Seg seg[2*maxn];
void build(int);
void ask(int);
Seg merge(Seg,Seg);
void print(Seg);
void checkout(int,int);
int n,m;
int main()
{
    ios::sync_with_stdio(false);
    register int temp1,temp2;
    cin>>n>>m;
    seg[1].left=1;
    seg[1].right=n;
    build(1,n);
    while(m--)
    {
        cin>>temp1;
        if(temp1==1){cin>>temp1;ask(1,temp1); }
        else{
            cin>>temp1>>temp2;
            checkout(temp1,temp2);
        }
    }
    return 0;
}
void build(int left,int right,int i)
{
    int n=right-left+1;
    seg[i].left=left;
    seg[i].right=right;
    seg[i].maxem= seg[i].preem=seg[i].sufem=seg[i].empty=n;
    if(left!=right)
    {
        build(left,(left+right)>>1,i<<1);
        build((left+right)>>1+1,right,i<<1|1);
    }
    return ;
}
Seg merge(Seg a,Seg b)
{
    if(a.left==b.right)/// a is right
    {
        Seg temp;
        temp.left=b.left;
        temp.right=a.right;
        temp.preem= b.preem==b.empty? (b.empty+a.preem):b.preem;
        temp.sufem= a.sufem==a.empty? (b.sufem+a.empty):a.sufem;
        temp.empty= a.empty+b.empty;
        temp.maxem=max(max(a.maxem,b.maxem),a.preem+b.sufem);
        return temp;
    }
    else if(a.right==b.left)///a is left
    {
        Seg temp;
        temp.left=a.left;
        temp.right=b.right;
        temp.preem= a.preem==a.empty? (a.empty+b.preem):a.preem;
        temp.sufem= b.sufem==b.empty? (a.sufem+b.empty):b.sufem;
        temp.empty= a.empty+b.empty;
        temp.maxem=max(max(a.maxem,b.maxem),a.sufem+b.preem);
        return temp;
    }
    cout<<"merge Bug! :'"<<Endl;
    print(a);
    print(b);
    cout<<endl;
    abort();
}
void print(Seg a)
{
    cout<<"["<<a.left<<","<<a.right<<"]  emptynum:"<<a.empty<<"  pre"<<a.preem<<"   suf"<<a.sufem<<endl;
    return ;
}
void ask(int pos,int num)
{
    if(num>seg[pos].maxem) { cout<<"0"<<endl;   return ;}
    else
    {
        if(seg[pos<<1].maxem>=num)  ask(pos<<1,num);
        else if(seg[pos<<1].sufem+seg[pos<<1|1].preem>=num )
        {
			
        }
    }
}
