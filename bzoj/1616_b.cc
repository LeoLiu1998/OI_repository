//yeguanghao
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include  <functional>
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
	x = 0; int f = 1; char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	x *= f;
}
 
#define mp make_pair
#define pb push_back
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
 
typedef pair<int, int> pii;
#define px first
#define py second
struct Q {
	pii pos;int times;
	Q(pii _pos = mp(0, 0), int _times = 0) {
		pos = _pos; times = _times;
	}
 
};
inline void R(pii &x) {
	R(x.first); R(x.second);
}
const int maxn = 100;
int map[maxn+5][maxn+5];
int n, m, t;
pii s, e;
int ans = 0;
pii mov[4] = { mp(0,1),mp(1,0),mp(-1,0),mp(0,-1) };
pii add(pii a, pii b) {
	pii ret;
	ret.first = a.first + b.first;
	ret.second = a.second + b.second;
	return ret;
}
bool check(pii a) {
	if (a.first >= 1 && a.first <= n&&a.second >= 1 && a.second <= m&&map[a.first][a.second]) return 1;
	return 0;
}
void bfs() {
	queue<Q> q;
	q.push(Q(s, 0));
	while (q.size()) {
		Q qf = q.front();
		if (qf.times > t) break;
		if (qf.pos == e&&qf.times==t) ans++;
		pii cur;
		for (int i = 0; i < 4; ++i) {
			cur = add(qf.pos ,mov[i]);
			if (check(cur)&&qf.times+1<=t) {
				q.push(Q(cur,qf.times +1));
//				been[cur.first][cur.second][qf.times + 1] = 1;
			}
		}
		q.pop();
	}
}
int been[103][103][16];
void dfs(Q cur) {
	if(cur.pos==e&&cur.times==t) ans++;
	been[cur.pos.px][cur.pos.py][cur.times]=1;
	pii next;
	for(int i=0;i<4;++i) {
		next=add(cur.pos,mov[i]); 
		if(check(next)&&cur.times<t&&(1)) { //!been[next.px][next.py][cur.times+1])) {
			dfs(Q(next,cur.times+1));
		}
	}
}
int main()
{
	R(n); R(m); R(t);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			char cur = getchar();
			while (cur != '.'&&cur != '*') cur = getchar();
			map[i][j] = cur == '.';
		}
		getchar();
	}
	R(s); R(e);
	dfs(Q(s,0));	//	bfs();
	Pn(ans);
	return 0;
}
