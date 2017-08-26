#include<bits/stdc++.h>
#define PB push_back
#define LS (((k) << 1) + 1)
#define RS (((k) << 1) + 2)
#define LM ((l) + (r) >> 1)
#define RM (LM + 1)
//#define LOG(x) tb[(UI(x) * (UI)263572066) >> 27]
#define FST first
#define SCD second
#define retunr return
#define modp 1000000007
#define EPS 1e-7
#define INF 0x3f3f3f3f
#define MAX2 113
#define MAX3 1013
#define MAX4 10013
#define MAX5 100013
#define MAX6 1000013
#define MAXN 6 * MAX5
#define MANX MAXN
using namespace std;
int anc[5];
struct splay_node
{
    int num,maxx,ls,rs,fath;
    bool lazy;
}p[5];
struct lct
{
    inline void _pushdown(int i)
    {
        p[i].lazy^=1;
        p[p[i].ls].lazy^=1;
        p[p[i].rs].lazy^=1;
        int t=p[i].ls;p[i].ls=p[i].rs;p[i].rs=t;
    }
    inline void _pushup(int i)
    {
        p[i].maxx=max(max(p[p[i].ls].maxx,p[p[i].rs].maxx),p[i].num);
    }
    inline void _zig(int i)
    {
        int j=p[i].fath,k;
        k=p[j].fath;
        if(k!=0&&j==p[k].ls)p[k].ls=i;
        else if(k!=0)p[k].rs=i;
        p[i].fath=k;
        p[j].fath=i;
        p[p[i].rs].fath=j;
        p[j].ls=p[i].rs;
        p[i].rs=j;
        anc[i]=anc[j];
        p[i].maxx=p[j].maxx;
        _pushup(j);
    }
    inline void _zag(int i)
    {
        int j=p[i].fath,k;
        k=p[j].fath;
        if(k!=0&&j==p[k].ls)p[k].ls=i;
        else if(k!=0)p[k].rs=i;
        p[i].fath=k;
        p[j].fath=i;
        p[p[i].ls].fath=j;
        p[j].rs=p[i].ls;
        p[i].ls=j;
        anc[i]=anc[j];
        p[i].maxx=p[j].maxx;
        _pushup(j);
    }
    void _splay(int i)
    {
        int j;
        while(p[i].fath!=0)
        {
            j=p[i].fath;
            if(p[p[j].fath].lazy==true)_pushdown(p[j].fath);
            if(p[j].lazy==true)_pushdown(j);
            if(p[i].lazy==true)_pushdown(i);
            if(p[j].fath==0)
            {
                if(i==p[j].ls)_zig(i);
                else _zag(i);
            }
            else if(j==p[p[j].fath].ls)
            {
                if(i==p[j].ls)_zig(j),_zig(i);
                else _zag(i),_zig(i);
            }
            else
            {
                if(i==p[j].rs)_zag(j),_zag(i);
                else _zig(i),_zag(i);
            }
        }
    }
    int _find_max(int i)
    {
        while(i!=0)
        {
            if(p[i].lazy==true)_pushdown(i);
            if(p[i].ls!=0&&p[i].maxx==p[p[i].ls].maxx)i=p[i].ls;
            else if(p[i].maxx==p[i].num)return i;
            else i=p[i].rs;
        }
        return i;
    }
    void _access(int i)
    {
        int j=0;
        while(i!=0)
        {
            _splay(i);
            if(p[i].lazy==true)_pushdown(i);
            if(p[i].rs!=0)
            {
                p[p[i].rs].fath=0;
                anc[p[i].rs]=i;
            }
            p[i].rs=j;
            p[j].fath=i;
            _pushup(i);
            j=i;i=anc[i];
        }
    }
    void _setroot(int i)
    {
        _access(i);
        _splay(i);
        p[i].lazy^=1;
    }
}T;
typedef long long LL;
typedef unsigned int UI;
//typedef pair<int, int> P;
//const UI tb[32] = {13, 0, 27, 1, 28, 18, 23, 2, 29, 21, 19, 12, 24, 9, 14, 3, 30, 26, 17, 22, 20, 11, 8, 13, 25, 16, 10, 7, 15, 6, 5, 4};
const int N = 2e5 + 7;
int bit[N];
int sa[N] , t1[N] , t2[N] , c[N];
int Rank[N] , height[N];
char s[N];
int cur;
void buildsa(char *s , int n , int m) {
    int i , k , p , a1 , a2 , *x = t1 , *y = t2;
    memset(c , 0 , m << 2);
    for (i = 0 ; i < n ; ++ i) ++ c[x[i] = s[i]];
    for (i = 1 ; i < m ; ++ i) c[i] += c[i - 1];
    for (i = n - 1 ; i >= 0 ; -- i) sa[-- c[x[i]]] = i;
    for (k = 1 , p = 0; k < n ; k <<= 1 , p = 0) {
        for (i = n - k ; i < n ; ++ i) y[p ++] = i;
        for (i = 0 ; i < n ; ++ i) if (sa[i] >= k) y[p ++] = sa[i] - k;
        memset(c , 0 , m << 2);
        for (i = 0 ; i < n ; ++ i) ++ c[x[y[i]]];
        for (i = 1 ; i < m ; ++ i) c[i] += c[i - 1];
        for (i = n - 1 ; i >= 0 ; -- i) sa[-- c[x[y[i]]]] = y[i];
        swap(x , y) , p = 1 , x[sa[0]] = 0;
        for (i = 1 ; i < n ; ++ i) {
            a1 = sa[i - 1] + k < n ? y[sa[i - 1] + k] : -1;
            a2 = sa[i] + k < n ? y[sa[i] + k] : -1;
            x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && a1 == a2) ? p - 1 : p ++;
        }
        if (p >= n) break; m = p;
    }
    for (i = 0 ; i < n ; ++ i) Rank[sa[i]] = i;
    for (i = 0 , k = 0; i < n ; ++ i) {
        if (k) -- k; if (!Rank[i]) continue;
        int j = sa[Rank[i] - 1];
        while (s[i + k] == s[j + k]) ++ k;
        height[Rank[i]] = k;
    }
}

