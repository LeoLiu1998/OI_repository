//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=500500;
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

};
int a[maxn];
bool vis[maxn];
int main()
{
	int n;R(n);
	for(int i=1;i<=n;i++) R(a[i]);
	for(int i=1;i<=n;i++) {
		if(i==1 || i==n)vis[i]=1;
		if(a[i]==a[i+1])vis[i]=1;
		if(a[i]==a[i-1])vis[i]=1;
	}
	int ans=0,cur;
	for(int i=1;i<=n;i++) {
		if(!vis[i]) {
			cur=0;
			for(int j=i+1;j<=n;j++) {
				if(vis[j]) {
					cur=j-1; break;
				}
			}
			for(int j=i;j<=(i+cur>>1);j+=1)a[j]=a[i-1],vis[j]=1;
			for(int j=(i+cur>>1)+1;j<=cur;j+=1) {
				a[j]=a[cur+1];
				vis[j]=1;
			}	
			ans=max(ans,cur-i+2>>1);
		}
	}
	Pn(ans);
	for(int i=1;i<=n;i++) Ps(a[i]);
}

