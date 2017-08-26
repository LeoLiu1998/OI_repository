//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
void Redirect() {
	freopen(PROB".in","r",stdin);
#ifndef YGHDEBUG
	freopen(PROB".out","w",stdout);
#endif
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
using namespace std;
typedef long long ll;

struct P {
    int l, r;
} x[100010];

inline bool cmp(const P & x, const P & b) {
    return x.l < b.l;
}

int n, m, now, ans, l, r, i, t;

int main() {
    while (~scanf("%d %d", &n, &m)) {
        
        for (i = 1; i <= n; ++i) {
        	R(x[i].l); R(x[i].r);
        }
        sort(x+1, x+1+n, cmp);
        t = n;
        n = 0;
        
        for (i = 1; i <= t; i++) {
            if (i != 1 && x[i].l <= x[n].r) {
                x[n].r = max(x[n].r, x[i].r);
            } else {
                x[++n].l = x[i].l;
                x[n].r = x[i].r;
            }
        }
        
        l = 1;now = 0;ans = 0;
        
        for (i = 1; i <= n; ++i) {
            if (i != 1)
                now += x[i].l - x[i-1].r - 1;
            while (i != 1 && now > m) {
                now -= x[l+1].l - x[l].r - 1;
                ++l;
            }
            ans = max(ans, x[i].r - x[l].l + 1 + m - now);
        }
        
        printf("%d\n", ans);
    }
    return 0;
}
