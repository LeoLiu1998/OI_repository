/*Copyright (c)2014 Ye Guanghao
 *This sourcecode is licensed under GPLv3
 */
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
//#define cena
using namespace std;
int n,k,m;
const int maxn=20010;
struct Edge
{
	int begin,end,cost1,cost2;
};
Edge edge[maxn];
int father[maxn];
int mx=INT_MIN;
int l=0,r;
long long ans=INT_MAX;
int em;
bool check(int);
int askfather(int);
int main()
{
	#ifdef cena
 	freopen("xili.in","r",stdin);
 	freopen("xili.out","w",stdout);
 	#endif
 	#ifdef in
 	freopen("in.txt","r",stdin);
 	#endif
 	ios::sync_with_stdio(false);
 	cin>>n>>k>>m;
 	for(int i=1;i<m;i++)
 	{
 		cin>>edge[i].begin>>edge[i].end>>edge[i].cost1>>edge[i].cost2;
 		mx=max(mx,edge[i].cost1);
 		em++;
	 }
	 r=mx;
	 while(l<r)
	 {
	 	if(l+1==r)	break;
	 	int mid=(l+r)>>1;
	 	if(check(mid)) r=mid;
	 	else l=mid+1;
	 }
	 if(!check(l))	l++;
	 ans=l;
	 cout<<ans<<endl;
}
int askfather(int x)
{
	if(father[x]==x)	return x;
	father[x]=askfather(father[x]);
	return father[x];
}
bool check(int mo)
{
	for(int i=1;i<=n;i++)
		father[i]=i;
	int num=0;
	for(int i=1;i<=em;i++)
	{
		if(edge[i].cost1<=mo)
		{
			int x=askfather(edge[i].begin),y=askfather(edge[i].end);
			if(father[x]!=father[y])
			{
				father[father[y]]=father[x];
				num++;
			}
		}
	}
	if(num<k)	return false;
	for(int i=1;i<=em;i++)
	{
		if(edge[i].cost2<=mo)
		{
			int x=askfather(edge[i].begin),y=askfather(edge[i].end);
			if(father[x]!=father[y])
			{
				father[father[y]]=father[x];
				num++;
			}
		}
	}
	if (num == n - 1) return true;
    else return false;
}