int lcp[25][N] , LOG[N];
void initLCP(int n) {
    for (int i = 2 ; i <= n ; ++ i) {
        LOG[i] = LOG[i >> 1] + 1;
    }
    for (int i = 0 ; i < n ; ++ i) {
        lcp[0][i] = height[i];
    }
    for (int j = 1 ; 1 << j < n ; ++ j) {
        for (int i = 0 ; i + (1 << j) <= n ; ++ i) {
            lcp[j][i] = min(lcp[j - 1][i] , lcp[j - 1][i + (1 << j - 1)]);
        }
    }
}
inline int LCP(int x , int y) {
    x = Rank[x] , y = Rank[y];
    if (x > y) swap(x , y); ++ x;
    int j = LOG[y - x + 1];
    return min(lcp[j][x] , lcp[j][y - (1 << j) + 1]);
}
const int M = 2e5 + 7;
int head[M], len[M];
pair <int, int> h[M];
char pre[M], suf[M];
int ans[M];
void upd(int x) {
	while (x <= cur) {
		bit[x] ++;
		x += x & -x;
	}
}
int get(int x) {
	int ret = 0;
	while (x) {
		ret += bit[x];
		x -= x & -x;
	}
	return ret;
}
int main()
{
	int T, n, q;
	scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &n, &q);
		head[0] = 0;
		cur = 0;
		memset(s, 0, sizeof s);
		for (int i = 0; i < n; ++ i) {
			scanf("%s", s + head[i]);
			len[i] = strlen(s + head[i]);
			h[i] = make_pair(-len[i], i);
			cur += len[i];
			s[cur] = '?';
			cur ++;
			for (int j = 0; j < len[i]; ++ j) {
				s[cur ++] = s[j + head[i]];
			}
			s[cur ++] = '#';
			head[i + 1] = cur;
		}
		for (int i = 0; i < q; ++ i) {
			scanf("%s%s", pre, suf);
			int lenpre = strlen(pre);
			int lensuf = strlen(suf);
			len[i + n] = lenpre + lensuf;
			h[i + n] = make_pair(-len[i + n], i + n);
			memcpy(s + cur, suf, lensuf);
			cur += lensuf;
			s[cur ++] = '?';
			memcpy(s + cur, pre, lenpre);
			cur += lenpre;
			s[cur ++] = '#';
			head[i + n + 1] = cur;
		}
		buildsa(s, cur, 128);
		initLCP(cur);
		sort(h, h + n + q);
		for (int i = 0; i < n + q; ++ i) {
			int id = h[i].second;
			if (id < n) {
				
				for (int i = 0; i < len[id]; ++ i) {
					upd(Rank[i + head[id]] + 1);
				}
			} else {
				int nw = Rank[head[id]];
				for (int i = nw; i < nw + 5; ++ i) {
				}
				cout << LCP(sa[nw], sa[nw + 1]) << endl;
				if (nw == cur - 1 || LCP(sa[nw], sa[nw + 1]) < len[id]) {
					ans[id] = 0;
				} else {
					puts("abc");
					int l = nw + 1;
					int r = cur;
					while (l <= r) {
						int mid = (l + r) >> 1;
						if (LCP(sa[nw], sa[mid]) >= len[id]) {
							r = mid - 1;
						} else {
							l = mid + 1;
						}
					}
					ans[id] = get(l + 1) - get(nw);
				}
			}
		}
		for (int i = n; i < n + q; ++ i) {
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}
