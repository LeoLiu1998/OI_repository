//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
#define x first
#define y second
typedef pair<int,int> pii;
const int maxn=15;
pii point[maxn];
int n;
int ans=0;
bool cmp(pii a,pii b) {
	if(a.y!=b.y) return a.y<b.y;
	return a.x<b.x;
}
bool use[maxn];
int pa[maxn];
int cho[maxn];
bool vis[maxn];
bool go(int k) {
	if(vis[k]) return 1;
	vis[k]=1;
	if(point[k].y!=point[k+1].y) return 0;
	vis[k+1]=1;
	return go(pa[k+1]);
}
bool check(int k) {
	memset(vis,0,sizeof(vis));
	return go(k);
}
void dfs(int k) {
	if(k==n+1) {
		for(int i=1;i<=n;i+=2) {
			Ps(cho[i]); Pn(cho[i+1]);
			pa[cho[i]]=cho[i+1];
			pa[cho[i+1]]=cho[i];
		}
		puts("");
		for(int i=1;i<=n;i+=2) {
			ans+=(check(cho[i])||check(cho[i+1]));
			if(check(cho[i])||check(cho[i+1])) {
				Pn(cho[i]);
				Pn(cho[i+1]);
			}
		}
		return ;
	}
	if(k%2==0) {
		for(int i=cho[k-1]+1;i<=n;++i) {
			if(use[i]) continue;
			cho[k]=i; use[i]=1;
			dfs(k+1);
			use[i]=0;
		}
	} else {
		for(int i= (k==1) ? 1:(cho[k-2]+1);i<=n;++i) {
			if(use[i]) continue;
			cho[k]=i; use[i]=1;
			dfs(k+1);
			use[i]=0;
		}
	}

}
int main() {
	R(n);
	rep(i,1,n,1) {
		R(point[i].x); R(point[i].y);
	}
	sort(point+1,point+n+1,cmp);
	dfs(1);
	Pn(ans);
}
