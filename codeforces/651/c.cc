//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
void Redirect() {
	freopen(PROB".in","r",stdin);
#ifndef YGHDEBUG
	freopen(PROB".out","w",stdout);
#endif
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n;
map<pii,int> cal;
map<int,int> x,y;
pii temp;
const int maxn=1000;
ll ans=0;
struct node
{
	int l,r,key;
};

struct splay
{
	int root,size;
	node z[maxn];
	splay()
	{
		root=0;
		size=-1;
	}
	void rot_l(int &now)
	{
		int a=z[now].r;
		z[now].r=z[a].l;
		z[a].l=now;
		now=a;
	}
	void rot_r(int &now)
	{
		int a=z[now].l;
		z[now].l=z[a].r;
		z[a].r=now;
		now=a;
	}
	void insert(int &now,int nowkey)
	{
		if (size==-1)
		{
			size++;
			now=size;
			z[now].l=z[now].r=-1;
			z[now].key=nowkey;
			return;
		}
		if (now==-1)
		{
			size++;
			now=size;
			z[now].l=z[now].r=-1;
			z[now].key=nowkey;
			return;
		}
		if (nowkey<=z[now].key)
		{
			insert(z[now].l,nowkey);
			rot_r(now);
		}
		else 
		{
			insert(z[now].r,nowkey);
			rot_l(now);
		}
	}
	int get(int &now,int nowkey)
	{
		if (now==-1) return -1;
		if (z[now].key==nowkey) return 0;
		if (z[now].key<nowkey)
		{
			int nowans=get(z[now].r,nowkey);
			if (nowans!=-1)
			{
				if (nowans<abs(z[now].key-nowkey))
				{
					rot_l(now);
					return nowans;
				}
				else return abs(z[now].key-nowkey);
			}
			else return abs(z[now].key-nowkey);
		}
		else
		{
			int nowans=get(z[now].l,nowkey);
			if (nowans!=-1)
			{
				if (nowans<abs(z[now].key-nowkey))
				{
					rot_r(now);
					return nowans;
				}
				else return(abs(z[now].key-nowkey));
			}
			else return abs(z[now].key-nowkey);
		}
		return -1;
	}
	int getmin(int nowkey)
	{
		return get(root,nowkey);
	}

}tree;

int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		R(temp.fi); R(temp.se);
		cal[temp]++;
		x[temp.fi]++; y[temp.se]++;
	}
	for(map<int,int>::iterator it=y.begin();it!=y.end();++it) {
		ans+=(ll)(it->second-1)*(it->second)/2;
	}
	for(map<int,int>::iterator it=x.begin();it!=x.end();++it) {
		ans+=(ll)(it->second-1)*(it->second)/2;
	}
	for(map<pii,int>::iterator it=cal.begin();it!=cal.end();++it) {
		ans-=(ll)(it->second-1)*(it->second)/2;
	}
	cout<<ans<<endl;
}

