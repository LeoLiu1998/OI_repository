#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#define R(x) scanf("%d",&x)
using namespace std;
struct Edge{
	int t;
	double dist;
	Edge(int _t=0,double _dist=0) { t=_t;dist=_dist;}
};
struct Point {
	int x,y;
	vector<Edge> e;
	Point(int _x=0,int _y=0) {
	x=_x;y=_y;e.clear();}
};
const int maxn=200;
const int oo=49302458;
double d[maxn];
bool use[maxn];
Point p[maxn];
int n,m;
int s,t;
void add_edge(int,int);
void dijkstra(int);
int main()  {
	R(n);
	for(register int i=1,a,b;i<=n;++i) {
		R(a); R(b);
		p[i]=(Point(a,b));
	}
	R(m);
	for(int i=1,a,b;i<=m;++i ) {
		R(a); R(b);
		add_edge(a,b);
	}
	R(s); R(t);
	dijkstra(s);
	printf("%.2f\n",d[t]);
}

void add_edge(int a,int b) {
	double dis=(p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y);
	dis=sqrt(dis);
	p[a].e.push_back(Edge(b,dis));
	p[b].e.push_back(Edge(a,dis));
}



struct rec {
	int k;
	double dist;
	rec(){}
	rec(int _k,int _dist) {
		k=_k; dist=_dist;
	}
	bool operator < (const rec &a) const {
		return dist>a.dist;
	}
};

priority_queue<rec> pq;
void dijkstra(int s) {
	for(int i=0;i<150;++i) {
		d[i]=oo;
	}
	d[s]=0;
	rec cur;
	pq.push(rec(s,0));
	while(pq.size()) {
		cur=pq.top();
		pq.pop();
		if(use[cur.k]) continue;
		use[cur.k]=true;
		for(int i=0;i<p[cur.k].e.size();++i) {
			if(d[cur.k]+p[cur.k].e[i].dist<d[p[cur.k].e[i].t]) {
				d[p[cur.k].e[i].t]=d[cur.k]+p[cur.k].e[i].dist;
				pq.push(rec(p[cur.k].e[i].t,d[p[cur.k].e[i].t]));
			}
		}
	}
	return ;
}
