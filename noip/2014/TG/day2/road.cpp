//yeguanghao
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#ifdef DEBUG
#include <iostream>
#include <iomanip>
#endif
#include <cctype>
#include <climits>
#include <algorithm>
using namespace std;
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10 +  ch- '0'; ch=getchar();}
	x*=f;
}
#define mp make_pair
#define pb push_back
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define PROB "road"
void Redirect() {
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
}
const int maxn=10000;
vector<int> in[maxn+5],out[maxn+5];
int s,t,n,m;
int dist[maxn+5];
bool tot[maxn+5],exist[maxn+5];
static inline void input() {
	R(n); R(m);
	for(register int i=1,l,r;i<=m;++i) {
		R(l); R(r);
		if(l==r) continue;
		out[l].pb(r);
		in[r].pb(l);
	}
	R(s); R(t);
}
void dfs(int cur) {
	tot[cur]=1;
	for(int i=0;i<(int)in[cur].size();++i) {
		if(!tot[in[cur][i]]) 
			dfs(in[cur][i]);
	}
}
int SPFA() {
	memset(exist,0,sizeof(exist));
	memset(dist,0x3f,sizeof(dist));
	queue<int> q; q.push(s); dist[s]=0; exist[s]=1;
	while(!q.empty()) {
		int qf=q.front();
		for(int i=0;i<(int)out[qf].size();++i) {
			int cur=out[qf][i];
			if(tot[cur]&&dist[cur]>dist[qf]+1 ) {
				for(int j=0;j<(int)out[cur].size();++j) {
					if(!tot[out[cur][j]]) goto NEXT;
				}
				dist[cur]=dist[qf]+1;
				if(!exist[cur]) {
					q.push(cur);
					exist[cur]=1;
				}			
			}
NEXT:;
		}
     	q.pop();
		exist[qf]=0;
	}
	if(dist[t]==0x3f3f3f3f) return -1;
	return dist[t];
}
int main() {
	Redirect();
	input();
	dfs(t);
	Pn(SPFA());
}
