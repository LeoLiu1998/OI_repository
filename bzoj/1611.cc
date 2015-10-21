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
const int maxn=505;
bool been[maxn][maxn];
int t[maxn][maxn];
typedef pair<int,pair<int,int> > Meteor;
priority_queue<Meteor,vector<Meteor>,greater<Meteor> > pq;
typedef pair<int,int> pii;
int m;
Meteor get() {
	int a,b,c; R(a); R(b); R(c);
	return mp(c,mp(a,b));
}
#define x first
#define y second
pii mov[4]={mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
bool check(pii a) {
	if(a.x>=0&&a.y>=0&&a.x<=502&&a.y<=502) return 1;
	return 0;
}
pii add(pii a,pii b) {
	pii ret=mp(a.first+b.first,a.second+b.second);
	return ret;
}
const int INF=0x3f3f3f3f;
void remove_p(pii a) {
	been[a.first][a.second]=1;
	t[a.first][a.second]=INF;
}
void remove(pii a) {
	remove_p(a);
	for(int i=0;i<4;++i) {
		pii cur=add(a,mov[i]);
		if(check(cur)) {
			remove_p(cur);
		}
	}
}
void print() {
	for(int i=0;i<=15;++i) {
		for(int j=0;j<=15;++j) {
			cout<<setw(5)<<(t[i][j]==INF?-1:t[i][j]);
		}
		cout<<endl;
	}
	cout<<"\n\n";
}

void bfs() {
	memset(t,0x3f,sizeof(t));
	queue<Meteor> q; q.push(mp(0,mp(0,0)));
	t[0][0]=0;
	while(q.size()) {
		Meteor qf=q.front();
	//	Ps(qf.first); Ps(qf.second.first); Pn(qf.second.second); print();
		while(pq.size()&&pq.top().first<=qf.first) {
			remove(pq.top().second);
			pq.pop();
		}
		if(been[qf.second.first][qf.second.second]) goto NEXT;
		been[qf.second.first][qf.second.second]=1;
		for(int i=0;i<4;++i) {
			pii cur=add(qf.second,mov[i]);
			if(check(cur)&&(!been[cur.first][cur.second])) {
				t[cur.first][cur.second]=qf.first+1;
				q.push(mp(qf.first+1,cur));	
			}
		}
NEXT:;
		q.pop();
	}

}
int ans=INF;
pii pos;
int main() {
	R(m);
	rep(i,1,m,1) pq.push(get());
	bfs();
	for(int i=0;i<303;++i) {
		for(int j=0;j<303;++j) {
			if(t[i][j]<ans) {
				ans=t[i][j]; pos=mp(j,i);
			}
		}
	}
	if(ans==2) ans++;
	if(ans==INF) puts("-1");
	else Pn(ans);
}
