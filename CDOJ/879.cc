#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline int read(){
	int x; R(x);
	return x;
}
const int maxn=10005;
const int Nmax = 10005;
int n, m;
int w[Nmax];
long long wsq[Nmax]; 
long long dp[Nmax][2]; 

struct queue{
	int num[Nmax];
	int head, tail;
	
	inline void init(){ head = 0; tail = -1; } 
	inline void push_back(int a){ num[++tail] = a; }
	inline void pop_back() { --tail; }
	inline void pop_front() { ++head; }
	inline int size() { return tail - head + 1; }
}q;

inline double get_k(int i, int j, int nw)
{
	if(w[i + 1] == w[j + 1]) return 1e200;
	return 1.0 * (dp[i][nw] + wsq[i + 1] - dp[j][nw] - wsq[j + 1]) / (w[i + 1] - w[j + 1]);
}

int main()
{
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	
	n = read(); m = read();
	for(int i = 1; i <= n; ++i) w[i] = read();
	sort(w + 1, w + n + 1);
	for(int i = 1; i <= n; ++i) wsq[i] = w[i] * w[i];
	
	for(int i = 1; i <= n; ++i) dp[i][1] = wsq[i] + wsq[1] - 2 * w[1] * w[i]; 
	for(int j = 2; j <= m; ++j)
	{
		int nw = j & 1, lst = nw ^ 1;
		
		q.init(); q.push_back(j - 1);
		for(int i = j; i <= n; ++i)
		{
			while(q.size() > 1 && get_k(q.num[q.head], q.num[q.head + 1], lst) <= 2.0 * w[i]) q.pop_front();
			dp[i][nw] = dp[q.num[q.head]][lst] + wsq[i] - 2 * w[q.num[q.head] + 1] * w[i] +  wsq[q.num[q.head] + 1];
			while(q.size() > 1 && get_k(q.num[q.tail-1], q.num[q.tail], lst) >= get_k(q.num[q.tail], i, lst)) q.pop_back();
			q.push_back(i);
		}
	}
	
	cout << dp[n][m & 1] << endl;
	
	return 0;
}
