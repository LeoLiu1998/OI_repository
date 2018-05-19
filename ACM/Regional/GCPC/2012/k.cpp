#include <bits/stdc++.h>
using namespace std;
int t;
int n,m;
typedef pair<int,int> pii;
typedef vector<pii> Node;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
Node node[10005];
int dist[10005];
int tres[10];
int tn;
map<pii,int> fdis;
int cost;
void Dijkstra(int s) {
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	memset(dist,0x3f,sizeof dist);
	dist[s]=0;
	int x;
	pq.push(mp(0,s));
	while(pq.size()) {
		pii cur=pq.top();
		pq.pop();
		if(dist[x=cur.second]<cur.first) continue;
		for(auto it:node[x]) {
			if(dist[x]+it.se<dist[it.fi]) {
				dist[it.fi]=dist[x]+it.se;
				pq.push(mp(dist[it.fi],it.fi));
			}
		}
	}
	fdis[mp(0,s)]=dist[0];
	fdis[mp(s,0)]=dist[0];
	for(int i=1; i<=tn; ++i) {
		fdis[mp(s,tres[i])]=fdis[mp(tres[i],s)] = dist[tres[i]];
	}
}
int main() {
	scanf("%d",&t);
	for(int qwq=1; qwq<=t; ++qwq) {
		if(qwq==62) {
			freopen("data.txt","w",stdout);
			scanf("%d%d",&n,&m);
			printf("%d %d\n",n,m);
			for(int i=1;i<=m;++i) {
				int u,v,w;
				scanf("%d%d%d",&u,&v,&w);
				printf("%d %d %d\n",u,v,w);
			}
			scanf("%d",&tn);
			printf("%d\n",tn);
			for(int i=1; i<=tn; ++i) {
				scanf("%d",&tres[i]);
				printf("%d ",tres[i]);
			}
			puts("");

			scanf("%d",&cost);
			printf("%d\n",cost);
		}	
		int ans=0;
		fdis.clear();
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; ++i)
			node[i].clear();
		for(int i=1; i<=m; ++i) {
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			node[u].pb(mp(v,w));
			node[v].pb(mp(u,w));
		}
		scanf("%d",&tn);
		for(int i=1; i<=tn; ++i) scanf("%d",&tres[i]);
		Dijkstra(0);
		for(int i=1; i<=tn; ++i)
			Dijkstra(tres[i]);

		
		tres[0]=0;
		scanf("%d",&cost);
		sort(tres+1,tres+tn+1);
		do {
			int cur_ans=0;
			long long ccost=0;
			for(int i=1; i<=tn; ++i) {
				ccost+=fdis[mp(tres[i-1],tres[i])];
				if(ccost>cost)
					break;
				if(ccost+fdis[mp(tres[i],0)]<=cost)
					cur_ans=i;
			}
			ans=max(ans,cur_ans);
		} while(next_permutation(tres+1,tres+tn+1));
		printf("%d\n",ans);
	}
}
