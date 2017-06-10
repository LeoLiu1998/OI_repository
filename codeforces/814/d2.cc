#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

typedef vector<vector<ll> > matrix;

matrix mul(matrix a, matrix b){
    matrix c;
    c.resize(a.size());
    for (int i = 0; i < c.size(); i++)
        c[i].resize(b[0].size(), 0);
    for (int i = 0; i < c.size(); i++)
        for (int j = 0; j < c[i].size(); j++)
            for (int k = 0; k < b.size(); k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]);
    return c;
}

matrix def;

matrix bpow(matrix a, ll st){
    if (st == 0)
        return def;
    if (st == 1)
        return a;
    matrix b = bpow(a, st >> 1);
    b = mul(b, b);
    if (st & 1)
        b = mul(a, b);
    return b;
}

ll AR = 19, BR = 13, CR = 23, XR = 228, YR = 322, MOD = 1e9 + 993;

ll myrand(){
    ll ZR = (XR * AR + YR * BR + CR) % MOD;
    XR = YR;
    YR = ZR;
    return ZR;
}

ll sqr(ll x){
    return x * x;
}

const ll llinf = 2e18;

const ld EPS = 1e-9;

const ld PI = atan2(0, -1);

const int maxn = 2e5 + 100, inf = 1e9 + 100, mod = 1e9 + 7;

int p[maxn];

vector<int> e[maxn];

int n;

pair<ll, pair<ll, ll> > a[maxn];

ll dist(pair<ll, ll> x, pair<ll, ll> y){
    return sqr(x.first - y.first) + sqr(x.second - y.second);
}

bool vis[maxn];

ld answer;

ll fun(int h){
    if (h < 2 || (h & 1) == 1)
        return 1;
    return -1;
}

void dfs(int v, int h){
    vis[v] = 1;
    answer += PI * a[v].first * a[v].first * fun(h);
    cout<<a[v].second.first<<" "<<a[v].second.second<<" "<<a[v].first<<" "<<h<<" "<<fun(h)<<endl;
    for (int i = 0; i < e[v].size(); i++)
        dfs(e[v][i], h + 1);
}

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    #else
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].second.first >> a[i].second.second >> a[i].first, p[i] = -1;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (dist(a[i].second, a[j].second) <= a[i].first * a[i].first && p[j] == -1)
                e[i].push_back(j), p[j] = i;
    for (int i = n - 1; i >= 0; i--)
        if (!vis[i])
            dfs(i, 0);
    cout << fixed << setprecision(20) << answer;
}
