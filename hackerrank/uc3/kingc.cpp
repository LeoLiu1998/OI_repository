//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#ifdef _WIN32
#define Pln(x) printf("%I64d\n",x)
#define Pls(x) printf("%I6d ",x)
#else
#define Pln(x) printf("%lld\n",x)
#define Pls(x) printf("%lld ",x)
#endif
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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define up(i,j,n)		for (int i = j; i <= n; i++)
#define down(i,j,n)	for (int i = j; i >= n; i--)
#define cmax(a,b)		a = max (a, b)
#define cmin(a,b)		a = min (a, b)
#define pii			pair<int, int>
#define fi			first
#define se			second
#define Auto(i,node)	for (int i = LINK[node]; i; i = e[i].next)

struct splay_node {
    int num,maxx,ls,rs,fath;
    bool lazy;
} p[5];
int anc[5];
const int mod=233;
struct lct {
    inline void _pushdown(int i) {
        p[i].lazy^=1;
        p[p[i].ls].lazy^=1;
        p[p[i].rs].lazy^=1;
        int t=p[i].ls;
        p[i].ls=p[i].rs;
        p[i].rs=t;
    }
    inline void _pushup(int i) {
        p[i].maxx=max(max(p[p[i].ls].maxx,p[p[i].rs].maxx),p[i].num);
    }
    inline void _zig(int i) {
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
    inline void _zag(int i) {
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
    void _splay(int i) {
        int j;
        while(p[i].fath!=0) {
            j=p[i].fath;
            if(p[p[j].fath].lazy==true)_pushdown(p[j].fath);
            if(p[j].lazy==true)_pushdown(j);
            if(p[i].lazy==true)_pushdown(i);
            if(p[j].fath==0) {
                if(i==p[j].ls)_zig(i);
                else _zag(i);
            } else if(j==p[p[j].fath].ls) {
                if(i==p[j].ls)_zig(j),_zig(i);
                else _zag(i),_zig(i);
            } else {
                if(i==p[j].rs)_zag(j),_zag(i);
                else _zig(i),_zag(i);
            }
        }
    }
    int _find_max(int i) {
        while(i!=0) {
            if(p[i].lazy==true)_pushdown(i);
            if(p[i].ls!=0&&p[i].maxx==p[p[i].ls].maxx)i=p[i].ls;
            else if(p[i].maxx==p[i].num)return i;
            else i=p[i].rs;
        }
        return i;
    }
    void _access(int i) {
        int j=0;
        while(i!=0) {
            _splay(i);
            if(p[i].lazy==true)_pushdown(i);
            if(p[i].rs!=0) {
                p[p[i].rs].fath=0;
                anc[p[i].rs]=i;
            }
            p[i].rs=j;
            p[j].fath=i;
            _pushup(i);
            j=i;
            i=anc[i];
        }
    }
    void _setroot(int i) {
        _access(i);
        _splay(i);
        p[i].lazy^=1;
    }
} T;
struct Mat {
    const static int N=15;
    ll d[17][17];
    Mat() {
        memset(d,0,sizeof d);
    }
    Mat operator * (const Mat &a) const  {
        Mat ret;
        for(int i=0; i<=N; ++i)  {
            for(int j=0; j<=N; ++j) {
                ret.d[i][j]=0;
                for(int k=0; k<=N; ++k) {
                    ret.d[i][j]+=d[i][k]*a.d[k][j];
                    ret.d[i][j]%=mod;
                }
            }
        }
        return ret;
    }
};
Mat qpow(Mat x, ll p) {
    Mat ret;
    for(int i=0; i<=ret.N; ++i) ret.d[i][i]=1;
    while(p) {
        if(p&1) {
            ret=ret*x;
        }
        x=x*x;
        p>>=1;
    }
    return ret;
}


string mat[8];
bool vis[8][8];
unordered_map<ll, ll> arr[2];
string target;
int mid;

int count_bit(ll a) {
    int res = 0;
    while (a) {
        res++;
        a = (a&(a - 1));
    }
    if (res % 2 == 0) return 1;
    else return -1;
}


void dfs(int row, int col, int l,int depth,ll mask,int dir) {
    vis[row][col] = true;
    int indx = row * 8 + col;
    if (depth != 0) {
        mask = mask | (1ll << indx);
    }
    if (depth == l) {
        if (dir == 1) {
            for (ll temp = mask; ; temp = ((temp - 1)&mask)) {
                if (arr[dir].find(temp) == arr[dir].end()) arr[dir][temp] = 1;
                else arr[dir][temp]++;
                if (temp == 0) break;
            }
        }
        else {
            if (arr[dir].find(mask) == arr[dir].end()) arr[dir][mask] = 1;
            else arr[dir][mask]++;
        }
    }
    int mul = 2 * dir - 1;
    if (depth < l) {
        for (int dr = -1; dr <= 1; dr++) {
            if (row + dr < 0 || row + dr >= 8) continue;
            for (int dc = -1; dc <= 1; dc++) {
                if (dr == dc&& dc == 0) continue;
                if (col + dc < 0 || col + dc >= 8) continue;
                if (vis[row + dr][col + dc]) continue;
                if (target[mid + mul*(depth + 1)] != mat[row + dr][col + dc]) continue;
                dfs(row + dr, col + dc, l, depth + 1,mask,dir);
            }
        }
    }
    vis[row][col] = false;
}

int main() {

    int l;
    cin >> l;
    cin >> target;
    for (int i = 0; i < 8; i++) cin >>mat[i];
    mid = l / 2;
    ll ans = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (mat[i][j] == target[mid]) {
                arr[0].clear();
                arr[1].clear();
                dfs(i, j, l - mid - 1, 0,0, 1);
                dfs(i, j, mid, 0, 0,0);

                for (unordered_map<ll, ll>::iterator it = arr[0].begin(); it != arr[0].end(); it++) {
                    ll mask = it->first;
                    ll ts = 0;
                    for (ll temp = mask; temp ; temp = ((temp - 1)&mask)) {
                        if (arr[1].find(temp) != arr[1].end()) ts+=arr[1][temp]*count_bit(temp);
                    }
                    ans += ts*(it->second);
                }

            }
        }
    }
    cout << ans << endl;
    return 0;
}
