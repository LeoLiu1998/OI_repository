/*ID:yeguang2
PROG:wormhole
LANG:C++
*/
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
int ans=0;
typedef pair<int,int> pii;
pii poi[20];
int n;
bool use[20];
int pai[20];
int is[20];
vector<pii> cho;

#define px first
#define py second
void init() {
	memset(is,0,sizeof(is));
	for(int i=0;i<cho.size();++i) {
		pai[cho[i].first]=cho[i].second;
		pai[cho[i].second]=cho[i].first;
	}
}
bool vis[20];
bool go(int k) {
	if(vis[k]) return 1;
	vis[k]=1;
	pii cur=poi[k];
	int to=0;
	for(int i=1;i<=n;++i) {
		if(poi[i].py!=cur.py||poi[i].px<=cur.px) continue;
		if(poi[to].px>poi[i].px) to=i;
	}
	if(!to) return 0;
	vis[to]=1;
	return go(pai[to]);
}
bool check(int k) {
	memset(vis,0,sizeof(vis));
	bool ret=go(k);
/*	if(ret) {
		rep(i,1,(n>>1),1) {
			Ps(cho[i-1].px); Pn(cho[i-1].py);
		}
		cout<<"p:"<<k<<endl<<endl;
	}
*/	return ret;
}
void dfs(int k) { // k means now is choosing the kth pair
	if(k==(n>>1)+1) {
		init();
/*		rep(i,1,n,1) {
			Ps(pai[i]);
		}
		puts("");
*/		rep(i,1,n,1) {
			bool ret=check(i);
			if(ret) {
				if(is[ret]) continue;
				is[ret]=is[pai[ret]]=1;
				ans++;
			}
		}
		return ;
	}
	int fi=1;
	while(use[fi]) fi++;
	for(int i=fi;i<=n;++i) {
		if(use[i]) continue;
		if((cho.size())&&(i<=cho.back().px)) continue;
		for(int j=i+1;j<=n;++j) {
			if(use[j]) continue;
			cho.pb(mp(i,j));
			use[i]=1; use[j]=1;
			dfs(k+1);
			use[i]=use[j]=0;
			cho.erase(cho.end()-1);
		}
	}

}
int main() {
	freopen("wormhole.in","r",stdin);
	freopen("wormhole.out","w",stdout);
	R(n);
	poi[0].px=1000000000;
	rep(i,1,n,1) {
		R(poi[i].px); R(poi[i].py);	
	}
	dfs(1);
	Pn(ans);
}
