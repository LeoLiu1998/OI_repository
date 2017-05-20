// team.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
inline void R(int &x) {
	x = 0; int f = 1; char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
	while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	x *= f;
}
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 500500;
int rank[4][maxn];
int rev[4][maxn];
int vis[maxn];
int n,k;
void solve(int coach, int pos) {
	while (vis[rank[coach][rank[coach][0] + 1]]) {
		rank[coach][0]++;
	}
	vis[rank[coach][rank[coach][0] + 1]] = coach;
}
int main()
{	
	R(n);
	for (int i = 1; i < 4; ++i) {
		for (int j = 1; j <= n; ++j) {
			R(rank[i][j]);
			//rev[i][rank[i][j]] = j;
		}
	}
	R(k);

	for (int i = 0; i < n; ++i) {
		solve(i % 3 + 1, i);
	}
	//for (int i = 1; i <= n; ++i) {
	//	putchar('A' + vis[i] - 1);
	//}
	//putchar('\n');
	putchar('A' + vis[k] - 1);
	//system("pause");
	return 0;
}

