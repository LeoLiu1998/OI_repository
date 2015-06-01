#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define R(x) scanf("%d",&x)
typedef long long ll;
int n,m;
#ifdef DEBUG 
#include <iostream>
#endif
const int maxn=1005;
struct Edge {
	int a,b;
	double dis;
	Edge(int _s=0,int _t=0,double _dis=0) {
		a=_s; b=_t; dis=_dis;
	}
	bool operator < (const Edge &a) const {
		return dis<a.dis;
	}
};
struct Point {
	int x,y;
	vector<int> e;
	Point(int _x=0,int _y=0) {
		x=_x; y=_y;
	}
};
Point p[maxn];
int f[maxn];
int getf(int a) {
	if(f[a]==a) return a;
	f[a]=getf(f[a]);
	return f[a];
}
inline double dist(int a,int b) {
	double ans=0;
	ans+=(double(p[a].x)-p[b].x)*(p[a].x-p[b].x);
	ans+=(p[a].y-p[b].y)*(p[a].y-p[b].y);
	ans=sqrt(ans);
}
vector <Edge> edge;
void Kruskal();
double ans=0;
int cnt=0;
int main() {
	R(n); R(m);
	for(int i=1,x,y;i<=n;++i) {
		f[i]=i;
		R(x); R(y);
		p[i]=Point(x,y);
	}
	for(int i=1;i<n;++i) {
		for(int j=i+1;j<=n;++j) {
			edge.push_back(Edge(i,j,dist(i,j)));
			p[i].e.push_back(edge.size()-1);
			p[j].e.push_back(edge.size()-1);
		}
	}
	for(int i=1,a,b;i<=m;++i) {
		R(a); R(b);
		edge.push_back(Edge(a,b,0));
	}
	Kruskal();
	printf("%.2f",ans);
}


void Kruskal() {
	Edge cur;
	sort(edge.begin(),edge.end());
	for(int i=0;i<edge.size()&&cnt!=n-1;++i) {
		cur=edge[i];
		int fa=getf(cur.a);
		int fb=getf(cur.b);
		if(fa==fb) continue;
		f[cur.a]=f[cur.b]=min(fa,fb);
		ans+=cur.dis;
		cnt++;
	}
}
