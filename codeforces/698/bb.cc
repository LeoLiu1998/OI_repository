#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)



template<int um> class UF { // from kmjp
public:
	vector<int> par;
	UF() { par = vector<int>(um, 0); rep(i, 0, um) par[i] = i; }
	int operator[](int x) { return par[x] == x ? x : par[x] = operator[](par[x]); }
	void operator()(int x, int y)
	{
		x = operator[](x); y = operator[](y);
		if (x != y) par[x] = y;
	}
};
//-----------------------------------------------------------------
int n;
int a[201010];
//-----------------------------------------------------------------
int main() {
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", &a[i]), a[i]--;

	UF<201010> uf;
	vector<int> roots, loops;
	rep(i, 0, n) {
		if (a[i] == i) {
			roots.push_back(i);
			continue;
		}

		if (uf[i] == uf[a[i]])
			loops.push_back(i);
		else
			uf(i, a[i]);
	}

	int ans = 0;
	if (roots.size() == 0) {
		if (loops.size() != 0) {
			int root = loops[0];

			a[root] = root; ans++;
			rep(i, 1, loops.size()) a[loops[i]] = root, ans++;
		}
	}
	else {
		int root = roots[0];

		a[root] = root;
		rep(i, 1, roots.size()) a[roots[i]] = root, ans++;
		rep(i, 0, loops.size()) a[loops[i]] = root, ans++;
	}

	printf("%d\n", ans);
//	rep(i, 0, n) printf("%d ", a[i] + 1);
	printf("\n");
}
