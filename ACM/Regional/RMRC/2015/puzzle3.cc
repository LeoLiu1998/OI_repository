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

typedef unsigned long long ST;
const ST T = (0x55 << 16) | (0xAA << 8) | (0xFF);

void relax(map<ST, int> &D, queue<ST> &Q, ST x, int nd) {
    int &od = D[x];
    if (!od) {
        od = nd;
        if (nd <= 6) Q.push(x);
    }
}

void go(ST S, map<ST, int> &D) {
    queue<ST> Q;
    Q.push(S);
    D[S] = 1;
    while (!Q.empty()) {
        ST x = Q.front(); Q.pop();
        int d = D[x];
        for (int i = 0; i < 4; ++i) {
            ST mask = 0x000000FFULL << (8*i);
            ST b = x & mask;
            relax(D, Q, (x & ~mask) | ((b>>2 | b<<6) & mask), d+1);
            relax(D, Q, (x & ~mask) | ((b>>6 | b<<2) & mask), d+1);
            mask = 0x03030303ULL << (2*i);
            b = x & mask;
            relax(D, Q, (x & ~mask) | ((b>>8 | b<<24) & mask), d+1);
            relax(D, Q, (x & ~mask) | ((b>>24 | b<<8) & mask), d+1);
        }
    }
}

char row[10];
int main(void) {
    ST S = 0;
    while(~scanf("%s",row)) {
    for (int i = 0; i < 4; ++i) {
	    if(i)
        scanf("%s", row);
        for (int j = 0; j < 4; ++j) {
            ST b = 0;
            switch (row[j]) {
            case 'Y': ++b;
            case 'B': ++b;
            case 'G': ++b;
            }
            S = (S<<2) | b;
        }
    }
    map<ST, int> distS, distT;
    go(S, distS);
    go(T, distT);
    int ans = 20;
    for (auto a: distS)
        if (a.first == T) ans = a.second-1;
        else {
            auto b = distT.find(a.first);
            if (b != distT.end()) ans = min(ans, a.second + b->second - 2);
        }
    printf("%d\n", ans);
    }
    return 0;
}
