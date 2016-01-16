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
#define PROB "gates"
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
set<pii> ver,hiz; //ver means the seg direction
bool vis[2005][2005]; // grid is present by the location of left lower corner
int n,ans;
pii cur(1000,1000);
queue<pii> q;
static inline 
bool isLegal(pii pos) {
	if((pos.fi<0)||(pos.fi>2000)||(pos.se<0)||(pos.se>2000)) return 0;
	if(vis[pos.fi][pos.se]) return 0;	
	return 1;
}
void bfs(pii cur) {
	while(q.size()) q.pop();
	vis[cur.fi][cur.se]=1;
	q.push(cur);
	while(q.size()) {
		pii qf=q.front(); q.pop();
		pii next;
		if(!hiz.count(qf)) {
			next=qf; next.second++;
			if(isLegal(next)) {
				vis[next.fi][next.se]=1;
				q.push(next);
			}
		} if(!ver.count(qf)) {
			next=qf; next.fi++;
			if(isLegal(next)) {
				vis[next.fi][next.se]=1;
				q.push(next);
			}
		}
		next=qf; next.se--;
		if(!hiz.count(next)) {
			if(isLegal(next)) {
				vis[next.fi][next.se]=1;
				q.push(next);
			}
		}
		next=qf; next.fi--;
		if(!ver.count(next)) {
			if(isLegal(next)) {
				vis[next.fi][next.se]=1;
				q.push(next);
			}
		}
	}
	
}
int main() {
	Redirect();
	R(n); char dir=0;
	for(int i=1;i<=n;++i) {
		dir=0; while(!isalpha(dir)) dir=getchar();
		if(dir=='N') {
			ver.insert(make_pair(cur.fi-1,cur.se));
			cur.se++;
		} else if(dir=='S') {
			ver.insert(make_pair(cur.fi-1,cur.se-1));
			cur.se--;
		} else if(dir=='E') {
			hiz.insert(make_pair(cur.fi,cur.se-1));
			cur.fi++;
		} else if(dir=='W') {
			hiz.insert(make_pair(cur.fi-1,cur.se-1));
			cur.fi--;
		}
	}
	for(int i=0;i<=2000;++i) {
		for(int j=0;j<=2000;++j) {
			if(!vis[i][j]) {
				ans++;
				bfs(mp(i,j));
			}
		}
	}
	Pn(ans-1);
}

