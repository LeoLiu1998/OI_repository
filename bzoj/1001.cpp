/*Copyright (c)2014 Ye Guanghao
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
#include <algorithm>
const double pi=3.1415926535898;
using namespace std;

const int u=2000010,w=6000010;
int ver[w],edge[w],next[w],head[u],d[u],v[u],q[u];
int n,m,s,t,tot,i,x;

void add(int x,int y,int z)
{
	ver[++tot]=y; edge[tot]=z; next[tot]=head[x]; head[x]=tot;
	ver[++tot]=x; edge[tot]=z; next[tot]=head[y]; head[y]=tot;
}

void makegraph()
{
	int nm=(n-1)*(m-1),i,j,x;
	s=0; t=2*nm+1;
	for(i=1;i<m;i++) {scanf("%d",&x); add(s,i,x);}
	for(i=2;i<n;i++)
		for(j=1;j<m;j++)
		{scanf("%d",&x); add((i-2)*(m-1)+j+nm,(i-1)*(m-1)+j,x);}
	for(i=1;i<m;i++)
		{scanf("%d",&x); add((n-2)*(m-1)+i+nm,t,x);}
	for(i=1;i<n;i++)
	{
		scanf("%d",&x); add(t,(i-1)*(m-1)+nm+1,x);
		for(j=2;j<m;j++)
			{scanf("%d",&x); add((i-1)*(m-1)+j-1,(i-1)*(m-1)+nm+j,x);}
		scanf("%d",&x); add(s,i*(m-1),x);
	}
	for(i=1;i<n;i++)
		for(j=1;j<m;j++)
		{
			scanf("%d",&x);
			add((i-1)*(m-1)+j,(i-1)*(m-1)+nm+j,x);
		}
} 

void up(int x)
{
	while(x>1)
		if(d[q[x]]<d[q[x>>1]])
		{
			swap(q[x],q[x>>1]);
			swap(v[q[x]],v[q[x>>1]]);
			x>>=1;
		}
		else break;
}

void down(int x,int y)
{
	int z=x*2;
	while(z<=y)
	{
		if(z<y&&d[q[z]]>d[q[z+1]]) z++;
		if(d[q[x]]>d[q[z]])
		{
			swap(q[x],q[z]);
			swap(v[q[x]],v[q[z]]);
			x=z; z=x*2;
		}
		else break;
	}
} 

void heapspfa()
{
	int p,x,i;
	memset(d,0x3f,sizeof(d));
	q[p=1]=s; d[s]=0; v[s]=1;
	while(p)
	{
		x=q[1]; v[x]=0;
		if(x==t) break;
		q[1]=q[p]; v[q[p]]=1;
		p--; down(1,p);
		for(i=head[x];i;i=next[i])
			if(d[ver[i]]>d[x]+edge[i])
			{
				d[ver[i]]=d[x]+edge[i];
				if(v[ver[i]]) up(v[ver[i]]);
				else{
					q[++p]=ver[i]; v[ver[i]]=p;
					up(p);
				}			
			}
	}
}

int main()
{
	cin>>n>>m;
	if(m==1)
	{
		d[t]=0x3fffffff;
		for(i=1;i<n;i++) {scanf("%d",&x); d[t]=min(d[t],x);}
		cout<<d[t]<<endl;
		return 0;
	}
	if(n==1)
	{
		d[t]=0x3fffffff;
		for(i=1;i<m;i++) {scanf("%d",&x); d[t]=min(d[t],x);}
		cout<<d[t]<<endl;
		return 0;
	}
	makegraph();
	heapspfa();
	cout<<d[t]<<endl;
	return 0;
} 