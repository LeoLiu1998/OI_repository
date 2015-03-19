s source-code is licensed under GPLv3
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
struct Edge
{
	int begin,end,v;
};
Edge edge[100005];
int parent[100005];
bool cmp(Edge a,Edge b)
{
	return a.v<b.v;
}

int ask(int cur)
{
	if(parent[cur]==cur)	return cur;
	else
	{
		parent[cur]=ask(parent[cur]);
		return parent[cur];
	}
}

void change(int a,int v)
{
	if(parent[a]==a)
	{
		parent[a]=v;
		return ;
	}
	else
	{
		change(parent[a],v);
		parent[a]=v;
		return ;
	}
}

void merge(int a,int b)
{
	int a_p=ask(a);
	int b_p=ask(b);
	if(a_p==b_p)	return;
	if(a_p<b_p)
	{
		change(b,a_p);
	}
	else{
		change(a,b_p);
	}
	return ;
}

int main(int argc, char* argv[])
{
	//freopen("in.txt","r",stdin);
	int n;
	int m;
	Read(n);
	Read(m);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		parent[i]=i;
	}
	register int a,b,c;
	for(int i=0;i<m;i++)
	{
		Read(a);
		Read(b);
		Read(c);
		edge[i].begin=a;
		edge[i].end=b;
		edge[i].v=c;
	}
	sort(edge+0,edge+m,cmp);
	//for(int i=0;i<n*n;i++)	cout<<edge[i].begin<<" "<<edge[i].end<<" "<<edge[i].v<<endl;
	long long ans=0;
	for(int i=0;i<m;i++)
	{
		if(ask(edge[i].begin)!=ask(edge[i].end))
		{
			ans+=edge[i].v;
			merge(edge[i].begin,edge[i].end);
		}
	}
	cout<<ans;
}

