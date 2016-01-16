#ifdef YGHDEBUG
#include <iostream>
#include <iomanip>
#endif
#include <cstdio>
#include <climits>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
#define index idx
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
inline void R(int &x) {
	x = 0; int f = 1; char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
	while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	x *= f;
}
#define next nxt
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int  maxn = 200050, maxm = 1000050;
int head[maxn], dfn[maxn], low[maxn],ecnt=2;
int next[maxm], to[maxm];
bool instack[maxn];
int scccnt = 0, belong[maxn];
int in[maxn], out[maxn];
stack<int> s;
void add_edge(int u, int v) {
	to[ecnt] = v; next[ecnt] = head[u]; head[u] = ecnt++;
}
int n, m,index;

void tarjan(int k) {
//	Pn(k);
	s.push(k);
	instack[k] = 1;
	low[k] = dfn[k] = ++index;
	for (int i = head[k]; i; i = next[i]) {
		if (!dfn[to[i]]) {
			tarjan(to[i]);
			low[k] = min(low[k], low[to[i]]);
		}
		else if(instack[to[i]]){
			low[k] = min(low[k], dfn[to[i]]);
		}
	}
	int cur;
	if (dfn[k] == low[k]) {
		scccnt++;
		do {
			if(!s.size()) break;
			cur=s.top();
			belong[cur] = scccnt;
			instack[cur] = 0;
			s.pop();
		}while(s.size()&&cur!=low[k]);
	}
}
int main() {
	R(n); R(m);
	for (int i = 1; i <= m; ++i) {
		int x, y; R(x); R(y);
		add_edge(x, y);
	}
	for (int i = 1; i <= n; ++i) {
		if (!dfn[i]) tarjan(i);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = head[i]; j; j = next[j]) {
			if (belong[i] != belong[to[j]]) {
				in[belong[to[j]]]++;
				out[belong[i]]++;
			}
		}
	}
#ifdef YGHDEBUG
				for (int j = 1; j <= n;++j) {
					Ps(belong[j]);
				}
				puts("");
				for (int j = 1; j <= scccnt; ++j) {
					Ps(in[j]); Pn(out[j]);
				}
#endif
	int incnt = 0;
	for (int i = 1; i <= scccnt; ++i) {
		incnt += (out[i] == 0);
	}
	int ans = 0;
	if (incnt == 1) {
		for (int i = 1; i <= scccnt; ++i) {
			if (out[i] == 0) {
				for (int j = 1; j <= n; ++j) {
					ans += (belong[j] == i);
				}
				Pn(ans);
				return 0;
			}
		}
	} else {
		puts("0");
	}
	return 0;
}
